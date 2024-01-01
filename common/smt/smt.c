/*****************************************************************************
						Copyright(c) 2009 YokogawaDigitalComputer Corporation
��ǽ�������ƥ�ޥ���ȥ졼�������ͥ����API�饤�֥��

��ա�

�ѹ�����
 +-------------- �����ֹ� (000 �� 999)
 |	  +--------- �������Ƥ��륷���ƥ�С������
 |	  | 	+--- �������ѹ����ɲá������ʬ��
 v	  v 	v
 No  Ver  ʬ�� ǯ����	  ̾��			����
---+-----+----+----------+-------------+--------------------------------------
000 00.00 ���� 2010/04/19 S.Tonoshita	������ȯ
*****************************************************************************/

/* ���󥯥롼�ɻ��� *********************************************************/
#include <linux/module.h>
#include <smt/SMTAPI.h>

/* ������ ******************************************************************/
#define SET_FUNCPOINTER(api)		_SMT_##api = (func ? func : _SMT_##api##_nop)

/* �ؿ��ץ�ȥ�������� *****************************************************/
void smt_set_PortOut( int (*func)(unsigned long addr,unsigned long data,_SMT_PSZ size,_SMT_PRW rw ) );
void smt_set_Printf( int (*func)(int level,const char *format , ...) );
void smt_set_Puts( int (*func)(int level,const char *s) );
void smt_set_UsrMsgTag0( int (*func)(int level,unsigned long TagNum ) );
void smt_set_UsrMsgTag1( int (*func)(int level,unsigned long TagNum,unsigned long arg1 ) );
void smt_set_UsrMsgTag2( int (*func)(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2 ) );
void smt_set_UsrMsgTag3( int (*func)(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3 ) );
void smt_set_UsrMsgTag4( int (*func)(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4 ) );

void smt_set_OsSwitch_Process( int (*func)(unsigned long processid) );
void smt_set_OsSwitch_ThreadProcess( int (*func)(unsigned long threadid,unsigned long processid) );
void smt_set_OsSwitch_Process_Name( int (*func)(unsigned long processid,const char *str) );
void smt_set_OsSwitch_ThreadProcess_Name( int (*func)(unsigned long threadid,unsigned long processid,const char *tname,const char *pname) );
void smt_set_OsSwitch_Irq_in( int (*func)(unsigned long irqid) );
void smt_set_OsSwitch_Irq_out( int (*func)(unsigned long irqid) );
void smt_set_OsSwitch_Idle( int (*func)( void ) );
void smt_set_OsCall0( int (*func)(int osc,_SMT_OS_CALL attr) );
void smt_set_OsCall1( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1) );
void smt_set_OsCall2( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2) );
void smt_set_OsCall3( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3) );
void smt_set_OsCall4( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4) );
void smt_set_OsCall5( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5) );
void smt_set_OsCall6( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6) );
void smt_set_OsCall7( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7) );
void smt_set_OsCall8( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8) );
void smt_set_OsCall9( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9) );
void smt_set_OsCall10( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10) );
void smt_set_OsCall11( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11) );
void smt_set_OsCall12( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12) );
void smt_set_OsCall13( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13) );
void smt_set_OsCall14( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14) );
void smt_set_OsCall15( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15) );
void smt_set_OsCall16( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15,unsigned long arg16) );

void smt_set_Hook0( void (*func)(unsigned long TagNum) );
void smt_set_Hook1( void (*func)(unsigned long TagNum,unsigned long arg1) );
void smt_set_Hook2( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2) );
void smt_set_Hook3( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3) );
void smt_set_Hook4( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4) );
void smt_set_Hook5( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5) );
void smt_set_Hook6( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6) );
void smt_set_Hook7( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7) );
void smt_set_Hook8( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8) );
void smt_set_Hook9( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9) );
void smt_set_Hook10( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10) );
void smt_set_Hook11( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11) );
void smt_set_Hook12( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12) );
void smt_set_Hook13( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13) );
void smt_set_Hook14( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14) );
void smt_set_Hook15( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15) );
void smt_set_Hook16( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15,unsigned long arg16) );

/* �����ؿ��ץ�ȥ�������� *************************************************/
static int _SMT_PortOut_nop(unsigned long addr,unsigned long data,_SMT_PSZ size,_SMT_PRW rw);
static int _SMT_Printf_nop(int level,const char *format , ...);
static int _SMT_Puts_nop(int level,const char *s);
static int _SMT_UsrMsgTag0_nop(int level,unsigned long TagNum);
static int _SMT_UsrMsgTag1_nop(int level,unsigned long TagNum,unsigned long arg1);
static int _SMT_UsrMsgTag2_nop(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2);
static int _SMT_UsrMsgTag3_nop(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3);
static int _SMT_UsrMsgTag4_nop(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4);
static int _SMT_OsSwitch_Process_nop(unsigned long processid);
static int _SMT_OsSwitch_ThreadProcess_nop(unsigned long threadid,unsigned long processid);
static int _SMT_OsSwitch_Process_Name_nop(unsigned long processid,const char *str);
static int _SMT_OsSwitch_ThreadProcess_Name_nop(unsigned long threadid,unsigned long processid,const char *tname,const char *pname);
static int _SMT_OsSwitch_Irq_in_nop(unsigned long irqid);
static int _SMT_OsSwitch_Irq_out_nop(unsigned long irqid);
static int _SMT_OsSwitch_Idle_nop( void );

static int _SMT_OsCall0_nop(int osc,_SMT_OS_CALL attr);
static int _SMT_OsCall1_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1);
static int _SMT_OsCall2_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2);
static int _SMT_OsCall3_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3);
static int _SMT_OsCall4_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4);
static int _SMT_OsCall5_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5);
static int _SMT_OsCall6_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6);
static int _SMT_OsCall7_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7);
static int _SMT_OsCall8_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8);
static int _SMT_OsCall9_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9);
static int _SMT_OsCall10_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10);
static int _SMT_OsCall11_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11);
static int _SMT_OsCall12_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12);
static int _SMT_OsCall13_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13);
static int _SMT_OsCall14_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14);
static int _SMT_OsCall15_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15);
static int _SMT_OsCall16_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15,unsigned long arg16);

static void _TRQ_Hook0_nop(unsigned long TagNum);
static void _TRQ_Hook1_nop(unsigned long TagNum,unsigned long arg1);
static void _TRQ_Hook2_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2);
static void _TRQ_Hook3_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3);
static void _TRQ_Hook4_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4);
static void _TRQ_Hook5_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5);
static void _TRQ_Hook6_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6);
static void _TRQ_Hook7_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7);
static void _TRQ_Hook8_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8);
static void _TRQ_Hook9_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9);
static void _TRQ_Hook10_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10);
static void _TRQ_Hook11_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11);
static void _TRQ_Hook12_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12);
static void _TRQ_Hook13_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13);
static void _TRQ_Hook14_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14);
static void _TRQ_Hook15_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15);
static void _TRQ_Hook16_nop(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15,unsigned long arg16);

/* �����ѿ���� *************************************************************/
static int SMTDebugLevel 		  = SMT_LV_MSK;

int (*_SMT_PortOut)(unsigned long addr ,unsigned long data,_SMT_PSZ size,_SMT_PRW rw)												= _SMT_PortOut_nop;
int (*_SMT_Printf)(int level,const char *format , ...)																				= _SMT_Printf_nop;
int (*_SMT_Puts)(int level,const char *s)																							= _SMT_Puts_nop;
int (*_SMT_UsrMsgTag0)(int level,unsigned long TagNum)																				= _SMT_UsrMsgTag0_nop;
int (*_SMT_UsrMsgTag1)(int level,unsigned long TagNum,unsigned long arg1)															= _SMT_UsrMsgTag1_nop;
int (*_SMT_UsrMsgTag2)(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2)										= _SMT_UsrMsgTag2_nop;
int (*_SMT_UsrMsgTag3)(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3)						= _SMT_UsrMsgTag3_nop;
int (*_SMT_UsrMsgTag4)(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4)	= _SMT_UsrMsgTag4_nop;
int (*_SMT_OsSwitch_Process)(unsigned long processid) 																				= _SMT_OsSwitch_Process_nop;
int (*_SMT_OsSwitch_ThreadProcess)(unsigned long threadid,unsigned long processid) 													= _SMT_OsSwitch_ThreadProcess_nop;
int (*_SMT_OsSwitch_Process_Name)(unsigned long processid,const char *str) 															= _SMT_OsSwitch_Process_Name_nop;
int (*_SMT_OsSwitch_ThreadProcess_Name)(unsigned long threadid,unsigned long processid,const char *tname,const char *pname) 		= _SMT_OsSwitch_ThreadProcess_Name_nop;
int (*_SMT_OsSwitch_Irq_in)(unsigned long irqid) 																					= _SMT_OsSwitch_Irq_in_nop;
int (*_SMT_OsSwitch_Irq_out)(unsigned long irqid) 																					= _SMT_OsSwitch_Irq_out_nop;
int (*_SMT_OsSwitch_Idle)( void ) 																									= _SMT_OsSwitch_Idle_nop;

int (*_SMT_OsCall0)(int osc,_SMT_OS_CALL attr) 																						= _SMT_OsCall0_nop;
int (*_SMT_OsCall1)(int osc,_SMT_OS_CALL attr,unsigned long arg1) 																	= _SMT_OsCall1_nop;
int (*_SMT_OsCall2)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2) 												= _SMT_OsCall2_nop;
int (*_SMT_OsCall3)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3) 							= _SMT_OsCall3_nop;
int (*_SMT_OsCall4)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4) 			= _SMT_OsCall4_nop;
int (*_SMT_OsCall5)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5) 																																																							= _SMT_OsCall5_nop;
int (*_SMT_OsCall6)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6) 																																																		= _SMT_OsCall6_nop;
int (*_SMT_OsCall7)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7) 																																													= _SMT_OsCall7_nop;
int (*_SMT_OsCall8)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8) 																																								= _SMT_OsCall8_nop;
int (*_SMT_OsCall9)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9)																																				= _SMT_OsCall9_nop;
int (*_SMT_OsCall10)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10) 																														= _SMT_OsCall10_nop;
int (*_SMT_OsCall11)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11) 																									= _SMT_OsCall11_nop;
int (*_SMT_OsCall12)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12) 																				= _SMT_OsCall12_nop;
int (*_SMT_OsCall13)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13) 															= _SMT_OsCall13_nop;
int (*_SMT_OsCall14)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14) 										= _SMT_OsCall14_nop;
int (*_SMT_OsCall15)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15) 					= _SMT_OsCall15_nop;
int (*_SMT_OsCall16)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15,unsigned long arg16) = _SMT_OsCall16_nop;

void (*_TRQ_Hook0)(unsigned long TagNum)																							= _TRQ_Hook0_nop;
void (*_TRQ_Hook1)(unsigned long TagNum,unsigned long arg1)																			= _TRQ_Hook1_nop;
void (*_TRQ_Hook2)(unsigned long TagNum,unsigned long arg1,unsigned long arg2)														= _TRQ_Hook2_nop;
void (*_TRQ_Hook3)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3)									= _TRQ_Hook3_nop;
void (*_TRQ_Hook4)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4)				= _TRQ_Hook4_nop;
void (*_TRQ_Hook5)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5)																																																								= _TRQ_Hook5_nop;
void (*_TRQ_Hook6)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6) 																																																			= _TRQ_Hook6_nop;
void (*_TRQ_Hook7)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7)																																														= _TRQ_Hook7_nop;
void (*_TRQ_Hook8)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8) 																																									= _TRQ_Hook8_nop;
void (*_TRQ_Hook9)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9)																																					= _TRQ_Hook9_nop;
void (*_TRQ_Hook10)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10)																															= _TRQ_Hook10_nop;
void (*_TRQ_Hook11)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11)																										= _TRQ_Hook11_nop;
void (*_TRQ_Hook12)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12)																					= _TRQ_Hook12_nop;
void (*_TRQ_Hook13)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13)																= _TRQ_Hook13_nop;
void (*_TRQ_Hook14)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14)											= _TRQ_Hook14_nop;
void (*_TRQ_Hook15)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15)						= _TRQ_Hook15_nop;
void (*_TRQ_Hook16)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15,unsigned long arg16)	= _TRQ_Hook16_nop;

EXPORT_SYMBOL(_SMT_PortOut);
EXPORT_SYMBOL(_SMT_Printf);
EXPORT_SYMBOL(_SMT_Puts);
EXPORT_SYMBOL(_SMT_UsrMsgTag0);
EXPORT_SYMBOL(_SMT_UsrMsgTag1);
EXPORT_SYMBOL(_SMT_UsrMsgTag2);
EXPORT_SYMBOL(_SMT_UsrMsgTag3);
EXPORT_SYMBOL(_SMT_UsrMsgTag4);
EXPORT_SYMBOL(_SMT_OsSwitch_Process);
EXPORT_SYMBOL(_SMT_OsSwitch_ThreadProcess);
EXPORT_SYMBOL(_SMT_OsSwitch_Process_Name);
EXPORT_SYMBOL(_SMT_OsSwitch_ThreadProcess_Name);
EXPORT_SYMBOL(_SMT_OsSwitch_Irq_in);
EXPORT_SYMBOL(_SMT_OsSwitch_Irq_out);
EXPORT_SYMBOL(_SMT_OsSwitch_Idle);
EXPORT_SYMBOL(_SMT_OsCall0);
EXPORT_SYMBOL(_SMT_OsCall1);
EXPORT_SYMBOL(_SMT_OsCall2);
EXPORT_SYMBOL(_SMT_OsCall3);
EXPORT_SYMBOL(_SMT_OsCall4);
EXPORT_SYMBOL(_SMT_OsCall5);
EXPORT_SYMBOL(_SMT_OsCall6);
EXPORT_SYMBOL(_SMT_OsCall7);
EXPORT_SYMBOL(_SMT_OsCall8);
EXPORT_SYMBOL(_SMT_OsCall9);
EXPORT_SYMBOL(_SMT_OsCall10);
EXPORT_SYMBOL(_SMT_OsCall11);
EXPORT_SYMBOL(_SMT_OsCall12);
EXPORT_SYMBOL(_SMT_OsCall13);
EXPORT_SYMBOL(_SMT_OsCall14);
EXPORT_SYMBOL(_SMT_OsCall15);
EXPORT_SYMBOL(_SMT_OsCall16);
EXPORT_SYMBOL(_TRQ_Hook0);
EXPORT_SYMBOL(_TRQ_Hook1);
EXPORT_SYMBOL(_TRQ_Hook2);
EXPORT_SYMBOL(_TRQ_Hook3);
EXPORT_SYMBOL(_TRQ_Hook4);
EXPORT_SYMBOL(_TRQ_Hook5);
EXPORT_SYMBOL(_TRQ_Hook6);
EXPORT_SYMBOL(_TRQ_Hook7);
EXPORT_SYMBOL(_TRQ_Hook8);
EXPORT_SYMBOL(_TRQ_Hook9);
EXPORT_SYMBOL(_TRQ_Hook10);
EXPORT_SYMBOL(_TRQ_Hook11);
EXPORT_SYMBOL(_TRQ_Hook12);
EXPORT_SYMBOL(_TRQ_Hook13);
EXPORT_SYMBOL(_TRQ_Hook14);
EXPORT_SYMBOL(_TRQ_Hook15);
EXPORT_SYMBOL(_TRQ_Hook16);

/*****************************************************************************
1.��ǽ���ǥХå��ץ���ʸ�ǥХå���٥�򻲾Ȥ���

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------

4.����͡�
*****************************************************************************/
int	_SMT_GetDebugLevel( void )
{
	return SMTDebugLevel;
}
EXPORT_SYMBOL(_SMT_GetDebugLevel);

/*****************************************************************************
1.��ǽ���ǥХå��ץ���ʸ�ǥХå���٥�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------

4.����͡�
*****************************************************************************/
void _SMT_SetDebugLevel( int level )
{
	SMTDebugLevel = level;
}
EXPORT_SYMBOL(_SMT_SetDebugLevel);

/*****************************************************************************
1.��ǽ��_SMT_PortOut()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_PortOut( int (*func)(unsigned long addr ,unsigned long data ,_SMT_PSZ size ,_SMT_PRW rw ) )
{
	if( func ){
		_SMT_PortOut = func;
	}
	else{
		_SMT_PortOut = _SMT_PortOut_nop;
	}
}
EXPORT_SYMBOL(smt_set_PortOut);

/*****************************************************************************
1.��ǽ��_SMT_Printf()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Printf( int (*func)(int level,const char *format , ...) )
{
	if( func ){
		_SMT_Printf = func;
	}
	else{
		_SMT_Printf = _SMT_Printf_nop;
	}
}
EXPORT_SYMBOL(smt_set_Printf);

/*****************************************************************************
1.��ǽ��_SMT_Puts()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Puts( int (*func)(int level,const char *s) )
{
	if( func ){
		_SMT_Puts = func;
	}
	else{
		_SMT_Puts = _SMT_Puts_nop;
	}
}
EXPORT_SYMBOL(smt_set_Puts);

/*****************************************************************************
1.��ǽ��_SMT_UsrMsgTag0()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_UsrMsgTag0( int(*func)(int level,unsigned long TagNum ) )
{
	if( func ){
		_SMT_UsrMsgTag0 = func;
	}
	else{
		_SMT_UsrMsgTag0 = _SMT_UsrMsgTag0_nop;
	}
}
EXPORT_SYMBOL(smt_set_UsrMsgTag0);

/*****************************************************************************
1.��ǽ��_SMT_UsrMsgTag1()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_UsrMsgTag1( int (*func)(int level,unsigned long TagNum,unsigned long arg1 ) )
{
	if( func ){
		_SMT_UsrMsgTag1 = func;
	}
	else{
		_SMT_UsrMsgTag1 = _SMT_UsrMsgTag1_nop;
	}
}
EXPORT_SYMBOL(smt_set_UsrMsgTag1);

/*****************************************************************************
1.��ǽ��_SMT_UsrMsgTag2()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_UsrMsgTag2( int (*func)(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2 ) )
{
	if( func ){
		_SMT_UsrMsgTag2 = func;
	}
	else{
		_SMT_UsrMsgTag2 = _SMT_UsrMsgTag2_nop;
	}
}
EXPORT_SYMBOL(smt_set_UsrMsgTag2);

/*****************************************************************************
1.��ǽ��_SMT_UsrMsgTag3()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_UsrMsgTag3( int (*func)(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3 ) )
{
	if( func ){
		_SMT_UsrMsgTag3 = func;
	}
	else{
		_SMT_UsrMsgTag3 = _SMT_UsrMsgTag3_nop;
	}
}
EXPORT_SYMBOL(smt_set_UsrMsgTag3);

/*****************************************************************************
1.��ǽ��_SMT_UsrMsgTag4()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_UsrMsgTag4( int (*func)(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4 ) )
{
	if( func ){
		_SMT_UsrMsgTag4 = func;
	}
	else{
		_SMT_UsrMsgTag4 = _SMT_UsrMsgTag4_nop;
	}
}
EXPORT_SYMBOL(smt_set_UsrMsgTag4);

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_PortOut()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	addr						���ɥ쥹��
I/	data						�ǡ�����
I/	size						�ݡ��ȥ����� 1:8bit 2:16bit 3:32bit
I/	rw							�꡼�ɥ饤�ȼ��� 0:�饤�� 1:�꡼��

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_PortOut_nop(unsigned long addr ,unsigned long data ,_SMT_PSZ size ,_SMT_PRW rw )
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMTPrintf()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	level						���ϥ�٥�
I/	*format						��
I/	agg1						����....

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_Printf_nop(int level,const char *format , ...)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMTPuts()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	level						���ϥ�٥�
I/	*format						��
I/	agg1						����....

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_Puts_nop(int level,const char *s)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_UsrMsgTag0()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	level						���ϥ�٥�
I/	TagNum						��å����������ֹ�

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_UsrMsgTag0_nop(int level,unsigned long TagNum)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_UsrMsgTag1()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	level						���ϥ�٥�
I/	TagNum						��å����������ֹ�
I/	arg1						����1

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_UsrMsgTag1_nop(int level,unsigned long TagNum,unsigned long arg1)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_UsrMsgTag2()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	level						���ϥ�٥�
I/	TagNum						��å����������ֹ�
I/	arg1						����1
I/	arg2						����2

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_UsrMsgTag2_nop(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_UsrMsgTag4()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	level						���ϥ�٥�
I/	TagNum						��å����������ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_UsrMsgTag3_nop(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_UsrMsgTag4()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	level						���ϥ�٥�
I/	TagNum						��å����������ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_UsrMsgTag4_nop(int level,unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ��_SMT_OsSwitch_Process()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsSwitch_Process( int (*func)(unsigned long processid) )
{
	SET_FUNCPOINTER(OsSwitch_Process);
}
EXPORT_SYMBOL(smt_set_OsSwitch_Process);

/*****************************************************************************
1.��ǽ��_SMT_OsSwitch_ThreadProcess()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsSwitch_ThreadProcess( int (*func)(unsigned long threadid,unsigned long processid) )
{
	SET_FUNCPOINTER(OsSwitch_ThreadProcess);
}
EXPORT_SYMBOL(smt_set_OsSwitch_ThreadProcess);

/*****************************************************************************
1.��ǽ��_SMT_OsSwitch_Process_Name()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsSwitch_Process_Name( int (*func)(unsigned long processid,const char *str) )
{
	SET_FUNCPOINTER(OsSwitch_Process_Name);
}
EXPORT_SYMBOL(smt_set_OsSwitch_Process_Name);

/*****************************************************************************
1.��ǽ��_SMT_OsSwitch_ThreadProcess_Name()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsSwitch_ThreadProcess_Name( int (*func)(unsigned long threadid,unsigned long processid,const char *tname,const char *pname) )
{
	SET_FUNCPOINTER(OsSwitch_ThreadProcess_Name);
}
EXPORT_SYMBOL(smt_set_OsSwitch_ThreadProcess_Name);

/*****************************************************************************
1.��ǽ��_SMT_OsSwitch_Irq_in()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsSwitch_Irq_in( int (*func)(unsigned long irqid) )
{
	SET_FUNCPOINTER(OsSwitch_Irq_in);
}
EXPORT_SYMBOL(smt_set_OsSwitch_Irq_in);

/*****************************************************************************
1.��ǽ��_SMT_OsSwitch_Irq_out()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsSwitch_Irq_out( int (*func)(unsigned long irqid) )
{
	SET_FUNCPOINTER(OsSwitch_Irq_out);
}
EXPORT_SYMBOL(smt_set_OsSwitch_Irq_out);

/*****************************************************************************
1.��ǽ��_SMT_OsSwitch_Idle()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsSwitch_Idle( int (*func)( void ) )
{
	SET_FUNCPOINTER(OsSwitch_Idle);
}
EXPORT_SYMBOL(smt_set_OsSwitch_Idle);

/*****************************************************************************
1.��ǽ��_SMT_OsCall1()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall0( int (*func)(int osc,_SMT_OS_CALL attr) )
{
	SET_FUNCPOINTER(OsCall0);
}
EXPORT_SYMBOL(smt_set_OsCall0);

/*****************************************************************************
1.��ǽ��_SMT_OsCall1()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall1( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1) )
{
	SET_FUNCPOINTER(OsCall1);
}
EXPORT_SYMBOL(smt_set_OsCall1);

/*****************************************************************************
1.��ǽ��_SMT_OsCall2()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall2( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2) )
{
	SET_FUNCPOINTER(OsCall2);
}
EXPORT_SYMBOL(smt_set_OsCall2);

/*****************************************************************************
1.��ǽ��_SMT_OsCall3()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall3( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3) )
{
	SET_FUNCPOINTER(OsCall3);
}
EXPORT_SYMBOL(smt_set_OsCall3);

/*****************************************************************************
1.��ǽ��_SMT_OsCall4()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall4( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4) )
{
	SET_FUNCPOINTER(OsCall4);
}
EXPORT_SYMBOL(smt_set_OsCall4);

/*****************************************************************************
1.��ǽ��_SMT_OsCall5()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall5( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5) )
{
	SET_FUNCPOINTER(OsCall5);
}
EXPORT_SYMBOL(smt_set_OsCall5);

/*****************************************************************************
1.��ǽ��_SMT_OsCall6()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall6( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6) )
{
	SET_FUNCPOINTER(OsCall6);
}
EXPORT_SYMBOL(smt_set_OsCall6);

/*****************************************************************************
1.��ǽ��_SMT_OsCall7()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall7( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7) )
{
	SET_FUNCPOINTER(OsCall7);
}
EXPORT_SYMBOL(smt_set_OsCall7);

/*****************************************************************************
1.��ǽ��_SMT_OsCall8()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall8( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8) )
{
	SET_FUNCPOINTER(OsCall8);
}
EXPORT_SYMBOL(smt_set_OsCall8);

/*****************************************************************************
1.��ǽ��_SMT_OsCall9()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall9( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9) )
{
	SET_FUNCPOINTER(OsCall9);
}
EXPORT_SYMBOL(smt_set_OsCall9);

/*****************************************************************************
1.��ǽ��_SMT_OsCall10()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall10( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10) )
{
	SET_FUNCPOINTER(OsCall10);
}
EXPORT_SYMBOL(smt_set_OsCall10);

/*****************************************************************************
1.��ǽ��_SMT_OsCall11()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall11( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11) )
{
	SET_FUNCPOINTER(OsCall11);
}
EXPORT_SYMBOL(smt_set_OsCall11);

/*****************************************************************************
1.��ǽ��_SMT_OsCall12()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall12( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12) )
{
	SET_FUNCPOINTER(OsCall12);
}
EXPORT_SYMBOL(smt_set_OsCall12);

/*****************************************************************************
1.��ǽ��_SMT_OsCall13()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall13( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13) )
{
	SET_FUNCPOINTER(OsCall13);
}
EXPORT_SYMBOL(smt_set_OsCall13);

/*****************************************************************************
1.��ǽ��_SMT_OsCall14()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall14( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14) )
{
	SET_FUNCPOINTER(OsCall14);
}
EXPORT_SYMBOL(smt_set_OsCall14);

/*****************************************************************************
1.��ǽ��_SMT_OsCall15()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall15( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15) )
{
	SET_FUNCPOINTER(OsCall15);
}
EXPORT_SYMBOL(smt_set_OsCall15);

/*****************************************************************************
1.��ǽ��_SMT_OsCall16()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_OsCall16( int (*func)(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15,unsigned long arg16) )
{
	SET_FUNCPOINTER(OsCall16);
}
EXPORT_SYMBOL(smt_set_OsCall16);


/*****************************************************************************
1.��ǽ��_TRQ_Hook0()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook0( void (*func)(unsigned long TagNum) )
{
	if( func ){
		_TRQ_Hook0 = func;
	}
	else{
		_TRQ_Hook0 = _TRQ_Hook0_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook0);

/*****************************************************************************
1.��ǽ��_TRQ_Hook1()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook1( void (*func)(unsigned long TagNum,unsigned long arg1) )
{
	if( func ){
		_TRQ_Hook1 = func;
	}
	else{
		_TRQ_Hook1 = _TRQ_Hook1_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook1);

/*****************************************************************************
1.��ǽ��_TRQ_Hook2()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook2( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2) )
{
	if( func ){
		_TRQ_Hook2 = func;
	}
	else{
		_TRQ_Hook2 = _TRQ_Hook2_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook2);

/*****************************************************************************
1.��ǽ��_TRQ_Hook3()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook3( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3) )
{
	if( func ){
		_TRQ_Hook3 = func;
	}
	else{
		_TRQ_Hook3 = _TRQ_Hook3_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook3);

/*****************************************************************************
1.��ǽ��_TRQ_Hook4()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook4( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4) )
{
	if( func ){
		_TRQ_Hook4 = func;
	}
	else{
		_TRQ_Hook4 = _TRQ_Hook4_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook4);

/*****************************************************************************
1.��ǽ��_TRQ_Hook5()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook5( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5) )
{
	if( func ){
		_TRQ_Hook5 = func;
	}
	else{
		_TRQ_Hook5 = _TRQ_Hook5_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook5);

/*****************************************************************************
1.��ǽ��_TRQ_Hook6()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook6( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6) )
{
	if( func ){
		_TRQ_Hook6 = func;
	}
	else{
		_TRQ_Hook6 = _TRQ_Hook6_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook6);

/*****************************************************************************
1.��ǽ��_TRQ_Hook7()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook7( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7) )
{
	if( func ){
		_TRQ_Hook7 = func;
	}
	else{
		_TRQ_Hook7 = _TRQ_Hook7_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook7);

/*****************************************************************************
1.��ǽ��_TRQ_Hook8()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook8( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8) )
{
	if( func ){
		_TRQ_Hook8 = func;
	}
	else{
		_TRQ_Hook8 = _TRQ_Hook8_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook8);

/*****************************************************************************
1.��ǽ��_TRQ_Hook9()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook9( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9) )
{
	if( func ){
		_TRQ_Hook9 = func;
	}
	else{
		_TRQ_Hook9 = _TRQ_Hook9_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook9);

/*****************************************************************************
1.��ǽ��_TRQ_Hook10()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook10( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10) )
{
	if( func ){
		_TRQ_Hook10 = func;
	}
	else{
		_TRQ_Hook10 = _TRQ_Hook10_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook10);

/*****************************************************************************
1.��ǽ��_TRQ_Hook11()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook11( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11) )
{
	if( func ){
		_TRQ_Hook11 = func;
	}
	else{
		_TRQ_Hook11 = _TRQ_Hook11_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook11);

/*****************************************************************************
1.��ǽ��_TRQ_Hook12()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook12( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12) )
{
	if( func ){
		_TRQ_Hook12 = func;
	}
	else{
		_TRQ_Hook12 = _TRQ_Hook12_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook12);

/*****************************************************************************
1.��ǽ��_TRQ_Hook13()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook13( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13) )
{
	if( func ){
		_TRQ_Hook13 = func;
	}
	else{
		_TRQ_Hook13 = _TRQ_Hook13_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook13);

/*****************************************************************************
1.��ǽ��_TRQ_Hook14()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook14( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14) )
{
	if( func ){
		_TRQ_Hook14 = func;
	}
	else{
		_TRQ_Hook14 = _TRQ_Hook14_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook14);

/*****************************************************************************
1.��ǽ��_TRQ_Hook15()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook15( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15) )
{
	if( func ){
		_TRQ_Hook15 = func;
	}
	else{
		_TRQ_Hook15 = _TRQ_Hook15_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook15);

/*****************************************************************************
1.��ǽ��_TRQ_Hook16()�ؿ��Υ��ɥ쥹�����ꤹ��

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	func						�ؿ��ݥ���

4.����͡�
*****************************************************************************/
void smt_set_Hook16( void (*func)(unsigned long TagNum,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15,unsigned long arg16) )
{
	if( func ){
		_TRQ_Hook16 = func;
	}
	else{
		_TRQ_Hook16 = _TRQ_Hook16_nop;
	}
}
EXPORT_SYMBOL(smt_set_Hook16);


/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsSwitch_Process()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	processid					�ץ���ID

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsSwitch_Process_nop(unsigned long processid)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsSwitch_ThreadProcess()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	threadid					����å�ID
I/	processid					�ץ���ID

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsSwitch_ThreadProcess_nop(unsigned long threadid,unsigned long processid)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsSwitch_Process_Name()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	processid					�ץ���ID
I/	str							�ץ���̾��(����32ʸ����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsSwitch_Process_Name_nop(unsigned long processid,const char *str)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsSwitch_ThreadProcess_Name()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	threadid					����å�ID
I/	processid					�ץ���ID
I/	tname						����å�̾��(����32ʸ����
I/	pname						�ץ���̾��(����32ʸ����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsSwitch_ThreadProcess_Name_nop(unsigned long threadid,unsigned long processid,const char *tname,const char *pname)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsSwitch_Irq_in()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	irqid						���ID

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsSwitch_Irq_in_nop(unsigned long irqid)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsSwitch_Irq_out()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	irqid						���ID

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsSwitch_Irq_out_nop(unsigned long irqid)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsSwitch_Idle()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsSwitch_Idle_nop( void )
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall0()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall0_nop(int osc,_SMT_OS_CALL attr)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall1()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	arg1						����1����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall1_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall2()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��2)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall2_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall3()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��3)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall3_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall4()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��4)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall4_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall5()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��5)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall5_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall6()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��6)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall6_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall7()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��7)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall7_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall8()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��8)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall8_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall9()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��9)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall9_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall10()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��10)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall10_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall11()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��11)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall11_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall12()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��12)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall12_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall13()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��13)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall13_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall14()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��14)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall14_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall15()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��15)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall15_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���饤�֥��̤���������_SMT_OsCall16()�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	osc							OS���������
I/	attr						ȯ�Լ���(_SMT_OS_ATTR_CALL/_SMT_OS_ATTR_RET)
I/	argN(N=1��16)				����N����

4.����͡�						_SMT_OK:���ｪλ
								_SMT_NG:�۾ｪλ
*****************************************************************************/
static int _SMT_OsCall16_nop(int osc,_SMT_OS_CALL attr,unsigned long arg1,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5,unsigned long arg6,unsigned long arg7,unsigned long arg8,unsigned long arg9,unsigned long arg10,unsigned long arg11,unsigned long arg12,unsigned long arg13,unsigned long arg14,unsigned long arg15,unsigned long arg16)
{
	return( _SMT_OK );
}

/*****************************************************************************
1.��ǽ���ؿ�����HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�

4.����͡�
*****************************************************************************/
static void _TRQ_Hook0_nop(unsigned long TagNum)
{
}

/*****************************************************************************
1.��ǽ���ؿ�����[�����Ŀ�=1]/�и�[return�ͤ���]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����/return��

4.����͡�
*****************************************************************************/
static void _TRQ_Hook1_nop(unsigned long TagNum,unsigned long arg1 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=2]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2

4.����͡�
*****************************************************************************/
static void _TRQ_Hook2_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=3]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3

4.����͡�
*****************************************************************************/
static void _TRQ_Hook3_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=4]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4

4.����͡�
*****************************************************************************/
static void _TRQ_Hook4_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=5]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5

4.����͡�
*****************************************************************************/
static void _TRQ_Hook5_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=6]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5
I/	arg6						����6

4.����͡�
*****************************************************************************/
static void _TRQ_Hook6_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 ,unsigned long arg6 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=7]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5
I/	arg6						����6
I/	arg7						����7

4.����͡�
*****************************************************************************/
static void _TRQ_Hook7_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 ,unsigned long arg6 ,unsigned long arg7 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=8]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5
I/	arg6						����6
I/	arg7						����7
I/	arg8						����8

4.����͡�
*****************************************************************************/
static void _TRQ_Hook8_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 ,unsigned long arg6 ,unsigned long arg7 ,unsigned long arg8 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=9]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5
I/	arg6						����6
I/	arg7						����7
I/	arg8						����8
I/	arg9						����9

4.����͡�
*****************************************************************************/
static void _TRQ_Hook9_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 ,unsigned long arg6 ,unsigned long arg7 ,unsigned long arg8 ,unsigned long arg9 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=10]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5
I/	arg6						����6
I/	arg7						����7
I/	arg8						����8
I/	arg9						����9
I/	arg10						����10

4.����͡�
*****************************************************************************/
static void _TRQ_Hook10_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 ,unsigned long arg6 ,unsigned long arg7 ,unsigned long arg8 ,unsigned long arg9 ,unsigned long arg10 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=11]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5
I/	arg6						����6
I/	arg7						����7
I/	arg8						����8
I/	arg9						����9
I/	arg10						����10
I/	arg11						����11

4.����͡�
*****************************************************************************/
static void _TRQ_Hook11_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 ,unsigned long arg6 ,unsigned long arg7 ,unsigned long arg8 ,unsigned long arg9 ,unsigned long arg10 ,unsigned long arg11 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=12]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5
I/	arg6						����6
I/	arg7						����7
I/	arg8						����8
I/	arg9						����9
I/	arg10						����10
I/	arg11						����11
I/	arg12						����12

4.����͡�
*****************************************************************************/
static void _TRQ_Hook12_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 ,unsigned long arg6 ,unsigned long arg7 ,unsigned long arg8 ,unsigned long arg9 ,unsigned long arg10 ,unsigned long arg11 ,unsigned long arg12 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=13]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5
I/	arg6						����6
I/	arg7						����7
I/	arg8						����8
I/	arg9						����9
I/	arg10						����10
I/	arg11						����11
I/	arg12						����12
I/	arg13						����13

4.����͡�
*****************************************************************************/
static void _TRQ_Hook13_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 ,unsigned long arg6 ,unsigned long arg7 ,unsigned long arg8 ,unsigned long arg9 ,unsigned long arg10 ,unsigned long arg11 ,unsigned long arg12 ,unsigned long arg13 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=14]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5
I/	arg6						����6
I/	arg7						����7
I/	arg8						����8
I/	arg9						����9
I/	arg10						����10
I/	arg11						����11
I/	arg12						����12
I/	arg13						����13
I/	arg14						����14

4.����͡�
*****************************************************************************/
static void _TRQ_Hook14_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 ,unsigned long arg6 ,unsigned long arg7 ,unsigned long arg8 ,unsigned long arg9 ,unsigned long arg10 ,unsigned long arg11 ,unsigned long arg12 ,unsigned long arg13 ,unsigned long arg14 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=15]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5
I/	arg6						����6
I/	arg7						����7
I/	arg8						����8
I/	arg9						����9
I/	arg10						����10
I/	arg11						����11
I/	arg12						����12
I/	arg13						����13
I/	arg14						����14
I/	arg15						����15

4.����͡�
*****************************************************************************/
static void _TRQ_Hook15_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 ,unsigned long arg6 ,unsigned long arg7 ,unsigned long arg8 ,unsigned long arg9 ,unsigned long arg10 ,unsigned long arg11 ,unsigned long arg12 ,unsigned long arg13 ,unsigned long arg14 ,unsigned long arg15 )
{
}

/*****************************************************************************
1.��ǽ��
	�ؿ�����[�����Ŀ�=16]�ξ���HOOK�ؿ�

2.���¡���ա�

3.�����ϰ�����
I/O|�ѿ�̾					   |����
---+---------------------------+----------------------------------------------
I/	TagNum						�ؿ������å��ݥ�����ֹ�
I/	arg1						����1
I/	arg2						����2
I/	arg3						����3
I/	arg4						����4
I/	arg5						����5
I/	arg6						����6
I/	arg7						����7
I/	arg8						����8
I/	arg9						����9
I/	arg10						����10
I/	arg11						����11
I/	arg12						����12
I/	arg13						����13
I/	arg14						����14
I/	arg15						����15
I/	arg16						����16

4.����͡�
*****************************************************************************/
static void _TRQ_Hook16_nop(unsigned long TagNum ,unsigned long arg1 ,unsigned long arg2 ,unsigned long arg3 ,unsigned long arg4 ,unsigned long arg5 ,unsigned long arg6 ,unsigned long arg7 ,unsigned long arg8 ,unsigned long arg9 ,unsigned long arg10 ,unsigned long arg11 ,unsigned long arg12 ,unsigned long arg13 ,unsigned long arg14 ,unsigned long arg15 ,unsigned long arg16 )
{
}
