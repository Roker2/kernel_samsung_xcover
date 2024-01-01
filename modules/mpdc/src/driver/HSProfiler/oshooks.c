/*
** (C) Copyright 2009 Marvell International Ltd.
**  		All Rights Reserved

** This software file (the "File") is distributed by Marvell International Ltd. 
** under the terms of the GNU General Public License Version 2, June 1991 (the "License"). 
** You may use, redistribute and/or modify this File in accordance with the terms and 
** conditions of the License, a copy of which is available along with the File in the 
** license.txt file or by writing to the Free Software Foundation, Inc., 59 Temple Place, 
** Suite 330, Boston, MA 02111-1307 or on the worldwide web at http://www.gnu.org/licenses/gpl.txt.
** THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED WARRANTIES 
** OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY DISCLAIMED.  
** The License provides additional details about this warranty disclaimer.
*/

#include <linux/linkage.h>
#include <linux/ptrace.h> 
#include <linux/file.h>
#include <asm/unistd.h>
#include <asm/uaccess.h>
#include <asm/mman.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>

#if defined(LINUX_VERSION_CODE) && (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 28))
#include <linux/fdtable.h>
#endif

#include "PXD_hs.h"
#include "hotspot_dsa.h"
#include "hotspot_drv.h"
#include "ring_buffer.h"
#include "vdkiocode.h"
#include "common.h"


#define MODULE_FLAG_1ST       0x00000001
#define MODULE_FLAG_GLOBAL    0x00000002

bool g_is_image_load_set = false;
bool g_is_app_exit_set   = false;

char g_image_load_path[PATH_MAX];
pid_t g_launch_app_pid = 0;

bool g_launched_app_exit = false;

bool g_static_enum = false;
char name[PATH_MAX];

static unsigned long g_buffer[sizeof(PXD32_Hotspot_Module) + PATH_MAX];

static struct notifier_block nb_init;

struct mmap_arg_struct {
	unsigned long add;
	unsigned long len;
	unsigned long prot;
	unsigned long flags;
	unsigned long fd;
	unsigned long offset;
};

extern void** system_call_table;
extern wait_queue_head_t pxhs_kd_wait;
extern struct px_hotspot_dsa *g_dsa;
extern struct RingBufferInfo g_module_buffer;

typedef asmlinkage int (*sys_fork_t) (struct pt_regs *regs);
typedef asmlinkage int (*sys_vfork_t) (struct pt_regs *regs);
typedef asmlinkage int (*sys_clone_t) (unsigned long clone_flgs, 
			                           unsigned long newsp, 
									   struct pt_regs *regs);
typedef asmlinkage int (*sys_execve_t) (char *filenameei, 
			                            char **argv, 
										char **envp, 
										struct pt_regs *regs);
										
typedef asmlinkage int (*sys_mmap_t) (struct mmap_arg_struct *arg);
typedef asmlinkage int (*sys_mmap2_t) (unsigned long addr, 
                                       unsigned long len,
			                           unsigned long prot,
			                           unsigned long flags,
			                           unsigned long fd,
			                           unsigned long pgoff);

typedef asmlinkage int (*sys_exit_t) (int error_code);
typedef asmlinkage int (*sys_exit_group_t) (int error_code);
typedef asmlinkage long (*sys_kill_t) (int pid, int sig);
typedef asmlinkage long (*sys_tkill_t) (int pid, int sig);
typedef asmlinkage long (*sys_tgkill_t) (int pid, int tid, int sig);


extern PXD32_DWord convert_to_PXD32_DWord(unsigned long long n);
extern int handle_image_loaded(void);

#define ALIGN_UP(x, align)  ((x + align - 1) & ~(align - 1))

/* formally we use register IP to calculate SP value, which is incorrect. 
 * code optimization will use IP register for temp usage, thus mess up.
 * here we use fp to cal SP value.
 */
#define INIT_STACK_FRAME \
	char *originstack = NULL;\
	char *stackbuf = NULL;\
	do{\
		__asm__("add %0, fp, #4\n\t":"=r"(originstack):);\
	} while(0)\

#define APPEND_STACK_FRAME \
	do{\
	__asm__(\
		"sub sp, sp, #84\n\t"\
		"str sp, %0"\
		:"=m"(stackbuf):"m"(stackbuf)\
	);\
	memcpy(stackbuf, originstack, 84);\
	} while(0)\

#define CUTTAIL_STACK_FRAME \
	do{\
		memcpy(originstack, stackbuf, 84);\
		__asm__("add sp, sp, #84");\
	} while(0)

static sys_vfork_t          px_original_sys_vfork      = NULL;
static sys_fork_t           px_original_sys_fork       = NULL;
static sys_clone_t          px_original_sys_clone      = NULL;
static sys_execve_t         px_original_sys_execve     = NULL;
static sys_mmap_t           px_original_sys_mmap       = NULL;
static sys_mmap2_t          px_original_sys_mmap2      = NULL;
static sys_exit_t           px_original_sys_exit       = NULL;
static sys_exit_group_t     px_original_sys_exit_group = NULL;
static sys_kill_t           px_original_sys_kill       = NULL;
static sys_tkill_t          px_original_sys_tkill      = NULL;
static sys_tgkill_t         px_original_sys_tgkill     = NULL;

static bool gb_enable_os_hooks = false; 

DEFINE_MUTEX(fork_mutex);
DEFINE_MUTEX(buf_mutex);

static unsigned long get_filename_offset(char * full_path)
{
	unsigned long i;
	unsigned long offset;
	
	if (full_path == NULL)
		return 0;
		
	if (full_path[0] != '/')
		return 0;
	
	offset = 0;
	
	for (i=0; full_path[i] != '\0'; i++)
	{
		if (full_path[i] == '/')
			offset = i+1;
	}
	
	return offset;      
}

static void create_hotspot_module(char *        module_path,
                                  unsigned long name_offset,
                                  pid_t         pid,
                                  unsigned long address,
                                  unsigned long size,
                                  unsigned long flag,
                                  unsigned long lsc,
                                  PXD32_Hotspot_Module *p_info)
{
	unsigned int offset;
	unsigned int name_len;
	unsigned int extra_len;
	
	p_info->pid     = pid;
	p_info->lscount = lsc;
	p_info->loadAddr = address;
	p_info->codeSize = size;

	if (is_exe_module(address) && (flag & MODULE_FLAG_1ST))
	{
		p_info->flag |= MODULE_RECORD_FLAG_EXE;
	}
	
	if (flag & MODULE_FLAG_GLOBAL)
	{
		p_info->flag |= MODULE_RECORD_FLAG_GLOBAL_MODULE;
	}

	if (flag & MODULE_FLAG_1ST)
	{
		p_info->flag |= MODULE_RECORD_FLAG_FIRST_MODULE_IN_PROCESS;
	}

	memcpy(p_info->pathName, module_path, strlen(module_path) + 1);

	offset = (char *)&(p_info->pathName[0]) - (char *)p_info;

	name_len  = (strlen(p_info->pathName) + 1) * sizeof(char);
	
	if (name_len <= sizeof(PXD32_Hotspot_Module) - offset)
	{
		extra_len = 0;
	}
	else
	{
		extra_len = name_len - (sizeof(PXD32_Hotspot_Module) - offset);
	}

	p_info->nameOffset = name_offset;

	p_info->length =  sizeof(PXD32_Hotspot_Module)
			        + ALIGN_UP(extra_len, sizeof(unsigned long));
}

int add_module_record(struct add_module_data * data)
{
	bool need_flush;
	bool buffer_full;
	struct add_module_data amd;
	PXD32_Hotspot_Module *p_info;
		
	mutex_lock(&buf_mutex);

	if (copy_from_user(&amd, data, sizeof(struct add_module_data)) != 0)
	{
		mutex_unlock(&buf_mutex);
		return -EFAULT;
	}

	if (strncpy_from_user(name, data->name, PATH_MAX) < 0)
	{
		mutex_unlock(&buf_mutex);
		return -EFAULT;
	}

	memset(g_buffer, 0, sizeof(g_buffer));

	p_info = (PXD32_Hotspot_Module *)&g_buffer;

	create_hotspot_module(name, amd.name_offset, amd.pid, amd.address, amd.size, amd.flag, amd.lsc, p_info);
	
	write_ring_buffer(&g_module_buffer.buffer, p_info, p_info->length, &buffer_full, &need_flush);

	if (need_flush && !g_module_buffer.is_full_event_set)
	{
		g_module_buffer.is_full_event_set = true;

		if (waitqueue_active(&pxhs_kd_wait))
			wake_up_interruptible(&pxhs_kd_wait);
	}

	mutex_unlock(&buf_mutex);

	return 0;
}

unsigned long long get_sample_count(void)
{
	return g_dsa->sample_count;
}

static void wait_image_load_notif(void)
{
	handle_image_loaded();
}

static void launched_app_exit_notif(void)
{
	g_launched_app_exit = true;

	if (waitqueue_active(&pxhs_kd_wait))
		wake_up_interruptible(&pxhs_kd_wait);
}

static void check_wait_for_image_load(char *path)
{
	if (path == NULL)
		return;

	if (g_is_image_load_set && !strcmp(path, g_image_load_path))
	{
		wait_image_load_notif();
		g_is_image_load_set = false;
	}
}

static void check_launched_app_exit(pid_t pid)
{
	if (g_is_app_exit_set && (pid == g_launch_app_pid))
	{
		launched_app_exit_notif();
		g_is_app_exit_set = false;
	}
}


static void write_module_info(char *        module_path,
                              unsigned long name_offset,
                              pid_t         pid,
                              unsigned long address,
                              unsigned long size,
                              unsigned long flag,
                              unsigned long lsc)
{
	PXD32_Hotspot_Module *p_info;
	bool need_flush;
	bool buffer_full;

	mutex_lock(&buf_mutex);

	memset(g_buffer, 0, sizeof(g_buffer));

	p_info = (PXD32_Hotspot_Module *)&g_buffer;

	create_hotspot_module(module_path, name_offset, pid, address, size, flag, lsc, p_info);

	write_ring_buffer(&g_module_buffer.buffer, p_info, p_info->length, &buffer_full, &need_flush);

	if (need_flush && !g_module_buffer.is_full_event_set)
	{
		g_module_buffer.is_full_event_set = true;

		if (waitqueue_active(&pxhs_kd_wait))
			wake_up_interruptible(&pxhs_kd_wait);
	}
	
	mutex_unlock(&buf_mutex);
}

static void module_load_notif(char *path, 
                              unsigned long name_offset,
                              unsigned long pid,
                              unsigned long base,
                              unsigned long size,
                              unsigned long flag,
                              unsigned long lsc)
{
	if (!g_static_enum)
	{
		check_wait_for_image_load(path);
	}

	write_module_info(path, name_offset, pid, base, size, flag, lsc);
}

/*
 * static enumeration kernel modules
 */
static void static_enum_kernel_modules(void)
{
	module_load_notif("swapper", 0, 0, 
				      LINUX_APP_BASE_LOW, 0, 
				      MODULE_FLAG_1ST, 0);

	/*
	 * PAGE_OFFSET is the load address of kernel
	 * 
	 * 0x8000 is the offset to the text section of kernel
	 * which is defined as TEXT_OFFSET in arch/arm/Makefile
	 */
	module_load_notif("vmlinux", 0, 0, 
	                  PAGE_OFFSET + 0x8000, 4096 * 2 * 1024,
	                  MODULE_FLAG_GLOBAL, 0);
}


/* 
 * enumerate all modules for process
 * pid: process id
 * lsc: load sample count
 */
static void enum_modules_for_process(pid_t pid, unsigned long lsc)
{
	bool find = false;
	char *pname;
	unsigned long name_offset;
	unsigned int options;
	struct task_struct *task;
	struct vm_area_struct *mmap;
	struct mm_struct *mm;

	task = px_find_task_by_pid(pid);

	if (task == NULL)
		return;

	mm = get_task_mm(task);
	if (mm != NULL)
	{
		down_read(&mm->mmap_sem);

		for (mmap = mm->mmap; mmap; mmap = mmap->vm_next)
		{
			if (is_valid_module(mmap))
			{
				memset(name, 0, (PATH_MAX) * sizeof(char));
				pname = px_d_path(mmap->vm_file, name, PATH_MAX);

				if (pname != NULL)
				{
					options = 0;

					if (find == false)
					{
						options |= MODULE_FLAG_1ST;
						find = true;
					}
					
					name_offset = get_filename_offset(pname);
					
					module_load_notif(pname, name_offset, pid,
						              mmap->vm_start, mmap->vm_end - mmap->vm_start,
						              options, lsc);
				}
			}
		}

		up_read(&mm->mmap_sem);
		mmput(mm);
	}

	if (find == false)
	{
		module_load_notif(task->comm, 0, pid,
				  LINUX_APP_BASE_LOW, 0,//mmap->vm_end - mmap->vm_start,
				  MODULE_FLAG_1ST, lsc);
	}

	return;
}

static void static_enum_exiting_process_modules(void)
{
	struct task_struct *p_task = &init_task;

	do
	{
		/* static enumeration: load sample count of modules are all zero */
		enum_modules_for_process(p_task->pid, 0);

		read_lock(&tasklist_lock);

		p_task = next_task(p_task);

		read_unlock(&tasklist_lock);
	}while (p_task != &init_task);

}



int module_init_notifier(struct notifier_block *self,
                         unsigned long event,
                         void *arg)
{
	struct module *mod = (struct module *)arg;
	unsigned int name_offset;
	unsigned int lsc;
	
	lsc = get_sample_count();
	
	name_offset = 0;


	if (event == MODULE_STATE_COMING)
	{
		if (mod->init_size > 0)
		{
			module_load_notif((char *)mod->name, name_offset, 0,
				              (__u32)mod->module_init, mod->init_size,
				              MODULE_FLAG_GLOBAL, lsc);
		}
		
		if (mod->core_size > 0)
		{	
			module_load_notif((char*)mod->name, name_offset, 0,
				              (__u32)mod->module_core, mod->core_size,
				              MODULE_FLAG_GLOBAL, lsc);
		}
	}
	
	return 0;
}

asmlinkage int px_sys_fork(struct pt_regs *regs)
{
	int ret = 0;
	unsigned long lsc;

	INIT_STACK_FRAME; 

	mutex_lock(&fork_mutex);

	APPEND_STACK_FRAME;

	lsc = get_sample_count();

	ret = px_original_sys_fork(NULL);

	mutex_unlock(&fork_mutex);
	CUTTAIL_STACK_FRAME;

	if ((ret >= 0) && (gb_enable_os_hooks))
	{
		enum_modules_for_process(ret, lsc);
	}
	
	//mutex_unlock(&fork_mutex);

	return ret;
}

asmlinkage int px_sys_vfork(struct pt_regs *regs)
{
	int ret = 0;
	unsigned long lsc;

	INIT_STACK_FRAME; 

	mutex_lock(&fork_mutex);
	mutex_unlock(&fork_mutex);
	
	APPEND_STACK_FRAME;

	lsc = get_sample_count();

	ret = px_original_sys_vfork(regs);

	CUTTAIL_STACK_FRAME;

	if ((ret >= 0) && (gb_enable_os_hooks))
	{
		enum_modules_for_process(ret, lsc);
	}

	return ret;
}

asmlinkage int px_sys_clone(unsigned long clone_flgs, unsigned long newsp, struct pt_regs *regs)
{
	int ret = 0;
	unsigned long lsc;

	INIT_STACK_FRAME; 

	mutex_lock(&fork_mutex);

	APPEND_STACK_FRAME;

	lsc = get_sample_count();

	ret = px_original_sys_clone(clone_flgs, newsp, regs);
	
	mutex_unlock(&fork_mutex);
	CUTTAIL_STACK_FRAME;

	if ((ret >= 0) && (gb_enable_os_hooks))
	{
		if (!(clone_flgs & CLONE_THREAD))
		{
			enum_modules_for_process(ret, lsc);
		}
	}

	//mutex_unlock(&fork_mutex);

	return ret;
}

asmlinkage int px_sys_execve(char *filenameei, char **argv, char **envp, struct pt_regs *regs)
{
	int ret;
	unsigned long lsc;

	INIT_STACK_FRAME; 

	/** 
	 * here we just use the mutex to make sure the fork call is finished, 
	 *   no need to keep the mutex till the call finished 
	 **/
	mutex_lock(&fork_mutex);
	mutex_unlock(&fork_mutex);

	APPEND_STACK_FRAME;

	lsc = get_sample_count();

	ret = px_original_sys_execve(filenameei, argv, envp, regs);

	CUTTAIL_STACK_FRAME;

	if ((ret >= 0) && (gb_enable_os_hooks))
	{
		enum_modules_for_process(current->tgid, lsc);
	}

	return ret;
}


asmlinkage int px_sys_mmap2(
		unsigned long addr, unsigned long len,
		unsigned long prot, unsigned long flgs,
		unsigned long fd, unsigned long pgoff
/*		unsigned long lRegSP*/
		)
{
	int ret = 0;
	int saved_r5;
	unsigned long lsc;
	struct file *file;

	INIT_STACK_FRAME; 

	// here we must save r5 since it will be used by the OS sys_mmap2 code
	__asm__("str r5, %0\n\t":"=m"(saved_r5):);

	APPEND_STACK_FRAME;

	lsc = get_sample_count();

	// restore r5 
	__asm__("ldr r5, %0\n\t"::"m"(saved_r5):"r5");

	ret = px_original_sys_mmap2( addr, len, prot, flgs, fd, pgoff);

	CUTTAIL_STACK_FRAME;

	if (gb_enable_os_hooks && !IS_ERR((void *)ret) && (prot & PROT_EXEC) && !(flgs & MAP_ANONYMOUS))
	{
		//rcu_read_lock();

		if ((file = fcheck(fd))!= NULL)
		{
			char *pname;
			
			memset(name, 0, PATH_MAX * sizeof(char));
			pname = px_d_path(file, name, PATH_MAX);
			
			if (pname)
			{
				unsigned long name_offset;

				name_offset = get_filename_offset(pname);

				module_load_notif(pname, name_offset, current->tgid,
						          ret, len, 0, lsc);
			}
			
		}
		//rcu_read_unlock();
	}
	
	return ret;
}

asmlinkage int px_sys_mmap(struct mmap_arg_struct *arg)
{
	int ret = 0;
	struct mmap_arg_struct tmp;
	struct file *file;
	unsigned long lsc;

	lsc = get_sample_count();
	
	if (copy_from_user(&tmp, arg, sizeof(tmp)) != 0)
	{
		return -EFAULT;
	}

 	ret = px_original_sys_mmap(arg);

	if (gb_enable_os_hooks && (!IS_ERR((void*)ret)) && (tmp.prot & PROT_EXEC) && !(tmp.flags & MAP_ANONYMOUS))
	{
		//rcu_read_lock();
		if ((file = fcheck(tmp.fd)) != NULL)
		{
			char *pname;

			memset(name, 0, PATH_MAX * sizeof(char));
			pname = px_d_path(file, name, PATH_MAX);
			if (pname)
			{
				unsigned long name_offset;

				name_offset = get_filename_offset(pname);
				
				module_load_notif(pname, name_offset, current->tgid,
					              ret, tmp.len,
					              0, lsc);
			}
		}

		//rcu_read_unlock();
	}

	return ret;	
}

asmlinkage int px_sys_exit(int error_code)
{
	long ret = 0;
	/**
	 * We must save the original sys_exit function here. If the current pid
	 * is the application the user launched and user selected "stop sampling
	 * on application unload", then the function "enum_module_for_exit_check"
	 * will terminate the sampling session, which in turn will remove all the
	 * syscall hooks. On 2.4 kernel it is not going to happen, because the 
	 * utility has no chance to run until this function returns; but on 2.6
	 * kernel with preempt turned on, the utility maybe scheduled run before 
	 * the following call to px_original_sys_exit, so at that time the module
	 * tracker is already unloaded and the px_original_sys_exit becomes NULL
	 * pointer. The following px_sys_exit_group has the same situation.
	 */
	sys_exit_t saved_sys_exit = px_original_sys_exit;

	if (gb_enable_os_hooks) 
	{
		check_launched_app_exit(current->tgid);
	}

	ret = saved_sys_exit(error_code);

	return ret;
}

asmlinkage int px_sys_exit_group(int error_code)
{
	long ret = 0;

	sys_exit_group_t saved_sys_exit_group = px_original_sys_exit_group;

	if (gb_enable_os_hooks)
	{
		check_launched_app_exit(current->tgid);
	}
	
	ret = saved_sys_exit_group(error_code);

	return ret;
}

static bool is_kill_sig(int sig)
{
	switch (sig)
	{
	case SIGINT:
	case SIGKILL:
	case SIGTERM:
	case SIGABRT:
	case SIGFPE:
	case SIGILL:
	case SIGQUIT:
	case SIGSEGV:
	case SIGBUS:
		return true;
	default:
		return false;
	}
}

asmlinkage long px_sys_kill(int pid, int sig)
{
	long ret = 0;
	sys_kill_t saved_sys_kill = px_original_sys_kill;

	ret = saved_sys_kill(pid, sig);
	
	if (!ret && gb_enable_os_hooks && is_kill_sig(sig))
	{
		check_launched_app_exit(pid);
	}

	return ret;
}

asmlinkage long px_sys_tkill(int pid, int sig)
{
	long ret = 0;
	sys_tkill_t saved_sys_tkill = px_original_sys_tkill;


	ret = saved_sys_tkill(pid, sig);
	
	if (!ret && gb_enable_os_hooks && is_kill_sig(sig))
	{
		check_launched_app_exit(pid);
	}
	
	return ret;
}

asmlinkage long px_sys_tgkill(int pid, int tid, int sig)
{
	long ret = 0;
	sys_tgkill_t saved_sys_tgkill = px_original_sys_tgkill;


	ret = saved_sys_tgkill(pid, tid, sig);
	
	if (!ret && gb_enable_os_hooks && is_kill_sig(sig))
	{
		check_launched_app_exit(pid);
	}
	
	return ret;
}

static int install_os_hooks(void)
{
	int ret;
	
	/* register module state change notifier */
	nb_init.notifier_call = module_init_notifier;

	ret = register_module_notifier(&nb_init);

	if (ret != 0)
	{
		printk(KERN_ERR "register_module_notifier() fails\n");
		return -EFAULT;
	}

	/* hook necessary system call table */
	px_original_sys_fork       = (sys_fork_t) xchg(&system_call_table[__NR_fork - __NR_SYSCALL_BASE], px_sys_fork);
	px_original_sys_vfork      = (sys_vfork_t) xchg(&system_call_table[__NR_vfork - __NR_SYSCALL_BASE], px_sys_vfork);
	px_original_sys_clone      = (sys_clone_t) xchg(&system_call_table[__NR_clone - __NR_SYSCALL_BASE], px_sys_clone);
	px_original_sys_execve     = (sys_execve_t) xchg(&system_call_table[__NR_execve - __NR_SYSCALL_BASE], px_sys_execve);
	px_original_sys_mmap       = (sys_mmap_t) xchg(&system_call_table[__NR_mmap - __NR_SYSCALL_BASE], px_sys_mmap);
	px_original_sys_mmap2      = (sys_mmap2_t) xchg(&system_call_table[__NR_mmap2 - __NR_SYSCALL_BASE], px_sys_mmap2);
	px_original_sys_exit       = (sys_exit_t) xchg(&system_call_table[__NR_exit - __NR_SYSCALL_BASE], px_sys_exit);
	px_original_sys_exit_group = (sys_exit_group_t) xchg(&system_call_table[__NR_exit_group - __NR_SYSCALL_BASE], px_sys_exit_group);
	px_original_sys_kill       = (sys_kill_t) xchg(&system_call_table[__NR_kill - __NR_SYSCALL_BASE], px_sys_kill);
	px_original_sys_tkill      = (sys_tkill_t) xchg(&system_call_table[__NR_tkill - __NR_SYSCALL_BASE], px_sys_tkill);
	px_original_sys_tgkill     = (sys_tgkill_t) xchg(&system_call_table[__NR_tgkill - __NR_SYSCALL_BASE], px_sys_tgkill);
	
	gb_enable_os_hooks = true;
	
	return 0;
}

static int remove_os_hooks(void)
{
	void *orgFn;

	/* only remove the os hooks when install_os_hooks() has been called */
	if (!gb_enable_os_hooks)
		return 0;
	
	if ((orgFn = xchg(&px_original_sys_fork, 0)))
		orgFn = xchg(&system_call_table[__NR_fork - __NR_SYSCALL_BASE], orgFn);

	if ((orgFn = xchg(&px_original_sys_vfork, 0)))
		orgFn = xchg(&system_call_table[__NR_vfork - __NR_SYSCALL_BASE], orgFn);
	
	if ((orgFn = xchg(&px_original_sys_clone, 0)))
		orgFn = xchg(&system_call_table[__NR_clone - __NR_SYSCALL_BASE], orgFn);

	if ((orgFn = xchg(&px_original_sys_execve, 0)))
		orgFn = xchg(&system_call_table[__NR_execve - __NR_SYSCALL_BASE], orgFn);

	if ((orgFn = xchg(&px_original_sys_mmap, 0)))
		orgFn = xchg(&system_call_table[__NR_mmap - __NR_SYSCALL_BASE], orgFn);

	if ((orgFn = xchg(&px_original_sys_mmap2, 0)))
		orgFn = xchg(&system_call_table[__NR_mmap2 - __NR_SYSCALL_BASE], orgFn);

	if ((orgFn = xchg(&px_original_sys_exit, 0)))
		orgFn = xchg(&system_call_table[__NR_exit - __NR_SYSCALL_BASE], orgFn);

	if ((orgFn = xchg(&px_original_sys_exit_group, 0)))
		orgFn = xchg(&system_call_table[__NR_exit_group - __NR_SYSCALL_BASE], orgFn);

	if ((orgFn = xchg(&px_original_sys_kill, 0)))
		orgFn = xchg(&system_call_table[__NR_kill - __NR_SYSCALL_BASE], orgFn);
		
	if ((orgFn = xchg(&px_original_sys_tkill, 0)))
		orgFn = xchg(&system_call_table[__NR_tkill - __NR_SYSCALL_BASE], orgFn);

	if ((orgFn = xchg(&px_original_sys_tgkill, 0)))
		orgFn = xchg(&system_call_table[__NR_tgkill - __NR_SYSCALL_BASE], orgFn);

	// unregister module state change notifier
	unregister_module_notifier(&nb_init);
	
	gb_enable_os_hooks = false;
	
	return 0;
}

int start_module_tracking(void)
{
	int ret;

	/* 
	 * now we seperate start_module_tracking and start_sampling as two steps
	 * we need to set sample count to zero here
	 * otherwise it will record the sample count in the last running
	 */
	g_dsa->sample_count = 0;

	g_static_enum = true;

	static_enum_kernel_modules();

	static_enum_exiting_process_modules();
	
	g_static_enum = false;

	ret = install_os_hooks();

	return ret;
}

int stop_module_tracking(void)
{
	int ret;

	ret = remove_os_hooks();
	
	return ret;
}

