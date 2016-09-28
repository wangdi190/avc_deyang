// DB_PASParam.cpp: implementation of the DB_PASParam class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_PASParam.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_PASParam::DB_PASParam()
{

}

DB_PASParam::~DB_PASParam()
{

}

void DB_PASParam::RefreshModel(char *pData, int bufSize)
{
	
	PARA_RTNET_EMS_Model *pRec = (PARA_RTNET_EMS_Model*)pData;
	ScadaAVC_PasSEParam DBrec;
	int m_recn;
	LSI_EmptyTable("ScadaAVC.PasSEParam", false);

	for (int i=0; i<bufSize/sizeof(PARA_RTNET_EMS_Model); i++)
	{
		PARA_RTNET_EMS_Model* pnew = new PARA_RTNET_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(PARA_RTNET_EMS_Model));

		ZeroMemory(&DBrec, sizeof(DBrec));

		ScadaAVC_PasSEParam* pDBrec1 = (ScadaAVC_PasSEParam*)g_DB.QueryRecord("PasSEParam",NULL,m_recn,"ScadaAVC");

		DBrec.Run_State=pnew->run_flag;					//当前运行状态
		DBrec.Pause_State=pnew->pause_flag;					//暂停计算状态
		DBrec.RunTime=pnew->hourmark;//+pnew->datemark;						//计算时间
		DBrec.Conv_State=pnew->conv_state;					//当前收敛状态
		DBrec.Measure_Rate=pnew->estimable_rate;				//遥测覆盖率
		DBrec.CycleTime=pnew->conv_rate;					//运行周期(分)
		DBrec.MaxIter=pnew->iter_step_limit;						//最大迭代次数
		DBrec.EpsP=pnew->epsp;						//有功收敛精度
		DBrec.EpsQ1=pnew->epsq;						//无功收敛精度

		if(pDBrec1==NULL)
			LSI_AppendRec("ScadaAVC.PasSEParam", &DBrec);
		else
		{
			DBrec.SE_Rate=pDBrec1->SE_Rate;						//当前状估合格率
			DBrec.SE_DayRate=pDBrec1->SE_DayRate;					//当日状估合格率
			DBrec.SE_MonRate=pDBrec1->SE_MonRate;					//月状估合格率
			DBrec.SE_YearRate=pDBrec1->SE_YearRate;					//年状估合格率
			DBrec.LogTime=g_TimeFile;
			LSI_UpdateARecord("ScadaAVC.PasSEParam", &DBrec,0);
		}
		delete pnew;
	}
}
