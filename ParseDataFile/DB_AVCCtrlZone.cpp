// DB_AVCCtrlZone.cpp: implementation of the DB_AVCCtrlZone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCCtrlZone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCCtrlZone::DB_AVCCtrlZone()
{

}

DB_AVCCtrlZone::~DB_AVCCtrlZone()
{

}
void DB_AVCCtrlZone::RefreshModel(char* pData, int bufSize)
{
	ZONE_AVC_EMS_Model *pRec = (ZONE_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;


	for (int i=0; i<bufSize/sizeof(ZONE_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		ZONE_AVC_EMS_Model* pnew = new ZONE_AVC_EMS_Model();
		memcpy(pnew, (pRec+i), sizeof(ZONE_AVC_EMS_Model));
		
		//添加AVC配置信息
		ScadaAVC_AVCCtrlZone AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;						//序号
		if(MatchKeyNo(pnew->keyno, ZONE_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		strcat(AVCRec.Name, pnew->chid);						//区域名称
		AVCRec.VovNum=pnew->vovnum;						//电压考核越限数
		AVCRec.QovNum=pnew->qovnum;						//无功考核越限数
		AVCRec.wloss=pnew->wloss;						//区域网损值
		AVCRec.NormCp=pnew->normcp;						//可控电容数
		AVCRec.NormXf=pnew->normxf;						//可控变压器数
		AVCRec.LockCp=pnew->lockcp;						//闭锁电容数
		AVCRec.LockXf=pnew->lockxf;						//闭锁变压器数
		AVCRec.VarIn=pnew->varin;						//已投入无功总容量
		AVCRec.VarOff=pnew->varoff;						//未投入无功总容量
		AVCRec.Cosfi=pnew->cosfi;						//关口功率因数
		AVCRec.score=pnew->score;						//区域状态得分

		AVCRec.LogTime = g_TimeFile;

		m_szTmp.Format("TABLE(ScadaAVC.AVCCtrlZone),WHERE(KeyID=%d)", pnew->keyno);
		ScadaAVC_AVCCtrlZone* pAvcRec = (ScadaAVC_AVCCtrlZone*)g_DB.QueryRecord("AVCCtrlZone",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCCtrlZone", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCCtrlZone", &AVCRec);
		}
		delete pnew;
	}
}
