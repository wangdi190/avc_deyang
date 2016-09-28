// LogLibrary.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "LogLibrary.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CLogLibraryApp

BEGIN_MESSAGE_MAP(CLogLibraryApp, CWinApp)
	//{{AFX_MSG_MAP(CLogLibraryApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogLibraryApp construction

int nTableID;
DWORD bigTableID;

int GetTableID(char* pszDB, char* pszTable)
{
	DWORD idi;
	if(!LSI_GetTableID(pszDB,pszTable,idi)) 
		return -1;
	
	bigTableID = idi;
	int tbid=LOWORD(idi);
	return tbid;
}

//查询记录
void* QueryRecord(int nTableID, char* pszWhere, int &num)
{
	num=0;
	void* pReturn=NULL;
	if(pszWhere!=NULL)
	{
		int error;
		char* pRec=(char*)LSI_QueryRecord(pszWhere,num,error,TRUE);
		pReturn=(void*)(pRec+num*2*sizeof(char));
	}
	else
	{
		//		DWORD idi;
		MEMTABLE *mtb;
		//		if(!LSI_GetTableID(pszDB,pszTable,idi)) return 0;
		//		int addr=LOWORD(idi);
		mtb=(MEMTABLE *)LSI_GetTableAdd(nTableID);
		if(mtb!=NULL)
		{
			num=mtb->userec;
			pReturn=mtb->data;
		}
	}
	return pReturn;
}

CLogLibraryApp::CLogLibraryApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	if(!LSI_InitNTDbi())
	{
		AfxMessageBox("内存库平台未启动或初始化失败！");
	}

	//if (!LSI_CheckUser("tyh", "0000AAAA@"))
	if (!LSI_CheckUser("sa", ""))
	{
		AfxMessageBox("LSI_CheckUser error");
	}

	nTableID = GetTableID("common", "LogRecord");
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLogLibraryApp object

CLogLibraryApp theApp;


void EncodeString(LPCTSTR lpszText, LPTSTR *lpszReturn, LPCTSTR lpszKey)
{
	if(lpszText==0)
		return;

	int nTextLen=0; 
	char *cPos = NULL;
	char *pDest = NULL;
	
	if(!lpszReturn)//加密
	{
		nTextLen = ::_tcslen(lpszText);
		pDest = (LPTSTR)lpszText;
	}
	else//解密
	{
		cPos = (LPTSTR)lpszText;
		while(true)
		{
			if(*cPos == '=' && cPos[1]=='=' && cPos[2]=='\0')
				break;
			cPos++;
		}
		
		if(!cPos)
			return;
		
		nTextLen = cPos-lpszText;
		pDest = new char[nTextLen+3];
	}
	int nKeyLen = ::_tcslen(lpszKey);
	int k=0;
	for (int i=0; i<nTextLen; i++)
	{
		pDest[i] = lpszText[i]^lpszKey[k];
		k++;
		if(k>=nKeyLen)
			k=0;
	}
	
	if(!cPos)
		memcpy(pDest+nTextLen, _T("==\0"), 3*sizeof(TCHAR));
	else
	{
		memset(pDest+nTextLen, _T('\0'), sizeof(TCHAR));
		*lpszReturn = pDest;
	}
}

bool WINAPI WriteRecord(char *pApp, char *pData)
{
	if(strlen(pApp)>64 && strlen(pData)>256)
		return false;

	CTime now = CTime::GetCurrentTime();
	
	int recn=0;
	common_LogRecord *pRecord = (common_LogRecord*)QueryRecord(nTableID, NULL, recn);
	if(recn>0 && pRecord != NULL)
	{
		for (int i=0; i<recn; i++)
		{
			if((now-pRecord[i].time).GetDays()>180)
				LSI_DeleteRecord("common.LogRecord", i);
		}	
	}
		

	common_LogRecord log;
	
	log.time = now;
	strcpy(log.App, pApp);
	
	
	strcpy(log.Data, pData);
	EncodeString(log.Data, NULL, "wangdi");
	
	
	LSI_AppendRec("common.LogRecord", &log);
	
	return true;
}


typedef std::vector<common_LogRecord> VecRecord;
typedef std::vector<CString> VecApp;


bool WINAPI ReadRecord(VecRecord &vecRecord, VecApp &vecApp)
{
	vecRecord.clear();
	vecApp.clear();
	int recn;
	common_LogRecord record;
	common_LogRecord *pRecord = (common_LogRecord*)QueryRecord(nTableID, NULL, recn);
	if(recn<0 || pRecord == NULL) 
		return false;
	
	
	for (int i=0; i<recn; i++)
	{
		char *lpszDest=NULL;
		EncodeString(pRecord[i].Data, &lpszDest, "wangdi");

		memset(&record, 0, sizeof(record));
		record.time = pRecord[i].time;
		strcpy(record.App, pRecord[i].App);
		CString strTmp(record.App);

		bool bFound = false;
		for (int n=0; n<vecApp.size(); n++)
		{
			if(strcmp(vecApp.at(n), strTmp)==0 )
			{
				bFound = true;
				break;
			}
		}
		if(bFound == false)
			vecApp.push_back(strTmp);
		

		strcpy(record.Data, lpszDest);
		vecRecord.push_back(record);
	}
	return true;
}

/*bool WINAPI ReadRecord(VecRecord &vecRecord, CTime time)
{
	vecRecord.clear();
	int recn;
	common_LogRecord record;
	common_LogRecord *pRecord = (common_LogRecord*)QueryRecord(nTableID, NULL, recn);
	if(recn<0 || pRecord == NULL) 
		return false;
	
	for (int i=0; i<recn; i++)
	{
		char *lpszDest=NULL;
		EncodeString(pRecord[i].Data, &lpszDest, "wangdi");
		
		memset(&record, 0, sizeof(record));
		record.time = pRecord[i].time;

		if(strcmp(record.time.Format("%Y-%m-%d"), time.Format("%Y-%m-%d")) == 0)
		{
			strcpy(record.App, pRecord[i].App);
			strcpy(record.Data, lpszDest);
			vecRecord.push_back(record);
		}
	}
	return true;
}*/