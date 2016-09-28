// public.h: 计算服务、图形客户端、控制程序的公有定义.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PUBLIC__INCLUDED_)
#define _PUBLIC___INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "varMdbi.h"
#include "WarnLog.h"
#include "varWarn.h"
#include "opfData.h"
#include "opfpara.h"
#include "visualdb.h"
#include "sysdata.h"

#include <vector>
#include <list>
#include <algorithm>

using namespace std;

const int PORT_UI_ONLINE=13080;         //在线端口号
const int PORT_UI_OFFLINE=13090;        //离线端口号
const int PORT_CTRL_ONLINE=13081;       //在线控制端口号

const short MAX_NET_MSG_LEN   = 1024;//最大网络报文记录长度

const short HOST_NAME_LENGTH  = 20;//最大主机名长度
const short USER_NAME_LENGTH  = 32;//最大用户名长度
const short PASSWORD_LENGTH   = 16; //最大密码长度

const short MAX_GROUPS_PERSTATION   = 3; //每厂站最大控制组数
const short MAX_SUBSTATION_ORDER  = 200; //最大厂站序号
/******************************************************************
**类名：MSGH_STRUCT
**描述：计算服务、图形客户端、控制程序相互通讯消息头结构
******************************************************************/
typedef struct MSGH_STRUCT 
{
  MSGH_STRUCT()
  {
    memset(this,0,sizeof(*this));
    iRecNun=1;
  }
  BYTE        byType;                  //消息类型，取值见如下定义
  int         iRecNun;                 //记录数
  int         iMsgLen;                 //报文内容长度,不包括本结构的内容总长
}MSGH_STRUCT;
//说明：
//    网络消息的结构格式为：MSGH_STRUCT+消息结构（MSG_LOGIN、MSG_SVRNOTIFY等）1、2...n;

//********NET_MSG的bytType成员取值***********/
const BYTE NET_MSG_LOGIN      =0;       //用户连接登陆(图形/控制-->计算服务)
const BYTE NET_MSG_SVRNOTIFY  =1;       //服务检测报文，用于判断网络是否中断或服务在运行（图形/控制->计算服务）
const BYTE NET_MSG_SETMODAL   =2;       //控制方式切换(图形-->计算服务)
const BYTE NET_MSG_SVRSTATUS  =3;       //计算服务器计算状态信息(计算服务-->图形/控制)
const BYTE NET_MSG_RUNCOMMAND =4;       //执行命令(图形-->计算服务->控制)
const BYTE NET_MSG_CMDRETURN  =5;       //产生命令返回(控制->计算服务)
const BYTE NET_MSG_EXERETURN  =6;       //执行命令返回(控制->计算服务)
const BYTE NET_MSG_WARNINFO   =7;       //通用告警信息
const BYTE NET_MSG_LOCKWARN   =8;       //闭锁信息(计算服务-->控制,转发设备上传的闭锁告警)
const BYTE NET_MSG_CMDCHANGE   =9;       //控制命令状态改变(图形-->计算服务->控制)
//********NET_MSG的bytType成员取值***********/

/******************************************************************
**类名：MSG_LOGIN
**描述：网络连接登陆结构
******************************************************************/
typedef struct MSG_LOGIN
{
  short shFuncType;                   //功能类型
  char  szNodeName[HOST_NAME_LENGTH]; //节点名
  char  szUserName[USER_NAME_LENGTH]; //用户名
  char  szPassword[PASSWORD_LENGTH];  //密码
  short shPermit;                      //许可内容,如登陆失败该值为零,否则为该帐号权限
}MSG_LOGIN;

/******************************************************************
**类名：MSG_CHECKSVR
**描述： 查询计算服务状态信息
******************************************************************/
typedef enum MSG_SVRNOTIFY
{
  NOTIFY_STATUS_CLIEXIT,        //用户通知计算服务退出连接
  NOTIFY_STATUS_QUESTION,       //查询计算服务状态
  NOTIFY_STATUS_SVRON,          //计算服务在运行
  NOTIFY_STATUS_SVRONOFF,       //计算服务退出运行
};

//********MSG_QUESTIONSVR的byNotify成员取值***********/
//********MSG_CHECKNET的byStatus成员取值***********/

/******************************************************************
**类名：MSG_SETMODAL
**描述：设置运行方式
******************************************************************/
typedef BYTE MSG_SETMODAL;   //运行方式，取值如下

const BYTE SETMODAL_MANUAL=0;          //手动控制
const BYTE SETMODAL_AUTOOPEN=1;        //自动开环
const BYTE SETMODAL_AUTOCLOSE=2;       //自动闭环

const CString MSG_MODAL[]={"手动控制","自动开环","自动闭环"};


/******************************************************************
**类名：MSG_SVRSTATUS
**描述：计算服务计算状态
******************************************************************/
typedef struct MSG_SVRSTATUS
{
  MSG_SVRSTATUS()
  {
    memset(this,0,sizeof(*this));
  }
  MSG_SETMODAL byRunModel;   //运行方式,成员取值见MSG_SETMODAL
  BYTE byCurProcess;         //当前运行进程,成员取值见MSG_RUNCOMMAND
  BYTE byProcStatus;         //当前运行进程状态,成员取值如下
  BYTE byOverProcess;        //已结束进程,成员取值如下
}MSG_SVRSTATUS;

//********MSG_SVRSTATUS的byProcStatus成员取值***********/
const BYTE MSG_PROCSTATUS_NONE     =0;     //等待状态
const BYTE MSG_PROCSTATUS_STARTRUN =1;     //开始运行
const BYTE MSG_PROCSTATUS_RUNEND   =2;     //运行结束
const BYTE MSG_PROCSTATUS_EXECCTRL =3;     //执行控制
const BYTE MSG_PROCSTATUS_EXECEND  =4;     //执行结束
const BYTE MSG_PROCSTATUS_STOPRUN  =5;     //停止运行命令
//********MSG_SVRSTATUS的byProcStatus成员取值***********/

//********MSG_SVRSTATUS的byOverProcess成员取值***********/
const BYTE MSG_OVERPROC_EMPTY  =0;       //无已运行进程
const BYTE MSG_OVERPROC_NTP    =1;       //拓扑已运行
const BYTE MSG_OVERPROC_SE     =1<<1;    //估计已运行
const BYTE MSG_OVERPROC_OPF    =1<<2;    //优化已运行
const BYTE MSG_OVERPROC_CTRL   =1<<3;    //控制已运行
//********MSG_SVRSTATUS的byOverProcess成员取值***********/

//********MSG_SVRSTATUS的成员序号***********/
const BYTE STATUS_INDEX_MODAL=1;        //控制模式状态序号
const BYTE STATUS_INDEX_CURPROC=1<<1;   //当前进程序号
const BYTE STATUS_INDEX_PROCSTAT=1<<2;  //当前进程状态序号
const BYTE STATUS_INDEX_OVERPROC=1<<3;  //已结束进程状态序号
//********MSG_SVRSTATUS的成员序号***********/

/******************************************************************
**类名：MSG_RUNCOMMAND
**描述：消息记录结构
******************************************************************/
typedef BYTE MSG_RUNCOMMAND; //执行指令，取值如下

const BYTE MSG_COMMAND_EMPTY    =0;       //无命令
const BYTE MSG_COMMAND_RUNNTP   =1;       //拓扑命令
const BYTE MSG_COMMAND_RUNSE    =2;       //状态估计
const BYTE MSG_COMMAND_RUNOPF   =3;       //优化
const BYTE MSG_COMMAND_CREATECMD=4;       //建立控制指令
const BYTE MSG_COMMAND_EXECCTRL =5;       //执行控制命令
const BYTE MSG_COMMAND_CHCMDSTATUS =6;    //改变控制命令状态
const BYTE MSG_COMMAND_RUNLIMIT =7;       //极限计算

const CString MSG_COMMAND[]={"","运行拓扑分析","运行状态估计","运行优化计算","生成控制指令","执行优化控制","运行极限计算"}; 

const CString EVENT_CREATECMD="建立控制命令";  //建立控制指令事件
const CString EVENT_EXECUTECMD="执行控制命令"; //建立控制指令事件

const BYTE CALCULATION_OTHER=0;				//其他优化计算
const BYTE CALCULATION_OPF=1;				//普通优化计算
const BYTE CALCULATION_LIMIT=2;				//极限优化计算
const BYTE CALCULATION_PROCESS=3;			//过程优化计算
const BYTE CALCULATION_SHANGHAI=4;			//上海优化计算
const char CALCULATION_TYPE[][20]={"其他","电压优化潮流","无功极限潮流","过程优化","上海电力优化"};
/******************************************************************
**类名：MSG_WARNINFO
**描述：通用告警信息
******************************************************************/
typedef struct MSG_WARNINFO
{
  SYSTEMTIME  warnTime;                         //告警时间
  char        szWarnInfo[WARN_INFO_LENGTH];     //告警信息
  short       shWarnMode;                       //告警处理方式,取值同WARN_TAG的shWarnMode
}MSG_WARNINFO;

/******************************************************************
**类名：MSG_LOCKWARN
**描述：闭锁告警信息
******************************************************************/
typedef WARN_LOCK MSG_LOCKWARN;

/******************************************************************
**类名：MSG_OPFCMD
**描述：优化命令告警信息
******************************************************************/
typedef refavc_opfCmd_table MSG_OPFCMD;


//等待事件返回
int WaitForEvent(CString szEventName,int iOverTime);
inline int WaitForEvent(CString szEventName,int iOverTime)
{
  int iResult=WAIT_FAILED;
  HANDLE hThreadEvents; 
  hThreadEvents = CreateEvent(NULL,TRUE,TRUE,szEventName); 
  if (hThreadEvents != NULL) 
  {
    ResetEvent(hThreadEvents);   
    iResult=WaitForSingleObject(hThreadEvents,iOverTime);
    CloseHandle(hThreadEvents);
  }
  return iResult; 
}

//响应事件
int ReponseEvent(CString szEventName);
inline int ReponseEvent(CString szEventName)
{
  HANDLE hThreadEvents=OpenEvent(EVENT_MODIFY_STATE,TRUE,szEventName);
  if(hThreadEvents!=NULL)
  {
    SetEvent(hThreadEvents);
    CloseHandle(hThreadEvents);
  }
  else
    return 1;
  return 0;
}

#endif