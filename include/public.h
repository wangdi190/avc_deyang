// public.h: �������ͼ�οͻ��ˡ����Ƴ���Ĺ��ж���.
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

const int PORT_UI_ONLINE=13080;         //���߶˿ں�
const int PORT_UI_OFFLINE=13090;        //���߶˿ں�
const int PORT_CTRL_ONLINE=13081;       //���߿��ƶ˿ں�

const short MAX_NET_MSG_LEN   = 1024;//������籨�ļ�¼����

const short HOST_NAME_LENGTH  = 20;//�������������
const short USER_NAME_LENGTH  = 32;//����û�������
const short PASSWORD_LENGTH   = 16; //������볤��

const short MAX_GROUPS_PERSTATION   = 3; //ÿ��վ����������
const short MAX_SUBSTATION_ORDER  = 200; //���վ���
/******************************************************************
**������MSGH_STRUCT
**�������������ͼ�οͻ��ˡ����Ƴ����໥ͨѶ��Ϣͷ�ṹ
******************************************************************/
typedef struct MSGH_STRUCT 
{
  MSGH_STRUCT()
  {
    memset(this,0,sizeof(*this));
    iRecNun=1;
  }
  BYTE        byType;                  //��Ϣ���ͣ�ȡֵ�����¶���
  int         iRecNun;                 //��¼��
  int         iMsgLen;                 //�������ݳ���,���������ṹ�������ܳ�
}MSGH_STRUCT;
//˵����
//    ������Ϣ�Ľṹ��ʽΪ��MSGH_STRUCT+��Ϣ�ṹ��MSG_LOGIN��MSG_SVRNOTIFY�ȣ�1��2...n;

//********NET_MSG��bytType��Աȡֵ***********/
const BYTE NET_MSG_LOGIN      =0;       //�û����ӵ�½(ͼ��/����-->�������)
const BYTE NET_MSG_SVRNOTIFY  =1;       //�����ⱨ�ģ������ж������Ƿ��жϻ���������У�ͼ��/����->�������
const BYTE NET_MSG_SETMODAL   =2;       //���Ʒ�ʽ�л�(ͼ��-->�������)
const BYTE NET_MSG_SVRSTATUS  =3;       //�������������״̬��Ϣ(�������-->ͼ��/����)
const BYTE NET_MSG_RUNCOMMAND =4;       //ִ������(ͼ��-->�������->����)
const BYTE NET_MSG_CMDRETURN  =5;       //���������(����->�������)
const BYTE NET_MSG_EXERETURN  =6;       //ִ�������(����->�������)
const BYTE NET_MSG_WARNINFO   =7;       //ͨ�ø澯��Ϣ
const BYTE NET_MSG_LOCKWARN   =8;       //������Ϣ(�������-->����,ת���豸�ϴ��ı����澯)
const BYTE NET_MSG_CMDCHANGE   =9;       //��������״̬�ı�(ͼ��-->�������->����)
//********NET_MSG��bytType��Աȡֵ***********/

/******************************************************************
**������MSG_LOGIN
**�������������ӵ�½�ṹ
******************************************************************/
typedef struct MSG_LOGIN
{
  short shFuncType;                   //��������
  char  szNodeName[HOST_NAME_LENGTH]; //�ڵ���
  char  szUserName[USER_NAME_LENGTH]; //�û���
  char  szPassword[PASSWORD_LENGTH];  //����
  short shPermit;                      //�������,���½ʧ�ܸ�ֵΪ��,����Ϊ���ʺ�Ȩ��
}MSG_LOGIN;

/******************************************************************
**������MSG_CHECKSVR
**������ ��ѯ�������״̬��Ϣ
******************************************************************/
typedef enum MSG_SVRNOTIFY
{
  NOTIFY_STATUS_CLIEXIT,        //�û�֪ͨ��������˳�����
  NOTIFY_STATUS_QUESTION,       //��ѯ�������״̬
  NOTIFY_STATUS_SVRON,          //�������������
  NOTIFY_STATUS_SVRONOFF,       //��������˳�����
};

//********MSG_QUESTIONSVR��byNotify��Աȡֵ***********/
//********MSG_CHECKNET��byStatus��Աȡֵ***********/

/******************************************************************
**������MSG_SETMODAL
**�������������з�ʽ
******************************************************************/
typedef BYTE MSG_SETMODAL;   //���з�ʽ��ȡֵ����

const BYTE SETMODAL_MANUAL=0;          //�ֶ�����
const BYTE SETMODAL_AUTOOPEN=1;        //�Զ�����
const BYTE SETMODAL_AUTOCLOSE=2;       //�Զ��ջ�

const CString MSG_MODAL[]={"�ֶ�����","�Զ�����","�Զ��ջ�"};


/******************************************************************
**������MSG_SVRSTATUS
**����������������״̬
******************************************************************/
typedef struct MSG_SVRSTATUS
{
  MSG_SVRSTATUS()
  {
    memset(this,0,sizeof(*this));
  }
  MSG_SETMODAL byRunModel;   //���з�ʽ,��Աȡֵ��MSG_SETMODAL
  BYTE byCurProcess;         //��ǰ���н���,��Աȡֵ��MSG_RUNCOMMAND
  BYTE byProcStatus;         //��ǰ���н���״̬,��Աȡֵ����
  BYTE byOverProcess;        //�ѽ�������,��Աȡֵ����
}MSG_SVRSTATUS;

//********MSG_SVRSTATUS��byProcStatus��Աȡֵ***********/
const BYTE MSG_PROCSTATUS_NONE     =0;     //�ȴ�״̬
const BYTE MSG_PROCSTATUS_STARTRUN =1;     //��ʼ����
const BYTE MSG_PROCSTATUS_RUNEND   =2;     //���н���
const BYTE MSG_PROCSTATUS_EXECCTRL =3;     //ִ�п���
const BYTE MSG_PROCSTATUS_EXECEND  =4;     //ִ�н���
const BYTE MSG_PROCSTATUS_STOPRUN  =5;     //ֹͣ��������
//********MSG_SVRSTATUS��byProcStatus��Աȡֵ***********/

//********MSG_SVRSTATUS��byOverProcess��Աȡֵ***********/
const BYTE MSG_OVERPROC_EMPTY  =0;       //�������н���
const BYTE MSG_OVERPROC_NTP    =1;       //����������
const BYTE MSG_OVERPROC_SE     =1<<1;    //����������
const BYTE MSG_OVERPROC_OPF    =1<<2;    //�Ż�������
const BYTE MSG_OVERPROC_CTRL   =1<<3;    //����������
//********MSG_SVRSTATUS��byOverProcess��Աȡֵ***********/

//********MSG_SVRSTATUS�ĳ�Ա���***********/
const BYTE STATUS_INDEX_MODAL=1;        //����ģʽ״̬���
const BYTE STATUS_INDEX_CURPROC=1<<1;   //��ǰ�������
const BYTE STATUS_INDEX_PROCSTAT=1<<2;  //��ǰ����״̬���
const BYTE STATUS_INDEX_OVERPROC=1<<3;  //�ѽ�������״̬���
//********MSG_SVRSTATUS�ĳ�Ա���***********/

/******************************************************************
**������MSG_RUNCOMMAND
**��������Ϣ��¼�ṹ
******************************************************************/
typedef BYTE MSG_RUNCOMMAND; //ִ��ָ�ȡֵ����

const BYTE MSG_COMMAND_EMPTY    =0;       //������
const BYTE MSG_COMMAND_RUNNTP   =1;       //��������
const BYTE MSG_COMMAND_RUNSE    =2;       //״̬����
const BYTE MSG_COMMAND_RUNOPF   =3;       //�Ż�
const BYTE MSG_COMMAND_CREATECMD=4;       //��������ָ��
const BYTE MSG_COMMAND_EXECCTRL =5;       //ִ�п�������
const BYTE MSG_COMMAND_CHCMDSTATUS =6;    //�ı��������״̬
const BYTE MSG_COMMAND_RUNLIMIT =7;       //���޼���

const CString MSG_COMMAND[]={"","�������˷���","����״̬����","�����Ż�����","���ɿ���ָ��","ִ���Ż�����","���м��޼���"}; 

const CString EVENT_CREATECMD="������������";  //��������ָ���¼�
const CString EVENT_EXECUTECMD="ִ�п�������"; //��������ָ���¼�

const BYTE CALCULATION_OTHER=0;				//�����Ż�����
const BYTE CALCULATION_OPF=1;				//��ͨ�Ż�����
const BYTE CALCULATION_LIMIT=2;				//�����Ż�����
const BYTE CALCULATION_PROCESS=3;			//�����Ż�����
const BYTE CALCULATION_SHANGHAI=4;			//�Ϻ��Ż�����
const char CALCULATION_TYPE[][20]={"����","��ѹ�Ż�����","�޹����޳���","�����Ż�","�Ϻ������Ż�"};
/******************************************************************
**������MSG_WARNINFO
**������ͨ�ø澯��Ϣ
******************************************************************/
typedef struct MSG_WARNINFO
{
  SYSTEMTIME  warnTime;                         //�澯ʱ��
  char        szWarnInfo[WARN_INFO_LENGTH];     //�澯��Ϣ
  short       shWarnMode;                       //�澯����ʽ,ȡֵͬWARN_TAG��shWarnMode
}MSG_WARNINFO;

/******************************************************************
**������MSG_LOCKWARN
**�����������澯��Ϣ
******************************************************************/
typedef WARN_LOCK MSG_LOCKWARN;

/******************************************************************
**������MSG_OPFCMD
**�������Ż�����澯��Ϣ
******************************************************************/
typedef refavc_opfCmd_table MSG_OPFCMD;


//�ȴ��¼�����
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

//��Ӧ�¼�
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