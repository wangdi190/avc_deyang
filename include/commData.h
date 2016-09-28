/******************************************************************
** 文件名:commData.h
** Copyright (c) 1998-2003*********星宇软件开发股份有限公司
** 编码 :柴若愚    日期:2003-8-29
** 修改人:         日期:
** 描述:本文件提供数据库的公用数据结构和常量定义。
** 版本:1.0
**-----------------------------------------------------------------
******************************************************************/

#ifndef	__VARCS_COMMONDATA__H
#define __VARCS_COMMONDATA__H

//*********************************************************************
//**varCS系统使用专门的端口在模块间通过网络传递信息
const unsigned short SOCKPORT_WARN_BROADCAST = 17777;//告警UDP广播端口
const unsigned short SOCKPORT_TCI_REMOTE = 17778;//前置机遥控TCP端口
const unsigned short SOCKPORT_OPFWARN_LISTEN = 17789;//优化服务告警监听UDP广播端口
const unsigned short SOCKPORT_BROADCAST_INFO = 17780;//广播信息UDP广播端口

const UINT SHIFTMDBIDSOCKETPORT=17781;
//*********************************************************************

//*********************************************************************
//**varCS系统可以使用专门的windows消息在模块间传递信息
//**以下给出这些消息统一的注册字符串，关心这些消息的模块用相应的字符串
//**注册，并处理相关的windows消息
const char VARCS_HISWARN_QUIT[] = "VARCS_HISWARN_MODULE_QUIT";//历史告警服务退出
const char VARCS_SHIFTWARN_DBID[] = "VARCS_SHIFTWARN_DBID";//内存库切换告警
//*********************************************************************

const short SHORT_NULL = -9999;//数值类型字段的空值

//*********************************************************************
//**用户密码加密用的数值，用此数值与密码字符串的每个字符异或
const unsigned char PASSWORD_EXCLUSIVE_OR = 127;
//*********************************************************************

//*********************************************************************
//**varCS系统各程序模块的编号，唯一标识各程序模块。
//**用于程序描述表（program_table）中程序号字段取值

const unsigned char VARCS_TCI_MODULE = 1;//通信接口
const unsigned char VARCS_GE_MODULE = 2;//图形监控
const unsigned char VARCS_DBI_MODULE = 3;//实时数据管理
const unsigned char VARCS_HISWARN_MODULE = 4;//历史告警服务
const unsigned char VARCS_OPFSVR_MODULE = 5;//优化控制服务
const unsigned char VARCS_OPFCLI_MODULE = 6;//优化控制客户
const unsigned char VARCS_HISBROW_MODULE = 7;//历史数据浏览
const unsigned char VARCS_RTC_MODULE = 8;//遥控遥调
const unsigned char VARCS_USER_MODULE = 9;//用户管理
const unsigned char VARCS_OFFSVR_MODULE = 10;//离线计算服务
const unsigned char VARCS_OFFCLI_MODULE = 11;//离线计算客户
const unsigned char VARCS_RPT_MODULE = 12;//报表
const unsigned char VARCS_MDBI_MODULE = 13;//内存库接口
const unsigned char VARCS_MRTDB_MODULE = 14;//内存库主服务
const unsigned char VARCS_CRTDB_MODULE = 15;//内存库客户服务
const unsigned char VARCS_HISDB_MODULE = 16;//历史库
//*********************************************************************

//*********************************************************************
//**varCS图形中各图元的编号，唯一标识1种图元类型
//**用于图元参数关联表OBJLINK_TABLE的shObjType字段取值*******
/*const short METAFIG_FACTORY = 1;//厂站
const short METAFIG_VQC = 2;//VQC装置
const short METAFIG_BITRANS = 3;//双绕组变压器
const short METAFIG_TRITRANS = 4;//三绕组变压器
const short METAFIG_CAPACITANCE = 5;//电容
const short METAFIG_REACTANCE = 6;//电抗
const short METAFIG_BREAKER = 7;//开关
const short METAFIG_DISCLOSER = 8;//刀闸
const short METAFIG_GENERATOR = 9;//发电机
const short METAFIG_LOAD = 10;//负荷
const short METAFIG_BUS = 11;//母线
const short METAFIG_LINE = 12;//线路
const short METAFIG_TNODE = 13;//T接点
const short METAFIG_YC = 14;//遥测
const short METAFIG_YX = 15;//遥信
const short METAFIG_PULSE = 16;//电度
const short METAFIG_YK = 17;//遥控
const short METAFIG_YT = 18;//遥调
const short METAFIG_RELAY = 19;//保护
const short METAFIG_RELAY_YX = 20;//保护状态信息*/
const short METAFIG_VARCS = 21;//varCS系统
//*********************************************************************

/******************************************************************
**类名：NET_STATUS
**描述：NET_STATUS说明网络状态
******************************************************************/
struct NET_STATUS
{
	BYTE byNetaStatus;  //A网状态，见下文的成员取值
	BYTE byNetbStatus;  //B网状态，取值同A网状态
};

//****NET_STATUS的byNetaStatus成员取值*********************
const unsigned char NET_OFFLINE = 0;//退出
const unsigned char NET_ONLINE = 1;//投入
//*********************************************************

/******************************************************************
**类名：OBJECT_ID
**描述：OBJECT_ID用于表示设备、厂站、量测及varCS系统
******************************************************************/
struct OBJECT_ID
{
	OBJECT_ID()
	{memset(this, 0, sizeof(OBJECT_ID));};
		
	short shDbNo; //内存数据库编号
	short shObjType;  //对象类型，取上文图元编号
	short shObjectFac;  //对象厂号，对于设备、量测给出其所属厂站（厂站表中厂号）
	//对于线路、T接点、varCS系统,不关心其厂号
	DWORD shObjectNo;  //对象序号，对于设备、量测给出其对应的内存库表中的序号
	//对于厂站、varCS系统,不关心其序号
	char pdb[30];
	char ptable[30];
};

/******************************************************************
**类名：ID_CODE
**描述：ID_CODE用于标识厂站的设备、量测
******************************************************************/
struct ID_CODE
{
	short shDbNo; //内存数据库编号
	short shObjectFac;  //对象厂号，对于设备、量测给出其所属厂站（厂站表中厂号）
	short shObjectNo;  //对象序号，对于设备、量测给出其对应的内存库表中的序号
};

/******************************************************************
**类名：MESG_ID
**描述：MESG_ID用于表示报文内的数据编号
******************************************************************/
struct MESG_ID
{
	short shDbNo; //内存数据库编号
	short shSourceNo;  //数据源号
	short shFacNo;  //厂号
	short shFrameOrder;  //报文序号
};

/******************************************************************
**类名：COMM_STATUS
**描述：COMM_STATUS用于表示通信状态
******************************************************************/
struct COMM_STATUS
{
	BYTE byUpComm;  //上行通信状态，同SOURCE_TABLE的byUpComm成员取值
	BYTE byDownComm;  //下行通信状态，同SOURCE_TABLE的byUpComm成员取值
};

/******************************************************************
**类名：YC_VS
**描述：YC_VS用于表示遥测值及其状态
******************************************************************/
struct YC_VS
{
	float fValue;  //遥测实际值
	BYTE byRefresh;  //更新状态，同YC_TABLE的byRefresh成员取值
	BYTE byLimitStatus;  //越限状态，同YC_TABLE的byLimitStatus成员取值
	short shWarnMode;  //告警方式
};

/******************************************************************
**类名：DEVICE_STATUS
**描述：DEVICE_STATUS用于表示设备的状态
******************************************************************/
struct DEVICE_STATUS
{
	short byStatus;  //工作状态，同FACTORY_TABLE的byFacStatus成员取值
	BYTE byLock;  //闭锁状态，同FACTORY_TABLE的byLock成员取值
	short shWarnMode;  //告警方式
};

/******************************************************************
**类名：FACTORY_STATUS
**描述：FACTORY_STATUS用于表示厂站的状态
******************************************************************/
struct FACTORY_STATUS
{
	BYTE byStatus;  //工作状态，同FACTORY_TABLE的byFacStatus成员取值
	BYTE byLock;  //闭锁状态，同FACTORY_TABLE的byLock成员取值
	BYTE byRefresh;  //更新状态，同FACTORY_TABLE的byRefresh成员取值
	short shWarnMode;  //告警方式
};

/******************************************************************
**类名：YX_VS
**描述：YX_VS用于表示遥信值及其状态
******************************************************************/
struct YX_VS
{
	BYTE byValue;  //遥信值，同YX_TABLE的byValue成员取值
	BYTE byRefresh;  //更新状态，同YX_TABLE的byRefresh成员取值
	BYTE byStatus;  //遥信状态，同YX_TABLE的byStatus成员取值
	short shWarnMode;  //告警方式
};

/******************************************************************
**类名：PULSE_VS
**描述：PULSE_VS用于表示电能脉冲值及其状态
******************************************************************/
struct PULSE_VS
{
	float fValue;  //电能脉冲值
	BYTE byRefresh;  //更新状态，同PULSE_TABLE的byRefresh成员取值
	short shWarnMode;  //告警方式
};

/******************************************************************
**类名：RELAYYX_VS
**描述：RELAYYX_VS用于表示保护状态
******************************************************************/
struct RELAYYX_VS
{
	BYTE byStatus;  //保护状态，同RELAYYX_TABLE的byStatus成员取值
	BYTE byRefresh;  //更新状态，同RELAYYX_TABLE的byRefresh成员取值
	short shWarnMode;  //告警方式
};

#endif //__VARCS_COMMONDATA__H