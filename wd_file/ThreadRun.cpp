#include "ThreadRun.h"
#include <qdatetime.h>

CThreadRun::CThreadRun(QWidget *pMainform)
{
    m_pMain = pMainform;
}

void CThreadRun::run()
{
    printf("start the Thread.\n");
    m_Data.Parse_ProfileXml("/users/ems/wd_file/profile.xml");
    struct timeval timenow;
    TimeData_Struct *pTD;
    Data_Struct *pD;
    DataInfo_Struct dInfo;
    char *pData;
    int nBufSize, nTotalBufSize;
    char pDataFile[64];
    char pShellCmd[128];
    time_t ltime;
    struct tm *now;
    QString strTmp;
    bool bSendTag = true;
    bool bStartProgram = true;
    while(1)
    {
	if(access("/users/ems/wd_file/wd.Model", F_OK) == 0)
	{
	    AddTip("wd.Model exists,Restart Parse_ProfileXml...");
	    m_Data.Parse_ProfileXml("/users/ems/wd_file/profile.xml");
	    remove("/users/ems/wd_file/wd.Model");
	    bSendTag = true;
	    bStartProgram = true;
	}
	
    	if(bStartProgram == true)
    	{
	    AddTip("Start Program,Please Hold on...");
	    	for(int n=0; n<m_Data.m_VecData.size(); n++)
		{
			pD = &m_Data.m_VecData.at(n);
			if(pD->SendTag == 1)
			{
				nBufSize = 0;
				pData = NULL;
				pData = m_Data.GetDataByFieldName(pD->nAppNo, pD->nTableNo, pD->field_name, nBufSize);
				if(pData != NULL && nBufSize > 0)
				{
					pD->SendTag = 0;
				}
				else
				{
					bSendTag = false;
					strTmp.sprintf("Init:Get AppNo=%d,TableNo=%d failed.(%d)", pD->nAppNo, pD->nTableNo, nBufSize);
					AddTip(strTmp);
				}
				
				if (pData != NULL)
				{
				    free(pData);
				    pData = NULL;
				}
				
			}
		}
		//printf("%d\n", bSendTag);
		if(bSendTag == true)
		{
			bStartProgram = false;
			sleep(30);
			//break;
		}
		else
		{
			bSendTag = true;
			sleep(5);
			continue;
		}
	}
	//printf("okokokokokokokook  %d\n", m_Data.m_VecTimeData.size());
	gettimeofday(&timenow,0); 
	for(int i=0; i<m_Data.m_VecTimeData.size(); i++)
	{
		pTD = &m_Data.m_VecTimeData.at(i);
		//printf("IntervalTime %d\n", pTD->nIntervalTime);
		if(timenow.tv_sec - pTD->timevalue.tv_sec > pTD->nIntervalTime)
		{
			if(pTD->bStartProgram == true)
			{
				sleep(5);
				pTD->bStartProgram = false;
			}
		
			pTD->timevalue = timenow;
			memset(pDataFile, 0, 64);
			time(&ltime);
			now = localtime( &ltime );
			sprintf(pDataFile,  "Data_%d_%d%02d%02d%02d%02d%02d.dat", pTD->nIntervalTime, 
						1900+now->tm_year, now->tm_mon+1, now->tm_mday,
						now->tm_hour, now->tm_min, now->tm_sec);
		
			strTmp.sprintf("Get %8ds Data run.(%s)", pTD->nIntervalTime, pDataFile);
			AddTip(strTmp);
		
			nTotalBufSize = 0;
			std::ofstream fout(pDataFile, std::ios::binary);
			for(int n=0; n<pTD->vecdata.size(); n++)
			{
				pD = &pTD->vecdata.at(n);
				nBufSize = 0;
				pData = NULL;
				pData = m_Data.GetDataByFieldName(pD->nAppNo, pD->nTableNo, pD->field_name, nBufSize);
				nTotalBufSize += nBufSize;
				if(pData != NULL && nBufSize > 0)
				{
					memset(&dInfo, 0, sizeof(DataInfo_Struct));
					dInfo.top = 0x16;
					dInfo.bottom = 0x16;
					dInfo.nAppNo = pD->nAppNo;
					dInfo.nTableNo = pD->nTableNo;
					dInfo.nBufSize = nBufSize;
					dInfo.nTypeID = pD->nTypeID;
					strcpy(dInfo.pName, pD->pName);
							
					fout.write((char*)&dInfo, sizeof(DataInfo_Struct));
					fout.write(pData, nBufSize);
				}
				else
				{
					strTmp.sprintf("Get AppNo=%d,TableNo=%d failed.(%d)", pD->nAppNo, pD->nTableNo, nBufSize);
					AddTip(strTmp);
				}
						
				if (pData != NULL)
				{
				    free(pData);
				    pData = NULL;
				}
			}
					
			fout.close();
			memset(pShellCmd, 0, 128);
			sprintf(pShellCmd, "bash /users/ems/wd_file/putfile %s %s", pDataFile, pDataFile);
			//printf("%s nTotalBufSize %d\n", pDataFile, nTotalBufSize);
			if(nTotalBufSize>0)
				system(pShellCmd);
				
			remove(pDataFile);
		}
	}
	sleep(1);
    }
}

void CThreadRun::AddTip( QString strTip)
{
    QCustomEvent *event = new QCustomEvent(12345);
    //QString str = "wangdi";
     event->setData(new QString(strTip));
     QApplication::postEvent(m_pMain, event);
}
