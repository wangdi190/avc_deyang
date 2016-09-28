/******************************************************************
** �ļ���:opfPara.h
** Copyright (c) 1998-2003*********������������ɷ����޹�˾
** ���� :������    ����:2003-8-27
** �޸���:         ����:
** ����:���ļ��ṩ���ݿ���Ż�������������ݽṹ�ͳ������塣
** �汾:1.0
**-----------------------------------------------------------------
******************************************************************/

#ifndef	__VARCS_OPFPARAMETER__H
#define __VARCS_OPFPARAMETER__H

const short OPFPARA_NAME_LENGTH = 50;

/******************************************************************
**������LOCK_TABLE
**������LOCK_TABLE��Ӧ�����ݿ�ı��������
******************************************************************/
struct LOCK_TABLE
{
  short shLockNo;  //���
  BYTE byEventType;  //�����¼����ͣ������ĵĳ�Աȡֵ
  short shEventFac;  //�����¼�����
  short shEventNo;  //�����¼����
  BYTE byObjectType;  //�����������ͣ������ĵĳ�Աȡֵ
  short shObjectFac;  //�������󳧺�
  short shObjectNo;  //�����������
  BYTE byYxVal;  //ң�ű���ֵ�������ĵĳ�Աȡֵ
  short shWarnMode;  //�澯��ʽ�������ĵĳ�Աȡֵ����
  BYTE byUnlockType;  //�����ʽ�������ĵĳ�Աȡֵ
};

//****LOCK_TABLE��byEventType��Աȡֵ**********************
const unsigned char LOCK_EVENT_YX = 0;//ң�ű�λ
const unsigned char LOCK_EVENT_YC = 1;//ң��Խ��
const unsigned char LOCK_EVENT_RELAY = 2;//��������
//*********************************************************

//****LOCK_TABLE��byObjectType��Աȡֵ*********************
const unsigned char LOCK_OBJ_FACTORY = 0;//��վ
const unsigned char LOCK_OBJ_BITRANS = 1;//˫�����ѹ��
const unsigned char LOCK_OBJ_TRITRANS = 2;//�������ѹ��
const unsigned char LOCK_OBJ_SHUNT = 3;//�����޹��豸
const unsigned char LOCK_OBJ_VARCS = 4;//varCS
//*********************************************************

//****LOCK_TABLE��byYxVal��Աȡֵ**************************
const unsigned char LOCK_YX_OFF = 0;//��
const unsigned char LOCK_YX_ON = 1;//��
//*********************************************************

//****LOCK_TABLE��shWarnMode��Աȡֵ����*******************
const short LOCK_WARN_DISPLAY = 0x01;//����ʾ
const short LOCK_WARN_LOG = 0x01<<1;//���¼
const short LOCK_WARN_PRINT = 0x01<<2;//���ӡ
const short LOCK_WARN_VOICE = 0x01<<3;//������
//*********************************************************

//****LOCK_TABLE��byUnlockType��Աȡֵ*********************
const unsigned char LOCK_FREE_MANUAL = 0;//�ֹ����
const unsigned char LOCK_FREE_AUTO = 1;//�Զ����
//*********************************************************

/******************************************************************
**������AREA_TABLE
**������AREA_TABLE��Ӧ�����ݿ�������
******************************************************************/
struct AREA_TABLE
{
  short shAreaNo;  //�����
  char szAreaName[OPFPARA_NAME_LENGTH];  //������
  float fPA;  //�ƻ��й����
  float fPLA;  //���佻���ݲ�
};

/******************************************************************
**������ZONE_TABLE
**������ZONE_TABLE��Ӧ�����ݿ���������ݱ�
******************************************************************/
struct ZONE_TABLE
{
  short shZoneNo;  //���κ�
  char szZoneName[OPFPARA_NAME_LENGTH];  //������
  BYTE byIT;  //�Ż����ͣ������ĵĳ�Աȡֵ
  BYTE byLT;  //��С������ͣ������ĵĳ�Աȡֵ
  BYTE byMIZ;  //����й����״̬��־�������ĵĳ�Աȡֵ
  float fLossDead;  //�й������������
  float fLimitDead;  //��ѹԽ�޼�������
  float fPrePLoss;  //�Ż�ǰ�й�����
  float fPostPLoss;  //�Ż����й�����
  float fPreQLoss;  //�Ż�ǰ�޹�����
  float fPostQLoss;  //�Ż����޹�����
};

//****ZONE_TABLE��byIT��Աȡֵ*****************************
const unsigned char ZONE_IT_NOOPF = 0;//���Ż�
const unsigned char ZONE_IT_OPF = 1;//�Ż�
//*********************************************************

//****ZONE_TABLE��byLT��Աȡֵ*****************************
const unsigned char ZONE_LT_NOOPF = 0;//���Ż�
const unsigned char ZONE_LT_OPF = 1;//�Ż�
//*********************************************************

//****ZONE_TABLE��byMIZ��Աȡֵ****************************
const unsigned char ZONE_MIZ00 = 0;//�������Ż���С��ĵ�֧·
const unsigned char ZONE_MIZ01 = 1;//�����Ż���С���֧·������֧·
//*********************************************************

/******************************************************************
**������VOLLIMIT_TABLE
**������VOLLIMIT_TABLE��Ӧ�����ݿ�ĵ�ѹ���Ƽ���
******************************************************************/
struct VOLLIMIT_TABLE
{
  short shLimitNo;  //��ֵ����
  short shOrderNo;  //���
  CTime tStartTime;  //��ʼʱ��
  CTime tEndTime;  //��ֹʱ��
  float fMax1st;  //һ�����ֵ
  float fMin1st;  //һ����Сֵ
  float fMax2st;  //�������ֵ
  float fMin2st;  //������Сֵ
  float fMax3st;  //�������ֵ
  float fMin3st;  //������Сֵ
};

/******************************************************************
**������VOLVAR_TABLE
**������VOLVAR_TABLE��Ӧ�����ݿ�ĵ�ѹ�仯���Ƽ���
******************************************************************/
struct VOLVAR_TABLE
{
  short shLimitNo;  //��ֵ����
  short shOrderNo;  //���
  CTime tStartTime;  //��ʼʱ��
  CTime tEndTime;  //��ֹʱ��
  float fMax1st;  //һ�����ֵ
  float fMin1st;  //һ����Сֵ
  float fMax2st;  //�������ֵ
  float fMin2st;  //������Сֵ
  float fMax3st;  //�������ֵ
  float fMin3st;  //������Сֵ
};

/******************************************************************
**������QSETLIM_TABLE
**������QSETLIM_TABLE��Ӧ�����ݿ���޹���ֵԼ����
******************************************************************/
struct QSETLIM_TABLE
{
  short shLimitNo;  //Լ������
  short shOrderNo;  //���
  CTime tStartTime;  //��ʼʱ��
  CTime tEndTime;  //��ֹʱ��
  float fUpLimit;  //�޹�/������������
  float fLowLimit;  //�޹�/������������
};

/******************************************************************
**������VSETLIM_TABLE
**������VSETLIM_TABLE��Ӧ�����ݿ�ĵ�ѹ��ֵԼ����
******************************************************************/
struct VSETLIM_TABLE
{
  short shLimitNo;  //Լ������
  short shOrderNo;  //���
  CTime tStartTime;  //��ʼʱ��
  CTime tEndTime;  //��ֹʱ��
  float fUpLimit;  //��ѹ����
  float fLowLimit;  //��ѹ����
};

/******************************************************************
**������OPFEVENT_TABLE
**������OPFEVENT_TABLE��Ӧ�����ݿ���Ż����������¼���
******************************************************************/
struct OPFEVENT_TABLE
{
  short shEventNo;  //���
  BYTE byEventType;  //�¼����ͣ������ĵĳ�Աȡֵ
  short shSourceFac;  //�¼�����
  short shSourceNo;  //�¼����
  BYTE byYxVal;  //ң��ֵ�������ĵĳ�Աȡֵ
  float fChangeLimit;  //ң��仯��ֵ����ֵ
  short shRelay;  //������ʱ
  float fLastValue;  //�ϴβ���ֵ
};

//****OPFEVENT_TABLE��byEventType��Աȡֵ******************
const unsigned char OPFEVENT_YX = 0;//ң�ű�λ
const unsigned char OPFEVENT_YC = 1;//ң��Խ��
const unsigned char OPFEVENT_DELYC = 2;//ͻ����Խ��
//*********************************************************

//****OPFEVENT_TABLE��byYxVal��Աȡֵ**********************
const unsigned char OPFEVENT_YX_OFF = 0;//��
const unsigned char OPFEVENT_YX_ON = 1;//��
//*********************************************************

/******************************************************************
**������OPFSTART_TABLE
**������OPFSTART_TABLE��Ӧ�����ݿ���Ż���������ʱ�̱�
******************************************************************/
struct OPFSTART_TABLE
{
  short shTimeNo;  //���
  CTime tStartTime;  //����ʱ��
};

/******************************************************************
**������OPFYCLIM_TABLE
**������OPFYCLIM_TABLE��Ӧ�����ݿ������仯��ֵ��
******************************************************************/
struct OPFYCLIM_TABL
{
  short shLimitNo;  //���
  short shYcFac;  //ң�⳧��
  short shYcNo;  //ң�����
  float fChangeLimit;  //�仯������ֵ��ֵ
};

/******************************************************************
**������OPFSET_TABLE
**������OPFSET_TABLE��Ӧ�����ݿ���Ż����Ʋ�����
******************************************************************/
struct OPFSET_TABLE
{
  short shAutoId;  //���
  BYTE byRunMode;  //���з�ʽ�������ĵĳ�Աȡֵ
  BYTE byControlMode;  //����ִ�еȴ�ʱ��(����)
  BYTE bySetType;  //�޹���ֵ���ͣ������ĵĳ�Աȡֵ
  short shMaxCmd;  //1������������
  BYTE byCtrlFail;  //���ƹ����쳣���������ĵĳ�Աȡֵ
  BYTE byObjPreAct;  //����ʱδ�������ƶ������������ĵĳ�Աȡֵ
  short shSeTime;  //״̬���Ƽ���ʱ����ֵ
  short shOpfTime;  //�Ż�����ʱ����ֵ
  short shTriggerCyc;  //��������
  short shCalWarn;  //�Ż����������澯��ʽ��ͬ���������澯��ʽȡֵ
  short shCtrlWarn;  //�Ż����������澯��ʽ��ͬ���������澯��ʽȡֵ
  short shCtrlEndWarn;  //�Ż����Ƴɹ��澯��ʽ��ͬ���������澯��ʽȡֵ
  short shFailWarn;  //�Ż�ʧ�ܸ澯��ʽ��ͬ���������澯��ʽȡֵ
  short shAutoLockWarn;  //�Զ������澯��ʽ��ͬ���������澯��ʽȡֵ
  float fBaseMva;  //��׼����
  short shMaxTapReg;  //��ѹ���������������
};

//****OPFSET_TABLE��byRunMode��Աȡֵ**********************
const unsigned char OPF_RUN_MANUAL = 0;//�ֹ�����
const unsigned char OPF_RUN_AUTOOPEN = 1;//�Զ�����
const unsigned char OPF_RUN_AUTOCLOSE = 2;//�Զ��ջ�
//*********************************************************

//****OPFSET_TABLE��bySetType��Աȡֵ**********************
const unsigned char OPF_Q_SET = 0;//�޹�����
const unsigned char OPF_COS_SET = 1;//��������
//*********************************************************

//****OPFSET_TABLE��byCtrlFail��Աȡֵ**********************
const unsigned char OPF_FAIL_RECAL = 0;//���¼���
const unsigned char OPF_FAIL_QUIT = 1;//�˳�����
//*********************************************************

//****OPFSET_TABLE��byObjPreAct��Աȡֵ********************
const unsigned char OPF_PRE_KEEP = 0;//��������
const unsigned char OPF_PRE_RECAL = 1;//���¼���
const unsigned char OPF_PRE_QUIT = 2;//�˳�����
//*********************************************************

/******************************************************************
**������VOLLEVEL_TABLE
**������VOLLEVEL_TABLE��Ӧ�����ݿ�ĵ�ѹ�ȼ���
******************************************************************/
struct VOLLEVEL_TABLE
{
  BYTE byVolDegree;  //��ѹ�ȼ���ţ������ĵĳ�Աȡֵ
  float fBaseVol;  //��׼��ѹ
  float fSeLimit;  //������ƺϸ�Χ
};

//****FACTORY_TABLE��byVolDegree��Աȡֵ*******************
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