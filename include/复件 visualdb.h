#if !defined(_DB_STRUCT_H_)
#define _DB_STRUCT_H_
/************************************************/
//��ͷ�ļ��ɡ����ݿ����������Զ�����
//2013-1-9
//�Ǻ��߿Ƽ���ҵ�ɷ����޹�˾
/************************************************/
//����Ԥ����ֵ
//=================���ӻ�����ϵͳ��===============
//PT��
typedef struct visualpw_PT
{
	DWORD  NU;							//PT���
	char  Name[64];						//PT����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[32];						//��ʶ
}visualpw_PT,*LPvisualpw_PT;
//�����
typedef struct visualpw_Gen
{
	DWORD  NU;							//�������
	char  Name[64];						//�������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  vl;							//��ѹ�ȼ�
	BYTE  Type;							//����
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
	float  angle;						//�Ƕ�
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	float  Qmax;						//�������޹�
	float  Qmaxi;						//�������޹�
	int  Synsta;						//�ۺ�״̬
	char  ID[32];						//��ʶ
	DWORD  Node;						//�ڵ�
	char  ControlArea[32];				//���ȹ�ϵ
	float  UtilizationHou;				//����Сʱ��
	float  Suffocate;					//��������
	float  Electrovalency;				//������
	CTime  OperationTime;				//Ͷ��ʱ��
	BYTE  AGCsta;						//AGC״̬
	float  TimingSpeed;					//�����������
	float  TimingSpeed1;				//�����������
	float  UpWhirl;						//��������
	float  DownWhirl;					//��������
}visualpw_Gen,*LPvisualpw_Gen;
//���ص�բ
typedef struct visualpw_Switch
{
	DWORD  NU;							//���ر��
	char  Name[64];						//��������
	DWORD  Station;						//����վ
	float  vl;							//��ѹ�ȼ�
	BYTE  Type;							//����
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	int  Synsta;						//�ۺ�״̬
	char  ID[32];						//��ʶ
	DWORD  Node1;						//�ڵ�1
	DWORD  Node2;						//�ڵ�2
	CTime  ShiftTime;					//��λʱ��
}visualpw_Switch,*LPvisualpw_Switch;
//����
typedef struct visualpw_Load
{
	DWORD  NU;							//���ɱ��
	char  Name[64];						//��������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  vl;							//��ѹ�ȼ�
	float  MaxP;						//�й�����
	float  MinP;						//�й�����
	float  P;							//�й�����
	float  Q;							//�޹�����
	float  I;							//����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	int  Synsta;						//�ۺ�״̬
	char  ID[32];						//��ʶ
	DWORD  Node;						//�ڵ�
}visualpw_Load,*LPvisualpw_Load;
//����
typedef struct visualpw_Shunt
{
	DWORD  NU;							//�����豸���
	char  Name[64];						//�����豸����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  vl;							//��ѹ�ȼ�
	float  Q;							//Ͷ���޹�
	float  Qmax;						//����޹����
	float  I;							//����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	float  Qchk;						//��������
	int  Synsta;						//�ۺ�״̬
	char  ID[32];						//��ʶ
	DWORD  Node1;						//�ڵ�1
	DWORD  Node2;						//�ڵ�2
}visualpw_Shunt,*LPvisualpw_Shunt;
//�翹
typedef struct visualpw_Sreact
{
	DWORD  NU;							//�翹�����
	char  Name[64];						//�翹����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  vl;							//��ѹ�ȼ�
	float  Qmax;						//����޹����
	float  Zx;							//Ͷ��翹
	float  I;							//����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	int  Synsta;						//�ۺ�״̬
	char  ID[32];						//��ʶ
	DWORD  Node1;						//�ڵ�1
	DWORD  Node2;						//�ڵ�2
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
	float  vl_H;						//��ѹ���ѹ�ȼ�
	float  vl_L;						//��ѹ���ѹ�ȼ�
	float  tap;							//��ѹ���ֽ�ͷ
	float  Pmax;						//��ѹ���������
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
	int  Synsta;						//�ۺ�״̬
	char  ID[32];						//��ʶ
	DWORD  Node1;						//�ڵ�1
	DWORD  Node2;						//�ڵ�2
	float  UtilizationHou;				//����Сʱ��
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
	float  vl_H;						//��ѹ���ѹ�ȼ�
	float  vl_M;						//��ѹ���ѹ�ȼ�
	float  vl_L;						//��ѹ���ѹ�ȼ�
	float  TapH;						//�߶˷ֽ�ͷλ��
	float  TapM;						//�ж˷ֽ�ͷλ��
	float  TapL;						//�Ͷ˷ֽ�ͷλ��
	float  Pmax;						//��ѹ���������
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
	int  Synsta;						//�ۺ�״̬
	char  ID[32];						//��ʶ
	DWORD  NodeH;						//��ѹ�ڵ�
	DWORD  NodeM;						//��ѹ�ڵ�
	DWORD  NodeL;						//��ѹ�ڵ�
	float  UtilizationHou;				//����Сʱ��
}visualpw_Tfm2,*LPvisualpw_Tfm2;
//��̬�޹�����
typedef struct visualpw_SVC
{
	DWORD  NU;							//SVC���
	char  Name[24];						//SVC����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Qmax;						//����޹����
	float  Qmin;						//��С�޹����
	float  Q;							//�޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  Tsta;							//����״̬
	char  ID[32];						//��ʶ
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
	DWORD  Node;						//�ڵ�
	float  PreVlo;						//Ԥ��ʹ�õ�����
	float  vl;							//��ѹ�ȼ�
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
	int  Synsta;						//�ۺ�״̬
	char  ID[32];						//��ʶ
}visualpw_Bus,*LPvisualpw_Bus;
//������
typedef struct visualpw_Line
{
	DWORD  NU;							//�����߱��
	char  Name[64];						//����������
	DWORD  Station;						//����վ
	int  Zonef;							//��ʼ�������
	int  Zonet;							//�յ��������
	float  vl;							//��ѹ�ȼ�
	float  Imax;						//�������ֵ
	float  MaxP;						//�й�����
	float  Par;							//����߸����ʸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
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
	int  Synsta;						//�ۺ�״̬
	char  ID[32];						//��ʶ
	DWORD  NodeF;						//�׶˽ڵ�
	DWORD  NodeT;						//ĩ�˽ڵ�
}visualpw_Line,*LPvisualpw_Line;
//ֱ����
typedef struct visualpw_DCLine
{
	DWORD  NU;							//ֱ���߱��
	char  Name[24];						//ֱ��������
	DWORD  Station;						//����վ
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
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[32];						//��ʶ
	DWORD  NodeF;						//�׶˽ڵ�
	DWORD  NodeT;						//ĩ�˽ڵ�
}visualpw_DCLine,*LPvisualpw_DCLine;
//�������������
typedef struct visualpw_CVT
{
	DWORD  NU;							//�豸���
	char  Name[24];						//�豸����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  Tsta;							//����״̬
	char  ID[32];						//��ʶ
}visualpw_CVT,*LPvisualpw_CVT;
//����
typedef struct visualpw_Zone
{
	DWORD  NU;							//������
	char  Name[64];						//��������
	float  progen_generat;				//ʡ�������ܳ���
	float  total_load;					//ȫ���ܸ���
	float  UpSpare;						//ʵʱ��������
	float  DownSpare;					//ʵʱ��������
	float  progenvalue;					//ʡ��װ������
	float  transvalue;					//�����������
	char  ID[32];						//��ʶ
}visualpw_Zone,*LPvisualpw_Zone;
//վ
typedef struct visualpw_Station
{
	DWORD  NU;							//վ��
	char  Name[64];						//վ��
	DWORD  zoneNU;						//��������
	BYTE  Type;							//��վ����
	float  vl;							//��ѹ�ȼ�
	int  Synsta;						//�ۺ�״̬
	char  ID[32];						//��ʶ
	char  ControlArea[32];				//���ȹ�ϵ
	BYTE  Property;						//��Ȩ
	char  Subjection[32];				//��������
	float  LastPower;					//��úˮλ
	CTime  LastPowerRTime;				//��úˮλ�ϱ�ʱ��
	float  LastPowerTime;				//��úˮλʹ��ʱ��(Сʱ)
	char  PW0FileName[32];				//��վ��ӦPW0�ļ���
}visualpw_Station,*LPvisualpw_Station;
//���ڵ��ѹ����
typedef struct visualpw_VotOutage
{
	int  NU;							//�豸���
	char  type;							//�豸����
	float  Defl;						//��ѹƫ����
}visualpw_VotOutage,*LPvisualpw_VotOutage;
//��֧·����
typedef struct visualpw_LineOutage
{
	int  NU;							//�豸���
	char  type;							//����
	float  Defl;						//��ѹƫ����
}visualpw_LineOutage,*LPvisualpw_LineOutage;
//�ڵ��ѹ��֧·�ϳ�
typedef struct visualpw_AllOutage
{
	int  NU;							//�豸���
	char  type;							//����
	float  Defl;						//������
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
//ACE
typedef struct visualpw_ACE
{
	DWORD  ID;							//��ʶID
	float  CurVal;						//��ǰֵ
	CTime  datatime;					//����ʱ��
	BYTE  alarm;						//�澯
	BYTE  ack;							//ȷ��
	float  Index;						//ָ��
}visualpw_ACE,*LPvisualpw_ACE;
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
	char  Name[24];						//����
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
	char  Name[64];						//��������
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
	int  Synsta;						//�ۺ�״̬
}visualpw_Area,*LPvisualpw_Area;
//Ӧ�ò���
typedef struct visualpw_AppParam
{
	float  OverRate;					//������
	float  HisMaxLoad;					//��ʷ��󸺺�
}visualpw_AppParam,*LPvisualpw_AppParam;
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
//���ޱ�
typedef struct visualpw_DevRepair
{
	CTime  RecTime;						//�Ǽ�ʱ��
	DWORD  DevNU;						//�豸���
	BYTE  DevType;						//�豸����
	DWORD  Station;						//��վ
	CTime  StartTime;					//������ʼʱ��
	CTime  EndTime;						//���޽���ʱ��
	BYTE  State;						//��Ч��ʶ
	char  Comment[512];					//ע������
	DWORD  GroundDevNU;					//�ӵ��豸���
	BYTE  GroundDevType;				//�ӵ��豸����
}visualpw_DevRepair,*LPvisualpw_DevRepair;
//���Ʊ�
typedef struct visualpw_SignBrand
{
	CTime  RecTime;						//�Ǽ�ʱ��
	BYTE  SignType;						//��������
	DWORD  DevNU;						//�豸���
	BYTE  DevType;						//�豸����
	BYTE  State;						//��Ч��ʶ
	char  Comment[512];					//ע������
	DWORD  GroundDevNU;					//�ӵ��豸���
	BYTE  GroundDevType;				//�ӵ��豸����
}visualpw_SignBrand,*LPvisualpw_SignBrand;
//������Ϣ��
typedef struct visualpw_Protector
{
	DWORD  DNu;							//�����豸���
	char  Name[64];						//��������
	DWORD  Station;						//��վ
	BYTE  DevType;						//�����豸���
	BYTE  Alarm;						//�澯����
	BYTE  State;						//�澯״̬
	char  Comment[256];					//��ע��Ϣ
	CTime  EventTime;					//��������ʱ��
	short  MilliSecond;					//��������ʱ��(����)
}visualpw_Protector,*LPvisualpw_Protector;
//ѹ����Ϣ��
typedef struct visualpw_KeepPlate  
{
	DWORD  NU;							//ѹ����
	DWORD  Station;						//���ڳ�վ
	DWORD  Border;						//��������
	char  Name[64];						//ѹ������
	BYTE  State;						//ѹ��Ͷ��״̬
	BYTE  MisState;						//ѹ����Ͷ��״̬
	DWORD  StatePos;					//ѹ��Ͷ��״̬���
	DWORD  MisStatePos;					//ѹ����Ͷ��״̬���
}visualpw_KeepPlate  ,*LPvisualpw_KeepPlate  ;
//����Ԥ����Ԥ���
typedef struct visualpw_ForcastPlan
{
	CTime  PlanTime;					//�ƻ�����ʱ��
	BYTE  PlanType;						//�ƻ����ͣ�Ԥ�⡢�ƻ���
	DWORD  DevID;						//Ԥ��ƻ��豸ID
	float  PlanValue;					//Ԥ��ƻ�ֵ
	DWORD  Index;						//�ƻ����
	float  RealValue;					//ʵ��ֵ
}visualpw_ForcastPlan,*LPvisualpw_ForcastPlan;
//����ƻ���
typedef struct visualpw_GenPlan
{
	CTime  PlanTime;					//�ƻ�ʱ��
	DWORD  GenID;						//�������
	double  PlanValue;					//�ƻ�ֵ
	float  RealValue;					//ʵ��ֵ
}visualpw_GenPlan,*LPvisualpw_GenPlan;
//ϵͳ���ݱ�
typedef struct visualpw_SystemData
{
	DWORD  ID;							//���
	char  Name[64];						//����
	float  Value;						//��ֵ
	float  MaxValue;					//�����ֵ
	float  MinValue;					//��С��ֵ
}visualpw_SystemData,*LPvisualpw_SystemData;
//AGC��
typedef struct visualpw_AGC
{
	DWORD  NU;							//���
	char  Name[64];						//��������
	float  MaxP;						//װ������
	float  Index;						//��������
}visualpw_AGC,*LPvisualpw_AGC;
//�ӵص�բ
typedef struct visualpw_GND
{
	DWORD  NU;							//���ر��
	char  Name[64];						//��������
	DWORD  Station;						//����վ
	float  vl;							//��ѹ�ȼ�
	BYTE  Type;							//����
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	int  Synsta;						//�ۺ�״̬
	char  ID[32];						//��ʶ
	DWORD  Node1;						//�ڵ�1
	DWORD  Node2;						//�ڵ�2
	CTime  ShiftTime;					//��λʱ��
}visualpw_GND,*LPvisualpw_GND;
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
	BYTE  FType;						//Ԥ������
	float  FValue;						//����Ԥ��ֵ
	float  RValue;						//����ʵ��ֵ
	CTime  hour;						//Ԥ��ֵʱ��
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
	DWORD  MNu;							//���
	DWORD  VNu1;						//���ӻ��е��豸ID1
	char  MName[64];					//��������
	char  VName1[64];					//�豸����1
	char  MeasID[64];					//�����ʶ
	BYTE  DevType1;						//�豸����1
	BYTE  MeasType;						//��������
	BYTE  MeasPos1;						//����λ��1
	DWORD  Station;						//����վ��
	BYTE  quality;						//������־
	DWORD  VNu2;						//���ӻ��е��豸ID2
	char  VName2[64];					//�豸����2
	BYTE  DevType2;						//�豸����2
	BYTE  MeasPos2;						//����λ��2
}common_Relation,*LPcommon_Relation;
//Ԥ������泱��
typedef struct common_PreDefSF
{
	DWORD  ID;							//����ID
	char  Name[45];						//��������
	float  curval;						//��ǰ����ֵ
	float  Vmax;						//����������ֵ
	float  Vmin;						//��������Сֵ
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
//�ֶ�˵��
typedef struct common_Field
{
	DWORD  shTableNo;					//����
	short  shFieldNo;					//�ֶα��
	char  szFieldName[50];				//�ֶ���
	BYTE  byDataType;					//��������
	short  shFieldAttrib;				//����
	float  szDefaultVal;				//ȱʡֵ
	float  szMaxVal;					//���ֵ
	float  szMinVal;					//��Сֵ
	char  szEnumString[100];				//ö���ַ���
}common_Field,*LPcommon_Field;
//�������
typedef struct common_UnEquMeas
{
	DWORD  NU;							//���
	char  Name[64];						//����
	float  max;							//���ֵ
	float  min;							//��Сֵ
	float  val;							//ֵ
	BYTE  type;							//��������
	char  ID[64];						//��ʶ
	char  PID[64];						//����ʶ
	DWORD  Station;						//����վ��
}common_UnEquMeas,*LPcommon_UnEquMeas;
//�Ӷ����
typedef struct common_SubObject
{
	DWORD  NU;							//���
	char  Name[64];						//����
	char  ID[64];						//�����ʶ
	BYTE  Type;							//��������
	DWORD  Station;						//��վ
	DWORD  PNU;							//���豸��
	BYTE  PType;						//���豸����
}common_SubObject,*LPcommon_SubObject;
//������
typedef struct common_Environment
{
	BYTE  EnType;						//��������
	CTime  RecTime;						//��Ϣʱ��
	char  Comment[128];					//��ע��Ϣ
	BYTE  State;						//����״̬
	float  PosX;						//����λ��X
	float  PosY;						//����λ��Y
	float  Length;						//���곤
	float  Width;						//�����
	char  SourcePath[128];				//��Դ·��
}common_Environment,*LPcommon_Environment;
//�����
typedef struct common_Meteor
{
	BYTE  MeType;						//��������
	CTime  RecTime;						//��Ϣʱ��
	char  Comment[128];					//��ע��Ϣ
	DWORD  ZoneNU;						//������
	BYTE  State;						//����״̬
	float  PosX;						//����λ��X
	float  PosY;						//����λ��Y
	float  Length;						//���곤
	float  Width;						//�����
	char  SourcePath[128];				//��Դ·��
}common_Meteor,*LPcommon_Meteor;
//��г������
typedef struct common_HexieD
{
	DWORD  NameID;						//���
	char  Name[64];						//����
	CTime  Time1;						//ʱ��
	float  Value;						//��ֵ
}common_HexieD,*LPcommon_HexieD;
//��г��������
typedef struct common_HexieYM
{
	DWORD  NameID;						//���
	BYTE  Type;							//����(�¡���)
	char  Name[64];						//����
	CTime  Time1;						//ʱ��
	float  Value;						//��ֵ
}common_HexieYM,*LPcommon_HexieYM;
//����װ�����ͳ�Ʊ�
typedef struct common_GenTransSta
{
	DWORD  ID;							//���
	char  Name[64];						//����
	WORD  DevNumber;					//�豸̨��
	float  Capacity;					//����
	DWORD  OwnerID;						//���豸ID
	char  Type[16];						//����
}common_GenTransSta,*LPcommon_GenTransSta;
//=================��Ƶ�𵴲ɼ�װ��===============
//��Ƶ����·
typedef struct pmu_lfline
{
	DWORD  LineID;						//��·ID
	BYTE  Type;							//���ͽ�����ֱ��
	BYTE  LFsta;						//��Ƶ��״̬
	CTime  StartTime;					//��ʼʱ��
	CTime  EndTime;						//����ʱ��
	float  LFFreq;						//��Ƶ��
	float  LFValue;						//�񵴷�ֵ
}pmu_lfline,*LPpmu_lfline;
//pmu���ݷ���������
typedef struct pmu_pmusvr
{
	DWORD  ip;							//������IP��ַ
	WORD  port;							//�������ں�
}pmu_pmusvr,*LPpmu_pmusvr;
//=================ˮ�����ݿ�===============
//ˮ�����ݿ�
typedef struct waterele_reservoir
{
	WORD  ID;							//ˮ���ʶ
	char  Name[24];						//ˮ������
	int  GenNU;							//���������ID
	float  Uplevel;						//����ˮλ
	float  DownLevel;					//����ˮλ
	float  WaterInput;					//��ˮ��
	float  P;							//�й�����
	float  WaterUse;					//��������
}waterele_reservoir,*LPwaterele_reservoir;
//=================�о�̬===============
//PT��
typedef struct studypw_PT
{
	DWORD  NU;							//PT���
	char  Name[24];						//PT����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[32];						//��ʶ
}studypw_PT,*LPstudypw_PT;
//�����
typedef struct studypw_Gen
{
	DWORD  NU;							//�������
	char  Name[24];						//�������
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
	float  angle;						//�Ƕ�
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	float  Qmax;						//�������޹�
	float  Qmaxi;						//�������޹�
	BYTE  Tsta;							//����״̬
	char  ID[32];						//��ʶ
}studypw_Gen,*LPstudypw_Gen;
//���ص�բ
typedef struct studypw_Switch
{
	DWORD  NU;							//���ر��
	char  Name[24];						//��������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[32];						//��ʶ
}studypw_Switch,*LPstudypw_Switch;
//����
typedef struct studypw_Load
{
	DWORD  NU;							//���ɱ��
	char  Name[24];						//��������
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  MaxP;						//�й�����
	float  MinP;						//�й�����
	float  P;							//�й�����
	float  Q;							//�޹�����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[32];						//��ʶ
}studypw_Load,*LPstudypw_Load;
//����
typedef struct studypw_Shunt
{
	DWORD  NU;							//�����豸���
	char  Name[24];						//�����豸����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Q;							//Ͷ���޹�
	float  Qmax;						//����޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	float  Qchk;						//��������
	BYTE  Tsta;							//����״̬
	char  ID[32];						//��ʶ
}studypw_Shunt,*LPstudypw_Shunt;
//�翹
typedef struct studypw_Sreact
{
	DWORD  NU;							//�翹�����
	char  Name[24];						//�翹����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Zx;							//Ͷ��翹
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  Tsta;							//����״̬
	char  ID[32];						//��ʶ
}studypw_Sreact,*LPstudypw_Sreact;
//2�����ѹ��
typedef struct studypw_Tfm1
{
	DWORD  NU;							//2�Ʊ���
	char  Name[24];						//2�Ʊ���
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
	char  ID[32];						//��ʶ
}studypw_Tfm1,*LPstudypw_Tfm1;
//3�����ѹ��
typedef struct studypw_Tfm2
{
	DWORD  NU;							//3�Ʊ���
	char  Name[24];						//3�Ʊ���
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
	char  ID[32];						//��ʶ
}studypw_Tfm2,*LPstudypw_Tfm2;
//��̬�޹�����
typedef struct studypw_SVC
{
	DWORD  NU;							//SVC���
	char  Name[24];						//SVC����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	float  Qmax;						//����޹����
	float  Qmin;						//��С�޹����
	float  Q;							//�޹����
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  Tsta;							//����״̬
	char  ID[32];						//��ʶ
}studypw_SVC,*LPstudypw_SVC;
//ĸ��
typedef struct studypw_Bus
{
	DWORD  NU;							//ĸ�߱��
	char  Name[24];						//ĸ������
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
	char  ID[32];						//��ʶ
}studypw_Bus,*LPstudypw_Bus;
//������
typedef struct studypw_Line
{
	DWORD  NU;							//�����߱��
	char  Name[24];						//����������
	DWORD  Station;						//����վ
	int  Zonef;							//��ʼ�������
	int  Zonet;							//�յ��������
	float  Imax;						//�������ֵ
	float  MaxP;						//�й�����
	float  Par;							//����߸����ʸ澯��
	float  CurPar;						//��ǰʹ�õĸ澯��
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
	char  ID[32];						//��ʶ
}studypw_Line,*LPstudypw_Line;
//ֱ����
typedef struct studypw_DCLine
{
	DWORD  NU;							//ֱ���߱��
	char  Name[24];						//ֱ��������
	DWORD  Station;						//����վ
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
	BYTE  alarm;						//Ԥ�����
	BYTE  ack;							//�澯ȷ��
	CTime  rptm1;						//���޿�ʼʱ��
	CTime  rptm2;						//���޽���ʱ��
	BYTE  Tsta;							//����״̬
	char  ID[32];						//��ʶ
}studypw_DCLine,*LPstudypw_DCLine;
//�������������
typedef struct studypw_CVT
{
	DWORD  NU;							//�豸���
	char  Name[24];						//�豸����
	DWORD  Station;						//����վ
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	BYTE  Tsta;							//����״̬
	char  ID[32];						//��ʶ
}studypw_CVT,*LPstudypw_CVT;
//�ӵ�
typedef struct studypw_GND
{
	DWORD  NU;							//�ӵر��
	char  Name[24];						//�ӵ�����
	DWORD  Station;						//����վ��
	int  ZoneNU;						//���������
	BYTE  ele;							//����״̬
	BYTE  sta;							//����״̬
	char  ID[32];						//��ʶ
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
	char  ID[32];						//��ʶ
}studypw_Zone,*LPstudypw_Zone;
//վ
typedef struct studypw_Station
{
	DWORD  NU;							//վ��
	char  Name[24];						//վ��
	DWORD  zoneNU;						//��������
	char  ID[32];						//��ʶ
}studypw_Station,*LPstudypw_Station;
//���ڵ��ѹ����
typedef struct studypw_VotOutage
{
	int  NU;							//�豸���
	char  type;							//�豸����
	float  Defl;						//��ѹƫ����
}studypw_VotOutage,*LPstudypw_VotOutage;
//��֧·����
typedef struct studypw_LineOutage
{
	int  NU;							//�豸���
	char  type;							//����
	float  Defl;						//��ѹƫ����
}studypw_LineOutage,*LPstudypw_LineOutage;
//�ڵ��ѹ��֧·�ϳ�
typedef struct studypw_AllOutage
{
	int  NU;							//�豸���
	char  type;							//����
	float  Defl;						//������
}studypw_AllOutage,*LPstudypw_AllOutage;
//���ڵ��ѹ����
typedef struct studypw_VotOutagef
{
	int  NU;							//�豸���
	char  type;							//�豸����
	float  Defl;						//��ѹƫ����
}studypw_VotOutagef,*LPstudypw_VotOutagef;
//��֧·����
typedef struct studypw_LineOutagef
{
	int  NU;							//�豸���
	char  type;							//�豸����
	float  Defl;						//��ѹƫ����
}studypw_LineOutagef,*LPstudypw_LineOutagef;
//�ڵ��ѹ��֧·�ϳ�
typedef struct studypw_AllOutagef
{
	int  NU;							//�豸���
	char  type;							//�豸����
	float  Defl;						//��ѹƫ����
}studypw_AllOutagef,*LPstudypw_AllOutagef;
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
	char  Name[24];						//����
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
//Ӧ�ò���
typedef struct studypw_AppParam
{
	float  OverRate;					//������
	float  HisMaxLoad;					//��ʷ��󸺺�
}studypw_AppParam,*LPstudypw_AppParam;
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
//=================������ʱ��===============
//ѹ����Ϣ��
typedef struct IIIzone_KeepPlate  
{
	DWORD  NU;							//ѹ����
	DWORD  Station;						//���ڳ�վ
	DWORD  Border;						//��������
	char  Name[64];						//ѹ������
	BYTE  State;						//ѹ��Ͷ��״̬
	BYTE  MisState;						//ѹ����Ͷ��״̬
	DWORD  StatePos;					//ѹ��Ͷ��״̬���
	DWORD  MisStatePos;					//ѹ����Ͷ��״̬���
}IIIzone_KeepPlate  ,*LPIIIzone_KeepPlate  ;
//������
typedef struct IIIzone_Environment
{
	BYTE  EnType;						//��������
	CTime  RecTime;						//��Ϣʱ��
	char  Comment[128];					//��ע��Ϣ
	BYTE  State;						//����״̬
	float  PosX;						//����λ��X
	float  PosY;						//����λ��Y
	float  Length;						//���곤
	float  Width;						//�����
	char  SourcePath[128];				//��Դ·��
}IIIzone_Environment,*LPIIIzone_Environment;
//�����
typedef struct IIIzone_Meteor
{
	BYTE  MeType;						//��������
	CTime  RecTime;						//��Ϣʱ��
	char  Comment[128];					//��ע��Ϣ
	DWORD  ZoneNU;						//������
	BYTE  State;						//����״̬
	float  PosX;						//����λ��X
	float  PosY;						//����λ��Y
	float  Length;						//���곤
	float  Width;						//�����
	char  SourcePath[128];				//��Դ·��
}IIIzone_Meteor,*LPIIIzone_Meteor;
#endif