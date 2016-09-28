/******************************************************************
** �ļ���:WarnLog.h
** Copyright (c) 1998-2003*********������������ɷ����޹�˾
** ���� :������    ����:2003-9-18
** �޸���:         ����:
** ����:���ļ��ṩ�澯��־���ݵ����ݽṹ�ͳ������塣
** �汾:1.0
**-----------------------------------------------------------------
******************************************************************/

#ifndef	__VARCS_WARNLOG__H
#define __VARCS_WARNLOG__H

#include "opfData.h"
#include "visualdb.h"

const short WARN_INFO_LENGTH = 100;
const short WARN_SYS_LENGTH = 200;
const short WARN_USER_NAME = 50;

const short MAX_WARN_MSG_LEN = 6;//�����澯���ݽṹ���ȼ��㲻����UDP�ķ�Ƭ���ĳ���

/******************************************************************
**������SOE_WARN
**������SOE_WARN������վ�ϴ���SOE�澯��Ϣ
******************************************************************/
struct SOE_WARN
{
  short shSourceNo;  //����Դ��
  short shFacNo;  //����
  int object_no;//�����
  FILETIME soe_time;//SOEʱ��
  BYTE object_val;//����״̬�������ĵĳ�Աȡֵ
};

//****SOE_WARN��object_val��Աȡֵ*************************
const unsigned char WARN_SOE_OFF = 0;//��
const unsigned char WARN_SOE_ON = 1;//��
//*********************************************************

/******************************************************************
**������VQC_LOCK_WARN
**������VQC_LOCK_WARN����VQC�ϴ��ı����澯��Ϣ
******************************************************************/
struct VQC_LOCK_WARN
{
  FILETIME tWarnTime; //�澯ʱ��
  BYTE byObjType; //�������ͣ������ĵĳ�Աȡֵ
  short shFacNo; //����
  short shObjNo; //�������
  BYTE byAttrib; //���ʣ������ĵĳ�Աȡֵ
};

//****VQC_LOCK_WARN��byObjType��Աȡֵ*********************
const unsigned char VQC_LOCK_VQC = 0;//vqc
const unsigned char VQC_LOCK_BITRANS = 1;//˫�����ѹ��
const unsigned char VQC_LOCK_TRITRANS = 2;//�������ѹ��
const unsigned char VQC_LOCK_SHUNT = 3;//�����޹��豸
//*********************************************************

//****VQC_LOCK_WARN��byAttrib��Աȡֵ*********************
const unsigned char VQC_LOCK_LOCK = 0;//����
const unsigned char VQC_LOCK_UNLOCK = 1;//�������
//*********************************************************

/******************************************************************
**������WARN_LOCK
**������WARN_LOCK���������澯��Ϣ,��Ӧ���ݿ�ı����澯��(warnLock_table)
******************************************************************/
struct WARN_LOCK
{
  FILETIME tLockTime; //����ʱ��
  BYTE byObjectType; //�����������ͣ������ĵĳ�Աȡֵ
  short shObjectFac; //�������󳧺�
  short shObjectNo; //�����������
  BYTE byLockType;  //�������ͣ������ĵĳ�Աȡֵ
  BYTE byObjStatus;  //�������״̬�������ĵĳ�Աȡֵ
  char szLockInfo[WARN_INFO_LENGTH]; //������Ϣ
};

//****WARN_LOCK��byObjectType��Աȡֵ**********************
const unsigned char WARN_LOCK_FACTORY = 0;//��վ
const unsigned char WARN_LOCK_BITRANS = 1;//˫�����ѹ��
const unsigned char WARN_LOCK_TRITRANS = 2;//�������ѹ��
const unsigned char WARN_LOCK_SHUNT = 3;//�����޹��豸
const unsigned char WARN_LOCK_VARCS = 4;//varCS
//*********************************************************

//****WARN_LOCK��byLockType��Աȡֵ************************
const unsigned char WARN_LOCKTYPE_LOCK = 0;//����
const unsigned char WARN_LOCKTYPE_UNLOCK = 1;//�������
//*********************************************************

//****WARN_LOCK��byObjStatus��Աȡֵ***********************
const unsigned char WARN_LOCKSTATUS_NORMAL = 0;//����
const unsigned char WARN_LOCKSTATUS_LOCK = 1;//����
//*********************************************************

/******************************************************************
**������WARN_OPERATE_LOG
**������WARN_OPERATE_LOG���������澯��Ϣ,��Ӧ���ݿ�Ĳ�����־(logOpe_table)
******************************************************************/
struct WARN_OPERATE_LOG
{
  FILETIME log_time; //����ʱ��
  char operator_name[WARN_USER_NAME]; //����������
  char operation_info[WARN_INFO_LENGTH]; //��������
};

/******************************************************************
**������WARN_SYSTEM
**������WARN_SYSTEM����ϵͳ�澯��Ϣ,��Ӧ���ݿ��ϵͳ�澯��(warnSys_table)
******************************************************************/
struct WARN_SYSTEM
{
  FILETIME tWarnTime; //�澯ʱ��
  char szWarnInfo[WARN_SYS_LENGTH]; //�澯��Ϣ
};
const unsigned char WARN_SYSREST = 255;//��λ

/******************************************************************
**������WARN_YK
**������WARN_YK����ң�ظ澯��Ϣ,��Ӧ���ݿ��ң�ظ澯��(warnYk_table)
******************************************************************/
struct WARN_YK
{
  FILETIME tWarnTime; //�澯ʱ��
  short shFacNo; //����
  short shOrderNo; //���
  char szUserName[WARN_USER_NAME]; //������
  BYTE byYkVal; //ң�ز����������ĵĳ�Աȡֵ
  char szWarnInfo[WARN_INFO_LENGTH]; //�澯��Ϣ
};

//****WARN_YK��byYkVal��Աȡֵ*****************************
const unsigned char WARN_YK_OFF = 0;//��
const unsigned char WARN_YK_ON = 1;//��
//*********************************************************

/******************************************************************
**������WARN_YT
**������WARN_YT����ң���澯��Ϣ,��Ӧ���ݿ��ң���澯��(warnYt_table)
******************************************************************/
struct WARN_YT
{
  FILETIME tWarnTime; //�澯ʱ��
  short shFacNo; //����
  short shOrderNo; //���
  char szUserName[WARN_USER_NAME]; //������
  short shCurrentPos; //��ǰλ��
  BYTE byYtVal; //ң�������������ĵĳ�Աȡֵ
  char szWarnInfo[WARN_INFO_LENGTH]; //�澯��Ϣ
};

//****WARN_YT��byYtVal��Աȡֵ*****************************
const unsigned char WARN_YT_UP = 0;//��
const unsigned char WARN_YT_DOWN = 1;//��
//*********************************************************

/******************************************************************
**������WARN_YC
**������WARN_YC����ң��澯��Ϣ,��Ӧ���ݿ��ң��澯��(warnYc_table)
******************************************************************/
struct WARN_YC
{
  FILETIME tWarnTime; //�澯ʱ��
  short shFacNo; //����
  short shOrderNo; //���
  BYTE byType; //���ͣ������ĵĳ�Աȡֵ
  float fYcVal; //ң��ֵ
  char szWarnInfo[WARN_INFO_LENGTH]; //�澯��Ϣ
};

//****WARN_YC��byType��Աȡֵ******************************
const unsigned char WARN_YC_BLOCK = 0;//����
const unsigned char WARN_YC_UNLOCK = 1;//�������
const unsigned char WARN_YC_LIMIT = 2;//Խ��
const unsigned char WARN_YC_LIMIT_CONTINUE = 3;//����Խ��
const unsigned char WARN_YC_RECOVER = 4;//Խ�޻ָ�
const unsigned char WARN_YC_CHANGE = 5;//ͻ����
//*********************************************************

/******************************************************************
**������WARN_YX
**������WARN_YX����ң�Ÿ澯��Ϣ,��Ӧ���ݿ��ң�Ÿ澯��(warnYx_table)
******************************************************************/
struct WARN_YX
{
  FILETIME tWarnTime; //�澯ʱ��
  short shFacNo; //����
  short shOrderNo; //���
  BYTE byRefresh; //����״̬�������ĵĳ�Աȡֵ
  BYTE byYxVal; //ң��ֵ�������ĵĳ�Աȡֵ
  BYTE byStatus; //ң��״̬�������ĵĳ�Աȡֵ
  char szWarnInfo[WARN_INFO_LENGTH]; //�澯��Ϣ
};

//****WARN_YX��byRefresh��Աȡֵ***************************
const unsigned char WARN_YX_NORMAL = 0;//����
const unsigned char WARN_YX_BLOCK = 1;//����
const unsigned char WARN_YX_UNLOCK = 2;//�������
//*********************************************************

//****WARN_YX��byYxVal��Աȡֵ*****************************
const unsigned char WARN_YX_OFF = 0;//��
const unsigned char WARN_YX_ON = 1;//��
//*********************************************************

//****WARN_YX��byStatus��Աȡֵ****************************
const unsigned char WARN_YXSTATUS_NORMAL = 0;//����
const unsigned char WARN_YXSTATUS_CHANGE = 1;//��λ
//*********************************************************

/******************************************************************
**������WARN_SET
**������WARN_SET������ֵ�澯��Ϣ,��Ӧ���ݿ�Ķ�ֵ�澯��(warnSet_table)
******************************************************************/
struct WARN_SET
{
  FILETIME tWarnTime; //�澯ʱ��
  short shFacNo; //����
  BYTE byDevType; //�豸���ͣ������ĵĳ�Աȡֵ
  short shDeviceNo; //�豸���
  char szUserName[WARN_USER_NAME]; //������
  BYTE bySetType; //�������ͣ������ĵĳ�Աȡֵ
  float fHiVolSet; //��ѹ��ֵ����
  float fLowVolSet; //��ѹ��ֵ����
  float fHiVarSet; //�޹�/����������ֵ����
  float fLowVarSet; //�޹�/����������ֵ����
  char szWarnInfo[WARN_INFO_LENGTH]; //�澯��Ϣ
};

//****WARN_SET��byDevType��Աȡֵ**************************
const unsigned char WARN_SET_BITRANS = 0;//˫�����ѹ��
const unsigned char WARN_SET_TRITRANS = 1;//�������ѹ��
//*********************************************************

//****WARN_SET��bySetType��Աȡֵ**************************
const unsigned char WARN_SET_SETTING = 0;//���ö�ֵ
const unsigned char WARN_SET_CANCEL = 1;//������ֵ
//*********************************************************

/******************************************************************
**������WARN_FACTORY
**������WARN_FACTORY������վ�澯��Ϣ,��Ӧ���ݿ�ĳ�վ�澯��(warnFac_table)
******************************************************************/
struct WARN_FACTORY
{
  FILETIME tWarnTime; //�澯ʱ��
  short shFacNo; //����
  char szWarnInfo[WARN_INFO_LENGTH]; //�澯��Ϣ
};

/******************************************************************
**������WARN_RELAY_YX
**������WARN_RELAY_YX��������״̬�澯��Ϣ,��Ӧ���ݿ�ı���״̬�澯��(warnRelayYx_table)
******************************************************************/
struct WARN_RELAY_YX
{
  FILETIME tWarnTime; //�澯ʱ��
  short shFacNo; //����
  short shOrderNo; //���
  BYTE byRefresh; //����״̬�������ĵĳ�Աȡֵ
  BYTE byStatus; //����״̬�������ĵĳ�Աȡֵ
  BYTE byChange; //�仯��ǣ������ĵĳ�Աȡֵ
  char szWarnInfo[WARN_INFO_LENGTH]; //�澯��Ϣ
};

//****WARN_RELAY_YX��byRefresh��Աȡֵ*********************
const unsigned char WARN_RELAYYX_NORMAL = 0;//����
const unsigned char WARN_RELAYYX_BLOCK = 1;//����
const unsigned char WARN_RELAYYX_UNBLOCK = 2;//�������
//*********************************************************

//****WARN_RELAY_YX��byStatus��Աȡֵ**********************
const unsigned char WARN_RELAYYX_NOACT = 0;//����
const unsigned char WARN_RELAYYX_ACT = 1;//����
//*********************************************************

//****WARN_RELAY_YX��byChange��Աȡֵ**********************
const unsigned char WARN_RELAYYX_NOCHANGE = 0;//����
const unsigned char WARN_RELAYYX_CHANGE = 1;//����
//*********************************************************

/******************************************************************
**������WARN_SOE_INFO
**������WARN_SOE_INFO����soe�澯��Ϣ,��Ӧ���ݿ��soe�澯��(warnSOE_table)
******************************************************************/
struct WARN_SOE_INFO
{
  FILETIME tWarnTime; //�澯ʱ��
  short shFacNo; //����
  short shSourceNo; //����Դ��
  int iObjNo; //�����
  BYTE byObjVal; //����״̬��ͬSOE_WARN��object_val��Աȡֵ
  char szWarnInfo[WARN_INFO_LENGTH]; //�澯��Ϣ
};

/******************************************************************
**������WARN_COMM
**������WARN_COMM����ͨ�Ÿ澯��Ϣ,����Ϣ��������ʷ���ݿ��ϵͳ
        �澯��(warnSys_table)
******************************************************************/
struct WARN_COMM
{
  FILETIME tWarnTime; //�澯ʱ��
  short shSourceNo;  //����Դ��
  short shAddress;  //��վ��ַ
  BYTE bySubType;  //��վ���ͣ������ĵĳ�Աȡֵ
  short shFacNo;  //����
  BYTE byUpStatus;  //����ͨ��״̬�������ĵĳ�Աȡֵ
  BYTE byDownStatus;  //����ͨ��״̬����Աȡֵͬ����ͨ��״̬
};

//****WARN_COMM��bySubType��Աȡֵ*************************
const unsigned char WARN_COMM_SUBSTATION = 0;//���վ
const unsigned char WARN_COMM_VQC = 1;//VQC
const unsigned char WARN_COMM_SCADA = 2;//SCADA
const unsigned char WARN_COMM_TRANSMIT = 3;//ת��
//*********************************************************

//****WARN_COMM��byUpStatus��Աȡֵ************************
const unsigned char WARN_COMM_NORMAL = 0;//����
const unsigned char WARN_COMM_ABNORMAL = 1;//�쳣
//*********************************************************

/******************************************************************
**������WARN_DEV_OPER
**������WARN_DEV_OPER�����豸�����澯��Ϣ,����Ϣ��������ʷ���ݿ��
        ��վ�澯��(warnFac_table)
******************************************************************/
struct WARN_DEV_OPER
{
  FILETIME tWarnTime; //�澯ʱ��
  short shDevType;  //�豸���ͣ������ĵĳ�Աȡֵ
  short shFacNo;  //����
  short shDevNo;  //��ţ����ڳ�վ�����������
  BYTE byOper;  //�����������ĵĳ�Աȡֵ
  char operator_name[WARN_USER_NAME]; //����������
};

//****WARN_DEV_OPER��shDevType��Աȡֵ*********************
const short WARN_DEV_FACTORY = 1;//��վ
const short WARN_DEV_VQC = 2;//VQCװ��
const short WARN_DEV_BITRANS = 3;//˫�����ѹ��
const short WARN_DEV_TRITRANS = 4;//�������ѹ��
const short WARN_DEV_SHUNT = 5;//�޹��豸
const short WARN_DEV_BREAKER = 6;//����
const short WARN_DEV_DISCLOSER = 7;//��բ
const short WARN_DEV_GENERATOR = 8;//�����
//*********************************************************

//****WARN_DEV_OPER��byOper��Աȡֵ************************
const unsigned char WARN_DEVOPER_QUIT = 0;//�˳�
const unsigned char WARN_DEVOPER_RUN = 1;//Ͷ��
//*********************************************************

/******************************************************************
**������WARN_OPF
**������WARN_OPF�����Ż�������ƹ����еĸ澯��Ϣ
******************************************************************/
struct WARN_OPF
{
  FILETIME tWarnTime; //�澯ʱ��
  BYTE byCalType; //�������ͣ������ĵĳ�Աȡֵ
  short shType;  //�澯���ͣ������ĵĳ�Աȡֵ
};

//****WARN_OPF��byCalType��Աȡֵ**************************
const unsigned char WARN_OPF_ONLINE = 0;//�����Ż�����
const unsigned char WARN_OPF_OFFLINE = 1;//�����Ż�����
//*********************************************************

//****WARN_OPF��shType��Աȡֵ*****************************
const short WARN_OPF_CALSTART = 0;//�Ż���������
const short WARN_OPF_CALSUCCESS = 1;//�Ż�����ɹ�
const short WARN_OPF_CALFAIL = 2;//�Ż�����ʧ��
const short WARN_OPF_CTRLSTART = 3;//�Ż���������
const short WARN_OPF_CTRLSUCCESS = 4;//�Ż����Ƴɹ�
const short WARN_OPF_CTRLFAIL = 5;//�Ż�����ʧ��
const short WARN_OPF_END = 6;//�Ż�������ƽ���
const short WARN_OPF_HASCMD=7;//���Ż���������
const short WARN_OPF_MULTIFAIL=8;//�����������ʧ��
//*********************************************************

/******************************************************************
**������WARN_BROADCAST_INFO
**������WARN_BROADCAST_INFO����varcsϵͳ�ڵĹ㲥��Ϣ
******************************************************************/
struct WARN_BROADCAST_INFO
{
  unsigned char byProgramId; //����ģ��ı��,commData.h
  unsigned char byInfoType; //��Ϣ���ͣ������ĵĳ�Աȡֵ
  short shInfoTag;  //��Ϣ��־�������ĵĳ�Աȡֵ
};

//****WARN_BROADCAST_INFO��byInfoType��Աȡֵ**************
const unsigned char PROGRAM_STATUS = 0;//����ģ��״̬
//*********************************************************

//****WARN_BROADCAST_INFO��shInfoTag��Աȡֵ***************
const short PROGRAM_STATUS_NORMAL = 0;//����ģ������
const short PROGRAM_STATUS_ABNORMAL = 1;//����ģ���쳣
//*********************************************************

/******************************************************************
**������WARN_VQCACT
**������WARN_VQCACT����VQC�ϴ�������¼��Ϣ
******************************************************************/
struct WARN_VQCACT
{
  FILETIME tActTime;  //����ʱ��
  short shFacNo;      //����
  int iObjNo;         //�����
  BYTE byAction;  //��������
  BYTE byResult;  //��������������ĵĳ�Աȡֵ
};

//****WARN_VQCACT��byAction��Աȡֵ**********************
const unsigned char VQCACT_ACTION_OFF = 0; //��/��
const unsigned char VQCACT_ACTION_ON = 1;  //��/��
//*********************************************************

//****WARN_VQCACT��byResult��Աȡֵ***************
const short VQCACT_RESULT_SUCCESS = 1;//�ɹ�
const short VQCACT_RESULT_FAIL = 2;   //ʧ��
const short VQCACT_RESULT_REJECT = 3; //�ܶ�
const short VQCACT_RESULT_SLIP = 4;   //����
const short VQCACT_RESULT_CANCEL = 5; //����
//*********************************************************


/*********************************************************
**�ṹ����WARN_SHIFTMODEL
**������WARN_SHIFTMODEL�����л�����ģ��ʱ�ĸ澯��Ϣ
******************************************************************/
struct  WARN_SHIFTDBMODEL
{
    FILETIME tWarnTime; //�澯ʱ��
    short shDbNo;//�л���ĵ���ģ�ͱ��
};

/*********************************************************
**�ṹ����WARN_COMMAND
**������WARN_COMMAND������������Ĳ����ʹ�����
******************************************************************/
typedef refavc_opfCmd_table WARN_COMMAND;

/******************************************************************
**������WARN_TAG
**������WARN_TAG���������ύ�澯��Ϣʱȷ���澯���͵����ݽṹ
******************************************************************/
struct WARN_TAG
{
  BYTE byWarnType; //�澯���ͣ������ĵĳ�Աȡֵ
  short shWarnMode;  //�澯��ʽ�������ĵĳ�Աȡֵ����
};

//****WARN_TAG��Warn_Type��Աȡֵ**************************
const unsigned char	WARN_TYPE_LOCK = 0;//�����澯
const unsigned char	WARN_TYPE_OPERATE = 1;//������־
const unsigned char	WARN_TYPE_SYSTEM = 2;//ϵͳ�澯
const unsigned char	WARN_TYPE_YK = 3;//ң�ظ澯
const unsigned char	WARN_TYPE_YT = 4;//ң���澯
const unsigned char	WARN_TYPE_YC = 5;//ң��澯
const unsigned char	WARN_TYPE_YX = 6;//ң�Ÿ澯
const unsigned char	WARN_TYPE_SET = 7;//��ֵ�澯
const unsigned char	WARN_TYPE_FACTORY = 8;//��վ�澯
const unsigned char	WARN_TYPE_RELAYYX = 9;//����״̬�澯
const unsigned char	WARN_TYPE_SOE = 10;//soe�澯
const unsigned char	WARN_TYPE_COMM = 11;//ͨ�Ÿ澯
const unsigned char	WARN_TYPE_DEVOPER = 12;//�豸�����澯
const unsigned char	WARN_TYPE_VQCLOCK = 13;//VQC�ϴ������澯
const unsigned char	WARN_TYPE_OPF = 14;//�Ż��澯
const unsigned char	WARN_TYPE_VQCACT = 15;//VQC������Ϣ
const unsigned char	WARN_TYPE_BROADCAST_INFO = 16;//�㲥��Ϣ
const unsigned char	WARN_TYPE_SHIFTDBMODEL = 17;//�л�����ģ�͸澯
const unsigned char	WARN_TYPE_COMMAND = 18;//��������澯
//*********************************************************

//****WARN_TAG��shWarnMode��Աȡֵ����*********************
const short WARN_MODE_DISPLAY = 0x01;//����ʾ
const short WARN_MODE_LOG = 0x01<<1;//���¼
const short WARN_MODE_PRINT = 0x01<<2;//���ӡ
const short WARN_MODE_VOICE = 0x01<<3;//������
//*********************************************************

/******************************************************************
**������WARN_REC
**������WARN_REC�ۺ���������澯��Ϣ���Ա�ͳһ����
******************************************************************/
struct WARN_REC
{
  WARN_LOCK wLock; //�����澯
  WARN_OPERATE_LOG wOpe; //������־
  WARN_SYSTEM wSys; //ϵͳ�澯
  WARN_YK wYk; //ң�ظ澯
  WARN_YT wYt; //ң���澯
  WARN_YC wYc; //ң��澯
  WARN_YX wYx; //ң�Ÿ澯
  WARN_SET wSet; //��ֵ�澯
  WARN_FACTORY wFac; //��վ�澯
  WARN_RELAY_YX wRelayYx; //����״̬�澯
  WARN_SOE_INFO wSoe; //SOE�澯
  WARN_COMM wComm;//ͨ�Ÿ澯
  WARN_DEV_OPER wDevOper;//�豸�����澯
  VQC_LOCK_WARN wVqcLock;//VQC�ϴ������澯
  WARN_OPF wOpf;//�Ż��澯
  WARN_BROADCAST_INFO wBroadcastInfo;//�㲥��Ϣ
  WARN_VQCACT wVqcAct;//VQC������Ϣ
  WARN_SHIFTDBMODEL wShiftDbModel;//�л�����ģ��ʱ�ĸ澯��Ϣ
  WARN_COMMAND wCommand;//��������澯;
};

/******************************************************************
**������WARN_INFO
**������WARN_INFO������varCSϵͳ������ģ���ύ�ĸ澯��Ϣ
******************************************************************/
struct WARN_INFO
{
  WARN_TAG warnTag;//�澯����
  WARN_REC warnRec;//�澯��¼
};

/******************************************************************
**������WARN_NET_MSG
**������WARN_NET_MSG����varCSϵͳ�����й㲥�ĸ澯����
******************************************************************/
struct WARN_NET_MSG
{
  int iWarnNum; //�澯��Ϣ����������WARN_INFOΪ��λ
  WARN_INFO warn[MAX_WARN_MSG_LEN]; //�澯��Ϣ
};

#endif //__VARCS_WARNLOG__H