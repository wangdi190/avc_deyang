/******************************************************************
** 文件名:opfPara.h
** Copyright (c) 1998-2003*********星宇软件开发股份有限公司
** 编码 :柴若愚    日期:2003-8-27
** 修改人:         日期:
** 描述:本文件提供数据库的优化计算参数的数据结构和常量定义。
** 版本:1.0
**-----------------------------------------------------------------
******************************************************************/

#ifndef	__VARCS_OPFPARAMETER__H
#define __VARCS_OPFPARAMETER__H

const short OPFPARA_NAME_LENGTH = 50;

/******************************************************************
**类名：LOCK_TABLE
**描述：LOCK_TABLE对应于数据库的闭锁定义表
******************************************************************/
struct LOCK_TABLE
{
  short shLockNo;  //编号
  BYTE byEventType;  //闭锁事件类型，见下文的成员取值
  short shEventFac;  //闭锁事件厂号
  short shEventNo;  //闭锁事件序号
  BYTE byObjectType;  //闭锁对象类型，见下文的成员取值
  short shObjectFac;  //闭锁对象厂号
  short shObjectNo;  //闭锁对象序号
  BYTE byYxVal;  //遥信闭锁值，见下文的成员取值
  short shWarnMode;  //告警方式，见下文的成员取值掩码
  BYTE byUnlockType;  //解除方式，见下文的成员取值
};

//****LOCK_TABLE的byEventType成员取值**********************
const unsigned char LOCK_EVENT_YX = 0;//遥信变位
const unsigned char LOCK_EVENT_YC = 1;//遥测越限
const unsigned char LOCK_EVENT_RELAY = 2;//保护动作
//*********************************************************

//****LOCK_TABLE的byObjectType成员取值*********************
const unsigned char LOCK_OBJ_FACTORY = 0;//厂站
const unsigned char LOCK_OBJ_BITRANS = 1;//双绕组变压器
const unsigned char LOCK_OBJ_TRITRANS = 2;//三绕组变压器
const unsigned char LOCK_OBJ_SHUNT = 3;//并联无功设备
const unsigned char LOCK_OBJ_VARCS = 4;//varCS
//*********************************************************

//****LOCK_TABLE的byYxVal成员取值**************************
const unsigned char LOCK_YX_OFF = 0;//分
const unsigned char LOCK_YX_ON = 1;//合
//*********************************************************

//****LOCK_TABLE的shWarnMode成员取值掩码*******************
const short LOCK_WARN_DISPLAY = 0x01;//需显示
const short LOCK_WARN_LOG = 0x01<<1;//需记录
const short LOCK_WARN_PRINT = 0x01<<2;//需打印
const short LOCK_WARN_VOICE = 0x01<<3;//需声音
//*********************************************************

//****LOCK_TABLE的byUnlockType成员取值*********************
const unsigned char LOCK_FREE_MANUAL = 0;//手工解除
const unsigned char LOCK_FREE_AUTO = 1;//自动解除
//*********************************************************

/******************************************************************
**类名：AREA_TABLE
**描述：AREA_TABLE对应于数据库的区域表
******************************************************************/
struct AREA_TABLE
{
  short shAreaNo;  //区域号
  char szAreaName[OPFPARA_NAME_LENGTH];  //区域名
  float fPA;  //计划有功输出
  float fPLA;  //传输交换容差
};

/******************************************************************
**类名：ZONE_TABLE
**描述：ZONE_TABLE对应于数据库的区段数据表
******************************************************************/
struct ZONE_TABLE
{
  short shZoneNo;  //区段号
  char szZoneName[OPFPARA_NAME_LENGTH];  //区段名
  BYTE byIT;  //优化类型，见下文的成员取值
  BYTE byLT;  //最小损耗类型，见下文的成员取值
  BYTE byMIZ;  //最大有功输出状态标志，见下文的成员取值
  float fLossDead;  //有功网损减少死区
  float fLimitDead;  //电压越限减少死区
  float fPrePLoss;  //优化前有功网损
  float fPostPLoss;  //优化后有功网损
  float fPreQLoss;  //优化前无功网损
  float fPostQLoss;  //优化后无功网损
};

//****ZONE_TABLE的byIT成员取值*****************************
const unsigned char ZONE_IT_NOOPF = 0;//不优化
const unsigned char ZONE_IT_OPF = 1;//优化
//*********************************************************

//****ZONE_TABLE的byLT成员取值*****************************
const unsigned char ZONE_LT_NOOPF = 0;//不优化
const unsigned char ZONE_LT_OPF = 1;//优化
//*********************************************************

//****ZONE_TABLE的byMIZ成员取值****************************
const unsigned char ZONE_MIZ00 = 0;//仅包括优化最小损耗的支路
const unsigned char ZONE_MIZ01 = 1;//除不优化最小损耗支路的所有支路
//*********************************************************

/******************************************************************
**类名：VOLLIMIT_TABLE
**描述：VOLLIMIT_TABLE对应于数据库的电压限制集表
******************************************************************/
struct VOLLIMIT_TABLE
{
  short shLimitNo;  //限值集号
  short shOrderNo;  //序号
  CTime tStartTime;  //起始时间
  CTime tEndTime;  //终止时间
  float fMax1st;  //一级最大值
  float fMin1st;  //一级最小值
  float fMax2st;  //二级最大值
  float fMin2st;  //二级最小值
  float fMax3st;  //三级最大值
  float fMin3st;  //三级最小值
};

/******************************************************************
**类名：VOLVAR_TABLE
**描述：VOLVAR_TABLE对应于数据库的电压变化限制集表
******************************************************************/
struct VOLVAR_TABLE
{
  short shLimitNo;  //限值集号
  short shOrderNo;  //序号
  CTime tStartTime;  //起始时间
  CTime tEndTime;  //终止时间
  float fMax1st;  //一级最大值
  float fMin1st;  //一级最小值
  float fMax2st;  //二级最大值
  float fMin2st;  //二级最小值
  float fMax3st;  //三级最大值
  float fMin3st;  //三级最小值
};

/******************************************************************
**类名：QSETLIM_TABLE
**描述：QSETLIM_TABLE对应于数据库的无功定值约束表
******************************************************************/
struct QSETLIM_TABLE
{
  short shLimitNo;  //约束集号
  short shOrderNo;  //序号
  CTime tStartTime;  //起始时间
  CTime tEndTime;  //终止时间
  float fUpLimit;  //无功/功率因数高限
  float fLowLimit;  //无功/功率因数低限
};

/******************************************************************
**类名：VSETLIM_TABLE
**描述：VSETLIM_TABLE对应于数据库的电压定值约束表
******************************************************************/
struct VSETLIM_TABLE
{
  short shLimitNo;  //约束集号
  short shOrderNo;  //序号
  CTime tStartTime;  //起始时间
  CTime tEndTime;  //终止时间
  float fUpLimit;  //电压高限
  float fLowLimit;  //电压低限
};

/******************************************************************
**类名：OPFEVENT_TABLE
**描述：OPFEVENT_TABLE对应于数据库的优化控制启动事件表
******************************************************************/
struct OPFEVENT_TABLE
{
  short shEventNo;  //编号
  BYTE byEventType;  //事件类型，见下文的成员取值
  short shSourceFac;  //事件厂号
  short shSourceNo;  //事件序号
  BYTE byYxVal;  //遥信值，见下文的成员取值
  float fChangeLimit;  //遥测变化限值绝对值
  short shRelay;  //启动延时
  float fLastValue;  //上次采样值
};

//****OPFEVENT_TABLE的byEventType成员取值******************
const unsigned char OPFEVENT_YX = 0;//遥信变位
const unsigned char OPFEVENT_YC = 1;//遥测越限
const unsigned char OPFEVENT_DELYC = 2;//突变量越限
//*********************************************************

//****OPFEVENT_TABLE的byYxVal成员取值**********************
const unsigned char OPFEVENT_YX_OFF = 0;//分
const unsigned char OPFEVENT_YX_ON = 1;//合
//*********************************************************

/******************************************************************
**类名：OPFSTART_TABLE
**描述：OPFSTART_TABLE对应于数据库的优化控制启动时刻表
******************************************************************/
struct OPFSTART_TABLE
{
  short shTimeNo;  //编号
  CTime tStartTime;  //启动时刻
};

/******************************************************************
**类名：OPFYCLIM_TABLE
**描述：OPFYCLIM_TABLE对应于数据库的量测变化限值表
******************************************************************/
struct OPFYCLIM_TABL
{
  short shLimitNo;  //编号
  short shYcFac;  //遥测厂号
  short shYcNo;  //遥测序号
  float fChangeLimit;  //变化量绝对值限值
};

/******************************************************************
**类名：OPFSET_TABLE
**描述：OPFSET_TABLE对应于数据库的优化控制参数表
******************************************************************/
struct OPFSET_TABLE
{
  short shAutoId;  //编号
  BYTE byRunMode;  //运行方式，见下文的成员取值
  BYTE byControlMode;  //控制执行等待时间(分钟)
  BYTE bySetType;  //无功定值类型，见下文的成员取值
  short shMaxCmd;  //1次最多控制数量
  BYTE byCtrlFail;  //控制过程异常处理，见下文的成员取值
  BYTE byObjPreAct;  //控制时未操作控制对象动作，见下文的成员取值
  short shSeTime;  //状态估计计算时间限值
  short shOpfTime;  //优化计算时间限值
  short shTriggerCyc;  //触发周期
  short shCalWarn;  //优化计算启动告警方式，同闭锁定义表告警方式取值
  short shCtrlWarn;  //优化控制启动告警方式，同闭锁定义表告警方式取值
  short shCtrlEndWarn;  //优化控制成功告警方式，同闭锁定义表告警方式取值
  short shFailWarn;  //优化失败告警方式，同闭锁定义表告警方式取值
  short shAutoLockWarn;  //自动闭锁告警方式，同闭锁定义表告警方式取值
  float fBaseMva;  //基准容量
  short shMaxTapReg;  //变压器最大连续调档数
};

//****OPFSET_TABLE的byRunMode成员取值**********************
const unsigned char OPF_RUN_MANUAL = 0;//手工运行
const unsigned char OPF_RUN_AUTOOPEN = 1;//自动开环
const unsigned char OPF_RUN_AUTOCLOSE = 2;//自动闭环
//*********************************************************

//****OPFSET_TABLE的bySetType成员取值**********************
const unsigned char OPF_Q_SET = 0;//无功功率
const unsigned char OPF_COS_SET = 1;//功率因数
//*********************************************************

//****OPFSET_TABLE的byCtrlFail成员取值**********************
const unsigned char OPF_FAIL_RECAL = 0;//重新计算
const unsigned char OPF_FAIL_QUIT = 1;//退出控制
//*********************************************************

//****OPFSET_TABLE的byObjPreAct成员取值********************
const unsigned char OPF_PRE_KEEP = 0;//继续控制
const unsigned char OPF_PRE_RECAL = 1;//重新计算
const unsigned char OPF_PRE_QUIT = 2;//退出控制
//*********************************************************

/******************************************************************
**类名：VOLLEVEL_TABLE
**描述：VOLLEVEL_TABLE对应于数据库的电压等级表
******************************************************************/
struct VOLLEVEL_TABLE
{
  BYTE byVolDegree;  //电压等级序号，见下文的成员取值
  float fBaseVol;  //基准电压
  float fSeLimit;  //量测估计合格范围
};

//****FACTORY_TABLE的byVolDegree成员取值*******************
const unsigned char VOLTAGE_LEVEL_380 = 0;//380V
const unsigned char VOLTAGE_LEVEL_3K = 1;//3kV
const unsigned char VOLTAGE_LEVEL_6K = 2;//6kV
const unsigned char VOLTAGE_LEVEL_10K = 3;//10kV
const unsigned char VOLTAGE_LEVEL_35K = 4;//35kV
const unsigned char VOLTAGE_LEVEL_63K = 5;//63kV
const unsigned char VOLTAGE_LEVEL_110K = 6;//110kV
const unsigned char VOLTAGE_LEVEL_220K = 7;//220kV
const unsigned char VOLTAGE_LEVEL_330K = 8;//330kV
const unsigned char VOLTAGE_LEVEL_500K = 9;//500kV
const unsigned char VOLTAGE_LEVEL_60K = 10;//60kV
const unsigned char VOLTAGE_LEVEL_132K = 11;//132kV
const unsigned char VOLTAGE_LEVEL_13K8 = 12;//13.8kV
const unsigned char VOLTAGE_LEVEL_13K2 = 13;//13.2kV
const unsigned char VOLTAGE_LEVEL_33K = 14;//33kV
const unsigned char VOLTAGE_LEVEL_24K = 15;//24kV
const unsigned char VOLTAGE_LEVEL_20K = 16;//20kV
//*********************************************************

#endif //__VARCS_OPFPARAMETER__H