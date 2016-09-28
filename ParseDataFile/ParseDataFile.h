// ParseDataFile.h : main header file for the PARSEDATAFILE application
//

#if !defined(AFX_PARSEDATAFILE_H__9233E90C_3A07_47A8_AE52_20DDE805BC75__INCLUDED_)
#define AFX_PARSEDATAFILE_H__9233E90C_3A07_47A8_AE52_20DDE805BC75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CParseDataFileApp:
// See ParseDataFile.cpp for the implementation of this class
//

#include "RealDataBase.h"
#include "Parse.h"
#include "CommonFunc.h"

BYTE GetStationAVCSta(DWORD facid);				//取厂站的AVC控制状态

class CParseDataFileApp : public CWinApp
{
public:
	CParseDataFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParseDataFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CParseDataFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CRealDataBase g_DB;
extern Parse g_DataBase;
extern CTime g_TimeFile;
extern CCommonFunc g_ComFunc;
DWORD GetZoneNU(DWORD facid);


#include <string>
using namespace std;
const char* UT2MB(char* buf);
bool MatchKeyNo(int keyno, DWORD nModel);
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARSEDATAFILE_H__9233E90C_3A07_47A8_AE52_20DDE805BC75__INCLUDED_)
