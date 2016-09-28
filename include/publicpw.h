#if !defined(AFX_PUBLICPW_H__INCLUDED_)
#define AFX_PUBLICPW_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//变电站类型
const int STATION_W=1;		//水电
const int STATION_H=2;		//火电
const int STATION_T=3;		//变电站
const int STATION_C=4;		//换流站
const int STATION_F=5;		//变电站
const int STATION_PH=6;		//换流站
const int STATION_NU=7;		//换流站
const int STATION_O=8;		//其他

//发电机类型
const int GEN_TYPE_UNKOWN=0;
const int GEN_TYPE_THERMAL=1;		//火电机组
const int GEN_TYPE_HYDRO=2;		//水电机组

//设备子对象
const int SUBEQUIP_NAME=0;  //设备名字
const int TRANSF_SUB_HIG=1;	//变压器子对象高绕组
const int TRANSF_SUB_MID=2;	//变压器子对象中绕组
const int TRANSF_SUB_LOW=3;	//变压器子对象低绕组

//量测位置
const int MEAS_POS_FROMH=1;  //设备首端/变压器高
const int MEAS_POS_TOL=2;	//设备末端/双绕变低，三绕变压器中
const int MEAS_POS_LOW=3;	//三绕变压器低压侧

//变压器绕组类型
const int WINDING_TYPE_HIGH=0;  //高
const int WINDING_TYPE_LOW=1;  //低
const int WINDING_TYPE_MID=2;  //中


//电力对象类型
const int EQUIP_TYPE_UNK=0;//未知设备
const int EQUIP_TYPE_GEN=1;	//发电机
const int EQUIP_TYPE_BUS=2;	//母线
const int EQUIP_TYPE_LINE=3;	//线路
const int EQUIP_TYPE_BITRS=4;	//双绕组变
const int EQUIP_TYPE_TRITRS=5;//三绕组变
const int EQUIP_TYPE_LOAD=6;	//负荷
const int EQUIP_TYPE_SHUNT=7;	//并联无功设备
const int EQUIP_TYPE_SWITCH=8;//开关
const int EQUIP_TYPE_DCLINE=9;//直流线路
const int EQUIP_TYPE_REACT=10;//电抗器
const int EQUIP_TYPE_SVC=11; //静止无功补偿器
const int EQUIP_TYPE_MEASUREMENT=12; //量测关系
const int EQUIP_TYPE_SUB=20; //厂站
const int EQUIP_TYPE_TERM=21; //终端
const int EQUIP_TYPE_BAY=22; //间隔
const int EQUIP_TYPE_AREA=23; //区域
const int EQUIP_TYPE_DUMMY=24; //未设备

const char DevTableName[][12]={"","Gen","Bus","Line","Tfm1","Tfm2","Load","Shunt","Switch","DCLine","Sreact","SVC","","","","","","","","","Station","","","Area",""};
//量测类型
enum MEASURE_TYPE
{
	MEASURE_TYPE_UN=0,		
	MEASURE_TYPE_V=1,		//电压
	MEASURE_TYPE_P=2,		//有功
	MEASURE_TYPE_Q=3,		//无功
	MEASURE_TYPE_S=4,		//视在功率
	MEASURE_TYPE_I=5,		//电流
	MEASURE_TYPE_Pf=6,		//功率因数
	MEASURE_TYPE_T=7,		//温度
	MEASURE_TYPE_Pos=8,		//档位
	MEASURE_TYPE_f=9,		//频率
	MEASURE_TYPE_Ang=10,	//相角
	MEASURE_TYPE_YX=11,		//遥信
	MEASURE_TYPE_Va=12,		//a相电压
	MEASURE_TYPE_Vb=13,		//b相电压
	MEASURE_TYPE_Vc=14,		//c相电压
	MEASURE_TYPE_Vab=15,		//ab线电压
	MEASURE_TYPE_Vbc=16,		//bc线电压
	MEASURE_TYPE_Vca=17,		//ca线电压
	MEASURE_TYPE_Ia=18,		//a相电流
	MEASURE_TYPE_Ib=19,		//b相电流
	MEASURE_TYPE_Ic=20,		//c相电流
	MEASURE_TYPE_Rl=21,		//保护信号
	MEASURE_TYPE_ETS=22,	//事故总信号
	MEASURE_TYPE_GENRATOR=23,	//电量
	MEASURE_TYPE_UNSORT=24	//未分类
};

//等值类型
const int EQUI_TYPE_INVALID=0;//未等值
const int EQUI_TYPE_LOAD=1;	//等值负荷
const int EQUI_TYPE_GEN=2;	//等值发电机

//系统运行参数
const BYTE SYSTEM_DATARUN=1;		//数据服务
const BYTE SYSTEM_STARUN=2;			//统计服务
const BYTE SYSTEM_CTRLRUn=3;		//控制服务

const char Compress_YC=1;			//遥测压缩
const char Compress_YX=1<<1;		//遥信压缩
const char Compress_Ctrl=1<<2;		//控制压缩
const char Compress_Out=1<<3;		//越限压缩

#endif // !defined(AFX_PUBLICPW_H__INCLUDED_)
