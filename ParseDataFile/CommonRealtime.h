#pragma once



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

#pragma pack(8)


typedef struct
{
	char Title[5];  //0x68 0x68 标记 0x68 0x68   
	int nLen;       //即将发送的数据长度
}DataTitle;

//变压器绕组表
struct R_TRWD_DEVICE
{
	int tr_id;       //变压器ID
	char trwd_type;  //变压器绕组类型
	float p_value;   //有功
	float q_value;   //无功
	float i_value;   //电流
	float tap_pos;
};

//交流线段端点表
struct R_ACLN_DOT
{
	int acln_id;     //交流线段端点表
	int fac_id;      //厂站ID
	float p_value;   //有功
	float q_value;   //无功
	float i_value;   //电流
};


//母线表
struct R_BS_DEVICE
{
	int bs_id;
	float v_value; //线电压幅值
	float c_value; //电压相角
};

//发电机表
struct R_GN_DEVICE
{
	int gn_id;     //发电机ID
	float p_value; //有功值
	float q_value; //无功值
	float v_value; //电压值
	float gn_angle;//发电机功角
};

//负荷表
struct R_LD_DEVICE 
{
	int ld_id;
	float p_value;   //有功
	float q_value;   //无功
	float i_value;   //电流
};

//刀闸表
struct R_DISCR_DEVICE
{
	int discr_id;//刀闸ID
	int run_state;//投运状态
	unsigned char yx_value;//遥信状态
};

//断路器
struct R_BRK_DEVICE
{
	int brk_id;
	int run_state;//投运状态
	unsigned char yx_value;//遥信状态
};

//容抗器表  电容和电抗
struct R_RC_DEVICE
{
	int rc_id;
	unsigned char rc_type;//容抗器类型
	float q_value;//无功值
};

#pragma pack()