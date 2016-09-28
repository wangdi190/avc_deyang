// Parse.cpp: implementation of the Parse class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "Parse.h"
#include "ParseDataFileDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



Parse::Parse()
{

}

Parse::~Parse()
{

}

CParseDataFileDlg *pMainDlg;
void Parse::InitParamer()
{
	
	pMainDlg = (CParseDataFileDlg*)AfxGetApp()->m_pMainWnd;

	m_pwTfm.InitParam();
	m_pwSwitch.InitParam();
	m_pwShuntSreact.InitParam();
	m_pwLoad.InitParam();
	m_pwLine.InitParam();
	m_pwGen.InitParam();
	m_pwBus.InitParam();
	m_pwStation.InitParam();
	return;

	LSI_EmptyTable("visualpw.Bus", false);
	LSI_EmptyTable("visualpw.Gen", false);
	LSI_EmptyTable("visualpw.Line", false);
	LSI_EmptyTable("visualpw.Tfm1", false);
	LSI_EmptyTable("visualpw.Tfm2", false);
	LSI_EmptyTable("visualpw.Load", false);
	LSI_EmptyTable("visualpw.Shunt", false);
	LSI_EmptyTable("visualpw.Sreact", false);
	LSI_EmptyTable("visualpw.Switch", false);
	LSI_EmptyTable("visualpw.GND", false);

	LSI_EmptyTable("ScadaAVC.AVCStation", false);
	LSI_EmptyTable("ScadaAVC.AVCBus", false);
	LSI_EmptyTable("ScadaAVC.AVCTrans", false);
	LSI_EmptyTable("ScadaAVC.AVCShunt", false);
}


void Parse::StartPrase(char *pFilePath)
{
	if(pFilePath == NULL)
		return;

	DataInfo_Struct dInfo;
	std::ifstream fin(pFilePath, std::ios::binary);
	
	if(fin)
	{
		while(fin.good())
		{
			memset(&dInfo, 0, sizeof(DataInfo_Struct));
			fin.read((char*)&dInfo, sizeof(DataInfo_Struct));
			if( dInfo.top ==0x16 && dInfo.bottom ==0x16 )
			{
				char *pData = new char[dInfo.nBufSize+1];
				memset(pData, 0, dInfo.nBufSize+1);
				fin.read(pData, dInfo.nBufSize);
				
				
				SwitchPrase(pData, &dInfo);

				delete pData;
			}
			else
				break;
		}
	}
	fin.close();
}



void Parse::SwitchPrase(char* pPacket, DataInfo_Struct *pdInfo)
{
	int lLength = pdInfo->nBufSize;
	switch (pdInfo->nTypeID)
	{
	case TRWD_DEVICE_REAL:
		{
			m_pwTfm.RefreshRealTime_TRWD(pPacket, lLength);
		}break;//变压器绕组
	case ACLN_DOT_REAL: 
		{
			m_pwLine.RefreshRealTime_Dot(pPacket, lLength);
		}break;//交流线段端点表
	case GN_DEVICE_REAL:
		{
			m_pwGen.RefreshRealTime(pPacket, lLength);
		}break;//发电机
	case BS_DEVICE_REAL:
		{
			m_pwBus.RefreshRealTime(pPacket, lLength);
		}break;//母线
	case LD_DEVICE_REAL:
		{
			m_pwLoad.RefreshRealTime(pPacket, lLength);
		}break;//负荷
	case DISCR_DEVICE_REAL:
		{
			m_pwSwitch.RefreshRealTime_Discr(pPacket, lLength);
		}break;//刀闸表
	case BRK_DEVICE_REAL:
		{
			m_pwSwitch.RefreshRealTime_Brk(pPacket, lLength);
		}break;//断路器信息表
	case RC_DEVICE_REAL:
		{
			m_pwShuntSreact.RefreshRealTime(pPacket, lLength);
		}break;//容抗器
	case VL_TYPE_MODEL:
		{
			m_CommonVec.RefreshModel_Voltage(pPacket, lLength); 
		}break;//电压等级
	case BRK_DEVICE_MODEL:
		{
			m_pwSwitch.RefreshModel_Brk(pPacket, lLength); 
		}break;//断路器信息表
	case DISCR_DEVICE_MODEL:
		{
			m_pwSwitch.RefreshModel_Discr(pPacket, lLength);
		}break;//刀闸表
	case GDDISCR_DEVICE_MODEL:
		{
			m_pwSwitch.RefreshModel_Gddiscr(pPacket, lLength); 
		}break;//接地刀闸表
	case BS_DEVICE_MODEL:
		{
			m_pwBus.RefreshModel(pPacket, lLength);
		}break;//母线表
	case TR_DEVICE_MODEL:
		{
			m_pwTfm.RefreshModel_TR(pPacket, lLength);
		}break;//变压器表
	case TRWD_DEVICE_MODEL:
		{
			m_pwTfm.RefreshModel_TRWD(pPacket, lLength);
		}break;//变压器绕组
	case TAP_TYPE_MODEL:
		{
			m_pwTfmTap.RefreshModel(pPacket, lLength);
		}break;	//绕组类型
	case GN_DEVICE_MODEL:
		{
			m_pwGen.RefreshModel(pPacket, lLength);
		}break;//发电机表
	case LD_DEVICE_MODEL:
		{
			m_pwLoad.RefreshModel(pPacket, lLength);
		}break;//负荷
	case ACLN_DEVICE_MODEL:
		{
			m_pwLine.RefreshModel(pPacket, lLength);
		}break;//交流线段表
	case ACLN_DOT_MODEL:
		{
			m_pwLine.RefreshModel_Dot(pPacket, lLength);
		}break;//交流线段端点表
	case FAC_INFO_MODEL:
		{
			m_pwStation.RefreshModel(pPacket, lLength);
		}break;//厂站信息表
	case DIV_INFO_MODEL:
		{
			m_pwZone.RefreshModel(pPacket, lLength);
		}break;//区域表
	case RC_DEVICE_MODEL:
		{
			m_pwShuntSreact.RefreshModel(pPacket, lLength);
		}break;//容抗器表

	case STM_AVC_EMS_MODEL:	
		{
			m_avcstation.RefreshModel(pPacket, lLength);	
		}break;//AVC厂站定义
	case NDM_AVC_EMS_MODEL:	
		{
			m_avcbus.RefreshModel(pPacket, lLength);	
		}break;//AVC母线控制定义
	case XFM_AVC_EMS_MODEL:
		{
			m_avctrans.RefreshModel(pPacket, lLength);	
		}break;//AVC变压器控制定义
	case CPM_AVC_EMS_MODEL:
		{
			m_avcshunt.RefreshModel(pPacket, lLength);	
		}break;//AVC电容器控制定义
		
	case ITEM_AVC_EMS_MODEL://AVCRUNPARAM_AVC_EMS_MODEL:
		{
			m_avcctrlparam.RefreshModel(pPacket, lLength);	
		}break;//AVC控制定义
	case RUNPLT_AVC_EMS_MODEL:
		{
			m_avcrunparam.RefreshModel(pPacket, lLength);
		}break;//AVC运行参数
	case DEVPLT_AVC_EMS_MODEL:
		{
			m_timepart.RefreshModel(pPacket, lLength);
		}break;//AVC时段控制定义
/*	case M_AVC_WARMTYPE:
		{
			pMainDlg->AddTip("AVC告警类型 模型", false);
			break;
		}//告警类型
	case M_AVC_CONPLOY:
		{
			pMainDlg->AddTip("AVC控制策略 模型", false);
			break;
		}//控制策略
	case M_AVC_WARMSIGN:
		{
			pMainDlg->AddTip("AVC告警信号 模型", false);
			break;
		}//告警信号*/
	case RELAY_AVC_EMS_MODEL:
		{
			m_relay.RefreshModel(pPacket, lLength);	
		}break;//avc保护定义表
	case ALMTYP_AVC_EMS_MODEL:
		{
			m_warntype.RefreshModel(pPacket, lLength);
		}break;//告警类型
	case ALMYX_AVC_EMS_MODEL:
		{
			m_warninfo.RefreshModel(pPacket, lLength);
		}break;//告警信息
	case OVBUS_AVC_EMS_MODEL://VOLEVENT_AVC_EMS_MODEL:
		{
			m_avcvolevent.RefreshModel(pPacket, lLength);
		}break;//电压越限
	case AOPMSG_AVC_EMS_MODEL://CTRLEVENT_AVC_EMS_MODEL:
		{
			m_avcctrlevent.RefreshModel(pPacket, lLength);
		}break;//控制事件
	case XFACT_AVC_EMS_MODEL://TRANSEVENT_AVC_EMS_MODEL:
		{
			m_avctranevent.RefreshModel(pPacket, lLength);
		}break;//变压器事件
	case CPACT_AVC_EMS_MODEL://SHUNTEVENT_AVC_EMS_MODEL:
		{
			m_avcshuntevent.RefreshModel(pPacket, lLength);	
		}break;//电容器事件
	case OPBUFF_AVC_EMS_MODEL://CTRLCMD_AVC_EMS_MODEL:
		{
			m_avcctrlcmd.RefreshModel(pPacket, lLength);
		}break;//控制策略
	case ZONE_AVC_EMS_MODEL://AVCCTRLZONE_AVC_EMS_MODEL:
		{
			m_avcctrlzone.RefreshModel(pPacket, lLength);
		}break;//控制区域
	case STAT_AVC_EMS_MODEL:
		{
			m_avcstainfo.RefreshModel(pPacket, lLength);
		}break;//统计信息表
	case EXCHG_AVC_EMS_MODEL://AVCZONECHANGE_AVC_EMS_MODEL:
		{
			m_avczonechange.RefreshModel(pPacket, lLength);
		}break;//交换区域表
	case DIILND_COMM_EMS_MODEL:
		{
			m_pasisland.RefreshModel(pPacket, lLength);	
		}break;//电气岛
	case RECENTMSG_COMM_EMS_MODEL:
		{
			m_pasruninfo.RefreshModel(pPacket, lLength);
		}break;//运行信息
	case PARA_RTNET_EMS_MODEL:
		{
			m_pasparam.RefreshModel(pPacket, lLength);
		}break;//运行参数
	case SEMEAS_RTNET_EMS_MODEL:
		{
			m_pasmeasure.RefreshModel(pPacket, lLength);		
		}break;//PAS量测数据
	}
	pMainDlg->AddTip(UT2MB(pdInfo->pName), false);
}