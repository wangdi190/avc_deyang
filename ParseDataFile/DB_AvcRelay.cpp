// DB_AvcRelay.cpp: implementation of the DB_AvcRelay class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AvcRelay.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AvcRelay::DB_AvcRelay()
{

}

DB_AvcRelay::~DB_AvcRelay()
{

}

void DB_AvcRelay::RefreshModel(char *pData, int bufSize)
{
	RELAY_AVC_EMS_Model *pRec = (RELAY_AVC_EMS_Model*)pData;
	refavc_lock_table DBrec, *pDBrec;
	CString m_szTmp;
	int m_recn=0;

	for (int i=0; i<bufSize/sizeof(RELAY_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		RELAY_AVC_EMS_Model* pnew = new RELAY_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(RELAY_AVC_EMS_Model));

		ZeroMemory(&DBrec, sizeof(DBrec));
		
	//	m_szTmp.Format("TABLE(refavc.lock_table),WHERE(NU=%d)", pRec[i].rlyid);
/*		pDBrec = (refavc_lock_table*)g_DB.QueryRecord("lock_table",m_szTmp.GetBuffer(0),m_recn,"refavc");
		if(pDBrec != NULL)
		{
			memcpy(&DBrec, pDBrec, sizeof(DBrec));
			DBrec.CtrlType=pnew->pltyp;
			if(pnew->offavr!=0)
				DBrec.status|=STATION_LOCKED;
			else
				DBrec.status&=!STATION_LOCKED;

			DBrec.status|=STUS_DEVOPFED;
			g_DB.UpdateRecord("lock_table", m_szTmp.GetBuffer(0), &DBrec, "refavc");
		}*/

		//���AVC������Ϣ
		ScadaAVC_AVCRelayInfo AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.StationID=pnew->fac_id;					//��վID

		if(MatchKeyNo(pnew->fac_id, FAC_INFO_MODEL) == false)
		{
			delete pnew;
			break;
		}


		AVCRec.RelayID=pnew->rlyid;						//����ID
		AVCRec.state=pnew->stat;						//����״̬
		AVCRec.qlock=pnew->qlock;						//�������鷽ʽ
		AVCRec.DevId=pnew->devid1;						//�����豸ID
		AVCRec.OnTm=(CTime)pnew->ontm-CTimeSpan(0, 8, 0, 0);							//����ʱ��
		AVCRec.OffTm=(CTime)pnew->offtm-CTimeSpan(0, 8, 0, 0);						//����ʱ��

		m_szTmp.Format("TABLE(ScadaAVC.AVCRelayInfo),WHERE(RelayID=%d)", pnew->rlyid);
		ScadaAVC_AVCRelayInfo* pAvcRec = (ScadaAVC_AVCRelayInfo*)g_DB.QueryRecord("AVCRelayInfo",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCRelayInfo", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCRelayInfo", &AVCRec);
		}

		delete pnew;
	}
}
