// DB_AVCCtrlPloy.cpp: implementation of the DB_AVCCtrlPloy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCCtrlPloy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCCtrlPloy::DB_AVCCtrlPloy()
{

}

DB_AVCCtrlPloy::~DB_AVCCtrlPloy()
{

}

void DB_AVCCtrlPloy::RefreshModel(char *pData, int bufSize)
{
	OPBUFF_AVC_EMS_Model *pRec = (OPBUFF_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;

	for (int i=0; i<bufSize/sizeof(OPBUFF_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		OPBUFF_AVC_EMS_Model* pnew = new OPBUFF_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(OPBUFF_AVC_EMS_Model));

		ScadaAVC_AVCCtrlCmd AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;						//序号
		if(MatchKeyNo(pnew->keyno, OPBUFF_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.LogTime=g_TimeFile;//CTime::GetCurrentTime();						//策略时间
		CString sztext=pnew->id;
		sztext.TrimRight();
		strcat(AVCRec.DevName, sztext);					//设备名称
		AVCRec.StationID=pnew->facid;					//厂站ID
		AVCRec.DevID=pnew->devid;						//设备ID
		AVCRec.DevSub=pnew->devsub;						//控制设备下标
		AVCRec.IssTm=pnew->isstm-CTimeSpan(0, 8, 0, 0);						//发送时刻
		AVCRec.CmdTm=pnew->comtm-CTimeSpan(0, 8, 0, 0);						//执行时刻
		sztext=pnew->cause;
		sztext.TrimRight();
		strcat(AVCRec.cause_info, sztext);				//控制原因
		sztext=pnew->result;
		sztext.TrimRight();
		strcat(AVCRec.result_info, sztext);				//措施
		sztext=pnew->text;
		sztext.TrimRight();
		strcat(AVCRec.Cmd_info, sztext);				//命令描述
		sztext=pnew->cmdtype;
		sztext.TrimRight();
		strcat(AVCRec.CmdType, sztext);					//命令类型
		AVCRec.CtrlType=pnew->optype;					//操作类型
		sztext=pnew->rslttyp;
		sztext.TrimRight();
		strcat(AVCRec.rslttype, sztext);					//处理状态
		AVCRec.qcheck=pnew->qcheck;						//命令确认
		AVCRec.qaut=pnew->qaut;							//自控命令
		AVCRec.seq=pnew->seq;							//命令编号
		AVCRec.ZoneID=pnew->zone;						//责任区ID
		AVCRec.resp=pnew->resp;						//责任区

		m_szTmp.Format("TABLE(ScadaAVC.AVCCtrlCmd),WHERE(KeyID=%d)", pnew->keyno);
		ScadaAVC_AVCCtrlCmd* pAvcRec = (ScadaAVC_AVCCtrlCmd*)g_DB.QueryRecord("AVCCtrlCmd",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCCtrlCmd", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCCtrlCmd", &AVCRec);
		}

		delete pnew;
	}
}
