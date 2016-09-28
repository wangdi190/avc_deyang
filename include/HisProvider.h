// HisProvider.h : main header file for the HISPROVIDER DLL
/************************************************/
//编  码：张强
//时  间：2007-06-13
//功能描述：历史数据提供者输出函数
/************************************************/


#if !defined(AFX_HISPROVIDER_H__93D53415_6572_4FA9_BE35_FCB9A182080F__INCLUDED_)
#define AFX_HISPROVIDER_H__93D53415_6572_4FA9_BE35_FCB9A182080F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif


//历史数据类型定义
const int HIS_GEN=0;		//发电机
const int HIS_LOAD=1;		//负荷
const int HIS_SHUNT=2;		//电容
const int HIS_SREACT=3;		//电抗
const int HIS_TFM1=4;		//双绕组变

const int HIS_TFM2=5;		//三绕组变
const int HIS_BUS=6;		//母线
const int HIS_LINE=7;		//交流线路
const int HIS_SWITCH=8;		//开关
const int HIS_DCLINE=9;		//直流线路

const int HIS_GND=10;		//接地
const int HIS_SVC=11;		//静态无功补偿
const int HIS_STATION=12;	//变电站
const int HIS_ZONE=13;		//区域
const int HIS_PT=14;		//PT

const int HIS_CVT=15;		//CTV
const int HIS_SYSALARM=16;		//区域
const int HIS_AVC=17;		//电压考核曲线
const int HIS_DYNMONITOR=18;		//PT
const int HIS_RELAY=19;		//CTV
const int HIS_TANK=20;		//间隔
const int HIS_BAY=21;		//单元

const int HIS_END=22;		//最后一张历史表序号，添加新表此表顺延！！！

//历史数据库全表名
static const char* chHisName[]={"HIS_Gen","HIS_Load","HIS_Shunt","HIS_Sreact","HIS_Tfm1",
"HIS_Tfm2","HIS_Bus","HIS_Line","HIS_Switch","HIS_DCLine",
"HIS_GND","HIS_SVC","HIS_STATION","HIS_ZONE","HIS_PT",
"HIS_CVT","HIS_SYSALARM","HIS_AVC","HIS_DYNMONITOR","HIS_RELAY", "HIS_TANK", "HIS_BAY"};

//历史数据库数据表表名
static const char* chHisData[]={"HIS_Gen2","HIS_Load2","HIS_Shunt2","HIS_Sreact2","HIS_Tfm12",
"HIS_Tfm22","HIS_Bus2","HIS_Line2","HIS_Switch2","HIS_DCLine2",
"HIS_GND2","HIS_SVC2","HIS_STATION2","HIS_ZONE2","HIS_PT2",
"HIS_CVT2","HIS_SYSALARM2","HIS_AVC2","HIS_DYNMONITOR2","HIS_RELAY2", "HIS_TANK2", "HIS_BAY2"};

//内数据库表名
static const char* chMemName[]={"Gen","Load","Shunt","Sreact","Tfm1",
"Tfm2","Bus","Line","Switch","DCLine",
"GND","SVC","Station","Zone","PT",
"CVT","SysAlarm","AVC","DynMonitor","Relay", "Tank", "Bay"};

/////////////////////////////////////////////////////////////////////////////
// CHisProvider
// See HisProvider.cpp for the implementation of this class
//
//打开数据提供者,初始化数据库连接
BOOL WINAPI IniProvider();

//关闭数据提供者
void WINAPI	CloseProvider();
//***********************************************************************************//
//先调IniProvider,在调用后面的函数,若不需要了可用CloseProvider关闭数据库连接,释放内存//
//***********************************************************************************//

//保存历史数据
void WINAPI	SaveHisData();

//***********************************************************************************//
//下面三个是历史数据播放函数接口,按顺序调用,GetNextSection的tmCur,可由GetFirstSection//
//的tmList中的值任意选取                                                             //
//***********************************************************************************//
//注册需要播放的数据(pRecord:数据记录指针，num:数量，type:类型)
int WINAPI RegPlayData(DWORD* pRecord,int num,int type);

//获取历史数据断面数(tmStart:开始时间，tmEnd:结束的时间，tmList:断面数时间列表，iMaxSection:tmList可返回最大数)(暂未实现)
int WINAPI GetSectionList(time_t tmStart,time_t tmEnd,time_t* pList,int iMaxSection);

//开始获取数据
BOOL WINAPI	BeginGettingData();

//获取历史数据断面，并存入内存历史库(tmCur:要播放的数据段时间，tmNext:下一个要播放的时间段)
BOOL WINAPI	GetNextSection(time_t tmCur,time_t &tmNext);

//获取历史数据断面，并存入内存历史库(tmCur:要播放的数据段时间，tmNext:下一个要播放的时间段)
BOOL WINAPI	GetPreSection(time_t tmCur,time_t &tmNext);

//清除全部注册数据
void WINAPI ClearAllRegData();
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISPROVIDER_H__93D53415_6572_4FA9_BE35_FCB9A182080F__INCLUDED_)
