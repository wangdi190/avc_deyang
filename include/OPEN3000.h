////


#if !defined(AFX_OPEN3000_H__FDA2D0C6_635E_4EC2_8614_F6A36E15D888_INCLUDED_)
#define AFX_OPEN3000_H__FDA2D0C6_635E_4EC2_8614_F6A36E15D888_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define M_SCADA_BRK_DEVICE 60      //断路器信息表
#define M_SCADA_DISCR_DEVICE 61    //刀闸表
#define M_SCADA_GDDISCR_DEVICE 62  //接地刀闸表
#define M_SCADA_BS_DEVICE 63       //母线表
#define M_SCADA_TR_DEVICE 64       //变压器表
#define M_SCADA_TRWD_DEVICE 65     //变压器绕组
#define M_SCADA_GN_DEVICE 66       //发电机表
#define M_SCADA_LD_DEVICE 67       //负荷
#define M_SCADA_ACLN_DEVICE 68     //交流线段表
#define M_SCADA_ACLN_DOT 69        //交流线段端点表
#define M_SCADA_FAC_INFO 70        //厂站信息表
#define M_SCADA_DIV_INFO 71        //行政区域表
#define M_SCADA_RC_DEVICE 72       //容抗器表  电容和电抗
#define M_SCADA_VL_TYPE 73         //电压类型表
#define M_SCADA_TAP_TYPE 74         //档位类型表

#define M_AVC_STATION 75			//AVC厂站定义
#define M_AVC_BUS 76				//AVC母线控制定义
#define M_AVC_TRANS 77				//AVC变压器控制定义
#define M_AVC_SHUNT 78				//AVC电容器控制定义
#define M_AVC_CONTROL 79			//AVC控制定义
#define M_AVC_RUNPARAM 80			//AVC运行参数
#define M_AVC_TIMEPART 81			//AVC时段控制定义
#define M_AVC_WARMTYPE 82			//告警类型
#define M_AVC_CONPLOY 83			//控制策略
#define M_AVC_WARMSIGN 84			//告警信号
#define M_AVC_PROTECTSIGN 85		//保护信号


#define R_SCADA_BRK_DEVICE 10      //断路器信息表
#define R_SCADA_DISCR_DEVICE 11    //刀闸表
#define R_SCADA_GDDISCR_DEVICE 12  //接地刀闸表
#define R_SCADA_BS_DEVICE 13       //母线表
#define R_SCADA_TR_DEVICE 14       //变压器表
#define R_SCADA_TRWD_DEVICE 15     //变压器绕组
#define R_SCADA_GN_DEVICE 16       //发电机表
#define R_SCADA_LD_DEVICE 17       //负荷
#define R_SCADA_ACLN_DEVICE 18     //交流线段表
#define R_SCADA_ACLN_DOT 19        //交流线段端点表
#define R_SCADA_FAC_INFO 20        //厂站信息表
#define R_SCADA_DIV_INFO 21        //行政区域表
#define R_SCADA_RC_DEVICE 22       //容抗器表  电容和电抗
#define R_SCADA_VL_TYPE 23         //电压类型表

typedef struct MODEL_VOLTAGE			//电压类型表_模型
{
	int vlty_id;					//电压类型ID号
	char vlty_name[64];				//电压类型名称
	float vbase;					//电压基准
	int vlColor;					//电压类型颜色
	float hlim;						//电压上限
	float llim;						//电压下限
	float vbase_kh;					//电压考核基准
	float sbse_kh;					//功率考核基准
}MODEL_VOLTAGE;

typedef struct MODEL_ZONE				//行政区域表_模型
{
	int area_id;					//区域ID号
	char area_name[64];				//区域名称
	int area_no;					//区域编号
}MODEL_ZONE;

#define STATION_HOT 0
#define STATION_WATER 1
#define STATION_NUCLEAR 2
#define STATION_TRANS 3
#define STATION_VIR 4
#define STATION_SHIFT 5
#define STATION_STAT 10
typedef struct MODEL_STATION			//厂站信息表_模型
{
	int fac_id;								//厂站ID
	int area_id;							//区域ID
	char fac_name[64];						//厂站名称
	unsigned char fac_type;					//厂站类型    0火电、1水电、2核电、3变电站、4虚拟站等值站、5转发厂、10统计厂
	int vlty_id;							//最高电压等级
	char graph_name[64];					//接线图名称
}MODEL_STATION;

typedef struct MODEL_VOLLEVEL		//电压等级表_模型
{
}MODEL_VOLLEVEL;

#define STATE_RUN 0
#define STATE_QUIT 1
#define STATE_READQUIT 2
typedef struct MODEL_BREAKE			//断路器信息表_模型
{
	int brk_id;									//断路器ID号
	int fac_id;									//厂站ID号
	char brk_name[64];							//断路器名称
	int vlty_id;								//电压类型ID号
	int nd1_no;									//节点1号
	int nd2_no;									//节点2号
	int bay_id;									//间隔ID号
	int run_state;								//运行状态				0投运、1未投运、2待退役
	unsigned char yx_value;						//遥信值
	int bw_number;								//变位次数
}MODEL_BREAKE;

typedef struct MODEL_DISCR			//刀闸表_模型
{
	int discr_id;								//刀闸ID号
	int fac_id;									//厂站ID号
	char discr_name[64];						//刀闸名称
	int vlty_id;								//电压类型ID号
	int nd1_no;									//节点1号
	int nd2_no;									//节点2号
	int bay_id;									//间隔ID号
	int run_state;								//运行状态
	unsigned char yx_value;						//遥信值
	int bw_number;								//变位次数
}MODEL_DISCR;

typedef struct MODEL_GDISCR			//接地刀闸表_模型
{
	int gddiscr_id;							//接地刀闸ID号
	int fac_id;								//厂站ID号
	char gddiscr_name[64];					//接地刀闸名称
	int vlty_id;							//电压类型ID号
	int nd_no;								//节点号
	int bay_id;								//间隔ID号
	int run_state;							//运行状态
	unsigned char yx_value;					//遥信值
	int bw_number;							//变位次数
}MODEL_GDISCR;

typedef struct MODEL_BUS					//母线表_模型
{
	int bs_id;								//母线ID号
	int fac_id;								//厂站ID号
	char bs_name[64];						//母线名称
	int vlty_id;							//电压类型ID号
	float vmax;								//电压上限
	float vmin;								//电压下限
	int bay_id;								//间隔ID号
	int nd_no;								//节点号
	int run_state;							//投运状态
	float v_value;							//线电压幅值
	float c_value;							//电压相角
}MODEL_BUS;

#define EQUAL_NO 0							//0不等值
#define EQUAL_LOAD 1						//1等值为负荷
#define EQUAL_GEN 3							//2等值为发电机
typedef struct MODEL_LINE					//交流线段表_模型
{
	int acln_id;							//交流线段ID号
	int fac_id_s;							//一端厂站ID号
	int fac_id_e;							//二端厂站ID号
	char acln_name[64];						//交流线段名称
	int vlty_id;							//电压类型ID号
	int line_id;							//线路ID号
	float smax;								//功率限值
	float imax1;							//电流正常限
	int area_id;							//区域ID号
	unsigned char eq_fg;					//等值标志						0不等值、1等值为负荷、2等值为发电机
	int run_state;							//投运状态
	float r_value_pu;						//正序电阻标幺值
	float x_value_pu;						//正序电抗标幺值
	float bch_value_pu;						//正序电纳标幺值
}MODEL_LINE;

typedef struct MODEL_LINEDOT				//交流线段端点表_模型
{
	int fac_id;									//厂站ID号
	char acln_dot_name[64];						//交流线段端点名称
	int acln_id;								//所属交流线段ID号
	int vlty_id;								//所属交流线段ID号
	int bay_id;									//间隔ID号
	int nd_no;									//节点号
}MODEL_LINEDOT;

typedef struct MODEL_TRANS				//变压器表_模型
{		
	int tr_id;									//变压器ID号
	int fac_id;									//厂站ID号
	char tr_name[64];							//变压器名称
	unsigned char trty;							//绕组类型
	int run_state;								//投运状态
}MODEL_TRANS;

#define WINDING_HIGH 0
#define WINDING_MID 1
#define WINDING_LOW 2

#define LOADTRANS_NO 0					//有载不可调压
#define LOADTRANS_YES 1					//有载可调压

typedef struct MODEL_TRANSWIND				//变压器绕组_模型
{
	int trwd_id;									//变压器绕组ID号
	int fac_id;										//厂站ID号
	char trwd_name[64];								//变压器绕组名称
	int tr_id;										//变压器ID号
	unsigned char trwd_type;						//变压器绕组类型				0高、1中、2低
	int tapty_id;									//分接头类型ID号
	int vlty_id;									//电压类型ID号
	int nd_no;										//节点号
	unsigned char ltc_fg;							//有载调压标志        0不可调、1可调
	float snom;										//额定功率
	float vnom;										//额定电压
	int bay_id;										//间隔ID
	float r_value_pu;								//正序电阻标幺值
	float x_value_pu;								//正序电抗标幺值
}MODEL_TRANSWIND;


typedef struct MODEL_TAPTYPE				//变压器绕组档位_模型
{
	int tapty_id;									//变压器分接头类型ID号
	char tapty_name[64];							//变压器分接头类型名称
	int tapty_mn;									//最小档位
	int tapty_mx;									//最大档位
	int tapty_nom;									//额定档位
	float tapty_step;								//步长
}MODEL_TAPTYPE;

typedef struct MODEL_GEN							//发电机表_模型
{
	int gn_id;										//发电机ID号
	int fac_id;										//厂站ID号
	char gn_name[64];								//发电机名称
	int vlty_id;									//电压类型ID号
	float snom;										//额定功率
	int nd_no;										//节点编号
	int run_state;									//投运状态
}MODEL_GEN;

typedef struct MODEL_LOAD						//负荷_模型
{
	int ld_id;										//负荷ID号
	int fac_id;										//厂站ID号
	char ld_name[64];								//负荷名称
	int vlty_id;									//电压类型ID号
	int bay_id;										//间隔ID号
	int nd_no;										//节点号
	int run_state;									//投运状态
}MODEL_LOAD;

#define RC_SHUNT 1							//并联电容	
#define RC_REACT 2							//并联电抗
#define RC_SERIESSHUNT 3					//串联电容
#define RC_SERIESREACT 4					//串联电抗
#define RC_SPLITREACT 5						//分裂电抗

typedef struct MODEL_SHUNT							//电容和电抗_模型
{
	int rc_id;										//容抗器ID号
	int fac_id;										//厂站ID号
	char rc_name[64];								//容抗器名称
	int vlty_id;									//电压类型ID号
	unsigned char rc_type;							//容抗器类型			1并联电容、2并联电抗、3串联电容、4串联电抗、5分裂电抗
	int nd1_no;										//节点1号 
	int nd2_no;										//节点2号
	int nd3_no;										//节点3号
	int run_state;									//投运状态
	float qnom;										//额定容量
	float vnom;										//额定电压
	int bay_id;										//间隔ID号
	float r_value_pu;								//正序电阻标幺值
	float x_value_pu;								//正序电抗标幺值
}MODEL_SHUNT;

#define RELAY_OTHER 0
#define RELAY_ALL 1
#define RELAY_FORECAST 2
#define RELAY_ACT 3
#define RELAY_FAULT 4
#define RELAY_COMMON 5
#define RELAY_CTRL 6
#define RELAY_DEVICE 7
#define RELAY_REPEAT 9
#define RELAY_BACKUP 10

const char RELAY_NAME[][12]={"其他","事故总","预告信号","动作信号","故障信号","通讯信号","控制信号","设备信号","","重合闸信号","备自投信号"};
typedef struct MODEL_RELAY							//保护节点表_模型
{
	int rly_id;										//保护ID号
	int fac_id;										//厂站ID号
	char rly_name[64];								//保护名称
	unsigned char rly_type;							//保护类型			0其他、1事故总、2预告信号、3动作信号、4故障信号、5通讯信号、6控制信号、7设备信号、9重合闸信号、10备自投信号
	int vlty_id;									//电压类型
	unsigned char yx_value;							//遥信值
	int bay_id;										//间隔ID号
	int devid_avc;									//AVC相关设备ID
}MODEL_RELAY;

#define YKTYPE_YK 0
#define YKTYPE_DAYK 1
#define YKTYPE_DIRYK 2
#define YKTYPE_AVCYK 3
#define YKTYPE_DOUYK 4
const char YKTYPE_NAME[][12]={"遥控","DA遥控","直接遥控","AVC遥控","双点遥控"};

#define YKSTATE_NORMAL 0
#define YKSTATE_YKLOCK 1
#define YKSTATE_LOCKOPEN 2
#define YKSTATE_LOCKCLOSE 3
const char YKSTATE_NAME[][12]={"遥控正常","遥控闭锁","遥控闭锁分","遥控闭锁合"};

#define AVCCTRL_NO 0
#define AVCCTRL_YES 1
const char AVCCTRL_NAME[][12]={"AVC不可控","AVC可控"};

typedef struct MODEL_YK									//遥控关系表_模型
{
	unsigned char yx_id[14];						//遥信ID号
	int fac_id;										//厂站ID号
	int yk_no;										//遥控点号
	unsigned char yk_type;							//遥控类型					0遥控、1DA遥控、2直接遥控、3AVC遥控、4双点遥控
	unsigned char yk_status;						//遥控状态					0遥控正常、1遥控闭锁、2遥控闭锁分、3遥控闭锁合
	unsigned char if_avc_yk;						//是否AVC可控				0否、1是
}MODEL_YK;

#define YTTYPE_YT 0
#define YTTYPE_AVCYT 1
const char YTTYPE_NAME[][12]={"遥调","AVC遥调"};

typedef struct MODEL_YT									//遥调关系表_模型
{
	unsigned char yc_id[14];						//遥测ID号
	int fac_id;										//厂站ID号
	int yt_no;										//遥调点号
	unsigned char yt_type;							//遥调类型				0遥调、1AVC遥调
}MODEL_YT;

#define TRANS_YKSTATE_OPEN 0				//分
#define TRANS_YKSTATE_CLOSE 1				//合
typedef struct MODEL_WINDYT								//档位遥调关系表_模型
{
	int trwd_id;								//变压器绕组ID
	unsigned char up_yx[14];					//升遥信ID
	unsigned char up_yx_state;					//控升状态				0分、1合
	unsigned char down_yx_id[14];				//降遥信ID
	unsigned char down_yx_state;				//控降状态				0分、1合
	unsigned char stop_yx_id[14];				//急停遥信ID
	unsigned char stop_yx_state;				//控停状态				0分、1合
	int max_dw;									//最大档位
	int min_dw;									//最小档位
}MODEL_WINDYT;

#define SWITCHTYPE_OTHER 1					//其他
#define SWITCHTYPE_CAPBREAK 2				//电容开关
#define SWITCHTYPE_WINDBREAK 3				//变压器开关
#define YKMODE_TEST 0						//测试
#define YKMODE_RUN 1						//运行
typedef struct MODEL_AVCRELATION				//AVC遥控关系表_模型
{
	unsigned char yx_id[14];					//遥信ID号
	int fac_id;									//厂站iD号
	unsigned char enable_avc;					//可受AVC控制				0否、1是
	unsigned char cb_type;						//开关类型					1其他、2电容器开关、3变压器分接开关
	unsigned char yk_mode;						//运行模型					0测试态、1运行态
}MODEL_AVCRELATION;


typedef struct REAL_BREAKE					//断路器信息表_实时
{
	int brk_id;									//断路器ID号
	int run_state;								//运行状态
	unsigned char yx_value;						//遥信值
}REAL_BREAKE;

typedef struct REAL_DISCR							//刀闸表_实时
{
	int discr_id;								//刀闸ID号
	int run_state;								//运行状态
	unsigned char yx_value;						//遥信值
}REAL_DISCR;

typedef struct REAL_GDDISCR						//接地刀闸表_实时
{
	int gddiscr_id;								//接地刀闸ID号
	int run_state;								//运行状态
	unsigned char yx_value;						//遥信值
}REAL_GDDISCR;

typedef struct REAL_BUS								//母线表_实时
{
	int bs_id;											//母线ID号
	int run_state;										//运行状态
	float v_value;										//母线线电压
	float c_value;										//电压相角
}REAL_BUS;

typedef struct REAL_TRANSWIND						//变压器绕组_实时
{
	int trwd_id;										//变压器绕组ID号
	int tr_id;
	unsigned char trwd_type;
	int run_state;										//运行状态
	float p_value;										//有功功率
	float q_value;										//无功功率
	float i_value;										//电流
	float tap_pos;										//绕组档位
}REAL_TRANSWIND;

typedef struct REAL_LINEDOT							//交流线段端点表_实时
{
	int acln_dot_id;									//交流线段ID号
	int fac_id;											//厂站ID
	int run_state;										//运行状态
	float p_value;										//有功功率
	float q_value;										//无功功率
	float i_value;										//电流
}REAL_LINEDOT;

typedef struct REAL_GEN									//发电机表_实时
{		
	int gn_id;											//发电机ID号
	int run_state;										//运行状态
	float p_value;										//有功功率
	float q_value;										//无功功率
	float v_value;										//电压
}REAL_GEN;

typedef struct REAL_LOAD								//负荷_实时
{
	int ld_id;											//负荷ID号
	int run_state;										//运行状态
	float p_value;										//有功功率
	float q_value;										//无功功率
	float i_value;										//电流
}REAL_LOAD;

typedef struct REAL_SHUNT							//容抗器表(电容和电抗)_实时
{
	int rc_id;											//容抗ID号
	unsigned char rc_type;
	int run_state;										//运行状态
	float q_value;										//无功功率
}REAL_SHUNT;

typedef struct REAL_RELAY								//保护节点表_实时
{
	int rly_id;									//保护ID号
	unsigned char yx_value;						//遥信
}REAL_RELAY;

#define ITERSTATE_YES 0
#define ITERSTATE_LIMIT 5
#define ITERSTATE_FAIL 6
#define ITERSTATE_NOJION 9
const char ITERSTATE_NAME[][16]={"收敛","","","","","到达迭代极限","发散","","","未参加计算"};

typedef struct PASREAL_ISLAND						//PAS电气岛信息表
{
	int keyno;											//序号
	short isrec;										//岛号
	char chst[16];										//平衡机厂站名
	int stid;											//平衡机厂站ID
	char un[20];										//平衡机名称
	int unid;											//平衡机ID
	short bus;											//节点数
	unsigned char stat;								//收敛状态										0收敛、5到达迭代极限、6发散、9未参加计算
	unsigned char obisle;							//是否可观测									0否、1是
	unsigned char lvbadp;							//有功坏数据
	unsigned char lvbadq;							//无功坏数据
}PASREAL_ISLAND;

typedef struct PASREAL_RUNINFO					//PAS最近运行信息表
{
	int runtime;										//时间
	char msg[160];										//消息
}PASREAL_RUNINFO;

typedef struct PASREAL_SEPARAMINFO			//状态估计参数和信息表
{
	unsigned char pause_flag;						//暂停计算标志
	int conv_state;									//收敛状态										0收敛、5到达迭代极限、6发散、9未参加计算
	int run_state;									//运行中标志									0否、1是
	float estimeble_rate;							//量测覆盖率
	int datemark;									//日戳
	int hourmark;									//时戳
	float conv_rate;								//当日收敛率
	int cycle_period;								//运行周期（分）
	int iter_step_limit;							//最大迭代次数
	float epsp;										//有功收敛精度
	float epsq;										//无功收敛精度
}PASREAL_SEPARAMINFO;

typedef struct PASREAL_SEMEASURE					//状态估计量测一览表
{
	int keyno;											//序号
	int stid;											//厂站ID
	int devid;											//设备ID
	short meassub;										//量测下标
	short meastype;										//量测类型
	int devmtyp;										//设备量测类型
	float measval;										//量测值
	float seval;										//状态估计值
	float err;											//误差百分数
	float qbigerr;										//大误差
	float qbad;											//坏数据
	int island;											//岛号
}PASREAL_SEMEASURE;

typedef struct AVCMODEL_STATION						//AVC厂站定义_模型
{
	int fac_id;											//厂站ID号
	int resper;											//所属责任区域
	unsigned char remove;								//厂站排出									0否、1是
	unsigned char qaut;									//自动控制									0否、1是
	int pltyp;											//时段类型
	unsigned char qdevlck;								//下属设备闭锁							0否、1是
}AVCMODEL_STATION;

#define LOCKTYPE_NORMAL 0
#define LOCKTYPE_MAN 1
#define LOACKTYPE_AUTO 2
#define LOACKTYPE_COMPLEX 3
const char LOCKTYPE_NAME[][12]={"正常投入","人工闭锁","自动闭锁","综合闭锁"};

typedef struct AVCMODEL_BUS								//AVC母线定义_模型
{
	int fac_id;											//厂站ID号
	int bsid;											//母线ID号
	int pltyp;											//时段类型
	unsigned char offavr;								//闭锁状态									0正常投入、1人工闭锁、2自动闭锁、3综合闭锁
	unsigned char qavr;									//参与计算									0否、1是
	unsigned char qgate;								//关口母线									0否、1是
}AVCMODEL_BUS;

typedef struct AVCMODEL_TRANS								//AVC变压器定义_模型
{
	int fac_id;											//厂站ID号
	int trid;											//变压器ID号
	int pltyp;											//时段类型
	unsigned char offavr;								//闭锁状态									0正常投入、1人工闭锁、2自动闭锁、3综合闭锁
	unsigned char qavr;									//参与计算									0否、1是
	short limtnum;										//动作次数限制
	int upyxid;											//升档遥信ID
	int upykno;											//升档遥控ID
	int dnyxid;											//降档遥信ID
	int dnykno;											//降档遥控ID
	int isbsid;											//控制母线
	int numday;											//日AVC动作次数
	int tnumday;										//日总动作次数
	int cnumday;										//日AVC控制次数
	int nummoon;										//月AVC动作次数
	int tnummoon;										//月总动作次数
	int cnummoon;										//月AVC控制次数
	int numyea;											//年AVC动作次数
	int tnumyea;										//年总动作次数
	int cnumyea;										//年AVC控制次数
	unsigned char qgate;								//uchar关口主变									0否、1是
}AVCMODEL_TRANS;

typedef struct AVCMODEL_SHUNT					//AVC电容器定义_模型
{
	int fac_id;											//厂站ID号
	int cpid;											//电容ID号
	int pltyp;											//时段类型
	unsigned char offavr;								//闭锁状态									0正常投入、1人工闭锁、2自动闭锁、3综合闭锁
	unsigned char qavr;									//参与计算									0否、1是
	short limtnum;										//动作次数限制
	int yxid;											//遥信ID
	int ykno;											//遥控ID
	int isbsid;											//控制母线
	int bkid;											//控制开关
	int numday;											//日AVC动作次数
	int tnumday;										//日总动作次数
	int cnumday;										//日AVC控制次数
	int nummoon;										//月AVC动作次数
	int tnummoon;										//月总动作次数
	int cnummoon;										//月AVC控制次数
	int numyea;											//年AVC动作次数
	int tnumyea;										//年总动作次数
	int cnumyea;										//年AVC控制次数
	int rtmday;											//日运行时长
	int rtmmoon;										//月运行时长
	int rtmyea;											//年运行时长
}AVCMODEL_SHUNT;

#define AVCCALCULATION_DEFAULT 0
#define AVCCALCULATION_OPF 1
#define AVCCALCULATION_CTRL 2
const char CALCULATION_NAME[][20]={"默认模式","优化算法模式","控制算法模式"};

typedef struct AVCMODEL_CTRLPARAM				//AVC控制参数表_模型
{
	char sysinfo[16];								//系统信息
	char avcmsg[64];								//运行信息
	int avcnum;										//运行次数
	int strtime;									//开始时间
	int avctime;									//计算结束时间
	unsigned char run;								//运行状态									0否、1是
	unsigned char aut;								//自动控制									0否、1是
	unsigned char abort;							//程序退出									0否、1是
	unsigned char cmd;								//命令下发									0否、1是
	unsigned char remote;							//远方模式									0否、1是
	short cycvol;									//采样周期
	int ctrlmtd;									//控制算法									0默认模式、1优化算法模式、2控制算法模式
	unsigned char ctrlre;							//电容器控制									0否、1是
	unsigned char ctrlcq;							//区域无功控制									0否、1是
	unsigned char ctrltcv;							//区域电压控制									0否、1是
	int xfregin;									//主变调档时间间隔
	int cpouin;										//电容投入后切除时间
	int cpinin;										//电容切除后投入时间
	int znctlin;									//区域控制时间间隔
	float xfnvid;									//float主变过载系数
	float avcuper;									//AVC可用率
	int avcautt;									//AVC闭环时长
	int ctrlnum;									//控制指令次数
	int ctrlsuc;									//控制成功次数
	float sucper;									//控制成功率
	int mxopnum;									//最大可动设备数
	int cpacfnm;									//容抗拒动次数
	int xfacfnm;									//主变拒动次数
	int enable;										//AVC可用标志
	float lossdec;									//日降损量
}AVCMODEL_CTRLPARAM;

typedef struct AVCMODEL_RUNPARAM					//AVC运行参数_模型
{
	int keyno;												//序号
	int strtm;												//开始时间
	int endtm;												//结束时间
	short type;												//时段类型
	int cpnum;												//电容可用次数
	int xfnum;												//变压器可用次数
	float cosfup;											//关口功率因数上限
	float cosfdn;											//关口功率因数下限
	float scosfup;											//厂站功率因数上限
	float scosfdn;											//厂站功率因数下限
	float v6up;												//6kv电压上限
	float v6dn;												//6kv电压下限
	float v10up;											//10kv电压上限
	float v10dn;											//10kv电压下限
	float v35up;											//35kv电压上限
	float v35dn;											//35kv电压下限
	float v110up;											//110kv电压上限
	float v110dn;											//110kv电压下限
	float v220up;											//220kv电压上限
	float v220dn;											//220kv电压下限
	float v330up;											//330kv电压上限
	float v330dn;											//330kv电压下限
	float v500up;											//330kv电压上限
	float v500dn;											//330kv电压下限
}AVCMODEL_RUNPARAM;

typedef struct AVCMODEL_TIMEPART						//AVC时段控制定义_模型
{
	int keyno;												//序号
	char id[32];											//时段名称
	float vup1;												//电压上限1
	float vdn1;												//电压下限1
	float cpnum1;											//电容可用次数1
	float xfnum1;											//变压器可用次数1
	float cosfup1;											//功率因数上限1
	float cosfdn1;											//功率因数下限1
	int tm1;												//时段1分割点
	float vup2;												//电压上限2
	float vdn2;												//电压下限2
	float cpnum2;											//电容可用次数2
	float xfnum2;											//变压器可用次数2
	float cosfup2;											//功率因数上限2
	float cosfdn2;											//功率因数下限2
	int tm2;												//时段2分割点
	float vup3;												//电压上限3
	float vdn3;												//电压下限3
	float cpnum3;											//电容可用次数3
	float xfnum3;											//变压器可用次数3
	float cosfup3;											//功率因数上限3
	float cosfdn3;											//功率因数下限3
	int tm3;												//时段3分割点
	float vup4;												//电压上限4
	float vdn4;												//电压下限4
	float cpnum4;											//电容可用次数4
	float xfnum4;											//变压器可用次数4
	float cosfup4;											//功率因数上限4
	float cosfdn4;											//功率因数下限4
	int tm4;												//时段4分割点
	float vup5;												//电压上限5
	float vdn5;												//电压下限5
	float cpnum5;											//电容可用次数5
	float xfnum5;											//变压器可用次数5
	float cosfup5;											//功率因数上限5
	float cosfdn5;											//功率因数下限5
	int tm5;												//时段5分割点			
	float vup6;												//电压上限6
	float vdn6;												//电压下限6
	float cpnum6;											//电容可用次数6
	float xfnum6;											//变压器可用次数6
	float cosfup6;											//功率因数上限6
	float cosfdn6;											//功率因数下限6
}AVCMODEL_TIMEPART;

#define AVCALARM_YX 0
#define AVCALARM_TRANSREFUSE 1
#define AVCALARM_TRANSSLIP 2
#define AVCALARM_CPREFUSE 3
#define AVCALARM_DISLOCATION 4
#define AVCALARM_MANUAL 5
#define AVCALARM_YCYXCLASH 6
#define AVCALARM_TOPU 7
#define AVCALARM_TRANSOVERLOAD 8
#define AVCALARM_BUSOVERVOL 9
#define AVCALARM_BUSLOWVOL 10
#define AVCALARM_CTRLOVER 11
#define AVCALARM_COLDBACK 12
#define AVCALARM_CANNOCTRL 13
#define AVCALARM_MEASURE 14
#define AVCALARM_WINDVOLFAIL 15
#define AVCALARM_TIMEPARTFAOL 16
#define AVCALARM_ONEGROUD 17
#define AVCALARM_VOLBALANCE 18
#define AVCALARM_BADDATA 19
#define AVCALARM_DEVICEFLAG 20
#define AVCALARM_SHUNTLOCK 21
#define AVCALARM_TRANSSERIES 22
const char AVCALARM_NAME[][20]={"遥信异常","分接头拒动","分接头滑档","容抗器拒动","并列主变错挡","手工操作","遥测遥信不匹配","拓扑异常","主变过载","母线过电压","母线欠电压",\
"动作次数越限","设备冷备用","无调节措施","量测不刷新","调档电压异常","时段设置错误","单相接地","三相电压不平衡","量测坏数据","设备挂牌","并联电容闭锁","主变连续同向调档",};

#define ALARMDEVICE_AVC 1
#define ALARMDEVICE_TRANS 2
#define ALARMDEVICE_SHUNT 3
#define ALARMDEVICE_GEN 4
#define ALARMDEVICE_BUS 5
#define ALARMDEVICE_STATION 6
typedef struct AVCMODEL_WARNTYPE				//AVC告警类型定义_模型
{
	int keyno;										//序号
	int id;											//告警ID
	//0遥信异常、1分接头拒动、2分接头滑档、3容抗器拒动、4并列主变错挡、5手工操作、6遥测遥信不匹配、7拓扑异常、8主变过载、9母线过电压、10母线欠电压、11动作次数越限、12设备冷备用、
	//13无调节措施、14量测不刷新、15调档电压异常、16时段设置错误、17单相接地、18三相电压不平衡、19量测坏数据、20设备挂牌、21并联电容闭锁、22主变连续同向调档
	short ot;										//告警设备类型									多选：1AVC系统、2变压器、3电容器、4发电机、5母线、6厂站
	char txt[32];									//告警内容
	unsigned char qskip;							//是否抑制告警									0否、1是									
	unsigned char qlock;							//闭锁复归方式									0人工解锁、1自动解锁
	unsigned char qsend;							//是否送告警										0否、1是
	int deltm;										//复归延时时间
}AVCMODEL_WARNTYPE;

typedef struct AVCMODEL_CTRLPLOY						//AVC控制策略_模型
{
	int keyno;												//序号
	char stm[32];											//厂站控制名
	char id[24];											//设备名
	int facid;												//厂站ID
	int devid;												//设备ID
	int devsub;												//控制设备下标
	int	isstm;												//发送时刻
	int comtm;												//执行时刻
	char cause[80];										//原因
	char result[80];									//措施
	char text[120];										//命令信息
	char cmdtype[8];									//命令类型
	short opftype;										//操作类型
	char rslttype[12];								//处理状态
	unsigned char qcheck;							//命令确认										0否、1是
	unsigned char qaut;								//自控命令										0否、1是
	int seq;													//命令编号
	int zone;													//区域ID
	int resp;													//责任区
}AVCMODEL_CTRLPLOY;

#define RESETLOCK_MANUAL 0
#define RESETLOCK_AUTO 1
const char RESETLOCK_NAME[][10]={"人工解锁","自动解锁"};
typedef struct AVCMODEL_WARNDEFINE						//AVC告警信号_模型
{
	int fac_id;												//厂站ID号
	int devid;												//告警设备ID号
	int atyid;												//告警类型ID号
	unsigned char qlock;							//闭锁复归方式								0人工解锁、1自动解锁
	unsigned char stat;								//闭锁状态										0否、1是
	short almtyp;											//告警类型
	int ontm;													//动作时间
	int offtm;												//复归时间
}AVCMODEL_WARNDEFINE;

typedef struct AVCMODEL_RELAY							//AVC保护信息定义_模型
{
	int fac_id;												//厂站ID
	int rlyid;												//保护名称
	unsigned char stat;										//状态										0否、1是
	short qlock;											//闭锁复归方式								0人工解锁、1自动解锁
	int devid1;												//关联设备
	int ontm;												//动作时间
	int offtm;												//复归时间
}AVCMODEL_RELAY;

typedef struct AVCREAL_VOLEVENT						//AVC电压越限事件表
{
	int keyno;												//序号
	char st[32];											//厂站
	char id[32];											//母线名
	float val;												//电压值
	float lmt;												//电压限值
}AVCREAL_VOLEVENT;

typedef struct AVCREAL_CMDEVENT						//AVC操作信息事件表
{		
	int keyno;												//序号
	char usr[12];											//用户名
	_int64 time;											//操作时刻
	char opefunc[24];										//操作项
	char text[120];											//操作内容
}AVCREAL_CMDEVENT;	

typedef struct AVCREAL_TRANSEVENT					//AVC变压器动作事件表
{
	int keyno;												//序号
	char stm[32];											//厂站名
	char chid[16];											//变压器名
	short sub;												//主变序号
	int fadid;												//厂站Id
	int id;													//变压器ID
	_int64 optime;											//操作时间
	short afttap;											//操作后档位
	short pretap;											//操作前档位
	float val;												//操作后电压
	char optypt[8];											//命令类型
	float prekv;											//操作前电压
	float prevh;											//动作前高压电压
	float prewh;											//动作前高压有功
	float prerh;											//动作前高压无功
	float prevm;											//动作前中压电压
	float prewm;											//动作前中压有功
	float prerm;											//动作前中压无功
	float prevl;											//动作前低压电压
	float prewl;											//动作前低压有功
	float prerl;											//动作前低压无功
	float aftvh;											//动作后高压电压
	float aftwh;											//动作后高压有功
	float aftrh;											//动作后高压无功
	float aftvm;											//动作后中压电压
	float aftwm;											//动作后中压有功
	float aftrm;											//动作后中压无功
	float aftvl;											//动作后低压电压
	float aftwl;											//动作后低压有功
	float aftrl;											//动作后低压无功
	unsigned char qavc;										//是否AVC命令										0否、1是
}AVCREAL_TRANSEVENT;

typedef struct AVCREAL_SHUNTEVENT							//AVC电容控制动作事件表
{
	int keyno;												//序号
	char stm[32];											//厂站名
	char chid[32];											//电容器名
	short sub;												//电容器序号
	int facid;												//厂站ID
	int id;													//电容器ID
	_int64 optime;											//操作时刻
	char optype[8];											//命令类型
	float val;												//操作后电压
	float prekv;											//操作前电压
	unsigned char qopen;									//操作后运行状态								0投入、1退出
	unsigned char qavc;										//是否AVC指令										0否、1是
}AVCREAL_SHUNTEVENT;

typedef struct AVCREAL_CTRLZONE								//AVC控制区域表
{
	int keyno;												//序号
	char chid[32];											//区域名称
	int vovnum;												//电压考核越限数
	int qovnum;												//无功考核越限数
	float wloss;											//区域网损值
	int normcp;												//可控电容数
	int lockcp;												//闭锁电容数
	int normxf;												//可控变压器数
	int lockxf;												//闭锁变压器数
	float varin;											//已投无功总容量
	float varoff;											//未投无功总容量
	float cosfi;											//关口功率因数
	float score;											//区域状态得分
}AVCREAL_CTRLZONE;

typedef struct AVCREAL_STATE						//AVC统计信息表
{
	int keyno;												//序号
	int devid;												//设备ID
	int fac_id;												//厂站ID
	int numall;												//日动作次数
	int numavc;												//日成功次数
	int numorder;											//日下令次数
	int numfail;											//日失败次数
	float sucrate;											//float日成功率
	char devname[32];										//设备中文名
}AVCREAL_STATE;

typedef struct AVCREAL_ZONECHANGE					//AVC省地交换信息表
{
	int keyno;												//序号
	int objtype;											//对象类型
	int objid;												//对象ID
	int objcdid;											//对象测点ID
	float fval;												//对象值
	int datdir;												//数据传输方向
}AVCREAL_ZONECHANGE;

#endif // !defined(AFX_OPEN3000_H__INCLUDED_)