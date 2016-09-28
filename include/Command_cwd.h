#ifndef	__VARCS_COMMANDCWD__H
#define __VARCS_COMMANDCWD__H

/******************************************************************
**������DZ_STRUCT
**������DZ_STRUCT����ң��ң�����Ƴ��򷢶�ֵ��TCI�ĵ�ѹ�����������Ȳ���    
         ��memcpy�ֽڿ����� CONTROL_COMMAND�� szCommandInfo ��Ա��     
******************************************************************/
struct DZ_STRUCT
{
	float fVoltagHiValue;      //��ѹ����ֵ
	float fVoltagLowValue;    //��ѹ����ֵ
	float fPowerCosHiValue;    //������������ֵ 
	float fPowerCosLowValue;  //������������ֵ
};
const int COMMANDINFOLENTH=sizeof(DZ_STRUCT);   //DZ_STRUCT�ṹ���С

/******************************************************************
**������CONTROL_COMMAND
**������CONTROL_COMMAND����ң��ң�����Ƴ�����TCI�Ŀ�������       
******************************************************************/
struct CONTROL_COMMAND
{
  short	shStationAdd;//���վ��ַ
  short shSourceNo;//����Դ���
  BYTE  byCommandType;//�������ͣ������ĵĳ�Աȡֵ
  int	shOrderNo;//������������
  BYTE  szCommandInfo[COMMANDINFOLENTH]; //�����ĵĳ�Աȡֵ��
                  //�����ң�صĿ��أ�ң�����������ڵ�һ���ֽڣ�
                   //���Ƕ�ֵ�� DZ_STRUCT Ҳ��CommandInfo[0]�ֽڿ�ʼ���                        

};


//****CONTROL_COMMAND��byCommandType��Աȡֵ*****************
const BYTE COMMAND_YK_SELECT = 1;//ң��ѡ��
const BYTE COMMAND_YK_EXE = 2;//ң��ִ��
const BYTE COMMAND_YK_CANCEL = 3;//ң�س���
const BYTE COMMAND_YT_SELECT = 4;//ң��ѡ��
const BYTE COMMAND_YT_EXE = 5;//ң��ִ��
const BYTE COMMAND_YT_CANCEL = 6;//ң������
const BYTE COMMAND_SETTING=7; //�趨����
const BYTE COMMAND_RESET=8; //�������� 
const BYTE COMMAND_FREEZE=9; //�㲥����(��������)
const BYTE COMMAND_SET_TIME = 10;//����ʱ��
const BYTE COMMAND_ADJUSTTIME=11; //����ʱ��У��ֵ����
const BYTE COMMAND_CALLSUBTIME=12;//�ٻ���վʱ������
const BYTE RETURN_OVERTIME=15;//��ʱ
const BYTE RETURN_EXCEPTION=16;//δ֪�쳣

const BYTE COMMAND_DZ_SET=21;    //�趨��ֵ
const BYTE COMMAND_DZ_CANCEL=22; //��ֵ����

const BYTE COMMAND_LOCK_SET=26;    //����
const BYTE COMMAND_LOCK_CANCEL=27; //�������

const BYTE COMMAND_VARCSRUN_NORMAL=30;  //VARCSϵͳ��������


//CONTROL_COMMAND��szCommandInfo ��Աȡֵ
//*********************************************************
const BYTE OPER_UP=11; //ң����
const BYTE OPER_ON=12; //ң�غ�
const BYTE OPER_DOWN=13;//ң����
const BYTE OPER_OFF=14;//ң�ط�
const BYTE OPER_EXE=15;//ң��ִ�У�ң��ִ��
const BYTE OPER_CANCEL=16;//ң��ȡ����ң��ȡ��
const BYTE OPER_STOP=17;//��ͣ
//���Ƕ�ֵ�趨����ó�Աȡֵ��һ��DZ_STRUCT �ṹ��
//*********************************************************



/******************************************************************
**������COMMAND_RETURN
**������COMMAND_RETURN������������ķ�У��Ϣ����TCI����ң��ң�����Ƴ���
******************************************************************/
struct COMMAND_RETURN
{
  short	shStationAdd;//���վ��ַ
  short shSourceNo;//����Դ���
  BYTE  byCommandType;//�������ͣ������ĵĳ�Աȡֵ
  short	shOrderNo;//������������
  BYTE  byReturnInfo;//�������Ϣ�������ĵĳ�Աȡֵ
};

//****COMMAND_RETURN��byCommandType��Աȡֵ******************
//**��CONTROL_COMMAND��byCommandType��Աȡֵ��Ӧ
const BYTE RETURN_YK_SELECT = 1;//ң��ѡ��У
const BYTE RETURN_YK_EXE = 2;//ң��ִ�з�У
const BYTE RETURN_YT_SELECT = 4;//ң��ѡ��У
const BYTE RETURN_YT_EXE = 5;//ң��ִ�з�У
const BYTE RETURN_SET_TIME = 7;//����ʱ�ӷ�У
const BYTE RETURN_DZ_SET=21;    //�趨��ֵ��У
//*********************************************************

//****COMMAND_RETURN��byReturnInfo��Աȡֵ*******************
const BYTE RETURN_DOWN = 1;//��/��
const BYTE RETURN_UP = 2;//��/��

const BYTE RETURN_VERIFY_ERROR = 3;//У�����
const BYTE RETURN_COMMAND_ERROR = 4;//�������,�������Vqc�ܾ�ִ��

const BYTE RETURN_SUCCESS = 5;//ִ�гɹ�
const BYTE RETURN_FAIL = 6;//ִ��ʧ��
const BYTE RETURN_REJECT=7;  //�豸�ܶ�
const BYTE RETURN_IMBALANCE=8;//���಻ƽ���ѹ
const BYTE RETURN_LOCK=9;//�����򲻿ɿ�
const BYTE RETURN_PROTECT=10;//��������
const BYTE RETURN_SLIDEPOS=11;//����
const BYTE RETURN_ERRORPOS=12;//��

const BYTE RETURN_DZSET_SUCCESS = 13;//���ö�ֵ�ɹ�
const BYTE RETURN_DZSET_FAIL = 14;//���ö�ֵʧ��


//*******************************************************


/********************************************************
 ������COMMAND_SENDED
 ������COMMAND_SENDED  ����TCI �ڼ�¼ĳ��SOCKET�ѽ��ղ����͵Ŀ�������
///******************************************************/
 struct COMMAND_SENDED
{
  short	shStationAdd;//���վ��ַ
  short shSourceNo;//����Դ���
  BYTE  byCommandType;//�������ͣ�ͬ���ĵ�CONTROL_COMMAND��CommandType��Աȡֵ
  short	shOrderNo;//������������
  CTime SendTime;//��¼����ʱ��
};

///////////////////////

/*****************************************************
Ϊ�˶�ң��ң��(6��14�����)luo
******************************************************/
struct CHECKYKYT	
{
	short	shFacNo;
	int	shOrderNo;
	//char	szFacName[32];
	char	szObjName[32];

	CHECKYKYT()
	{
		shFacNo = -1;
		shOrderNo  = -1;
		//memset(szFacName, 0, sizeof(szFacName));
		memset(szObjName, 0, sizeof(szObjName));
	}
};
#endif 