/******************************************************************
** �ļ���:sysData.h
** Copyright (c) 1998-2003*********������������ɷ����޹�˾
** ���� :������    ����:2003-8-25
** �޸���:         ����:
** ����:���ļ��ṩ���ݿ��ϵͳ���ݵ����ݽṹ�ͳ������塣
** �汾:1.0
**-----------------------------------------------------------------
******************************************************************/

#ifndef	__VARCS_SYSDATA__H
#define __VARCS_SYSDATA__H

const short SYSDATA_NAME_LENGTH = 50;
const short DEFAULT_COMMENT_LENGTH = 250;
const short SYSDATA_IPADD_LENGTH = 24;

/******************************************************************
**������TABLE_TABLE
**������TABLE_TABLE��Ӧ�����ݿ�ı�����
******************************************************************/
struct TABLE_TABLE
{
  short shViewNo;  //���
  char szViewName[SYSDATA_NAME_LENGTH];  //������
  char szDisplayName[SYSDATA_NAME_LENGTH];  //��ʾ����
  short shViewAttrib;  //���ԣ������ĵĳ�Աȡֵ����
  char szViewClass[SYSDATA_NAME_LENGTH];  //���
  short shFilterView;  //���˱�
  short shMaxRange;  //������
  BYTE byAccessLevel;  //���ʼ���
  BYTE byType;  //�����ͣ������ĵĳ�Աȡֵ
  short shFieldNum;  //�ֶ���
  short shRecLen;  //��¼����
};

//****TABLE_TABLE��shViewAttrib��Աȡֵ����****************
const short TABLE_MEMDB_MASK =	0x01;//�ڴ�����
const short TABLE_HISDB_MASK = 0x01<<1;//��ʷ����
const short TABLE_TEMDB_MASK = 0x01<<2;//��ʱ����
const short TABLE_INIT_MASK =	0x01<<3;//���ʼ��
const short TABLE_DBI_MASK =	0x01<<4;//����DBI����
const short TABLE_INFO_MASK =	0x01<<5;//��Ϣѡ��
const short TABLE_REALTIME_MASK =	0x01<<6;//ʵʱ��Ϣ
const short TABLE_FIXNUM_MASK =	0x01<<7;//����������¼
//*********************************************************

//****TABLE_TABLE��byType��Աȡֵ***********************
const unsigned char TABLE_COMMON_TYPE = 0;//��ͨ��
const unsigned char TABLE_CYCLE_TYPE = 1;//ѭ����
//*********************************************************

/******************************************************************
**������FIELD_TABLE
**������FIELD_TABLE��Ӧ�����ݿ���ֶα�
******************************************************************/
struct FIELD_TABLE
{
  short shViewNo;  //����
  short shFieldNo;  //�ֶα��
  char szFieldName[SYSDATA_NAME_LENGTH];  //�ֶ���
  char szDisplayName[SYSDATA_NAME_LENGTH];  //��ʾ����
  char szComment[DEFAULT_COMMENT_LENGTH];  //�ֶ�˵��
  BYTE byDataType;  //�������ͣ������ĵĳ�Աȡֵ
  short shOffset;  //ƫ����
  short shLength;  //�ֶγ���
  short shFieldAttrib;  //���ԣ������ĵĳ�Աȡֵ����
  BYTE byDecimalDigit;  //С��λ��
  char szInitVal[SYSDATA_NAME_LENGTH];  //��ʼֵ
  char szMaxVal[SYSDATA_NAME_LENGTH];  //���ֵ
  char szMinVal[SYSDATA_NAME_LENGTH];  //��Сֵ
  char szDefaultVal[SYSDATA_NAME_LENGTH];  //ȱʡֵ
  char szEnumString[DEFAULT_COMMENT_LENGTH];  //ö���ַ���
};

//****FIELD_TABLE��byDataType��Աȡֵ**********************
const unsigned char FIELD_SIENUM_TYPE = 0;//��ѡ
const unsigned char FIELD_MUENUM_TYPE = 1;//��ѡ
const unsigned char FIELD_BYTE_TYPE = 2;//BYTE
const unsigned char FIELD_SHORT_TYPE = 3;//short
const unsigned char FIELD_INT_TYPE = 4;//int
const unsigned char FIELD_LONG_TYPE = 5;//long
const unsigned char FIELD_FLOAT_TYPE = 6;//float
const unsigned char FIELD_DOUBLE_TYPE = 7;//double
const unsigned char FIELD_STRING_TYPE = 8;//string
const unsigned char FIELD_DATETIME_TYPE = 9;//datetime
const unsigned char FIELD_FORMULA_TYPE = 10;//formula
const unsigned char FIELD_STRUCT_TYPE = 11;//struct
const unsigned char FIELD_JBYTE_TYPE = 12;//join_BYTE
const unsigned char FIELD_JSHORT_TYPE = 13;//join_short
const unsigned char FIELD_WTIME_TYPE = 14;//warn_time
const unsigned char FIELD_TIME_TYPE = 15;//time
//*********************************************************

//****FIELD_TABLE��shFieldAttrib��Աȡֵ����***************
const short COL_KEY_MASK = 0x01;//�ؼ���
const short COL_NONULL_MASK = 0x01<<1;//�ǿ�
const short COL_DISPLAY_MASK = 0x01<<2;//����ʾ
const short COL_ALTER_MASK = 0x01<<3;//�ɸ�
const short COL_INIT_MASK = 0x01<<4;//��ʼ��
const short COL_RECNAME_MASK = 0x01<<5;//��¼��
const short COL_REALTIME_MASK = 0x01<<6;//ʵʱ
//*********************************************************

/******************************************************************
**������NODE_TABLE
**������NODE_TABLE��Ӧ�����ݿ�Ľڵ��
******************************************************************/
struct NODE_TABLE
{
  BYTE byNodeNo;  //�ڵ��
  char szNodeName[SYSDATA_NAME_LENGTH];  //������
  char szNetaIpAddr[SYSDATA_IPADD_LENGTH];  //A��IP��ַ
  char szNetbIpAddr[SYSDATA_IPADD_LENGTH];  //B��IP��ַ
  BYTE byNodeType;  //���ͣ������ĵĳ�Աȡֵ
  BYTE byTciType;  //ǰ�û����ͣ������ĵĳ�Աȡֵ
  BYTE byHisType;  //��ʷ�����ͣ������ĵĳ�Աȡֵ
  short shFuncType;  //�������ͣ������ĵĳ�Աȡֵ����
  short shWarnProc;  //�澯���������ĵĳ�Աȡֵ����
  BYTE byNetaStatus;  //A��״̬�������ĵĳ�Աȡֵ
  BYTE byNetbStatus;  //B��״̬��ȡֵͬA��״̬
  short shWarnMode;  //�澯��ʽ�������ĵĳ�Աȡֵ����
};

//****NODE_TABLE��byNodeType��Աȡֵ***********************
const unsigned char NODE_WORKSTATION = 0;//����վ
const unsigned char NODE_MASTER_HOST = 1;//����
const unsigned char NODE_STANDBY_HOST = 2;//�ȱ�������
//*********************************************************

//****NODE_TABLE��byTciType��Աȡֵ************************
const unsigned char NODE_NO_TCI = 0;//����վ
const unsigned char NODE_MASTER_TCI = 1;//��ǰ�û�
const unsigned char NODE_STANDBY_TCI = 2;//����ǰ�û�
//*********************************************************

//****NODE_TABLE��byHisType��Աȡֵ************************
const unsigned char NODE_SLAVE_HISTORY = 0;//����վ
const unsigned char NODE_MASTER_HISTORY = 1;//��ʷ��
//*********************************************************

//****NODE_TABLE��shFuncType��Աȡֵ����*******************
const short NODE_GE_MASK = 0x01;//ͼ�μ��
const short NODE_DBI_MASK = 0x01<<1;//ʵʱ���ݹ���
const short NODE_TCI_MASK = 0x01<<2;//ͨ�Žӿ�
const short NODE_RTC_MASK = 0x01<<3;//ң��ң��
const short NODE_HISWARN_MASK = 0x01<<4;//��ʷ�澯
const short NODE_OPFSER_MASK = 0x01<<5;//�Ż����Ʒ���
const short NODE_OFFSVR_MASK = 0X01<<5;//���߼���������Ż����Ʒ�����ͬ
const short NODE_OPFCLI_MASK = 0x01<<6;//�Ż����ƿͻ�
const short NODE_OFFCLI_MASK = 0x01<<6;//���߼���ͻ������Ż����ƿͻ���ͬ
const short NODE_REPORT_MASK = 0x01<<7;//����
const short NODE_HISBROWSE_MASK = 0X01<<7;//��ʷ����������뱨����ͬ
const short NODE_USER_MASK = 0x01<<8;//�û�����
//*********************************************************

//****NODE_TABLE��shWarnProc��Աȡֵ����*******************
const short NODE_DISPLAY_WARN = 0x01;//�澯��ʾ
const short NODE_PRINT_WARN = 0x01<<1;//�����ӡ
const short NODE_VOICE_WARN = 0x01<<2;//�����澯
//*********************************************************

//****NODE_TABLE��byNetaStatus��Աȡֵ*********************
const unsigned char NODE_QUIT = 0;//�˳�
const unsigned char NODE_RUN = 1;//Ͷ��
//*********************************************************

//****NODE_TABLE��shWarnMode��Աȡֵ����*******************
const short WARN_DISPLAY_MASK = 0x01;//����ʾ
const short WARN_LOG_MASK = 0x01<<1;//���¼
const short WARN_PRINT_MASK = 0x01<<2;//���ӡ
const short WARN_VOICE_MASK = 0x01<<3;//������
//*********************************************************

/******************************************************************
**������PROGRAM_TABLE
**������PROGRAM_TABLE��Ӧ�����ݿ�ĳ���������
******************************************************************/
struct PROGRAM_TABLE
{
  BYTE byProgramNo;  //�����
  char szProgramName[SYSDATA_IPADD_LENGTH];  //��������
  int iSevrPort;  //����˿�
  int iBroadPort;  //�㲥�˿�
  BYTE byMaxProcess;  //��������
  BYTE byMaxServProc;  //�������������
  BYTE byNodeMaxProc;  //�ڵ���������
};

/******************************************************************
**������PROCESS_TABLE
**������PROCESS_TABLE��Ӧ�����ݿ�Ľ���״̬��
******************************************************************/
struct PROCESS
{
  BYTE byNodeNo;  //�ڵ��
  BYTE byProgramNo;  //�����
  BYTE byProcessNum;  //������
};

/******************************************************************
**������USER_TABLE
**������USER_TABLE��Ӧ�����ݿ���û�Ȩ�ޱ�
******************************************************************/
struct USER_TABLE
{
  char szUserName[SYSDATA_NAME_LENGTH];  //�û���
  char szPassword[SYSDATA_NAME_LENGTH];  //����
  BYTE byGroupNo;  //���𣬼����ĵĳ�Աȡֵ
  short shPurview;  //Ȩ�ޣ������ĵĳ�Աȡֵ����
};

//****USER_TABLE��byGroupNo��Աȡֵ************************
const unsigned char USER_SUPER = 0;//�����û�
const unsigned char USER_SYSMAN = 1;//ϵͳ����Ա
const unsigned char USER_MANAGER = 2;//����Ա
const unsigned char USER_MADISP = 3;//������Ա
const unsigned char USER_DISPATCHER = 4;//����Ա
const unsigned char USER_COMMON = 5;//һ����Ա
//*********************************************************

//****USER_TABLE��shPurview��Աȡֵ����********************
const short USER_BROWS_ATTRIB = 0x01;//�鿴����
const short USER_ALTER_ATTRIB = 0x01<<1;//�޸�����
const short USER_BROWS_DATA = 0x01<<2;//�������
const short USER_RTC = 0x01<<3;//���Ʋ���
const short USER_ALTER_REPORT = 0x01<<4;//�����޸�
const short USER_ALTER_GRAPH = 0x01<<5;//ͼ���޸�
const short USER_ALTER_DB = 0x01<<6;//���ݿ��޸�
const short USER_MANAGE_USER = 0x01<<7;//�û�����
//*********************************************************


#endif //__VARCS_SYSDATA__H