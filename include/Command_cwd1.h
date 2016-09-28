#ifndef	__VARCS_COMMANDCWD__H
#define __VARCS_COMMANDCWD__H

/******************************************************************
**������DZ_STRUCT
**������DZ_STRUCT����ң��ң�����Ƴ��򷢶�ֵ��TCI�ĵ�ѹ�����������Ȳ���    
         ��memcpy�ֽڿ����� CONTROL_COMMAND�� CommandInfo ��Ա��     
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
  short	Station_add;//���վ��ַ

  short source_no;//����Դ���
  unsigned char CommandType;//�������ͣ������ĵĳ�Աȡֵ
  short	order_no;//������������
  unsigned char CommandInfo[COMMANDINFOLENTH]; //�����ĵĳ�Աȡֵ��
                  //�����ң�صĿ��أ�ң�����������ڵ�һ���ֽڣ�
                   //���Ƕ�ֵ�� DZ_STRUCT Ҳ��CommandInfo[0]�ֽڿ�ʼ���                        

};

//****CONTROL_COMMAND��CommandType��Աȡֵ*****************
const unsigned char COMMAND_YK_SELECT = 1;//ң��ѡ��
const unsigned char COMMAND_YK_EXE = 2;//ң��ִ��
const unsigned char COMMAND_YK_CANCEL = 3;//ң�س���
const unsigned char COMMAND_YT_SELECT = 4;//ң��ѡ��
const unsigned char COMMAND_YT_EXE = 5;//ң��ִ��
const unsigned char COMMAND_YT_CANCEL = 6;//ң������
const unsigned char	COMMAND_SETTING=7; //�趨����
const unsigned char	COMMAND_RESET=8; //�������� 
const unsigned char COMMAND_FREEZE=9; //�㲥����(��������)
const unsigned char COMMAND_SET_TIME = 10;//����ʱ��
const unsigned char COMMAND_ADJUSTTIME=11; //����ʱ��У��ֵ����
const unsigned char	COMMAND_CALLSUBTIME=12;//�ٻ���վʱ������

const unsigned char COMMAND_DZ_SET=21;    //�趨��ֵ
const unsigned char COMMAND_DZ_CANCEL=22; //��ֵ����

const unsigned char COMMAND_VARCSRUN_NORMAL=30;  //VARCSϵͳ��������


//CONTROL_COMMAND��CommandInfo ��Աȡֵ
//*********************************************************
const unsigned char OPER_UP=11; //ң����
const unsigned char OPER_ON=12; //ң�غ�
const unsigned char OPER_DOWN=13;//ң����
const unsigned char OPER_OFF=14;//ң�ط�
const unsigned char OPER_EXE=15;//ң��ִ�У�ң��ִ��
const unsigned char OPER_CANCEL=16;//ң��ȡ����ң��ȡ��
//���Ƕ�ֵ�趨����ó�Աȡֵ��һ��DZ_STRUCT �ṹ��
//*********************************************************



/******************************************************************
**������COMMAND_RETURN
**������COMMAND_RETURN������������ķ�У��Ϣ����TCI����ң��ң�����Ƴ���
******************************************************************/
struct COMMAND_RETURN
{
  short	Station_add;//���վ��ַ
  short source_no;//����Դ���
  unsigned char CommandType;//�������ͣ������ĵĳ�Աȡֵ
  short	order_no;//������������
  unsigned char ReturnInfo;//�������Ϣ�������ĵĳ�Աȡֵ
};

//****COMMAND_RETURN��CommandType��Աȡֵ******************
//**��CONTROL_COMMAND��CommandType��Աȡֵ��Ӧ
const unsigned char RETURN_YK_SELECT = 1;//ң��ѡ��У
const unsigned char RETURN_YK_EXE = 2;//ң��ִ�з�У
const unsigned char RETURN_YT_SELECT = 4;//ң��ѡ��У
const unsigned char RETURN_YT_EXE = 5;//ң��ִ�з�У
const unsigned char RETURN_SET_TIME = 7;//����ʱ�ӷ�У
const unsigned char RETURN_DZ_SET=21;    //�趨��ֵ��У
//*********************************************************

//****COMMAND_RETURN��ReturnInfo��Աȡֵ*******************
const unsigned char RETURN_DOWN = 1;//��/��
const unsigned char RETURN_UP = 2;//��/��

const unsigned char RETURN_VERIFY_ERROR = 3;//У�����
const unsigned char RETURN_COMMAND_ERROR = 4;//�������

const unsigned char RETURN_SUCCESS = 5;//ִ�гɹ�
const unsigned char RETURN_FAIL = 6;//ִ��ʧ��
const unsigned char RETURN_REJECT=7;  //�豸�ܶ�
const unsigned char RETURN_IMBALANCE=8;//���಻ƽ���ѹ
const unsigned char RETURN_LOCK=9;//�����򲻿ɿ�
const unsigned char RETURN_PROTECT=10;//��������
const unsigned char RETURN_SLIDEPOS=11;//����
const unsigned char RETURN_ERRORPOS=12;//��

const unsigned char RETURN_DZSET_SUCCESS = 13;//���ö�ֵ�ɹ�
const unsigned char RETURN_DZSET_FAIL = 14;//���ö�ֵʧ��


//*******************************************************


/********************************************************
 ������COMMAND_SENDED
 ������COMMAND_SENDED  ����TCI �ڼ�¼ĳ��SOCKET�ѽ��ղ����͵Ŀ�������
///******************************************************/
 struct COMMAND_SENDED
{
  short	Station_add;//���վ��ַ
  short source_no;//����Դ���
  unsigned char CommandType;//�������ͣ�ͬ���ĵ�CONTROL_COMMAND��CommandType��Աȡֵ
  short	order_no;//������������
  CTime SendTime;//��¼����ʱ��
};

///////////////////////


#endif 