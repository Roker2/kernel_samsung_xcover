# File: Makefile
# Copyright (C) 2007-2011, Marvell International Ltd.
#

CC=		$(CROSS_COMPILE)gcc
LD=		$(CROSS_COMPILE)ld

BACKUP=		/root/backup
YMD=		`date +%Y%m%d%H%M`

#############################################################################
# Configuration Options
#############################################################################

# Debug Option
# DEBUG LEVEL n/1/2:
# n: NO DEBUG
# 1: PRINTM(MSG,...), PRINTM(FATAL,...), PRINTM(WARN,...) and PRINTM(INFO,...)
# 2: All PRINTM()
CONFIG_DEBUG=1

# SDIO suspend/resume
CONFIG_SDIO_SUSPEND_RESUME=y

#############################################################################
# Select Platform Tools
#############################################################################

MODEXT = ko


# KERNELDIR point to the installed kernel directory
# for PXA3XX BSP. 
# KERNELDIR can be set on the command line 
# make KERNELDIR=/usr/src/arm/<arch-bsp-path>
# Alternatively KERNELDIR can be set in the environment.
# Default value for KERNELDIR is set below.
KERNELDIR ?= /home/sst/mg1/src/ML8DSP2.01.08/android_base/kernel/kernel

# CROSS_COMPILE specify the prefix used for all executables used
# during compilation. Only gcc and related bin-utils executables
# CROSS_COMPILE can be set on the command line 
# make CROSS_COMPILE=</usr/local/arm/4.1.1/bin/>arm-linux-
# Alternatively CROSS_COMPILE can be set in the environment.
# Default value for CROSS_COMPILE is set below.
CROSS_COMPILE ?= /home/sst/mg1/src/ML8DSP2.01.08/android_base/prebuilt/linux-x86/toolchain/arm-eabi-4.4.3/bin/arm-eabi-

# INSTALLDIR specify the path to install the kernel module after
# succesful compilation.
# INSTALLDIR can be set on the command line 
# make INSTALLDIR=/tftpboot/<rootfs>
# Alternatively INSTALLDIR can be set in the environment.
# Default value for INSTALL is set below.
INSTALLDIR ?= /tftpboot/pxa3xx/root

# ARCH specifies the architecture of the target processor, this kernel
# module will run.
# ARCH can be set on the command line
# make ARCH=<arm/i386>
# Alternatively ARCH can be set in the environment
# Default values of ARCH for specific platform are set below.
ARCH ?= arm



EXTRA_CFLAGS += -I$(KERNELDIR)/include

EXTRA_CFLAGS += -I$(M)/../mbtchar_src
EXTRA_CFLAGS += -I$(M)/bt
LD += -S

BINDIR = ../bin_sd8787_btchar

#############################################################################
# Compiler Flags
#############################################################################
	EXTRA_CFLAGS += -DFPNUM='"65"'

ifeq ($(CONFIG_DEBUG),1)
	EXTRA_CFLAGS += -DDEBUG_LEVEL1
endif

ifeq ($(CONFIG_DEBUG),2)
	EXTRA_CFLAGS += -DDEBUG_LEVEL1
	EXTRA_CFLAGS += -DDEBUG_LEVEL2
	DBG=	-dbg
endif

ifeq ($(CONFIG_SDIO_SUSPEND_RESUME),y)
	EXTRA_CFLAGS += -DSDIO_SUSPEND_RESUME
endif

#############################################################################
# Make Targets
#############################################################################

ifneq ($(KERNELRELEASE),)

BTOBJS = bt/bt_main.o bt/bt_sdiommc.o bt/bt_proc.o

BTOBJS += bt/bt_init.o

obj-m := mbt8xxx.o
mbt8xxx-objs := $(BTOBJS)



# Otherwise we were called directly from the command line; invoke the kernel build system.
else
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules
endif

###############################################################

export		CC LD EXTRA_CFLAGS KERNELDIR

echo:

build:		echo default

	@if [ ! -d $(BINDIR) ]; then \
		mkdir $(BINDIR); \
	fi
	cp -f mbt8xxx.$(MODEXT) $(BINDIR)/mbt8787$(DBG).$(MODEXT)
	cp -r config $(BINDIR) 	


	cp -f README $(BINDIR)

clean:
	-find . -name "*.o" -exec rm {} \;
	-find . -name "*.ko" -exec rm {} \;
	-find . -name ".*.cmd" -exec rm {} \;
	-find . -name "*.mod.c" -exec rm {} \;
	-find . -name "*.symvers" -exec rm {} \;
	-find . -name "modules.order" -exec rm {} \;
	-rm -rf .tmp_versions

install: default

distclean:
	-find . -name "*.o" -exec rm {} \;
	-find . -name "*.orig" -exec rm {} \;
	-find . -name "*.swp" -exec rm {} \;
	-find . -name "*.*~" -exec rm {} \;
	-find . -name "*~" -exec rm {} \;
	-find . -name "*.d" -exec rm {} \;
	-find . -name "*.a" -exec rm {} \;
	-find . -name "tags" -exec rm {} \;
	-find . -name ".*" -exec rm -rf 2> /dev/null \;
	-find . -name "*.ko" -exec rm {} \;
	-find . -name ".*.cmd" -exec rm {} \;
	-find . -name "*.mod.c" -exec rm {} \;
	-rm -rf .tmp_versions
# End of file;
