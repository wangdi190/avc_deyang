/******************************************************************
** �ļ���:commData.h
** Copyright (c) 1998-2003*********������������ɷ����޹�˾
** ���� :������    ����:2003-8-29
** �޸���:         ����:
** ����:���ļ��ṩ���ݿ�Ĺ������ݽṹ�ͳ������塣
** �汾:1.0
**-----------------------------------------------------------------
******************************************************************/

#ifndef	__VARCS_COMMONDATA__H
#define __VARCS_COMMONDATA__H

//*********************************************************************
//**varCSϵͳʹ��ר�ŵĶ˿���ģ���ͨ�����紫����Ϣ
const unsigned short SOCKPORT_WARN_BROADCAST = 17777;//�澯UDP�㲥�˿�
const unsigned short SOCKPORT_TCI_REMOTE = 17778;//ǰ�û�ң��TCP�˿�
const unsigned short SOCKPORT_OPFWARN_LISTEN = 17789;//�Ż�����澯����UDP�㲥�˿�
const unsigned short SOCKPORT_BROADCAST_INFO = 17780;//�㲥��ϢUDP�㲥�˿�

const UINT SHIFTMDBIDSOCKETPORT=17781;
//*********************************************************************

//*********************************************************************
//**varCSϵͳ����ʹ��ר�ŵ�windows��Ϣ��ģ��䴫����Ϣ
//**���¸�����Щ��Ϣͳһ��ע���ַ�����������Щ��Ϣ��ģ������Ӧ���ַ���
//**ע�ᣬ��������ص�windows��Ϣ
const char VARCS_HISWARN_QUIT[] = "VARCS_HISWARN_MODULE_QUIT";//��ʷ�澯�����˳�
const char VARCS_SHIFTWARN_DBID[] = "VARCS_SHIFTWARN_DBID";//�ڴ���л��澯
//*********************************************************************

const short SHORT_NULL = -9999;//��ֵ�����ֶεĿ�ֵ

//*********************************************************************
//**�û���������õ���ֵ���ô���ֵ�������ַ�����ÿ���ַ����
const unsigned char PASSWORD_EXCLUSIVE_OR = 127;
//*********************************************************************

//*********************************************************************
//**varCSϵͳ������ģ��ı�ţ�Ψһ��ʶ������ģ�顣
//**���ڳ���������program_table���г�����ֶ�ȡֵ

const unsigned char VARCS_TCI_MODULE = 1;//ͨ�Žӿ�
const unsigned char VARCS_GE_MODULE = 2;//ͼ�μ��
const unsigned char VARCS_DBI_MODULE = 3;//ʵʱ���ݹ���
const unsigned char VARCS_HISWARN_MODULE = 4;//��ʷ�澯����
const unsigned char VARCS_OPFSVR_MODULE = 5;//�Ż����Ʒ���
const unsigned char VARCS_OPFCLI_MODULE = 6;//�Ż����ƿͻ�
const unsigned char VARCS_HISBROW_MODULE = 7;//��ʷ�������
const unsigned char VARCS_RTC_MODULE = 8;//ң��ң��
const unsigned char VARCS_USER_MODULE = 9;//�û�����
const unsigned char VARCS_OFFSVR_MODULE = 10;//���߼������
const unsigned char VARCS_OFFCLI_MODULE = 11;//���߼���ͻ�
const unsigned char VARCS_RPT_MODULE = 12;//����
const unsigned char VARCS_MDBI_MODULE = 13;//�ڴ��ӿ�
const unsigned char VARCS_MRTDB_MODULE = 14;//�ڴ��������
const unsigned char VARCS_CRTDB_MODULE = 15;//�ڴ��ͻ�����
const unsigned char VARCS_HISDB_MODULE = 16;//��ʷ��
//*********************************************************************

//*********************************************************************
//**varCSͼ���и�ͼԪ�ı�ţ�Ψһ��ʶ1��ͼԪ����
//**����ͼԪ����������OBJLINK_TABLE��shObjType�ֶ�ȡֵ*******
/*const short METAFIG_FACTORY = 1;//��վ
const short METAFIG_VQC = 2;//VQCװ��
const short METAFIG_BITRANS = 3;//˫�����ѹ��
const short METAFIG_TRITRANS = 4;//�������ѹ��
const short METAFIG_CAPACITANCE = 5;//����
const short METAFIG_REACTANCE = 6;//�翹
const short METAFIG_BREAKER = 7;//����
const short METAFIG_DISCLOSER = 8;//��բ
const short METAFIG_GENERATOR = 9;//�����
const short METAFIG_LOAD = 10;//����
const short METAFIG_BUS = 11;//ĸ��
const short METAFIG_LINE = 12;//��·
const short METAFIG_TNODE = 13;//T�ӵ�
const short METAFIG_YC = 14;//ң��
const short METAFIG_YX = 15;//ң��
const short METAFIG_PULSE = 16;//���
const short METAFIG_YK = 17;//ң��
const short METAFIG_YT = 18;//ң��
const short METAFIG_RELAY = 19;//����
const short METAFIG_RELAY_YX = 20;//����״̬��Ϣ*/
const short METAFIG_VARCS = 21;//varCSϵͳ
//*********************************************************************

/******************************************************************
**������NET_STATUS
**������NET_STATUS˵������״̬
******************************************************************/
struct NET_STATUS
{
	BYTE byNetaStatus;  //A��״̬�������ĵĳ�Աȡֵ
	BYTE byNetbStatus;  //B��״̬��ȡֵͬA��״̬
};

//****NET_STATUS��byNetaStatus��Աȡֵ*********************
const unsigned char NET_OFFLINE = 0;//�˳�
const unsigned char NET_ONLINE = 1;//Ͷ��
//*********************************************************

/******************************************************************
**������OBJECT_ID
**������OBJECT_ID���ڱ�ʾ�豸����վ�����⼰varCSϵͳ
******************************************************************/
struct OBJECT_ID
{
	OBJECT_ID()
	{memset(this, 0, sizeof(OBJECT_ID));};
		
	short shDbNo; //�ڴ����ݿ���
	short shObjType;  //�������ͣ�ȡ����ͼԪ���
	short shObjectFac;  //���󳧺ţ������豸�����������������վ����վ���г��ţ�
	//������·��T�ӵ㡢varCSϵͳ,�������䳧��
	DWORD shObjectNo;  //������ţ������豸������������Ӧ���ڴ����е����
	//���ڳ�վ��varCSϵͳ,�����������
	char pdb[30];
	char ptable[30];
};

/******************************************************************
**������ID_CODE
**������ID_CODE���ڱ�ʶ��վ���豸������
******************************************************************/
struct ID_CODE
{
	short shDbNo; //�ڴ����ݿ���
	short shObjectFac;  //���󳧺ţ������豸�����������������վ����վ���г��ţ�
	short shObjectNo;  //������ţ������豸������������Ӧ���ڴ����е����
};

/******************************************************************
**������MESG_ID
**������MESG_ID���ڱ�ʾ�����ڵ����ݱ��
******************************************************************/
struct MESG_ID
{
	short shDbNo; //�ڴ����ݿ���
	short shSourceNo;  //����Դ��
	short shFacNo;  //����
	short shFrameOrder;  //�������
};

/******************************************************************
**������COMM_STATUS
**������COMM_STATUS���ڱ�ʾͨ��״̬
******************************************************************/
struct COMM_STATUS
{
	BYTE byUpComm;  //����ͨ��״̬��ͬSOURCE_TABLE��byUpComm��Աȡֵ
	BYTE byDownComm;  //����ͨ��״̬��ͬSOURCE_TABLE��byUpComm��Աȡֵ
};

/******************************************************************
**������YC_VS
**������YC_VS���ڱ�ʾң��ֵ����״̬
******************************************************************/
struct YC_VS
{
	float fValue;  //ң��ʵ��ֵ
	BYTE byRefresh;  //����״̬��ͬYC_TABLE��byRefresh��Աȡֵ
	BYTE byLimitStatus;  //Խ��״̬��ͬYC_TABLE��byLimitStatus��Աȡֵ
	short shWarnMode;  //�澯��ʽ
};

/******************************************************************
**������DEVICE_STATUS
**������DEVICE_STATUS���ڱ�ʾ�豸��״̬
******************************************************************/
struct DEVICE_STATUS
{
	short byStatus;  //����״̬��ͬFACTORY_TABLE��byFacStatus��Աȡֵ
	BYTE byLock;  //����״̬��ͬFACTORY_TABLE��byLock��Աȡֵ
	short shWarnMode;  //�澯��ʽ
};

/******************************************************************
**������FACTORY_STATUS
**������FACTORY_STATUS���ڱ�ʾ��վ��״̬
******************************************************************/
struct FACTORY_STATUS
{
	BYTE byStatus;  //����״̬��ͬFACTORY_TABLE��byFacStatus��Աȡֵ
	BYTE byLock;  //����״̬��ͬFACTORY_TABLE��byLock��Աȡֵ
	BYTE byRefresh;  //����״̬��ͬFACTORY_TABLE��byRefresh��Աȡֵ
	short shWarnMode;  //�澯��ʽ
};

/******************************************************************
**������YX_VS
**������YX_VS���ڱ�ʾң��ֵ����״̬
******************************************************************/
struct YX_VS
{
	BYTE byValue;  //ң��ֵ��ͬYX_TABLE��byValue��Աȡֵ
	BYTE byRefresh;  //����״̬��ͬYX_TABLE��byRefresh��Աȡֵ
	BYTE byStatus;  //ң��״̬��ͬYX_TABLE��byStatus��Աȡֵ
	short shWarnMode;  //�澯��ʽ
};

/******************************************************************
**������PULSE_VS
**������PULSE_VS���ڱ�ʾ��������ֵ����״̬
******************************************************************/
struct PULSE_VS
{
	float fValue;  //��������ֵ
	BYTE byRefresh;  //����״̬��ͬPULSE_TABLE��byRefresh��Աȡֵ
	short shWarnMode;  //�澯��ʽ
};

/******************************************************************
**������RELAYYX_VS
**������RELAYYX_VS���ڱ�ʾ����״̬
******************************************************************/
struct RELAYYX_VS
{
	BYTE byStatus;  //����״̬��ͬRELAYYX_TABLE��byStatus��Աȡֵ
	BYTE byRefresh;  //����״̬��ͬRELAYYX_TABLE��byRefresh��Աȡֵ
	short shWarnMode;  //�澯��ʽ
};

#endif //__VARCS_COMMONDATA__H