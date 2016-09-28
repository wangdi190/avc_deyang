/******************************************************************
** 文件名:WarnLog.h
** Copyright (c) 1998-2003*********星宇软件开发股份有限公司
** 编码 :柴若愚    日期:2003-9-18
** 修改人:         日期:
** 描述:本文件提供告警日志数据的数据结构和常量定义。
** 版本:1.0
**-----------------------------------------------------------------
******************************************************************/

#ifndef	__VARCS_WARNLOG__H
#define __VARCS_WARNLOG__H

#include "opfData.h"
#include "visualdb.h"

const short WARN_INFO_LENGTH = 100;
const short WARN_SYS_LENGTH = 200;
const short WARN_USER_NAME = 50;

const short MAX_WARN_MSG_LEN = 6;//按最大告警数据结构长度计算不超过UDP的分片报文长度

/******************************************************************
**类名：SOE_WARN
**描述：SOE_WARN描述子站上传的SOE告警信息
******************************************************************/
struct SOE_WARN
{
  short shSourceNo;  //数据源号
  short shFacNo;  //厂号
  int object_no;//对象号
  FILETIME soe_time;//SOE时间
  BYTE object_val;//对象状态，见下文的成员取值
};

//****SOE_WARN的object_val成员取值*************************
const unsigned char WARN_SOE_OFF = 0;//分
const unsigned char WARN_SOE_ON = 1;//合
//*********************************************************

/******************************************************************
**类名：VQC_LOCK_WARN
**描述：VQC_LOCK_WARN描述VQC上传的闭锁告警信息
******************************************************************/
struct VQC_LOCK_WARN
{
  FILETIME tWarnTime; //告警时间
  BYTE byObjType; //对象类型，见下文的成员取值
  short shFacNo; //厂号
  short shObjNo; //对象序号
  BYTE byAttrib; //性质，见下文的成员取值
};

//****VQC_LOCK_WARN的byObjType成员取值*********************
const unsigned char VQC_LOCK_VQC = 0;//vqc
const unsigned char VQC_LOCK_BITRANS = 1;//双绕组变压器
const unsigned char VQC_LOCK_TRITRANS = 2;//三绕组变压器
const unsigned char VQC_LOCK_SHUNT = 3;//并联无功设备
//*********************************************************

//****VQC_LOCK_WARN的byAttrib成员取值*********************
const unsigned char VQC_LOCK_LOCK = 0;//闭锁
const unsigned char VQC_LOCK_UNLOCK = 1;//解除闭锁
//*********************************************************

/******************************************************************
**类名：WARN_LOCK
**描述：WARN_LOCK描述闭锁告警信息,对应数据库的闭锁告警表(warnLock_table)
******************************************************************/
struct WARN_LOCK
{
  FILETIME tLockTime; //闭锁时间
  BYTE byObjectType; //闭锁对象类型，见下文的成员取值
  short shObjectFac; //闭锁对象厂号
  short shObjectNo; //闭锁对象序号
  BYTE byLockType;  //操作类型，见下文的成员取值
  BYTE byObjStatus;  //对象闭锁状态，见下文的成员取值
  char szLockInfo[WARN_INFO_LENGTH]; //闭锁信息
};

//****WARN_LOCK的byObjectType成员取值**********************
const unsigned char WARN_LOCK_FACTORY = 0;//厂站
const unsigned char WARN_LOCK_BITRANS = 1;//双绕组变压器
const unsigned char WARN_LOCK_TRITRANS = 2;//三绕组变压器
const unsigned char WARN_LOCK_SHUNT = 3;//并联无功设备
const unsigned char WARN_LOCK_VARCS = 4;//varCS
//*********************************************************

//****WARN_LOCK的byLockType成员取值************************
const unsigned char WARN_LOCKTYPE_LOCK = 0;//闭锁
const unsigned char WARN_LOCKTYPE_UNLOCK = 1;//解除闭锁
//*********************************************************

//****WARN_LOCK的byObjStatus成员取值***********************
const unsigned char WARN_LOCKSTATUS_NORMAL = 0;//正常
const unsigned char WARN_LOCKSTATUS_LOCK = 1;//闭锁
//*********************************************************

/******************************************************************
**类名：WARN_OPERATE_LOG
**描述：WARN_OPERATE_LOG描述操作告警信息,对应数据库的操作日志(logOpe_table)
******************************************************************/
struct WARN_OPERATE_LOG
{
  FILETIME log_time; //操作时间
  char operator_name[WARN_USER_NAME]; //操作人名称
  char operation_info[WARN_INFO_LENGTH]; //操作内容
};

/******************************************************************
**类名：WARN_SYSTEM
**描述：WARN_SYSTEM描述系统告警信息,对应数据库的系统告警表(warnSys_table)
******************************************************************/
struct WARN_SYSTEM
{
  FILETIME tWarnTime; //告警时间
  char szWarnInfo[WARN_SYS_LENGTH]; //告警信息
};
const unsigned char WARN_SYSREST = 255;//复位

/******************************************************************
**类名：WARN_YK
**描述：WARN_YK描述遥控告警信息,对应数据库的遥控告警表(warnYk_table)
******************************************************************/
struct WARN_YK
{
  FILETIME tWarnTime; //告警时间
  short shFacNo; //厂号
  short shOrderNo; //序号
  char szUserName[WARN_USER_NAME]; //操作者
  BYTE byYkVal; //遥控操作，见下文的成员取值
  char szWarnInfo[WARN_INFO_LENGTH]; //告警信息
};

//****WARN_YK的byYkVal成员取值*****************************
const unsigned char WARN_YK_OFF = 0;//分
const unsigned char WARN_YK_ON = 1;//合
//*********************************************************

/******************************************************************
**类名：WARN_YT
**描述：WARN_YT描述遥调告警信息,对应数据库的遥调告警表(warnYt_table)
******************************************************************/
struct WARN_YT
{
  FILETIME tWarnTime; //告警时间
  short shFacNo; //厂号
  short shOrderNo; //序号
  char szUserName[WARN_USER_NAME]; //操作者
  short shCurrentPos; //当前位置
  BYTE byYtVal; //遥调操作，见下文的成员取值
  char szWarnInfo[WARN_INFO_LENGTH]; //告警信息
};

//****WARN_YT的byYtVal成员取值*****************************
const unsigned char WARN_YT_UP = 0;//升
const unsigned char WARN_YT_DOWN = 1;//降
//*********************************************************

/******************************************************************
**类名：WARN_YC
**描述：WARN_YC描述遥测告警信息,对应数据库的遥测告警表(warnYc_table)
******************************************************************/
struct WARN_YC
{
  FILETIME tWarnTime; //告警时间
  short shFacNo; //厂号
  short shOrderNo; //序号
  BYTE byType; //类型，见下文的成员取值
  float fYcVal; //遥测值
  char szWarnInfo[WARN_INFO_LENGTH]; //告警信息
};

//****WARN_YC的byType成员取值******************************
const unsigned char WARN_YC_BLOCK = 0;//封锁
const unsigned char WARN_YC_UNLOCK = 1;//解除封锁
const unsigned char WARN_YC_LIMIT = 2;//越限
const unsigned char WARN_YC_LIMIT_CONTINUE = 3;//连续越限
const unsigned char WARN_YC_RECOVER = 4;//越限恢复
const unsigned char WARN_YC_CHANGE = 5;//突变量
//*********************************************************

/******************************************************************
**类名：WARN_YX
**描述：WARN_YX描述遥信告警信息,对应数据库的遥信告警表(warnYx_table)
******************************************************************/
struct WARN_YX
{
  FILETIME tWarnTime; //告警时间
  short shFacNo; //厂号
  short shOrderNo; //序号
  BYTE byRefresh; //更新状态，见下文的成员取值
  BYTE byYxVal; //遥信值，见下文的成员取值
  BYTE byStatus; //遥信状态，见下文的成员取值
  char szWarnInfo[WARN_INFO_LENGTH]; //告警信息
};

//****WARN_YX的byRefresh成员取值***************************
const unsigned char WARN_YX_NORMAL = 0;//正常
const unsigned char WARN_YX_BLOCK = 1;//封锁
const unsigned char WARN_YX_UNLOCK = 2;//解除封锁
//*********************************************************

//****WARN_YX的byYxVal成员取值*****************************
const unsigned char WARN_YX_OFF = 0;//分
const unsigned char WARN_YX_ON = 1;//合
//*********************************************************

//****WARN_YX的byStatus成员取值****************************
const unsigned char WARN_YXSTATUS_NORMAL = 0;//正常
const unsigned char WARN_YXSTATUS_CHANGE = 1;//变位
//*********************************************************

/******************************************************************
**类名：WARN_SET
**描述：WARN_SET描述定值告警信息,对应数据库的定值告警表(warnSet_table)
******************************************************************/
struct WARN_SET
{
  FILETIME tWarnTime; //告警时间
  short shFacNo; //厂号
  BYTE byDevType; //设备类型，见下文的成员取值
  short shDeviceNo; //设备编号
  char szUserName[WARN_USER_NAME]; //操作者
  BYTE bySetType; //操作类型，见下文的成员取值
  float fHiVolSet; //电压定值上限
  float fLowVolSet; //电压定值下限
  float fHiVarSet; //无功/功率因数定值上限
  float fLowVarSet; //无功/功率因数定值下限
  char szWarnInfo[WARN_INFO_LENGTH]; //告警信息
};

//****WARN_SET的byDevType成员取值**************************
const unsigned char WARN_SET_BITRANS = 0;//双绕组变压器
const unsigned char WARN_SET_TRITRANS = 1;//三绕组变压器
//*********************************************************

//****WARN_SET的bySetType成员取值**************************
const unsigned char WARN_SET_SETTING = 0;//设置定值
const unsigned char WARN_SET_CANCEL = 1;//撤销定值
//*********************************************************

/******************************************************************
**类名：WARN_FACTORY
**描述：WARN_FACTORY描述厂站告警信息,对应数据库的厂站告警表(warnFac_table)
******************************************************************/
struct WARN_FACTORY
{
  FILETIME tWarnTime; //告警时间
  short shFacNo; //厂号
  char szWarnInfo[WARN_INFO_LENGTH]; //告警信息
};

/******************************************************************
**类名：WARN_RELAY_YX
**描述：WARN_RELAY_YX描述保护状态告警信息,对应数据库的保护状态告警表(warnRelayYx_table)
******************************************************************/
struct WARN_RELAY_YX
{
  FILETIME tWarnTime; //告警时间
  short shFacNo; //厂号
  short shOrderNo; //序号
  BYTE byRefresh; //更新状态，见下文的成员取值
  BYTE byStatus; //保护状态，见下文的成员取值
  BYTE byChange; //变化标记，见下文的成员取值
  char szWarnInfo[WARN_INFO_LENGTH]; //告警信息
};

//****WARN_RELAY_YX的byRefresh成员取值*********************
const unsigned char WARN_RELAYYX_NORMAL = 0;//正常
const unsigned char WARN_RELAYYX_BLOCK = 1;//封锁
const unsigned char WARN_RELAYYX_UNBLOCK = 2;//解除封锁
//*********************************************************

//****WARN_RELAY_YX的byStatus成员取值**********************
const unsigned char WARN_RELAYYX_NOACT = 0;//正常
const unsigned char WARN_RELAYYX_ACT = 1;//动作
//*********************************************************

//****WARN_RELAY_YX的byChange成员取值**********************
const unsigned char WARN_RELAYYX_NOCHANGE = 0;//正常
const unsigned char WARN_RELAYYX_CHANGE = 1;//动作
//*********************************************************

/******************************************************************
**类名：WARN_SOE_INFO
**描述：WARN_SOE_INFO描述soe告警信息,对应数据库的soe告警表(warnSOE_table)
******************************************************************/
struct WARN_SOE_INFO
{
  FILETIME tWarnTime; //告警时间
  short shFacNo; //厂号
  short shSourceNo; //数据源号
  int iObjNo; //对象号
  BYTE byObjVal; //对象状态，同SOE_WARN的object_val成员取值
  char szWarnInfo[WARN_INFO_LENGTH]; //告警信息
};

/******************************************************************
**类名：WARN_COMM
**描述：WARN_COMM描述通信告警信息,该信息保存于历史数据库的系统
        告警表(warnSys_table)
******************************************************************/
struct WARN_COMM
{
  FILETIME tWarnTime; //告警时间
  short shSourceNo;  //数据源号
  short shAddress;  //子站地址
  BYTE bySubType;  //子站类型，见下文的成员取值
  short shFacNo;  //厂号
  BYTE byUpStatus;  //上行通信状态，见下文的成员取值
  BYTE byDownStatus;  //下行通信状态，成员取值同上行通信状态
};

//****WARN_COMM的bySubType成员取值*************************
const unsigned char WARN_COMM_SUBSTATION = 0;//变电站
const unsigned char WARN_COMM_VQC = 1;//VQC
const unsigned char WARN_COMM_SCADA = 2;//SCADA
const unsigned char WARN_COMM_TRANSMIT = 3;//转发
//*********************************************************

//****WARN_COMM的byUpStatus成员取值************************
const unsigned char WARN_COMM_NORMAL = 0;//正常
const unsigned char WARN_COMM_ABNORMAL = 1;//异常
//*********************************************************

/******************************************************************
**类名：WARN_DEV_OPER
**描述：WARN_DEV_OPER描述设备操作告警信息,该信息保存于历史数据库的
        厂站告警表(warnFac_table)
******************************************************************/
struct WARN_DEV_OPER
{
  FILETIME tWarnTime; //告警时间
  short shDevType;  //设备类型，见下文的成员取值
  short shFacNo;  //厂号
  short shDevNo;  //序号，对于厂站不关心其序号
  BYTE byOper;  //操作，见下文的成员取值
  char operator_name[WARN_USER_NAME]; //操作人名称
};

//****WARN_DEV_OPER的shDevType成员取值*********************
const short WARN_DEV_FACTORY = 1;//厂站
const short WARN_DEV_VQC = 2;//VQC装置
const short WARN_DEV_BITRANS = 3;//双绕组变压器
const short WARN_DEV_TRITRANS = 4;//三绕组变压器
const short WARN_DEV_SHUNT = 5;//无功设备
const short WARN_DEV_BREAKER = 6;//开关
const short WARN_DEV_DISCLOSER = 7;//刀闸
const short WARN_DEV_GENERATOR = 8;//发电机
//*********************************************************

//****WARN_DEV_OPER的byOper成员取值************************
const unsigned char WARN_DEVOPER_QUIT = 0;//退出
const unsigned char WARN_DEVOPER_RUN = 1;//投入
//*********************************************************

/******************************************************************
**类名：WARN_OPF
**描述：WARN_OPF描述优化计算控制过程中的告警信息
******************************************************************/
struct WARN_OPF
{
  FILETIME tWarnTime; //告警时间
  BYTE byCalType; //计算类型，见下文的成员取值
  short shType;  //告警类型，见下文的成员取值
};

//****WARN_OPF的byCalType成员取值**************************
const unsigned char WARN_OPF_ONLINE = 0;//在线优化计算
const unsigned char WARN_OPF_OFFLINE = 1;//离线优化计算
//*********************************************************

//****WARN_OPF的shType成员取值*****************************
const short WARN_OPF_CALSTART = 0;//优化计算启动
const short WARN_OPF_CALSUCCESS = 1;//优化计算成功
const short WARN_OPF_CALFAIL = 2;//优化计算失败
const short WARN_OPF_CTRLSTART = 3;//优化控制启动
const short WARN_OPF_CTRLSUCCESS = 4;//优化控制成功
const short WARN_OPF_CTRLFAIL = 5;//优化控制失败
const short WARN_OPF_END = 6;//优化计算控制结束
const short WARN_OPF_HASCMD=7;//有优化控制命令
const short WARN_OPF_MULTIFAIL=8;//计算连续多次失败
//*********************************************************

/******************************************************************
**类名：WARN_BROADCAST_INFO
**描述：WARN_BROADCAST_INFO描述varcs系统内的广播信息
******************************************************************/
struct WARN_BROADCAST_INFO
{
  unsigned char byProgramId; //程序模块的编号,commData.h
  unsigned char byInfoType; //信息类型，见下文的成员取值
  short shInfoTag;  //信息标志，见下文的成员取值
};

//****WARN_BROADCAST_INFO的byInfoType成员取值**************
const unsigned char PROGRAM_STATUS = 0;//程序模块状态
//*********************************************************

//****WARN_BROADCAST_INFO的shInfoTag成员取值***************
const short PROGRAM_STATUS_NORMAL = 0;//程序模块正常
const short PROGRAM_STATUS_ABNORMAL = 1;//程序模块异常
//*********************************************************

/******************************************************************
**类名：WARN_VQCACT
**描述：WARN_VQCACT描述VQC上传动作记录信息
******************************************************************/
struct WARN_VQCACT
{
  FILETIME tActTime;  //动作时间
  short shFacNo;      //厂号
  int iObjNo;         //对象号
  BYTE byAction;  //动作内容
  BYTE byResult;  //动作结果，见下文的成员取值
};

//****WARN_VQCACT的byAction成员取值**********************
const unsigned char VQCACT_ACTION_OFF = 0; //分/降
const unsigned char VQCACT_ACTION_ON = 1;  //合/升
//*********************************************************

//****WARN_VQCACT的byResult成员取值***************
const short VQCACT_RESULT_SUCCESS = 1;//成功
const short VQCACT_RESULT_FAIL = 2;   //失败
const short VQCACT_RESULT_REJECT = 3; //拒动
const short VQCACT_RESULT_SLIP = 4;   //滑挡
const short VQCACT_RESULT_CANCEL = 5; //撤消
//*********************************************************


/*********************************************************
**结构名：WARN_SHIFTMODEL
**描述：WARN_SHIFTMODEL描述切换电网模型时的告警信息
******************************************************************/
struct  WARN_SHIFTDBMODEL
{
    FILETIME tWarnTime; //告警时间
    short shDbNo;//切换后的电网模型编号
};

/*********************************************************
**结构名：WARN_COMMAND
**描述：WARN_COMMAND描述控制命令的产生和处理结果
******************************************************************/
typedef refavc_opfCmd_table WARN_COMMAND;

/******************************************************************
**类名：WARN_TAG
**描述：WARN_TAG用于描述提交告警信息时确定告警类型的数据结构
******************************************************************/
struct WARN_TAG
{
  BYTE byWarnType; //告警类型，见下文的成员取值
  short shWarnMode;  //告警方式，见下文的成员取值掩码
};

//****WARN_TAG的Warn_Type成员取值**************************
const unsigned char	WARN_TYPE_LOCK = 0;//闭锁告警
const unsigned char	WARN_TYPE_OPERATE = 1;//操作日志
const unsigned char	WARN_TYPE_SYSTEM = 2;//系统告警
const unsigned char	WARN_TYPE_YK = 3;//遥控告警
const unsigned char	WARN_TYPE_YT = 4;//遥调告警
const unsigned char	WARN_TYPE_YC = 5;//遥测告警
const unsigned char	WARN_TYPE_YX = 6;//遥信告警
const unsigned char	WARN_TYPE_SET = 7;//定值告警
const unsigned char	WARN_TYPE_FACTORY = 8;//厂站告警
const unsigned char	WARN_TYPE_RELAYYX = 9;//保护状态告警
const unsigned char	WARN_TYPE_SOE = 10;//soe告警
const unsigned char	WARN_TYPE_COMM = 11;//通信告警
const unsigned char	WARN_TYPE_DEVOPER = 12;//设备操作告警
const unsigned char	WARN_TYPE_VQCLOCK = 13;//VQC上传闭锁告警
const unsigned char	WARN_TYPE_OPF = 14;//优化告警
const unsigned char	WARN_TYPE_VQCACT = 15;//VQC动作信息
const unsigned char	WARN_TYPE_BROADCAST_INFO = 16;//广播信息
const unsigned char	WARN_TYPE_SHIFTDBMODEL = 17;//切换电网模型告警
const unsigned char	WARN_TYPE_COMMAND = 18;//控制命令告警
//*********************************************************

//****WARN_TAG的shWarnMode成员取值掩码*********************
const short WARN_MODE_DISPLAY = 0x01;//需显示
const short WARN_MODE_LOG = 0x01<<1;//需记录
const short WARN_MODE_PRINT = 0x01<<2;//需打印
const short WARN_MODE_VOICE = 0x01<<3;//需声音
//*********************************************************

/******************************************************************
**类名：WARN_REC
**描述：WARN_REC综合描述各类告警信息，以便统一处理。
******************************************************************/
struct WARN_REC
{
  WARN_LOCK wLock; //闭锁告警
  WARN_OPERATE_LOG wOpe; //操作日志
  WARN_SYSTEM wSys; //系统告警
  WARN_YK wYk; //遥控告警
  WARN_YT wYt; //遥调告警
  WARN_YC wYc; //遥测告警
  WARN_YX wYx; //遥信告警
  WARN_SET wSet; //定值告警
  WARN_FACTORY wFac; //厂站告警
  WARN_RELAY_YX wRelayYx; //保护状态告警
  WARN_SOE_INFO wSoe; //SOE告警
  WARN_COMM wComm;//通信告警
  WARN_DEV_OPER wDevOper;//设备操作告警
  VQC_LOCK_WARN wVqcLock;//VQC上传闭锁告警
  WARN_OPF wOpf;//优化告警
  WARN_BROADCAST_INFO wBroadcastInfo;//广播信息
  WARN_VQCACT wVqcAct;//VQC动作信息
  WARN_SHIFTDBMODEL wShiftDbModel;//切换电网模型时的告警信息
  WARN_COMMAND wCommand;//控制命令告警;
};

/******************************************************************
**类名：WARN_INFO
**描述：WARN_INFO描述由varCS系统各程序模块提交的告警信息
******************************************************************/
struct WARN_INFO
{
  WARN_TAG warnTag;//告警类型
  WARN_REC warnRec;//告警记录
};

/******************************************************************
**类名：WARN_NET_MSG
**描述：WARN_NET_MSG描述varCS系统网络中广播的告警报文
******************************************************************/
struct WARN_NET_MSG
{
  int iWarnNum; //告警信息的数量，以WARN_INFO为单位
  WARN_INFO warn[MAX_WARN_MSG_LEN]; //告警信息
};

#endif //__VARCS_WARNLOG__H