#if !defined(_DB_STRUCT_H_)
#define _DB_STRUCT_H_
/************************************************/
//��ͷ�ļ��ɡ����ݿ����������Զ�����
//2010-11-25
//�Ǻ��߿Ƽ���ҵ�ɷ����޹�˾
/************************************************/
//����Ԥ����ֵ
//=================���ӻ�����ϵͳ��===============
//PT��
typedef struct visualpw_PT
{
	DWORD  NU;							//PT���
	char  Name[32];						//PT����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	short  status;						//�ۺ�״̬
}visualpw_PT,*LPvisualpw_PT;
//�����
typedef struct visualpw_Gen
{
	DWORD  NU;							//�������
	char  Name[32];						//�������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  MaxP;						//�й�����
	float  Par;							//�й������ٷֱȸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  Pchk;						//���޹���
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	float  P;							//�й�����
	float  Q;							//�޹�����
	float  V;							//���˵�ѹ
	float  angle;						//�Ƕ�
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	float  Qmax;						//�������޹�
	float  Qmaxi;						//�������޹�
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	BYTE  Type;							//����
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}visualpw_Gen,*LPvisualpw_Gen;
//���ص�բ
typedef struct visualpw_Switch
{
	DWORD  NU;							//���ر��
	char  Name[32];						//��������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node1;						//�ڵ�1
	DWORD  Node2;						//�ڵ�2
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}visualpw_Switch,*LPvisualpw_Switch;
//����
typedef struct visualpw_Load
{
	DWORD  NU;							//���ɱ��
	char  Name[32];						//��������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  MaxP;						//�й�����
	float  MinP;						//�й�����
	float  P;							//�й�����
	float  Q;							//�޹�����
	float  I;							//����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}visualpw_Load,*LPvisualpw_Load;
//����
typedef struct visualpw_Shunt
{
	DWORD  NU;							//�����豸���
	char  Name[32];						//�����豸����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Q;							//Ͷ���޹�
	float  I;							//����
	float  Qmax;						//����޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	float  Qchk;						//��������
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}visualpw_Shunt,*LPvisualpw_Shunt;
//�翹
typedef struct visualpw_Sreact
{
	DWORD  NU;							//�翹�����
	char  Name[32];						//�翹����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Zx;							//Ͷ��翹
	float  I;							//����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node1;						//�ڵ�1
	DWORD  Node2;						//�ڵ�2
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}visualpw_Sreact,*LPvisualpw_Sreact;
//2�����ѹ��
typedef struct visualpw_Tfm1
{
	DWORD  NU;							//2�Ʊ���
	char  Name[32];						//2�Ʊ���
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	WORD  Tallow;						//��������ʱ��(��)
	WORD  Tover;						//����������ʱ��(��)
	float  tap;							//��ѹ���ֽ�ͷ
	float  Pmax;						//��ѹ������й�(����)
	float  Par;							//��ѹ�������ʾ�����
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
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  NodeH;						//��ѹ�ڵ�
	DWORD  NodeL;						//��ѹ�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}visualpw_Tfm1,*LPvisualpw_Tfm1;
//3�����ѹ��
typedef struct visualpw_Tfm2
{
	DWORD  NU;							//3�Ʊ���
	char  Name[32];						//3�Ʊ���
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	WORD  Tallow;						//��������ʱ��(��)
	WORD  Tover;						//����������ʱ��(��)
	float  TapH;						//�߶˷ֽ�ͷλ��
	float  TapM;						//�ж˷ֽ�ͷλ��
	float  TapL;						//�Ͷ˷ֽ�ͷλ��
	float  Pmax;						//��ѹ������й�(����)
	float  Par;							//��ѹ�������ʾ�����
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
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  NodeH;						//��ѹ�ڵ�
	DWORD  NodeM;						//��ѹ�ڵ�
	DWORD  NodeL;						//��ѹ�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}visualpw_Tfm2,*LPvisualpw_Tfm2;
//��̬�޹�����
typedef struct visualpw_SVC
{
	DWORD  NU;							//SVC���
	char  Name[32];						//SVC����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Qmax;						//����޹����
	float  Qmin;						//��С�޹����
	float  Q;							//�޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	short  status;						//�ۺ�״̬
}visualpw_SVC,*LPvisualpw_SVC;
//ĸ��
typedef struct visualpw_Bus
{
	DWORD  NU;							//ĸ�߱��
	char  Name[32];						//ĸ������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  MaxV;						//��ѹ����
	float  MinV;						//��ѹ����
	float  HiLimit;						//��ѹ�澯����
	float  LoLimit;						//��ѹ�澯����
	float  PreVhi;						//Ԥ��ʹ�õ�����
	float  PreVlo;						//Ԥ��ʹ�õ�����
	float  Vl;							//��ѹ�ȼ�
	float  V;							//�ڵ��ѹ(pu)
	float  Vb;							//��ѹʵ��ֵ
	float  DayMax;						//�����ֵ
	float  DayMin;						//����Сֵ
	float  deg;							//���
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  AlarmHiLo;					//Խ������0��1��2
	BYTE  AlarmBand;					//Խ5%��0��1
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	DWORD  cNode;						//�ϲ��ڵ�
	short  status;						//�ۺ�״̬
}visualpw_Bus,*LPvisualpw_Bus;
//������
typedef struct visualpw_Line
{
	DWORD  NU;							//�����߱��
	char  Name[32];						//����������
	DWORD  Stationf;					//�׶�վ
	DWORD  Stationt;					//ĩ��վ
	int  Zonef;							//��ʼ�������
	int  Zonet;							//�յ��������
	float  Imax;						//�������ֵ
	float  MaxP;						//�й�����
	float  Par;							//����߸����ʸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  VL;							//��ѹ�ȼ�
	float  Pf;							//ʼ���й�
	float  Qf;							//ʼ���޹�
	float  Pt;							//ĩ���й�
	float  Qt;							//ĩ���޹�
	float  I;							//����ֵ
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  NodeF;						//�׽ڵ�
	DWORD  NodeT;						//ĩ�ڵ�
	short  status;						//�ۺ�״̬
}visualpw_Line,*LPvisualpw_Line;
//ֱ����
typedef struct visualpw_DCLine
{
	DWORD  NU;							//ֱ���߱��
	char  Name[32];						//ֱ��������
	DWORD  Stationf;					//�׶�վ
	DWORD  Stationt;					//ĩ��վ
	int  Zonef;							//��ʼ�������
	int  Zonet;							//�յ��������
	float  Imax;						//�������ֵ
	float  Maxp;						//�й�����
	float  Par;							//����߸����ʸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  VL;							//��ѹ�ȼ�
	float  Pf;							//ʼ���й�
	float  Qf;							//ʼ���޹�
	float  Pt;							//ĩ���й�
	float  Qt;							//ĩ���޹�
	float  I;							//����ֵ
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  NodeF;						//�׽ڵ�
	DWORD  NodeT;						//ĩ�ڵ�
	short  status;						//�ۺ�״̬
}visualpw_DCLine,*LPvisualpw_DCLine;
//�������������
typedef struct visualpw_CVT
{
	DWORD  NU;							//�豸���
	char  Name[32];						//�豸����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	short  status;						//�ۺ�״̬
}visualpw_CVT,*LPvisualpw_CVT;
//�ӵ�
typedef struct visualpw_GND
{
	DWORD  NU;							//�ӵر��
	char  Name[32];						//�ӵ�����
	DWORD  Station;						//����վ��
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
}visualpw_GND,*LPvisualpw_GND;
//����
typedef struct visualpw_Zone
{
	DWORD  NU;							//������
	char  Name[32];						//��������
	float  Pgen;						//�����й�
	float  Qgen;						//�޹�����
	float  GenMax;						//���������
	float  Pld;							//�й�����
	float  Qld;							//�޹�����
	float  LdMax;						//�������ֵ
	float  ZoneLP;						//�����й�����
	float  ZoneLQ;						//�����޹�����
	short  Sub50;						//500kV���վ��
	short  Sub22;						//220kV���վ��
	float  TransMW;						//���վ����
}visualpw_Zone,*LPvisualpw_Zone;
//վ
typedef struct visualpw_Station
{
	DWORD  NU;							//վ��
	char  Name[32];						//վ��
	DWORD  zoneNU;						//��������
	float  VL;							//��ѹ�ȼ�
	int  Type;							//��վ����
	char  ID[24];						//���վ��ʶ
	short  status;						//�ۺ�״̬
}visualpw_Station,*LPvisualpw_Station;
//���ڵ��ѹ����
typedef struct visualpw_VotOutage
{
	int  NU;							//�豸���
	char  type;							//�豸����
	float  Defl;						//����ָ��
	BYTE  Group;						//��������
}visualpw_VotOutage,*LPvisualpw_VotOutage;
//��֧·����
typedef struct visualpw_LineOutage
{
	int  NU;							//�豸���
	char  type;							//����
	float  Defl;						//����ָ��
	BYTE  Group;						//��������
}visualpw_LineOutage,*LPvisualpw_LineOutage;
//�ڵ��ѹ��֧·�ϳ�
typedef struct visualpw_AllOutage
{
	int  NU;							//�豸���
	char  type;							//����
	float  Defl;						//����ָ��
	BYTE  Group;						//��������
}visualpw_AllOutage,*LPvisualpw_AllOutage;
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
//ϵͳ�澯
typedef struct visualpw_Ace
{
	DWORD  ID;							//��ʶID
	float  CurVal;						//��ǰֵ
	CTime  datatime;					//����ʱ��
	BYTE  alarm;						//�澯
	BYTE  ack;							//ȷ��
}visualpw_Ace,*LPvisualpw_Ace;
//��·����������
typedef struct visualpw_ShortCC
{
	DWORD  SwtNU;						//���ر��ID
	BYTE  GType;						//��������
	DWORD  LineNU;						//��·���
	BYTE  LineType;						//��·����
	CTime  DTime;						//����ʱ��
	float  TrPos;						//����λ��
	float  Imax;						//������
	float  Isc;							//��·����
	float  Usc;							//������ѹ
}visualpw_ShortCC,*LPvisualpw_ShortCC;
//�����Ǳ���ʾ
typedef struct visualpw_Meter
{
	int  ID;							//Ψһ��ID��
	char  Name[32];						//����
	float  Value;						//��ǰֵ
	float  Vmax;						//���ֵ
	float  Vmin;						//��Сֵ
	float  Vmax1;						//��һ�����ֵ
	float  Vmin1;						//��һ����Сֵ
	float  Vmax2;						//�ڶ������ֵ
	float  Vmin2;						//�ڶ�����Сֵ
	BYTE  AreaNo;						//�������
	BYTE  FieldNo;						//�ֶ����
}visualpw_Meter,*LPvisualpw_Meter;
//������
typedef struct visualpw_Area
{
	DWORD  NU;							//������
	char  Name[32];						//��������
	DWORD  AColor;						//������ɫ
	float  Security;					//��ȫָ��
	float  LDFactor;					//���ر�
	float  LDFactorT;					//�������ر�
	float  LDFactorL;					//��·���ر�
	float  LDFactorG;					//�������ر�
	float  LDFactorS;					//�޹����ر�
	float  Energy;						//����ƽ��
	float  VolRate;						//��ѹ�ϸ���
	float  LDRate;						//����ˮƽ
	float  OverLoading;					//������
	float  OverLoadingT;				//����������
	float  OverLoadingL;				//��·������
}visualpw_Area,*LPvisualpw_Area;
//��ѹ�޹����Ʊ�
typedef struct visualpw_AVC
{
	DWORD  NU;							//��ѹ����
	char  Name[64];						//�豸����
	float  fVol;						//����ѹֵ
	float  fVar;						//����޹�ֵ
	BYTE  POS;							//����ͼλ��
	BYTE  byTransType;					//��ѹ������
	char  Property[256];				//����
	char  PreValues[96];				//����ı仯ֵ
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
}visualpw_AVC,*LPvisualpw_AVC;
//�����PQV������
typedef struct visualpw_PQV
{
	DWORD  GenNU;						//��������
	char  Name[64];						//�豸����
	DWORD  BusNU;						//����ĸ�ߺ�
	BYTE  Gentype;						//�����͹������
	float  FacS;						//���������
	float  FacU;						//�������ѹ
	float  FacF;						//�����Ƶ��
	float  xd;							//D��翹
	float  xq;							//Q��翹
	float  imax;						//������ŵ���
	float  eqmax;						//����ͨ
	char  Property[256];				//����
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
}visualpw_PQV,*LPvisualpw_PQV;
//����ͳ�Ʊ�
typedef struct visualpw_ldstate
{
	DWORD  NU;							//���
	BYTE  type;							//����
	float  LDmax;						//�������
	CTime  LDmaxT;						//����س���ʱ��
	DWORD  LDoverT;						//�ո��ع���ʱ��
}visualpw_ldstate,*LPvisualpw_ldstate;
//��ѹ������������
typedef struct visualpw_Hvcondata
{
	DWORD  ID;							//IDֵ
	char  Name1[40];					//����
	char  Name2[40];					//����
	float  Vlimit;						//��ֵ
	float  Curval;						//��ǰֵ
	char  sta;							//����״̬
	CTime  datetm;						//����ʱ��
	char  Alarm;						//�澯
	char  Ack;							//ȷ��
}visualpw_Hvcondata,*LPvisualpw_Hvcondata;
//��ѹ����̬����
typedef struct visualpw_DynMonitor
{
	DWORD  NU;							//���
	char  Name[32];						//����
	BYTE  Winding;						//��������
	BYTE  Mode;							//����ģʽ
	float  Normal1;						//������ֵ1
	int  NorTime1;						//������ֵ1ʱ��
	float  Normal2;						//������ֵ2
	int  NorTime2;						//������ֵ2ʱ��
	float  Normal3;						//������ֵ3
	int  NorTime3;						//������ֵ3ʱ��
	float  Contingency1;				//�¹���ֵ1
	int  CtgTime1;						//�¹���ֵ1ʱ��
	float  Contingency2;				//�¹���ֵ2
	int  CtgTime2;						//�¹���ֵ2ʱ��
	float  Contingency3;				//�¹���ֵ3
	int  CtgTime3;						//�¹���ֵ3ʱ��
	char  Buffer[240];					//��������
}visualpw_DynMonitor,*LPvisualpw_DynMonitor;
//�¹�Ӱ��
typedef struct visualpw_CtgEffect
{
	DWORD  CtgNU;						//�¹��豸��
	char  CtgName[32];					//�¹��豸��
	int  CtgType;						//�¹��豸����
	float  fSecurity;					//����ָ��
	DWORD  EftNU;						//��̬�豸��
	char  EftName[32];					//��̬�豸��
	int  EftType;						//��̬�豸����
	float  EftVal;						//��̬�̶�
}visualpw_CtgEffect,*LPvisualpw_CtgEffect;
//ȫ��������
typedef struct visualpw_Grid
{
	float  GenMax;						//ȫ������������
	float  GenP;						//ȫ�������й�
	float  GenQ;						//ȫ�������޹�
	float  StopP;						//ȫ��ͣ��������
	float  UpRes;						//ȫ������ת����
	float  DownRes;						//ȫ������ת����
	float  LoadMax;						//ȫ������ܸ���
	float  LoadP;						//ȫ���õ縺��
}visualpw_Grid,*LPvisualpw_Grid;
//��ѹ������
typedef struct visualpw_Winding
{
	DWORD  NU;							//������
	char  ID[24];						//�����ʶ
	char  TID[24];						//��ѹ����ʶ
	float  ratedKV;						//���ѹ
	float  ratedMVA;					//�����
	float  fShortLoss;					//��·���
	float  fShortVol;					//��·��ѹ
	float  fNoLoadLoss;					//�������
	float  fR;							//����
	float  fX;							//�翹
	float  fB;							//����
	float  fR0;							//�����
	float  fX0;							//��翹
	BYTE  Type;							//��������
	BYTE  Tmax;							//���λ
	BYTE  Tmin;							//��С��λ
	BYTE  Tnor;							//������λ
	float  step;						//��λ����
}visualpw_Winding,*LPvisualpw_Winding;
//���߱�
typedef struct visualpw_Conductor
{
	DWORD  NU;							//���
	BYTE  Type;							//����
	char  LID[24];						//��·��ʶ
	float  fR;							//����
	float  fX;							//�翹
	float  fB;							//����
	float  fG;							//�絼
	float  fR0;							//�������
	float  fX0;							//����翹
	float  fB0;							//�������
	float  fG0;							//����絼
}visualpw_Conductor,*LPvisualpw_Conductor;
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
	int  NU;							//���
	int  VNu;							//���ӻ��е��豸ID
	char  VName[32];					//���ӻ����豸����
	BYTE  DevType;						//�豸����
	BYTE  MeasType;						//��������
	char  MeasID[32];					//�����ʶ
	BYTE  MeasPos;						//����λ��
	DWORD  Station;						//����վ��
	float  SectVal;						//��ʼ����ֵ
	float  SeVal;						//״̬����ֵ
	float  EmVal;						//�������ֵ
	BYTE  quality;						//������־
	float  SndVal;						//����ֵ
	float  wStep;						//Ȩ�ز���
}common_Relation,*LPcommon_Relation;
//Ԥ������
typedef struct common_PreLimit
{
	WORD  ID;							//ID��
	char  Name[24];						//����
	float  Value;						//����ֵ
}common_PreLimit,*LPcommon_PreLimit;
//���⿪�ع�����ϵ
typedef struct common_VSwitch
{
	DWORD  SwtNU;						//����ID
	char  Name[32];						//��������
	DWORD  VSwtNU;						//�������⿪��NU
	DWORD  LineNU;						//������·
}common_VSwitch,*LPcommon_VSwitch;
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
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	float  Pcur;						//�����й�
	float  Qcur;						//�����޹�
	char  msg[45];						//��ʾ�ı�
}common_PreDefSF,*LPcommon_PreDefSF;
//�����Ƚ����
typedef struct common_Sen
{
	DWORD  NU;							//�豸���ID
	BYTE  type;							//�豸����
	float  senval;						//������ֵ
}common_Sen,*LPcommon_Sen;
//Ӧ�ò���
typedef struct common_AppParam
{
	DWORD  NU;							//���
	char  Name[32];						//������
	float  Param;						//����ֵ
}common_AppParam,*LPcommon_AppParam;
//�Ӷ����
typedef struct common_SubObject
{
	DWORD  NU;							//���
	char  Name[32];						//����
	char  ID[32];						//�����ʶ
	BYTE  Type;							//��������
	DWORD  Station;						//��վ
	DWORD  PNU;							//���豸��
	BYTE  PType;						//���豸����
}common_SubObject,*LPcommon_SubObject;
//���豸����
typedef struct common_UnEquMeas
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  max;							//���ֵ
	float  min;							//��Сֵ
	float  val;							//ֵ
	BYTE  type;							//��������
	char  ID[32];						//��ʶ
	char  PID[32];						//����ʶ
}common_UnEquMeas,*LPcommon_UnEquMeas;
//=================��������===============
//�����
typedef struct emluator_mGen
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  VL;							//��ѹ�ȼ�
	float  rateP;						//�����
	float  rateV;						//���ѹ
	float  IX;							//�ڲ��翹
	DWORD  node;						//�ڵ�
	float  P;							//�й�
	float  Q;							//�޹�
	float  I;							//����
	float  V;							//���˵�ѹ
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
}emluator_mGen,*LPemluator_mGen;
//ĸ��
typedef struct emluator_mBus
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  VL;							//��ѹ�ȼ�
	DWORD  node;						//�ڵ�
	float  V;							//��ѹ
	float  deg;							//���
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
}emluator_mBus,*LPemluator_mBus;
//��ѹ��
typedef struct emluator_mTfm
{
	DWORD  NU;							//���
	char  Name[32];						//����
	DWORD  MU;							//������
	float  rateP;						//�����
	float  VLI;							//I��ѹ�ȼ�
	float  VLJ;							//J��ѹ�ȼ�
	DWORD  nodeI;						//�ڵ�I
	DWORD  nodeJ;						//�ڵ�J
	float  R;							//����
	float  X;							//�翹
	float  B;							//����
	float  R0;							//�����
	float  X0;							//��翹
	float  T;							//��ǰ���
	float  TMX;							//�����
	float  TMN;							//��С���
	float  step;						//����
	float  Pi;							//I���й�
	float  Qi;							//I���޹�
	float  Pj;							//J���й�
	float  Qj;							//J���޹�
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
}emluator_mTfm,*LPemluator_mTfm;
//��·
typedef struct emluator_mLine
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  VL;							//��ѹ�ȼ�
	float  rateP;						//�����
	DWORD  nodeI;						//I�ڵ�
	DWORD  nodeJ;						//J�ڵ�
	float  R;							//����
	float  X;							//�翹
	float  B;							//����
	float  R0;							//�������
	float  X0;							//����翹
	float  B0;							//�������
	float  Pi;							//I���й�
	float  Qi;							//I���޹�
	float  Pj;							//J���й�
	float  Qj;							//J���޹�
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  stationf;						//�׶˳�վ
	int  stationt;						//ĩ�˳�վ
}emluator_mLine,*LPemluator_mLine;
//����
typedef struct emluator_mLoad
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  VL;							//��ѹ�ȼ�
	DWORD  node;						//�ڵ�
	float  Pmax;						//��󸺺�
	float  P;							//�й�
	float  Q;							//�޹�
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
}emluator_mLoad,*LPemluator_mLoad;
//����
typedef struct emluator_mShunt
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  rateQ;						//�����
	float  rateV;						//���ѹ
	float  VL;							//��ѹ�ȼ�
	DWORD  node;						//�ڵ�
	float  Q;							//�޹�
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
}emluator_mShunt,*LPemluator_mShunt;
//����
typedef struct emluator_mSerial
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  rateQ;						//�����
	float  rateV;						//���ѹ
	float  VL;							//��ѹ�ȼ�
	float  Zk;							//�迹
	DWORD  nodeI;						//�ڵ�I
	DWORD  nodeJ;						//�ڵ�J
	float  Q;							//�޹�
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
}emluator_mSerial,*LPemluator_mSerial;
//ֱ����
typedef struct emluator_mDLine
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  rateP;						//�����
	float  VL;							//��ѹ�ȼ�
	DWORD  nodeI;						//�ڵ�I
	DWORD  nodeJ;						//�ڵ�J
	float  R;							//����
	float  Xi;							//I�˵翹
	float  Xj;							//J�˵翹
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  stationf;						//�׶˳�վ
	int  stationt;						//ĩ�˳�վ
}emluator_mDLine,*LPemluator_mDLine;
//������ͳ����
typedef struct emluator_mStat
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  statval;						//ͳ��ֵ
}emluator_mStat,*LPemluator_mStat;
//=================������===============
//��Ŀ��
typedef struct estimator_project
{
	DWORD  NU;							//��Ŀ���
	char  Name[32];						//��Ŀ����
	char  AVC[32];						//������AVC
	BYTE  Type;							//����
	char  projectpath[128];				//��Ŀ·��
}estimator_project,*LPestimator_project;
//����
typedef struct estimator_estimate
{
	DWORD  NU;							//���
	char  description[32];				//��������
	DWORD  project;						//��������Ŀ
	char  report[32];					//��������
}estimator_estimate,*LPestimator_estimate;
//��������
typedef struct estimator_estcase
{
	DWORD  NU;							//�������
	char  Name[32];						//��������
	DWORD  project;						//��������Ŀ
	short  casetype;					//��������
	BYTE  onlie;						//���߰���
	char  descr[256];					//��������
}estimator_estcase,*LPestimator_estcase;
//���涨��
typedef struct estimator_sectdef
{
	DWORD  NU;							//������
	char  Name[32];						//��������
	char  Path[32];						//����·��
	DWORD  estcase;						//����������
	CTime  dtime;						//����ʱ��
	char  descr[256];					//��������
}estimator_sectdef,*LPestimator_sectdef;
//�����
typedef struct estimator_eGen
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  VL;							//��ѹ�ȼ�
	float  rateP;						//�����
	float  rateV;						//���ѹ
	float  IX;							//�ڲ��翹
	DWORD  node;						//�ڵ�
	float  P;							//�й�
	float  Q;							//�޹�
	float  I;							//����
	float  V;							//���˵�ѹ
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
	int  island;						//������
}estimator_eGen,*LPestimator_eGen;
//ĸ��
typedef struct estimator_eBus
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  VL;							//��ѹ�ȼ�
	float  V;							//��ѹ
	float  deg;							//���
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
	int  island;						//������
}estimator_eBus,*LPestimator_eBus;
//��ѹ��
typedef struct estimator_eTfm
{
	DWORD  NU;							//���
	char  Name[32];						//����
	DWORD  MU;							//������
	float  rateP;						//�����
	float  VLI;							//I��ѹ�ȼ�
	float  VLJ;							//J��ѹ�ȼ�
	DWORD  nodeI;						//�ڵ�I
	DWORD  nodeJ;						//�ڵ�J
	float  R;							//����
	float  X;							//�翹
	float  B;							//����
	float  R0;							//�����
	float  X0;							//��翹
	float  T;							//��ǰ���
	float  TMX;							//�����
	float  TMN;							//��С���
	float  step;						//����
	float  Pi;							//I���й�
	float  Qi;							//I���޹�
	float  Pj;							//J���й�
	float  Qj;							//J���޹�
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
	int  island;						//������
}estimator_eTfm,*LPestimator_eTfm;
//��·
typedef struct estimator_eLine
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  VL;							//��ѹ�ȼ�
	float  rateP;						//�����
	DWORD  nodeI;						//I�ڵ�
	DWORD  nodeJ;						//J�ڵ�
	float  R;							//����
	float  X;							//�翹
	float  B;							//����
	float  R0;							//�������
	float  X0;							//����翹
	float  B0;							//�������
	float  Pi;							//I���й�
	float  Qi;							//I���޹�
	float  Pj;							//J���й�
	float  Qj;							//J���޹�
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  stationf;						//�׶�վ
	int  stationt;						//ĩ��վ
	int  island;						//������
}estimator_eLine,*LPestimator_eLine;
//����
typedef struct estimator_eLoad
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  VL;							//��ѹ�ȼ�
	DWORD  node;						//�ڵ�
	float  Pmax;						//��󸺺�
	float  P;							//�й�
	float  Q;							//�޹�
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
	int  island;						//������
}estimator_eLoad,*LPestimator_eLoad;
//����
typedef struct estimator_eShunt
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  rateQ;						//�����
	float  rateV;						//���ѹ
	float  VL;							//��ѹ�ȼ�
	DWORD  node;						//�ڵ�
	float  Q;							//�޹�
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
	int  island;						//������
}estimator_eShunt,*LPestimator_eShunt;
//����
typedef struct estimator_eSerial
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  rateQ;						//�����
	float  rateV;						//���ѹ
	float  VL;							//��ѹ�ȼ�
	float  Zk;							//�迹
	DWORD  nodeI;						//�ڵ�I
	DWORD  nodeJ;						//�ڵ�J
	float  Q;							//�޹�
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
	int  island;						//������
}estimator_eSerial,*LPestimator_eSerial;
//ֱ����
typedef struct estimator_eDLine
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  rateP;						//�����
	float  VL;							//��ѹ�ȼ�
	DWORD  nodeI;						//�ڵ�I
	DWORD  nodeJ;						//�ڵ�J
	float  R;							//����
	float  Xi;							//I�˵翹
	float  Xj;							//J�˵翹
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  stationf;						//�׶˳�վ
	int  stationt;						//ĩ�˳�վ
	int  island;						//������
}estimator_eDLine,*LPestimator_eDLine;
//��������
typedef struct estimator_casemeas
{
	DWORD  NU;							//���
	DWORD  estcase;						//��������
	DWORD  casedev;						//�����豸
	DWORD  casesec;						//��������
	BYTE  mkattr;						//��������
	char  MeasID[32];					//����ID
	float  val;							//�˹�ֵ
	float  Vmx;							//���ֵ
	float  Vmn;							//��Сֵ
	BYTE  quality;						//������־
}estimator_casemeas,*LPestimator_casemeas;
//�����豸
typedef struct estimator_caseequ
{
	DWORD  NU;							//���
	DWORD  estcase;						//��������
	char  random;						//����豸
	BYTE  dtype;						//�豸����
	DWORD  dNU;							//�豸���
	short  action;						//�豸����
	short  targe;						//����Ŀ��
}estimator_caseequ,*LPestimator_caseequ;
//����ģ��
typedef struct estimator_CASETEMP
{
	DWORD  NU;							//���
	char  Name[32];						//��������
	short  casetype;					//��������
	int  estkeep;						//��������ʱ��
	char  dsite[32];					//����λ��
	short  scircle;						//���淢������
	int  target;						//����ָ��
}estimator_CASETEMP,*LPestimator_CASETEMP;
//AVC����ָ���
typedef struct estimator_avcctrl
{
	DWORD  NU;							//ʱ�����
	DWORD  dev;							//�豸���
	BYTE  dtype;						//�豸����
	BYTE  ctrl;							//����ָ��
	BYTE  project;						//��������Ŀ
	DWORD  estimate;					//��������
	DWORD  estcase;						//��������
	int  status;						//ָ��״̬
}estimator_avcctrl,*LPestimator_avcctrl;
//���������
typedef struct estimator_estresult
{
	DWORD  NU;							//���
	DWORD  project;						//��������Ŀ
	DWORD  estimate;					//��������
	DWORD  estcase;						//��������
	char  Name[32];						//��������
	DWORD  casetemp;					//����ģ��
	DWORD  secttime;					//���淢��ʱ��
	DWORD  esttime;						//����ʱ��
	BYTE  quality;						//��������
	float  ctrl;						//��������
	float  loss;						//�������
	float  voltage;						//��ѹ����
	float  action;						//����������
	float  reserve;						//�޹���������
	float  stability;					//�ȶ�������
	float  lock;						//��������
	float  load;						//��������
	float  speed;						//�ٶ�����
	char  appendix[32];					//�����ļ�
}estimator_estresult,*LPestimator_estresult;
//������
typedef struct estimator_eIsland
{
	int  iIslandNo;						//��������
	int  iNodeNum;						//�ڵ���
	int  iGenNum;						//�������
	int  iLoadNum;						//������
	short  shSeTime;					//״̬����ʱ��
	BYTE  bySeResult;					//״̬���ƽ��
	short  shOpfTime;					//�Ż�����ʱ��
	BYTE  byOpfResult;					//�Ż�������
	int  iMeasNum;						//����������
	int  iEligibleNum;					//���ƺϸ���
	char  szRefGen[48];					//ƽ���
}estimator_eIsland,*LPestimator_eIsland;
//�״�Ȩ��
typedef struct estimator_RADARWT
{
	DWORD  NU;							//���
	char  Name[32];						//����
	float  maxVal;						//���ֵ
	float  minVal;						//��Сֵ
	float  weight;						//Ȩ��
}estimator_RADARWT,*LPestimator_RADARWT;
//=================�о�̬===============
//PT��
typedef struct studypw_PT
{
	DWORD  NU;							//PT���
	char  Name[32];						//PT����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	short  status;						//�ۺ�״̬
}studypw_PT,*LPstudypw_PT;
//�����
typedef struct studypw_Gen
{
	DWORD  NU;							//�������
	char  Name[32];						//�������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  MaxP;						//�й�����
	float  Par;							//�й������ٷֱȸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  Pchk;						//���޹���
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	float  P;							//�й�����
	float  Q;							//�޹�����
	float  V;							//���˵�ѹ
	float  angle;						//�Ƕ�
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	float  Qmax;						//�������޹�
	float  Qmaxi;						//�������޹�
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	BYTE  Type;							//����
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}studypw_Gen,*LPstudypw_Gen;
//���ص�բ
typedef struct studypw_Switch
{
	DWORD  NU;							//���ر��
	char  Name[32];						//��������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node1;						//�ڵ�1
	DWORD  Node2;						//�ڵ�2
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}studypw_Switch,*LPstudypw_Switch;
//����
typedef struct studypw_Load
{
	DWORD  NU;							//���ɱ��
	char  Name[32];						//��������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  MaxP;						//�й�����
	float  MinP;						//�й�����
	float  P;							//�й�����
	float  Q;							//�޹�����
	float  I;							//����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}studypw_Load,*LPstudypw_Load;
//����
typedef struct studypw_Shunt
{
	DWORD  NU;							//�����豸���
	char  Name[32];						//�����豸����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Q;							//Ͷ���޹�
	float  I;							//����
	float  Qmax;						//����޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	float  Qchk;						//��������
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}studypw_Shunt,*LPstudypw_Shunt;
//�翹
typedef struct studypw_Sreact
{
	DWORD  NU;							//�翹�����
	char  Name[32];						//�翹����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Zx;							//Ͷ��翹
	float  I;							//����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node1;						//�ڵ�1
	DWORD  Node2;						//�ڵ�2
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}studypw_Sreact,*LPstudypw_Sreact;
//2�����ѹ��
typedef struct studypw_Tfm1
{
	DWORD  NU;							//2�Ʊ���
	char  Name[32];						//2�Ʊ���
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	WORD  Tallow;						//��������ʱ��(��)
	WORD  Tover;						//����������ʱ��(��)
	float  tap;							//��ѹ���ֽ�ͷ
	float  Pmax;						//��ѹ������й�(����)
	float  Par;							//��ѹ�������ʾ�����
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
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  NodeH;						//��ѹ�ڵ�
	DWORD  NodeL;						//��ѹ�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}studypw_Tfm1,*LPstudypw_Tfm1;
//3�����ѹ��
typedef struct studypw_Tfm2
{
	DWORD  NU;							//3�Ʊ���
	char  Name[32];						//3�Ʊ���
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	WORD  Tallow;						//��������ʱ��(��)
	WORD  Tover;						//����������ʱ��(��)
	float  TapH;						//�߶˷ֽ�ͷλ��
	float  TapM;						//�ж˷ֽ�ͷλ��
	float  TapL;						//�Ͷ˷ֽ�ͷλ��
	float  Pmax;						//��ѹ������й�(����)
	float  Par;							//��ѹ�������ʾ�����
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
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  NodeH;						//��ѹ�ڵ�
	DWORD  NodeM;						//��ѹ�ڵ�
	DWORD  NodeL;						//��ѹ�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
}studypw_Tfm2,*LPstudypw_Tfm2;
//��̬�޹�����
typedef struct studypw_SVC
{
	DWORD  NU;							//SVC���
	char  Name[32];						//SVC����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Qmax;						//����޹����
	float  Qmin;						//��С�޹����
	float  Q;							//�޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	short  status;						//�ۺ�״̬
}studypw_SVC,*LPstudypw_SVC;
//ĸ��
typedef struct studypw_Bus
{
	DWORD  NU;							//ĸ�߱��
	char  Name[32];						//ĸ������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  MaxV;						//��ѹ����
	float  MinV;						//��ѹ����
	float  HiLimit;						//��ѹ�澯����
	float  LoLimit;						//��ѹ�澯����
	float  PreVhi;						//Ԥ��ʹ�õ�����
	float  PreVlo;						//Ԥ��ʹ�õ�����
	float  Vl;							//��ѹ�ȼ�
	float  V;							//�ڵ��ѹ(pu)
	float  Vb;							//��ѹʵ��ֵ
	float  DayMax;						//�����ֵ
	float  DayMin;						//����Сֵ
	float  deg;							//���
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  AlarmHiLo;					//Խ������0��1��2
	BYTE  AlarmBand;					//Խ5%��0��1
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	DWORD  cNode;						//�ϲ��ڵ�
	short  status;						//�ۺ�״̬
}studypw_Bus,*LPstudypw_Bus;
//������
typedef struct studypw_Line
{
	DWORD  NU;							//�����߱��
	char  Name[32];						//����������
	DWORD  Stationf;					//�׶�վ
	DWORD  Stationt;					//ĩ��վ
	int  Zonef;							//��ʼ�������
	int  Zonet;							//�յ��������
	float  Imax;						//�������ֵ
	float  MaxP;						//�й�����
	float  Par;							//����߸����ʸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  VL;							//��ѹ�ȼ�
	float  Pf;							//ʼ���й�
	float  Qf;							//ʼ���޹�
	float  Pt;							//ĩ���й�
	float  Qt;							//ĩ���޹�
	float  I;							//����ֵ
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  NodeF;						//�׽ڵ�
	DWORD  NodeT;						//ĩ�ڵ�
	short  status;						//�ۺ�״̬
}studypw_Line,*LPstudypw_Line;
//ֱ����
typedef struct studypw_DCLine
{
	DWORD  NU;							//ֱ���߱��
	char  Name[32];						//ֱ��������
	DWORD  Stationf;					//�׶�վ
	DWORD  Stationt;					//ĩ��վ
	int  Zonef;							//��ʼ�������
	int  Zonet;							//�յ��������
	float  Imax;						//�������ֵ
	float  Maxp;						//�й�����
	float  Par;							//����߸����ʸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
	float  VL;							//��ѹ�ȼ�
	float  Pf;							//ʼ���й�
	float  Qf;							//ʼ���޹�
	float  Pt;							//ĩ���й�
	float  Qt;							//ĩ���޹�
	float  I;							//����ֵ
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  NodeF;						//�׽ڵ�
	DWORD  NodeT;						//ĩ�ڵ�
	short  status;						//�ۺ�״̬
}studypw_DCLine,*LPstudypw_DCLine;
//�������������
typedef struct studypw_CVT
{
	DWORD  NU;							//�豸���
	char  Name[32];						//�豸����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	short  status;						//�ۺ�״̬
}studypw_CVT,*LPstudypw_CVT;
//�ӵ�
typedef struct studypw_GND
{
	DWORD  NU;							//�ӵر��
	char  Name[32];						//�ӵ�����
	DWORD  Station;						//����վ��
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
}studypw_GND,*LPstudypw_GND;
//����
typedef struct studypw_Zone
{
	DWORD  NU;							//������
	char  Name[32];						//��������
	float  Pgen;						//�����й�
	float  Qgen;						//�޹�����
	float  GenMax;						//���������
	float  Pld;							//�й�����
	float  Qld;							//�޹�����
	float  LdMax;						//�������ֵ
	float  ZoneLP;						//�����й�����
	float  ZoneLQ;						//�����޹�����
	short  Sub50;						//500kV���վ��
	short  Sub22;						//220kV���վ��
	float  TransMW;						//���վ����
}studypw_Zone,*LPstudypw_Zone;
//վ
typedef struct studypw_Station
{
	DWORD  NU;							//վ��
	char  Name[32];						//վ��
	DWORD  zoneNU;						//��������
	float  VL;							//��ѹ�ȼ�
	int  Type;							//��վ����
	char  ID[24];						//���վ��ʶ
	short  status;						//�ۺ�״̬
}studypw_Station,*LPstudypw_Station;
//���ڵ��ѹ����
typedef struct studypw_VotOutage
{
	int  NU;							//�豸���
	char  type;							//�豸����
	float  Defl;						//����ָ��
	BYTE  Group;						//��������
}studypw_VotOutage,*LPstudypw_VotOutage;
//��֧·����
typedef struct studypw_LineOutage
{
	int  NU;							//�豸���
	char  type;							//����
	float  Defl;						//����ָ��
	BYTE  Group;						//��������
}studypw_LineOutage,*LPstudypw_LineOutage;
//�ڵ��ѹ��֧·�ϳ�
typedef struct studypw_AllOutage
{
	int  NU;							//�豸���
	char  type;							//����
	float  Defl;						//����ָ��
	BYTE  Group;						//��������
}studypw_AllOutage,*LPstudypw_AllOutage;
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
//ϵͳ�澯
typedef struct studypw_Ace
{
	DWORD  ID;							//��ʶID
	float  CurVal;						//��ǰֵ
	CTime  datatime;					//����ʱ��
	BYTE  alarm;						//�澯
	BYTE  ack;							//ȷ��
}studypw_Ace,*LPstudypw_Ace;
//��·����������
typedef struct studypw_ShortCC
{
	DWORD  SwtNU;						//���ر��ID
	BYTE  GType;						//��������
	DWORD  LineNU;						//��·���
	BYTE  LineType;						//��·����
	CTime  DTime;						//����ʱ��
	float  TrPos;						//����λ��
	float  Imax;						//������
	float  Isc;							//��·����
	float  Usc;							//������ѹ
}studypw_ShortCC,*LPstudypw_ShortCC;
//�����Ǳ���ʾ
typedef struct studypw_Meter
{
	int  ID;							//Ψһ��ID��
	char  Name[32];						//����
	float  Value;						//��ǰֵ
	float  Vmax;						//���ֵ
	float  Vmin;						//��Сֵ
	float  Vmax1;						//��һ�����ֵ
	float  Vmin1;						//��һ����Сֵ
	float  Vmax2;						//�ڶ������ֵ
	float  Vmin2;						//�ڶ�����Сֵ
	BYTE  AreaNo;						//�������
	BYTE  FieldNo;						//�ֶ����
}studypw_Meter,*LPstudypw_Meter;
//������
typedef struct studypw_Area
{
	DWORD  NU;							//������
	char  Name[32];						//��������
	DWORD  AColor;						//������ɫ
	float  Security;					//��ȫָ��
	float  LDFactor;					//���ر�
	float  LDFactorT;					//�������ر�
	float  LDFactorL;					//��·���ر�
	float  LDFactorG;					//�������ر�
	float  LDFactorS;					//�޹����ر�
	float  Energy;						//����ƽ��
	float  VolRate;						//��ѹ�ϸ���
	float  LDRate;						//����ˮƽ
	float  OverLoading;					//������
	float  OverLoadingT;				//����������
	float  OverLoadingL;				//��·������
}studypw_Area,*LPstudypw_Area;
//��ѹ�޹����Ʊ�
typedef struct studypw_AVC
{
	DWORD  NU;							//��ѹ����
	char  Name[64];						//�豸����
	float  fVol;						//����ѹֵ
	float  fVar;						//����޹�ֵ
	BYTE  POS;							//����ͼλ��
	BYTE  byTransType;					//��ѹ������
	char  Property[256];				//����
	char  PreValues[96];				//����ı仯ֵ
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
}studypw_AVC,*LPstudypw_AVC;
//�����PQV������
typedef struct studypw_PQV
{
	DWORD  GenNU;						//��������
	char  Name[64];						//�豸����
	DWORD  BusNU;						//����ĸ�ߺ�
	BYTE  Gentype;						//�����͹������
	float  FacS;						//���������
	float  FacU;						//�������ѹ
	float  FacF;						//�����Ƶ��
	float  xd;							//D��翹
	float  xq;							//Q��翹
	float  imax;						//������ŵ���
	float  eqmax;						//����ͨ
	char  Property[256];				//����
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
}studypw_PQV,*LPstudypw_PQV;
//����ͳ�Ʊ�
typedef struct studypw_ldstate
{
	DWORD  NU;							//���
	BYTE  type;							//����
	float  LDmax;						//�������
	CTime  LDmaxT;						//����س���ʱ��
	DWORD  LDoverT;						//�ո��ع���ʱ��
}studypw_ldstate,*LPstudypw_ldstate;
//��ѹ������������
typedef struct studypw_Hvcondata
{
	DWORD  ID;							//IDֵ
	char  Name1[40];					//����
	char  Name2[40];					//����
	float  Vlimit;						//��ֵ
	float  Curval;						//��ǰֵ
	char  sta;							//����״̬
	CTime  datetm;						//����ʱ��
	char  Alarm;						//�澯
	char  Ack;							//ȷ��
}studypw_Hvcondata,*LPstudypw_Hvcondata;
//��ѹ����̬����
typedef struct studypw_DynMonitor
{
	DWORD  NU;							//���
	char  Name[32];						//����
	BYTE  Winding;						//��������
	BYTE  Mode;							//����ģʽ
	float  Normal1;						//������ֵ1
	int  NorTime1;						//������ֵ1ʱ��
	float  Normal2;						//������ֵ2
	int  NorTime2;						//������ֵ2ʱ��
	float  Normal3;						//������ֵ3
	int  NorTime3;						//������ֵ3ʱ��
	float  Contingency1;				//�¹���ֵ1
	int  CtgTime1;						//�¹���ֵ1ʱ��
	float  Contingency2;				//�¹���ֵ2
	int  CtgTime2;						//�¹���ֵ2ʱ��
	float  Contingency3;				//�¹���ֵ3
	int  CtgTime3;						//�¹���ֵ3ʱ��
	char  Buffer[240];					//��������
}studypw_DynMonitor,*LPstudypw_DynMonitor;
//�¹�Ӱ��
typedef struct studypw_CtgEffect
{
	DWORD  CtgNU;						//�¹��豸��
	char  CtgName[32];					//�¹��豸��
	int  CtgType;						//�¹��豸����
	float  fSecurity;					//����ָ��
	DWORD  EftNU;						//��̬�豸��
	char  EftName[32];					//��̬�豸��
	int  EftType;						//��̬�豸����
	float  EftVal;						//��̬�̶�
}studypw_CtgEffect,*LPstudypw_CtgEffect;
//ȫ��������
typedef struct studypw_Grid
{
	float  GenMax;						//ȫ������������
	float  GenP;						//ȫ�������й�
	float  GenQ;						//ȫ�������޹�
	float  StopP;						//ȫ��ͣ��������
	float  UpRes;						//ȫ������ת����
	float  DownRes;						//ȫ������ת����
	float  LoadMax;						//ȫ������ܸ���
	float  LoadP;						//ȫ���õ縺��
}studypw_Grid,*LPstudypw_Grid;
//��ѹ������
typedef struct studypw_Winding
{
	DWORD  NU;							//������
	char  ID[24];						//�����ʶ
	char  TID[24];						//��ѹ����ʶ
	float  ratedKV;						//���ѹ
	float  ratedMVA;					//�����
	float  fShortLoss;					//��·���
	float  fShortVol;					//��·��ѹ
	float  fNoLoadLoss;					//�������
	float  fR;							//����
	float  fX;							//�翹
	float  fB;							//����
	float  fR0;							//�����
	float  fX0;							//��翹
	BYTE  Type;							//��������
	BYTE  Tmax;							//���λ
	BYTE  Tmin;							//��С��λ
	BYTE  Tnor;							//������λ
	float  step;						//��λ����
}studypw_Winding,*LPstudypw_Winding;
//���߱�
typedef struct studypw_Conductor
{
	DWORD  NU;							//���
	BYTE  Type;							//����
	char  LID[24];						//��·��ʶ
	float  fR;							//����
	float  fX;							//�翹
	float  fB;							//����
	float  fG;							//�絼
	float  fR0;							//�������
	float  fX0;							//����翹
	float  fB0;							//�������
	float  fG0;							//����絼
}studypw_Conductor,*LPstudypw_Conductor;
//=================AVC��===============
//�������ñ�
typedef struct refavc_NetSet_table
{
	short  shNo;						//���
	char  szName[50];					//��������
	BYTE  byProtocol;					//����Э��
	int  iPort;							//����˿�
	char  szDestIpAddr[24];				//Ŀ��IP
	char  szSouIpAddr[24];				//ԴIP
}refavc_NetSet_table,*LPrefavc_NetSet_table;
//ң�ر�
typedef struct refavc_yk_table
{
	DWORD  shFacNo;						//����
	DWORD  shOrderNo;					//�豸��
	DWORD  shSwitchNo;					//���غ�
	DWORD  shYxOrder;					//ң�ŵ��
	DWORD  shYKNo;						//ң�ص��
	WORD  DayMaxCtrlNum;				//����������
	WORD  BackBlankTime;				//������ʱ��
	CTime  LastCtrlTime;				//�ϴο���ʱ��
	WORD  ActNum;						//��������
	WORD  RefuseNum;					//�ܶ�����
	BYTE  Priority;						//�������ȼ�
}refavc_yk_table,*LPrefavc_yk_table;
//ң����
typedef struct refavc_yt_table
{
	short  shFacNo;						//����
	short  shOrderNo;					//���
	BYTE  VlPos;						//��ѹ��λ��
	BYTE  byCommandType;				//������ʽ
	short  shUpNo;						//����������
	BYTE  byUpInverse;					//������ȡ��
	short  shDownNo;					//����������
	BYTE  byDownInverse;				//������ȡ��
	short  shStopNo;					//������������
	BYTE  byStopInverse;				//��ͣ����ȡ��
	BYTE  byCurrentPos;					//��ǰλ��
	BYTE  byTopPos;						//���λ��
	BYTE  byBottomPos;					//���λ��
	short  DayMaxActNum;				//����������
	WORD  HdDelayTime;					//������ʱ
	WORD  CdDelayTime;					//����ʱ
	WORD  SameBlankTime;				//ͬ����ʱ��
	WORD  BackBlankTime;				//������ʱ��
	BYTE  LastCtrl;						//�ϴο���
	CTime  LastCtrlTime;				//�ϴο���ʱ��
	WORD  shActNum;						//���ڴ���
	WORD  RefuseNum;					//�ܶ�����
}refavc_yt_table,*LPrefavc_yt_table;
//������Ϣ��
typedef struct refavc_relay_table
{
	short  shFacNo;						//����
	short  shOrderNo;					//���
	char  szName[50];					//��������
	short  shAddress;					//��ַ
}refavc_relay_table,*LPrefavc_relay_table;
//����״̬��
typedef struct refavc_RelayYx_table
{
	short  shFacNo;						//����
	short  shOrderNo;					//���
	char  szName[50];					//����״̬��
	short  shUnitNo;					//��Ԫ��
	short  shSourceNo;					//����Դ��
	short  shFrameOrder;				//�������
	BYTE  byStatus;						//����״̬
	BYTE  byInverter;					//�����־
	BYTE  byRefresh;					//����״̬
	short  shWarnMode;					//�澯��ʽ
	BYTE  byUpdateNum;					//���¼���
}refavc_RelayYx_table,*LPrefavc_RelayYx_table;
//T�ڵ��
typedef struct refavc_tNode_table
{
	short  shTnodeNo;					//T�ӵ���
	char  szName[50];					//T����
	BYTE  byVolDegree;					//��ѹ�ȼ�
	short  shAreaNo;					//���������
	short  shZoneNo;					//�������κ�
	int  iPointNo;						//���ӵ��
}refavc_tNode_table,*LPrefavc_tNode_table;
//��ֵ��ѹ����
typedef struct refavc_equTrans_table
{
	short  shFacNo;						//����
	short  shMasterNo;					//����ѹ����
	short  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	float  fCapacity;					//�����
	BYTE  byReguType;					//��ѹ��ʽ
	BYTE  byStatus;						//����״̬
	BYTE  byLock;						//����״̬
	BYTE  byCtrlType;					//�Ż���������
	short  shTapYcNo;					//��λң�����
	float  fResistance;					//����ֵ
	float  fReactance;					//�翹ֵ
	float  fConductance;				//�絼ֵ
	float  fSusceptance;				//����ֵ
	float  fMinRatio;					//��С���
	float  fMaxRatio;					//�����
	float  fStepSize;					//��λ����
	int  iFromPoint;					//�׶����ӵ��
	int  iToPoint;						//ĩ�����ӵ��
	short  shFromPNo;					//�׶��й��������
	short  shFromQNo;					//�׶��޹��������
	short  shFromINo;					//�׶˵����������
	short  shToPNo;						//ĩ���й��������
	short  shToQNo;						//ĩ���޹��������
	short  shToINo;						//ĩ�˵����������
	float  fBaseVol;					//��׼��ѹ
}refavc_equTrans_table,*LPrefavc_equTrans_table;
//���������
typedef struct refavc_lock_table
{
	short  shLockNo;					//���
	BYTE  byEventType;					//�����¼�����
	char  shEvent[32];					//�����¼�����
	short  shEventNo;					//�����¼����
	BYTE  byObjectType;					//������������
	short  shObjectFac;					//�������󳧺�
	short  shObjectNo;					//�����������
	char  shObjectName[32];				//������������
	short  shWarnMode;					//�澯��ʽ
	BYTE  byUnlockType;					//�����ʽ
}refavc_lock_table,*LPrefavc_lock_table;
//�����
typedef struct refavc_area_table
{
	short  shAreaNo;					//�����
	char  szAreaName[50];				//������
	float  fPA;							//�ƻ��й����
	float  fPLA;						//���佻���ݲ�
}refavc_area_table,*LPrefavc_area_table;
//�����
typedef struct refavc_zone_table
{
	short  shZoneNo;					//���κ�
	char  szZoneName[50];				//������
	BYTE  byIT;							//�Ż�����
	BYTE  byLT;							//��С�������
	BYTE  byMIZ;						//����й����״̬��־
	float  fLossDead;					//�й������������
	float  fLimitDead;					//��ѹԽ�޼�������
	float  fPrePLoss;					//�Ż�ǰ�й�����
	float  fPostPLoss;					//�Ż����й�����
	float  fPreQLoss;					//�Ż�ǰ�޹�����
	float  fPostQLoss;					//�Ż����޹�����
}refavc_zone_table,*LPrefavc_zone_table;
//��ѹ��ֵ��
typedef struct refavc_VolLimit_table
{
	DWORD  shLimitNo;					//��ֵ����
	short  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fMax1st;						//һ�����ֵ
	float  fMin1st;						//һ����Сֵ
	float  fMax2st;						//�������ֵ
	float  fMin2st;						//������Сֵ
	float  fMax3st;						//�������ֵ
	float  fMin3st;						//������Сֵ
}refavc_VolLimit_table,*LPrefavc_VolLimit_table;
//��ѹ�仯��ֵ��
typedef struct refavc_VolVar_table
{
	DWORD  shLimitNo;					//��ֵ����
	short  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fMax1st;						//һ�����ֵ
	float  fMin1st;						//һ����Сֵ
	float  fMax2st;						//�������ֵ
	float  fMin2st;						//������Сֵ
	float  fMax3st;						//�������ֵ
	float  fMin3st;						//������Сֵ
}refavc_VolVar_table,*LPrefavc_VolVar_table;
//�޹���ֵ��
typedef struct refavc_qSetLim_table
{
	DWORD  shLimitNo;					//Լ������
	short  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fUpLimit;					//�޹�/������������
	float  fLowLimit;					//�޹�/������������
	BYTE  vlpos;						//��ѹ��
}refavc_qSetLim_table,*LPrefavc_qSetLim_table;
//��ѹ��ֵ��
typedef struct refavc_vSetLim_table
{
	DWORD  shLimitNo;					//Լ������
	short  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fUpLimit;					//��ѹ����
	float  fLowLimit;					//��ѹ����
	BYTE  vlpos;						//��ѹ��
}refavc_vSetLim_table,*LPrefavc_vSetLim_table;
//�Ż��¼���
typedef struct refavc_opfEvent_table
{
	short  shEventNo;					//���
	BYTE  byEventType;					//�¼�����
	short  shSourceFac;					//�¼�����
	short  shSourceNo;					//�¼����
	BYTE  byYxVal;						//ң��ֵ
	float  fChangeLimit;				//ң��仯��ֵ����ֵ
	short  shRelay;						//������ʱ
	float  fLastValue;					//�ϴβ���ֵ
}refavc_opfEvent_table,*LPrefavc_opfEvent_table;
//�Ż�ʱ���
typedef struct refavc_opfStart_table
{
	short  shTimeNo;					//���
	CTime  tStartTime;					//����ʱ��
}refavc_opfStart_table,*LPrefavc_opfStart_table;
//ң��仯��ֵ��
typedef struct refavc_opfYcLim_table
{
	short  shLimitNo;					//���
	short  shYcFac;						//ң�⳧��
	short  shYcNo;						//ң�����
	float  fChangeLimit;				//�仯������ֵ��ֵ
}refavc_opfYcLim_table,*LPrefavc_opfYcLim_table;
//�Ż��������ñ�
typedef struct refavc_opfSet_table
{
	short  shAutoId;					//���
	BYTE  byRunMode;					//���з�ʽ
	BYTE  byControlMode;				//����ִ�з�ʽ
	BYTE  bySetType;					//�޹���ֵ����
	short  shMaxCmd;					//1������������
	BYTE  byCtrlFail;					//���ƹ����쳣����
	BYTE  byObjPreAct;					//����ʱδ�������ƶ�����
	short  shSeTime;					//״̬���Ƽ���ʱ����ֵ
	short  shOpfTime;					//�Ż�����ʱ����ֵ
	short  shTriggerCyc;				//��������
	short  shCalWarn;					//�Ż����������澯��ʽ
	short  shCtrlWarn;					//�Ż����������澯��ʽ
	short  shCtrlEndWarn;				//�Ż����Ƴɹ��澯��ʽ
	short  shFailWarn;					//�Ż�ʧ�ܸ澯��ʽ
	short  shAutoLockWarn;				//�Զ������澯��ʽ
	float  fBaseMva;					//��׼����
	short  shMaxTapReg;					//��ѹ���������������
}refavc_opfSet_table,*LPrefavc_opfSet_table;
//��������
typedef struct refavc_tIsland_table
{
	int  iIslandNo;						//��������
	int  iNodeNum;						//�ڵ���
	int  iGenNum;						//�������
	int  iLoadNum;						//������
	short  shSeTime;					//״̬����ʱ��
	BYTE  bySeResult;					//se���
	short  shOpfTime;					//�Ż�����ʱ��
	BYTE  byOpfResult;					//opf���
	int  iMeasNum;						//�����������
	int  iEligibleNum;					//���ƺ�ϸ����
	char  szRefGen[200];				//ƽ���
}refavc_tIsland_table,*LPrefavc_tIsland_table;
//����ڵ��
typedef struct refavc_tmpNode_table
{
	int  iNodeNo;						//�ڵ��
	int  iIslandNo;						//��������
	short  shFacNo;						//���ڳ���
	short  shAreaNo;					//���������
	short  shZoneNo;					//�������κ�
	BYTE  byBusType;					//ĸ������
	BYTE  byCtrlType;					//�Ż���������
	float  fBaseVol;					//��׼��ѹ
	float  fYcVol;						//ң���ѹֵ
	float  fVolWeight;					//��ѹȨֵ
	float  fVolStep;					//��ѹȨֵ����
	BYTE  byJPV;						//��ѹ����״̬
	BYTE  byJPC;						//��ѹ�仯����״̬
	float  fSeVoltage;					//se��ѹֵ
	float  fSeAngle;					//se��ѹ���
	short  shLimitNo;					//��ѹ���Ƽ���
	short  shVarLimNo;					//��ѹ�仯���Ƽ���
	char  Name[32];						//����
}refavc_tmpNode_table,*LPrefavc_tmpNode_table;
//�����ѹ����
typedef struct refavc_tmpTrans_table
{
	short  shFacNo;						//����
	short  shMasterNo;					//����ѹ����
	int  iTransNo;						//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	float  fCapacity;					//�����
	BYTE  byReguType;					//��ѹ��ʽ
	BYTE  byStatus;						//����״̬
	BYTE  byLock;						//����״̬
	BYTE  byCtrlType;					//�Ż���������
	float  fResistance;					//����ֵ
	float  fReactance;					//�翹ֵ
	float  fConductance;				//�絼ֵ
	float  fSusceptance;				//����ֵ
	float  fMinRatio;					//��С���
	float  fMaxRatio;					//�����
	float  fCurrentRatio;				//��ǰ���
	float  fStepSize;					//��λ����
	float  fYcFromP;					//�׶��й�����
	float  fFromPWeight;				//�׶��й�Ȩֵ
	float  fFromPStep;					//�׶��й�Ȩֵ����
	float  fYcFromQ;					//�׶��޹�����
	float  fFromQWeight;				//�׶��޹�Ȩֵ
	float  fFromQStep;					//�׶��޹�Ȩֵ����
	float  fYcFromI;					//�׶˵�������
	float  fFromIWeight;				//�׶˵���Ȩֵ
	float  fFromIStep;					//�׶˵���Ȩֵ����
	float  fYcToP;						//ĩ���й�����
	float  fToPWeight;					//ĩ���й�Ȩֵ
	float  fToPStep;					//ĩ���й�Ȩֵ����
	float  fYcToQ;						//ĩ���޹�����
	float  fToQWeight;					//ĩ���޹�Ȩֵ
	float  fToQStep;					//ĩ���޹�Ȩֵ����
	float  fYcToI;						//ĩ�˵�������
	float  fToIWeight;					//ĩ�˵���Ȩֵ
	float  fToIStep;					//ĩ�˵���Ȩֵ����
	int  iFromNode;						//�׶˽ڵ��
	int  iToPoint;						//ĩ�˽ڵ��
	float  fSeFromP;					//�׶��й�
	float  fSeFromQ;					//�׶��޹�
	float  fSeFromI;					//�׶˵���
	float  fSeToP;						//ĩ���й�
	float  fSeToQ;						//ĩ���޹�
	float  fSeToI;						//ĩ�˵���
	int  iIslandNo;						//��������
	char  Name[32];						//����
}refavc_tmpTrans_table,*LPrefavc_tmpTrans_table;
//�����޹��豸��
typedef struct refavc_tmpShunt_table
{
	short  shFacNo;						//����
	int  iShuntNo;						//���
	float  fRateVol;					//���ѹ
	float  fCapacity;					//�����
	BYTE  byStatus;						//����״̬
	BYTE  byLock;						//����״̬
	BYTE  byCtrlType;					//�Ż���������
	float  fYcP;						//�й�����
	float  fPWeight;					//�й�����Ȩֵ
	float  fPStep;						//�й�����Ȩֵ����
	float  fYcQ;						//�޹�����
	float  fQWeight;					//�޹�����Ȩֵ
	float  fQStep;						//�޹�����Ȩֵ����
	float  fYcI;						//��������
	float  fIWeight;					//��������Ȩֵ
	float  fIStep;						//��������Ȩֵ����
	int  iFromNode;						//�׶˽ڵ��
	int  iToPoint;						//ĩ�˽ڵ��
	float  fSeQ;						//�޹�����ֵ
	int  iIslandNo;						//��������
	char  Name[32];						//����
}refavc_tmpShunt_table,*LPrefavc_tmpShunt_table;
//���㷢�����
typedef struct refavc_tmpGen_table
{
	short  shFacNo;						//����
	int  iGenNo;						//�������
	float  fRatedS;						//�����
	float  fRatedP;						//�����
	float  fRatedVol;					//���ѹ
	BYTE  byStatus;						//����״̬
	float  fYcP;						//�й�ң��
	float  fPWeight;					//�й�ң��Ȩֵ
	float  fPStep;						//�й�ң��Ȩֵ����
	float  fYcQ;						//�޹�ң��
	float  fQWeight;					//�޹�ң��Ȩֵ
	float  fQStep;						//�޹�ң��Ȩֵ����
	float  fMaxP;						//����й�
	float  fMinP;						//��С�й�
	float  fMaxQ;						//����޹�
	float  fMinQ;						//��С�޹�
	float  fMaxI;						//���޵���
	BYTE  byRunMode;					//����ģʽ
	float  fVolUpper;					//��ѹ����
	float  fVolLower;					//��ѹ����
	int  iNodeNo;						//�ڵ��
	float  fSeP;						//�й�����ֵ
	float  fSeQ;						//�޹�����ֵ
	int  iIslandNo;						//��������
	char  Name[32];						//����
}refavc_tmpGen_table,*LPrefavc_tmpGen_table;
//���㸺�ɱ�
typedef struct refavc_tmpLoad_table
{
	short  shFacNo;						//����
	int  iLoadNo;						//���
	BYTE  byStatus;						//����״̬
	float  fYcP;						//�й�ң��
	float  fPWeight;					//�й�ң��Ȩֵ
	float  fPStep;						//�й�ң��Ȩֵ����
	float  fYcQ;						//�޹�ң��
	float  fQWeight;					//�޹�ң��Ȩֵ
	float  fQStep;						//�޹�ң��Ȩֵ����
	float  fMaxP;						//����й�
	float  fMinP;						//��С�й�
	float  fMaxQ;						//����޹�
	float  fMinQ;						//��С�޹�
	int  iNodeNo;						//�ڵ��
	float  fSeP;						//�й�����ֵ
	float  fSeQ;						//�޹�����ֵ
	int  iIslandNo;						//��������
	char  Name[32];						//����
}refavc_tmpLoad_table,*LPrefavc_tmpLoad_table;
//������·��
typedef struct refavc_tmpLine_table
{
	int  iLineNo;						//��·��
	short  shFromFac;					//�׶˳���
	short  shToFac;						//ĩ�˳���
	float  fResistance;					//����ֵ
	float  fReactance;					//�翹ֵ
	float  fConductance;				//�絼ֵ
	float  fSusceptance;				//����ֵ
	float  fFromCapacity;				//��·�׶�����
	float  fToCapacity;					//��·ĩ������
	float  fMaxI;						//������ֵ
	float  fYcFromP;					//�׶��й�����
	float  fFromPWeight;				//�׶��й�Ȩֵ
	float  fFromPStep;					//�׶��й�Ȩֵ����
	float  fYcFromQ;					//�׶��޹�����
	float  fFromQWeight;				//�׶��޹�Ȩֵ
	float  fFromQStep;					//�׶��޹�Ȩֵ����
	float  fYcFromI;					//�׶˵�������
	float  fFromIWeight;				//�׶˵���Ȩֵ
	float  fFromIStep;					//�׶˵���Ȩֵ����
	float  fYcToP;						//ĩ���й�����
	float  fToPWeight;					//ĩ���й�Ȩֵ
	float  fToPStep;					//ĩ���й�Ȩֵ����
	float  fYcToQ;						//ĩ���޹�����
	float  fToQWeight;					//ĩ���޹�Ȩֵ
	float  fToQStep;					//ĩ���޹�Ȩֵ����
	float  fYcToI;						//ĩ�˵�������
	float  fToIWeight;					//ĩ�˵���Ȩֵ
	float  fToIStep;					//ĩ�˵���Ȩֵ����
	int  iFromNode;						//�׶˽ڵ��
	int  iToNode;						//ĩ�˽ڵ��
	float  fSeFromP;					//�׶��й�����
	float  fSeFromQ;					//�׶��޹�����
	float  fSeFromI;					//�׶˵�������
	float  fSeToP;						//ĩ���й�����
	float  fSeToQ;						//ĩ���޹�����
	float  fSeToI;						//ĩ�˵�������
	int  iIslandNo;						//��������
	char  Name[32];						//����
}refavc_tmpLine_table,*LPrefavc_tmpLine_table;
//����ĸ�߱�
typedef struct refavc_tmpBus_table
{
	short  shFacNo;						//����
	short  shBusNo;						//ĸ�ߺ�
	int  iNodeNo;						//�ڵ��
	BYTE  byBusType;					//ĸ������
	BYTE  byCtrlType;					//�Ż���������
	float  fBaseVol;					//��׼��ѹ
	float  fYcVol;						//ң���ѹֵ
	float  fVolWeight;					//��ѹȨֵ
	float  fVolStep;					//��ѹȨֵ����
	BYTE  byJPV;						//��ѹ����״̬
	BYTE  byJPC;						//��ѹ�仯����״̬
	short  shLimitNo;					//��ѹ���Ƽ���
	short  shVarLimNo;					//��ѹ�仯���Ƽ���
	char  Name[32];						//����
}refavc_tmpBus_table,*LPrefavc_tmpBus_table;
//�Ż����������Ϣ��
typedef struct refavc_opfRes_table
{
	short  shAutoId;					//���
	CTime  tStartTime;					//����ʱ��
	CTime  tEndTime;					//����ʱ��
	BYTE  byResult;						//������ƽ��
	float  fSeEligible;					//ң����ƺϸ���
	short  shOperateTime;				//����ִ��ʱ��
	float  fPrePLoss;					//�Ż�ǰ�й�����
	float  fPostPLoss;					//�Ż����й�����
	float  fPreQLoss;					//�Ż�ǰ�޹�����
	float  fPostQLoss;					//�Ż����޹�����
	short  shCmdNum;					//������������
	short  shCmdSucNum;					//��������ɹ�����
	char  szStartReason[100];				//����ԭ��
	char  szComment[200];				//˵��
}refavc_opfRes_table,*LPrefavc_opfRes_table;
//���ⲻ���
typedef struct refavc_MeasAna_table
{
	int  iNoBalanceBran;				//��ƽ��֧·��
	int  iNoBalanceNode;				//��ƽ��֧·��
	int  iBSNoMatch;					//���س�����ƥ����
	int  iBadData;						//��������
	int  iShadMeas;						//����������
	int  iDummyMeas;					//α������
}refavc_MeasAna_table,*LPrefavc_MeasAna_table;
//�Ż�ǰ�ڵ��
typedef struct refavc_preNode_table
{
	int  iNodeNo;						//�ڵ��
	int  iIslandNo;						//��������
	float  fVoltage;					//��ѹֵ
	float  fVolAngle;					//��ѹ���
	float  fGenMW;						//�����й�
	float  fGenMvar;					//�����޹�
	float  fLoadMW;						//�����й�
	float  fLoadMvar;					//�����޹�
	float  fShuntMW;					//����֧·�й�
	float  fShuntMvar;					//����֧·�޹�
}refavc_preNode_table,*LPrefavc_preNode_table;
//�Ż���ڵ��
typedef struct refavc_postNode_table
{
	int  iNodeNo;						//�ڵ��
	int  iIslandNo;						//��������
	float  fVoltage;					//��ѹֵ
	float  fVolAngle;					//��ѹ���
	float  fGenMW;						//�����й�
	float  fGenMvar;					//�����޹�
	float  fLoadMW;						//�����й�
	float  fLoadMvar;					//�����޹�
	float  fShuntMW;					//����֧·�й�
	float  fShuntMvar;					//����֧·�޹�
	float  fPSen;						//�й�������
	float  fQSen;						//�޹�������
	float  fSenLoss;					//�������������
}refavc_postNode_table,*LPrefavc_postNode_table;
//�Ż�ǰ��·��
typedef struct refavc_preLine_table
{
	int  iLineNo;						//��·��
	int  iFromNode;						//�׶˽ڵ��
	int  iToNode;						//ĩ�˽ڵ��
	float  fFromMW;						//��·�׶��й�
	float  fFromMvar;					//��·�׶��޹�
	float  fToMW;						//��·ĩ���й�
	float  fToMvar;						//��·ĩ���޹�
}refavc_preLine_table,*LPrefavc_preLine_table;
//�Ż�����·��
typedef struct refavc_postLine_table
{
	int  iLineNo;						//��·��
	int  iFromNode;						//�׶˽ڵ��
	int  iToNode;						//ĩ�˽ڵ��
	float  fFromMW;						//��·�׶��й�
	float  fFromMvar;					//��·�׶��޹�
	float  fToMW;						//��·ĩ���й�
	float  fToMvar;						//��·ĩ���޹�
}refavc_postLine_table,*LPrefavc_postLine_table;
//�Ż�ǰ��ѹ����
typedef struct refavc_preTrans_table
{
	short  shFacNo;						//����
	short  shMasterNo;					//����ѹ����
	short  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	int  iFromNode;						//�׶˽ڵ��
	int  iToNode;						//ĩ�˽ڵ��
	float  fFromMW;						//�׶��й�
	float  fFromMvar;					//�׶��޹�
	float  fToMW;						//ĩ���й�
	float  fToMvar;						//ĩ���޹�
	float  fFromPf;						//�׶˹�������
	float  fToPf;						//ĩ�˹�������
}refavc_preTrans_table,*LPrefavc_preTrans_table;
//�Ż����ѹ����
typedef struct refavc_postTran_table
{
	short  shFacNo;						//����
	short  shMasterNo;					//����ѹ����
	short  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	int  iFromNode;						//�׶˽ڵ��
	int  iToNode;						//ĩ�˽ڵ��
	float  fFromMW;						//�׶��й�
	float  fFromMvar;					//�׶��޹�
	float  fToMW;						//ĩ���й�
	float  fToMvar;						//ĩ���޹�
	float  fFromPf;						//�׶˹�������
	float  fToPf;						//ĩ�˹�������
}refavc_postTran_table,*LPrefavc_postTran_table;
//�Ż����Ʊ�ѹ����
typedef struct refavc_opfTrans_table
{
	short  shFacNo;						//����
	short  shMasterNo;					//����ѹ����
	short  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	int  iFromNode;						//�׶˽ڵ��
	int  iToNode;						//ĩ�˽ڵ��
	float  fFromBaseVol;				//�׶˻�׼��ѹ
	float  fToBaseVol;					//ĩ�˻�׼��ѹ
	float  fPreRatio;					//�Ż�ǰ���
	float  fPostRatio;					//�Ż�����
}refavc_opfTrans_table,*LPrefavc_opfTrans_table;
//�Ż������޹���
typedef struct refavc_opfShunt_table
{
	short  shFacNo;						//����
	short  shShuntNo;					//���
	int  iFromNode;						//�׶˽ڵ��
	int  iToNode;						//ĩ�˽ڵ��
	float  fPreVar;						//�Ż�ǰ����
	float  fPostVar;					//�Ż�������
}refavc_opfShunt_table,*LPrefavc_opfShunt_table;
//VQC��ֵ��
typedef struct refavc_VqcSet_table
{
	short  shFacNo;						//����
	BYTE  byType;						//��ѹ������
	short  shTransNo;					//��ѹ����
	char  szFacName[50];				//��վ��
	char  szTransName[50];				//��ѹ����
	float  fHiVolSet;					//��ѹ��ֵ����
	float  fLowVolSet;					//��ѹ��ֵ����
	float  fHiVarSet;					//�޹�/����������ֵ����
	float  fLowVarSet;					//�޹�/����������ֵ����
	BYTE  byStatus;						//����״̬
}refavc_VqcSet_table,*LPrefavc_VqcSet_table;
//���������
typedef struct refavc_opfCmd_table
{
	int  tmOrder;						//���
	short  shFacNo;						//����
	BYTE  byType;						//�豸����
	short  shDeviceNo;					//�豸���
	char  szFacName[50];				//��վ��
	char  szDevName[50];				//�豸��
	BYTE  byCommand;					//����
	short  shCurTap;					//��ǰ��λ
	short  shEndTap;					//Ŀ�굵λ
	BYTE  byStatus;						//����״̬
}refavc_opfCmd_table,*LPrefavc_opfCmd_table;
//������Ż���
typedef struct refavc_opfGen_table
{
	short  shFacNo;						//����
	short  shGenNo;						//�������
	int  iNodeNo;						//�ڵ��
	float  fPreP;						//�Ż�ǰ�й�
	float  fPostP;						//�Ż����й�
	float  fPreQ;						//�Ż�ǰ�޹�
	float  fPostQ;						//�Ż����޹�
}refavc_opfGen_table,*LPrefavc_opfGen_table;
//�����PQ���߱�
typedef struct refavc_genPQ_table
{
	short  shFacNo;						//����
	short  shGenNo;						//�������
	short  shOrderNo;					//���
	float  fP;							//�й�����
	float  fMaxQ;						//����޹�
	float  fMinQ;						//��С�޹�
}refavc_genPQ_table,*LPrefavc_genPQ_table;
//ĸ���Ż������
typedef struct refavc_opfBus_table
{
	short  shFacNo;						//����
	short  shBusNo;						//ĸ�ߺ�
	char  szFacName[50];				//��վ��
	char  szBusName[50];				//ĸ����
	float  fYcVol;						//ң���ѹֵ
	float  fSeVol;						//״̬���Ƶ�ѹֵ
	float  fSeDev;						//�������ƫ��
	float  fSeAngle;					//״̬���Ƶ�ѹ���
	float  fOpfVol;						//�Ż���ѹֵ
	float  fOpfAngle;					//�Ż���ѹ���
	float  fPostVol;					//���ƺ��ѹֵ
}refavc_opfBus_table,*LPrefavc_opfBus_table;
//��·�Ż������
typedef struct refavc_opfLine_table
{
	int  iLineNo;						//��·��
	char  szName[50];					//��·��
	float  fYcFromP;					//�׶��й�ң��
	float  fYcFromQ;					//�׶��޹�ң��
	float  fYcToP;						//ĩ���й�ң��
	float  fYcToQ;						//ĩ���޹�ң��
	float  fSeFromP;					//״̬�����׶��й�
	float  fSeFromQ;					//״̬�����׶��޹�
	float  fSeToP;						//״̬����ĩ���й�
	float  fSeToQ;						//״̬����ĩ���޹�
	float  fOpfFromP;					//�Ż��׶��й�
	float  fOpfFromQ;					//�Ż��׶��޹�
	float  fOpfToP;						//�Ż�ĩ���й�
	float  fOpfToQ;						//�Ż�ĩ���޹�
	float  fPostFromP;					//���ƺ��׶��й�ң��
	float  fPostFromQ;					//���ƺ��׶��޹�ң��
	float  fPostToP;					//���ƺ�ĩ���й�ң��
	float  fPostToQ;					//���ƺ�ĩ���޹�ң��
}refavc_opfLine_table,*LPrefavc_opfLine_table;
//��ѹ���Ż������
typedef struct refavc_opfByq_table
{
	short  shFacNo;						//����
	BYTE  byType;						//��ѹ������
	short  shTransNo;					//��ѹ����
	char  szFacName[50];				//��վ��
	char  szTransName[50];				//��ѹ����
	float  fYcHiP;						//��ѹ���й�ң��
	float  fYcHiQ;						//��ѹ���޹�ң��
	float  fYcMidP;						//��ѹ���й�ң��
	float  fYcMidQ;						//��ѹ���޹�ң��
	float  fYcLowP;						//��ѹ���й�ң��
	float  fYcLowQ;						//��ѹ���޹�ң��
	float  fPreHiRatio;					//�Ż�ǰ��ѹ���
	float  fPreMidRatio;				//�Ż�ǰ��ѹ���
	float  fSeHiP;						//״̬���Ƹ�ѹ���й�
	float  fSeHiQ;						//״̬���Ƹ�ѹ���޹�
	float  fSeMidP;						//״̬������ѹ���й�
	float  fSeMidQ;						//״̬������ѹ���޹�
	float  fSeLowP;						//״̬���Ƶ�ѹ���й�
	float  fSeLowQ;						//״̬���Ƶ�ѹ���޹�
	float  fOpfHiP;						//�Ż���ѹ���й�
	float  fOpfHiQ;						//�Ż���ѹ���޹�
	float  fOpfMidP;					//�Ż���ѹ���й�
	float  fOpfMidQ;					//�Ż���ѹ���޹�
	float  fOpfLowP;					//�Ż���ѹ���й�
	float  fOpfLowQ;					//�Ż���ѹ���޹�
	float  fPostHiRatio;				//�Ż����ѹ���
	float  fPostMidRatio;				//�Ż�����ѹ���
	float  fPostHiP;					//���ƺ��ѹ���й�ң��
	float  fPostHiQ;					//���ƺ��ѹ���޹�ң��
	float  fPostMidP;					//���ƺ���ѹ���й�ң��
	float  fPostMidQ;					//���ƺ���ѹ���޹�ң��
	float  fPostLowP;					//���ƺ��ѹ���й�ң��
	float  fPostLowQ;					//���ƺ��ѹ���޹�ң��
}refavc_opfByq_table,*LPrefavc_opfByq_table;
//�޹��豸�Ż������
typedef struct refavc_opfWgsb_table
{
	short  shFacNo;						//����
	short  shShuntNo;					//���
	char  szFacName[50];				//��վ��
	char  szName[50];					//�豸��
	float  fYcQ;						//�޹�ң��
	float  fSeQ;						//״̬�����޹�
	float  fOpfQ;						//�Ż��޹�
	float  fPostQ;						//���ƺ��޹�ң��
}refavc_opfWgsb_table,*LPrefavc_opfWgsb_table;
//������Ż������
typedef struct refavc_opfFdj_table
{
	short  shFacNo;						//����
	short  shGenNo;						//�������
	char  szFacName[50];				//��վ��
	char  szName[50];					//�������
	float  fYcP;						//�й�ң��
	float  fYcQ;						//�޹�ң��
	float  fSeP;						//״̬�����й�
	float  fSeQ;						//״̬�����޹�
	float  fOpfP;						//�Ż��й�
	float  fOpfQ;						//�Ż��޹�
	float  fPostP;						//���ƺ��й�ң��
	float  fPostQ;						//���ƺ��޹�ң��
}refavc_opfFdj_table,*LPrefavc_opfFdj_table;
//��ѹ����ͳ�Ʊ�
typedef struct refavc_VolSeSta_table
{
	int  iIslandNo;						//��������
	BYTE  byStaType;					//����ͳ������
	BYTE  byVolDegree;					//��ѹ�ȼ����
	float  fVolSeAccu;					//���ƺϸ���
}refavc_VolSeSta_table,*LPrefavc_VolSeSta_table;
//ĸ�ߵ�ѹԽ�ޱ�
typedef struct refavc_BusExcee_table
{
	short  shFacNo;						//����
	short  shBusNo;						//ĸ�ߺ�
	char  szFacName[50];				//��վ��
	char  szBusName[50];				//ĸ����
	float  fYcVol;						//ң���ѹֵ
	float  fSeVol;						//״̬���Ƶ�ѹֵ
	float  fOpfVol;						//�Ż���ѹֵ
}refavc_BusExcee_table,*LPrefavc_BusExcee_table;
//��ѹ����ı�
typedef struct refavc_LossByq_table
{
	short  shFacNo;						//����
	BYTE  byType;						//��ѹ������
	short  shTransNo;					//��ѹ����
	char  szFacName[50];				//��վ��
	char  szTransName[50];				//��ѹ����
	float  fPrePLoss;					//�Ż�ǰ�й����
	float  fPostPLoss;					//�Ż����й����
	float  fPreQLoss;					//�Ż�ǰ�޹����
	float  fPostQLoss;					//�Ż����޹����
}refavc_LossByq_table,*LPrefavc_LossByq_table;
//��·��ı�
typedef struct refavc_LossLine_table
{
	int  iLineNo;						//��·��
	char  szName[50];					//��·��
	float  fPrePLoss;					//�Ż�ǰ�й����
	float  fPostPLoss;					//�Ż����й����
	float  fPreQLoss;					//�Ż�ǰ�޹����
	float  fPostQLoss;					//�Ż����޹����
}refavc_LossLine_table,*LPrefavc_LossLine_table;
//��ǰ������
typedef struct refavc_curLock_table
{
	CTime  tLockTime;					//����ʱ��
	BYTE  byObjectType;					//������������
	short  shObjectFac;					//�������󳧺�
	char  szFacName[50];				//����������
	short  shObjectNo;					//���������
	char  szObectName[50];				//����������
	char  szLockInfo[100];				//������Ϣ
}refavc_curLock_table,*LPrefavc_curLock_table;
//��ʱ�޿��Ʊ�
typedef struct refavc_DevCtrl_table
{
	short  shOrderNo;					//���
	float  fVolIntegral;				//��ѹ������
	float  fVolSecIncreas;				//��ѹ��������
	short  shVolHop;					//��ѹ������
	float  fCosIntegral;				//���ʻ������
	float  fCosSecIncreas;				//���ʶ�������
	short  shCosHop;					//����������
}refavc_DevCtrl_table,*LPrefavc_DevCtrl_table;
//�����
typedef struct refavc_Rule_table
{
	BYTE  rule_no;						//������
	short  order_no;					//���
	BYTE  v_status;						//��ѹ״̬
	BYTE  cos_status;					//��������״̬
	BYTE  t_status;						//��ѹ����ǰ״
	BYTE  c_status;						//����װ��״̬
	BYTE  t_action;						//��ѹ������
	BYTE  c_action;						//����װ�ö���
}refavc_Rule_table,*LPrefavc_Rule_table;
//���������
typedef struct refavc_shady_table
{
	BYTE  bType;						//����
	char  szInfo[160];					//��Ϣ
}refavc_shady_table,*LPrefavc_shady_table;
#endif