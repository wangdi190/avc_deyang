// Parse.h: interface for the Parse class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSE_H__FD3EB868_408C_4608_9FD9_C3DCEBAB06BB__INCLUDED_)
#define AFX_PARSE_H__FD3EB868_408C_4608_9FD9_C3DCEBAB06BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <fstream>

#include "DB_pwSwitch.h"
#include "DB_pwBus.h"
#include "DB_pwGen.h"
#include "DB_pwLine.h"
#include "DB_pwLoad.h"
#include "DB_pwTfm.h"
#include "DB_pwTfmTap.h"
#include "DB_pwStation.h"
#include "DB_pwShuntSreact.h"
#include "DB_pwZone.h"
#include "DB_CommonVec.h"

#include "DB_AvcStation.h"
#include "DB_AvcBus.h"
#include "DB_AvcShunt.h"
#include "DB_AvcTrans.h"
#include "DB_AvcRunParam.h"
#include "DB_AvcRunTimePart.h"
#include "DB_AVCCtrlParam.h"
#include "DB_AvcRelay.h"
#include "DB_AVCWarnType.h"
#include "DB_AVCWarnInfo.h"

#include "DB_AvcRunParam.h"
#include "DB_AVCVolEvent.h"
#include "DB_AVCCtrlEvent.h"
#include "DB_AVCShuntEvent.h"
#include "DB_AVCTranEvent.h"
#include "DB_AVCCtrlPloy.h"
#include "DB_AVCCtrlZone.h"
#include "DB_AVCStatInfo.h"
#include "DB_AVCZoneChange.h"

#include "DB_PASIsland.h"
#include "DB_PASRuninfo.h"
#include "DB_PASParam.h"
#include "DB_PASMeasure.h"

#pragma pack(4)
struct DataInfo_Struct
{
	char top;
	int nTypeID;
	int nAppNo;
	int nTableNo;
	int nBufSize;
	char pName[256];
	char bottom;
};
#pragma pack()


class Parse  
{
public:
	Parse();
	virtual ~Parse();

	DB_pwSwitch m_pwSwitch;					//开关表
	DB_pwBus m_pwBus;						//母线表
	DB_pwGen m_pwGen;						//发电机表
	DB_pwLine m_pwLine;						//线路表
	DB_pwLoad m_pwLoad;						//负荷表
	DB_pwTfm m_pwTfm;						//变压器表
	DB_pwTfmTap m_pwTfmTap;					//变压器档位类型表
	DB_pwStation m_pwStation;				//厂站表
	DB_pwShuntSreact m_pwShuntSreact;		//电容电抗表
	DB_pwZone m_pwZone;						//区域表
	DB_CommonVec m_CommonVec;				//电压类型表

	DB_AvcStation m_avcstation;				//AVC厂站表
	DB_AvcBus m_avcbus;						//AVC母线表
	DB_AvcShunt m_avcshunt;					//AVC电容表
	DB_AvcTrans m_avctrans;					//AVC变压器表
	DB_AvcRunParam m_avcrunparam;			//AVC控制默认参数表
	DB_AvcRunTimePart m_timepart;			//AVC控制时段表
	DB_AVCCtrlParam m_avcctrlparam;			//AVC控制参数表

	DB_AvcRelay m_relay;					//AVC保护表
	DB_AVCWarnType m_warntype;				//AVC告警类型
	DB_AVCWarnInfo m_warninfo;				//AVC告警信息表

	DB_AVCVolEvent m_avcvolevent;			//AVC电压越限表
	DB_AVCCtrlEvent m_avcctrlevent;			//AVC控制事件表
	DB_AVCShuntEvent m_avcshuntevent;		//AVC电容控制事件
	DB_AVCTranEvent m_avctranevent;			//AVC变压器控制事件
	DB_AVCCtrlPloy m_avcctrlcmd;			//AVC控制指令表
	DB_AVCCtrlZone m_avcctrlzone;			//AVC控制区域表
	DB_AVCStatInfo m_avcstainfo;			//统计信息表
	DB_AVCZoneChange m_avczonechange;			//区域交换表

	DB_PASIsland m_pasisland;				//PAS电气岛
	DB_PASRuninfo m_pasruninfo;				//PAS运行信息
	DB_PASParam m_pasparam;					//PAS运行参数
	DB_PASMeasure m_pasmeasure;				//PAS量测数据
public:
	void InitParamer();
	void StartPrase(char *pFilePath);
	void SwitchPrase(char* pPacket, DataInfo_Struct *pdInfo);
};

#endif // !defined(AFX_PARSE_H__FD3EB868_408C_4608_9FD9_C3DCEBAB06BB__INCLUDED_)
