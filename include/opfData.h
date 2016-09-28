/******************************************************************
** �ļ���:opfData.h
** Copyright (c) 1998-2003*********������������ɷ����޹�˾
** ���� :������    ����:2003-8-27
** �޸���:         ����:
** ����:���ļ��ṩ���ݿ���Ż������м����ݺͽ�����ݵ����ݽṹ�ͳ������塣
** �汾:1.0
**-----------------------------------------------------------------
******************************************************************/

#ifndef	__VARCS_OPFDATA__H
#define __VARCS_OPFDATA__H

const short OPF_DEVNAME_LENGTH = 64;
const short OPF_NAME_LENGTH = 100;
const short OPF_COMMENT_LENGTH = 200;

/******************************************************************
**������TISLAND_TABLE
**������TISLAND_TABLE��Ӧ�����ݿ�ĵ�������Ϣ��
******************************************************************/
struct TISLAND_TABLE
{
  int iIslandNo;  //��������
  int iNodeNum;  //�ڵ���
  int iGenNum;  //�������
  int iLoadNum;  //������
  short shSeTime;  //״̬����ʱ��
  BYTE bySeResult;  //se����������ĵĳ�Աȡֵ
  short shOpfTime;  //�Ż�����ʱ��
  BYTE byOpfResult;  //opf����������ĵĳ�Աȡֵ
  int iMeasNum;      //�����������
  int iEligibleNum;  //���ƺ�ϸ����
  char szRefGen[OPF_COMMENT_LENGTH];  //ƽ�ⷢ���
};

//****TISLAND_TABLE��bySeResult��Աȡֵ********************
/*const unsigned char SE_SUCCESS = 0;//����ɹ�
const unsigned char SE_INVALID = 1;//��������Ч
const unsigned char SE_INOBSERV = 2;//���ɹ۲�
const unsigned char SE_NOCONVERGE = 3;//������
const unsigned char SE_ERROR = 4;//�������
const unsigned char SE_ELIGIBLELOW = 5;//�ϸ��ʹ���*/
//*********************************************************

//****TISLAND_TABLE��byOpfResult��Աȡֵ*******************
/*const unsigned char OPF_SUCCESS = 0;//����ɹ�
const unsigned char OPF_NOCONVERGE = 1;//������
const unsigned char OPF_ERROR = 2;//�������*/
//*********************************************************

/******************************************************************
**������TMPNODE_TABLE
**������TMPNODE_TABLE��Ӧ�����ݿ�Ľڵ���Ϣ��
******************************************************************/
struct TMPNODE_TABLE
{
  int iNodeNo;  //�ڵ��
  int iIslandNo;  //��������
  short shFacNo;  //���ڳ���
  short shAreaNo;  //���������
  short shZoneNo;  //�������κ�
  BYTE byBusType;  //ĸ�����ͣ������ĵĳ�Աȡֵ
  BYTE byCtrlType;  //�Ż��������ͣ������ĵĳ�Աȡֵ
  float fBaseVol;  //��׼��ѹ
  float fYcVol;  //ң���ѹֵ
  float fVolWeight;  //��ѹȨֵ
  float fVolStep;  //��ѹȨֵ����
  BYTE byJPV;  //��ѹ����״̬�������ĵĳ�Աȡֵ
  BYTE byJPC;  //��ѹ�仯����״̬�������ĵĳ�Աȡֵ
  float fSeVoltage;  //se��ѹֵ
  float fSeAngle;  //se��ѹ���
  short shLimitNo;  //��ѹ���Ƽ���
  short shVarLimNo;  //��ѹ�仯���Ƽ���
};

//****TMPNODE_TABLE��byBusType��Աȡֵ*********************
const unsigned char TMPNODE_NORMAL = 0;//��ͨĸ��
const unsigned char TMPNODE_LOAD = 1;//����ĸ��
//*********************************************************

//****TMPNODE_TABLE��byCtrlType��Աȡֵ********************
const unsigned char TMPNODE_NOOPF = 0;//���Ż�����
const unsigned char TMPNODE_OPF = 1;//�Ż�����
//*********************************************************

//****TMPNODE_TABLE��byJPV��Աȡֵ*************************
const unsigned char TMPNODE_JPV_NOFORCE = 0;//��ǿ�Ƽ��
const unsigned char TMPNODE_JPV_FORCE = 1;//ǿ�Ƽ��
//*********************************************************

//****TMPNODE_TABLE��byJPC��Աȡֵ*************************
const unsigned char TMPNODE_JPC_NOFORCE = 0;//��ǿ�Ƽ��
const unsigned char TMPNODE_JPC_FORCE = 1;//ǿ�Ƽ��
//*********************************************************

/******************************************************************
**������TMPTRANS_TABLE
**������TMPTRANS_TABLE��Ӧ�����ݿ�ļ����ѹ����
******************************************************************/
struct TMPTRANS_TABLE
{
  short shFacNo;  //����
  short shMasterNo;  //����ѹ����
  int iTransNo;  //��ѹ����
  BYTE byVolSide;  //��ѹ�࣬�����ĵĳ�Աȡֵ
  float fCapacity;  //�����
  BYTE byReguType;  //��ѹ��ʽ�������ĵĳ�Աȡֵ
  BYTE byStatus;  //����״̬�������ĵĳ�Աȡֵ
  BYTE byLock;  //����״̬�������ĵĳ�Աȡֵ
  BYTE byCtrlType;  //�Ż��������ͣ������ĵĳ�Աȡֵ
  float fResistance;  //����ֵ
  float fReactance;  //�翹ֵ
  float fConductance;  //�絼ֵ
  float fSusceptance;  //����ֵ
  float fMinRatio;  //��С���
  float fMaxRatio;  //�����
  float fCurrentRatio;  //��ǰ���
  float fStepSize;  //��λ����
  float fYcFromP;  //�׶��й�����
  float fFromPWeight;  //�׶��й�Ȩֵ
  float fFromPStep;  //�׶��й�Ȩֵ����
  float fYcFromQ;  //�׶��޹�����
  float fFromQWeight;  //�׶��޹�Ȩֵ
  float fFromQStep;  //�׶��޹�Ȩֵ����
  float fYcFromI;  //�׶˵�������
  float fFromIWeight;  //�׶˵���Ȩֵ
  float fFromIStep;  //�׶˵���Ȩֵ����
  float fYcToP;  //ĩ���й�����
  float fToPWeight;  //ĩ���й�Ȩֵ
  float fToPStep;  //ĩ���й�Ȩֵ����
  float fYcToQ;	  //ĩ���޹�����
  float fToQWeight;  //ĩ���޹�Ȩֵ
  float fToQStep;  //ĩ���޹�Ȩֵ����
  float fYcToI;  //ĩ�˵�������
  float fToIWeight;  //ĩ�˵���Ȩֵ
  float fToIStep;  //ĩ�˵���Ȩֵ����
  int iFromNode;  //�׶˽ڵ��
  int iToPoint;  //ĩ�˽ڵ��
  float fSeFromP;  //�׶��й�
  float fSeFromQ;  //�׶��޹�
  float fSeFromI;  //�׶˵���
  float fSeToP;  //ĩ���й�
  float fSeToQ;  //ĩ���޹�
  float fSeToI;  //ĩ�˵���
  int iIslandNo;  //��������
};

//****TMPTRANS_TABLE��byVolSide��Աȡֵ********************
const unsigned char TMPTRANS_SIDE_HI = 0;//��ѹ��
const unsigned char TMPTRANS_SIDE_MID = 2;//��ѹ��
const unsigned char TMPTRANS_SIDE_LOW = 1;//��ѹ��
//*********************************************************

//****TMPTRANS_TABLE��byReguType��Աȡֵ*******************
const unsigned char TMPTRANS_NO_REGU = 0;//���ɵ�ѹ
const unsigned char TMPTRANS_REGU = 1;//���Ե�ѹ
//*********************************************************

//****TMPTRANS_TABLE��byStatus��Աȡֵ*********************
const unsigned char TMPDEVICE_QUIT = 0;//�˳�
const unsigned char TMPDEVICE_RUN = 1;//Ͷ��
//*********************************************************

//****TMPTRANS_TABLE��byLock��Աȡֵ***********************
const unsigned char TMPDEVICE_OPERATE_NORMAL = 0;//����
const unsigned char TMPDEVICE_OPERATE_LOCK = 1;//����
//*********************************************************

//****TMPTRANS_TABLE��byCtrlType��Աȡֵ*******************
const unsigned char TMPDEVICE_NO_OPF = 0;//���Ż�����
const unsigned char TMPDEVICE_OPF = 1;//�Ż�����
//*********************************************************

/******************************************************************
**������TMPSHUNT_TABLE
**������TMPSHUNT_TABLE��Ӧ�����ݿ�ļ����޹��豸��
******************************************************************/
struct TMPSHUNT_TABLE
{
  short shFacNo;  //����
  int iShuntNo;  //���
  float fRateVol;  //���ѹ
  float fCapacity;  //�����
  BYTE byStatus;  //����״̬��ͬ�����ѹ����Ĺ���״̬ȡֵ
  BYTE byLock;  //����״̬��ͬ�����ѹ����ı���״̬ȡֵ
  BYTE byCtrlType;  //�Ż��������ͣ�ͬ�����ѹ������Ż���������ȡֵ
  float fYcP;  //�й�����
  float fPWeight;  //�й�����Ȩֵ
  float fPStep;  //�й�����Ȩֵ����
  float fYcQ; //�޹�����
  float fQWeight;  //�޹�����Ȩֵ
  float fQStep;  //�޹�����Ȩֵ����
  float fYcI;  //��������
  float fIWeight;  //��������Ȩֵ
  float fIStep;  //��������Ȩֵ����
  int iFromNode;  //�׶˽ڵ��
  int iToPoint;  //ĩ�˽ڵ��
  float fSeQ;  //�޹�����ֵ
  int iIslandNo;  //��������
};

/******************************************************************
**������TMPGEN_TABLE
**������TMPGEN_TABLE��Ӧ�����ݿ�ļ��㷢�����
******************************************************************/
struct TMPGEN_TABLE
{
  short shFacNo;  //����
  int iGenNo;  //�������
  float fRatedS;  //�����
  float fRatedP;  //�����
  float fRatedVol;  //���ѹ
  BYTE byStatus;  //����״̬��ͬ�����ѹ����Ĺ���״̬ȡֵ
  float fYcP;  //�й�ң��
  float fPWeight;  //�й�ң��Ȩֵ
  float fPStep;  //�й�ң��Ȩֵ����
  float fYcQ;  //�޹�ң��
  float fQWeight;  //�޹�ң��Ȩֵ
  float fQStep;  //�޹�ң��Ȩֵ����
  float fMaxP;  //����й�
  float fMinP;  //��С�й�
  float fMaxQ;  //����޹�
  float fMinQ;  //��С�޹�
  float fMaxI;  //���޵���
  BYTE byRunMode;  //����ģʽ�������ĵĳ�Աȡֵ
  float fVolUpper;  //��ѹ����
  float fVolLower;  //��ѹ����
  int iNodeNo;  //�ڵ��
  float fSeP;  //�й�����ֵ
  float fSeQ;  //�޹�����ֵ
  int iIslandNo;  //��������
};

//****TMPGEN_TABLE��byRunMode��Աȡֵ**********************
const unsigned char TMPGEN_PNOR_CTRLV = 0;//P���������Ƶ�ѹ
const unsigned char TMPGEN_FIXPQ = 1;//�̶�P��Q���
const unsigned char TMPGEN_FIXP_CTRLV = 2;//�̶�P��������Ƶ�ѹ
const unsigned char TMPGEN_PNOR_FIXQ = 3;//P����,�̶�Q���
//*********************************************************

/******************************************************************
**������TMPLOAD_TABLE
**������TMPLOAD_TABLE��Ӧ�����ݿ�ļ��㸺�ɱ�
******************************************************************/
struct TMPLOAD_TABLE
{
  short shFacNo;  //����
  int iLoadNo;  //���
  BYTE byStatus;  //����״̬��ͬ�����ѹ����Ĺ���״̬ȡֵ
  float fYcP;  //�й�ң��
  float fPWeight;  //�й�ң��Ȩֵ
  float fPStep;  //�й�ң��Ȩֵ����
  float fYcQ;  //�޹�ң��
  float fQWeight;  //�޹�ң��Ȩֵ
  float fQStep;  //�޹�ң��Ȩֵ����
  float fMaxP;  //����й�
  float fMinP;  //��С�й�
  float fMaxQ;  //����޹�
  float fMinQ;  //��С�޹�
  int iNodeNo;  //�ڵ��
  float fSeP;  //�й�����ֵ
  float fSeQ;  //�޹�����ֵ
  int iIslandNo;  //��������
};

/******************************************************************
**������TMPLINE_TABLE
**������TMPLINE_TABLE��Ӧ�����ݿ�ļ�����·��
******************************************************************/
struct TMPLINE_TABLE
{
  int iLineNo;  //��·��
  short shFromFac;  //�׶˳���
  short shToFac;  //ĩ�˳���
  float fResistance;  //����ֵ
  float fReactance;  //�翹ֵ
  float fConductance;  //�絼ֵ
  float fSusceptance;  //����ֵ
  float fFromCapacity;  //��·�׶�����
  float fToCapacity;  //��·ĩ������
  float fMaxI;  //������ֵ
  float fYcFromP;  //�׶��й�����
  float fFromPWeight;  //�׶��й�Ȩֵ
  float fFromPStep;  //�׶��й�Ȩֵ����
  float fYcFromQ;  //�׶��޹�����
  float fFromQWeight;  //�׶��޹�Ȩֵ
  float fFromQStep;  //�׶��޹�Ȩֵ����
  float fYcFromI;  //�׶˵�������
  float fFromIWeight;  //�׶˵���Ȩֵ
  float fFromIStep;  //�׶˵���Ȩֵ����
  float fYcToP;  //ĩ���й�����
  float fToPWeight;  //ĩ���й�Ȩֵ
  float fToPStep;  //ĩ���й�Ȩֵ����
  float fYcToQ;  //ĩ���޹�����
  float fToQWeight;  //ĩ���޹�Ȩֵ
  float fToQStep;  //ĩ���޹�Ȩֵ����
  float fYcToI;  //ĩ�˵�������
  float fToIWeight;  //ĩ�˵���Ȩֵ
  float fToIStep;  //ĩ�˵���Ȩֵ����
  int iFromNode;  //�׶˽ڵ��
  int iToNode;  //ĩ�˽ڵ��
  float fSeFromP;  //�׶��й�����
  float fSeFromQ;  //�׶��޹�����
  float fSeFromI;  //�׶˵�������
  float fSeToP;  //ĩ���й�����
  float fSeToQ;  //ĩ���޹�����
  float fSeToI;	  //ĩ�˵�������
  int iIslandNo;  //��������
};

/******************************************************************
**������TMPBUS_TABLE
**������TMPBUS_TABLE��Ӧ�����ݿ�ļ���ĸ�߱�
******************************************************************/
struct TMPBUS_TABLE
{
  short shFacNo;  //����
  short shBusNo;  //ĸ�ߺ�
  int iNodeNo;  //�ڵ��
  BYTE byBusType;  //ĸ�����ͣ�ͬ�ڵ���Ϣ��ĸ�����͵�ȡֵ
  BYTE byCtrlType;  //�Ż��������ͣ�ͬ�ڵ���Ϣ���Ż��������͵�ȡֵ
  float fBaseVol;  //��׼��ѹ
  float fYcVol;  //ң���ѹֵ
  float fVolWeight;  //��ѹȨֵ
  float fVolStep;  //��ѹȨֵ����
  BYTE byJPV;  //��ѹ����״̬��ͬ�ڵ���Ϣ���ѹ����״̬��ȡֵ
  BYTE byJPC;  //��ѹ�仯����״̬��ͬ�ڵ���Ϣ���ѹ�仯����״̬��ȡֵ
  short shLimitNo;  //��ѹ���Ƽ���
  short shVarLimNo;  //��ѹ�仯���Ƽ���
};

/******************************************************************
**������OPFRES_TABLE
**������OPFRES_TABLE��Ӧ�����ݿ���Ż����������Ϣ��
******************************************************************/
struct OPFRES_TABLE
{
  short shAutoId;  //���
  CTime tStartTime;  //����ʱ��
  CTime tEndTime;  //����ʱ��
  BYTE byResult;  //������ƽ���������ĵĳ�Աȡֵ
  float fSeEligible; //ң����ƺϸ���
  //short shTopoTime;  //���˷���ʱ��
  //short shSeTime;  //״̬����ʱ��
  //short shOpfTime;  //�Ż�����ʱ��
  short shOperateTime;  //����ִ��ʱ��
  float fPrePLoss;  //�Ż�ǰ�й�����
  float fPostPLoss;  //�Ż����й�����
  float fPreQLoss;  //�Ż�ǰ�޹�����
  float fPostQLoss;  //�Ż����޹�����
  short shCmdNum;  //������������
  short shCmdSucNum;  //��������ɹ�����
  char szStartReason[OPF_NAME_LENGTH];  //����ԭ��
  char szComment[OPF_COMMENT_LENGTH];  //˵��
};

//****OPFRES_TABLE��byResult��Աȡֵ***********************
const unsigned char OPFRES_CALSUCCESS = 0;//����ɹ�
const unsigned char OPFRES_CALFAIL = 1;//����ʧ��
const unsigned char OPFRES_CTRLSUCCESS = 2;//���Ƴɹ�
const unsigned char OPFRES_CTRLFAIL = 3;//����ʧ��
const unsigned char OPFRES_DISELIGIBLE = 4;//ң��ϸ��ʵ�
//*********************************************************

/******************************************************************
**������MEASANALYSE_TABLE
**������MEASANALYSE_TABLE��Ӧ�����ݿ���������ݷ�����
******************************************************************/
struct MEASANA_TABLE //�������ݷ�����
{
  int  iNoBalanceBranch;  //��ƽ��֧·��
  int  iNoBalanceNode;    //��ƽ��֧·��
  int  iBSNoMatch;        //���س�����ƥ����
  int  iBadData;          //��������
  int  iShadMeas;         //����������
  int  iDummyMeas;        //α������
};

/******************************************************************
**������PRENODE_TABLE
**������PRENODE_TABLE��Ӧ�����ݿ���Ż�ǰ�ڵ���Ϣ
******************************************************************/
struct PRENODE_TABLE
{
  int iNodeNo;  //�ڵ��
  int iIslandNo;  //��������
  float  fVoltage;  //��ѹֵ
  float fVolAngle;  //��ѹ���
  float fGenMW;  //�����й�
  float fGenMvar;  //�����޹�
  float fLoadMW;  //�����й�
  float fLoadMvar;  //�����޹�
  float fShuntMW;  //����֧·�й�
  float fShuntMvar;  //����֧·�޹�
};

/******************************************************************
**������POSTNODE_TABLE
**������POSTNODE_TABLE��Ӧ�����ݿ���Ż���ڵ���Ϣ
******************************************************************/
struct POSTNODE_TABLE
{
  int iNodeNo;  //�ڵ��
  int iIslandNo;  //��������
  float fVoltage;  //��ѹֵ
  float fVolAngle;  //��ѹ���
  float fGenMW;  //�����й�
  float fGenMvar;  //�����޹�
  float fLoadMW;  //�����й�
  float fLoadMvar;  //�����޹�
  float fShuntMW;  //����֧·�й�
  float fShuntMvar;  //����֧·�޹�
  float fPSen;  //�й�������
  float fQSen;  //�޹�������
  float fSenLoss;  //�������������
};

/******************************************************************
**������PRELINE_TABLE
**������PRELINE_TABLE��Ӧ�����ݿ���Ż�ǰ��·��Ϣ
******************************************************************/
struct PRELINE_TABLE
{
  int iLineNo;  //��·��
  int iFromNode;  //�׶˽ڵ��
  int iToNode;  //ĩ�˽ڵ��
  float fFromMW;  //��·�׶��й�
  float fFromMvar;  //��·�׶��޹�
  float fToMW;  //��·ĩ���й�
  float fToMvar;  //��·ĩ���޹�
};

/******************************************************************
**������POSTLINE_TABLE
**������POSTLINE_TABLE��Ӧ�����ݿ���Ż�����·��Ϣ
******************************************************************/
struct POSTLINE_TABLE
{
  int iLineNo;  //��·��
  int iFromNode;  //�׶˽ڵ��
  int iToNode;  //ĩ�˽ڵ��
  float fFromMW;  //��·�׶��й�
  float fFromMvar;  //��·�׶��޹�
  float fToMW;  //��·ĩ���й�
  float fToMvar;  //��·ĩ���޹�
};

/******************************************************************
**������PRETRANS_TABLE
**������PRETRANS_TABLE��Ӧ�����ݿ���Ż�ǰ��ѹ����Ϣ
******************************************************************/
struct PRETRANS_TABLE
{
  short shFacNo;  //����
  short shMasterNo;  //����ѹ����
  short shTransNo;  //��ѹ����
  BYTE byVolSide;  //��ѹ�࣬ͬ�����ѹ�����ѹ��ȡֵ
  int iFromNode;  //�׶˽ڵ��
  int iToNode;  //ĩ�˽ڵ��
  float fFromMW;  //�׶��й�
  float fFromMvar;  //�׶��޹�
  float fToMW;  //ĩ���й�
  float fToMvar;  //ĩ���޹�
  float fFromPf;  //�׶˹�������
  float fToPf;  //ĩ�˹�������
};

/******************************************************************
**������POSTTRANS_TABLE
**������POSTTRANS_TABLE��Ӧ�����ݿ���Ż����ѹ����Ϣ
******************************************************************/
struct POSTTRANS_TABLE
{
  short shFacNo;  //����
  short shMasterNo;  //����ѹ����
  short shTransNo;  //��ѹ����
  BYTE byVolSide;  //��ѹ�࣬ͬ�����ѹ�����ѹ��ȡֵ
  int iFromNode;  //�׶˽ڵ��
  int iToNode;  //ĩ�˽ڵ��
  float fFromMW;  //�׶��й�
  float fFromMvar;  //�׶��޹�
  float fToMW;  //ĩ���й�
  float fToMvar;  //ĩ���޹�
  float fFromPf;  //�׶˹�������
  float fToPf;  //ĩ�˹�������
};

/******************************************************************
**������OPFTRANS_TABLE
**������OPFTRANS_TABLE��Ӧ�����ݿ�ı�ѹ�������Ϣ��
******************************************************************/
struct OPFTRANS_TABLE
{
  short shFacNo;  //����
  short shMasterNo;  //����ѹ����
  short shTransNo;  //��ѹ����
  BYTE byVolSide;  //��ѹ�࣬ͬ�����ѹ�����ѹ��ȡֵ
  int iFromNode;  //�׶˽ڵ��
  int iToNode;  //ĩ�˽ڵ��
  float fFromBaseVol;  //�׶˻�׼��ѹ
  float fToBaseVol;  //ĩ�˻�׼��ѹ
  float fPreRatio;  //�Ż�ǰ���
  float fPostRatio;  //�Ż�����
};

/******************************************************************
**������OPFSHUNT_TABLE
**������OPFSHUNT_TABLE��Ӧ�����ݿ�Ĳ����޹��豸�����Ϣ��
******************************************************************/
struct OPFSHUNT_TABLE
{
  short shFacNo;  //����
  short shShuntNo;  //���
  int iFromNode;  //�׶˽ڵ��
  int iToNode;  //ĩ�˽ڵ��
  float fPreVar;  //�Ż�ǰ����
  float fPostVar;  //�Ż�������
};

/******************************************************************
**������VQCSET_TABLE
**������VQCSET_TABLE��Ӧ�����ݿ��VQC��ֵ��
******************************************************************/
struct VQCSET_TABLE
{
  short shFacNo;  //����
  BYTE byType;  //��ѹ�����ͣ������ĵĳ�Աȡֵ
  short shTransNo;  //��ѹ����
  char szFacName[OPF_DEVNAME_LENGTH];  //��վ��
  char szTransName[OPF_DEVNAME_LENGTH];  //��ѹ����
  float fHiVolSet;  //��ѹ��ֵ����
  float fLowVolSet;  //��ѹ��ֵ����
  float fHiVarSet;  //�޹�/����������ֵ����
  float fLowVarSet;  //�޹�/����������ֵ����
  BYTE byStatus;  //����״̬�������ĵĳ�Աȡֵ
};

//****VQCSET_TABLE��byType��Աȡֵ*************************
const unsigned char VQCSET_BITRANS = 0;//˫����
const unsigned char VQCSET_TRITRANS = 1;//������
//*********************************************************

//****VQCSET_TABLE��byStatus��Աȡֵ***********************
const unsigned char VQCSET_NOSEND = 0;  //δ����
const unsigned char VQCSET_SUCCESS = 1; //���ͳɹ�
const unsigned char VQCSET_FAIL = 2;    //����ʧ��
const unsigned char VQCSET_CANCEL = 5;  //����
const unsigned char VQCSET_READY  =6;   //׼��
//*********************************************************

/******************************************************************
**������OPFCMD_TABLE
**������OPFCMD_TABLE��Ӧ�����ݿ���Ż����������
******************************************************************/
struct OPFCMD_TABLE
{
  time_t tmOrder;  //���
  short shFacNo;  //����
  BYTE byType;  //�豸���ͣ������ĵĳ�Աȡֵ
  short shDeviceNo;  //�豸���
  char szFacName[OPF_DEVNAME_LENGTH];  //��վ��
  char szDevName[OPF_DEVNAME_LENGTH];  //�豸��
  BYTE byCommand;  //��������ĵĳ�Աȡֵ
  short shCurTap;  //��ǰ��λ
  short shEndTap;  //Ŀ�굵λ
  BYTE byStatus;  //����״̬�������ĵĳ�Աȡֵ
};

//****OPFCMD_TABLE��byType��Աȡֵ*************************
const unsigned char OPFCMD_BITRANS = 0;//˫�����ѹ��
const unsigned char OPFCMD_TRITRANS = 1;//�������ѹ��
const unsigned char OPFCMD_SHUNT = 2;//�����޹��豸
//*********************************************************

//****OPFCMD_TABLE��byCommand��Աȡֵ**********************
const unsigned char OPFCMD_OFF = 0;//��/��
const unsigned char OPFCMD_ON = 1;//��/��
const unsigned char OPFCMD_DZ = 2;//��ֵ
//*********************************************************

//****OPFCMD_TABLE��byStatus��Աȡֵ*************************
const unsigned char OPFCMD_NOSEND = 0;  //δִ��
const unsigned char OPFCMD_SUCCESS = 1; //���Ƴɹ�
const unsigned char OPFCMD_FAIL = 2;    //����ʧ��
const unsigned char OPFCMD_REJECT = 3;  //�ܶ�
const unsigned char OPFCMD_SLIP = 4;    //����
const unsigned char OPFCMD_CANCEL = 5;  //����
const unsigned char OPFCMD_READY  =6;   //׼��
//*********************************************************

/******************************************************************
**������OPFGEN_TABLE
**������OPFGEN_TABLE��Ӧ�����ݿ�ķ���������Ϣ
******************************************************************/
struct OPFGEN_TABLE
{
  short shFacNo;  //����
  short shGenNo;  //�������
  int iNodeNo;  //�ڵ��
  float fPreP;  //�Ż�ǰ�й�
  float fPostP;  //�Ż����й�
  float fPreQ;  //�Ż�ǰ�޹�
  float fPostQ;  //�Ż����޹�
};

/******************************************************************
**������OPFBUS_TABLE
**������OPFBUS_TABLE��Ӧ�����ݿ��ĸ���Ż������
******************************************************************/
struct OPFBUS_TABLE
{
  short shFacNo;  //����
  short shBusNo;  //ĸ�ߺ�
  char szFacName[OPF_DEVNAME_LENGTH];  //��վ��
  char szBusName[OPF_DEVNAME_LENGTH];  //ĸ����
  float fYcVol;  //ң���ѹֵ
  float fSeVol;  //״̬���Ƶ�ѹֵ
  float fSeDev;  //�������ƫ��
  float fSeAngle;  //״̬���Ƶ�ѹ���
  float fOpfVol;  //�Ż���ѹֵ
  float fOpfAngle;  //�Ż���ѹ���
  float fPostVol;  //���ƺ��ѹֵ
};

/******************************************************************
**������OPFLINE_TABLE
**������OPFLINE_TABLE��Ӧ�����ݿ����·�Ż������
******************************************************************/
struct OPFLINE_TABLE
{
  int iLineNo;  //��·��
  char szName[OPF_DEVNAME_LENGTH];  ;//��·��
  float fYcFromP;  //�׶��й�ң��
  float fYcFromQ;  //�׶��޹�ң��
  float fYcToP;  //ĩ���й�ң��
  float fYcToQ;  //ĩ���޹�ң��
  float fSeFromP;  //״̬�����׶��й�
  float fSeFromQ;  //״̬�����׶��޹�
  float fSeToP;  //״̬����ĩ���й�
  float fSeToQ;  //״̬����ĩ���޹�
  float fOpfFromP;  //�Ż��׶��й�
  float fOpfFromQ;  //�Ż��׶��޹�
  float fOpfToP;  //�Ż�ĩ���й�
  float fOpfToQ;  //�Ż�ĩ���޹�
  float fPostFromP;  //���ƺ��׶��й�ң��
  float fPostFromQ;  //���ƺ��׶��޹�ң��
  float fPostToP;  //���ƺ�ĩ���й�ң��
  float fPostToQ;  //���ƺ�ĩ���޹�ң��
};

/******************************************************************
**������OPFBYQ_TABLE
**������OPFBYQ_TABLE��Ӧ�����ݿ�ı�ѹ���Ż������
******************************************************************/
struct OPFBYQ_TABLE
{
  short shFacNo;  //����
  BYTE byType;  //��ѹ�����ͣ������ĵĳ�Աȡֵ
  short shTransNo;  //��ѹ����
  char szFacName[OPF_DEVNAME_LENGTH];  //��վ��
  char szTransName[OPF_DEVNAME_LENGTH];  //��ѹ����
  float fYcHiP;  //��ѹ���й�ң��
  float fYcHiQ;  //��ѹ���޹�ң��
  float fYcMidP;  //��ѹ���й�ң��
  float fYcMidQ;  //��ѹ���޹�ң��
  float fYcLowP;  //��ѹ���й�ң��
  float fYcLowQ;  //��ѹ���޹�ң��
  float fPreHiRatio;  //�Ż�ǰ��ѹ���
  float fPreMidRatio;  //�Ż�ǰ��ѹ���
  float fSeHiP;  //״̬���Ƹ�ѹ���й�
  float fSeHiQ;  //״̬���Ƹ�ѹ���޹�
  float fSeMidP;  //״̬������ѹ���й�
  float fSeMidQ;  //״̬������ѹ���޹�
  float fSeLowP;  //״̬���Ƶ�ѹ���й�
  float fSeLowQ;  //״̬���Ƶ�ѹ���޹�
  float fOpfHiP;  //�Ż���ѹ���й�
  float fOpfHiQ;  //�Ż���ѹ���޹�
  float fOpfMidP;  //�Ż���ѹ���й�
  float fOpfMidQ;  //�Ż���ѹ���޹�
  float fOpfLowP;  //�Ż���ѹ���й�
  float fOpfLowQ;  //�Ż���ѹ���޹�
  float fPostHiRatio;  //�Ż����ѹ���
  float fPostMidRatio;  //�Ż�����ѹ���
  float fPostHiP;  //���ƺ��ѹ���й�ң��
  float fPostHiQ;  //���ƺ��ѹ���޹�ң��
  float fPostMidP;  //���ƺ���ѹ���й�ң��
  float fPostMidQ;  //���ƺ���ѹ���޹�ң��
  float fPostLowP;  //���ƺ��ѹ���й�ң��
  float fPostLowQ;  //���ƺ��ѹ���޹�ң��
};

//****OPFBYQ_TABLE��byType��Աȡֵ**********************
const unsigned char OPFBYQ_BIT = 0;//˫�����ѹ��
const unsigned char OPFBYQ_TRIT = 1;//�������ѹ��
//*********************************************************

/******************************************************************
**������OPFWGSB_TABLE
**������OPFWGSB_TABLE��Ӧ�����ݿ�Ĳ����豸�Ż������
******************************************************************/
struct OPFWGSB_TABLE
{
  short shFacNo;  //����
  short shShuntNo;  //���
  char szFacName[OPF_DEVNAME_LENGTH];  //��վ��
  char szName[OPF_DEVNAME_LENGTH];  //�豸��
  float fYcQ;  //�޹�ң��
  float fSeQ;  //״̬�����޹�
  float fOpfQ;  //�Ż��޹�
  float fPostQ;  //���ƺ��޹�ң��
};

/******************************************************************
**������OPFFDJ_TABLE
**������OPFFDJ_TABLE��Ӧ�����ݿ�ķ�����Ż������
******************************************************************/
struct OPFFDJ_TABLE
{
  short shFacNo;  //����
  short shGenNo;  //�������
  char szFacName[OPF_DEVNAME_LENGTH];  //��վ��
  char szName[OPF_DEVNAME_LENGTH];  //�������
  float fYcP;  //�й�ң��
  float fYcQ;  //�޹�ң��
  float fSeP;  //״̬�����й�
  float fSeQ;  //״̬�����޹�
  float fOpfP;  //�Ż��й�
  float fOpfQ;  //�Ż��޹�
  float fPostP;  //���ƺ��й�ң��
  float fPostQ;  //���ƺ��޹�ң��
};

/******************************************************************
**������VOLSESTA_TABLE
**������VOLSESTA_TABLE��Ӧ�����ݿ��ң�����ͳ�Ʊ�
******************************************************************/
struct VOLSESTA_TABLE
{
  int iIslandNo;      //��������
  BYTE byStaType;     //����ͳ�����ͣ������ĵĳ�Աȡֵ
  BYTE byVolDegree;   //��ѹ�ȼ����
  float fVolSeAccu;   //��ѹ���ƺϸ���
};
//****VOLSESTA_TABLE��byStaType��Աȡֵ**********************
const unsigned char SESTA_VOL = 0;//��ѹ
const unsigned char SESTA_P = 1;//�й�
const unsigned char SESTA_Q = 2;//�޹�
const unsigned char SESTA_I = 3;//����
const unsigned char SESTA_TOTOLE = 4;//ȫ��
//*********************************************************

/******************************************************************
**������BUSEXCEE_TABLE
**������BUSEXCEE_TABLE��Ӧ�����ݿ��ĸ�ߵ�ѹԽ�ޱ�
******************************************************************/
struct BUSEXCEE_TABLE
{
  short shFacNo;  //����
  short shBusNo;  //ĸ�ߺ�
  char szFacName[OPF_DEVNAME_LENGTH];  //��վ��
  char szBusName[OPF_DEVNAME_LENGTH];  //ĸ����
  float fYcVol;  //ң���ѹֵ
  float fSeVol;  //״̬���Ƶ�ѹֵ
  float fOpfVol;  //�Ż���ѹֵ
};

/******************************************************************
**������LOSSBYQ_TABLE
**������LOSSBYQ_TABLE��Ӧ�����ݿ�ı�ѹ����ı�
******************************************************************/
struct LOSSBYQ_TABLE
{
  short shFacNo;  //����
  BYTE  byType;  //��ѹ������
  short shTransNo;  //��ѹ����
  char szFacName[OPF_DEVNAME_LENGTH];  //��վ��
  char szTransName[OPF_DEVNAME_LENGTH];  //��ѹ����
  float fPrePLoss;  //�Ż�ǰ�й����
  float fPostPLoss;  //�Ż����й����
  float fPreQLoss;  //�Ż�ǰ�޹����
  float fPostQLoss;  //�Ż����޹����
};

/******************************************************************
**������LOSSLINE_TABLE
**������LOSSLINE_TABLE��Ӧ�����ݿ����·��ı�
******************************************************************/
struct LOSSLINE_TABLE
{
  int iLineNo;  //��·��
  char szName[OPF_DEVNAME_LENGTH];  //��·��
  float fPrePLoss;	 //�Ż�ǰ�й����
  float fPostPLoss; 	//�Ż����й����
  float fPreQLoss;	 //�Ż�ǰ�޹����
  float fPostQLoss;	 //�Ż����޹����
};

/******************************************************************
**������CURLOCK_TABLE
**������CURLOCK_TABLE��Ӧ�����ݿ�ĵ�ǰ������
******************************************************************/
struct CURLOCK_TABLE
{
  FILETIME tLockTime;       //����ʱ��
  BYTE     byObjectType;    //������������,ͬLOCK_TABLE��byObjectType
  short    shObjectFac;     //�������󳧺�
  char     szFacName[OPF_DEVNAME_LENGTH];//��վ��
  short    shObjectNo;      //�����������
  char     szObectName[OPF_DEVNAME_LENGTH];   //����������
  char     szLockInfo[OPF_NAME_LENGTH];    //������Ϣ
};

/******************************************************************
**������DEVCTRL_TABLE
**������DEVCTRL_TABLE��Ӧ�����ݿ���豸�������ñ�
******************************************************************/
struct DEVCTRL_TABLE
{
  short   shOrderNo;        //���
  float   fVolIntegral;     //��ѹ������
  float   fVolSecIncrease;  //��ѹ��������
  short   shVolHop;         //��ѹ������
  float   fCosIntegral;     //���ʻ������
  float   fCosSecIncrease;  //���ʶ�������
  short   shCosHop;         //����������
};

/******************************************************************
**������RULE_TABLE
**������RULE_TABLE��Ӧ�����ݿ�Ĺ����
******************************************************************/
struct RULE_TABLE
{
  BYTE  rule_no;    //������
  short order_no;   //���
  BYTE  v_status;   //��ѹ״̬�������ĵĳ�Աȡֵ
  BYTE  cos_status; //��������״̬�������ĵĳ�Աȡֵ
  BYTE  t_status;   //��ѹ����ǰ״̬�������ĵĳ�Աȡֵ
  BYTE  c_status;   //����װ��״̬�������ĵĳ�Աȡֵ
  BYTE  t_action;   //��ѹ�������������ĵĳ�Աȡֵ
  BYTE  c_action;   //����װ�ö����������ĵĳ�Աȡֵ
};

//****RULE_TABLE��v_status��Աȡֵ**********************
const unsigned char RULE_VOL_LOW    = 0;    //��ѹ��
const unsigned char RULE_VOL_NLOW   = 1;    //��ѹ������
const unsigned char RULE_VOL_NORMAL = 2;    //��ѹ����
const unsigned char RULE_VOL_NHIGH = 3;    //��ѹ������
const unsigned char RULE_VOL_HIGH  = 4;    //��ѹ��
//*********************************************************

//****RULE_TABLE��cos_status��Աȡֵ**********************
const unsigned char RULE_COS_LOW    = 0;    //���ʵ�
const unsigned char RULE_COS_NORMAL = 1;    //��������
const unsigned char RULE_COS_HIGH  = 2;    //���ʸ�
//*********************************************************

//****RULE_TABLE��t_status��Աȡֵ**********************
const unsigned char RULE_TRANS_EXIT   = 0;//��ѹ���˳�
const unsigned char RULE_TRANS_BOTTOM = 1;//��ѹ����λ���
const unsigned char RULE_TRANS_NORMAL = 2;//��ѹ����λ����
const unsigned char RULE_TRANS_TOP    = 3;//��ѹ����λ���
//*********************************************************

//****RULE_TABLE��c_status��Աȡֵ**********************
const unsigned char RULE_CAP_EXIT     = 0;//����װ���˳�
const unsigned char RULE_CAP_ALLDOWN  = 1;//����װ��ȫ��
const unsigned char RULE_CAP_NORMAL   = 2;//����װ�ÿ�Ͷ����
const unsigned char RULE_CAP_ALLUP    = 3;//����װ��ȫͶ
//*********************************************************

//****RULE_TABLE��t_action��Աȡֵ**********************
const unsigned char TRANS_ACTION_KEEP = 0;//��ѹ������
const unsigned char TRANS_ACTION_DOWN = 1;//��ѹ����
const unsigned char TRANS_ACTION_UP   = 2;//��ѹ����
//*********************************************************

//****RULE_TABLE��c_action��Աȡֵ**********************
const unsigned char CAP_ACTION_KEEP = 0;//����װ�ò���
const unsigned char CAP_ACTION_OFF  = 1;//����װ����
const unsigned char CAP_ACTION_ON   = 2;//����װ��Ͷ
//*********************************************************

/******************************************************************
**������SHADY_TABLE
**������SHADY_TABLE��Ӧ�����ݿ�Ŀ������ݱ�
******************************************************************/
/*struct SHADY_TABLE
{
	BYTE bType;//�����������ͣ������ĵĳ�Աȡֵ
	char szInfo[160];
};*/

//****SHADY_TABLE��bType��Աȡֵ**********************
/*const unsigned char SHADINESS_NONMEASURE=6;   //α������Ϣ
const unsigned char SHADINESS_ERRORDATA=5;   //��������
const unsigned char SHADINESS_BADDATA=4;   //������
const unsigned char SHADINESS_BRANCH_BALANCE=3;   //֧·��ƽ��
const unsigned char SHADINESS_NODE_BALANCE  =2;   //�ڵ㲻ƽ��
const unsigned char SHADINESS_SWITCH_BRANCH =1;   //���ɿ���֧·���
const unsigned char SHADINESS_OTHER_CASE    =0;   //�������˲�ƽ������*/
//*********************************************************

#endif //__VARCS_OPFDATA__H