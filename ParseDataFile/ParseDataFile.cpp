// ParseDataFile.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ParseDataFile.h"
#include "ParseDataFileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParseDataFileApp

BEGIN_MESSAGE_MAP(CParseDataFileApp, CWinApp)
	//{{AFX_MSG_MAP(CParseDataFileApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParseDataFileApp construction

CParseDataFileApp::CParseDataFileApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CParseDataFileApp object

CParseDataFileApp theApp;
CRealDataBase g_DB;
Parse g_DataBase;
CTime g_TimeFile;
bool g_firstrun;
CCommonFunc g_ComFunc;

/////////////////////////////////////////////////////////////////////////////
// CParseDataFileApp initialization

BOOL CParseDataFileApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	if(!LSI_InitNTDbi())
	{
		AfxMessageBox("内存库平台未启动或初始化失败！");
		return FALSE;
	}

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CParseDataFileDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}



std::wstring UT2WC(const char* buf)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, buf, -1, NULL, 0);
    std::vector<wchar_t> unicode(len);
    MultiByteToWideChar(CP_UTF8, 0, buf, -1, &unicode[0], len);
	
    return std::wstring(&unicode[0]);
}

std::string WC2MB(const wchar_t* buf)
{
    int len = WideCharToMultiByte(CP_ACP, 0, buf, -1, NULL, 0, NULL, NULL);
    std::vector<char> utf8(len);
    WideCharToMultiByte(CP_ACP, 0, buf, -1, &utf8[0], len, NULL, NULL);
	
    return std::string(&utf8[0]);
}

std::string str;
const char* UT2MB(char* buf)
{
	if (buf == NULL)
		return NULL;
	
	std::wstring wstr = UT2WC(buf);
	if (wstr.c_str() == NULL)
		return NULL;
	
	str = WC2MB(wstr.c_str());
	if (str.c_str() == NULL)
		return NULL;
	else
		return str.data();
}

DWORD GetZoneNU(DWORD facid)
{
/*	m_szTmp.Format("TABLE(visualpw.Station),WHERE(NU=%d)", nu);
	visualpw_Station *pDBrec = (visualpw_Station*)g_DB.QueryRecord("Station",m_szTmp.GetBuffer(0),m_recn,"visualpw");
	if(pDBrec != NULL)
	{
		return pDBrec->Name;
	}*/

	DWORD zonenu=0;
	if(facid<=0)
		return 0;

	visualpw_Station* pfac=NULL;
	int datanum=0;
	CUIntArray posarray;
	CString szsql;
	szsql.Format("NU=%d", facid);
	SearchData("visualpw", "Station", szsql, "", (void**)&pfac, datanum, posarray);

	if(pfac!=NULL)
	{
		zonenu = pfac->zoneNU;
		delete []pfac;
	}

	return zonenu;
}


bool MatchKeyNo(int keyno, DWORD nModel)
{
	int nTable = nModel&0x0000ffff;
	if (nTable == ((keyno/1000000)&nTable))
		return true;
	else
		return false;
}

BYTE GetStationAVCSta(DWORD facid)
{
	BYTE bctrl=0;
	if(facid<=0)
		return bctrl;

	CString szsql;
	int m_recn=0;
	szsql.Format("TABLE(ScadaAVC.AVCStation),WHERE(ID=%d)", facid);
	ScadaAVC_AVCStation* pStation = (ScadaAVC_AVCStation*)g_DB.QueryRecord("AVCStation",szsql.GetBuffer(0),m_recn,"ScadaAVC");

	if(pStation==NULL)
		return 0;

	if(pStation->CtrlOut==0)
		bctrl=1;

	return bctrl;
}