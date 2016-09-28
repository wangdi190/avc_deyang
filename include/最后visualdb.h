#if !defined(_DB_STRUCT_H_)
#define _DB_STRUCT_H_
/************************************************/
//��ͷ�ļ��ɡ����ݿ����������Զ�����
//2008-5-26
//�Ǻ��߿Ƽ���ҵ�ɷ����޹�˾
/************************************************/
//����Ԥ����ֵ
//=================���ӻ�����ϵͳ��===============
//PT��
typedef struct visualpw_PT
{
	DWORD  NU;							//PT���
	char  Name[24];						//PT����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}visualpw_PT,*LPvisualpw_PT;
//�����
typedef struct visualpw_Gen
{
	DWORD  NU;							//�������
	char  Name[24];						//�������
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  MaxP;						//�й�����
	float  Par;							//�й������ٷֱȸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  Pchk;						//���޹���
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//Ԥ��
	BYTE  ack;							//�澯ȷ��
	float  P;							//�й�����
	float  Q;							//�޹�����
	float  angle;						//�Ƕ�
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}visualpw_Gen,*LPvisualpw_Gen;
//���ص�բ
typedef struct visualpw_Switch
{
	DWORD  NU;							//���ر��
	char  Name[24];						//��������
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	CTime  TurnDTime;					//����ʱ��
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  alarm;						//�ܸ澯
	BYTE  AlmRelay;						//���������澯0��1��2
	BYTE  SwtChange;					//���ر�λ
	BYTE  ack;							//ȷ��
	BYTE  rp;							//����״̬
	DWORD  BayID;						//���ID
}visualpw_Switch,*LPvisualpw_Switch;
//����
typedef struct visualpw_Load
{
	DWORD  NU;							//���ɱ��
	char  Name[24];						//��������
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  MaxP;						//�й�����
	float  MinP;						//�й�����
	float  P;							//�й�����
	float  Q;							//�޹�����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
}visualpw_Load,*LPvisualpw_Load;
//����
typedef struct visualpw_Shunt
{
	DWORD  NU;							//�����豸���
	char  Name[24];						//�����豸����
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  Vl;							//��ѹ�ȼ�
	float  Q;							//Ͷ���޹�
	float  Qmax;						//����޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}visualpw_Shunt,*LPvisualpw_Shunt;
//�翹
typedef struct visualpw_Sreact
{
	DWORD  NU;							//�翹�����
	char  Name[24];						//�翹����
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  Vl;							//��ѹ�ȼ�
	float  zst;							//����
	float  Zx;							//Ͷ��翹
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}visualpw_Sreact,*LPvisualpw_Sreact;
//2�����ѹ��
typedef struct visualpw_Tfm1
{
	DWORD  NU;							//2�Ʊ���
	char  Name[24];						//2�Ʊ���
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  Vl;							//��ѹ�ȼ�
	WORD  Tallow;						//��������ʱ��(��)
	WORD  Tover;						//����������ʱ��(��)
	float  tap;							//��ѹ���ֽ�ͷ
	float  Pmax;						//��ѹ������й�(����)
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  P;							//��ѹ���й�
	float  Q;							//��ѹ���޹�
	float  I;							//��ѹ�����
	float  P2;							//��ѹ���й�
	float  Q2;							//��ѹ���޹�
	float  I2;							//��ѹ�����
	float  Tcur;						//��ǰ�¶�
	float  Tmax;						//����¶�
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//�ܸ澯
	BYTE  ack;							//�澯ȷ��
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
	float  T1;							//�¶�1
	float  T2;							//�¶�2
	float  T3;							//�¶�3
	float  T4;							//�¶�4
	BYTE  AlmTfast;						//�¶�ͻ��澯
	BYTE  AlmCur;						//�¶����߸澯
	BYTE  AlmOver;						//�¶�Խ�޸澯
	BYTE  AlmLoad;						//����Խ�޸澯
	BYTE  AlmRelay;						//�����źŸ澯
}visualpw_Tfm1,*LPvisualpw_Tfm1;
//3�����ѹ��
typedef struct visualpw_Tfm2
{
	DWORD  NU;							//3�Ʊ���
	char  Name[24];						//3�Ʊ���
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  Vl;							//��ѹ�ȼ�
	WORD  Tallow;						//��������ʱ��(��)
	WORD  Tover;						//����������ʱ��(��)
	float  TapH;						//�߶˷ֽ�ͷλ��
	float  TapM;						//�ж˷ֽ�ͷλ��
	float  TapL;						//�Ͷ˷ֽ�ͷλ��
	float  Pmax;						//��ѹ������й�(����)
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  P;							//��ѹ���й�
	float  Q;							//��ѹ���޹�
	float  I;							//��ѹ�����
	float  P2;							//��ѹ���й�
	float  Q2;							//��ѹ���޹�
	float  I2;							//��ѹ�����
	float  P3;							//��ѹ���й�
	float  Q3;							//��ѹ���޹�
	float  I3;							//��ѹ�����
	float  Tcur;						//��ǰ�¶�
	float  Tmax;						//����¶�
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//�ܸ澯
	BYTE  ack;							//�澯ȷ��
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  Tnum;							//�ɼ����¶ȸ���
	float  T1;							//�¶�1
	float  T2;							//�¶�2
	float  T3;							//�¶�3
	float  T4;							//�¶�4
	float  T5;							//�¶�5
	float  T6;							//�¶�6
	BYTE  rp;							//����״̬
	BYTE  AlmTfast;						//�¶�ͻ��澯
	BYTE  AlmCur;						//�¶����߸澯
	BYTE  AlmOver;						//�¶�Խ�޸澯
	BYTE  AlmLoad;						//����Խ�޸澯
	BYTE  AlmRelay;						//�����źŸ澯
}visualpw_Tfm2,*LPvisualpw_Tfm2;
//��̬�޹�����
typedef struct visualpw_SVC
{
	DWORD  NU;							//SVC���
	char  Name[24];						//SVC����
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  Qmax;						//����޹����
	float  Qmin;						//��С�޹����
	float  Q;							//�޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}visualpw_SVC,*LPvisualpw_SVC;
//ĸ��
typedef struct visualpw_Bus
{
	DWORD  NU;							//ĸ�߱��
	char  Name[24];						//ĸ������
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  MaxV;						//��ѹ����
	float  MinV;						//��ѹ����
	float  HiLimit;						//��ѹ�澯����
	float  LoLimit;						//��ѹ�澯����
	float  Vl;							//��ѹ�ȼ�
	float  V;							//�ڵ��ѹ(pu)
	float  Vb;							//��ѹʵ��ֵ
	float  DayMax;						//�����ֵ
	float  DayMin;						//����Сֵ
	float  deg;							//���
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  AlmOver;						//Խ������0��1��2
	BYTE  AlmRelay;						//�����źŸ澯
	BYTE  alarm;						//�ܸ澯
	BYTE  ack;							//�澯ȷ��
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}visualpw_Bus,*LPvisualpw_Bus;
//������
typedef struct visualpw_Line
{
	DWORD  NU;							//�����߱��
	char  Name[24];						//����������
	DWORD  StationNU;					//����վ
	int  Zonef;							//��ʼ�������
	int  Zonet;							//�յ��������
	float  Vl;							//��ѹ�ȼ�
	float  Imax;						//�������ֵ
	float  MaxP;						//�й�����
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  Pf;							//ʼ���й�
	float  Qf;							//ʼ���޹�
	float  Pt;							//ĩ���й�
	float  Qt;							//ĩ���޹�
	float  I;							//����ֵ
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//�ܸ澯
	BYTE  ack;							//�澯ȷ��
	BYTE  AlmRelay;						//�����źŸ澯
	BYTE  AlmLoad;						//����Խ�޸澯
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
	BYTE  BayID;						//���ID
}visualpw_Line,*LPvisualpw_Line;
//ֱ����
typedef struct visualpw_DCLine
{
	DWORD  NU;							//ֱ���߱��
	char  Name[24];						//ֱ��������
	DWORD  StationNU;					//����վ
	int  Zonef;							//��ʼ�������
	int  Zonet;							//�յ��������
	float  Imax;						//�������ֵ
	float  Maxp;						//�й�����
	float  Par;							//����߸����ʸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  Pf;							//ʼ���й�
	float  Qf;							//ʼ���޹�
	float  Pt;							//ĩ���й�
	float  Qt;							//ĩ���޹�
	float  I;							//����ֵ
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//Ԥ��
	BYTE  ack;							//�澯ȷ��
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
	BYTE  BayID;						//���ID
}visualpw_DCLine,*LPvisualpw_DCLine;
//�������������
typedef struct visualpw_CVT
{
	DWORD  NU;							//�豸���
	char  Name[24];						//�豸����
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
}visualpw_CVT,*LPvisualpw_CVT;
//�ӵ�
typedef struct visualpw_GND
{
	DWORD  NU;							//�ӵر��
	char  Name[24];						//�ӵ�����
	DWORD  StationNU;					//����վ��
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
}visualpw_GND,*LPvisualpw_GND;
//����
typedef struct visualpw_Zone
{
	DWORD  NU;							//������
	char  Name[24];						//��������
	float  total_los;					//�й����
	float  total_gen;					//�й�����
	float  demand;						//�й�����
	float  cost;						//��λ��������
	float  curlr;						//��ǰ������
	float  lastlr;						//�ϴθ�����
	float  nextlr;						//δ��������
}visualpw_Zone,*LPvisualpw_Zone;
//վ
typedef struct visualpw_Station
{
	DWORD  NU;							//վ��
	char  Name[24];						//վ��
	DWORD  zoneNU;						//��������
	BYTE  Alarm;						//վ�澯
	BYTE  ack;							//�澯ȷ��
}visualpw_Station,*LPvisualpw_Station;
//ϵͳָ��
typedef struct visualpw_SysGD
{
	DWORD  ID;							//ָ���ʶID
	char  Name[24];						//ָ������
	float  zb;							//��ǰָ��
	float  Vmax;						//�������ֵ
	float  Vmin;						//������Сֵ
	float  Vmax1;						//��һ�����ֵ
	float  Vmin1;						//��һ����Сֵ
	float  Vmax2;						//�ڶ������ֵ
	float  Vmin2;						//�ڶ�����Сֵ
}visualpw_SysGD,*LPvisualpw_SysGD;
//ϵͳ�澯
typedef struct visualpw_SysAlarm
{
	WORD  Alarm;						//�澯״̬0,1
	WORD  num;							//�����澯���豸����
	char  picname[32];					//�Ƴ���������
	WORD  picno;						//�Ƴ��������
}visualpw_SysAlarm,*LPvisualpw_SysAlarm;
//״̬����
typedef struct visualpw_Status
{
	int  NU;							//ң��ID
	char  Name[24];						//����
	BYTE  type;							//����
	int  StationNU;						//վ��
	char  sta;							//״̬
	BYTE  Devtype;						//�����豸����
	DWORD  DevID;						//�����豸ID
}visualpw_Status,*LPvisualpw_Status;
//�����źű�
typedef struct visualpw_Relay
{
	int  NU;							//�����ź�ID
	char  Name[24];						//�����ź���
	int  StationNU;						//վ��
	BYTE  sta;							//״̬
	CTime  tm;							//����ʱ��
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  type;							//��������1��2��Ҫ��һ�㱣��
	BYTE  ack;							//ȷ�ϱ�־
	BYTE  devtype;						//�豸����
	DWORD  devid;						//�����豸ID
	DWORD  TankID;						//������ID
}visualpw_Relay,*LPvisualpw_Relay;
//������(��
typedef struct visualpw_Tank
{
	DWORD  ID;							//��ʶ
	char  Name[24];						//����
	BYTE  AlmLevel;						//�澯����0��1��2��3
	BYTE  ack;							//ȷ�ϱ�־
}visualpw_Tank,*LPvisualpw_Tank;
//����豸
typedef struct visualpw_Bay
{
	DWORD  ID;							//���ID
	char  Name[24];						//�������
	BYTE  Alarm;						//����澯
	BYTE  ack;							//ȷ�ϱ�־
}visualpw_Bay,*LPvisualpw_Bay;
//Relation104
typedef struct visualpw_Relation104
{
	DWORD  NU;							//���
	DWORD  MNU;							//�ڴ���NU
	int  StationNU;						//վ��
	char  Values[12];					//��
	float  MODULUS;						//��Ŷ�Ӧ��ϵ��
	BYTE  DevType;						//�豸����
	DWORD  ID;							//�Է�ID��
	char  Name[100];					//����
}visualpw_Relation104,*LPvisualpw_Relation104;
//Relationyx104
typedef struct visualpw_Relationyx104
{
	DWORD  NU;							//���
	DWORD  MNU;							//�ڴ���NU
	int  StationNU;						//վ��
	char  Values[12];					//��
	float  MODULUS;						//��Ŷ�Ӧ��ϵ��
	BYTE  DevType;						//�豸����
	DWORD  ID;							//�Է�ID��
	char  Name[100];					//����
}visualpw_Relationyx104,*LPvisualpw_Relationyx104;
//=================������===============
//�û���
typedef struct common_user
{
	WORD  id;							//�û�ID
	char  Name[15];						//�û���
	char  password[16];					//�û�����
	char  type;							//�û�����
	DWORD  limit;						//Ȩ��(32λ)
	char  exp[28];						//ע��
}common_user,*LPcommon_user;
//��ѹ��ɫ
typedef struct common_Color
{
	char  VLName[16];					//��ѹ����
	BYTE  R;							//��ɫ����
	BYTE  G;							//��ɫ����
	BYTE  B;							//��ɫ����
}common_Color,*LPcommon_Color;
//�����Ƚ����
typedef struct common_Sen
{
	DWORD  NU;							//�豸���ID
	BYTE  type;							//�豸����
	float  senval;						//������ֵ
}common_Sen,*LPcommon_Sen;
//ʵʱ����Ԥ��8��
typedef struct common_FLoad
{
	float  FValue;						//����Ԥ��ֵ
	float  RValue;						//����ʵ��ֵ
	BYTE  hour;							//����Сʱ��
}common_FLoad,*LPcommon_FLoad;
//���з�ʽ
typedef struct common_RunType
{
	DWORD  Nu;							//���
	char  Name[24];						//��
	BYTE  State;						//״̬
}common_RunType,*LPcommon_RunType;
//ĸ�߹���ֵ
typedef struct common_BusV
{
	DWORD  Nu;							//���
	char  Name[24];						//�豸��
	float  HGD_MaxV;					//�������ѹ����
	float  HGD_MinV;					//�������ѹ����
	float  HGW_MaxV;					//������ϵ�ѹ����
	float  HGW_MinV;					//������ϵ�ѹ����
	float  HSD_MaxV;					//��С�����ѹ����
	float  HSD_MinV;					//��С�����ѹ����
	float  HSW_MaxV;					//��С���ϵ�ѹ����
	float  HSW_MinV;					//��С���ϵ�ѹ����
	float  LGD_MaxV;					//�ݴ�����ѹ����
	float  LGD_MinV;					//�ݴ�����ѹ����
	float  LGW_MaxV;					//�ݴ����ϵ�ѹ����
	float  LGW_MinV;					//�ݴ����ϵ�ѹ����
	float  LSD_MaxV;					//��С�����ѹ����
	float  LSD_MinV;					//��С�����ѹ����
	float  LSW_MaxV;					//��С���ϵ�ѹ����
	float  LSW_MinV;					//��С���ϵ�ѹ����
	float  ESD_MaxV;					//��������ѹ����
	float  ESD_MinV;					//��������ѹ����
	float  ESW_MaxV;					//�������ϵ�ѹ����
	float  ESW_MinV;					//�������ϵ�ѹ����
}common_BusV,*LPcommon_BusV;
//ת����ϵ��
typedef struct common_Relation
{
	int  SNu;							//���
	int  VNu;							//���ӻ��е��豸ID
	char  SName[24];					//Scada�е�����
	char  EName[24];					//EMS�е�����
	char  DName[24];					//DMIS�е�����
	BYTE  DevType;						//�豸����
	char  VType;						//���
	WORD  GrpNu;						//�豸�����
	DWORD  Station;						//����վ��
}common_Relation,*LPcommon_Relation;
//Ԥ������泱��
typedef struct common_PreDefSF
{
	DWORD  ID;							//����ID
	char  Name[45];						//��������
	float  curval;						//��ǰ����ֵ
	float  Vmax;						//��������ֵ
	float  Par;							//���渺���ʸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
	BYTE  Nline;						//��·��
	char  DevID[256];					//����ID,���26����·
	BYTE  alarm;						//Ԥ��
	BYTE  ack;							//�澯ȷ��
	float  Pcur;						//�����й�
	float  Qcur;						//�����޹�
}common_PreDefSF,*LPcommon_PreDefSF;
//=================studypw===============
//PT��
typedef struct studypw_PT
{
	DWORD  NU;							//PT���
	char  Name[24];						//PT����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}studypw_PT,*LPstudypw_PT;
//�����
typedef struct studypw_Gen
{
	DWORD  NU;							//�������
	char  Name[24];						//�������
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  MaxP;						//�й�����
	float  Par;							//�й������ٷֱȸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  Pchk;						//���޹���
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//Ԥ��
	BYTE  ack;							//�澯ȷ��
	float  P;							//�й�����
	float  Q;							//�޹�����
	float  angle;						//�Ƕ�
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}studypw_Gen,*LPstudypw_Gen;
//���ص�բ
typedef struct studypw_Switch
{
	DWORD  NU;							//���ر��
	char  Name[24];						//��������
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	CTime  TurnDTime;					//����ʱ��
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  alarm;						//�ܸ澯
	BYTE  AlmRelay;						//���������澯0��1��2
	BYTE  SwtChange;					//���ر�λ
	BYTE  ack;							//ȷ��
	BYTE  rp;							//����״̬
	BYTE  BayID;						//���ID
}studypw_Switch,*LPstudypw_Switch;
//����
typedef struct studypw_Load
{
	DWORD  NU;							//���ɱ��
	char  Name[24];						//��������
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  MaxP;						//�й�����
	float  MinP;						//�й�����
	float  P;							//�й�����
	float  Q;							//�޹�����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
}studypw_Load,*LPstudypw_Load;
//����
typedef struct studypw_Shunt
{
	DWORD  NU;							//�����豸���
	char  Name[24];						//�����豸����
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  Vl;							//��ѹ�ȼ�
	float  Q;							//Ͷ���޹�
	float  Qmax;						//����޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}studypw_Shunt,*LPstudypw_Shunt;
//�翹
typedef struct studypw_Sreact
{
	DWORD  NU;							//�翹�����
	char  Name[24];						//�翹����
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  Vl;							//��ѹ�ȼ�
	float  zst;							//����
	float  Zx;							//Ͷ��翹
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}studypw_Sreact,*LPstudypw_Sreact;
//2�����ѹ��
typedef struct studypw_Tfm1
{
	DWORD  NU;							//2�Ʊ���
	char  Name[24];						//2�Ʊ���
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  Vl;							//��ѹ�ȼ�
	WORD  Tallow;						//��������ʱ��(��)
	WORD  Tover;						//����������ʱ��(��)
	float  tap;							//��ѹ���ֽ�ͷ
	float  Pmax;						//��ѹ������й�(����)
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  P;							//��ѹ���й�
	float  Q;							//��ѹ���޹�
	float  I;							//��ѹ�����
	float  P2;							//��ѹ���й�
	float  Q2;							//��ѹ���޹�
	float  I2;							//��ѹ�����
	float  Tcur;						//��ǰ�¶�
	float  Tmax;						//����¶�
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//�ܸ澯
	BYTE  ack;							//�澯ȷ��
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
	float  T1;							//�¶�1
	float  T2;							//�¶�2
	float  T3;							//�¶�3
	float  T4;							//�¶�4
	BYTE  AlmTfast;						//�¶�ͻ��澯
	BYTE  AlmCur;						//�¶����߸澯
	BYTE  AlmOver;						//�¶�Խ�޸澯
	BYTE  AlmLoad;						//����Խ�޸澯
	BYTE  AlmRelay;						//�����źŸ澯
}studypw_Tfm1,*LPstudypw_Tfm1;
//3�����ѹ��
typedef struct studypw_Tfm2
{
	DWORD  NU;							//3�Ʊ���
	char  Name[24];						//3�Ʊ���
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  Vl;							//��ѹ�ȼ�
	WORD  Tallow;						//��������ʱ��(��)
	WORD  Tover;						//����������ʱ��(��)
	float  TapH;						//�߶˷ֽ�ͷλ��
	float  TapM;						//�ж˷ֽ�ͷλ��
	float  TapL;						//�Ͷ˷ֽ�ͷλ��
	float  Pmax;						//��ѹ������й�(����)
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  P;							//��ѹ���й�
	float  Q;							//��ѹ���޹�
	float  I;							//��ѹ�����
	float  P2;							//��ѹ���й�
	float  Q2;							//��ѹ���޹�
	float  I2;							//��ѹ�����
	float  P3;							//��ѹ���й�
	float  Q3;							//��ѹ���޹�
	float  I3;							//��ѹ�����
	float  Tcur;						//��ǰ�¶�
	float  Tmax;						//����¶�
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//�ܸ澯
	BYTE  ack;							//�澯ȷ��
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  Tnum;							//�ɼ����¶ȸ���
	float  T1;							//�¶�1
	float  T2;							//�¶�2
	float  T3;							//�¶�3
	float  T4;							//�¶�4
	float  T5;							//�¶�5
	float  T6;							//�¶�6
	BYTE  rp;							//����״̬
	BYTE  AlmTfast;						//�¶�ͻ��澯
	BYTE  AlmCur;						//�¶����߸澯
	BYTE  AlmOver;						//�¶�Խ�޸澯
	BYTE  AlmLoad;						//����Խ�޸澯
	BYTE  AlmRelay;						//�����źŸ澯
}studypw_Tfm2,*LPstudypw_Tfm2;
//��̬�޹�����
typedef struct studypw_SVC
{
	DWORD  NU;							//SVC���
	char  Name[24];						//SVC����
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  Qmax;						//����޹����
	float  Qmin;						//��С�޹����
	float  Q;							//�޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}studypw_SVC,*LPstudypw_SVC;
//ĸ��
typedef struct studypw_Bus
{
	DWORD  NU;							//ĸ�߱��
	char  Name[24];						//ĸ������
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	float  MaxV;						//��ѹ����
	float  MinV;						//��ѹ����
	float  HiLimit;						//��ѹ�澯����
	float  LoLimit;						//��ѹ�澯����
	float  Vl;							//��ѹ�ȼ�
	float  V;							//�ڵ��ѹ(pu)
	float  Vb;							//��ѹʵ��ֵ
	float  DayMax;						//�����ֵ
	float  DayMin;						//����Сֵ
	float  deg;							//���
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  AlmOver;						//Խ������0��1��2
	BYTE  AlmRelay;						//�����źŸ澯
	BYTE  alarm;						//�ܸ澯
	BYTE  ack;							//�澯ȷ��
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
}studypw_Bus,*LPstudypw_Bus;
//������
typedef struct studypw_Line
{
	DWORD  NU;							//�����߱��
	char  Name[24];						//����������
	DWORD  StationNU;					//����վ
	int  Zonef;							//��ʼ�������
	int  Zonet;							//�յ��������
	float  Vl;							//��ѹ�ȼ�
	float  Imax;						//�������ֵ
	float  MaxP;						//�й�����
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  Pf;							//ʼ���й�
	float  Qf;							//ʼ���޹�
	float  Pt;							//ĩ���й�
	float  Qt;							//ĩ���޹�
	float  I;							//����ֵ
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//�ܸ澯
	BYTE  ack;							//�澯ȷ��
	BYTE  AlmRelay;						//�����źŸ澯
	BYTE  AlmLoad;						//����Խ�޸澯
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
	BYTE  BayID;						//���ID
}studypw_Line,*LPstudypw_Line;
//ֱ����
typedef struct studypw_DCLine
{
	DWORD  NU;							//ֱ���߱��
	char  Name[24];						//ֱ��������
	DWORD  StationNU;					//����վ
	int  Zonef;							//��ʼ�������
	int  Zonet;							//�յ��������
	float  Imax;						//�������ֵ
	float  Maxp;						//�й�����
	float  Par;							//����߸����ʸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  Pf;							//ʼ���й�
	float  Qf;							//ʼ���޹�
	float  Pt;							//ĩ���й�
	float  Qt;							//ĩ���޹�
	float  I;							//����ֵ
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//Ԥ��
	BYTE  ack;							//�澯ȷ��
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  rp;							//����״̬
	BYTE  BayID;						//���ID
}studypw_DCLine,*LPstudypw_DCLine;
//�������������
typedef struct studypw_CVT
{
	DWORD  NU;							//�豸���
	char  Name[24];						//�豸����
	DWORD  StationNU;					//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
}studypw_CVT,*LPstudypw_CVT;
//�ӵ�
typedef struct studypw_GND
{
	DWORD  NU;							//�ӵر��
	char  Name[24];						//�ӵ�����
	DWORD  StationNU;					//����վ��
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
}studypw_GND,*LPstudypw_GND;
//����
typedef struct studypw_Zone
{
	DWORD  NU;							//������
	char  Name[24];						//��������
	float  total_los;					//�й����
	float  total_gen;					//�й�����
	float  demand;						//�й�����
	float  cost;						//��λ��������
	float  curlr;						//��ǰ������
	float  lastlr;						//�ϴθ�����
	float  nextlr;						//δ��������
}studypw_Zone,*LPstudypw_Zone;
//վ
typedef struct studypw_Station
{
	DWORD  NU;							//վ��
	char  Name[24];						//վ��
	DWORD  zoneNU;						//��������
	BYTE  Alarm;						//վ�澯
	BYTE  ack;							//�澯ȷ��
}studypw_Station,*LPstudypw_Station;
//ϵͳָ��
typedef struct studypw_SysGD
{
	DWORD  ID;							//ָ���ʶID
	char  Name[24];						//ָ������
	float  zb;							//��ǰָ��
	float  Vmax;						//�������ֵ
	float  Vmin;						//������Сֵ
	float  Vmax1;						//��һ�����ֵ
	float  Vmin1;						//��һ����Сֵ
	float  Vmax2;						//�ڶ������ֵ
	float  Vmin2;						//�ڶ�����Сֵ
}studypw_SysGD,*LPstudypw_SysGD;
//ϵͳ�澯
typedef struct studypw_SysAlarm
{
	WORD  Alarm;						//�澯״̬0,1
	WORD  num;							//�����澯���豸����
	char  picname[32];					//�Ƴ���������
	WORD  picno;						//�Ƴ��������
}studypw_SysAlarm,*LPstudypw_SysAlarm;
//״̬����
typedef struct studypw_Status
{
	int  NU;							//ң��ID
	char  Name[24];						//����
	BYTE  type;							//����
	int  StationNU;						//վ��
	char  sta;							//״̬
	BYTE  Devtype;						//�����豸����
	DWORD  DevID;						//�����豸ID
}studypw_Status,*LPstudypw_Status;
//�����źű�
typedef struct studypw_Relay
{
	int  NU;							//�����ź�ID
	char  Name[24];						//�����ź���
	int  StationNU;						//վ��
	BYTE  sta;							//״̬
	CTime  tm;							//����ʱ��
	CTime  updatetm;					//���ݸ���ʱ��
	BYTE  olddata;						//������
	BYTE  type;							//��������1��2��Ҫ��һ�㱣��
	BYTE  ack;							//ȷ�ϱ�־
	BYTE  devtype;						//�豸����
	DWORD  devid;						//�����豸ID
	DWORD  TankID;						//������ID
}studypw_Relay,*LPstudypw_Relay;
//������(��
typedef struct studypw_Tank
{
	DWORD  ID;							//��ʶ
	char  Name[24];						//����
	BYTE  AlmLevel;						//�澯����0��1��2��3
	BYTE  ack;							//ȷ�ϱ�־
}studypw_Tank,*LPstudypw_Tank;
//����豸
typedef struct studypw_Bay
{
	DWORD  ID;							//���ID
	char  Name[24];						//�������
	BYTE  Alarm;						//����澯
	BYTE  ack;							//ȷ�ϱ�־
}studypw_Bay,*LPstudypw_Bay;
#endif