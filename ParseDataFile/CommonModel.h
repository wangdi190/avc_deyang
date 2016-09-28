#pragma once

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

#pragma pack(8)

struct MODEL_VL_TYPE
{
	int vlty_id; //电压类型ID号
	float vbase; //电压基值
};

//断路器信息表
struct MODEL_BRK_DEVICE
{
	int brk_id;
	int fac_id;//厂站ID
	char brk_name[64];//断路器名称
	int vlty_id; //电压类型ID号
	int nd1_no;//节点1号
	int nd2_no;//节点2号
	int run_state;//遥信状态
};

//刀闸表
struct MODEL_DISCR_DEVICE
{
	int discr_id;
	int fac_id;//厂站ID
	char discr_name[64];//刀闸名称
	int vlty_id; //电压类型ID号
	int nd1_no;  //节点1号
	int nd2_no;  //节点2号
	int run_state;//遥信状态
};

//接地刀闸表
struct MODEL_GDDISCR_DEVICE
{
	int gddiscr_id;
	int fac_id;//厂站ID
	char gddiscr_name[64];//接地刀闸名称
	int vlty_id; //电压类型ID号
	int nd_no;//节点号
};

//母线表
struct MODEL_BS_DEVICE
{
	int bs_id;  //
	int fac_id;//厂站ID
	char bs_name[64];//母线名称
	int vlty_id; //电压类型ID号
	float vmax; //电压上限
	float vmin; //电压下限
	int nd_no;//节点号
	int run_state;  //投运状态
};

//变压器表
struct MODEL_TR_DEVICE
{
	int tr_id;          //变压器ID号
	int fac_id;			//厂站ID
	char tr_name[64];   //变压器名称
	char trty;		    //绕组类型
	int run_state;		//投运状态
};

//变压器绕组
struct MODEL_TRWD_DEVICE
{
	int trwd_id;        //变压器绕组ID
	int fac_id;         //厂站ID
	char trwd_name[64]; //变压器绕组名称
	int tr_id;          //变压器ID号
	char trwd_type;     //变压器绕组类型
	float vnom;         //额定电压
	int nd_no;          //节点号
	int vlty_id; //电压类型ID号
	float snom;//额定功率
	int tapty_id;//分接头
	float pk;//短路损耗
	float uk; //短路电压百分
	float tapty_pos;
	float r_value_pu;//正序电阻标幺值
	float x_value_pu;//正序电抗标幺值
	float r0_value_pu;//零序电阻标幺值
	float x0_value_pu;//零序电抗标幺值
};

//变压器绕组档位
struct MODEL_TAP_DEVICE
{
	int tapty_id;				//类型ID
	char taptye_name[64];        //变压器绕组ID
	int tapty_mn;
	int tapty_mx;
	int tapty_nom;
	float tapty_step;
};

//发电机表
struct MODEL_GN_DEVICE
{
	int gn_id;    //发电机id
	int fac_id;    //厂站ID号
	char gn_name[64]; //发电机名称
	int vlty_id;   //电压类型ID号
	float pmax;    //有功上限
	int nd_no;     //节点号
	int run_state;      //发电机状态
};

//负荷
struct MODEL_LD_DEVICE
{
	int ld_id;
	int fac_id;//厂站ID号
	char ld_name[64];//负荷名称
	int vlty_id;   //电压类型ID号
	int nd_no;     //节点号
	int run_state;      //负荷状态
};

//交流线段表
struct MODEL_ACLN_DEVICE
{
	int acln_id;
	int fac_id_s;        //一端厂站ID
	int fac_id_e;        //二端厂站ID;
	char acln_name[64];  //交流线段名称
	int vlty_id;         //电压类型ID号
	int line_id;         //线路ID号
	float smax;          //功率限值
	float imax1;			//电流上限
	unsigned char eq_fg;//等值类型
	int run_state;       //线路状态

	float r_value_pu;     //正序电阻标幺值
	float x_value_pu;	  //正序电抗标幺值
	float bch_value_pu;   //正序电纳标幺值

	float r0_value_pu;     //零序电阻标幺值
	float x0_value_pu;	   //零序电抗标幺值
	float bch0_value_pu;   //零序电纳标幺值

};

//交流线段端点表
struct MODEL_ACLN_DOT
{
	int fac_id;            //厂站ID
	char acln_dot_name[64];//交流线段端点表名称
	int acln_id;           //所属交流线段ID号
	int vlty_id;           //电压类型ID号
	int nd_no;             //节点号
};

//厂站信息表
struct MODEL_FAC_INFO
{
	int fac_id;        //厂站ID
	char fac_name[64]; //厂站名称
	short fac_serial;  //厂站编号
	int area_id;       //区域ID
	int fac_type;      //厂站类型
	int vlty_id;       //电压类型ID号
};

//行政区域表
struct MODEL_DIV_INFO
{
	int area_id;
	char area_name[64]; //区域名称
	short area_no;      //区域编号
};

//容抗器表  电容和电抗
struct MODEL_RC_DEVICE
{
	int rc_id;
	int fac_id;            //厂站ID
	char rc_name[64]; //容抗器名称
	int vlty_id;       //电压类型ID号
	unsigned char rc_type;//容抗器类型
	int nd1_no;      //节点1号
	int nd2_no;//节点2号
	int nd3_no;//节点3号
	int run_state;  //状态
	float qnom;		//额定容量
	float vnom;		//额定电压
	int q_status;	//控制状态
};

//AVC厂站控制定义
struct AVC_STATION			
{
	int fac_id;					//厂站ID
	int respar;					//所属责任区
	unsigned char remove;		//厂站排除
	unsigned char qaut;			//自动控制
	int pltyp;					//时段类型
	unsigned char qdevlck;		//下属设备闭锁
};


//AVC母线控制
struct AVC_BUS
{
	int fac_id;					//厂站ID
	int bsid;					//母线ID
	int pltyp;					//时段类型
//	float val;					//电压值
//	float vup;					//电压上限
//	float vdn;					//电压下限
	unsigned char offavr;		//闭锁状态
	unsigned char qavr;			//参与计算
	unsigned char qgate;		//关口母线
//	int iszone;					//所属区域
};

//AVC变压器控制
struct AVC_TRANS
{
	int fac_id;					//厂站ID
	int trid;					//变压器ID
	int pltyp;					//时段类型
	unsigned char offavr;		//闭锁状态
	unsigned char qavr;			//参与计算
	short limtnum;				//控制限值
	int upyxid;					//升档遥信ID
	int upykno;					//升档遥控点号
	int dnyxid;					//降档遥信ID
	int dnykno;					//降档遥控点号
};

//AVC电容控制
struct AVC_SHUNT
{
	int fac_id;					//厂站ID
	int cpid;					//电容ID
	unsigned char offavr;		//闭锁状态
	unsigned char qavr;			//参与计算
	int pltyp;					//时段类型
//	int iszone;					//所属区域
};

//AVC控制参数
struct AVC_CtrlParam
{
	int fac_id;					//厂站ID
	int shid;					//母线ID
	int pltyp;					//时段类型
	unsigned char offavr;		//闭锁状态
	unsigned char qavr;			//参与计算
	int iszone;					//所属区域
};

//AVC运行参数
struct AVC_RunParam
{
	int strtm;					//起始时间
	int endtm;					//终止时间
	short type;					//时段类型
	int cpnum;					//电容控制数
	int xfnum;					//变压器控制数
	float cosfup;				//关口功率上限
	float cosfdn;				//关口功率下限
	float scosfup;				//厂站功率上限
	float scosfdn;				//厂站功率下限
	float v6up;					//6kv电压上限
	float v6dn;					//6kv电压下限
	float v10up;				//10kv电压上限
	float v10dn;				//10kv电压下限
	float v35up;				//35kv电压上限
	float v35dn;				//35kv电压下限
	float v110up;				//110kv电压上限
	float v110dn;				//110kv电压下限
	float v220up;				//220kv电压上限
	float v220dn;				//220kv电压下限
	float v500up;				//500kv电压上限
	float v500dn;				//500kv电压下限
};

//AVC设备控制时段定义
struct AVC_TimePart
{
	int keyno;					//编号
	char idname[32];			//时段定义名称
	float vup1;					//电压上限1
	float vdn1;					//电压下限1
	short cpnum1;				//电容控制数1
	short xfnum1;				//调档控制数1
	float cosfup1;				//功率上限1
	float cosfdn1;				//功率下限1
	int tm1;					//时段1
	float vup2;					//电压上限2
	float vdn2;					//电压下限2
	int cpnum2;				//电容控制数2
	int xfnum2;				//调档控制数2
	float cosfup2;				//功率上限2
	float cosfdn2;				//功率下限2
	int tm2;					//时段2
	float vup3;					//电压上限3
	float vdn3;					//电压下限3
	int cpnum3;				//电容控制数3
	int xfnum3;				//调档控制数3
	float cosfup3;				//功率上限3
	float cosfdn3;				//功率下限3
	int tm3;					//时段3
	float vup4;					//电压上限4
	float vdn4;					//电压下限4
	int cpnum4;				//电容控制数4
	int xfnum4;				//调档控制数4
	float cosfup4;				//功率上限4
	float cosfdn4;				//功率下限4
	int tm4;					//时段4
	float vup5;					//电压上限5
	float vdn5;					//电压下限5
	int cpnum5;				//电容控制数5
	int xfnum5;				//调档控制数5
	float cosfup5;				//功率上限5
	float cosfdn5;				//功率下限5
	int tm5;					//时段5
//	int tm6;					//时段6
	float vup6;					//电压上限6
	float vdn6;					//电压下限6
	int cpnum6;				//电容控制数6
	int xfnum6;				//调档控制数6
	float cosfup6;				//功率上限6
	float cosfdn6;				//功率下限6
};

//保护信号表
struct AVC_Relay
{
	int fac_id;					//厂号
	int rlyid;					//保护名称
	unsigned char stat;			//状态
	short qlock;				//闭锁复归方式
	int devid1;					//关联设备
	int ontm;					//动作时间
	int offtm;					//复归时间
};

#pragma pack()