// DB_AVCCtrlParam.cpp: implementation of the DB_AVCCtrlParam class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCCtrlParam.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCCtrlParam::DB_AVCCtrlParam()
{

}

DB_AVCCtrlParam::~DB_AVCCtrlParam()
{

}

void DB_AVCCtrlParam::RefreshModel(char *pData, int bufSize)
{
//	int n = sizeof(CTime);

	ITEM_AVC_EMS_Model *pRec = (ITEM_AVC_EMS_Model*)pData;
	ScadaAVC_AVCCtrRunParam DBrec;
	ZeroMemory(&DBrec, sizeof(ScadaAVC_AVCCtrRunParam));

	CTime lasttm=CTime(2000,1,1,0,0,0);
	ScadaAVC_AVCCtrRunParam* pparam=NULL;
	int datanum=0;
	CUIntArray posarray;
	if(SearchData("ScadaAVC", "AVCCtrRunParam", "", "StartTime", (void**)&pparam, datanum, posarray))
	{
		if(datanum>0)
			lasttm=(pparam+datanum-1)->StartTime;
	}
	
	if(pparam!=NULL)
	{
		delete []pparam;
	}

	CString m_szTmp;
	int m_recn=0;

	for (int i=0; i<bufSize/sizeof(ITEM_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		ITEM_AVC_EMS_Model* pnew = new ITEM_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(ITEM_AVC_EMS_Model));

		ZeroMemory(&DBrec, sizeof(ScadaAVC_AVCCtrRunParam));
		ScadaAVC_AVCCtrRunParam AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		CTime starttime=pnew->strtime-CTimeSpan(0, 8, 0, 0);
		if(starttime<=lasttm)
		{
			delete pnew;
			continue;
		}
		lasttm=starttime;

		AVCRec.DateLog=g_TimeFile;//CTime::GetCurrentTime();						//系统运行日志时间
		strcat(AVCRec.SysInfo, pnew->sysinfo);					//系统信息
		strcat(AVCRec.RunMsg, pnew->avcmsg);					//运行信息
		AVCRec.RunNum=pnew->avcnum;						//运行次数
		AVCRec.StartTime=pnew->strtime-CTimeSpan(0, 8, 0, 0);					//启动时间
		AVCRec.AvcTime=pnew->avctime-CTimeSpan(0, 8, 0, 0);						//AVC结束时间
		AVCRec.Run_Sta=pnew->run;						//运行状态
		AVCRec.Auto_Sta=pnew->aut;						//自动控制状态
		AVCRec.Quit_Sta=pnew->abort;						//程序退出状态
		AVCRec.Cmd_Sta=pnew->cmd;						//命令下发状态
		AVCRec.Remote_Sta=pnew->remote;					//远动状态
		AVCRec.Enable_Sta=pnew->enable;					//AVC可用标志
		AVCRec.Cycvol=pnew->cycvol;						//采样周期
		AVCRec.Ctrlmtd=pnew->ctrlmtd;						//控制算法
		AVCRec.Ctrl_CP=pnew->ctrlre;						//电容控制状态
		AVCRec.Ctrl_Cos=pnew->ctrlcq;						//区域无功控制状态
		AVCRec.Ctrl_Vol=pnew->ctrltcv;						//区域电压控制状态
		AVCRec.Xfre_space=pnew->xfregin;					//主变调档时间间隔
		AVCRec.CPOut_space=pnew->cpouin;					//电容投入退出时间间隔
		AVCRec.CPIn_space=pnew->cpinin;					//电容退出投入时间间隔
		AVCRec.Zone_space=pnew->znctlin;					//区域控制时间间隔
		AVCRec.Xfr_overload=pnew->xfhvld;				//主变过载系数
		AVCRec.AvcUse_Rate=pnew->avcuper;					//AVC可用率
		AVCRec.AvcClosedTime=pnew->avcautt;				//AVC闭环运行时长
		AVCRec.CtrlNum=pnew->ctrlnum;						//AVC控制指令数
		AVCRec.CtrlSucNum=pnew->ctrlsuc;					//AVC控制成功数
		AVCRec.CtrlSuc_Rate=pnew->sucper;				//AVC控制成功率
		AVCRec.MaxCtrlNum=pnew->mxopnum;					//最大可动设备数
		AVCRec.CP_RefuseNum=pnew->cpacfnm;				//容抗拒动次数
		AVCRec.XF_RefuseNum=pnew->xfacfnm;				//变压器拒动次数
		AVCRec.lossdec=pnew->lossdec;						//日降损量

//		m_szTmp.Format("TABLE(ScadaAVC.AVCCtrRunParam),WHERE(StartTime=%d)", AVCRec.StartTime);
//		ScadaAVC_AVCCtrRunParam* pAvcRec = (ScadaAVC_AVCCtrRunParam*)g_DB.QueryRecord("AVCCtrRunParam",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");
//		if(pAvcRec == NULL)
			LSI_AppendRec("ScadaAVC.AVCCtrRunParam", &AVCRec);
		delete pnew;
	}
}