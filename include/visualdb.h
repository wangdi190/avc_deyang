#if !defined(_DB_STRUCT_H_)
#define _DB_STRUCT_H_
/************************************************/
//��ͷ�ļ��ɡ����ݿ����������Զ�����
//2016-5-9
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
	char  Name[64];						//�������
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
	CTime  LogTime;						//����ʱ��
}visualpw_Gen,*LPvisualpw_Gen;
//���ص�բ
typedef struct visualpw_Switch
{
	DWORD  NU;							//���ر��
	char  Name[64];						//��������
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
	CTime  LogTime;						//����ʱ��
}visualpw_Switch,*LPvisualpw_Switch;
//����
typedef struct visualpw_Load
{
	DWORD  NU;							//���ɱ��
	char  Name[64];						//��������
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
	CTime  LogTime;						//����ʱ��
}visualpw_Load,*LPvisualpw_Load;
//����
typedef struct visualpw_Shunt
{
	DWORD  NU;							//�����豸���
	char  Name[64];						//�����豸����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Q;							//Ͷ���޹�
	float  I;							//����
	float  RVol;						//���ѹ
	float  Qmax;						//����޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	float  Qchk;						//��������
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
	DWORD  CtrlType;					//�������Ͷ���
	CTime  LogTime;						//����ʱ��
}visualpw_Shunt,*LPvisualpw_Shunt;
//�翹
typedef struct visualpw_Sreact
{
	DWORD  NU;							//�翹�����
	char  Name[64];						//�翹����
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
	DWORD  CtrlType;					//�������Ͷ���
	float  RVol;						//���ѹ
	float  Qmax;						//����޹����
	CTime  LogTime;						//����ʱ��
}visualpw_Sreact,*LPvisualpw_Sreact;
//2�����ѹ��
typedef struct visualpw_Tfm1
{
	DWORD  NU;							//2�Ʊ���
	char  Name[64];						//2�Ʊ���
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
	DWORD  CtrlType;					//�������Ͷ���
	float  CosDn;						//������������
	float  CosUp;						//������������
	CTime  LogTime;						//����ʱ��
}visualpw_Tfm1,*LPvisualpw_Tfm1;
//3�����ѹ��
typedef struct visualpw_Tfm2
{
	DWORD  NU;							//3�Ʊ���
	char  Name[64];						//3�Ʊ���
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
	DWORD  CtrlType;					//�������Ͷ���
	float  CosDn;						//������������
	float  CosUp;						//������������
	CTime  LogTime;						//����ʱ��
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
	CTime  LogTime;						//����ʱ��
}visualpw_SVC,*LPvisualpw_SVC;
//ĸ��
typedef struct visualpw_Bus
{
	DWORD  NU;							//ĸ�߱��
	char  Name[64];						//ĸ������
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
	DWORD  CtrlType;					//�������Ͷ���
	CTime  LogTime;						//����ʱ��
}visualpw_Bus,*LPvisualpw_Bus;
//������
typedef struct visualpw_Line
{
	DWORD  NU;							//�����߱��
	char  Name[64];						//����������
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
	BYTE  EquiSta;						//��ֵ״̬
	CTime  LogTime;						//����ʱ��
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
	CTime  LogTime;						//����ʱ��
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
	char  Name[64];						//�ӵ�����
	DWORD  Station;						//����վ��
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	CTime  LogTime;						//����ʱ��
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
	CTime  LogTime;						//����ʱ��
}visualpw_Zone,*LPvisualpw_Zone;
//վ
typedef struct visualpw_Station
{
	DWORD  NU;							//վ��
	char  Name[64];						//վ��
	DWORD  zoneNU;						//��������
	float  VL;							//��ѹ�ȼ�
	int  Type;							//��վ����
	char  ID[24];						//���վ��ʶ
	short  status;						//�ۺ�״̬
	DWORD  CtrlType;					//�������Ͷ���
	CTime  LogTime;						//����ʱ��
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
	CTime  LogTime;						//����ʱ��
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
	char  Name[64];						//����
	char  ID[24];						//�����ʶ
	char  TID[24];						//��ѹ����ʶ
	float  baseKV;						//��׼��ѹ
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
	CTime  LogTime;						//����ʱ��
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
	CTime  LogTime;						//����ʱ��
}visualpw_Conductor,*LPvisualpw_Conductor;
//������Ϣ��
typedef struct visualpw_Relay
{
	DWORD  ID;							//����ID��
	DWORD  Station;						//��վ��
	char  Name[64];						//��������
	BYTE  RelayType;					//��������
	BYTE  YX;							//ң��״̬
	DWORD  BayID;						//���ID
	DWORD  DevID;						//�����豸ID
	DWORD  DevNU;						//�����豸���
	char  DevName[64];					//�����豸����
	CTime  LogTime;						//����ʱ��
}visualpw_Relay,*LPvisualpw_Relay;
//ң�Ŷ����
typedef struct visualpw_YX
{
	DWORD  ID;							//ң��ID
	char  Name[64];						//ң������
	DWORD  DevID;						//�豸ID
	BYTE  DevType;						//�豸����
	char  DevName[64];					//�豸����
	BYTE  YX;							//ң��״̬
	CTime  LogTime;						//����ʱ��
}visualpw_YX,*LPvisualpw_YX;
//ң�ⶨ���
typedef struct visualpw_YC
{
	DWORD  ID;							//ң��ID
	char  Name[64];						//ң������
	DWORD  DevID;						//�豸ID
	BYTE  DevType;						//�豸����
	char  DevName[64];					//�豸����
	BYTE  MeasType;						//ң������
	BYTE  MeasPos;						//ң��λ��
	float  YC;							//ң��ֵ
	CTime  LogTime;						//����ʱ��
}visualpw_YC,*LPvisualpw_YC;
//ң��ң�Ź�ϵ��
typedef struct visualpw_YKYX
{
	DWORD  NU;							//���
}visualpw_YKYX,*LPvisualpw_YKYX;
//ϵͳ���������ݱ�
typedef struct visualpw_SysPowerLoss
{
	CTime  LogTime;						//ͳ��ʱ��
	BYTE  IsToDay;						//�Ƿ�������
	float  PowerP;						//���й�
	float  PowerQ;						//���޹�
	float  LoadP;						//�����й�
	float  LoadQ;						//�����޹�
	float  ShuntQ;						//�����޹�
	float  LossP;						//�й�����
	float  LossQ;						//�޹�����
	float  TheoryLossP;					//�����й�����
	float  TheoryLossQ;					//�����޹�����
}visualpw_SysPowerLoss,*LPvisualpw_SysPowerLoss;
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
	DWORD  Nu;							//���Ա�ţ�0Ϊר�ñ�ţ���0
	char  Name[64];						//��������
	char  Info[200];					//������Ϣ
	CTime  TestTime;					//��������ʱ��
	BYTE  TestType;						//�������Է���
	CTime  ProcTime;					//���̼���ѡ��ʱ��
	BYTE  RunSta;						//����״̬1��2��
	short  TopuRun;						//��������״̬
	short  SeRun;						//״̬��������״̬
	short  OpfRun;						//�Ż���������״̬
	char  Result[64];					//������̻�������
}common_RunType,*LPcommon_RunType;
//ĸ�߹���ֵ
typedef struct common_BusV
{
	DWORD  Nu;							//���
	char  Name[64];						//�豸��
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
	char  VName[64];					//���ӻ����豸����
	BYTE  DevType;						//�豸����
	BYTE  MeasType;						//��������
	char  MeasName[64];					//��������
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
	char  Name[64];						//����
	float  Value;						//����ֵ
}common_PreLimit,*LPcommon_PreLimit;
//���⿪�ع�����ϵ
typedef struct common_VSwitch
{
	DWORD  SwtNU;						//����ID
	char  Name[64];						//��������
	DWORD  VSwtNU;						//�������⿪��NU
	DWORD  LineNU;						//������·
}common_VSwitch,*LPcommon_VSwitch;
//Ԥ������泱��
typedef struct common_PreDefSF
{
	DWORD  ID;							//����ID
	char  Name[64];						//��������
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
	char  Name[64];						//������
	float  Param;						//����ֵ
}common_AppParam,*LPcommon_AppParam;
//�Ӷ����
typedef struct common_SubObject
{
	DWORD  NU;							//���
	char  Name[64];						//����
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
	char  Name[64];						//����
	float  max;							//���ֵ
	float  min;							//��Сֵ
	float  val;							//ֵ
	BYTE  type;							//��������
	char  ID[32];						//��ʶ
	char  PID[32];						//����ʶ
}common_UnEquMeas,*LPcommon_UnEquMeas;
//�������ӹ�ϵ��
typedef struct common_LinkRelation
{
	DWORD  NU;							//�豸NU
	char  Name[64];						//�豸����
	DWORD  Station;						//��վ���
	DWORD  Zone;						//������
	BYTE  DevType;						//�豸����
	DWORD  Bus1;						//����ĸ��1
	char  BusName1[64];					//����ĸ��1
	char  LinkDev1[128];				//���ӵĿ����豸����,�Ÿ���
	DWORD  Bus2;						//����ĸ��2
	char  BusName2[64];					//����ĸ��2
	char  LinkDev2[128];				//���ӵĿ����豸����,�Ÿ���
	DWORD  Bus3;						//����ĸ��3
	char  BusName3[64];					//����ĸ��3
	char  LinkDev3[128];				//���ӵĿ����豸����,�Ÿ���
}common_LinkRelation,*LPcommon_LinkRelation;
//���޻�����ѹ��
typedef struct common_BVoltage
{
	WORD  NU;							//���
	char  Name[32];						//����
	float  BaseVol;						//������ѹ
	float  StanVol;						//�궨��ѹ
	float  Dn1;							//���е�ѹ
	float  Up1;							//���е�ѹ
	float  Dn2;							//���е�ѹ
	float  Up2;							//���е�ѹ
	float  Dn3;							//���е�ѹ
	float  Up3;							//���е�ѹ
}common_BVoltage,*LPcommon_BVoltage;
//ϵͳ���в���
typedef struct common_SysRunParam
{
	BYTE  ParamType;					//�������
	char  ParamName[64];				//��������
	char  ParamValue[128];				//����
}common_SysRunParam,*LPcommon_SysRunParam;
//��־��
typedef struct common_LogRecord
{
	CTime  time;						//��¼ʱ��
	char  App[64];						//Ӧ��
	char  Data[256];					//��־
}common_LogRecord,*LPcommon_LogRecord;
//=================��������===============
//�����
typedef struct emluator_mGen
{
	DWORD  NU;							//���
	char  Name[64];						//����
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
	char  Name[64];						//����
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
	char  Name[64];						//����
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
	char  Name[64];						//����
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
	char  Name[64];						//����
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
	char  Name[64];						//����
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
	char  Name[64];						//����
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
	char  Name[64];						//����
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
	char  Name[64];						//����
	float  statval;						//ͳ��ֵ
}emluator_mStat,*LPemluator_mStat;
//=================������===============
//��Ŀ��
typedef struct estimator_project
{
	DWORD  NU;							//��Ŀ���
	char  Name[64];						//��Ŀ����
	char  AVC[64];						//������AVC
	BYTE  Type;							//����
	char  projectpath[128];				//��Ŀ·��
}estimator_project,*LPestimator_project;
//����
typedef struct estimator_estimate
{
	DWORD  NU;							//���
	char  description[64];				//��������
	DWORD  project;						//��������Ŀ
	char  report[64];					//��������
}estimator_estimate,*LPestimator_estimate;
//��������
typedef struct estimator_estcase
{
	DWORD  NU;							//�������
	char  Name[64];						//��������
	DWORD  project;						//��������Ŀ
	short  casetype;					//��������
	BYTE  onlie;						//���߰���
	char  descr[256];					//��������
}estimator_estcase,*LPestimator_estcase;
//���涨��
typedef struct estimator_sectdef
{
	DWORD  NU;							//������
	char  Name[64];						//��������
	char  Path[64];						//����·��
	DWORD  estcase;						//����������
	CTime  dtime;						//����ʱ��
	char  descr[256];					//��������
}estimator_sectdef,*LPestimator_sectdef;
//�����
typedef struct estimator_eGen
{
	DWORD  NU;							//���
	char  Name[64];						//����
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
	char  Name[64];						//����
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
	char  Name[64];						//����
	DWORD  MU;							//������
	float  rateP;						//�����
	float  rateVI;						//���ѹ
	float  rateVJ;						//���ѹ
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
	float  TapPos;						//��ǰ��λ
	float  Pi;							//I���й�
	float  Qi;							//I���޹�
	float  Pj;							//J���й�
	float  Qj;							//J���޹�
	float  I;							//����
	BYTE  sta;							//״̬
	short  status;						//�ۺ�״̬
	int  station;						//��վ
	int  island;						//������
	DWORD  Parallel;					//����֧·
}estimator_eTfm,*LPestimator_eTfm;
//��·
typedef struct estimator_eLine
{
	DWORD  NU;							//���
	char  Name[64];						//����
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
	DWORD  Parallel;					//����֧·
}estimator_eLine,*LPestimator_eLine;
//����
typedef struct estimator_eLoad
{
	DWORD  NU;							//���
	char  Name[64];						//����
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
	char  Name[64];						//����
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
	BYTE  IsVirtual;					//�����־
}estimator_eShunt,*LPestimator_eShunt;
//����
typedef struct estimator_eSerial
{
	DWORD  NU;							//���
	char  Name[64];						//����
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
	char  Name[64];						//����
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
	char  MeasID[64];					//����ID
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
	char  Name[64];						//��������
	short  casetype;					//��������
	int  estkeep;						//��������ʱ��
	char  dsite[64];					//����λ��
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
	char  Name[64];						//��������
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
//=================AVC��===============
//�������ñ�
typedef struct refavc_NetSet_table
{
	DWORD  shNo;						//���
	char  szName[64];					//��������
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
	char  Name[64];						//����
}refavc_yk_table,*LPrefavc_yk_table;
//ң����
typedef struct refavc_yt_table
{
	DWORD  shFacNo;						//����
	DWORD  shOrderNo;					//���
	BYTE  VlPos;						//��ѹ��λ��
	BYTE  byCommandType;				//������ʽ
	DWORD  shUpNo;						//����������
	BYTE  byUpInverse;					//������ȡ��
	DWORD  shDownNo;					//����������
	BYTE  byDownInverse;				//������ȡ��
	DWORD  shStopNo;					//������������
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
	char  Name[64];						//����
}refavc_yt_table,*LPrefavc_yt_table;
//������Ϣ��
typedef struct refavc_relay_table
{
	DWORD  shFacNo;						//����
	DWORD  shOrderNo;					//���
	char  szName[64];					//��������
	short  shAddress;					//��ַ
}refavc_relay_table,*LPrefavc_relay_table;
//����״̬��
typedef struct refavc_RelayYx_table
{
	DWORD  shFacNo;						//����
	DWORD  shOrderNo;					//���
	char  szName[64];					//����״̬��
	DWORD  shUnitNo;					//��Ԫ��
	DWORD  shSourceNo;					//����Դ��
	DWORD  shFrameOrder;				//�������
	BYTE  byStatus;						//����״̬
	BYTE  byInverter;					//�����־
	BYTE  byRefresh;					//����״̬
	short  shWarnMode;					//�澯��ʽ
	BYTE  byUpdateNum;					//���¼���
}refavc_RelayYx_table,*LPrefavc_RelayYx_table;
//T�ڵ��
typedef struct refavc_tNode_table
{
	DWORD  shTnodeNo;					//T�ӵ���
	char  szName[64];					//T����
	BYTE  byVolDegree;					//��ѹ�ȼ�
	DWORD  shAreaNo;					//���������
	DWORD  shZoneNo;					//�������κ�
	int  iPointNo;						//���ӵ��
}refavc_tNode_table,*LPrefavc_tNode_table;
//��ֵ��ѹ����
typedef struct refavc_equTrans_table
{
	DWORD  shFacNo;						//����
	DWORD  shMasterNo;					//����ѹ����
	DWORD  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	float  fCapacity;					//�����
	BYTE  byReguType;					//��ѹ��ʽ
	BYTE  byStatus;						//����״̬
	BYTE  byLock;						//����״̬
	BYTE  byCtrlType;					//�Ż���������
	DWORD  shTapYcNo;					//��λң�����
	float  fResistance;					//����ֵ
	float  fReactance;					//�翹ֵ
	float  fConductance;				//�絼ֵ
	float  fSusceptance;				//����ֵ
	float  fMinRatio;					//��С���
	float  fMaxRatio;					//�����
	float  fStepSize;					//��λ����
	DWORD  iFromPoint;					//�׶����ӵ��
	int  iToPoint;						//ĩ�����ӵ��
	DWORD  shFromPNo;					//�׶��й��������
	DWORD  shFromQNo;					//�׶��޹��������
	DWORD  shFromINo;					//�׶˵����������
	DWORD  shToPNo;						//ĩ���й��������
	DWORD  shToQNo;						//ĩ���޹��������
	DWORD  shToINo;						//ĩ�˵����������
	float  fBaseVol;					//��׼��ѹ
	char  szName[64];					//����
}refavc_equTrans_table,*LPrefavc_equTrans_table;
//���������
typedef struct refavc_lock_table
{
	DWORD  shLockNo;					//���
	BYTE  byEventType;					//�����¼�����
	char  shEvent[64];					//�����¼�����
	DWORD  shEventNo;					//�����¼����
	BYTE  byObjectType;					//������������
	DWORD  shObjectFac;					//�������󳧺�
	DWORD  shObjectNo;					//�����������
	char  shObjectName[64];				//������������
	short  shWarnMode;					//�澯��ʽ
	BYTE  byUnlockType;					//�����ʽ
}refavc_lock_table,*LPrefavc_lock_table;
//�����
typedef struct refavc_area_table
{
	DWORD  shAreaNo;					//�����
	char  szAreaName[64];				//������
	float  fPA;							//�ƻ��й����
	float  fPLA;						//���佻���ݲ�
}refavc_area_table,*LPrefavc_area_table;
//�����
typedef struct refavc_zone_table
{
	DWORD  shZoneNo;					//���κ�
	char  szZoneName[64];				//������
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
	DWORD  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fMax1st;						//һ�����ֵ
	float  fMin1st;						//һ����Сֵ
	float  fMax2st;						//�������ֵ
	float  fMin2st;						//������Сֵ
	float  fMax3st;						//�������ֵ
	float  fMin3st;						//������Сֵ
	char  szName[64];					//����
}refavc_VolLimit_table,*LPrefavc_VolLimit_table;
//��ѹ�仯��ֵ��
typedef struct refavc_VolVar_table
{
	DWORD  shLimitNo;					//��ֵ����
	DWORD  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fMax1st;						//һ�����ֵ
	float  fMin1st;						//һ����Сֵ
	float  fMax2st;						//�������ֵ
	float  fMin2st;						//������Сֵ
	float  fMax3st;						//�������ֵ
	float  fMin3st;						//������Сֵ
	char  szName[64];					//����
}refavc_VolVar_table,*LPrefavc_VolVar_table;
//�޹���ֵ��
typedef struct refavc_qSetLim_table
{
	DWORD  shLimitNo;					//Լ������
	DWORD  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fUpLimit;					//�޹�/������������
	float  fLowLimit;					//�޹�/������������
	BYTE  vlpos;						//��ѹ��
	char  szName[64];					//����
}refavc_qSetLim_table,*LPrefavc_qSetLim_table;
//��ѹ��ֵ��
typedef struct refavc_vSetLim_table
{
	DWORD  shLimitNo;					//Լ������
	DWORD  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fUpLimit;					//��ѹ����
	float  fLowLimit;					//��ѹ����
	BYTE  vlpos;						//��ѹ��
	char  szName[64];					//����
}refavc_vSetLim_table,*LPrefavc_vSetLim_table;
//�Ż��¼���
typedef struct refavc_opfEvent_table
{
	DWORD  shEventNo;					//���
	BYTE  byEventType;					//�¼�����
	DWORD  shSourceFac;					//�¼�����
	DWORD  shSourceNo;					//�¼����
	BYTE  byYxVal;						//ң��ֵ
	float  fChangeLimit;				//ң��仯��ֵ����ֵ
	short  shRelay;						//������ʱ
	float  fLastValue;					//�ϴβ���ֵ
}refavc_opfEvent_table,*LPrefavc_opfEvent_table;
//�Ż�ʱ���
typedef struct refavc_opfStart_table
{
	DWORD  shTimeNo;					//���
	CTime  tStartTime;					//����ʱ��
}refavc_opfStart_table,*LPrefavc_opfStart_table;
//ң��仯��ֵ��
typedef struct refavc_opfYcLim_table
{
	DWORD  shLimitNo;					//���
	DWORD  shYcFac;						//ң�⳧��
	DWORD  shYcNo;						//ң�����
	float  fChangeLimit;				//�仯������ֵ��ֵ
}refavc_opfYcLim_table,*LPrefavc_opfYcLim_table;
//�Ż��������ñ�
typedef struct refavc_opfSet_table
{
	DWORD  shAutoId;					//���
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
	DWORD  iIslandNo;					//��������
	DWORD  iNodeNum;					//�ڵ���
	DWORD  iGenNum;						//�������
	DWORD  iLoadNum;					//������
	short  shSeTime;					//״̬����ʱ��
	BYTE  bySeResult;					//se���
	short  shOpfTime;					//�Ż�����ʱ��
	BYTE  byOpfResult;					//opf���
	DWORD  iMeasNum;					//�����������
	DWORD  iEligibleNum;				//���ƺ�ϸ����
	char  szRefGen[200];				//ƽ���
}refavc_tIsland_table,*LPrefavc_tIsland_table;
//����ڵ��
typedef struct refavc_tmpNode_table
{
	DWORD  iNodeNo;						//�ڵ��
	DWORD  iIslandNo;					//��������
	DWORD  shFacNo;						//���ڳ���
	DWORD  shAreaNo;					//���������
	DWORD  shZoneNo;					//�������κ�
	short  byBusType;					//ĸ������
	BYTE  byCtrlType;					//�Ż���������
	float  fBaseVol;					//��׼��ѹ
	float  fYcVol;						//ң���ѹֵ
	float  fVolWeight;					//��ѹȨֵ
	float  fVolStep;					//��ѹȨֵ����
	BYTE  byJPV;						//��ѹ����״̬
	BYTE  byJPC;						//��ѹ�仯����״̬
	float  fSeVoltage;					//se��ѹֵ
	float  fSeAngle;					//se��ѹ���
	DWORD  shLimitNo;					//��ѹ���Ƽ���
	DWORD  shVarLimNo;					//�޹��仯���Ƽ���
	char  Name[64];						//����
	float  VolUpLimit;					//��ѹ��������
	float  VolDnLimit;					//��ѹ��������
	float  CosUpLimit;					//���ʿ�������
	float  CosDnLimit;					//���ʿ�������
	DWORD  SysNU;						//ϵͳ�ڲ����
	BYTE  IsGate;						//�ؿڱ�־
}refavc_tmpNode_table,*LPrefavc_tmpNode_table;
//�����ѹ����
typedef struct refavc_tmpTrans_table
{
	DWORD  shFacNo;						//����
	DWORD  shMasterNo;					//����ѹ����
	DWORD  iTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	float  fCapacity;					//�����
	float  fRateKVi;					//���ѹi
	float  fRateKVj;					//���ѹj
	float  fBaseKVi;					//��׼��ѹi
	float  fBaseKVj;					//��׼��ѹi
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
	float  fTapPos;						//��ǰ��λ
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
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToPoint;					//ĩ�˽ڵ��
	float  fSeFromP;					//�׶��й�
	float  fSeFromQ;					//�׶��޹�
	float  fSeFromI;					//�׶˵���
	float  fSeToP;						//ĩ���й�
	float  fSeToQ;						//ĩ���޹�
	float  fSeToI;						//ĩ�˵���
	DWORD  iIslandNo;					//��������
	char  Name[64];						//����
	DWORD  SysNU;						//ϵͳ�ڲ����
	BYTE  IsGate;						//�ؿڱ�־
	float  CosUpLimit;					//���ʿ�������
	float  CosDnLimit;					//���ʿ�������
	DWORD  Parallel;					//����֧·
}refavc_tmpTrans_table,*LPrefavc_tmpTrans_table;
//�����޹��豸��
typedef struct refavc_tmpShunt_table
{
	DWORD  shFacNo;						//����
	DWORD  iShuntNo;					//���
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
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToPoint;					//ĩ�˽ڵ��
	float  fSeQ;						//�޹�����ֵ
	DWORD  iIslandNo;					//��������
	char  Name[64];						//����
	DWORD  SysNU;						//ϵͳ�ڲ����
	BYTE  IsVirtual;					//�����־
}refavc_tmpShunt_table,*LPrefavc_tmpShunt_table;
//���㷢�����
typedef struct refavc_tmpGen_table
{
	DWORD  shFacNo;						//����
	DWORD  iGenNo;						//�������
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
	DWORD  iNodeNo;						//�ڵ��
	float  fSeP;						//�й�����ֵ
	float  fSeQ;						//�޹�����ֵ
	DWORD  iIslandNo;					//��������
	char  Name[64];						//����
	DWORD  SysNU;						//ϵͳ�ڲ����
}refavc_tmpGen_table,*LPrefavc_tmpGen_table;
//���㸺�ɱ�
typedef struct refavc_tmpLoad_table
{
	DWORD  shFacNo;						//����
	DWORD  iLoadNo;						//���
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
	DWORD  iNodeNo;						//�ڵ��
	float  fSeP;						//�й�����ֵ
	float  fSeQ;						//�޹�����ֵ
	DWORD  iIslandNo;					//��������
	char  Name[64];						//����
	DWORD  SysNU;						//ϵͳ�ڲ����
}refavc_tmpLoad_table,*LPrefavc_tmpLoad_table;
//������·��
typedef struct refavc_tmpLine_table
{
	DWORD  iLineNo;						//��·��
	DWORD  shFromFac;					//�׶˳���
	DWORD  shToFac;						//ĩ�˳���
	float  fResistance;					//����ֵ
	float  fReactance;					//�翹ֵ
	float  fConductance;				//�絼ֵ
	float  fSusceptance;				//����ֵ
	float  fFromCapacity;				//��·�׶�����
	float  fToCapacity;					//��·ĩ������
	float  fBaseKV;						//���ѹ
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
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fSeFromP;					//�׶��й�����
	float  fSeFromQ;					//�׶��޹�����
	float  fSeFromI;					//�׶˵�������
	float  fSeToP;						//ĩ���й�����
	float  fSeToQ;						//ĩ���޹�����
	float  fSeToI;						//ĩ�˵�������
	DWORD  iIslandNo;					//��������
	char  Name[64];						//����
	DWORD  SysNU;						//ϵͳ�ڲ����
	DWORD  Parallel;					//����֧·
}refavc_tmpLine_table,*LPrefavc_tmpLine_table;
//����ĸ�߱�
typedef struct refavc_tmpBus_table
{
	DWORD  shFacNo;						//����
	DWORD  shBusNo;						//ĸ�ߺ�
	DWORD  iNodeNo;						//�ڵ��
	short  byBusType;					//ĸ������
	BYTE  byCtrlType;					//�Ż���������
	float  fBaseVol;					//��׼��ѹ
	float  fYcVol;						//ң���ѹֵ
	float  fVolWeight;					//��ѹȨֵ
	float  fVolStep;					//��ѹȨֵ����
	BYTE  byJPV;						//��ѹ����״̬
	BYTE  byJPC;						//��ѹ�仯����״̬
	DWORD  shLimitNo;					//��ѹ���Ƽ���
	DWORD  shVarLimNo;					//�޹��仯���Ƽ���
	char  Name[64];						//����
	DWORD  iIslandNo;					//��������
	float  VolUpLimit;					//��ѹ��������
	float  VolDnLimit;					//��ѹ��������
	float  CosUpLimit;					//���ʿ�������
	float  CosDnLimit;					//���ʿ�������
	DWORD  SysNU;						//ϵͳ�ڲ����
	BYTE  IsGate;						//�ؿڱ�־
}refavc_tmpBus_table,*LPrefavc_tmpBus_table;
//�Ż����������Ϣ��
typedef struct refavc_opfRes_table
{
	DWORD  shAutoId;					//���
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
	DWORD  iNodeNo;						//�ڵ��
	DWORD  iIslandNo;					//��������
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
	DWORD  iNodeNo;						//�ڵ��
	DWORD  iIslandNo;					//��������
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
	DWORD  iLineNo;						//��·��
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fFromMW;						//��·�׶��й�
	float  fFromMvar;					//��·�׶��޹�
	float  fToMW;						//��·ĩ���й�
	float  fToMvar;						//��·ĩ���޹�
}refavc_preLine_table,*LPrefavc_preLine_table;
//�Ż�����·��
typedef struct refavc_postLine_table
{
	DWORD  iLineNo;						//��·��
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fFromMW;						//��·�׶��й�
	float  fFromMvar;					//��·�׶��޹�
	float  fToMW;						//��·ĩ���й�
	float  fToMvar;						//��·ĩ���޹�
}refavc_postLine_table,*LPrefavc_postLine_table;
//�Ż�ǰ��ѹ����
typedef struct refavc_preTrans_table
{
	DWORD  shFacNo;						//����
	DWORD  shMasterNo;					//����ѹ����
	DWORD  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
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
	DWORD  shFacNo;						//����
	DWORD  shMasterNo;					//����ѹ����
	DWORD  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
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
	DWORD  shFacNo;						//����
	DWORD  shMasterNo;					//����ѹ����
	DWORD  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fFromBaseVol;				//�׶˻�׼��ѹ
	float  fToBaseVol;					//ĩ�˻�׼��ѹ
	float  fPreRatio;					//�Ż�ǰ���
	float  fPostRatio;					//�Ż�����
}refavc_opfTrans_table,*LPrefavc_opfTrans_table;
//�Ż������޹���
typedef struct refavc_opfShunt_table
{
	DWORD  shFacNo;						//����
	DWORD  shShuntNo;					//���
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fPreVar;						//�Ż�ǰ����
	float  fPostVar;					//�Ż�������
}refavc_opfShunt_table,*LPrefavc_opfShunt_table;
//VQC��ֵ��
typedef struct refavc_VqcSet_table
{
	DWORD  shFacNo;						//����
	BYTE  byType;						//��ѹ������
	DWORD  shTransNo;					//��ѹ����
	char  szFacName[64];				//��վ��
	char  szTransName[64];				//��ѹ����
	float  fHiVolSet;					//��ѹ��ֵ����
	float  fLowVolSet;					//��ѹ��ֵ����
	float  fHiVarSet;					//�޹�/����������ֵ����
	float  fLowVarSet;					//�޹�/����������ֵ����
	BYTE  byStatus;						//����״̬
}refavc_VqcSet_table,*LPrefavc_VqcSet_table;
//���������
typedef struct refavc_opfCmd_table
{
	DWORD  tmOrder;						//���
	DWORD  shFacNo;						//����
	BYTE  byType;						//�豸����
	DWORD  shDeviceNo;					//�豸���
	char  szFacName[64];				//��վ��
	char  szDevName[64];				//�豸��
	DWORD  SwitchNU;					//���ر��
	char  YKSwitch[64];					//ң�ؿ���
	int  YKPoint;						//ң�ص��
	BYTE  byCommand;					//�������/�Ͻ���
	float  shCurTap;					//��ǰ��λ
	float  shEndTap;					//Ŀ�굵λ
	BYTE  byStatus;						//����״̬
	CTime  CreatTime;					//����ʱ��
	CTime  YKTime;						//����ʱ��
	char  YKInfo[64];					//������Ϣ
	BYTE  YKState;						//ң�ر�ʶ
	char  CtrlType[16];					//���Ʒ���
}refavc_opfCmd_table,*LPrefavc_opfCmd_table;
//������Ż���
typedef struct refavc_opfGen_table
{
	DWORD  shFacNo;						//����
	DWORD  shGenNo;						//�������
	DWORD  iNodeNo;						//�ڵ��
	float  fPreP;						//�Ż�ǰ�й�
	float  fPostP;						//�Ż����й�
	float  fPreQ;						//�Ż�ǰ�޹�
	float  fPostQ;						//�Ż����޹�
}refavc_opfGen_table,*LPrefavc_opfGen_table;
//�����PQ���߱�
typedef struct refavc_genPQ_table
{
	DWORD  shFacNo;						//����
	DWORD  shGenNo;						//�������
	DWORD  shOrderNo;					//���
	float  fP;							//�й�����
	float  fMaxQ;						//����޹�
	float  fMinQ;						//��С�޹�
}refavc_genPQ_table,*LPrefavc_genPQ_table;
//ĸ���Ż������
typedef struct refavc_opfBus_table
{
	DWORD  shFacNo;						//����
	DWORD  shBusNo;						//ĸ�ߺ�
	char  szFacName[64];				//��վ��
	char  szBusName[64];				//ĸ����
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
	DWORD  iLineNo;						//��·��
	char  szName[64];					//��·��
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
	DWORD  shFacNo;						//����
	BYTE  byType;						//��ѹ������
	DWORD  shTransNo;					//��ѹ����
	char  szFacName[64];				//��վ��
	char  szTransName[64];				//��ѹ����
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
	DWORD  shFacNo;						//����
	DWORD  shShuntNo;					//���
	char  szFacName[64];				//��վ��
	char  szName[64];					//�豸��
	float  fYcQ;						//�޹�ң��
	float  fSeQ;						//״̬�����޹�
	float  fOpfQ;						//�Ż��޹�
	float  fPostQ;						//���ƺ��޹�ң��
}refavc_opfWgsb_table,*LPrefavc_opfWgsb_table;
//������Ż������
typedef struct refavc_opfFdj_table
{
	DWORD  shFacNo;						//����
	DWORD  shGenNo;						//�������
	char  szFacName[64];				//��վ��
	char  szName[64];					//�������
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
	DWORD  iIslandNo;					//��������
	BYTE  byStaType;					//����ͳ������
	BYTE  byVolDegree;					//��ѹ�ȼ����
	float  fVolSeAccu;					//���ƺϸ���
}refavc_VolSeSta_table,*LPrefavc_VolSeSta_table;
//ĸ�ߵ�ѹԽ�ޱ�
typedef struct refavc_BusExcee_table
{
	DWORD  shFacNo;						//����
	DWORD  shBusNo;						//ĸ�ߺ�
	char  szFacName[64];				//��վ��
	char  szBusName[64];				//ĸ����
	float  fYcVol;						//ң���ѹֵ
	float  fSeVol;						//״̬���Ƶ�ѹֵ
	float  fOpfVol;						//�Ż���ѹֵ
}refavc_BusExcee_table,*LPrefavc_BusExcee_table;
//��ѹ����ı�
typedef struct refavc_LossByq_table
{
	DWORD  shFacNo;						//����
	BYTE  byType;						//��ѹ������
	DWORD  shTransNo;					//��ѹ����
	char  szFacName[64];				//��վ��
	char  szTransName[64];				//��ѹ����
	float  fPrePLoss;					//�Ż�ǰ�й����
	float  fPostPLoss;					//�Ż����й����
	float  fPreQLoss;					//�Ż�ǰ�޹����
	float  fPostQLoss;					//�Ż����޹����
}refavc_LossByq_table,*LPrefavc_LossByq_table;
//��·��ı�
typedef struct refavc_LossLine_table
{
	DWORD  iLineNo;						//��·��
	char  szName[64];					//��·��
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
	DWORD  shObjectFac;					//�������󳧺�
	char  szFacName[64];				//����������
	DWORD  shObjectNo;					//���������
	char  szObectName[64];				//����������
	char  szLockInfo[100];				//������Ϣ
}refavc_curLock_table,*LPrefavc_curLock_table;
//��ʱ�޿��Ʊ�
typedef struct refavc_DevCtrl_table
{
	DWORD  shOrderNo;					//���
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
	WORD  rule_no;						//������
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
//������ֵ��
typedef struct refavc_SetLim_table
{
	DWORD  shLimitNo;					//Լ������
	DWORD  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fVolUp;						//��ѹ����
	float  fVolLow;						//��ѹ����
	float  fVarUp;						//�޹�����
	float  fVarDown;					//�޹�����
	WORD  fTransNum;					//��ѹ���ɵ��ڴ���
	WORD  fShuntNum;					//�������ɵ��ڴ���
	BYTE  vlpos;						//��ѹ��
	char  szName[64];					//����
	float  fBaseVol;					//��׼��ѹ
}refavc_SetLim_table,*LPrefavc_SetLim_table;
//AVCϵͳĬ�����в���
typedef struct refavc_Avc_RunParam
{
	DWORD  NU;							//���
	CTime  starttime;					//��ʼʱ��
	CTime  endtime;						//��ֹʱ��
	short  type;						//ʱ�����
	char  tyname[64];					//ʱ���������
	float  BaseVol;						//��׼��ѹ
	WORD  capnum;						//���ݿ��ƴ���
	WORD  tfmnum;						//��ѹ�����ƴ���
	float  GateCosup;					//�ؿڹ�������
	float  GateCosdn;					//�ؿڹ�������
	float  FacCosup;					//��վ��������
	float  FacCosdn;					//��վ��������
	float  Volup;						//��ѹ����
	float  Voldn;						//��ѹ����
}refavc_Avc_RunParam,*LPrefavc_Avc_RunParam;
//�豸ң����Ϣ�����
typedef struct refavc_DevYk_table
{
	DWORD  NU;							//�豸���
	char  Name[64];						//�豸����
	BYTE  DevType;						//�豸����
	char  YKType[32];					//ң������
	char  YKName[64];					//ң������
	char  LinkSwitch[64];				//ң�ؿ���
	DWORD  SwitchNU;					//���ر��
	DWORD  UpPoint;						//��/�����
	DWORD  DnPoint;						//��/�����
	BYTE  RevFlag;						//�����ʶ
	short  DelayTime;					//�ӳ�ʱ��
}refavc_DevYk_table,*LPrefavc_DevYk_table;
//ϵͳ���������ݱ�
typedef struct refavc_SysPowerLoss
{
	CTime  LogTime;						//ͳ��ʱ��
	char  OpfType[32];					//�Ż�����
	float  PowerP;						//���й�
	float  PowerQ;						//���޹�
	float  LoadP;						//�����й�
	float  LoadQ;						//�����޹�
	float  ShuntQ;						//�����޹�
	float  LossP;						//�й�����
	float  LossQ;						//�޹�����
	int  CtrlTfm;						//��ѹ��������
	int  CtrlShunt;						//������������
	float  OpfLossP;					//�й�����
	float  OpfLossQ;					//�޹�����
}refavc_SysPowerLoss,*LPrefavc_SysPowerLoss;
//=================�о���===============
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
//������ֵ��
typedef struct studypw_SetLim_table
{
	DWORD  shLimitNo;					//Լ������
	DWORD  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fVolUp;						//��ѹ����
	float  fVolLow;						//��ѹ����
	float  fVarUp;						//�޹�����
	float  fVarDown;					//�޹�����
	WORD  fTransNum;					//��ѹ���ɵ��ڴ���
	WORD  fShuntNum;					//�������ɵ��ڴ���
	BYTE  vlpos;						//��ѹ��
	char  szName[64];					//����
	float  fBaseVol;					//��׼��ѹ
}studypw_SetLim_table,*LPstudypw_SetLim_table;
//=================AVC������Ϣ��===============
//�����������Ϣ��
typedef struct ScadaAVC_PasIsland
{
	DWORD  NU;							//���
	DWORD  IslandID;					//����
	DWORD  Station;						//ƽ�������
	char  StaName[64];					//ƽ�������
	DWORD  GenID;						//ƽ���ID
	char  GenName[64];					//ƽ�����
	DWORD  NodeNum;						//�ڵ���
	BYTE  State;						//������
	BYTE  Obisle;						//�ɹ۲���
	BYTE  BadDataP;						//�й�������
	BYTE  BadDataQ;						//�޹�������
	CTime  SERunTime;					//����ʱ��
	CTime  LogTime;						//����ʱ��
}ScadaAVC_PasIsland,*LPScadaAVC_PasIsland;
//���������Ϣ��
typedef struct ScadaAVC_PasRunInfo
{
	CTime  RunTime;						//����ʱ��
	char  RunInfo[200];					//������Ϣ
	CTime  LogTime;						//����ʱ��
}ScadaAVC_PasRunInfo,*LPScadaAVC_PasRunInfo;
//����SE������
typedef struct ScadaAVC_PasSEParam
{
	BYTE  Run_State;					//��ǰ����״̬
	BYTE  Pause_State;					//��ͣ����״̬
	CTime  RunTime;						//����ʱ��
	BYTE  Conv_State;					//��ǰ����״̬
	float  Measure_Rate;				//ң�⸲����
	DWORD  CycleTime;					//��������(��)
	DWORD  MaxIter;						//����������
	float  EpsP;						//�й���������
	float  EpsQ1;						//�޹���������
	float  SE_Rate;						//��ǰ״���ϸ���
	float  SE_DayRate;					//����״���ϸ���
	float  SE_MonRate;					//��״���ϸ���
	float  SE_YearRate;					//��״���ϸ���
	CTime  LogTime;						//����ʱ��
}ScadaAVC_PasSEParam,*LPScadaAVC_PasSEParam;
//����SE����һ����
typedef struct ScadaAVC_PasSEMeasure
{
	DWORD  Station;						//��վ��
	DWORD  DevID;						//�豸ID
	BYTE  DevType;						//�豸����
	BYTE  MeasType;						//��������
	BYTE  MeasPos;						//����λ��
	char  MeasInfo[64];					//��������
	DWORD  Island;						//����
	float  Meas_value;					//����ֵ
	float  SE_value;					//״̬����ֵ
	float  Err_value;					//���ٷ���
	float  Error;						//���ϸ�����
	float  BadData;						//������
	float  DHisRate;					//�պϸ�ͳ����
	float  MHisRate;					//�ºϸ�ͳ����
}ScadaAVC_PasSEMeasure,*LPScadaAVC_PasSEMeasure;
//AVC��վ��Ϣ��
typedef struct ScadaAVC_AVCStation
{
	DWORD  ID;							//��վID
	char  Name[64];						//��վ����
	DWORD  Zone;						//����ID
	BYTE  CtrlOut;						//�����˳�
	BYTE  AVCCtrl;						//AVC�Զ�����
	DWORD  CtrlID;						//����ʱ�α��
	BYTE  Lock_Sta;						//��վ����״̬
	BYTE  DevLock_Sta;					//��վ�豸����״̬
	float  Vol_rate;					//��ѹ�ϸ���
	float  Loss_P;						//�й�����
	float  Loss_Q;						//�޹�����
	float  Bachup_Q;					//�޹�����
	DWORD  DCtrlNum;					//�ն�����
	DWORD  H24CtrlNum;					//24Сʱ������
	DWORD  MCtrlNum;					//�¶�����
	CTime  LogTime;						//����ʱ��
}ScadaAVC_AVCStation,*LPScadaAVC_AVCStation;
//AVCĸ����Ϣ��
typedef struct ScadaAVC_AVCBus
{
	DWORD  BusID;						//ĸ��ID
	DWORD  StationID;					//��վID
	char  Name[64];						//ĸ������
	DWORD  CtrlID;						//����ʱ�α��
	BYTE  Ctr_Sta;						//�Ƿ����
	BYTE  Cal_Sta;						//�Ƿ�������
	BYTE  Lock_Sta;						//����״̬
	BYTE  IsGate;						//�ؿڱ�ʶ
	float  Volup;						//��ѹ����
	float  Voldn;						//��ѹ����
	float  Cosup;						//��������
	float  Cosdn;						//��������
	float  DVol_rate;					//�յ�ѹ�ϸ���
	float  H24Vol_rate;					//24Сʱ��ѹ�ϸ���
	float  MVol_rate;					//�µ�ѹ�ϸ���
	float  DCos_rate;					//���޹��ϸ���
	float  H24Cos_rate;					//24Сʱ�޹��ϸ���
	float  MCos_rate;					//���޹��ϸ���
	CTime  LogTime;						//����ʱ��
}ScadaAVC_AVCBus,*LPScadaAVC_AVCBus;
//AVC��ѹ����Ϣ��
typedef struct ScadaAVC_AVCTrans
{
	DWORD  ID;							//��ѹ��ID
	DWORD  StationID;					//��վID
	char  Name[64];						//��ѹ������
	DWORD  CtrlID;						//����ʱ��ID
	BYTE  Cal_Sta;						//��������ʶ
	BYTE  Lock_Sta;						//������ʶ
	short  LimitNumber;					//���ƴ�������
	DWORD  UpYXID;						//����ң��ID
	DWORD  UpYKNO;						//����ң�ص��
	DWORD  DnYXID;						//����ң��ID
	DWORD  DnYKNO;						//����ң�ص��
	DWORD  LinkBusID;					//����ĸ��ID
	BYTE  IsGate;						//�ؿڱ�ѹ��
	DWORD  DCtrlNum;					//�տ��ƴ���
	DWORD  DAVCCtrlNum;					//��AVC���ƴ���
	DWORD  DAVCActNum;					//��AVC��������
	DWORD  H24CtrlNum;					//24Сʱ���ƴ���
	DWORD  H24AVCCtrlNum;				//24СʱAVC���ƴ���
	DWORD  H24AVCActNum;				//24СʱAVC��������
	DWORD  MCtrlNum;					//�¿��ƴ���
	DWORD  MAVCCtrlNum;					//��AVC���ƴ���
	DWORD  MAVCActNum;					//��AVC��������
	DWORD  YCtrlNum;					//����ƴ���
	DWORD  YAVCCtrlNum;					//��AVC���ƴ���
	DWORD  YAVCActNum;					//��AVC��������
	CTime  LogTime;						//����ʱ��
}ScadaAVC_AVCTrans,*LPScadaAVC_AVCTrans;
//AVC�޹��豸��Ϣ��
typedef struct ScadaAVC_AVCShunt
{
	DWORD  ID;							//����ID
	DWORD  StationID;					//��վID
	char  Name[64];						//��������
	DWORD  CtrlID;						//����ʱ��ID
	BYTE  Cal_Sta;						//�������
	BYTE  Lock_Sta;						//����״̬
	WORD  LimitNum;						//������������
	DWORD  YXID;						//ң��ID
	DWORD  YKNO;						//ң�ص��
	DWORD  BusID;						//����ĸ��ID
	DWORD  BreakID;						//���ƿ���ID
	DWORD  DCtrlNum;					//�ն�������
	DWORD  DAVCCtrlNum;					//��AVC��������
	DWORD  DAVCActNum;					//��AVC��������
	DWORD  H24CtrlNum;					//24Сʱ��������
	DWORD  H24AVCCtrlNum;				//24СʱAVC��������
	DWORD  H24AVCActNum;				//24СʱAVC��������
	DWORD  MCtrlNum;					//�¶�������
	DWORD  MAVCCtrlNum;					//��AVC��������
	DWORD  MAVCActNum;					//��AVC��������
	DWORD  YCtrlNum;					//�궯������
	DWORD  YAVCCtrlNum;					//��AVC��������
	DWORD  YAVCActNum;					//��AVC��������
	DWORD  DRunTime;					//������ʱ��
	DWORD  H24RunTime;					//24Сʱ����ʱ��
	DWORD  MRunTime;					//������ʱ��
	DWORD  YRunTime;					//������ʱ��
	CTime  LogTime;						//����ʱ��
}ScadaAVC_AVCShunt,*LPScadaAVC_AVCShunt;
//AVC������Ϣ��
typedef struct ScadaAVC_AVCZone
{
	DWORD  ID;							//������
	char  Name[120];					//��������
	float  Vol_rate;					//��ѹ�ϸ���
	float  Cos_rate;					//�޹��ϸ���
	double  Loss_P;						//�й������ܼ�
	double  Loss_Q;						//�޹������ܼ�
	DWORD  Shunt_Ctrl;					//�޹�������
	DWORD  Trans_Ctrl;					//��ѹ��������
	float  H24Vol_rate;					//24Сʱ��ѹ�ϸ���
	float  H24Cos_rate;					//24Сʱ�޹��ϸ���
	float  H24LossP_rate;				//24Сʱ�й�������
	float  H24LossQ_rate;				//24Сʱ�޹�������
	DWORD  H24Shunt_Ctrl;				//24Сʱ�޹�������
	DWORD  H24Trans_Ctrl;				//24Сʱ��ѹ��������
	float  MVol_rate;					//�µ�ѹ�ϸ���
	float  MCos_rate;					//���޹��ϸ���
	float  MLossP_rate;					//���й�������
	float  MLossQ_rate;					//���޹�������
	DWORD  MShunt_Ctrl;					//���޹�������
	DWORD  MTrans_Ctrl;					//�±�ѹ��������
	float  YVol_rate;					//���ѹ�ϸ���
	float  YCos_rate;					//���޹��ϸ���
	float  YLossP_rate;					//���й�������
	float  YLossQ_rate;					//���޹�������
	DWORD  YShunt_Ctrl;					//���޹�������
	DWORD  YTrans_Ctrl;					//���ѹ��������
	CTime  LogTime;						//����ʱ��
}ScadaAVC_AVCZone,*LPScadaAVC_AVCZone;
//AVC���в�����Ϣ��
typedef struct ScadaAVC_AVCCtrRunParam
{
	CTime  DateLog;						//ϵͳ������־ʱ��
	char  SysInfo[24];					//ϵͳ��Ϣ
	char  RunMsg[64];					//������Ϣ
	DWORD  RunNum;						//���д���
	CTime  StartTime;					//����ʱ��
	CTime  AvcTime;						//AVC����ʱ��
	BYTE  Run_Sta;						//����״̬
	BYTE  Auto_Sta;						//�Զ�����״̬
	BYTE  Quit_Sta;						//�����˳�״̬
	BYTE  Cmd_Sta;						//�����·�״̬
	BYTE  Remote_Sta;					//Զ��״̬
	BYTE  Enable_Sta;					//AVC���ñ�־
	WORD  Cycvol;						//��������
	int  Ctrlmtd;						//�����㷨
	BYTE  Ctrl_CP;						//���ݿ���״̬
	BYTE  Ctrl_Cos;						//�����޹�����״̬
	BYTE  Ctrl_Vol;						//�����ѹ����״̬
	WORD  Xfre_space;					//�������ʱ����
	WORD  CPOut_space;					//����Ͷ���˳�ʱ����
	WORD  CPIn_space;					//�����˳�Ͷ��ʱ����
	WORD  Zone_space;					//�������ʱ����
	float  Xfr_overload;				//�������ϵ��
	float  AvcUse_Rate;					//AVC������
	DWORD  AvcClosedTime;				//AVC�ջ�����ʱ��
	DWORD  CtrlNum;						//AVC����ָ����
	DWORD  CtrlSucNum;					//AVC���Ƴɹ���
	float  CtrlSuc_Rate;				//AVC���Ƴɹ���
	DWORD  MaxCtrlNum;					//���ɶ��豸��
	DWORD  CP_RefuseNum;				//�ݿ��ܶ�����
	DWORD  XF_RefuseNum;				//��ѹ���ܶ�����
	float  lossdec;						//�ս�����
}ScadaAVC_AVCCtrRunParam,*LPScadaAVC_AVCCtrRunParam;
//AVCʱ�ζ����
typedef struct ScadaAVC_AVCTimePart
{
	DWORD  ID;							//���
	char  Name[64];						//ʱ������
	float  VUp1;						//��ѹ����1
	float  VDn1;						//��ѹ����1
	float  CP_Num1;						//���ݿɿش���1
	float  XF_Num1;						//��ѹ���ɿش���1
	float  CosUp1;						//������������1
	float  CosDn1;						//������������1
	CTime  Tm1;							//ʱ��1�ָ��
	float  VUp2;						//��ѹ����2
	float  VDn2;						//��ѹ����2
	float  CP_Num2;						//���ݿɿش���2
	float  XF_Num2;						//��ѹ���ɿش���2
	float  CosUp2;						//������������2
	float  CosDn2;						//������������2
	CTime  Tm2;							//ʱ��2�ָ��
	float  VUp3;						//��ѹ����3
	float  VDn3;						//��ѹ����3
	float  CP_Num3;						//���ݿɿش���3
	float  XF_Num3;						//��ѹ���ɿش���3
	float  CosUp3;						//������������3
	float  CosDn3;						//������������3
	CTime  Tm3;							//ʱ��3�ָ��
	float  VUp4;						//��ѹ����4
	float  VDn4;						//��ѹ����4
	float  CP_Num4;						//���ݿɿش���4
	float  XF_Num4;						//��ѹ���ɿش���4
	float  CosUp4;						//������������4
	float  CosDn4;						//������������4
	CTime  Tm4;							//ʱ��4�ָ��
	float  VUp5;						//��ѹ����5
	float  VDn5;						//��ѹ����5
	float  CP_Num5;						//���ݿɿش���5
	float  XF_Num5;						//��ѹ���ɿش���5
	float  CosUp5;						//������������5
	float  CosDn5;						//������������5
	CTime  Tm5;							//ʱ��1�ָ��
	float  VUp6;						//��ѹ����6
	float  VDn6;						//��ѹ����6
	float  CP_Num6;						//���ݿɿش���6
	float  XF_Num6;						//��ѹ���ɿش���6
	float  CosUp6;						//������������6
	float  CosDn6;						//������������6
	CTime  LogTime;						//����ʱ��
}ScadaAVC_AVCTimePart,*LPScadaAVC_AVCTimePart;
//AVC�澯���ͱ�
typedef struct ScadaAVC_AVCWarnType
{
	DWORD  KeyID;						//���
	DWORD  ID;							//�澯ID
	char  TypeName[24];					//�澯����
	short  ot;							//�澯�豸����
	char  txt[32];						//�澯����
	BYTE  qskip;						//��ֹ�澯��־
	BYTE  qlock;						//�������鷽ʽ
	BYTE  qsend;						//�澯���ͱ�־
	int  deltm;							//������ʱʱ��
}ScadaAVC_AVCWarnType,*LPScadaAVC_AVCWarnType;
//AVC�澯�����
typedef struct ScadaAVC_AVCWarnInfo
{
	DWORD  StationID;					//��վID
	DWORD  DevID;						//�豸ID
	DWORD  WarnID;						//�澯����ID
	BYTE  qlock;						//�������鷽ʽ
	BYTE  stat;							//����״̬
	WORD  almtype;						//�澯����
	CTime  ontm;						//����ʱ��
	CTime  offtm;						//����ʱ��
	BYTE  IsDone;						//�����־
}ScadaAVC_AVCWarnInfo,*LPScadaAVC_AVCWarnInfo;
//AVC���������
typedef struct ScadaAVC_AVCRelayInfo
{
	DWORD  StationID;					//��վID
	DWORD  RelayID;						//����ID
	BYTE  state;						//����״̬
	short  qlock;						//�������鷽ʽ
	DWORD  DevId;						//�����豸ID
	CTime  OnTm;						//����ʱ��
	CTime  OffTm;						//����ʱ��
	BYTE  IsDone;						//�����־
}ScadaAVC_AVCRelayInfo,*LPScadaAVC_AVCRelayInfo;
//AVC���Ʋ��Ա�
typedef struct ScadaAVC_AVCCtrlCmd
{
	DWORD  KeyID;						//���
	CTime  LogTime;						//����ʱ��
	char  DevName[64];					//�豸����
	DWORD  StationID;					//��վID
	DWORD  DevID;						//�豸ID
	DWORD  DevSub;						//�����豸�±�
	CTime  IssTm;						//����ʱ��
	CTime  CmdTm;						//ִ��ʱ��
	char  cause_info[80];				//����ԭ��
	char  result_info[80];				//��ʩ
	char  Cmd_info[120];				//��������
	char  CmdType[8];					//��������
	short  CtrlType;					//��������
	char  rslttype[12];					//����״̬
	BYTE  qcheck;						//����ȷ��
	BYTE  qaut;							//�Կ�����
	DWORD  seq;							//������
	DWORD  ZoneID;						//������ID
	DWORD  resp;						//������
}ScadaAVC_AVCCtrlCmd,*LPScadaAVC_AVCCtrlCmd;
//AVC���������
typedef struct ScadaAVC_AVCCtrlZone
{
	DWORD  KeyID;						//���
	char  Name[64];						//��������
	DWORD  VovNum;						//��ѹ����Խ����
	DWORD  QovNum;						//�޹�����Խ����
	float  wloss;						//��������ֵ
	DWORD  NormCp;						//�ɿص�����
	DWORD  NormXf;						//�ɿر�ѹ����
	DWORD  LockCp;						//����������
	DWORD  LockXf;						//������ѹ����
	float  VarIn;						//��Ͷ���޹�������
	float  VarOff;						//δͶ���޹�������
	float  Cosfi;						//�ؿڹ�������
	float  score;						//����״̬�÷�
	CTime  LogTime;						//����ʱ��
}ScadaAVC_AVCCtrlZone,*LPScadaAVC_AVCCtrlZone;
//AVC���򽻻���
typedef struct ScadaAVC_AVCAreaChange
{
	DWORD  KeyID;						//���
	DWORD  objtype;						//��������
	DWORD  objID;						//����ID
	DWORD  objcdID;						//������ID
	float  value;						//����ֵ
	DWORD  datdir;						//���ݴ��䷽��
}ScadaAVC_AVCAreaChange,*LPScadaAVC_AVCAreaChange;
//AVC�����¼���
typedef struct ScadaAVC_AVCCtrlEvent
{
	DWORD  KeyID;						//���
	char  user[24];						//�û���
	CTime  CmdTime;						//����ʱ��
	char  opefunc[64];					//������
	char  text[120];					//��������
}ScadaAVC_AVCCtrlEvent,*LPScadaAVC_AVCCtrlEvent;
//AVC��ѹԽ���¼���
typedef struct ScadaAVC_AVCVoltEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//վ��
	DWORD  BusID;						//ĸ��ID
	char  BusName[64];					//ĸ������
	float  val;							//��ѹֵ
	float  limit;						//��ѹ��ֵ
	CTime  EventTime;					//�¼�ʱ��
}ScadaAVC_AVCVoltEvent,*LPScadaAVC_AVCVoltEvent;
//AVC��ѹ�������¼���
typedef struct ScadaAVC_AVCTransEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//��վ����
	DWORD  TransID;						//��ѹ��ID
	char  TransName[64];				//��ѹ������
	DWORD  WindID;						//��������ID
	CTime  Optime;						//����ʱ��
	WORD  pretap;						//����ǰ��λ
	WORD  afttap;						//������λ
	float  preVol;						//����ǰ��ѹ
	float  aftVol;						//�������ѹ
	char  opttype[8];					//��������
	BYTE  qAVC;							//AVC�����־
	float  preHVol;						//����ǰ��ѹ��ѹ
	float  preHP;						//����ǰ��ѹ�й�
	float  preHQ;						//����ǰ��ѹ�޹�
	float  preMVol;						//����ǰ��ѹ��ѹ
	float  preMP;						//����ǰ��ѹ�й�
	float  preMQ;						//����ǰ��ѹ�޹�
	float  preLVol;						//����ǰ��ѹ��ѹ
	float  preLP;						//����ǰ��ѹ�й�
	float  preLQ;						//����ǰ��ѹ�޹�
	float  aftHVol;						//���ƺ��ѹ��ѹ
	float  aftHP;						//���ƺ��ѹ�й�
	float  aftHQ;						//���ƺ��ѹ�޹�
	float  aftMVol;						//���ƺ���ѹ��ѹ
	float  aftMP;						//���ƺ���ѹ�й�
	float  aftMQ;						//���ƺ���ѹ�޹�
	float  aftLVol;						//���ƺ��ѹ��ѹ
	float  aftLP;						//���ƺ��ѹ�й�
	float  aftLQ;						//���ƺ��ѹ�޹�
	CTime  EventTime;					//�¼�ʱ��
}ScadaAVC_AVCTransEvent,*LPScadaAVC_AVCTransEvent;
//AVC���ݿ����¼���
typedef struct ScadaAVC_AVCShuntEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//��վ����
	DWORD  ShuntID;						//����ID
	char  ShuntName[64];				//��������
	CTime  opttime;						//����ʱ��
	char  opttype[8];					//��������
	BYTE  qavc;							//AVCָ���־
	BYTE  qopen;						//����������״̬
	float  preVol;						//����ǰ��ѹ
	float  aftVol;						//�������ѹ
	CTime  EventTime;					//�¼�ʱ��
}ScadaAVC_AVCShuntEvent,*LPScadaAVC_AVCShuntEvent;
//AVCͳ����Ϣ��
typedef struct ScadaAVC_AVCStateInfo
{
	DWORD  KeyID;						//���
	DWORD  DevID;						//�豸ID
	DWORD  StationID;					//��վID
	char  Name[64];						//�豸����
	DWORD  numall;						//�ն�������
	DWORD  numavc;						//�ճɹ�����
	DWORD  numorder;					//���������
	DWORD  numfail;						//��ʧ�ܴ���
	float  sucrate;						//�ճɹ���
	CTime  timelog;						//����ʱ��
}ScadaAVC_AVCStateInfo,*LPScadaAVC_AVCStateInfo;
//����վ��
typedef struct ScadaAVC_PasStation
{
	DWORD  ID;							//��վID
	char  Name[64];						//��վ����
	DWORD  IsLand;						//����
	CTime  SERunTime;					//״������ʱ��
	BYTE  Error_sta;					//���ϸ������־
	BYTE  Bad_sta;						//�����ݱ�־
	float  Se_rate;						//����ϸ���
}ScadaAVC_PasStation,*LPScadaAVC_PasStation;
//AVC���в�����
typedef struct ScadaAVC_AVCRunParam
{
	DWORD  ID;							//���
	CTime  srttm;						//��ʼʱ��
	CTime  endtm;						//����ʱ��
	WORD  Type;							//ʱ������
	char  Msg[32];						//ʱ������
	WORD  CPNum;						//���ݿ��ô���
	WORD  XfrNum;						//��ѹ�����ô���
	float  CosUp;						//�ؿڹ�����������
	float  CosDn;						//�ؿڹ�����������
	float  SCosUp;						//��վ������������
	float  SCosDn;						//��վ������������
	float  V6Up;						//6KV����
	float  V6Dn;						//6KV����
	float  V10Up;						//10KV����
	float  V10Dn;						//10KV����
	float  V35Up;						//35KV����
	float  V35Dn;						//35KV����
	float  V110Up;						//110KV����
	float  V110Dn;						//110KV����
	float  V220Up;						//220KV����
	float  V220Dn;						//220KV����
	float  V330Up;						//330KV����
	float  V330Dn;						//330KV����
	CTime  LogTime;						//����ʱ��
}ScadaAVC_AVCRunParam,*LPScadaAVC_AVCRunParam;
//=================�������ݿ�===============
//վ
typedef struct ProcessData_Station
{
	DWORD  NU;							//վ��
	char  Name[64];						//վ��
	DWORD  zoneNU;						//��������
	float  VL;							//��ѹ�ȼ�
	int  Type;							//��վ����
	DWORD  CtrlType;					//�������Ͷ���
	short  SeData;						//״̬���ƿ�������
	short  CtrlNum;						//�Ż���������
	WORD  CtrlSta;						//����״̬��λ��ע
}ProcessData_Station,*LPProcessData_Station;
//����
typedef struct ProcessData_Zone
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
}ProcessData_Zone,*LPProcessData_Zone;
//�����
typedef struct ProcessData_Gen
{
	DWORD  NU;							//�������
	char  Name[64];						//�������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  MaxP;						//�й�����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	DWORD  Node;						//�ڵ�
	float  VL;							//��ѹ�ȼ�
	BYTE  Isbalance;					//ƽ���
	WORD  Island;						//������
	float  P;							//�й�����
	float  Q;							//�޹�����
	float  SeP;							//�й�����
	float  SeQ;							//�޹�����
	float  OpfP;						//�й�����
	float  OpfQ;						//�޹�����
}ProcessData_Gen,*LPProcessData_Gen;
//ĸ��
typedef struct ProcessData_Bus
{
	DWORD  NU;							//ĸ�߱��
	char  Name[64];						//ĸ������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  MaxV;						//��ѹ����
	float  MinV;						//��ѹ����
	float  Vl;							//��ѹ�ȼ�
	float  V;							//�ڵ��ѹ(pu)
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	DWORD  Node;						//�ڵ�
	DWORD  cNode;						//�ϲ��ڵ�
	WORD  Island;						//������
	float  Vb;							//��ѹ
	float  deg;							//���
	float  SeVb;						//��ѹ
	float  Sedeg;						//���
	float  OpfVb;						//��ѹ
	float  Opfdeg;						//���
	WORD  CtrlSta;						//����״̬��λ��ע
}ProcessData_Bus,*LPProcessData_Bus;
//����
typedef struct ProcessData_Load
{
	DWORD  NU;							//���ɱ��
	char  Name[64];						//��������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	DWORD  Node;						//�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
	WORD  Island;						//������
	float  P;							//�й�����
	float  Q;							//�޹�����
	float  I;							//����
	float  SeP;							//�й�����
	float  SeQ;							//�޹�����
	float  OpfP;						//�й�����
	float  OpfQ;						//�޹�����
}ProcessData_Load,*LPProcessData_Load;
//������
typedef struct ProcessData_Line
{
	DWORD  NU;							//�����߱��
	char  Name[64];						//����������
	DWORD  Stationf;					//�׶�վ
	DWORD  Stationt;					//ĩ��վ
	float  MaxP;						//�й�����
	float  VL;							//��ѹ�ȼ�
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	DWORD  NodeF;						//�׽ڵ�
	DWORD  NodeT;						//ĩ�ڵ�
	BYTE  EquiSta;						//��ֵ״̬
	WORD  Island;						//������
	float  Pf;							//ʼ���й�
	float  Qf;							//ʼ���޹�
	float  Pt;							//ĩ���й�
	float  Qt;							//ĩ���޹�
	float  I;							//����ֵ
	float  SePf;						//ʼ���й�
	float  SeQf;						//ʼ���޹�
	float  SePt;						//ĩ���й�
	float  SeQt;						//ĩ���޹�
	float  SeI;							//����ֵ
	float  OpfPf;						//ʼ���й�
	float  OpfQf;						//ʼ���޹�
	float  OpfPt;						//ĩ���й�
	float  OpfQt;						//ĩ���޹�
	float  OpfI;						//����ֵ
}ProcessData_Line,*LPProcessData_Line;
//2�����ѹ��
typedef struct ProcessData_Tfm1
{
	DWORD  NU;							//2�Ʊ���
	char  Name[64];						//2�Ʊ���
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  tap;							//��ѹ���ֽ�ͷ
	float  Pmax;						//��ѹ������й�(����)
	float  P;							//��ѹ���й�
	float  Q;							//��ѹ���޹�
	float  I;							//��ѹ�����
	float  P2;							//��ѹ���й�
	float  Q2;							//��ѹ���޹�
	float  I2;							//��ѹ�����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	DWORD  NodeH;						//��ѹ�ڵ�
	DWORD  NodeL;						//��ѹ�ڵ�
	float  VL;							//��ѹ�ȼ�
	BYTE  IsGate;						//�ؿ�
	int  Island;						//������
	float  CosDn;						//������������
	float  CosUp;						//������������
	float  SeP;							//��ѹ���й�
	float  SeQ;							//��ѹ���޹�
	float  SeP2;						//��ѹ���й�
	float  SeQ2;						//��ѹ���޹�
	float  Setap;						//��ѹ���ֽ�ͷ
	float  OpfP;						//��ѹ���й�
	float  OpfQ;						//��ѹ���޹�
	float  OpfP2;						//��ѹ���й�
	float  OpfQ2;						//��ѹ���޹�
	float  Opftap;						//��ѹ���ֽ�ͷ
	WORD  CtrlSta;						//����״̬��λ��ע
}ProcessData_Tfm1,*LPProcessData_Tfm1;
//3�����ѹ��
typedef struct ProcessData_Tfm2
{
	DWORD  NU;							//3�Ʊ���
	char  Name[64];						//3�Ʊ���
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  TapH;						//��ѹ���ֽ�ͷ
	float  TapM;						//�ж˷ֽ�ͷλ��
	float  Pmax;						//��ѹ������й�(����)
	float  P;							//��ѹ���й�
	float  Q;							//��ѹ���޹�
	float  I;							//��ѹ�����
	float  P2;							//��ѹ���й�
	float  Q2;							//��ѹ���޹�
	float  I2;							//��ѹ�����
	float  P3;							//��ѹ���й�
	float  Q3;							//��ѹ���޹�
	float  I3;							//��ѹ�����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  NodeH;						//��ѹ�ڵ�
	DWORD  NodeM;						//��ѹ�ڵ�
	DWORD  NodeL;						//��ѹ�ڵ�
	float  VL;							//��ѹ�ȼ�
	BYTE  IsGate;						//�ؿ�
	int  Island;						//������
	float  CosDn;						//������������
	float  CosUp;						//������������
	float  SeP;							//��ѹ���й�
	float  SeQ;							//��ѹ���޹�
	float  SeP2;						//��ѹ���й�
	float  SeQ2;						//��ѹ���޹�
	float  SeP3;						//��ѹ���й�
	float  SeQ3;						//��ѹ���޹�
	float  SeTapH;						//��ѹ���ֽ�ͷ
	float  SeTapM;						//�ж˷ֽ�ͷλ��
	float  OpfP;						//��ѹ���й�
	float  OpfQ;						//��ѹ���޹�
	float  OpfP2;						//��ѹ���й�
	float  OpfQ2;						//��ѹ���޹�
	float  OpfP3;						//��ѹ���й�
	float  OpfQ3;						//��ѹ���޹�
	float  OpfTapH;						//��ѹ���ֽ�ͷ
	float  OpfTapM;						//�ж˷ֽ�ͷλ��
	WORD  CtrlSta;						//����״̬��λ��ע
}ProcessData_Tfm2,*LPProcessData_Tfm2;
//����
typedef struct ProcessData_Shunt
{
	DWORD  NU;							//�����豸���
	char  Name[64];						//�����豸����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  RVol;						//���ѹ
	float  Qmax;						//����޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
	WORD  Island;						//������
	float  Q;							//Ͷ���޹�
	float  I;							//����
	float  SeQ;							//Ͷ���޹�
	float  SeI;							//����
	float  OpfQ;						//Ͷ���޹�
	float  OpfI;						//����
	WORD  CtrlSta;						//����״̬��λ��ע
}ProcessData_Shunt,*LPProcessData_Shunt;
//�翹
typedef struct ProcessData_Sreact
{
	DWORD  NU;							//�翹�����
	char  Name[64];						//�翹����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node1;						//�ڵ�1
	DWORD  Node2;						//�ڵ�2
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
	float  RVol;						//���ѹ
	float  Qmax;						//����޹����
	float  Q;							//Ͷ��翹
	float  I;							//����
	float  SeQ;							//Ͷ��翹
	float  SeI;							//����
	float  OpfQ;						//Ͷ��翹
	float  OpfI;						//����
	WORD  CtrlSta;						//����״̬��λ��ע
}ProcessData_Sreact,*LPProcessData_Sreact;
//��ѹ������
typedef struct ProcessData_Winding
{
	DWORD  NU;							//������
	char  Name[64];						//����
	char  ID[24];						//�����ʶ
	char  TID[24];						//��ѹ����ʶ
	float  baseKV;						//��׼��ѹ
	float  ratedKV;						//���ѹ
	float  ratedMVA;					//�����
	float  fR;							//����
	float  fX;							//�翹
	float  fB;							//����
	BYTE  Type;							//��������
	BYTE  Tmax;							//���λ
	BYTE  Tmin;							//��С��λ
	BYTE  Tnor;							//������λ
	float  step;						//��λ����
	float  P;							//�й�����
	float  Q;							//�޹�����
	short  Tap;							//��λ
	float  SeP;							//�й�����
	float  SeQ;							//�޹�����
	short  SeTap;						//��λ
	float  OpfP;						//�й�����
	float  OpfQ;						//�޹�����
	short  OpfTap;						//��λ
}ProcessData_Winding,*LPProcessData_Winding;
//ϵͳ���������ݱ�
typedef struct ProcessData_SysPowerLoss
{
	CTime  LogTime;						//ͳ��ʱ��
	BYTE  IsToDay;						//�Ƿ�������
	float  PowerP;						//���й�
	float  PowerQ;						//���޹�
	float  LoadP;						//�����й�
	float  LoadQ;						//�����޹�
	float  ShuntQ;						//�����޹�
	float  LossP;						//�й�����
	float  LossQ;						//�޹�����
	float  OpfPowerP;					//���й�
	float  OpfPowerQ;					//���޹�
	float  OpfLoadP;					//�����й�
	float  OpfLoadQ;					//�����޹�
	float  OpfShuntQ;					//�����޹�
	float  OpfLossP;					//�й�����
	float  OpfLossQ;					//�޹�����
}ProcessData_SysPowerLoss,*LPProcessData_SysPowerLoss;
//���ص�բ
typedef struct ProcessData_Switch
{
	DWORD  NU;							//���ر��
	char  Name[64];						//��������
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
}ProcessData_Switch,*LPProcessData_Switch;
//���������
typedef struct ProcessData_opfCmd
{
	DWORD  tmOrder;						//���
	DWORD  shFacNo;						//����
	BYTE  byType;						//�豸����
	DWORD  shDeviceNo;					//�豸���
	char  szFacName[64];				//��վ��
	char  szDevName[64];				//�豸��
	DWORD  SwitchNU;					//���ر��
	char  YKSwitch[64];					//ң�ؿ���
	int  YKPoint;						//ң�ص��
	BYTE  byCommand;					//�������/�Ͻ���
	float  shCurTap;					//��ǰ��λ
	float  shEndTap;					//Ŀ�굵λ
	BYTE  byStatus;						//����״̬
	CTime  CreatTime;					//����ʱ��
	CTime  YKTime;						//����ʱ��
	char  YKInfo[64];					//������Ϣ
	BYTE  YKState;						//ң�ر�ʶ
	char  CtrlType[16];					//���Ʒ���
}ProcessData_opfCmd,*LPProcessData_opfCmd;
//=================AVC���ۿ�===============
//����SE������
typedef struct AssessAVC_PasSEParam
{
	CTime  RunTime;						//����ʱ��
	BYTE  Conv_State;					//��ǰ����״̬
	float  Measure_Rate;				//ң�⸲����
	float  SE_Rate;						//��ǰ״���ϸ���
	char  RunInfo[86];					//������Ϣ
}AssessAVC_PasSEParam,*LPAssessAVC_PasSEParam;
//AVC��վ��Ϣ��
typedef struct AssessAVC_AVCStation
{
	DWORD  ID;							//��վID
	char  Name[64];						//��վ����
	DWORD  Zone;						//����ID
	BYTE  CtrlOut;						//�����˳�
	BYTE  AVCCtrl;						//AVC�Զ�����
	DWORD  CtrlID;						//����ʱ�α��
	WORD  Lock_Num;						//��վ���������ۼ�
	DWORD  DevLock_Num;					//��վ�豸���������ۼ�
	float  VL;							//��ѹ�ȼ�
	float  DVolRate;					//���յ�ѹ�ϸ���
	float  DCosRate;					//���չ��������ϸ���
	DWORD  DVAll_Time;					//�յ�ѹ��ʱ��
	DWORD  DVOut_Time;					//�յ�ѹԽ��ʱ��
	DWORD  DCAll_Time;					//�չ�����ʱ��
	DWORD  DCOut_Time;					//�չ���Խ��ʱ��
	float  H24VolRate;					//24Сʱ��ѹ�ϸ���
	float  H24CosRate;					//24Сʱ���ʺϸ���
	DWORD  H24VAll_Time;				//�յ�ѹ��ʱ��
	DWORD  H24VOut_Time;				//�յ�ѹԽ��ʱ��
	DWORD  H24CAll_Time;				//�չ�����ʱ��
	DWORD  H24COut_Time;				//�չ���Խ��ʱ��
	DWORD  DActNum;						//�ն�����
	DWORD  DAvcCtrlNum;					//��AVC������
	DWORD  DAvcActNum;					//��AVC������
	DWORD  H24ActNum;					//24Сʱ������
	DWORD  H24AvcCtrlNum;				//��AVC������
	DWORD  H24AvcActNum;				//��AVC������
	CTime  LogTime;						//����ʱ��
}AssessAVC_AVCStation,*LPAssessAVC_AVCStation;
//AVCĸ����Ϣ��
typedef struct AssessAVC_AVCBus
{
	DWORD  BusID;						//ĸ��ID
	DWORD  ZoneID;						//����ID
	DWORD  StationID;					//��վID
	char  Name[64];						//ĸ������
	float  VL;							//��ѹ�ȼ�
	DWORD  CtrlID;						//����ʱ�α��
	BYTE  IsGate;						//�ؿڱ�ʶ
	BYTE  Run_Sta;						//����״̬
	BYTE  Ctr_Sta;						//�Ƿ����
	BYTE  Cal_Sta;						//�Ƿ�������
	BYTE  Limit_Sta;					//Խ��״̬
	BYTE  Lock_Sta;						//����״̬
	float  Volup;						//��ѹ����
	float  Voldn;						//��ѹ����
	float  Cosup;						//��������
	float  Cosdn;						//��������
	WORD  DLock_Num;					//���������ۼ�
	WORD  DLock_Time;					//���������ۼ�ʱ��
	float  DVolmax;						//�յ�ѹ
	float  DVolmin;						//�յ�ѹ
	float  DLoadP;						//ĸ�߸����й�
	float  DLoadQ;						//ĸ�߸����޹�
	WORD  DVolOutNum;					//Խ�޴���
	WORD  DVolEvent;					//Խ���¼���
	WORD  DCtrlEvent;					//�����¼���
	float  DVol_rate;					//�յ�ѹ�ϸ���
	DWORD  DAll_Time;					//����ʱ��
	DWORD  DOut_Time;					//��Խ��ʱ��
	WORD  H24Lock_Num;					//���������ۼ�
	WORD  H24Lock_Time;					//���������ۼ�ʱ��
	float  H24Volmax;					//�յ�ѹ
	float  H24Volmin;					//�յ�ѹ
	int  H24VolEvent;					//Խ���¼���
	int  H24CtrlEvent;					//�����¼���
	float  H24Vol_rate;					//24Сʱ��ѹ�ϸ���
	DWORD  H24All_Time;					//24Сʱ��ʱ��
	DWORD  H24Out_Time;					//24СʱԽ��ʱ��
	CTime  LogTime;						//��ǰ����ʱ��
}AssessAVC_AVCBus,*LPAssessAVC_AVCBus;
//AVC��ѹ����Ϣ��
typedef struct AssessAVC_AVCTrans
{
	DWORD  ID;							//��ѹ��ID
	DWORD  ZoneID;						//����ID
	DWORD  StationID;					//��վID
	char  Name[64];						//��ѹ������
	DWORD  CtrlID;						//����ʱ��ID
	BYTE  Run_Sta;						//����״̬
	BYTE  Ctrl_Sta;						//������Ʊ�ʶ
	BYTE  Lock_Sta;						//����״̬
	BYTE  Limit_Sta;					//Խ��״̬
	DWORD  BusHID;						//��ѹĸ��ID
	DWORD  BusMID;						//��ѹĸ��ID
	DWORD  BusLID;						//��ѹĸ��ID
	BYTE  IsGate;						//�ؿڱ�ѹ��
	float  Cosup;						//��������
	float  Cosdn;						//��������
	WORD  DCtrlLimitNum;				//������ֵ����
	WORD  DTimeLimitNum;				//��ǰʱ����ֵ����
	float  DHiP;						//��ѹ�й�
	float  DHiQ;						//��ѹ�޹�
	float  DMaxS;						//����߸���
	float  DCosRate;					//���������ϸ���
	WORD  DLock_Num;					//��������
	WORD  DLock_Time;					//���������ۼ�ʱ��
	float  DAll_Time;					//��ʱ��
	float  DOut_Time;					//��ʱ��
	DWORD  DActNum;						//�տ��ƴ���
	DWORD  DAVCCtrlNum;					//��AVC���ƴ���
	DWORD  DAVCActNum;					//��AVC��������
	WORD  H24CtrlLimit;					//�տ�����ֵ����
	float  H24CosRate;					//24Сʱ���������ϸ���
	float  H24MaxS;						//����߸���
	float  H24All_Time;					//��ʱ��
	float  H24Out_Time;					//��ʱ��
	WORD  H24Lock_Num;					//��������
	WORD  H24Lock_Time;					//���������ۼ�ʱ��
	DWORD  H24ActNum;					//24Сʱ���ƴ���
	DWORD  H24AVCCtrlNum;				//24СʱAVC���ƴ���
	DWORD  H24AVCActNum;				//24СʱAVC��������
	CTime  LogTime;						//����ʱ��
}AssessAVC_AVCTrans,*LPAssessAVC_AVCTrans;
//AVC�޹��豸��Ϣ��
typedef struct AssessAVC_AVCShunt
{
	DWORD  ID;							//����ID
	DWORD  ZoneID;						//��վID
	DWORD  StationID;					//��վID
	char  Name[64];						//��������
	float  VL;							//��ѹ�ȼ�
	DWORD  CtrlID;						//����ʱ��ID
	BYTE  Run_Sta;						//����״̬
	BYTE  Ctrl_Sta;						//����״̬
	BYTE  Lock_Sta;						//����״̬
	DWORD  BreakerID;					//����ID
	DWORD  BusID;						//����ĸ��ID
	DWORD  BreakID;						//���ƿ���ID
	WORD  DayLimitNum;					//������������
	WORD  TimeLimitNum;					//ʱ�����ƴ���
	BYTE  DLock_Num;					//��������
	BYTE  DLock_Time;					//����ʱ��
	DWORD  DActNum;						//�ն�������
	DWORD  DAVCCtrlNum;					//��AVC��������
	DWORD  DAVCActNum;					//��AVC��������
	DWORD  DRunTime;					//������ʱ��
	float  DAll_Time;					//��ʱ��
	DWORD  H24ActNum;					//24Сʱ��������
	DWORD  H24AVCCtrlNum;				//24СʱAVC��������
	DWORD  H24AVCActNum;				//24СʱAVC��������
	WORD  H24LimitNum;					//������������
	DWORD  H24RunTime;					//24Сʱ����ʱ��
	float  H24All_Time;					//��ʱ��
	BYTE  H24Lock_Num;					//��������
	BYTE  H24Lock_Time;					//����ʱ��
	CTime  LogTime;						//����ʱ��
}AssessAVC_AVCShunt,*LPAssessAVC_AVCShunt;
//AVCϵͳͳ�Ʊ�
typedef struct AssessAVC_AVCSystem
{
	CTime  SysTime;						//ͳ��ʱ��
	char  Name[120];					//��������
	BYTE  AVCAll_Time;					//AVC������ʱ��
	BYTE  AVCOut_Time;					//AVC�˳�ʱ��
	BYTE  AVCOpen_Time;					//AVC�����˳�ʱ��
	float  AvcUse_Rate;					//AVC������
	DWORD  Vol_AllTime;					//��ѹ��ʱ��
	DWORD  Vol_OutTime;					//��ѹԽ��ʱ��
	DWORD  Bus_Num;						//ĸ������
	DWORD  OutBus_Num;					//Խ��ĸ������
	float  Vol_rate;					//��ѹ�ϸ���
	DWORD  Cos_AllTime;					//�޹���ʱ��
	DWORD  Cos_OutTime;					//�޹�Խ��ʱ��
	DWORD  Trans_Num;					//�޹��������
	DWORD  OutCos_Num;					//�޹�Խ������
	float  Cos_rate;					//�޹��ϸ���
	float  Loss_P;						//��ǰ�й������ܼ�
	float  Loss_Q;						//��ǰ�޹������ܼ�
	float  Gen_P;						//������й��ܼ�
	float  Gen_Q;						//������޹��ܼ�
	float  Load_P;						//�����й��ܼ�
	float  Load_Q;						//�����޹��ܼ�
	float  Trans_P;						//��ѹ���й��ܼ�
	float  Trans_Q;						//��ѹ���޹��ܼ�
	float  Line_P;						//��·�й��ܼ�
	float  Line_Q;						//��·�޹��ܼ�
	float  lossdec;						//AVC�ս�����
	DWORD  AVCLock_Num;					//AVC����������
	DWORD  DevLock_Num;					//�豸��������
	DWORD  ScadaEventNum;				//Խ���¼���
	DWORD  AVCEventNum;					//AVCԽ���¼���
	DWORD  AVCCtrlEveNum;				//AVC�����¼���
	DWORD  Shunt_Act;					//�޹�������
	DWORD  Trans_Act;					//��ѹ��������
	DWORD  AVCCtrl_Num;					//AVC��������
	DWORD  CtrlFail_Num;				//����ʧ������
	DWORD  AVCCP_CtrlNum;				//AVC�ݿ����ƴ���
	DWORD  AVCXF_CtrlNum;				//��ѹ�����ƴ���
	DWORD  CP_RefuseNum;				//�ݿ��ܶ�����
	DWORD  XF_RefuseNum;				//��ѹ���ܶ�����
	float  H24Vol_rate;					//��ѹ�ϸ���
	float  H24Cos_rate;					//�޹��ϸ���
	float  H24lossdec;					//AVC�ս�����
	DWORD  H24Shunt_Ctrl;				//�޹�������
	DWORD  H24Trans_Ctrl;				//��ѹ��������
	DWORD  H24Ctrl_Num;					//��������
	DWORD  H24Fail_Num;					//����ʧ������
	DWORD  H24CP_RefNum;				//�ݿ��ܶ�����
	DWORD  H24XF_RefNum;				//��ѹ���ܶ�����
	float  H24AvcUse_Rate;				//AVC������
	BYTE  H24AVC_Time;					//AVC������ʱ��
	BYTE  H24Open_Time;					//AVC�����˳�ʱ��
	CTime  LogTime;						//����ʱ��
}AssessAVC_AVCSystem,*LPAssessAVC_AVCSystem;
//AVC�澯�����
typedef struct AssessAVC_AVCWarnInfo
{
	DWORD  StationID;					//��վID
	DWORD  DevID;						//�豸ID
	DWORD  WarnID;						//�澯ID
	BYTE  WarnType;						//�澯����/����
	char  WarnInfo[32];					//�澯��������
	BYTE  lockstat;						//����״̬
	CTime  ontm;						//����ʱ��
	CTime  offtm;						//����ʱ��
}AssessAVC_AVCWarnInfo,*LPAssessAVC_AVCWarnInfo;
//AVC���Ʋ��Ա�
typedef struct AssessAVC_AVCCtrlCmd
{
	DWORD  KeyID;						//���
	CTime  LogTime;						//����ʱ��
	char  DevName[64];					//�豸����
	DWORD  StationID;					//��վID
	DWORD  DevID;						//�豸ID
	DWORD  DevSub;						//�����豸�±�
	CTime  IssTm;						//����ʱ��
	CTime  CmdTm;						//ִ��ʱ��
	char  cause_info[80];				//����ԭ��
	char  result_info[80];				//��ʩ
	char  Cmd_info[120];				//��������
	char  CmdType[8];					//��������
	short  CtrlType;					//��������
	char  rslttype[12];					//����״̬
	BYTE  qcheck;						//����ȷ��
	BYTE  qaut;							//�Կ�����
	DWORD  seq;							//������
	DWORD  ZoneID;						//������ID
	DWORD  resp;						//������
}AssessAVC_AVCCtrlCmd,*LPAssessAVC_AVCCtrlCmd;
//AVC���������
typedef struct AssessAVC_AVCCtrlZone
{
	DWORD  KeyID;						//���
	char  Name[64];						//��������
	DWORD  VovNum;						//��ѹ����Խ����
	DWORD  QovNum;						//�޹�����Խ����
	float  wloss;						//��������ֵ
	DWORD  NormCp;						//�ɿص�����
	DWORD  NormXf;						//�ɿر�ѹ����
	DWORD  LockCp;						//����������
	DWORD  LockXf;						//������ѹ����
	float  VarIn;						//��Ͷ���޹�������
	float  VarOff;						//δͶ���޹�������
	float  Cosfi;						//�ؿڹ�������
	float  score;						//����״̬�÷�
}AssessAVC_AVCCtrlZone,*LPAssessAVC_AVCCtrlZone;
//AVC�����¼���
typedef struct AssessAVC_AVCCtrlEvent
{
	DWORD  KeyID;						//���
	char  user[24];						//�û���
	CTime  CmdTime;						//����ʱ��
	char  opefunc[64];					//������
	char  text[120];					//��������
}AssessAVC_AVCCtrlEvent,*LPAssessAVC_AVCCtrlEvent;
//AVCԽ���¼���
typedef struct AssessAVC_AVCVoltEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//վ��
	BYTE  DevType;						//�豸����
	DWORD  DevID;						//�豸ID
	char  DevName[64];					//�豸����
	float  val;							//��ֵ
	float  limitdn;						//��ֵ
	float  limitup;						//��ֵ
	BYTE  ByScada;						//�¼���Դ1��Դ��SCADA
	CTime  EventTime;					//�¼�ʱ��
	CTime  OffTime;						//����ʱ��
	DWORD  CmdID;						//�����¼�ID
}AssessAVC_AVCVoltEvent,*LPAssessAVC_AVCVoltEvent;
//AVC��ѹ�������¼���
typedef struct AssessAVC_AVCTransEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//��վ����
	DWORD  TransID;						//��ѹ��ID
	char  TransName[64];				//��ѹ������
	DWORD  WindID;						//��������ID
	CTime  Optime;						//����ʱ��
	WORD  pretap;						//����ǰ��λ
	WORD  afttap;						//������λ
	float  preVol;						//����ǰ��ѹ
	float  aftVol;						//�������ѹ
	char  opttype[20];					//��������
	BYTE  qAVC;							//AVC�����־
	float  preHVol;						//����ǰ��ѹ��ѹ
	float  preHP;						//����ǰ��ѹ�й�
	float  preHQ;						//����ǰ��ѹ�޹�
	float  preMVol;						//����ǰ��ѹ��ѹ
	float  preMP;						//����ǰ��ѹ�й�
	float  preMQ;						//����ǰ��ѹ�޹�
	float  preLVol;						//����ǰ��ѹ��ѹ
	float  preLP;						//����ǰ��ѹ�й�
	float  preLQ;						//����ǰ��ѹ�޹�
	float  aftHVol;						//���ƺ��ѹ��ѹ
	float  aftHP;						//���ƺ��ѹ�й�
	float  aftHQ;						//���ƺ��ѹ�޹�
	float  aftMVol;						//���ƺ���ѹ��ѹ
	float  aftMP;						//���ƺ���ѹ�й�
	float  aftMQ;						//���ƺ���ѹ�޹�
	float  aftLVol;						//���ƺ��ѹ��ѹ
	float  aftLP;						//���ƺ��ѹ�й�
	float  aftLQ;						//���ƺ��ѹ�޹�
	BYTE  ByScada;						//�¼���Դ1��Դ��SCADA
	CTime  EventTime;					//�¼�ʱ��
	DWORD  CmdID;						//�����¼�ID
}AssessAVC_AVCTransEvent,*LPAssessAVC_AVCTransEvent;
//AVC���ݿ����¼���
typedef struct AssessAVC_AVCShuntEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//��վ����
	DWORD  ShuntID;						//����ID
	char  ShuntName[64];				//��������
	CTime  opttime;						//����ʱ��
	char  opttype[20];					//��������
	BYTE  qavc;							//AVCָ���־
	BYTE  qopen;						//����������״̬
	float  preVol;						//����ǰ��ѹ
	float  aftVol;						//�������ѹ
	BYTE  ByScada;						//�¼���Դ1��Դ��SCADA
	CTime  EventTime;					//�¼�ʱ��
	DWORD  CmdID;						//�����¼�ID
}AssessAVC_AVCShuntEvent,*LPAssessAVC_AVCShuntEvent;
//AVC���в�����
typedef struct AssessAVC_AVCRunParam
{
	DWORD  ID;							//���
	CTime  srttm;						//��ʼʱ��
	CTime  endtm;						//����ʱ��
	WORD  Type;							//ʱ������
	char  Msg[32];						//ʱ������
	WORD  CPNum;						//���ݿ��ô���
	WORD  XfrNum;						//��ѹ�����ô���
	float  CosUp;						//�ؿڹ�����������
	float  CosDn;						//�ؿڹ�����������
	float  SCosUp;						//��վ������������
	float  SCosDn;						//��վ������������
	float  V6Up;						//6KV����
	float  V6Dn;						//6KV����
	float  V10Up;						//10KV����
	float  V10Dn;						//10KV����
	float  V35Up;						//35KV����
	float  V35Dn;						//35KV����
	float  V110Up;						//110KV����
	float  V110Dn;						//110KV����
	float  V220Up;						//220KV����
	float  V220Dn;						//220KV����
	float  V330Up;						//330KV����
	float  V330Dn;						//330KV����
	CTime  LogTime;						//����ʱ��
}AssessAVC_AVCRunParam,*LPAssessAVC_AVCRunParam;
//AVCʱ�ζ����
typedef struct AssessAVC_AVCTimePart
{
	DWORD  ID;							//���
	char  Name[64];						//ʱ������
	float  VUp1;						//��ѹ����1
	float  VDn1;						//��ѹ����1
	float  CP_Num1;						//���ݿɿش���1
	float  XF_Num1;						//��ѹ���ɿش���1
	float  CosUp1;						//������������1
	float  CosDn1;						//������������1
	CTime  Tm1;							//ʱ��1�ָ��
	float  VUp2;						//��ѹ����2
	float  VDn2;						//��ѹ����2
	float  CP_Num2;						//���ݿɿش���2
	float  XF_Num2;						//��ѹ���ɿش���2
	float  CosUp2;						//������������2
	float  CosDn2;						//������������2
	CTime  Tm2;							//ʱ��2�ָ��
	float  VUp3;						//��ѹ����3
	float  VDn3;						//��ѹ����3
	float  CP_Num3;						//���ݿɿش���3
	float  XF_Num3;						//��ѹ���ɿش���3
	float  CosUp3;						//������������3
	float  CosDn3;						//������������3
	CTime  Tm3;							//ʱ��3�ָ��
	float  VUp4;						//��ѹ����4
	float  VDn4;						//��ѹ����4
	float  CP_Num4;						//���ݿɿش���4
	float  XF_Num4;						//��ѹ���ɿش���4
	float  CosUp4;						//������������4
	float  CosDn4;						//������������4
	CTime  Tm4;							//ʱ��4�ָ��
	float  VUp5;						//��ѹ����5
	float  VDn5;						//��ѹ����5
	float  CP_Num5;						//���ݿɿش���5
	float  XF_Num5;						//��ѹ���ɿش���5
	float  CosUp5;						//������������5
	float  CosDn5;						//������������5
	CTime  Tm5;							//ʱ��1�ָ��
	float  VUp6;						//��ѹ����6
	float  VDn6;						//��ѹ����6
	float  CP_Num6;						//���ݿɿش���6
	float  XF_Num6;						//��ѹ���ɿش���6
	float  CosUp6;						//������������6
	float  CosDn6;						//������������6
	CTime  LogTime;						//����ʱ��
}AssessAVC_AVCTimePart,*LPAssessAVC_AVCTimePart;
//AVC�����¼���
typedef struct AssessAVC_AVCLossEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//վ��
	char  Name[64];						//����
	float  val1;						//����ֵ1
	float  val2;						//����ֵ2
	BYTE  ByScada;						//�¼���Դ1��Դ��SCADA
	CTime  EventTime;					//�¼�ʱ��
	DWORD  CmdID;						//�����¼�ID
}AssessAVC_AVCLossEvent,*LPAssessAVC_AVCLossEvent;
//AVCʵʱ�������ܱ�
typedef struct AssessAVC_RealAVCCapably
{
	DWORD  NU;							//���
	char  Type[64];						//�������
	char  Name[64];						//����
	float  Value;						//��ֵ
}AssessAVC_RealAVCCapably,*LPAssessAVC_RealAVCCapably;
//=================Tvisualpw===============
//PT��
typedef struct Tvisualpw_PT
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
}Tvisualpw_PT,*LPTvisualpw_PT;
//�����
typedef struct Tvisualpw_Gen
{
	DWORD  NU;							//�������
	char  Name[64];						//�������
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
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Gen,*LPTvisualpw_Gen;
//���ص�բ
typedef struct Tvisualpw_Switch
{
	DWORD  NU;							//���ر��
	char  Name[64];						//��������
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
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Switch,*LPTvisualpw_Switch;
//����
typedef struct Tvisualpw_Load
{
	DWORD  NU;							//���ɱ��
	char  Name[64];						//��������
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
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Load,*LPTvisualpw_Load;
//����
typedef struct Tvisualpw_Shunt
{
	DWORD  NU;							//�����豸���
	char  Name[64];						//�����豸����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Q;							//Ͷ���޹�
	float  I;							//����
	float  RVol;						//���ѹ
	float  Qmax;						//����޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	float  Qchk;						//��������
	BYTE  Tsta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	float  VL;							//��ѹ�ȼ�
	short  status;						//�ۺ�״̬
	DWORD  CtrlType;					//�������Ͷ���
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Shunt,*LPTvisualpw_Shunt;
//�翹
typedef struct Tvisualpw_Sreact
{
	DWORD  NU;							//�翹�����
	char  Name[64];						//�翹����
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
	DWORD  CtrlType;					//�������Ͷ���
	float  RVol;						//���ѹ
	float  Qmax;						//����޹����
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Sreact,*LPTvisualpw_Sreact;
//2�����ѹ��
typedef struct Tvisualpw_Tfm1
{
	DWORD  NU;							//2�Ʊ���
	char  Name[64];						//2�Ʊ���
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
	DWORD  CtrlType;					//�������Ͷ���
	float  CosDn;						//������������
	float  CosUp;						//������������
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Tfm1,*LPTvisualpw_Tfm1;
//3�����ѹ��
typedef struct Tvisualpw_Tfm2
{
	DWORD  NU;							//3�Ʊ���
	char  Name[64];						//3�Ʊ���
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
	DWORD  CtrlType;					//�������Ͷ���
	float  CosDn;						//������������
	float  CosUp;						//������������
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Tfm2,*LPTvisualpw_Tfm2;
//��̬�޹�����
typedef struct Tvisualpw_SVC
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
	CTime  LogTime;						//����ʱ��
}Tvisualpw_SVC,*LPTvisualpw_SVC;
//ĸ��
typedef struct Tvisualpw_Bus
{
	DWORD  NU;							//ĸ�߱��
	char  Name[64];						//ĸ������
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
	DWORD  CtrlType;					//�������Ͷ���
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Bus,*LPTvisualpw_Bus;
//������
typedef struct Tvisualpw_Line
{
	DWORD  NU;							//�����߱��
	char  Name[64];						//����������
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
	BYTE  EquiSta;						//��ֵ״̬
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Line,*LPTvisualpw_Line;
//ֱ����
typedef struct Tvisualpw_DCLine
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
	CTime  LogTime;						//����ʱ��
}Tvisualpw_DCLine,*LPTvisualpw_DCLine;
//�������������
typedef struct Tvisualpw_CVT
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
}Tvisualpw_CVT,*LPTvisualpw_CVT;
//�ӵ�
typedef struct Tvisualpw_GND
{
	DWORD  NU;							//�ӵر��
	char  Name[64];						//�ӵ�����
	DWORD  Station;						//����վ��
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[24];						//��ʶ
	DWORD  Node;						//�ڵ�
	CTime  LogTime;						//����ʱ��
}Tvisualpw_GND,*LPTvisualpw_GND;
//����
typedef struct Tvisualpw_Zone
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
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Zone,*LPTvisualpw_Zone;
//վ
typedef struct Tvisualpw_Station
{
	DWORD  NU;							//վ��
	char  Name[64];						//վ��
	DWORD  zoneNU;						//��������
	float  VL;							//��ѹ�ȼ�
	int  Type;							//��վ����
	char  ID[24];						//���վ��ʶ
	short  status;						//�ۺ�״̬
	DWORD  CtrlType;					//�������Ͷ���
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Station,*LPTvisualpw_Station;
//���ڵ��ѹ����
typedef struct Tvisualpw_VotOutage
{
	int  NU;							//�豸���
	char  type;							//�豸����
	float  Defl;						//����ָ��
	BYTE  Group;						//��������
}Tvisualpw_VotOutage,*LPTvisualpw_VotOutage;
//��֧·����
typedef struct Tvisualpw_LineOutage
{
	int  NU;							//�豸���
	char  type;							//����
	float  Defl;						//����ָ��
	BYTE  Group;						//��������
}Tvisualpw_LineOutage,*LPTvisualpw_LineOutage;
//�ڵ��ѹ��֧·�ϳ�
typedef struct Tvisualpw_AllOutage
{
	int  NU;							//�豸���
	char  type;							//����
	float  Defl;						//����ָ��
	BYTE  Group;						//��������
}Tvisualpw_AllOutage,*LPTvisualpw_AllOutage;
//ϵͳָ��
typedef struct Tvisualpw_SysGD
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
}Tvisualpw_SysGD,*LPTvisualpw_SysGD;
//ϵͳ�澯
typedef struct Tvisualpw_SysAlarm
{
	WORD  Alarm;						//�澯״̬0,1
	WORD  num;							//�����澯���豸����
	char  picname[32];					//�Ƴ���������
	WORD  picno;						//�Ƴ��������
}Tvisualpw_SysAlarm,*LPTvisualpw_SysAlarm;
//ϵͳ�澯
typedef struct Tvisualpw_Ace
{
	DWORD  ID;							//��ʶID
	float  CurVal;						//��ǰֵ
	CTime  datatime;					//����ʱ��
	BYTE  alarm;						//�澯
	BYTE  ack;							//ȷ��
}Tvisualpw_Ace,*LPTvisualpw_Ace;
//��·����������
typedef struct Tvisualpw_ShortCC
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
}Tvisualpw_ShortCC,*LPTvisualpw_ShortCC;
//�����Ǳ���ʾ
typedef struct Tvisualpw_Meter
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
}Tvisualpw_Meter,*LPTvisualpw_Meter;
//������
typedef struct Tvisualpw_Area
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
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Area,*LPTvisualpw_Area;
//��ѹ�޹����Ʊ�
typedef struct Tvisualpw_AVC
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
}Tvisualpw_AVC,*LPTvisualpw_AVC;
//�����PQV������
typedef struct Tvisualpw_PQV
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
}Tvisualpw_PQV,*LPTvisualpw_PQV;
//����ͳ�Ʊ�
typedef struct Tvisualpw_ldstate
{
	DWORD  NU;							//���
	BYTE  type;							//����
	float  LDmax;						//�������
	CTime  LDmaxT;						//����س���ʱ��
	DWORD  LDoverT;						//�ո��ع���ʱ��
}Tvisualpw_ldstate,*LPTvisualpw_ldstate;
//��ѹ������������
typedef struct Tvisualpw_Hvcondata
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
}Tvisualpw_Hvcondata,*LPTvisualpw_Hvcondata;
//��ѹ����̬����
typedef struct Tvisualpw_DynMonitor
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
}Tvisualpw_DynMonitor,*LPTvisualpw_DynMonitor;
//�¹�Ӱ��
typedef struct Tvisualpw_CtgEffect
{
	DWORD  CtgNU;						//�¹��豸��
	char  CtgName[32];					//�¹��豸��
	int  CtgType;						//�¹��豸����
	float  fSecurity;					//����ָ��
	DWORD  EftNU;						//��̬�豸��
	char  EftName[32];					//��̬�豸��
	int  EftType;						//��̬�豸����
	float  EftVal;						//��̬�̶�
}Tvisualpw_CtgEffect,*LPTvisualpw_CtgEffect;
//ȫ��������
typedef struct Tvisualpw_Grid
{
	float  GenMax;						//ȫ������������
	float  GenP;						//ȫ�������й�
	float  GenQ;						//ȫ�������޹�
	float  StopP;						//ȫ��ͣ��������
	float  UpRes;						//ȫ������ת����
	float  DownRes;						//ȫ������ת����
	float  LoadMax;						//ȫ������ܸ���
	float  LoadP;						//ȫ���õ縺��
}Tvisualpw_Grid,*LPTvisualpw_Grid;
//��ѹ������
typedef struct Tvisualpw_Winding
{
	DWORD  NU;							//������
	char  Name[64];						//����
	char  ID[24];						//�����ʶ
	char  TID[24];						//��ѹ����ʶ
	float  baseKV;						//��׼��ѹ
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
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Winding,*LPTvisualpw_Winding;
//���߱�
typedef struct Tvisualpw_Conductor
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
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Conductor,*LPTvisualpw_Conductor;
//������Ϣ��
typedef struct Tvisualpw_Relay
{
	DWORD  ID;							//����ID��
	DWORD  Station;						//��վ��
	char  Name[64];						//��������
	BYTE  RelayType;					//��������
	BYTE  YX;							//ң��״̬
	DWORD  BayID;						//���ID
	DWORD  DevID;						//�����豸ID
	DWORD  DevNU;						//�����豸���
	char  DevName[64];					//�����豸����
	CTime  LogTime;						//����ʱ��
}Tvisualpw_Relay,*LPTvisualpw_Relay;
//ң�Ŷ����
typedef struct Tvisualpw_YX
{
	DWORD  ID;							//ң��ID
	char  Name[64];						//ң������
	DWORD  DevID;						//�豸ID
	BYTE  DevType;						//�豸����
	char  DevName[64];					//�豸����
	BYTE  YX;							//ң��״̬
	CTime  LogTime;						//����ʱ��
}Tvisualpw_YX,*LPTvisualpw_YX;
//ң�ⶨ���
typedef struct Tvisualpw_YC
{
	DWORD  ID;							//ң��ID
	char  Name[64];						//ң������
	DWORD  DevID;						//�豸ID
	BYTE  DevType;						//�豸����
	char  DevName[64];					//�豸����
	BYTE  MeasType;						//ң������
	BYTE  MeasPos;						//ң��λ��
	float  YC;							//ң��ֵ
	CTime  LogTime;						//����ʱ��
}Tvisualpw_YC,*LPTvisualpw_YC;
//ң��ң�Ź�ϵ��
typedef struct Tvisualpw_YKYX
{
}Tvisualpw_YKYX,*LPTvisualpw_YKYX;
//ϵͳ���������ݱ�
typedef struct Tvisualpw_SysPowerLoss
{
	CTime  LogTime;						//ͳ��ʱ��
	BYTE  IsToDay;						//�Ƿ�������
	float  PowerP;						//���й�
	float  PowerQ;						//���޹�
	float  LoadP;						//�����й�
	float  LoadQ;						//�����޹�
	float  ShuntQ;						//�����޹�
	float  LossP;						//�й�����
	float  LossQ;						//�޹�����
	float  TheoryLossP;					//�����й�����
	float  TheoryLossQ;					//�����޹�����
}Tvisualpw_SysPowerLoss,*LPTvisualpw_SysPowerLoss;
//=================Trefavc===============
//�������ñ�
typedef struct Trefavc_NetSet_table
{
	DWORD  shNo;						//���
	char  szName[64];					//��������
	BYTE  byProtocol;					//����Э��
	int  iPort;							//����˿�
	char  szDestIpAddr[24];				//Ŀ��IP
	char  szSouIpAddr[24];				//ԴIP
}Trefavc_NetSet_table,*LPTrefavc_NetSet_table;
//ң�ر�
typedef struct Trefavc_yk_table
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
	char  Name[64];						//����
}Trefavc_yk_table,*LPTrefavc_yk_table;
//ң����
typedef struct Trefavc_yt_table
{
	DWORD  shFacNo;						//����
	DWORD  shOrderNo;					//���
	BYTE  VlPos;						//��ѹ��λ��
	BYTE  byCommandType;				//������ʽ
	DWORD  shUpNo;						//����������
	BYTE  byUpInverse;					//������ȡ��
	DWORD  shDownNo;					//����������
	BYTE  byDownInverse;				//������ȡ��
	DWORD  shStopNo;					//������������
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
	char  Name[64];						//����
}Trefavc_yt_table,*LPTrefavc_yt_table;
//������Ϣ��
typedef struct Trefavc_relay_table
{
	DWORD  shFacNo;						//����
	DWORD  shOrderNo;					//���
	char  szName[64];					//��������
	short  shAddress;					//��ַ
}Trefavc_relay_table,*LPTrefavc_relay_table;
//����״̬��
typedef struct Trefavc_RelayYx_table
{
	DWORD  shFacNo;						//����
	DWORD  shOrderNo;					//���
	char  szName[64];					//����״̬��
	DWORD  shUnitNo;					//��Ԫ��
	DWORD  shSourceNo;					//����Դ��
	DWORD  shFrameOrder;				//�������
	BYTE  byStatus;						//����״̬
	BYTE  byInverter;					//�����־
	BYTE  byRefresh;					//����״̬
	short  shWarnMode;					//�澯��ʽ
	BYTE  byUpdateNum;					//���¼���
}Trefavc_RelayYx_table,*LPTrefavc_RelayYx_table;
//T�ڵ��
typedef struct Trefavc_tNode_table
{
	DWORD  shTnodeNo;					//T�ӵ���
	char  szName[64];					//T����
	BYTE  byVolDegree;					//��ѹ�ȼ�
	DWORD  shAreaNo;					//���������
	DWORD  shZoneNo;					//�������κ�
	int  iPointNo;						//���ӵ��
}Trefavc_tNode_table,*LPTrefavc_tNode_table;
//��ֵ��ѹ����
typedef struct Trefavc_equTrans_table
{
	DWORD  shFacNo;						//����
	DWORD  shMasterNo;					//����ѹ����
	DWORD  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	float  fCapacity;					//�����
	BYTE  byReguType;					//��ѹ��ʽ
	BYTE  byStatus;						//����״̬
	BYTE  byLock;						//����״̬
	BYTE  byCtrlType;					//�Ż���������
	DWORD  shTapYcNo;					//��λң�����
	float  fResistance;					//����ֵ
	float  fReactance;					//�翹ֵ
	float  fConductance;				//�絼ֵ
	float  fSusceptance;				//����ֵ
	float  fMinRatio;					//��С���
	float  fMaxRatio;					//�����
	float  fStepSize;					//��λ����
	DWORD  iFromPoint;					//�׶����ӵ��
	int  iToPoint;						//ĩ�����ӵ��
	DWORD  shFromPNo;					//�׶��й��������
	DWORD  shFromQNo;					//�׶��޹��������
	DWORD  shFromINo;					//�׶˵����������
	DWORD  shToPNo;						//ĩ���й��������
	DWORD  shToQNo;						//ĩ���޹��������
	DWORD  shToINo;						//ĩ�˵����������
	float  fBaseVol;					//��׼��ѹ
	char  szName[64];					//����
}Trefavc_equTrans_table,*LPTrefavc_equTrans_table;
//���������
typedef struct Trefavc_lock_table
{
	DWORD  shLockNo;					//���
	BYTE  byEventType;					//�����¼�����
	char  shEvent[64];					//�����¼�����
	DWORD  shEventNo;					//�����¼����
	BYTE  byObjectType;					//������������
	DWORD  shObjectFac;					//�������󳧺�
	DWORD  shObjectNo;					//�����������
	char  shObjectName[64];				//������������
	short  shWarnMode;					//�澯��ʽ
	BYTE  byUnlockType;					//�����ʽ
}Trefavc_lock_table,*LPTrefavc_lock_table;
//�����
typedef struct Trefavc_area_table
{
	DWORD  shAreaNo;					//�����
	char  szAreaName[64];				//������
	float  fPA;							//�ƻ��й����
	float  fPLA;						//���佻���ݲ�
}Trefavc_area_table,*LPTrefavc_area_table;
//�����
typedef struct Trefavc_zone_table
{
	DWORD  shZoneNo;					//���κ�
	char  szZoneName[64];				//������
	BYTE  byIT;							//�Ż�����
	BYTE  byLT;							//��С�������
	BYTE  byMIZ;						//����й����״̬��־
	float  fLossDead;					//�й������������
	float  fLimitDead;					//��ѹԽ�޼�������
	float  fPrePLoss;					//�Ż�ǰ�й�����
	float  fPostPLoss;					//�Ż����й�����
	float  fPreQLoss;					//�Ż�ǰ�޹�����
	float  fPostQLoss;					//�Ż����޹�����
}Trefavc_zone_table,*LPTrefavc_zone_table;
//��ѹ��ֵ��
typedef struct Trefavc_VolLimit_table
{
	DWORD  shLimitNo;					//��ֵ����
	DWORD  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fMax1st;						//һ�����ֵ
	float  fMin1st;						//һ����Сֵ
	float  fMax2st;						//�������ֵ
	float  fMin2st;						//������Сֵ
	float  fMax3st;						//�������ֵ
	float  fMin3st;						//������Сֵ
	char  szName[64];					//����
}Trefavc_VolLimit_table,*LPTrefavc_VolLimit_table;
//��ѹ�仯��ֵ��
typedef struct Trefavc_VolVar_table
{
	DWORD  shLimitNo;					//��ֵ����
	DWORD  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fMax1st;						//һ�����ֵ
	float  fMin1st;						//һ����Сֵ
	float  fMax2st;						//�������ֵ
	float  fMin2st;						//������Сֵ
	float  fMax3st;						//�������ֵ
	float  fMin3st;						//������Сֵ
	char  szName[64];					//����
}Trefavc_VolVar_table,*LPTrefavc_VolVar_table;
//�޹���ֵ��
typedef struct Trefavc_qSetLim_table
{
	DWORD  shLimitNo;					//Լ������
	DWORD  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fUpLimit;					//�޹�/������������
	float  fLowLimit;					//�޹�/������������
	BYTE  vlpos;						//��ѹ��
	char  szName[64];					//����
}Trefavc_qSetLim_table,*LPTrefavc_qSetLim_table;
//��ѹ��ֵ��
typedef struct Trefavc_vSetLim_table
{
	DWORD  shLimitNo;					//Լ������
	DWORD  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fUpLimit;					//��ѹ����
	float  fLowLimit;					//��ѹ����
	BYTE  vlpos;						//��ѹ��
	char  szName[64];					//����
}Trefavc_vSetLim_table,*LPTrefavc_vSetLim_table;
//�Ż��¼���
typedef struct Trefavc_opfEvent_table
{
	DWORD  shEventNo;					//���
	BYTE  byEventType;					//�¼�����
	DWORD  shSourceFac;					//�¼�����
	DWORD  shSourceNo;					//�¼����
	BYTE  byYxVal;						//ң��ֵ
	float  fChangeLimit;				//ң��仯��ֵ����ֵ
	short  shRelay;						//������ʱ
	float  fLastValue;					//�ϴβ���ֵ
}Trefavc_opfEvent_table,*LPTrefavc_opfEvent_table;
//�Ż�ʱ���
typedef struct Trefavc_opfStart_table
{
	DWORD  shTimeNo;					//���
	CTime  tStartTime;					//����ʱ��
}Trefavc_opfStart_table,*LPTrefavc_opfStart_table;
//ң��仯��ֵ��
typedef struct Trefavc_opfYcLim_table
{
	DWORD  shLimitNo;					//���
	DWORD  shYcFac;						//ң�⳧��
	DWORD  shYcNo;						//ң�����
	float  fChangeLimit;				//�仯������ֵ��ֵ
}Trefavc_opfYcLim_table,*LPTrefavc_opfYcLim_table;
//�Ż��������ñ�
typedef struct Trefavc_opfSet_table
{
	DWORD  shAutoId;					//���
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
}Trefavc_opfSet_table,*LPTrefavc_opfSet_table;
//��������
typedef struct Trefavc_tIsland_table
{
	DWORD  iIslandNo;					//��������
	DWORD  iNodeNum;					//�ڵ���
	DWORD  iGenNum;						//�������
	DWORD  iLoadNum;					//������
	short  shSeTime;					//״̬����ʱ��
	BYTE  bySeResult;					//se���
	short  shOpfTime;					//�Ż�����ʱ��
	BYTE  byOpfResult;					//opf���
	DWORD  iMeasNum;					//�����������
	DWORD  iEligibleNum;				//���ƺ�ϸ����
	char  szRefGen[200];				//ƽ���
}Trefavc_tIsland_table,*LPTrefavc_tIsland_table;
//����ڵ��
typedef struct Trefavc_tmpNode_table
{
	DWORD  iNodeNo;						//�ڵ��
	DWORD  iIslandNo;					//��������
	DWORD  shFacNo;						//���ڳ���
	DWORD  shAreaNo;					//���������
	DWORD  shZoneNo;					//�������κ�
	short  byBusType;					//ĸ������
	BYTE  byCtrlType;					//�Ż���������
	float  fBaseVol;					//��׼��ѹ
	float  fYcVol;						//ң���ѹֵ
	float  fVolWeight;					//��ѹȨֵ
	float  fVolStep;					//��ѹȨֵ����
	BYTE  byJPV;						//��ѹ����״̬
	BYTE  byJPC;						//��ѹ�仯����״̬
	float  fSeVoltage;					//se��ѹֵ
	float  fSeAngle;					//se��ѹ���
	DWORD  shLimitNo;					//��ѹ���Ƽ���
	DWORD  shVarLimNo;					//�޹��仯���Ƽ���
	char  Name[64];						//����
	float  VolUpLimit;					//��ѹ��������
	float  VolDnLimit;					//��ѹ��������
	float  CosUpLimit;					//���ʿ�������
	float  CosDnLimit;					//���ʿ�������
	DWORD  SysNU;						//ϵͳ�ڲ����
	BYTE  IsGate;						//�ؿڱ�־
}Trefavc_tmpNode_table,*LPTrefavc_tmpNode_table;
//�����ѹ����
typedef struct Trefavc_tmpTrans_table
{
	DWORD  shFacNo;						//����
	DWORD  shMasterNo;					//����ѹ����
	DWORD  iTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	float  fCapacity;					//�����
	float  fRateKVi;					//���ѹi
	float  fRateKVj;					//���ѹj
	float  fBaseKVi;					//��׼��ѹi
	float  fBaseKVj;					//��׼��ѹi
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
	float  fTapPos;						//��ǰ��λ
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
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToPoint;					//ĩ�˽ڵ��
	float  fSeFromP;					//�׶��й�
	float  fSeFromQ;					//�׶��޹�
	float  fSeFromI;					//�׶˵���
	float  fSeToP;						//ĩ���й�
	float  fSeToQ;						//ĩ���޹�
	float  fSeToI;						//ĩ�˵���
	DWORD  iIslandNo;					//��������
	char  Name[64];						//����
	DWORD  SysNU;						//ϵͳ�ڲ����
	BYTE  IsGate;						//�ؿڱ�־
	float  CosUpLimit;					//���ʿ�������
	float  CosDnLimit;					//���ʿ�������
	DWORD  Parallel;					//����֧·
}Trefavc_tmpTrans_table,*LPTrefavc_tmpTrans_table;
//�����޹��豸��
typedef struct Trefavc_tmpShunt_table
{
	DWORD  shFacNo;						//����
	DWORD  iShuntNo;					//���
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
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToPoint;					//ĩ�˽ڵ��
	float  fSeQ;						//�޹�����ֵ
	DWORD  iIslandNo;					//��������
	char  Name[64];						//����
	DWORD  SysNU;						//ϵͳ�ڲ����
	BYTE  IsVirtual;					//�����־
}Trefavc_tmpShunt_table,*LPTrefavc_tmpShunt_table;
//���㷢�����
typedef struct Trefavc_tmpGen_table
{
	DWORD  shFacNo;						//����
	DWORD  iGenNo;						//�������
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
	DWORD  iNodeNo;						//�ڵ��
	float  fSeP;						//�й�����ֵ
	float  fSeQ;						//�޹�����ֵ
	DWORD  iIslandNo;					//��������
	char  Name[64];						//����
	DWORD  SysNU;						//ϵͳ�ڲ����
}Trefavc_tmpGen_table,*LPTrefavc_tmpGen_table;
//���㸺�ɱ�
typedef struct Trefavc_tmpLoad_table
{
	DWORD  shFacNo;						//����
	DWORD  iLoadNo;						//���
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
	DWORD  iNodeNo;						//�ڵ��
	float  fSeP;						//�й�����ֵ
	float  fSeQ;						//�޹�����ֵ
	DWORD  iIslandNo;					//��������
	char  Name[64];						//����
	DWORD  SysNU;						//ϵͳ�ڲ����
}Trefavc_tmpLoad_table,*LPTrefavc_tmpLoad_table;
//������·��
typedef struct Trefavc_tmpLine_table
{
	DWORD  iLineNo;						//��·��
	DWORD  shFromFac;					//�׶˳���
	DWORD  shToFac;						//ĩ�˳���
	float  fResistance;					//����ֵ
	float  fReactance;					//�翹ֵ
	float  fConductance;				//�絼ֵ
	float  fSusceptance;				//����ֵ
	float  fFromCapacity;				//��·�׶�����
	float  fToCapacity;					//��·ĩ������
	float  fBaseKV;						//���ѹ
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
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fSeFromP;					//�׶��й�����
	float  fSeFromQ;					//�׶��޹�����
	float  fSeFromI;					//�׶˵�������
	float  fSeToP;						//ĩ���й�����
	float  fSeToQ;						//ĩ���޹�����
	float  fSeToI;						//ĩ�˵�������
	DWORD  iIslandNo;					//��������
	char  Name[64];						//����
	DWORD  SysNU;						//ϵͳ�ڲ����
	DWORD  Parallel;					//����֧·
}Trefavc_tmpLine_table,*LPTrefavc_tmpLine_table;
//����ĸ�߱�
typedef struct Trefavc_tmpBus_table
{
	DWORD  shFacNo;						//����
	DWORD  shBusNo;						//ĸ�ߺ�
	DWORD  iNodeNo;						//�ڵ��
	short  byBusType;					//ĸ������
	BYTE  byCtrlType;					//�Ż���������
	float  fBaseVol;					//��׼��ѹ
	float  fYcVol;						//ң���ѹֵ
	float  fVolWeight;					//��ѹȨֵ
	float  fVolStep;					//��ѹȨֵ����
	BYTE  byJPV;						//��ѹ����״̬
	BYTE  byJPC;						//��ѹ�仯����״̬
	DWORD  shLimitNo;					//��ѹ���Ƽ���
	DWORD  shVarLimNo;					//�޹��仯���Ƽ���
	char  Name[64];						//����
	DWORD  iIslandNo;					//��������
	float  VolUpLimit;					//��ѹ��������
	float  VolDnLimit;					//��ѹ��������
	float  CosUpLimit;					//���ʿ�������
	float  CosDnLimit;					//���ʿ�������
	DWORD  SysNU;						//ϵͳ�ڲ����
	BYTE  IsGate;						//�ؿڱ�־
}Trefavc_tmpBus_table,*LPTrefavc_tmpBus_table;
//�Ż����������Ϣ��
typedef struct Trefavc_opfRes_table
{
	DWORD  shAutoId;					//���
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
}Trefavc_opfRes_table,*LPTrefavc_opfRes_table;
//���ⲻ���
typedef struct Trefavc_MeasAna_table
{
	int  iNoBalanceBran;				//��ƽ��֧·��
	int  iNoBalanceNode;				//��ƽ��֧·��
	int  iBSNoMatch;					//���س�����ƥ����
	int  iBadData;						//��������
	int  iShadMeas;						//����������
	int  iDummyMeas;					//α������
}Trefavc_MeasAna_table,*LPTrefavc_MeasAna_table;
//�Ż�ǰ�ڵ��
typedef struct Trefavc_preNode_table
{
	DWORD  iNodeNo;						//�ڵ��
	DWORD  iIslandNo;					//��������
	float  fVoltage;					//��ѹֵ
	float  fVolAngle;					//��ѹ���
	float  fGenMW;						//�����й�
	float  fGenMvar;					//�����޹�
	float  fLoadMW;						//�����й�
	float  fLoadMvar;					//�����޹�
	float  fShuntMW;					//����֧·�й�
	float  fShuntMvar;					//����֧·�޹�
}Trefavc_preNode_table,*LPTrefavc_preNode_table;
//�Ż���ڵ��
typedef struct Trefavc_postNode_table
{
	DWORD  iNodeNo;						//�ڵ��
	DWORD  iIslandNo;					//��������
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
}Trefavc_postNode_table,*LPTrefavc_postNode_table;
//�Ż�ǰ��·��
typedef struct Trefavc_preLine_table
{
	DWORD  iLineNo;						//��·��
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fFromMW;						//��·�׶��й�
	float  fFromMvar;					//��·�׶��޹�
	float  fToMW;						//��·ĩ���й�
	float  fToMvar;						//��·ĩ���޹�
}Trefavc_preLine_table,*LPTrefavc_preLine_table;
//�Ż�����·��
typedef struct Trefavc_postLine_table
{
	DWORD  iLineNo;						//��·��
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fFromMW;						//��·�׶��й�
	float  fFromMvar;					//��·�׶��޹�
	float  fToMW;						//��·ĩ���й�
	float  fToMvar;						//��·ĩ���޹�
}Trefavc_postLine_table,*LPTrefavc_postLine_table;
//�Ż�ǰ��ѹ����
typedef struct Trefavc_preTrans_table
{
	DWORD  shFacNo;						//����
	DWORD  shMasterNo;					//����ѹ����
	DWORD  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fFromMW;						//�׶��й�
	float  fFromMvar;					//�׶��޹�
	float  fToMW;						//ĩ���й�
	float  fToMvar;						//ĩ���޹�
	float  fFromPf;						//�׶˹�������
	float  fToPf;						//ĩ�˹�������
}Trefavc_preTrans_table,*LPTrefavc_preTrans_table;
//�Ż����ѹ����
typedef struct Trefavc_postTran_table
{
	DWORD  shFacNo;						//����
	DWORD  shMasterNo;					//����ѹ����
	DWORD  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fFromMW;						//�׶��й�
	float  fFromMvar;					//�׶��޹�
	float  fToMW;						//ĩ���й�
	float  fToMvar;						//ĩ���޹�
	float  fFromPf;						//�׶˹�������
	float  fToPf;						//ĩ�˹�������
}Trefavc_postTran_table,*LPTrefavc_postTran_table;
//�Ż����Ʊ�ѹ����
typedef struct Trefavc_opfTrans_table
{
	DWORD  shFacNo;						//����
	DWORD  shMasterNo;					//����ѹ����
	DWORD  shTransNo;					//��ѹ����
	BYTE  byVolSide;					//��ѹ��
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fFromBaseVol;				//�׶˻�׼��ѹ
	float  fToBaseVol;					//ĩ�˻�׼��ѹ
	float  fPreRatio;					//�Ż�ǰ���
	float  fPostRatio;					//�Ż�����
}Trefavc_opfTrans_table,*LPTrefavc_opfTrans_table;
//�Ż������޹���
typedef struct Trefavc_opfShunt_table
{
	DWORD  shFacNo;						//����
	DWORD  shShuntNo;					//���
	DWORD  iFromNode;					//�׶˽ڵ��
	DWORD  iToNode;						//ĩ�˽ڵ��
	float  fPreVar;						//�Ż�ǰ����
	float  fPostVar;					//�Ż�������
}Trefavc_opfShunt_table,*LPTrefavc_opfShunt_table;
//VQC��ֵ��
typedef struct Trefavc_VqcSet_table
{
	DWORD  shFacNo;						//����
	BYTE  byType;						//��ѹ������
	DWORD  shTransNo;					//��ѹ����
	char  szFacName[64];				//��վ��
	char  szTransName[64];				//��ѹ����
	float  fHiVolSet;					//��ѹ��ֵ����
	float  fLowVolSet;					//��ѹ��ֵ����
	float  fHiVarSet;					//�޹�/����������ֵ����
	float  fLowVarSet;					//�޹�/����������ֵ����
	BYTE  byStatus;						//����״̬
}Trefavc_VqcSet_table,*LPTrefavc_VqcSet_table;
//���������
typedef struct Trefavc_opfCmd_table
{
	DWORD  tmOrder;						//���
	DWORD  shFacNo;						//����
	BYTE  byType;						//�豸����
	DWORD  shDeviceNo;					//�豸���
	char  szFacName[64];				//��վ��
	char  szDevName[64];				//�豸��
	DWORD  SwitchNU;					//���ر��
	char  YKSwitch[64];					//ң�ؿ���
	int  YKPoint;						//ң�ص��
	BYTE  byCommand;					//�������/�Ͻ���
	float  shCurTap;					//��ǰ��λ
	float  shEndTap;					//Ŀ�굵λ
	BYTE  byStatus;						//����״̬
	CTime  CreatTime;					//����ʱ��
	CTime  YKTime;						//����ʱ��
	char  YKInfo[64];					//������Ϣ
	BYTE  YKState;						//ң�ر�ʶ
	char  CtrlType[16];					//���Ʒ���
}Trefavc_opfCmd_table,*LPTrefavc_opfCmd_table;
//������Ż���
typedef struct Trefavc_opfGen_table
{
	DWORD  shFacNo;						//����
	DWORD  shGenNo;						//�������
	DWORD  iNodeNo;						//�ڵ��
	float  fPreP;						//�Ż�ǰ�й�
	float  fPostP;						//�Ż����й�
	float  fPreQ;						//�Ż�ǰ�޹�
	float  fPostQ;						//�Ż����޹�
}Trefavc_opfGen_table,*LPTrefavc_opfGen_table;
//�����PQ���߱�
typedef struct Trefavc_genPQ_table
{
	DWORD  shFacNo;						//����
	DWORD  shGenNo;						//�������
	DWORD  shOrderNo;					//���
	float  fP;							//�й�����
	float  fMaxQ;						//����޹�
	float  fMinQ;						//��С�޹�
}Trefavc_genPQ_table,*LPTrefavc_genPQ_table;
//ĸ���Ż������
typedef struct Trefavc_opfBus_table
{
	DWORD  shFacNo;						//����
	DWORD  shBusNo;						//ĸ�ߺ�
	char  szFacName[64];				//��վ��
	char  szBusName[64];				//ĸ����
	float  fYcVol;						//ң���ѹֵ
	float  fSeVol;						//״̬���Ƶ�ѹֵ
	float  fSeDev;						//�������ƫ��
	float  fSeAngle;					//״̬���Ƶ�ѹ���
	float  fOpfVol;						//�Ż���ѹֵ
	float  fOpfAngle;					//�Ż���ѹ���
	float  fPostVol;					//���ƺ��ѹֵ
}Trefavc_opfBus_table,*LPTrefavc_opfBus_table;
//��·�Ż������
typedef struct Trefavc_opfLine_table
{
	DWORD  iLineNo;						//��·��
	char  szName[64];					//��·��
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
}Trefavc_opfLine_table,*LPTrefavc_opfLine_table;
//��ѹ���Ż������
typedef struct Trefavc_opfByq_table
{
	DWORD  shFacNo;						//����
	BYTE  byType;						//��ѹ������
	DWORD  shTransNo;					//��ѹ����
	char  szFacName[64];				//��վ��
	char  szTransName[64];				//��ѹ����
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
}Trefavc_opfByq_table,*LPTrefavc_opfByq_table;
//�޹��豸�Ż������
typedef struct Trefavc_opfWgsb_table
{
	DWORD  shFacNo;						//����
	DWORD  shShuntNo;					//���
	char  szFacName[64];				//��վ��
	char  szName[64];					//�豸��
	float  fYcQ;						//�޹�ң��
	float  fSeQ;						//״̬�����޹�
	float  fOpfQ;						//�Ż��޹�
	float  fPostQ;						//���ƺ��޹�ң��
}Trefavc_opfWgsb_table,*LPTrefavc_opfWgsb_table;
//������Ż������
typedef struct Trefavc_opfFdj_table
{
	DWORD  shFacNo;						//����
	DWORD  shGenNo;						//�������
	char  szFacName[64];				//��վ��
	char  szName[64];					//�������
	float  fYcP;						//�й�ң��
	float  fYcQ;						//�޹�ң��
	float  fSeP;						//״̬�����й�
	float  fSeQ;						//״̬�����޹�
	float  fOpfP;						//�Ż��й�
	float  fOpfQ;						//�Ż��޹�
	float  fPostP;						//���ƺ��й�ң��
	float  fPostQ;						//���ƺ��޹�ң��
}Trefavc_opfFdj_table,*LPTrefavc_opfFdj_table;
//��ѹ����ͳ�Ʊ�
typedef struct Trefavc_VolSeSta_table
{
	DWORD  iIslandNo;					//��������
	BYTE  byStaType;					//����ͳ������
	BYTE  byVolDegree;					//��ѹ�ȼ����
	float  fVolSeAccu;					//���ƺϸ���
}Trefavc_VolSeSta_table,*LPTrefavc_VolSeSta_table;
//ĸ�ߵ�ѹԽ�ޱ�
typedef struct Trefavc_BusExcee_table
{
	DWORD  shFacNo;						//����
	DWORD  shBusNo;						//ĸ�ߺ�
	char  szFacName[64];				//��վ��
	char  szBusName[64];				//ĸ����
	float  fYcVol;						//ң���ѹֵ
	float  fSeVol;						//״̬���Ƶ�ѹֵ
	float  fOpfVol;						//�Ż���ѹֵ
}Trefavc_BusExcee_table,*LPTrefavc_BusExcee_table;
//��ѹ����ı�
typedef struct Trefavc_LossByq_table
{
	DWORD  shFacNo;						//����
	BYTE  byType;						//��ѹ������
	DWORD  shTransNo;					//��ѹ����
	char  szFacName[64];				//��վ��
	char  szTransName[64];				//��ѹ����
	float  fPrePLoss;					//�Ż�ǰ�й����
	float  fPostPLoss;					//�Ż����й����
	float  fPreQLoss;					//�Ż�ǰ�޹����
	float  fPostQLoss;					//�Ż����޹����
}Trefavc_LossByq_table,*LPTrefavc_LossByq_table;
//��·��ı�
typedef struct Trefavc_LossLine_table
{
	DWORD  iLineNo;						//��·��
	char  szName[64];					//��·��
	float  fPrePLoss;					//�Ż�ǰ�й����
	float  fPostPLoss;					//�Ż����й����
	float  fPreQLoss;					//�Ż�ǰ�޹����
	float  fPostQLoss;					//�Ż����޹����
}Trefavc_LossLine_table,*LPTrefavc_LossLine_table;
//��ǰ������
typedef struct Trefavc_curLock_table
{
	CTime  tLockTime;					//����ʱ��
	BYTE  byObjectType;					//������������
	DWORD  shObjectFac;					//�������󳧺�
	char  szFacName[64];				//����������
	DWORD  shObjectNo;					//���������
	char  szObectName[64];				//����������
	char  szLockInfo[100];				//������Ϣ
}Trefavc_curLock_table,*LPTrefavc_curLock_table;
//��ʱ�޿��Ʊ�
typedef struct Trefavc_DevCtrl_table
{
	DWORD  shOrderNo;					//���
	float  fVolIntegral;				//��ѹ������
	float  fVolSecIncreas;				//��ѹ��������
	short  shVolHop;					//��ѹ������
	float  fCosIntegral;				//���ʻ������
	float  fCosSecIncreas;				//���ʶ�������
	short  shCosHop;					//����������
}Trefavc_DevCtrl_table,*LPTrefavc_DevCtrl_table;
//�����
typedef struct Trefavc_Rule_table
{
	WORD  rule_no;						//������
	short  order_no;					//���
	BYTE  v_status;						//��ѹ״̬
	BYTE  cos_status;					//��������״̬
	BYTE  t_status;						//��ѹ����ǰ״
	BYTE  c_status;						//����װ��״̬
	BYTE  t_action;						//��ѹ������
	BYTE  c_action;						//����װ�ö���
}Trefavc_Rule_table,*LPTrefavc_Rule_table;
//���������
typedef struct Trefavc_shady_table
{
	BYTE  bType;						//����
	char  szInfo[160];					//��Ϣ
}Trefavc_shady_table,*LPTrefavc_shady_table;
//������ֵ��
typedef struct Trefavc_SetLim_table
{
	DWORD  shLimitNo;					//Լ������
	DWORD  shOrderNo;					//���
	CTime  tStartTime;					//��ʼʱ��
	CTime  tEndTime;					//��ֹʱ��
	float  fVolUp;						//��ѹ����
	float  fVolLow;						//��ѹ����
	float  fVarUp;						//�޹�����
	float  fVarDown;					//�޹�����
	WORD  fTransNum;					//��ѹ���ɵ��ڴ���
	WORD  fShuntNum;					//�������ɵ��ڴ���
	BYTE  vlpos;						//��ѹ��
	char  szName[64];					//����
	float  fBaseVol;					//��׼��ѹ
}Trefavc_SetLim_table,*LPTrefavc_SetLim_table;
//AVCϵͳĬ�����в���
typedef struct Trefavc_Avc_RunParam
{
	DWORD  NU;							//���
	CTime  starttime;					//��ʼʱ��
	CTime  endtime;						//��ֹʱ��
	short  type;						//ʱ�����
	char  tyname[64];					//ʱ���������
	float  BaseVol;						//��׼��ѹ
	WORD  capnum;						//���ݿ��ƴ���
	WORD  tfmnum;						//��ѹ�����ƴ���
	float  GateCosup;					//�ؿڹ�������
	float  GateCosdn;					//�ؿڹ�������
	float  FacCosup;					//��վ��������
	float  FacCosdn;					//��վ��������
	float  Volup;						//��ѹ����
	float  Voldn;						//��ѹ����
}Trefavc_Avc_RunParam,*LPTrefavc_Avc_RunParam;
//�豸ң����Ϣ�����
typedef struct Trefavc_DevYk_table
{
	DWORD  NU;							//�豸���
	char  Name[64];						//�豸����
	BYTE  DevType;						//�豸����
	char  YKType[32];					//ң������
	char  YKName[64];					//ң������
	char  LinkSwitch[64];				//ң�ؿ���
	DWORD  SwitchNU;					//���ر��
	DWORD  UpPoint;						//��/�����
	DWORD  DnPoint;						//��/�����
	BYTE  RevFlag;						//�����ʶ
	short  DelayTime;					//�ӳ�ʱ��
}Trefavc_DevYk_table,*LPTrefavc_DevYk_table;
//ϵͳ���������ݱ�
typedef struct Trefavc_SysPowerLoss
{
	CTime  LogTime;						//ͳ��ʱ��
	char  OpfType[32];					//�Ż�����
	float  PowerP;						//���й�
	float  PowerQ;						//���޹�
	float  LoadP;						//�����й�
	float  LoadQ;						//�����޹�
	float  ShuntQ;						//�����޹�
	float  LossP;						//�й�����
	float  LossQ;						//�޹�����
	int  CtrlTfm;						//��ѹ��������
	int  CtrlShunt;						//������������
	float  OpfLossP;					//�й�����
	float  OpfLossQ;					//�޹�����
}Trefavc_SysPowerLoss,*LPTrefavc_SysPowerLoss;
//=================TScadaAVC===============
//�����������Ϣ��
typedef struct TScadaAVC_PasIsland
{
	DWORD  NU;							//���
	DWORD  IslandID;					//����
	DWORD  Station;						//ƽ�������
	char  StaName[64];					//ƽ�������
	DWORD  GenID;						//ƽ���ID
	char  GenName[64];					//ƽ�����
	DWORD  NodeNum;						//�ڵ���
	BYTE  State;						//������
	BYTE  Obisle;						//�ɹ۲���
	BYTE  BadDataP;						//�й�������
	BYTE  BadDataQ;						//�޹�������
	CTime  SERunTime;					//����ʱ��
	CTime  LogTime;						//����ʱ��
}TScadaAVC_PasIsland,*LPTScadaAVC_PasIsland;
//���������Ϣ��
typedef struct TScadaAVC_PasRunInfo
{
	CTime  RunTime;						//����ʱ��
	char  RunInfo[200];					//������Ϣ
	CTime  LogTime;						//����ʱ��
}TScadaAVC_PasRunInfo,*LPTScadaAVC_PasRunInfo;
//����SE������
typedef struct TScadaAVC_PasSEParam
{
	BYTE  Run_State;					//��ǰ����״̬
	BYTE  Pause_State;					//��ͣ����״̬
	CTime  RunTime;						//����ʱ��
	BYTE  Conv_State;					//��ǰ����״̬
	float  Measure_Rate;				//ң�⸲����
	DWORD  CycleTime;					//��������(��)
	DWORD  MaxIter;						//����������
	float  EpsP;						//�й���������
	float  EpsQ1;						//�޹���������
	float  SE_Rate;						//��ǰ״���ϸ���
	float  SE_DayRate;					//����״���ϸ���
	float  SE_MonRate;					//��״���ϸ���
	float  SE_YearRate;					//��״���ϸ���
	CTime  LogTime;						//����ʱ��
}TScadaAVC_PasSEParam,*LPTScadaAVC_PasSEParam;
//����SE����һ����
typedef struct TScadaAVC_PasSEMeasure
{
	DWORD  Station;						//��վ��
	DWORD  DevID;						//�豸ID
	BYTE  DevType;						//�豸����
	BYTE  MeasType;						//��������
	BYTE  MeasPos;						//����λ��
	char  MeasInfo[64];					//��������
	DWORD  Island;						//����
	float  Meas_value;					//����ֵ
	float  SE_value;					//״̬����ֵ
	float  Err_value;					//���ٷ���
	float  Error;						//���ϸ�����
	float  BadData;						//������
	float  DHisRate;					//�պϸ�ͳ����
	float  MHisRate;					//�ºϸ�ͳ����
}TScadaAVC_PasSEMeasure,*LPTScadaAVC_PasSEMeasure;
//AVC��վ��Ϣ��
typedef struct TScadaAVC_AVCStation
{
	DWORD  ID;							//��վID
	char  Name[64];						//��վ����
	DWORD  Zone;						//����ID
	BYTE  CtrlOut;						//�����˳�
	BYTE  AVCCtrl;						//AVC�Զ�����
	DWORD  CtrlID;						//����ʱ�α��
	BYTE  Lock_Sta;						//��վ����״̬
	BYTE  DevLock_Sta;					//��վ�豸����״̬
	float  Vol_rate;					//��ѹ�ϸ���
	float  Loss_P;						//�й�����
	float  Loss_Q;						//�޹�����
	float  Bachup_Q;					//�޹�����
	DWORD  DCtrlNum;					//�ն�����
	DWORD  H24CtrlNum;					//24Сʱ������
	DWORD  MCtrlNum;					//�¶�����
	CTime  LogTime;						//����ʱ��
}TScadaAVC_AVCStation,*LPTScadaAVC_AVCStation;
//AVCĸ����Ϣ��
typedef struct TScadaAVC_AVCBus
{
	DWORD  BusID;						//ĸ��ID
	DWORD  StationID;					//��վID
	char  Name[64];						//ĸ������
	DWORD  CtrlID;						//����ʱ�α��
	BYTE  Ctr_Sta;						//�Ƿ����
	BYTE  Cal_Sta;						//�Ƿ�������
	BYTE  Lock_Sta;						//����״̬
	BYTE  IsGate;						//�ؿڱ�ʶ
	float  Volup;						//��ѹ����
	float  Voldn;						//��ѹ����
	float  Cosup;						//��������
	float  Cosdn;						//��������
	float  DVol_rate;					//�յ�ѹ�ϸ���
	float  H24Vol_rate;					//24Сʱ��ѹ�ϸ���
	float  MVol_rate;					//�µ�ѹ�ϸ���
	float  DCos_rate;					//���޹��ϸ���
	float  H24Cos_rate;					//24Сʱ�޹��ϸ���
	float  MCos_rate;					//���޹��ϸ���
	CTime  LogTime;						//����ʱ��
}TScadaAVC_AVCBus,*LPTScadaAVC_AVCBus;
//AVC��ѹ����Ϣ��
typedef struct TScadaAVC_AVCTrans
{
	DWORD  ID;							//��ѹ��ID
	DWORD  StationID;					//��վID
	char  Name[64];						//��ѹ������
	DWORD  CtrlID;						//����ʱ��ID
	BYTE  Cal_Sta;						//��������ʶ
	BYTE  Lock_Sta;						//������ʶ
	short  LimitNumber;					//���ƴ�������
	DWORD  UpYXID;						//����ң��ID
	DWORD  UpYKNO;						//����ң�ص��
	DWORD  DnYXID;						//����ң��ID
	DWORD  DnYKNO;						//����ң�ص��
	DWORD  LinkBusID;					//����ĸ��ID
	BYTE  IsGate;						//�ؿڱ�ѹ��
	DWORD  DCtrlNum;					//�տ��ƴ���
	DWORD  DAVCCtrlNum;					//��AVC���ƴ���
	DWORD  DAVCActNum;					//��AVC��������
	DWORD  H24CtrlNum;					//24Сʱ���ƴ���
	DWORD  H24AVCCtrlNum;				//24СʱAVC���ƴ���
	DWORD  H24AVCActNum;				//24СʱAVC��������
	DWORD  MCtrlNum;					//�¿��ƴ���
	DWORD  MAVCCtrlNum;					//��AVC���ƴ���
	DWORD  MAVCActNum;					//��AVC��������
	DWORD  YCtrlNum;					//����ƴ���
	DWORD  YAVCCtrlNum;					//��AVC���ƴ���
	DWORD  YAVCActNum;					//��AVC��������
	CTime  LogTime;						//����ʱ��
}TScadaAVC_AVCTrans,*LPTScadaAVC_AVCTrans;
//AVC�޹��豸��Ϣ��
typedef struct TScadaAVC_AVCShunt
{
	DWORD  ID;							//����ID
	DWORD  StationID;					//��վID
	char  Name[64];						//��������
	DWORD  CtrlID;						//����ʱ��ID
	BYTE  Cal_Sta;						//�������
	BYTE  Lock_Sta;						//����״̬
	WORD  LimitNum;						//������������
	DWORD  YXID;						//ң��ID
	DWORD  YKNO;						//ң�ص��
	DWORD  BusID;						//����ĸ��ID
	DWORD  BreakID;						//���ƿ���ID
	DWORD  DCtrlNum;					//�ն�������
	DWORD  DAVCCtrlNum;					//��AVC��������
	DWORD  DAVCActNum;					//��AVC��������
	DWORD  H24CtrlNum;					//24Сʱ��������
	DWORD  H24AVCCtrlNum;				//24СʱAVC��������
	DWORD  H24AVCActNum;				//24СʱAVC��������
	DWORD  MCtrlNum;					//�¶�������
	DWORD  MAVCCtrlNum;					//��AVC��������
	DWORD  MAVCActNum;					//��AVC��������
	DWORD  YCtrlNum;					//�궯������
	DWORD  YAVCCtrlNum;					//��AVC��������
	DWORD  YAVCActNum;					//��AVC��������
	DWORD  DRunTime;					//������ʱ��
	DWORD  H24RunTime;					//24Сʱ����ʱ��
	DWORD  MRunTime;					//������ʱ��
	DWORD  YRunTime;					//������ʱ��
	CTime  LogTime;						//����ʱ��
}TScadaAVC_AVCShunt,*LPTScadaAVC_AVCShunt;
//AVC������Ϣ��
typedef struct TScadaAVC_AVCZone
{
	DWORD  ID;							//������
	char  Name[120];					//��������
	float  Vol_rate;					//��ѹ�ϸ���
	float  Cos_rate;					//�޹��ϸ���
	double  Loss_P;						//�й������ܼ�
	double  Loss_Q;						//�޹������ܼ�
	DWORD  Shunt_Ctrl;					//�޹�������
	DWORD  Trans_Ctrl;					//��ѹ��������
	float  H24Vol_rate;					//24Сʱ��ѹ�ϸ���
	float  H24Cos_rate;					//24Сʱ�޹��ϸ���
	float  H24LossP_rate;				//24Сʱ�й�������
	float  H24LossQ_rate;				//24Сʱ�޹�������
	DWORD  H24Shunt_Ctrl;				//24Сʱ�޹�������
	DWORD  H24Trans_Ctrl;				//24Сʱ��ѹ��������
	float  MVol_rate;					//�µ�ѹ�ϸ���
	float  MCos_rate;					//���޹��ϸ���
	float  MLossP_rate;					//���й�������
	float  MLossQ_rate;					//���޹�������
	DWORD  MShunt_Ctrl;					//���޹�������
	DWORD  MTrans_Ctrl;					//�±�ѹ��������
	float  YVol_rate;					//���ѹ�ϸ���
	float  YCos_rate;					//���޹��ϸ���
	float  YLossP_rate;					//���й�������
	float  YLossQ_rate;					//���޹�������
	DWORD  YShunt_Ctrl;					//���޹�������
	DWORD  YTrans_Ctrl;					//���ѹ��������
	CTime  LogTime;						//����ʱ��
}TScadaAVC_AVCZone,*LPTScadaAVC_AVCZone;
//AVC���в�����Ϣ��
typedef struct TScadaAVC_AVCCtrRunParam
{
	CTime  DateLog;						//ϵͳ������־ʱ��
	char  SysInfo[24];					//ϵͳ��Ϣ
	char  RunMsg[64];					//������Ϣ
	DWORD  RunNum;						//���д���
	CTime  StartTime;					//����ʱ��
	CTime  AvcTime;						//AVC����ʱ��
	BYTE  Run_Sta;						//����״̬
	BYTE  Auto_Sta;						//�Զ�����״̬
	BYTE  Quit_Sta;						//�����˳�״̬
	BYTE  Cmd_Sta;						//�����·�״̬
	BYTE  Remote_Sta;					//Զ��״̬
	BYTE  Enable_Sta;					//AVC���ñ�־
	WORD  Cycvol;						//��������
	int  Ctrlmtd;						//�����㷨
	BYTE  Ctrl_CP;						//���ݿ���״̬
	BYTE  Ctrl_Cos;						//�����޹�����״̬
	BYTE  Ctrl_Vol;						//�����ѹ����״̬
	WORD  Xfre_space;					//�������ʱ����
	WORD  CPOut_space;					//����Ͷ���˳�ʱ����
	WORD  CPIn_space;					//�����˳�Ͷ��ʱ����
	WORD  Zone_space;					//�������ʱ����
	float  Xfr_overload;				//�������ϵ��
	float  AvcUse_Rate;					//AVC������
	DWORD  AvcClosedTime;				//AVC�ջ�����ʱ��
	DWORD  CtrlNum;						//AVC����ָ����
	DWORD  CtrlSucNum;					//AVC���Ƴɹ���
	float  CtrlSuc_Rate;				//AVC���Ƴɹ���
	DWORD  MaxCtrlNum;					//���ɶ��豸��
	DWORD  CP_RefuseNum;				//�ݿ��ܶ�����
	DWORD  XF_RefuseNum;				//��ѹ���ܶ�����
	float  lossdec;						//�ս�����
}TScadaAVC_AVCCtrRunParam,*LPTScadaAVC_AVCCtrRunParam;
//AVCʱ�ζ����
typedef struct TScadaAVC_AVCTimePart
{
	DWORD  ID;							//���
	char  Name[64];						//ʱ������
	float  VUp1;						//��ѹ����1
	float  VDn1;						//��ѹ����1
	float  CP_Num1;						//���ݿɿش���1
	float  XF_Num1;						//��ѹ���ɿش���1
	float  CosUp1;						//������������1
	float  CosDn1;						//������������1
	CTime  Tm1;							//ʱ��1�ָ��
	float  VUp2;						//��ѹ����2
	float  VDn2;						//��ѹ����2
	float  CP_Num2;						//���ݿɿش���2
	float  XF_Num2;						//��ѹ���ɿش���2
	float  CosUp2;						//������������2
	float  CosDn2;						//������������2
	CTime  Tm2;							//ʱ��2�ָ��
	float  VUp3;						//��ѹ����3
	float  VDn3;						//��ѹ����3
	float  CP_Num3;						//���ݿɿش���3
	float  XF_Num3;						//��ѹ���ɿش���3
	float  CosUp3;						//������������3
	float  CosDn3;						//������������3
	CTime  Tm3;							//ʱ��3�ָ��
	float  VUp4;						//��ѹ����4
	float  VDn4;						//��ѹ����4
	float  CP_Num4;						//���ݿɿش���4
	float  XF_Num4;						//��ѹ���ɿش���4
	float  CosUp4;						//������������4
	float  CosDn4;						//������������4
	CTime  Tm4;							//ʱ��4�ָ��
	float  VUp5;						//��ѹ����5
	float  VDn5;						//��ѹ����5
	float  CP_Num5;						//���ݿɿش���5
	float  XF_Num5;						//��ѹ���ɿش���5
	float  CosUp5;						//������������5
	float  CosDn5;						//������������5
	CTime  Tm5;							//ʱ��1�ָ��
	float  VUp6;						//��ѹ����6
	float  VDn6;						//��ѹ����6
	float  CP_Num6;						//���ݿɿش���6
	float  XF_Num6;						//��ѹ���ɿش���6
	float  CosUp6;						//������������6
	float  CosDn6;						//������������6
	CTime  LogTime;						//����ʱ��
}TScadaAVC_AVCTimePart,*LPTScadaAVC_AVCTimePart;
//AVC�澯���ͱ�
typedef struct TScadaAVC_AVCWarnType
{
	DWORD  KeyID;						//���
	DWORD  ID;							//�澯ID
	char  TypeName[24];					//�澯����
	short  ot;							//�澯�豸����
	char  txt[32];						//�澯����
	BYTE  qskip;						//��ֹ�澯��־
	BYTE  qlock;						//�������鷽ʽ
	BYTE  qsend;						//�澯���ͱ�־
	int  deltm;							//������ʱʱ��
}TScadaAVC_AVCWarnType,*LPTScadaAVC_AVCWarnType;
//AVC�澯�����
typedef struct TScadaAVC_AVCWarnInfo
{
	DWORD  StationID;					//��վID
	DWORD  DevID;						//�豸ID
	DWORD  WarnID;						//�澯����ID
	BYTE  qlock;						//�������鷽ʽ
	BYTE  stat;							//����״̬
	WORD  almtype;						//�澯����
	CTime  ontm;						//����ʱ��
	CTime  offtm;						//����ʱ��
	BYTE  IsDone;						//�����־
}TScadaAVC_AVCWarnInfo,*LPTScadaAVC_AVCWarnInfo;
//AVC���������
typedef struct TScadaAVC_AVCRelayInfo
{
	DWORD  StationID;					//��վID
	DWORD  RelayID;						//����ID
	BYTE  state;						//����״̬
	short  qlock;						//�������鷽ʽ
	DWORD  DevId;						//�����豸ID
	CTime  OnTm;						//����ʱ��
	CTime  OffTm;						//����ʱ��
	BYTE  IsDone;						//�����־
}TScadaAVC_AVCRelayInfo,*LPTScadaAVC_AVCRelayInfo;
//AVC���Ʋ��Ա�
typedef struct TScadaAVC_AVCCtrlCmd
{
	DWORD  KeyID;						//���
	CTime  LogTime;						//����ʱ��
	char  DevName[64];					//�豸����
	DWORD  StationID;					//��վID
	DWORD  DevID;						//�豸ID
	DWORD  DevSub;						//�����豸�±�
	CTime  IssTm;						//����ʱ��
	CTime  CmdTm;						//ִ��ʱ��
	char  cause_info[80];				//����ԭ��
	char  result_info[80];				//��ʩ
	char  Cmd_info[120];				//��������
	char  CmdType[8];					//��������
	short  CtrlType;					//��������
	char  rslttype[12];					//����״̬
	BYTE  qcheck;						//����ȷ��
	BYTE  qaut;							//�Կ�����
	DWORD  seq;							//������
	DWORD  ZoneID;						//������ID
	DWORD  resp;						//������
}TScadaAVC_AVCCtrlCmd,*LPTScadaAVC_AVCCtrlCmd;
//AVC���������
typedef struct TScadaAVC_AVCCtrlZone
{
	DWORD  KeyID;						//���
	char  Name[64];						//��������
	DWORD  VovNum;						//��ѹ����Խ����
	DWORD  QovNum;						//�޹�����Խ����
	float  wloss;						//��������ֵ
	DWORD  NormCp;						//�ɿص�����
	DWORD  NormXf;						//�ɿر�ѹ����
	DWORD  LockCp;						//����������
	DWORD  LockXf;						//������ѹ����
	float  VarIn;						//��Ͷ���޹�������
	float  VarOff;						//δͶ���޹�������
	float  Cosfi;						//�ؿڹ�������
	float  score;						//����״̬�÷�
	CTime  LogTime;						//����ʱ��
}TScadaAVC_AVCCtrlZone,*LPTScadaAVC_AVCCtrlZone;
//AVC���򽻻���
typedef struct TScadaAVC_AVCAreaChange
{
	DWORD  KeyID;						//���
	DWORD  objtype;						//��������
	DWORD  objID;						//����ID
	DWORD  objcdID;						//������ID
	float  value;						//����ֵ
	DWORD  datdir;						//���ݴ��䷽��
}TScadaAVC_AVCAreaChange,*LPTScadaAVC_AVCAreaChange;
//AVC�����¼���
typedef struct TScadaAVC_AVCCtrlEvent
{
	DWORD  KeyID;						//���
	char  user[24];						//�û���
	CTime  CmdTime;						//����ʱ��
	char  opefunc[64];					//������
	char  text[120];					//��������
}TScadaAVC_AVCCtrlEvent,*LPTScadaAVC_AVCCtrlEvent;
//AVC��ѹԽ���¼���
typedef struct TScadaAVC_AVCVoltEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//վ��
	DWORD  BusID;						//ĸ��ID
	char  BusName[64];					//ĸ������
	float  val;							//��ѹֵ
	float  limit;						//��ѹ��ֵ
	CTime  EventTime;					//�¼�ʱ��
}TScadaAVC_AVCVoltEvent,*LPTScadaAVC_AVCVoltEvent;
//AVC��ѹ�������¼���
typedef struct TScadaAVC_AVCTransEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//��վ����
	DWORD  TransID;						//��ѹ��ID
	char  TransName[64];				//��ѹ������
	DWORD  WindID;						//��������ID
	CTime  Optime;						//����ʱ��
	WORD  pretap;						//����ǰ��λ
	WORD  afttap;						//������λ
	float  preVol;						//����ǰ��ѹ
	float  aftVol;						//�������ѹ
	char  opttype[8];					//��������
	BYTE  qAVC;							//AVC�����־
	float  preHVol;						//����ǰ��ѹ��ѹ
	float  preHP;						//����ǰ��ѹ�й�
	float  preHQ;						//����ǰ��ѹ�޹�
	float  preMVol;						//����ǰ��ѹ��ѹ
	float  preMP;						//����ǰ��ѹ�й�
	float  preMQ;						//����ǰ��ѹ�޹�
	float  preLVol;						//����ǰ��ѹ��ѹ
	float  preLP;						//����ǰ��ѹ�й�
	float  preLQ;						//����ǰ��ѹ�޹�
	float  aftHVol;						//���ƺ��ѹ��ѹ
	float  aftHP;						//���ƺ��ѹ�й�
	float  aftHQ;						//���ƺ��ѹ�޹�
	float  aftMVol;						//���ƺ���ѹ��ѹ
	float  aftMP;						//���ƺ���ѹ�й�
	float  aftMQ;						//���ƺ���ѹ�޹�
	float  aftLVol;						//���ƺ��ѹ��ѹ
	float  aftLP;						//���ƺ��ѹ�й�
	float  aftLQ;						//���ƺ��ѹ�޹�
	CTime  EventTime;					//�¼�ʱ��
}TScadaAVC_AVCTransEvent,*LPTScadaAVC_AVCTransEvent;
//AVC���ݿ����¼���
typedef struct TScadaAVC_AVCShuntEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//��վ����
	DWORD  ShuntID;						//����ID
	char  ShuntName[64];				//��������
	CTime  opttime;						//����ʱ��
	char  opttype[8];					//��������
	BYTE  qavc;							//AVCָ���־
	BYTE  qopen;						//����������״̬
	float  preVol;						//����ǰ��ѹ
	float  aftVol;						//�������ѹ
	CTime  EventTime;					//�¼�ʱ��
}TScadaAVC_AVCShuntEvent,*LPTScadaAVC_AVCShuntEvent;
//AVCͳ����Ϣ��
typedef struct TScadaAVC_AVCStateInfo
{
	DWORD  KeyID;						//���
	DWORD  DevID;						//�豸ID
	DWORD  StationID;					//��վID
	char  Name[64];						//�豸����
	DWORD  numall;						//�ն�������
	DWORD  numavc;						//�ճɹ�����
	DWORD  numorder;					//���������
	DWORD  numfail;						//��ʧ�ܴ���
	float  sucrate;						//�ճɹ���
	CTime  timelog;						//����ʱ��
}TScadaAVC_AVCStateInfo,*LPTScadaAVC_AVCStateInfo;
//����վ��
typedef struct TScadaAVC_PasStation
{
	DWORD  ID;							//��վID
	char  Name[64];						//��վ����
	DWORD  IsLand;						//����
	CTime  SERunTime;					//״������ʱ��
	BYTE  Error_sta;					//���ϸ������־
	BYTE  Bad_sta;						//�����ݱ�־
	float  Se_rate;						//����ϸ���
}TScadaAVC_PasStation,*LPTScadaAVC_PasStation;
//AVC���в�����
typedef struct TScadaAVC_AVCRunParam
{
	DWORD  ID;							//���
	CTime  srttm;						//��ʼʱ��
	CTime  endtm;						//����ʱ��
	WORD  Type;							//ʱ������
	char  Msg[32];						//ʱ������
	WORD  CPNum;						//���ݿ��ô���
	WORD  XfrNum;						//��ѹ�����ô���
	float  CosUp;						//�ؿڹ�����������
	float  CosDn;						//�ؿڹ�����������
	float  SCosUp;						//��վ������������
	float  SCosDn;						//��վ������������
	float  V6Up;						//6KV����
	float  V6Dn;						//6KV����
	float  V10Up;						//10KV����
	float  V10Dn;						//10KV����
	float  V35Up;						//35KV����
	float  V35Dn;						//35KV����
	float  V110Up;						//110KV����
	float  V110Dn;						//110KV����
	float  V220Up;						//220KV����
	float  V220Dn;						//220KV����
	float  V330Up;						//330KV����
	float  V330Dn;						//330KV����
	CTime  LogTime;						//����ʱ��
}TScadaAVC_AVCRunParam,*LPTScadaAVC_AVCRunParam;
//=================TAssessAVC===============
//����SE������
typedef struct TAssessAVC_PasSEParam
{
	CTime  RunTime;						//����ʱ��
	BYTE  Conv_State;					//��ǰ����״̬
	float  Measure_Rate;				//ң�⸲����
	float  SE_Rate;						//��ǰ״���ϸ���
	char  RunInfo[86];					//������Ϣ
}TAssessAVC_PasSEParam,*LPTAssessAVC_PasSEParam;
//AVC��վ��Ϣ��
typedef struct TAssessAVC_AVCStation
{
	DWORD  ID;							//��վID
	char  Name[64];						//��վ����
	DWORD  Zone;						//����ID
	BYTE  CtrlOut;						//�����˳�
	BYTE  AVCCtrl;						//AVC�Զ�����
	DWORD  CtrlID;						//����ʱ�α��
	WORD  Lock_Num;						//��վ���������ۼ�
	DWORD  DevLock_Num;					//��վ�豸���������ۼ�
	float  VL;							//��ѹ�ȼ�
	float  DVolRate;					//���յ�ѹ�ϸ���
	float  DCosRate;					//���չ��������ϸ���
	DWORD  DVAll_Time;					//�յ�ѹ��ʱ��
	DWORD  DVOut_Time;					//�յ�ѹԽ��ʱ��
	DWORD  DCAll_Time;					//�չ�����ʱ��
	DWORD  DCOut_Time;					//�չ���Խ��ʱ��
	float  H24VolRate;					//24Сʱ��ѹ�ϸ���
	float  H24CosRate;					//24Сʱ���ʺϸ���
	DWORD  H24VAll_Time;				//�յ�ѹ��ʱ��
	DWORD  H24VOut_Time;				//�յ�ѹԽ��ʱ��
	DWORD  H24CAll_Time;				//�չ�����ʱ��
	DWORD  H24COut_Time;				//�չ���Խ��ʱ��
	DWORD  DActNum;						//�ն�����
	DWORD  DAvcCtrlNum;					//��AVC������
	DWORD  DAvcActNum;					//��AVC������
	DWORD  H24ActNum;					//24Сʱ������
	DWORD  H24AvcCtrlNum;				//��AVC������
	DWORD  H24AvcActNum;				//��AVC������
	CTime  LogTime;						//����ʱ��
}TAssessAVC_AVCStation,*LPTAssessAVC_AVCStation;
//AVCĸ����Ϣ��
typedef struct TAssessAVC_AVCBus
{
	DWORD  BusID;						//ĸ��ID
	DWORD  ZoneID;						//����ID
	DWORD  StationID;					//��վID
	char  Name[64];						//ĸ������
	float  VL;							//��ѹ�ȼ�
	DWORD  CtrlID;						//����ʱ�α��
	BYTE  IsGate;						//�ؿڱ�ʶ
	BYTE  Run_Sta;						//����״̬
	BYTE  Ctr_Sta;						//�Ƿ����
	BYTE  Cal_Sta;						//�Ƿ�������
	BYTE  Limit_Sta;					//Խ��״̬
	BYTE  Lock_Sta;						//����״̬
	float  Volup;						//��ѹ����
	float  Voldn;						//��ѹ����
	float  Cosup;						//��������
	float  Cosdn;						//��������
	WORD  DLock_Num;					//���������ۼ�
	WORD  DLock_Time;					//���������ۼ�ʱ��
	float  DVolmax;						//�յ�ѹ
	float  DVolmin;						//�յ�ѹ
	float  DLoadP;						//ĸ�߸����й�
	float  DLoadQ;						//ĸ�߸����޹�
	int  DVolEvent;						//Խ���¼���
	int  DCtrlEvent;					//�����¼���
	float  DVol_rate;					//�յ�ѹ�ϸ���
	DWORD  DAll_Time;					//����ʱ��
	DWORD  DOut_Time;					//��Խ��ʱ��
	WORD  H24Lock_Num;					//���������ۼ�
	WORD  H24Lock_Time;					//���������ۼ�ʱ��
	float  H24Volmax;					//�յ�ѹ
	float  H24Volmin;					//�յ�ѹ
	int  H24VolEvent;					//Խ���¼���
	int  H24CtrlEvent;					//�����¼���
	float  H24Vol_rate;					//24Сʱ��ѹ�ϸ���
	DWORD  H24All_Time;					//24Сʱ��ʱ��
	DWORD  H24Out_Time;					//24СʱԽ��ʱ��
	CTime  LogTime;						//��ǰ����ʱ��
}TAssessAVC_AVCBus,*LPTAssessAVC_AVCBus;
//AVC��ѹ����Ϣ��
typedef struct TAssessAVC_AVCTrans
{
	DWORD  ID;							//��ѹ��ID
	DWORD  ZoneID;						//����ID
	DWORD  StationID;					//��վID
	char  Name[64];						//��ѹ������
	DWORD  CtrlID;						//����ʱ��ID
	BYTE  Run_Sta;						//����״̬
	BYTE  Ctrl_Sta;						//������Ʊ�ʶ
	BYTE  Lock_Sta;						//����״̬
	BYTE  Limit_Sta;					//Խ��״̬
	DWORD  BusHID;						//��ѹĸ��ID
	DWORD  BusMID;						//��ѹĸ��ID
	DWORD  BusLID;						//��ѹĸ��ID
	BYTE  IsGate;						//�ؿڱ�ѹ��
	float  Cosup;						//��������
	float  Cosdn;						//��������
	WORD  DCtrlLimitNum;				//������ֵ����
	WORD  DTimeLimitNum;				//��ǰʱ����ֵ����
	float  DHiP;						//��ѹ�й�
	float  DHiQ;						//��ѹ�޹�
	float  DMaxS;						//����߸���
	float  DCosRate;					//���������ϸ���
	WORD  DLock_Num;					//��������
	WORD  DLock_Time;					//���������ۼ�ʱ��
	float  DAll_Time;					//��ʱ��
	float  DOut_Time;					//��ʱ��
	DWORD  DActNum;						//�տ��ƴ���
	DWORD  DAVCCtrlNum;					//��AVC���ƴ���
	DWORD  DAVCActNum;					//��AVC��������
	WORD  H24CtrlLimit;					//�տ�����ֵ����
	float  H24CosRate;					//24Сʱ���������ϸ���
	float  H24MaxS;						//����߸���
	float  H24All_Time;					//��ʱ��
	float  H24Out_Time;					//��ʱ��
	WORD  H24Lock_Num;					//��������
	WORD  H24Lock_Time;					//���������ۼ�ʱ��
	DWORD  H24ActNum;					//24Сʱ���ƴ���
	DWORD  H24AVCCtrlNum;				//24СʱAVC���ƴ���
	DWORD  H24AVCActNum;				//24СʱAVC��������
	CTime  LogTime;						//����ʱ��
}TAssessAVC_AVCTrans,*LPTAssessAVC_AVCTrans;
//AVC�޹��豸��Ϣ��
typedef struct TAssessAVC_AVCShunt
{
	DWORD  ID;							//����ID
	DWORD  ZoneID;						//��վID
	DWORD  StationID;					//��վID
	char  Name[64];						//��������
	float  VL;							//��ѹ�ȼ�
	DWORD  CtrlID;						//����ʱ��ID
	BYTE  Run_Sta;						//����״̬
	BYTE  Ctrl_Sta;						//����״̬
	BYTE  Lock_Sta;						//����״̬
	DWORD  BreakerID;					//����ID
	DWORD  BusID;						//����ĸ��ID
	DWORD  BreakID;						//���ƿ���ID
	WORD  DayLimitNum;					//������������
	WORD  TimeLimitNum;					//ʱ�����ƴ���
	BYTE  DLock_Num;					//��������
	BYTE  DLock_Time;					//����ʱ��
	DWORD  DActNum;						//�ն�������
	DWORD  DAVCCtrlNum;					//��AVC��������
	DWORD  DAVCActNum;					//��AVC��������
	DWORD  DRunTime;					//������ʱ��
	float  DAll_Time;					//��ʱ��
	DWORD  H24ActNum;					//24Сʱ��������
	DWORD  H24AVCCtrlNum;				//24СʱAVC��������
	DWORD  H24AVCActNum;				//24СʱAVC��������
	WORD  H24LimitNum;					//������������
	DWORD  H24RunTime;					//24Сʱ����ʱ��
	float  H24All_Time;					//��ʱ��
	BYTE  H24Lock_Num;					//��������
	BYTE  H24Lock_Time;					//����ʱ��
	CTime  LogTime;						//����ʱ��
}TAssessAVC_AVCShunt,*LPTAssessAVC_AVCShunt;
//AVCϵͳͳ�Ʊ�
typedef struct TAssessAVC_AVCSystem
{
	CTime  SysTime;						//ͳ��ʱ��
	char  Name[120];					//��������
	BYTE  AVC_Sta;						//AVC����״̬
	BYTE  AVCCtrl_Sta;					//AVC����״̬
	BYTE  AVCAll_Time;					//AVC������ʱ��
	BYTE  AVCOpen_Time;					//AVC�����˳�ʱ��
	float  Vol_rate;					//��ѹ�ϸ���
	float  Cos_rate;					//�޹��ϸ���
	float  Loss_P;						//��ǰ�й������ܼ�
	float  Loss_Q;						//��ǰ�޹������ܼ�
	float  Gen_P;						//������й��ܼ�
	float  Gen_Q;						//������޹��ܼ�
	float  Load_P;						//�����й��ܼ�
	float  Load_Q;						//�����޹��ܼ�
	float  Trans_P;						//��ѹ���й��ܼ�
	float  Trans_Q;						//��ѹ���޹��ܼ�
	float  Line_P;						//��·�й��ܼ�
	float  Line_Q;						//��·�޹��ܼ�
	float  lossdec;						//AVC�ս�����
	DWORD  AVCLock_Num;					//AVC����������
	DWORD  DevLock_Num;					//�豸����������
	DWORD  Shunt_Ctrl;					//�޹�������
	DWORD  Trans_Ctrl;					//��ѹ��������
	DWORD  CtrlAll_Num;					//��������
	DWORD  CtrlFail_Num;				//����ʧ������
	DWORD  CP_RefuseNum;				//�ݿ��ܶ�����
	DWORD  XF_RefuseNum;				//��ѹ���ܶ�����
	float  AvcUse_Rate;					//AVC������
	float  H24Vol_rate;					//��ѹ�ϸ���
	float  H24Cos_rate;					//�޹��ϸ���
	float  H24lossdec;					//AVC�ս�����
	DWORD  H24Shunt_Ctrl;				//�޹�������
	DWORD  H24Trans_Ctrl;				//��ѹ��������
	DWORD  H24Ctrl_Num;					//��������
	DWORD  H24Fail_Num;					//����ʧ������
	DWORD  H24CP_RefNum;				//�ݿ��ܶ�����
	DWORD  H24XF_RefNum;				//��ѹ���ܶ�����
	float  H24AvcUse_Rate;				//AVC������
	BYTE  H24AVC_Time;					//AVC������ʱ��
	BYTE  H24Open_Time;					//AVC�����˳�ʱ��
	CTime  LogTime;						//����ʱ��
}TAssessAVC_AVCSystem,*LPTAssessAVC_AVCSystem;
//AVC�澯�����
typedef struct TAssessAVC_AVCWarnInfo
{
	DWORD  StationID;					//��վID
	DWORD  DevID;						//�豸ID
	DWORD  WarnID;						//�澯ID
	BYTE  WarnType;						//�澯����/����
	char  WarnInfo[32];					//�澯��������
	BYTE  lockstat;						//����״̬
	CTime  ontm;						//����ʱ��
	CTime  offtm;						//����ʱ��
}TAssessAVC_AVCWarnInfo,*LPTAssessAVC_AVCWarnInfo;
//AVC���Ʋ��Ա�
typedef struct TAssessAVC_AVCCtrlCmd
{
	DWORD  KeyID;						//���
	CTime  LogTime;						//����ʱ��
	char  DevName[64];					//�豸����
	DWORD  StationID;					//��վID
	DWORD  DevID;						//�豸ID
	DWORD  DevSub;						//�����豸�±�
	CTime  IssTm;						//����ʱ��
	CTime  CmdTm;						//ִ��ʱ��
	char  cause_info[80];				//����ԭ��
	char  result_info[80];				//��ʩ
	char  Cmd_info[120];				//��������
	char  CmdType[8];					//��������
	short  CtrlType;					//��������
	char  rslttype[12];					//����״̬
	BYTE  qcheck;						//����ȷ��
	BYTE  qaut;							//�Կ�����
	DWORD  seq;							//������
	DWORD  ZoneID;						//������ID
	DWORD  resp;						//������
}TAssessAVC_AVCCtrlCmd,*LPTAssessAVC_AVCCtrlCmd;
//AVC���������
typedef struct TAssessAVC_AVCCtrlZone
{
	DWORD  KeyID;						//���
	char  Name[64];						//��������
	DWORD  VovNum;						//��ѹ����Խ����
	DWORD  QovNum;						//�޹�����Խ����
	float  wloss;						//��������ֵ
	DWORD  NormCp;						//�ɿص�����
	DWORD  NormXf;						//�ɿر�ѹ����
	DWORD  LockCp;						//����������
	DWORD  LockXf;						//������ѹ����
	float  VarIn;						//��Ͷ���޹�������
	float  VarOff;						//δͶ���޹�������
	float  Cosfi;						//�ؿڹ�������
	float  score;						//����״̬�÷�
}TAssessAVC_AVCCtrlZone,*LPTAssessAVC_AVCCtrlZone;
//AVC�����¼���
typedef struct TAssessAVC_AVCCtrlEvent
{
	DWORD  KeyID;						//���
	char  user[24];						//�û���
	CTime  CmdTime;						//����ʱ��
	char  opefunc[64];					//������
	char  text[120];					//��������
}TAssessAVC_AVCCtrlEvent,*LPTAssessAVC_AVCCtrlEvent;
//AVC��ѹԽ���¼���
typedef struct TAssessAVC_AVCVoltEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//վ��
	BYTE  DevType;						//�豸����
	DWORD  DevID;						//�豸ID
	char  DevName[64];					//�豸����
	float  val;							//��ֵ
	float  limitdn;						//��ֵ
	float  limitup;						//��ֵ
	BYTE  ByScada;						//�¼���Դ1��Դ��SCADA
	CTime  EventTime;					//�¼�ʱ��
	CTime  OffTime;						//����ʱ��
	DWORD  CmdID;						//�����¼�ID
}TAssessAVC_AVCVoltEvent,*LPTAssessAVC_AVCVoltEvent;
//AVC��ѹ�������¼���
typedef struct TAssessAVC_AVCTransEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//��վ����
	DWORD  TransID;						//��ѹ��ID
	char  TransName[64];				//��ѹ������
	DWORD  WindID;						//��������ID
	CTime  Optime;						//����ʱ��
	WORD  pretap;						//����ǰ��λ
	WORD  afttap;						//������λ
	float  preVol;						//����ǰ��ѹ
	float  aftVol;						//�������ѹ
	char  opttype[20];					//��������
	BYTE  qAVC;							//AVC�����־
	float  preHVol;						//����ǰ��ѹ��ѹ
	float  preHP;						//����ǰ��ѹ�й�
	float  preHQ;						//����ǰ��ѹ�޹�
	float  preMVol;						//����ǰ��ѹ��ѹ
	float  preMP;						//����ǰ��ѹ�й�
	float  preMQ;						//����ǰ��ѹ�޹�
	float  preLVol;						//����ǰ��ѹ��ѹ
	float  preLP;						//����ǰ��ѹ�й�
	float  preLQ;						//����ǰ��ѹ�޹�
	float  aftHVol;						//���ƺ��ѹ��ѹ
	float  aftHP;						//���ƺ��ѹ�й�
	float  aftHQ;						//���ƺ��ѹ�޹�
	float  aftMVol;						//���ƺ���ѹ��ѹ
	float  aftMP;						//���ƺ���ѹ�й�
	float  aftMQ;						//���ƺ���ѹ�޹�
	float  aftLVol;						//���ƺ��ѹ��ѹ
	float  aftLP;						//���ƺ��ѹ�й�
	float  aftLQ;						//���ƺ��ѹ�޹�
	BYTE  ByScada;						//�¼���Դ1��Դ��SCADA
	CTime  EventTime;					//�¼�ʱ��
	DWORD  CmdID;						//�����¼�ID
}TAssessAVC_AVCTransEvent,*LPTAssessAVC_AVCTransEvent;
//AVC���ݿ����¼���
typedef struct TAssessAVC_AVCShuntEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//��վ����
	DWORD  ShuntID;						//����ID
	char  ShuntName[64];				//��������
	CTime  opttime;						//����ʱ��
	char  opttype[20];					//��������
	BYTE  qavc;							//AVCָ���־
	BYTE  qopen;						//����������״̬
	float  preVol;						//����ǰ��ѹ
	float  aftVol;						//�������ѹ
	BYTE  ByScada;						//�¼���Դ1��Դ��SCADA
	CTime  EventTime;					//�¼�ʱ��
	DWORD  CmdID;						//�����¼�ID
}TAssessAVC_AVCShuntEvent,*LPTAssessAVC_AVCShuntEvent;
//AVC���в�����
typedef struct TAssessAVC_AVCRunParam
{
	DWORD  ID;							//���
	CTime  srttm;						//��ʼʱ��
	CTime  endtm;						//����ʱ��
	WORD  Type;							//ʱ������
	char  Msg[32];						//ʱ������
	WORD  CPNum;						//���ݿ��ô���
	WORD  XfrNum;						//��ѹ�����ô���
	float  CosUp;						//�ؿڹ�����������
	float  CosDn;						//�ؿڹ�����������
	float  SCosUp;						//��վ������������
	float  SCosDn;						//��վ������������
	float  V6Up;						//6KV����
	float  V6Dn;						//6KV����
	float  V10Up;						//10KV����
	float  V10Dn;						//10KV����
	float  V35Up;						//35KV����
	float  V35Dn;						//35KV����
	float  V110Up;						//110KV����
	float  V110Dn;						//110KV����
	float  V220Up;						//220KV����
	float  V220Dn;						//220KV����
	float  V330Up;						//330KV����
	float  V330Dn;						//330KV����
	CTime  LogTime;						//����ʱ��
}TAssessAVC_AVCRunParam,*LPTAssessAVC_AVCRunParam;
//AVCʱ�ζ����
typedef struct TAssessAVC_AVCTimePart
{
	DWORD  ID;							//���
	char  Name[64];						//ʱ������
	float  VUp1;						//��ѹ����1
	float  VDn1;						//��ѹ����1
	float  CP_Num1;						//���ݿɿش���1
	float  XF_Num1;						//��ѹ���ɿش���1
	float  CosUp1;						//������������1
	float  CosDn1;						//������������1
	CTime  Tm1;							//ʱ��1�ָ��
	float  VUp2;						//��ѹ����2
	float  VDn2;						//��ѹ����2
	float  CP_Num2;						//���ݿɿش���2
	float  XF_Num2;						//��ѹ���ɿش���2
	float  CosUp2;						//������������2
	float  CosDn2;						//������������2
	CTime  Tm2;							//ʱ��2�ָ��
	float  VUp3;						//��ѹ����3
	float  VDn3;						//��ѹ����3
	float  CP_Num3;						//���ݿɿش���3
	float  XF_Num3;						//��ѹ���ɿش���3
	float  CosUp3;						//������������3
	float  CosDn3;						//������������3
	CTime  Tm3;							//ʱ��3�ָ��
	float  VUp4;						//��ѹ����4
	float  VDn4;						//��ѹ����4
	float  CP_Num4;						//���ݿɿش���4
	float  XF_Num4;						//��ѹ���ɿش���4
	float  CosUp4;						//������������4
	float  CosDn4;						//������������4
	CTime  Tm4;							//ʱ��4�ָ��
	float  VUp5;						//��ѹ����5
	float  VDn5;						//��ѹ����5
	float  CP_Num5;						//���ݿɿش���5
	float  XF_Num5;						//��ѹ���ɿش���5
	float  CosUp5;						//������������5
	float  CosDn5;						//������������5
	CTime  Tm5;							//ʱ��1�ָ��
	float  VUp6;						//��ѹ����6
	float  VDn6;						//��ѹ����6
	float  CP_Num6;						//���ݿɿش���6
	float  XF_Num6;						//��ѹ���ɿش���6
	float  CosUp6;						//������������6
	float  CosDn6;						//������������6
	CTime  LogTime;						//����ʱ��
}TAssessAVC_AVCTimePart,*LPTAssessAVC_AVCTimePart;
//AVC�����¼���
typedef struct TAssessAVC_AVCLossEvent
{
	DWORD  KeyID;						//���
	DWORD  StationID;					//��վID
	char  StationName[64];				//վ��
	char  Name[64];						//����
	float  val1;						//����ֵ1
	float  val2;						//����ֵ2
	BYTE  ByScada;						//�¼���Դ1��Դ��SCADA
	CTime  EventTime;					//�¼�ʱ��
	DWORD  CmdID;						//�����¼�ID
}TAssessAVC_AVCLossEvent,*LPTAssessAVC_AVCLossEvent;
//AVCʵʱ�������ܱ�
typedef struct TAssessAVC_RealAVCCapably
{
	DWORD  NU;							//���
	char  Type[64];						//�������
	char  Name[64];						//����
	float  Value;						//��ֵ
}TAssessAVC_RealAVCCapably,*LPTAssessAVC_RealAVCCapably;
#endif