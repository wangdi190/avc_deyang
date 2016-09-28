/******************************************************************
** 文件名:sysData.h
** Copyright (c) 1998-2003*********星宇软件开发股份有限公司
** 编码 :柴若愚    日期:2003-8-25
** 修改人:         日期:
** 描述:本文件提供数据库的系统数据的数据结构和常量定义。
** 版本:1.0
**-----------------------------------------------------------------
******************************************************************/

#ifndef	__VARCS_SYSDATA__H
#define __VARCS_SYSDATA__H

const short SYSDATA_NAME_LENGTH = 50;
const short DEFAULT_COMMENT_LENGTH = 250;
const short SYSDATA_IPADD_LENGTH = 24;

/******************************************************************
**类名：TABLE_TABLE
**描述：TABLE_TABLE对应于数据库的表名表
******************************************************************/
struct TABLE_TABLE
{
  short shViewNo;  //编号
  char szViewName[SYSDATA_NAME_LENGTH];  //表名称
  char szDisplayName[SYSDATA_NAME_LENGTH];  //显示名称
  short shViewAttrib;  //属性，见下文的成员取值掩码
  char szViewClass[SYSDATA_NAME_LENGTH];  //类别
  short shFilterView;  //过滤表
  short shMaxRange;  //表容量
  BYTE byAccessLevel;  //访问级别
  BYTE byType;  //表类型，见下文的成员取值
  short shFieldNum;  //字段数
  short shRecLen;  //纪录长度
};

//****TABLE_TABLE的shViewAttrib成员取值掩码****************
const short TABLE_MEMDB_MASK =	0x01;//内存数据
const short TABLE_HISDB_MASK = 0x01<<1;//历史数据
const short TABLE_TEMDB_MASK = 0x01<<2;//临时数据
const short TABLE_INIT_MASK =	0x01<<3;//需初始化
const short TABLE_DBI_MASK =	0x01<<4;//可用DBI管理
const short TABLE_INFO_MASK =	0x01<<5;//信息选择
const short TABLE_REALTIME_MASK =	0x01<<6;//实时信息
const short TABLE_FIXNUM_MASK =	0x01<<7;//不可增减纪录
//*********************************************************

//****TABLE_TABLE的byType成员取值***********************
const unsigned char TABLE_COMMON_TYPE = 0;//普通表
const unsigned char TABLE_CYCLE_TYPE = 1;//循环表
//*********************************************************

/******************************************************************
**类名：FIELD_TABLE
**描述：FIELD_TABLE对应于数据库的字段表
******************************************************************/
struct FIELD_TABLE
{
  short shViewNo;  //表编号
  short shFieldNo;  //字段编号
  char szFieldName[SYSDATA_NAME_LENGTH];  //字段名
  char szDisplayName[SYSDATA_NAME_LENGTH];  //显示名称
  char szComment[DEFAULT_COMMENT_LENGTH];  //字段说明
  BYTE byDataType;  //数据类型，见下文的成员取值
  short shOffset;  //偏移量
  short shLength;  //字段长度
  short shFieldAttrib;  //属性，见下文的成员取值掩码
  BYTE byDecimalDigit;  //小数位数
  char szInitVal[SYSDATA_NAME_LENGTH];  //初始值
  char szMaxVal[SYSDATA_NAME_LENGTH];  //最大值
  char szMinVal[SYSDATA_NAME_LENGTH];  //最小值
  char szDefaultVal[SYSDATA_NAME_LENGTH];  //缺省值
  char szEnumString[DEFAULT_COMMENT_LENGTH];  //枚举字符串
};

//****FIELD_TABLE的byDataType成员取值**********************
const unsigned char FIELD_SIENUM_TYPE = 0;//单选
const unsigned char FIELD_MUENUM_TYPE = 1;//多选
const unsigned char FIELD_BYTE_TYPE = 2;//BYTE
const unsigned char FIELD_SHORT_TYPE = 3;//short
const unsigned char FIELD_INT_TYPE = 4;//int
const unsigned char FIELD_LONG_TYPE = 5;//long
const unsigned char FIELD_FLOAT_TYPE = 6;//float
const unsigned char FIELD_DOUBLE_TYPE = 7;//double
const unsigned char FIELD_STRING_TYPE = 8;//string
const unsigned char FIELD_DATETIME_TYPE = 9;//datetime
const unsigned char FIELD_FORMULA_TYPE = 10;//formula
const unsigned char FIELD_STRUCT_TYPE = 11;//struct
const unsigned char FIELD_JBYTE_TYPE = 12;//join_BYTE
const unsigned char FIELD_JSHORT_TYPE = 13;//join_short
const unsigned char FIELD_WTIME_TYPE = 14;//warn_time
const unsigned char FIELD_TIME_TYPE = 15;//time
//*********************************************************

//****FIELD_TABLE的shFieldAttrib成员取值掩码***************
const short COL_KEY_MASK = 0x01;//关键字
const short COL_NONULL_MASK = 0x01<<1;//非空
const short COL_DISPLAY_MASK = 0x01<<2;//可显示
const short COL_ALTER_MASK = 0x01<<3;//可改
const short COL_INIT_MASK = 0x01<<4;//初始化
const short COL_RECNAME_MASK = 0x01<<5;//记录名
const short COL_REALTIME_MASK = 0x01<<6;//实时
//*********************************************************

/******************************************************************
**类名：NODE_TABLE
**描述：NODE_TABLE对应于数据库的节点表
******************************************************************/
struct NODE_TABLE
{
  BYTE byNodeNo;  //节点号
  char szNodeName[SYSDATA_NAME_LENGTH];  //机器名
  char szNetaIpAddr[SYSDATA_IPADD_LENGTH];  //A网IP地址
  char szNetbIpAddr[SYSDATA_IPADD_LENGTH];  //B网IP地址
  BYTE byNodeType;  //类型，见下文的成员取值
  BYTE byTciType;  //前置机类型，见下文的成员取值
  BYTE byHisType;  //历史库类型，见下文的成员取值
  short shFuncType;  //功能类型，见下文的成员取值掩码
  short shWarnProc;  //告警处理，见下文的成员取值掩码
  BYTE byNetaStatus;  //A网状态，见下文的成员取值
  BYTE byNetbStatus;  //B网状态，取值同A网状态
  short shWarnMode;  //告警方式，见下文的成员取值掩码
};

//****NODE_TABLE的byNodeType成员取值***********************
const unsigned char NODE_WORKSTATION = 0;//工作站
const unsigned char NODE_MASTER_HOST = 1;//主机
const unsigned char NODE_STANDBY_HOST = 2;//热备用主机
//*********************************************************

//****NODE_TABLE的byTciType成员取值************************
const unsigned char NODE_NO_TCI = 0;//工作站
const unsigned char NODE_MASTER_TCI = 1;//主前置机
const unsigned char NODE_STANDBY_TCI = 2;//备用前置机
//*********************************************************

//****NODE_TABLE的byHisType成员取值************************
const unsigned char NODE_SLAVE_HISTORY = 0;//工作站
const unsigned char NODE_MASTER_HISTORY = 1;//历史库
//*********************************************************

//****NODE_TABLE的shFuncType成员取值掩码*******************
const short NODE_GE_MASK = 0x01;//图形监控
const short NODE_DBI_MASK = 0x01<<1;//实时数据管理
const short NODE_TCI_MASK = 0x01<<2;//通信接口
const short NODE_RTC_MASK = 0x01<<3;//遥控遥调
const short NODE_HISWARN_MASK = 0x01<<4;//历史告警
const short NODE_OPFSER_MASK = 0x01<<5;//优化控制服务
const short NODE_OFFSVR_MASK = 0X01<<5;//离线计算服务，与优化控制服务相同
const short NODE_OPFCLI_MASK = 0x01<<6;//优化控制客户
const short NODE_OFFCLI_MASK = 0x01<<6;//离线计算客户，与优化控制客户相同
const short NODE_REPORT_MASK = 0x01<<7;//报表
const short NODE_HISBROWSE_MASK = 0X01<<7;//历史数据浏览，与报表相同
const short NODE_USER_MASK = 0x01<<8;//用户管理
//*********************************************************

//****NODE_TABLE的shWarnProc成员取值掩码*******************
const short NODE_DISPLAY_WARN = 0x01;//告警显示
const short NODE_PRINT_WARN = 0x01<<1;//随机打印
const short NODE_VOICE_WARN = 0x01<<2;//声音告警
//*********************************************************

//****NODE_TABLE的byNetaStatus成员取值*********************
const unsigned char NODE_QUIT = 0;//退出
const unsigned char NODE_RUN = 1;//投入
//*********************************************************

//****NODE_TABLE的shWarnMode成员取值掩码*******************
const short WARN_DISPLAY_MASK = 0x01;//需显示
const short WARN_LOG_MASK = 0x01<<1;//需记录
const short WARN_PRINT_MASK = 0x01<<2;//需打印
const short WARN_VOICE_MASK = 0x01<<3;//需声音
//*********************************************************

/******************************************************************
**类名：PROGRAM_TABLE
**描述：PROGRAM_TABLE对应于数据库的程序描述表
******************************************************************/
struct PROGRAM_TABLE
{
  BYTE byProgramNo;  //程序号
  char szProgramName[SYSDATA_IPADD_LENGTH];  //程序名称
  int iSevrPort;  //服务端口
  int iBroadPort;  //广播端口
  BYTE byMaxProcess;  //最大进程数
  BYTE byMaxServProc;  //最大主机进程数
  BYTE byNodeMaxProc;  //节点最大进程数
};

/******************************************************************
**类名：PROCESS_TABLE
**描述：PROCESS_TABLE对应于数据库的进程状态表
******************************************************************/
struct PROCESS
{
  BYTE byNodeNo;  //节点号
  BYTE byProgramNo;  //程序号
  BYTE byProcessNum;  //进程数
};

/******************************************************************
**类名：USER_TABLE
**描述：USER_TABLE对应于数据库的用户权限表
******************************************************************/
struct USER_TABLE
{
  char szUserName[SYSDATA_NAME_LENGTH];  //用户名
  char szPassword[SYSDATA_NAME_LENGTH];  //密码
  BYTE byGroupNo;  //级别，见下文的成员取值
  short shPurview;  //权限，见下文的成员取值掩码
};

//****USER_TABLE的byGroupNo成员取值************************
const unsigned char USER_SUPER = 0;//超级用户
const unsigned char USER_SYSMAN = 1;//系统管理员
const unsigned char USER_MANAGER = 2;//管理员
const unsigned char USER_MADISP = 3;//主调度员
const unsigned char USER_DISPATCHER = 4;//调度员
const unsigned char USER_COMMON = 5;//一般人员
//*********************************************************

//****USER_TABLE的shPurview成员取值掩码********************
const short USER_BROWS_ATTRIB = 0x01;//查看属性
const short USER_ALTER_ATTRIB = 0x01<<1;//修改属性
const short USER_BROWS_DATA = 0x01<<2;//数据浏览
const short USER_RTC = 0x01<<3;//控制操作
const short USER_ALTER_REPORT = 0x01<<4;//报表修改
const short USER_ALTER_GRAPH = 0x01<<5;//图形修改
const short USER_ALTER_DB = 0x01<<6;//数据库修改
const short USER_MANAGE_USER = 0x01<<7;//用户管理
//*********************************************************


#endif //__VARCS_SYSDATA__H