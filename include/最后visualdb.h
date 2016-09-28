#if !defined(_DB_STRUCT_H_)
#define _DB_STRUCT_H_
/************************************************/
//本头文件由“数据库设计软件”自动生成
//2008-5-26
//星海高科技产业股份有限公司
/************************************************/
//掩码预定义值
//=================可视化电力系统库===============
//PT表
typedef struct visualpw_PT
{
	DWORD  NU;							//PT编号
	char  Name[24];						//PT名称
	DWORD  Station;						//所属站
	int  ZoneNU;						//所属区域号
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}visualpw_PT,*LPvisualpw_PT;
//发电机
typedef struct visualpw_Gen
{
	DWORD  NU;							//发电机号
	char  Name[24];						//发电机名
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  MaxP;						//有功上限
	float  Par;							//有功出力百分比告警限
	float  CurPar;						//当前使用的告警限
	float  Pchk;						//检修功率
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  alarm;						//预警
	BYTE  ack;							//告警确认
	float  P;							//有功出力
	float  Q;							//无功出力
	float  angle;						//角度
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}visualpw_Gen,*LPvisualpw_Gen;
//开关刀闸
typedef struct visualpw_Switch
{
	DWORD  NU;							//开关编号
	char  Name[24];						//开关名字
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	CTime  TurnDTime;					//动作时间
	BYTE  ele;							//带电状态
	BYTE  sta;							//开关状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  alarm;						//总告警
	BYTE  AlmRelay;						//保护动作告警0，1，2
	BYTE  SwtChange;					//开关变位
	BYTE  ack;							//确认
	BYTE  rp;							//检修状态
	DWORD  BayID;						//间隔ID
}visualpw_Switch,*LPvisualpw_Switch;
//负荷
typedef struct visualpw_Load
{
	DWORD  NU;							//负荷编号
	char  Name[24];						//负荷名称
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  MaxP;						//有功上限
	float  MinP;						//有功下限
	float  P;							//有功负荷
	float  Q;							//无功负荷
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
}visualpw_Load,*LPvisualpw_Load;
//电容
typedef struct visualpw_Shunt
{
	DWORD  NU;							//电容设备编号
	char  Name[24];						//电容设备名称
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  Vl;							//电压等级
	float  Q;							//投入无功
	float  Qmax;						//最大无功输出
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}visualpw_Shunt,*LPvisualpw_Shunt;
//电抗
typedef struct visualpw_Sreact
{
	DWORD  NU;							//电抗器变号
	char  Name[24];						//电抗器名
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  Vl;							//电压等级
	float  zst;							//步长
	float  Zx;							//投入电抗
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}visualpw_Sreact,*LPvisualpw_Sreact;
//2绕组变压器
typedef struct visualpw_Tfm1
{
	DWORD  NU;							//2绕变编号
	char  Name[24];						//2绕变名
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  Vl;							//电压等级
	WORD  Tallow;						//过载允许时间(分)
	WORD  Tover;						//已连续过载时间(分)
	float  tap;							//变压器分接头
	float  Pmax;						//变压器最大有功(容量)
	float  CurPar;						//当前使用的告警限
	float  P;							//高压侧有功
	float  Q;							//高压侧无功
	float  I;							//高压侧电流
	float  P2;							//低压侧有功
	float  Q2;							//低压侧无功
	float  I2;							//低压侧电流
	float  Tcur;						//当前温度
	float  Tmax;						//最高温度
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  alarm;						//总告警
	BYTE  ack;							//告警确认
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
	float  T1;							//温度1
	float  T2;							//温度2
	float  T3;							//温度3
	float  T4;							//温度4
	BYTE  AlmTfast;						//温度突变告警
	BYTE  AlmCur;						//温度曲线告警
	BYTE  AlmOver;						//温度越限告警
	BYTE  AlmLoad;						//负载越限告警
	BYTE  AlmRelay;						//保护信号告警
}visualpw_Tfm1,*LPvisualpw_Tfm1;
//3绕组变压器
typedef struct visualpw_Tfm2
{
	DWORD  NU;							//3绕变编号
	char  Name[24];						//3绕变名
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  Vl;							//电压等级
	WORD  Tallow;						//过载允许时间(分)
	WORD  Tover;						//已连续过载时间(分)
	float  TapH;						//高端分接头位置
	float  TapM;						//中端分接头位置
	float  TapL;						//低端分接头位置
	float  Pmax;						//变压器最大有功(容量)
	float  CurPar;						//当前使用的告警限
	float  P;							//高压侧有功
	float  Q;							//高压侧无功
	float  I;							//高压侧电流
	float  P2;							//中压侧有功
	float  Q2;							//中压侧无功
	float  I2;							//中压侧电流
	float  P3;							//低压侧有功
	float  Q3;							//低压侧无功
	float  I3;							//低压侧电流
	float  Tcur;						//当前温度
	float  Tmax;						//最高温度
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  alarm;						//总告警
	BYTE  ack;							//告警确认
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  Tnum;							//采集的温度个数
	float  T1;							//温度1
	float  T2;							//温度2
	float  T3;							//温度3
	float  T4;							//温度4
	float  T5;							//温度5
	float  T6;							//温度6
	BYTE  rp;							//检修状态
	BYTE  AlmTfast;						//温度突变告警
	BYTE  AlmCur;						//温度曲线告警
	BYTE  AlmOver;						//温度越限告警
	BYTE  AlmLoad;						//负载越限告警
	BYTE  AlmRelay;						//保护信号告警
}visualpw_Tfm2,*LPvisualpw_Tfm2;
//静态无功补偿
typedef struct visualpw_SVC
{
	DWORD  NU;							//SVC编号
	char  Name[24];						//SVC名称
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  Qmax;						//最大无功输出
	float  Qmin;						//最小无功输出
	float  Q;							//无功输出
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}visualpw_SVC,*LPvisualpw_SVC;
//母线
typedef struct visualpw_Bus
{
	DWORD  NU;							//母线编号
	char  Name[24];						//母线名称
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  MaxV;						//电压上限
	float  MinV;						//电压下限
	float  HiLimit;						//电压告警上限
	float  LoLimit;						//电压告警下限
	float  Vl;							//电压等级
	float  V;							//节点电压(pu)
	float  Vb;							//电压实际值
	float  DayMax;						//日最大值
	float  DayMin;						//日最小值
	float  deg;							//相角
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  AlmOver;						//越上下限0，1，2
	BYTE  AlmRelay;						//保护信号告警
	BYTE  alarm;						//总告警
	BYTE  ack;							//告警确认
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}visualpw_Bus,*LPvisualpw_Bus;
//交流线
typedef struct visualpw_Line
{
	DWORD  NU;							//交流线编号
	char  Name[24];						//交流线名称
	DWORD  StationNU;					//所属站
	int  Zonef;							//起始区域域号
	int  Zonet;							//终点区域域号
	float  Vl;							//电压等级
	float  Imax;						//电流最大值
	float  MaxP;						//有功上限
	float  CurPar;						//当前使用的告警限
	float  Pf;							//始端有功
	float  Qf;							//始端无功
	float  Pt;							//末端有功
	float  Qt;							//末端无功
	float  I;							//电流值
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  alarm;						//总告警
	BYTE  ack;							//告警确认
	BYTE  AlmRelay;						//保护信号告警
	BYTE  AlmLoad;						//负载越限告警
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
	BYTE  BayID;						//间隔ID
}visualpw_Line,*LPvisualpw_Line;
//直流线
typedef struct visualpw_DCLine
{
	DWORD  NU;							//直流线编号
	char  Name[24];						//直流线名称
	DWORD  StationNU;					//所属站
	int  Zonef;							//起始区域域号
	int  Zonet;							//终点区域域号
	float  Imax;						//电流最大值
	float  Maxp;						//有功上限
	float  Par;							//输电线负载率告警限
	float  CurPar;						//当前使用的告警限
	float  Pf;							//始端有功
	float  Qf;							//始端无功
	float  Pt;							//末端有功
	float  Qt;							//末端无功
	float  I;							//电流值
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  alarm;						//预警
	BYTE  ack;							//告警确认
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
	BYTE  BayID;						//间隔ID
}visualpw_DCLine,*LPvisualpw_DCLine;
//逆变器、变流器
typedef struct visualpw_CVT
{
	DWORD  NU;							//设备编号
	char  Name[24];						//设备名称
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
}visualpw_CVT,*LPvisualpw_CVT;
//接地
typedef struct visualpw_GND
{
	DWORD  NU;							//接地编号
	char  Name[24];						//接地名称
	DWORD  StationNU;					//所属站号
	int  ZoneNU;						//所属区域号
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
}visualpw_GND,*LPvisualpw_GND;
//区域
typedef struct visualpw_Zone
{
	DWORD  NU;							//区域编号
	char  Name[24];						//区域名称
	float  total_los;					//有功损耗
	float  total_gen;					//有功发电
	float  demand;						//有功需求
	float  cost;						//单位发电额费用
	float  curlr;						//当前负荷率
	float  lastlr;						//上次负荷率
	float  nextlr;						//未来负荷率
}visualpw_Zone,*LPvisualpw_Zone;
//站
typedef struct visualpw_Station
{
	DWORD  NU;							//站号
	char  Name[24];						//站名
	DWORD  zoneNU;						//所属区域
	BYTE  Alarm;						//站告警
	BYTE  ack;							//告警确认
}visualpw_Station,*LPvisualpw_Station;
//系统指标
typedef struct visualpw_SysGD
{
	DWORD  ID;							//指标标识ID
	char  Name[24];						//指标名称
	float  zb;							//当前指标
	float  Vmax;						//量程最大值
	float  Vmin;						//量程最小值
	float  Vmax1;						//第一段最大值
	float  Vmin1;						//第一段最小值
	float  Vmax2;						//第二段最大值
	float  Vmin2;						//第二段最小值
}visualpw_SysGD,*LPvisualpw_SysGD;
//系统告警
typedef struct visualpw_SysAlarm
{
	WORD  Alarm;						//告警状态0,1
	WORD  num;							//发生告警的设备个数
	char  picname[32];					//推出画面名称
	WORD  picno;						//推出画面序号
}visualpw_SysAlarm,*LPvisualpw_SysAlarm;
//状态量表
typedef struct visualpw_Status
{
	int  NU;							//遥信ID
	char  Name[24];						//名称
	BYTE  type;							//类型
	int  StationNU;						//站号
	char  sta;							//状态
	BYTE  Devtype;						//所属设备类型
	DWORD  DevID;						//所属设备ID
}visualpw_Status,*LPvisualpw_Status;
//保护信号表
typedef struct visualpw_Relay
{
	int  NU;							//保护信号ID
	char  Name[24];						//保护信号名
	int  StationNU;						//站号
	BYTE  sta;							//状态
	CTime  tm;							//动作时间
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  type;							//保护类型1，2重要或一般保护
	BYTE  ack;							//确认标志
	BYTE  devtype;						//设备类型
	DWORD  devid;						//关联设备ID
	DWORD  TankID;						//所属屏ID
}visualpw_Relay,*LPvisualpw_Relay;
//保护屏(柜）
typedef struct visualpw_Tank
{
	DWORD  ID;							//标识
	char  Name[24];						//名字
	BYTE  AlmLevel;						//告警级别0，1，2，3
	BYTE  ack;							//确认标志
}visualpw_Tank,*LPvisualpw_Tank;
//间隔设备
typedef struct visualpw_Bay
{
	DWORD  ID;							//间隔ID
	char  Name[24];						//间隔名字
	BYTE  Alarm;						//间隔告警
	BYTE  ack;							//确认标志
}visualpw_Bay,*LPvisualpw_Bay;
//Relation104
typedef struct visualpw_Relation104
{
	DWORD  NU;							//序号
	DWORD  MNU;							//内存库的NU
	int  StationNU;						//站号
	char  Values[12];					//域
	float  MODULUS;						//点号对应的系数
	BYTE  DevType;						//设备类型
	DWORD  ID;							//对方ID号
	char  Name[100];					//名字
}visualpw_Relation104,*LPvisualpw_Relation104;
//Relationyx104
typedef struct visualpw_Relationyx104
{
	DWORD  NU;							//序号
	DWORD  MNU;							//内存库的NU
	int  StationNU;						//站号
	char  Values[12];					//域
	float  MODULUS;						//点号对应的系数
	BYTE  DevType;						//设备类型
	DWORD  ID;							//对方ID号
	char  Name[100];					//名字
}visualpw_Relationyx104,*LPvisualpw_Relationyx104;
//=================公共库===============
//用户表
typedef struct common_user
{
	WORD  id;							//用户ID
	char  Name[15];						//用户名
	char  password[16];					//用户密码
	char  type;							//用户类型
	DWORD  limit;						//权限(32位)
	char  exp[28];						//注解
}common_user,*LPcommon_user;
//电压颜色
typedef struct common_Color
{
	char  VLName[16];					//电压名称
	BYTE  R;							//红色分量
	BYTE  G;							//绿色分量
	BYTE  B;							//兰色分量
}common_Color,*LPcommon_Color;
//灵敏度结果表
typedef struct common_Sen
{
	DWORD  NU;							//设备相关ID
	BYTE  type;							//设备类型
	float  senval;						//灵敏度值
}common_Sen,*LPcommon_Sen;
//实时负荷预测8点
typedef struct common_FLoad
{
	float  FValue;						//负荷预测值
	float  RValue;						//负荷实际值
	BYTE  hour;							//整点小时数
}common_FLoad,*LPcommon_FLoad;
//运行方式
typedef struct common_RunType
{
	DWORD  Nu;							//编号
	char  Name[24];						//名
	BYTE  State;						//状态
}common_RunType,*LPcommon_RunType;
//母线关联值
typedef struct common_BusV
{
	DWORD  Nu;							//编号
	char  Name[24];						//设备名
	float  HGD_MaxV;					//丰大白天电压上限
	float  HGD_MinV;					//丰大白天电压下限
	float  HGW_MaxV;					//丰大晚上电压上限
	float  HGW_MinV;					//丰大晚上电压下限
	float  HSD_MaxV;					//丰小白天电压上限
	float  HSD_MinV;					//丰小白天电压下限
	float  HSW_MaxV;					//丰小晚上电压上限
	float  HSW_MinV;					//丰小晚上电压下限
	float  LGD_MaxV;					//枯大白天电压上限
	float  LGD_MinV;					//枯大白天电压下限
	float  LGW_MaxV;					//枯大晚上电压上限
	float  LGW_MinV;					//枯大晚上电压下限
	float  LSD_MaxV;					//枯小白天电压上限
	float  LSD_MinV;					//枯小白天电压下限
	float  LSW_MaxV;					//枯小晚上电压上限
	float  LSW_MinV;					//枯小晚上电压下限
	float  ESD_MaxV;					//特殊白天电压上限
	float  ESD_MinV;					//特殊白天电压下限
	float  ESW_MaxV;					//特殊晚上电压上限
	float  ESW_MinV;					//特殊晚上电压下限
}common_BusV,*LPcommon_BusV;
//转换关系表
typedef struct common_Relation
{
	int  SNu;							//序号
	int  VNu;							//可视化中的设备ID
	char  SName[24];					//Scada中的名字
	char  EName[24];					//EMS中的名字
	char  DName[24];					//DMIS中的名字
	BYTE  DevType;						//设备类型
	char  VType;						//域号
	WORD  GrpNu;						//设备分组号
	DWORD  Station;						//所属站号
}common_Relation,*LPcommon_Relation;
//预定义断面潮流
typedef struct common_PreDefSF
{
	DWORD  ID;							//断面ID
	char  Name[45];						//断面名字
	float  curval;						//当前断面值
	float  Vmax;						//断面容量值
	float  Par;							//断面负载率告警限
	float  CurPar;						//当前使用的告警限
	BYTE  Nline;						//线路数
	char  DevID[256];					//断面ID,最大26条线路
	BYTE  alarm;						//预警
	BYTE  ack;							//告警确认
	float  Pcur;						//断面有功
	float  Qcur;						//断面无功
}common_PreDefSF,*LPcommon_PreDefSF;
//=================studypw===============
//PT表
typedef struct studypw_PT
{
	DWORD  NU;							//PT编号
	char  Name[24];						//PT名称
	DWORD  Station;						//所属站
	int  ZoneNU;						//所属区域号
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}studypw_PT,*LPstudypw_PT;
//发电机
typedef struct studypw_Gen
{
	DWORD  NU;							//发电机号
	char  Name[24];						//发电机名
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  MaxP;						//有功上限
	float  Par;							//有功出力百分比告警限
	float  CurPar;						//当前使用的告警限
	float  Pchk;						//检修功率
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  alarm;						//预警
	BYTE  ack;							//告警确认
	float  P;							//有功出力
	float  Q;							//无功出力
	float  angle;						//角度
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}studypw_Gen,*LPstudypw_Gen;
//开关刀闸
typedef struct studypw_Switch
{
	DWORD  NU;							//开关编号
	char  Name[24];						//开关名字
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	CTime  TurnDTime;					//动作时间
	BYTE  ele;							//带电状态
	BYTE  sta;							//开关状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  alarm;						//总告警
	BYTE  AlmRelay;						//保护动作告警0，1，2
	BYTE  SwtChange;					//开关变位
	BYTE  ack;							//确认
	BYTE  rp;							//检修状态
	BYTE  BayID;						//间隔ID
}studypw_Switch,*LPstudypw_Switch;
//负荷
typedef struct studypw_Load
{
	DWORD  NU;							//负荷编号
	char  Name[24];						//负荷名称
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  MaxP;						//有功上限
	float  MinP;						//有功下限
	float  P;							//有功负荷
	float  Q;							//无功负荷
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
}studypw_Load,*LPstudypw_Load;
//电容
typedef struct studypw_Shunt
{
	DWORD  NU;							//电容设备编号
	char  Name[24];						//电容设备名称
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  Vl;							//电压等级
	float  Q;							//投入无功
	float  Qmax;						//最大无功输出
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}studypw_Shunt,*LPstudypw_Shunt;
//电抗
typedef struct studypw_Sreact
{
	DWORD  NU;							//电抗器变号
	char  Name[24];						//电抗器名
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  Vl;							//电压等级
	float  zst;							//步长
	float  Zx;							//投入电抗
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}studypw_Sreact,*LPstudypw_Sreact;
//2绕组变压器
typedef struct studypw_Tfm1
{
	DWORD  NU;							//2绕变编号
	char  Name[24];						//2绕变名
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  Vl;							//电压等级
	WORD  Tallow;						//过载允许时间(分)
	WORD  Tover;						//已连续过载时间(分)
	float  tap;							//变压器分接头
	float  Pmax;						//变压器最大有功(容量)
	float  CurPar;						//当前使用的告警限
	float  P;							//高压侧有功
	float  Q;							//高压侧无功
	float  I;							//高压侧电流
	float  P2;							//低压侧有功
	float  Q2;							//低压侧无功
	float  I2;							//低压侧电流
	float  Tcur;						//当前温度
	float  Tmax;						//最高温度
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  alarm;						//总告警
	BYTE  ack;							//告警确认
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
	float  T1;							//温度1
	float  T2;							//温度2
	float  T3;							//温度3
	float  T4;							//温度4
	BYTE  AlmTfast;						//温度突变告警
	BYTE  AlmCur;						//温度曲线告警
	BYTE  AlmOver;						//温度越限告警
	BYTE  AlmLoad;						//负载越限告警
	BYTE  AlmRelay;						//保护信号告警
}studypw_Tfm1,*LPstudypw_Tfm1;
//3绕组变压器
typedef struct studypw_Tfm2
{
	DWORD  NU;							//3绕变编号
	char  Name[24];						//3绕变名
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  Vl;							//电压等级
	WORD  Tallow;						//过载允许时间(分)
	WORD  Tover;						//已连续过载时间(分)
	float  TapH;						//高端分接头位置
	float  TapM;						//中端分接头位置
	float  TapL;						//低端分接头位置
	float  Pmax;						//变压器最大有功(容量)
	float  CurPar;						//当前使用的告警限
	float  P;							//高压侧有功
	float  Q;							//高压侧无功
	float  I;							//高压侧电流
	float  P2;							//中压侧有功
	float  Q2;							//中压侧无功
	float  I2;							//中压侧电流
	float  P3;							//低压侧有功
	float  Q3;							//低压侧无功
	float  I3;							//低压侧电流
	float  Tcur;						//当前温度
	float  Tmax;						//最高温度
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  alarm;						//总告警
	BYTE  ack;							//告警确认
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  Tnum;							//采集的温度个数
	float  T1;							//温度1
	float  T2;							//温度2
	float  T3;							//温度3
	float  T4;							//温度4
	float  T5;							//温度5
	float  T6;							//温度6
	BYTE  rp;							//检修状态
	BYTE  AlmTfast;						//温度突变告警
	BYTE  AlmCur;						//温度曲线告警
	BYTE  AlmOver;						//温度越限告警
	BYTE  AlmLoad;						//负载越限告警
	BYTE  AlmRelay;						//保护信号告警
}studypw_Tfm2,*LPstudypw_Tfm2;
//静态无功补偿
typedef struct studypw_SVC
{
	DWORD  NU;							//SVC编号
	char  Name[24];						//SVC名称
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  Qmax;						//最大无功输出
	float  Qmin;						//最小无功输出
	float  Q;							//无功输出
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}studypw_SVC,*LPstudypw_SVC;
//母线
typedef struct studypw_Bus
{
	DWORD  NU;							//母线编号
	char  Name[24];						//母线名称
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	float  MaxV;						//电压上限
	float  MinV;						//电压下限
	float  HiLimit;						//电压告警上限
	float  LoLimit;						//电压告警下限
	float  Vl;							//电压等级
	float  V;							//节点电压(pu)
	float  Vb;							//电压实际值
	float  DayMax;						//日最大值
	float  DayMin;						//日最小值
	float  deg;							//相角
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  AlmOver;						//越上下限0，1，2
	BYTE  AlmRelay;						//保护信号告警
	BYTE  alarm;						//总告警
	BYTE  ack;							//告警确认
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
}studypw_Bus,*LPstudypw_Bus;
//交流线
typedef struct studypw_Line
{
	DWORD  NU;							//交流线编号
	char  Name[24];						//交流线名称
	DWORD  StationNU;					//所属站
	int  Zonef;							//起始区域域号
	int  Zonet;							//终点区域域号
	float  Vl;							//电压等级
	float  Imax;						//电流最大值
	float  MaxP;						//有功上限
	float  CurPar;						//当前使用的告警限
	float  Pf;							//始端有功
	float  Qf;							//始端无功
	float  Pt;							//末端有功
	float  Qt;							//末端无功
	float  I;							//电流值
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  alarm;						//总告警
	BYTE  ack;							//告警确认
	BYTE  AlmRelay;						//保护信号告警
	BYTE  AlmLoad;						//负载越限告警
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
	BYTE  BayID;						//间隔ID
}studypw_Line,*LPstudypw_Line;
//直流线
typedef struct studypw_DCLine
{
	DWORD  NU;							//直流线编号
	char  Name[24];						//直流线名称
	DWORD  StationNU;					//所属站
	int  Zonef;							//起始区域域号
	int  Zonet;							//终点区域域号
	float  Imax;						//电流最大值
	float  Maxp;						//有功上限
	float  Par;							//输电线负载率告警限
	float  CurPar;						//当前使用的告警限
	float  Pf;							//始端有功
	float  Qf;							//始端无功
	float  Pt;							//末端有功
	float  Qt;							//末端无功
	float  I;							//电流值
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	BYTE  alarm;						//预警
	BYTE  ack;							//告警确认
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  rp;							//检修状态
	BYTE  BayID;						//间隔ID
}studypw_DCLine,*LPstudypw_DCLine;
//逆变器、变流器
typedef struct studypw_CVT
{
	DWORD  NU;							//设备编号
	char  Name[24];						//设备名称
	DWORD  StationNU;					//所属站
	int  ZoneNU;						//所属区域号
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
}studypw_CVT,*LPstudypw_CVT;
//接地
typedef struct studypw_GND
{
	DWORD  NU;							//接地编号
	char  Name[24];						//接地名称
	DWORD  StationNU;					//所属站号
	int  ZoneNU;						//所属区域号
	BYTE  ele;							//带电状态
	BYTE  sta;							//运行状态
}studypw_GND,*LPstudypw_GND;
//区域
typedef struct studypw_Zone
{
	DWORD  NU;							//区域编号
	char  Name[24];						//区域名称
	float  total_los;					//有功损耗
	float  total_gen;					//有功发电
	float  demand;						//有功需求
	float  cost;						//单位发电额费用
	float  curlr;						//当前负荷率
	float  lastlr;						//上次负荷率
	float  nextlr;						//未来负荷率
}studypw_Zone,*LPstudypw_Zone;
//站
typedef struct studypw_Station
{
	DWORD  NU;							//站号
	char  Name[24];						//站名
	DWORD  zoneNU;						//所属区域
	BYTE  Alarm;						//站告警
	BYTE  ack;							//告警确认
}studypw_Station,*LPstudypw_Station;
//系统指标
typedef struct studypw_SysGD
{
	DWORD  ID;							//指标标识ID
	char  Name[24];						//指标名称
	float  zb;							//当前指标
	float  Vmax;						//量程最大值
	float  Vmin;						//量程最小值
	float  Vmax1;						//第一段最大值
	float  Vmin1;						//第一段最小值
	float  Vmax2;						//第二段最大值
	float  Vmin2;						//第二段最小值
}studypw_SysGD,*LPstudypw_SysGD;
//系统告警
typedef struct studypw_SysAlarm
{
	WORD  Alarm;						//告警状态0,1
	WORD  num;							//发生告警的设备个数
	char  picname[32];					//推出画面名称
	WORD  picno;						//推出画面序号
}studypw_SysAlarm,*LPstudypw_SysAlarm;
//状态量表
typedef struct studypw_Status
{
	int  NU;							//遥信ID
	char  Name[24];						//名称
	BYTE  type;							//类型
	int  StationNU;						//站号
	char  sta;							//状态
	BYTE  Devtype;						//所属设备类型
	DWORD  DevID;						//所属设备ID
}studypw_Status,*LPstudypw_Status;
//保护信号表
typedef struct studypw_Relay
{
	int  NU;							//保护信号ID
	char  Name[24];						//保护信号名
	int  StationNU;						//站号
	BYTE  sta;							//状态
	CTime  tm;							//动作时间
	CTime  updatetm;					//数据更新时间
	BYTE  olddata;						//旧数据
	BYTE  type;							//保护类型1，2重要或一般保护
	BYTE  ack;							//确认标志
	BYTE  devtype;						//设备类型
	DWORD  devid;						//关联设备ID
	DWORD  TankID;						//所属屏ID
}studypw_Relay,*LPstudypw_Relay;
//保护屏(柜）
typedef struct studypw_Tank
{
	DWORD  ID;							//标识
	char  Name[24];						//名字
	BYTE  AlmLevel;						//告警级别0，1，2，3
	BYTE  ack;							//确认标志
}studypw_Tank,*LPstudypw_Tank;
//间隔设备
typedef struct studypw_Bay
{
	DWORD  ID;							//间隔ID
	char  Name[24];						//间隔名字
	BYTE  Alarm;						//间隔告警
	BYTE  ack;							//确认标志
}studypw_Bay,*LPstudypw_Bay;
#endif