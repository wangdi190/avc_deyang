// DB_AVCZoneChange.cpp: implementation of the DB_AVCZoneChange class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCZoneChange.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCZoneChange::DB_AVCZoneChange()
{

}

DB_AVCZoneChange::~DB_AVCZoneChange()
{

}
void DB_AVCZoneChange::RefreshModel(char* pData, int bufSize)
{
	
	EXCHG_AVC_EMS_Model *pRec = (EXCHG_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;


	for (int i=0; i<bufSize/sizeof(EXCHG_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		EXCHG_AVC_EMS_Model* pnew = new EXCHG_AVC_EMS_Model();
		memcpy(pnew, (pRec+i), sizeof(EXCHG_AVC_EMS_Model));
		
		//添加AVC配置信息
		ScadaAVC_AVCAreaChange AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;						//序号
		if(MatchKeyNo(pnew->keyno, EXCHG_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.objtype=pnew->objtyp;						//对象类型
		AVCRec.objID=pnew->objid;						//对象ID
		AVCRec.objcdID=pnew->objcdid;						//对象测点ID
		AVCRec.value=pnew->fval;						//对象值
		AVCRec.datdir=pnew->datdir;						//数据传输方向

		m_szTmp.Format("TABLE(ScadaAVC.AVCAreaChange),WHERE(KeyID=%d)", pnew->keyno);
		ScadaAVC_AVCAreaChange* pAvcRec = (ScadaAVC_AVCAreaChange*)g_DB.QueryRecord("AVCAreaChange",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCAreaChange", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCAreaChange", &AVCRec);
		}
		delete pnew;
	}
}
