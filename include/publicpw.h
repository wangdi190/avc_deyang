#if !defined(AFX_PUBLICPW_H__INCLUDED_)
#define AFX_PUBLICPW_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//���վ����
const int STATION_W=1;		//ˮ��
const int STATION_H=2;		//���
const int STATION_T=3;		//���վ
const int STATION_C=4;		//����վ
const int STATION_F=5;		//���վ
const int STATION_PH=6;		//����վ
const int STATION_NU=7;		//����վ
const int STATION_O=8;		//����

//���������
const int GEN_TYPE_UNKOWN=0;
const int GEN_TYPE_THERMAL=1;		//������
const int GEN_TYPE_HYDRO=2;		//ˮ�����

//�豸�Ӷ���
const int SUBEQUIP_NAME=0;  //�豸����
const int TRANSF_SUB_HIG=1;	//��ѹ���Ӷ��������
const int TRANSF_SUB_MID=2;	//��ѹ���Ӷ���������
const int TRANSF_SUB_LOW=3;	//��ѹ���Ӷ��������

//����λ��
const int MEAS_POS_FROMH=1;  //�豸�׶�/��ѹ����
const int MEAS_POS_TOL=2;	//�豸ĩ��/˫�Ʊ�ͣ����Ʊ�ѹ����
const int MEAS_POS_LOW=3;	//���Ʊ�ѹ����ѹ��

//��ѹ����������
const int WINDING_TYPE_HIGH=0;  //��
const int WINDING_TYPE_LOW=1;  //��
const int WINDING_TYPE_MID=2;  //��


//������������
const int EQUIP_TYPE_UNK=0;//δ֪�豸
const int EQUIP_TYPE_GEN=1;	//�����
const int EQUIP_TYPE_BUS=2;	//ĸ��
const int EQUIP_TYPE_LINE=3;	//��·
const int EQUIP_TYPE_BITRS=4;	//˫�����
const int EQUIP_TYPE_TRITRS=5;//�������
const int EQUIP_TYPE_LOAD=6;	//����
const int EQUIP_TYPE_SHUNT=7;	//�����޹��豸
const int EQUIP_TYPE_SWITCH=8;//����
const int EQUIP_TYPE_DCLINE=9;//ֱ����·
const int EQUIP_TYPE_REACT=10;//�翹��
const int EQUIP_TYPE_SVC=11; //��ֹ�޹�������
const int EQUIP_TYPE_MEASUREMENT=12; //�����ϵ
const int EQUIP_TYPE_SUB=20; //��վ
const int EQUIP_TYPE_TERM=21; //�ն�
const int EQUIP_TYPE_BAY=22; //���
const int EQUIP_TYPE_AREA=23; //����
const int EQUIP_TYPE_DUMMY=24; //δ�豸

const char DevTableName[][12]={"","Gen","Bus","Line","Tfm1","Tfm2","Load","Shunt","Switch","DCLine","Sreact","SVC","","","","","","","","","Station","","","Area",""};
//��������
enum MEASURE_TYPE
{
	MEASURE_TYPE_UN=0,		
	MEASURE_TYPE_V=1,		//��ѹ
	MEASURE_TYPE_P=2,		//�й�
	MEASURE_TYPE_Q=3,		//�޹�
	MEASURE_TYPE_S=4,		//���ڹ���
	MEASURE_TYPE_I=5,		//����
	MEASURE_TYPE_Pf=6,		//��������
	MEASURE_TYPE_T=7,		//�¶�
	MEASURE_TYPE_Pos=8,		//��λ
	MEASURE_TYPE_f=9,		//Ƶ��
	MEASURE_TYPE_Ang=10,	//���
	MEASURE_TYPE_YX=11,		//ң��
	MEASURE_TYPE_Va=12,		//a���ѹ
	MEASURE_TYPE_Vb=13,		//b���ѹ
	MEASURE_TYPE_Vc=14,		//c���ѹ
	MEASURE_TYPE_Vab=15,		//ab�ߵ�ѹ
	MEASURE_TYPE_Vbc=16,		//bc�ߵ�ѹ
	MEASURE_TYPE_Vca=17,		//ca�ߵ�ѹ
	MEASURE_TYPE_Ia=18,		//a�����
	MEASURE_TYPE_Ib=19,		//b�����
	MEASURE_TYPE_Ic=20,		//c�����
	MEASURE_TYPE_Rl=21,		//�����ź�
	MEASURE_TYPE_ETS=22,	//�¹����ź�
	MEASURE_TYPE_GENRATOR=23,	//����
	MEASURE_TYPE_UNSORT=24	//δ����
};

//��ֵ����
const int EQUI_TYPE_INVALID=0;//δ��ֵ
const int EQUI_TYPE_LOAD=1;	//��ֵ����
const int EQUI_TYPE_GEN=2;	//��ֵ�����

//ϵͳ���в���
const BYTE SYSTEM_DATARUN=1;		//���ݷ���
const BYTE SYSTEM_STARUN=2;			//ͳ�Ʒ���
const BYTE SYSTEM_CTRLRUn=3;		//���Ʒ���

const char Compress_YC=1;			//ң��ѹ��
const char Compress_YX=1<<1;		//ң��ѹ��
const char Compress_Ctrl=1<<2;		//����ѹ��
const char Compress_Out=1<<3;		//Խ��ѹ��

#endif // !defined(AFX_PUBLICPW_H__INCLUDED_)
