#if !defined(AFX_AVCDEFPUBLIC_H__INCLUDED_)
#define AFX_AVCDEFPUBLIC_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//visualpw_Station��status�ֶ�״̬λ
const short STATION_LOCKED=0x10;//1<<8;   //����λ

//visualpw_Tfm1��status�ֶ�״̬λ
//visualpw_Tfm2��status�ֶ�״̬λ
const short TRANSFORM_LASTUP=1<<0;   //�������λ
const short TRANSFORM_HREGU=1<<1;   //��ѹ���ص�ѹλ
const short TRANSFORM_MREGU=1<<2;   //��ѹ���ص�ѹλ
const short TRANSFORM_LREGU=1<<3;   //��ѹ���ص�ѹλ

const short TRANSFORM_LOCKED=0x10;//1<<8;   //����λ

//visualpw_Shunt��status�ֶ�״̬λ
const short SHUNT_LOCKED=0x10;//1<<8;   //����λ

//visualpw_Gen��status�ֶ�״̬λ
const short GENERATOR_PNOR_CTRLV = 0;//P���������Ƶ�ѹ ƽ���
const short GENERATOR_FIXPQ = 1;//�̶�P��Q���
const short GENERATOR_FIXP_CTRLV = 2;//�̶�P��������Ƶ�ѹ PV�ڵ�
const short GENERATOR_PNOR_FIXQ = 3;//P����,�̶�Q���

//��ѹ�ȼ�
const unsigned char VOLTAGE_DEG_380 = 0;//380V
const unsigned char VOLTAGE_DEG_3K = 1;//3kV
const unsigned char VOLTAGE_DEG_6K = 2;//6kV
const unsigned char VOLTAGE_DEG_10K = 3;//10kV
const unsigned char VOLTAGE_DEG_35K = 4;//35kV
const unsigned char VOLTAGE_DEG_63K = 5;//63kV
const unsigned char VOLTAGE_DEG_110K = 6;//110kV
const unsigned char VOLTAGE_DEG_220K = 7;//220kV
const unsigned char VOLTAGE_DEG_330K = 8;//330kV
const unsigned char VOLTAGE_DEG_500K = 9;//500kV
const unsigned char VOLTAGE_DEG_60K = 10;//60kV
const unsigned char VOLTAGE_DEG_132K = 11;//132kV
const unsigned char VOLTAGE_DEG_13K8 = 12;//13.8kV
const unsigned char VOLTAGE_DEG_13K2 = 13;//13.2kV
const unsigned char VOLTAGE_DEG_33K = 14;//33kV
const unsigned char VOLTAGE_DEG_24K = 15;//24kV
const unsigned char VOLTAGE_DEG_20K = 16;//20kV

//****TISLAND��SeResult��Աȡֵ********************
const unsigned char SE_SUCCESS = 0;//����ɹ�
const unsigned char SE_INVALID = 1;//��������Ч
const unsigned char SE_INOBSERV = 2;//���ɹ۲�
const unsigned char SE_NOCONVERGE = 3;//������
const unsigned char SE_ERROR = 4;//�������
const unsigned char SE_ELIGIBLELOW = 5;//�ϸ��ʹ���
//*********************************************************

//****TISLAND��OpfResult��Աȡֵ*******************
const unsigned char OPF_SUCCESS = 0;//����ɹ�
const unsigned char OPF_NOCONVERGE = 1;//������
const unsigned char OPF_ERROR = 2;//�������
//*********************************************************

/******************************************************************
**������SHADY_TABLE
**������SHADY_TABLE��Ӧ�����ݿ�Ŀ������ݱ�
******************************************************************/
struct SHADY_TABLE
{
	BYTE bType;//�����������ͣ������ĵĳ�Աȡֵ
	char szInfo[160];
};

//****SHADY_TABLE��bType��Աȡֵ**********************
const unsigned char SHADINESS_NONMEASURE=6;   //α������Ϣ
const unsigned char SHADINESS_ERRORDATA=5;   //��������
const unsigned char SHADINESS_BADDATA=4;   //������
const unsigned char SHADINESS_BRANCH_BALANCE=3;   //֧·��ƽ��
const unsigned char SHADINESS_NODE_BALANCE  =2;   //�ڵ㲻ƽ��
const unsigned char SHADINESS_SWITCH_BRANCH =1;   //���ɿ���֧·���
const unsigned char SHADINESS_OTHER_CASE    =0;   //�������˲�ƽ������
//*********************************************************

const unsigned char AVC_QUIT=1;
const unsigned char AVC_OPERATE_LOCK=2;

//�Ż����ö���
const unsigned short STUS_DEVLOCKED=0x0100;			//����״̬
const unsigned short STUS_DEVOPFED=0x0200;			//�Ż�״̬
const unsigned short AVC_RUN=0x0300;
const unsigned short AVC_OPERATE_NORMAL=0x400;

//����ר��
const unsigned short STUS_VALUETYPE=0x0400;			//���ʶ�ֵ��Ĭ��Ϊ�����޹���ֵ
//���ר��
const unsigned short STUS_GEN_P_CV=0x0100;			//����P����ѹ����
const unsigned short STUS_GEN_P_Q=0x0200;			//P��Q���
const unsigned short STUS_GEN_FIXP_CV=0x0400;		//�̶�P����ѹ����
const unsigned short STUS_GEN_P_FIQ=0x0400;			//����P���̶�Q
//��ѹ��ר��
const unsigned short STUS_CTRL_HI=0x0800;			//��ѹ�ɵ�
const unsigned short STUS_CTRL_MID=0x0400;			//��ѹ�ɵ�
const unsigned short STUS_CTRL_HM=0x0c00;			//����ѹ�ɵ�
const unsigned short STUS_CTRLV_HIG=0x3000;			//����ѹ���ѹ
const unsigned short STUS_CTRLV_MID=0x2000;			//�����ѹ���ѹ
const unsigned short STUS_CTRLV_LOW=0x1000;			//����ѹ���ѹ
const unsigned short STUS_GATETFM=0x0300;				//�ؿڱ�ѹ��

//ĸ��ר��
const unsigned short STUS_GATEBUS=0x0300;			//�ؿ�ĸ��
const unsigned short STUS_ENFORCE_V=0x0400;			//�Ƶ�ѹ��ֵ���
const unsigned short STUS_ENFORCE_VC=0x0800;		//�Ƶ�ѹ�仯��� 
const unsigned short STUS_BUS_PQBUS=0x0001;			//����ĸ��


typedef struct AVCLimitParam			//AVC���ƶ�ֵ����
{
	AVCLimitParam(){	memset(this, 0, sizeof(AVCLimitParam));}
	DWORD nu;			//��ֵ���
	float bvol;			//������ѹ
	float voldn;		//��ѹ����
	float volup;		//��ѹ����
	float cosdn;		//������������
	float cosup;		//������������
	float gcosdn;		//�ؿڹ�����������
	float gcosup;		//�ؿڹ�����������
	int capnum;			//��������������
	int xfmnum;			//��ѹ����������
	CTime startt;		//��ʼʱ��
	CTime endt;			//��ֹʱ��
}AVCLimitParam;	


typedef struct BusVoltageRate				//��ѹ�ϸ�����Ϣ
{
	BusVoltageRate(){memset(this, 0, sizeof(BusVoltageRate));}
	BYTE type;			//����0ϵͳ��1����2���վ��3ĸ��
	DWORD zoneNU;		//�ϼ���ţ�ĸ��Ϊ��վ ����վΪ����
	DWORD parentNU;		//�ϼ���ţ�ĸ��Ϊ��վ ����վΪ����
	DWORD NU;
	char Name[64];
	BYTE datetype;		//ʱ������0�����ݡ�1Сʱ����
	float fvolleavel;		//��ѹ�ȼ�
	float fmaxvalue;		//Խ�޷���
	float fminvalue;		//Խ�޷���
	UINT outtime;		//Խ��ʱ��(��)
	UINT alltime;		//��ʱ��(��)
}BusVoltageRate;

const BYTE VolRate_system=0;
const BYTE VolRate_zone=1;
const BYTE VolRate_sub=2;
const BYTE VolRate_bus=3; 

typedef struct CtrlInfo					//������Ϣ
{
	CTime tm;			//ʱ��
	float oldpos;		//ԭʼ״̬
	float newpos;		//����״̬
	float oldv[3];		//ԭʼ��ѹ������Ǳ�ѹ�����Ǹ��ࣻ
	float newv[3];		//������ѹ
	float oldcos;		//ԭʼ��������
	float newcos;		//������������
}CtrlInfo;

typedef struct DistribCtrlRate			//���Ʒֲ���Ϣ
{
	DistribCtrlRate()
	{
		Name[0]=0;
		ctrlinfo.RemoveAll();
	}
	~DistribCtrlRate()
	{
		int count = ctrlinfo.GetSize();
		for(int i=0; i<count; i++)
		{
			CtrlInfo* ptmp = (CtrlInfo*)ctrlinfo.GetAt(i);
			if(ptmp!=NULL)
				delete ptmp;
		}
		ctrlinfo.RemoveAll();
	}
	BYTE type;			//�����豸����
	DWORD zone;			//����
	DWORD Station;		//��վ
	DWORD NU;
	char Name[64];
	BYTE datetype;		//ʱ������0�����ݡ�1Сʱ����
	CPtrArray ctrlinfo;
}DistribCtrlRate;

typedef struct DevCosRate				//�豸���������ϸ�����Ϣ
{
	DevCosRate(){memset(this, 0, sizeof(DevCosRate));}
	BYTE devtype;		//�豸
	DWORD zoneNU;		//����
	DWORD stationNU;	//��վ
	DWORD NU;
	char Name[64];
	BYTE gatetype;		//�ؿ�����0��ͨ��1�ؿ�
	float fcos;			//Խ�޷���
	UINT outtime;		//Խ��ʱ��(��)
	UINT alltime;		//��ʱ��(��)
}DevCosRate;


//********����ʵʱչʾָ��**********�ϸ��ӦRealAVCCapably���˳��*******************************
typedef enum SystemCapably
{
	VolRate_System=0,
	VolRate_SystemOut,
	VolRate_500,
	VolRate_220,
	VolRate_110,
	VolRate_35,
	VolRate_10,
	CosRate_System,
	CosRate_SystemOut,
	DevAct_System,
	DevAct_Trans,
	DevAct_Shunt,
	AVCAct_System,
	AVCAct_Trans,
	AVCAct_Shunt,
	AVCAct_RefuseNum,
	PowerLoss_SystemP,
	PowerLoss_SystemQ,
	PowerLoss_TransP,
	PowerLoss_TransQ,
	PowerLoss_LineP,
	PowerLoss_LineQ,
	PowerLoss_AVC,
	LockInfo_System,
	LockInfo_Bus,
	LockInfo_Trans,
	LockInfo_Shunt,
	ZoneInfo_Island,
	ZoneInfo_CtrlZone=28,
	VolRate_AVCVol=29,
	LockInfo_SystemNum=30,
	PowerLoss_ShuntQ=31,
	PowerLoss_GenP=32,
	PowerLoss_GenQ=33,
	PowerLoss_LoadP=34,
	PowerLoss_LoadQ=35,
	Capably_End
}SystemCapably;


#define DB_SYSTEM 1
#define DB_ZONE 2
#define DB_STATION 3
#define DB_VOLLEVEL 4
#define DB_BUS 5
#define DB_TRANS 6
#define DB_SHUNT 7
#define DB_LINE 8

#define DB_TYPE_VOL 1
#define DB_TYPE_COS 2

//*********����ʵʱչʾָ��****************************************

//������̬����״̬������
//��վ
const BYTE RUNDATA_STA_OldVolOut=0x01;				//ԭʼ��ѹԽ��
const BYTE RUNDATA_STA_VolOut=0x02;					//��ѹԽ��
const BYTE RUNDATA_STA_OldCosOut=0x04;				//ԭʼ�޹�Խ��
const BYTE RUNDATA_STA_CosOut=0x08;					//�޹�Խ��
const BYTE RUNDATA_STA_CtrlCmd=0x10;				//�п���ָ��
//�������ƣ���ѹ�仯�ƣ���ѹ�಻Ϊ0�͹ң����޹��仯�ƣ����಻Ϊ0�͹ң�������ָ���ƣ�����RUNDATA_STA_CtrlCmd�͹ң�

//ĸ��
const BYTE RUNDATA_BUS_OldVolOut=0x01;				//ԭʼ��ѹԽ��
const BYTE RUNDATA_BUS_VolOut=0x02;				//��ѹԽ��
//��һ���ƣ���ѹ�仯�ƣ�ֻҪ��Ϊ0��Ӧ�ù���

//��ѹ��
const BYTE RUNDATA_TFM_OldCosOut=0x01;		//ԭʼ�޹�Խ��
const BYTE RUNDATA_TFM_CosOut=0x02;				//�޹�Խ��
const BYTE CTRLDATA_TFM_TfmDn=0x04;				//��ѹ������
const BYTE CTRLDATA_TFM_TfmUp=0x08;				//��ѹ������
//�Ҷ����ƣ��޹��仯�ƣ�����ָ���ƣ�����ָ���ƻ򽵵�ָ���ƣ�

//����
const BYTE CTRLDATA_SHUNT_ShuntClose=0x01;			//�����˳�
const BYTE CTRLDATA_SHUNT_ShuntOpen=0x02;			//������Ͷ��
//��һ���ƣ�����ָ���ƣ�Ͷ��ָ���ƻ��˳�ָ���ƣ�

#endif // !defined(AFX_AVCDEFPUBLIC_H__INCLUDED_)
