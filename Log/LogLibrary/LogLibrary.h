// LogLibrary.h : main header file for the LOGLIBRARY DLL
//

#if !defined(AFX_LOGLIBRARY_H__A6E9F742_763F_4A30_8660_C55DDBE37709__INCLUDED_)
#define AFX_LOGLIBRARY_H__A6E9F742_763F_4A30_8660_C55DDBE37709__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLogLibraryApp
// See LogLibrary.cpp for the implementation of this class
//


#include "visualdb.h"
#include "dbapi.h"
#include "USERAPI.H"
#pragma comment(lib, "dbapi.lib")

#include <STRING>
#include <VECTOR>
using namespace std;

class CLogLibraryApp : public CWinApp
{
public:
	CLogLibraryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogLibraryApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CLogLibraryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGLIBRARY_H__A6E9F742_763F_4A30_8660_C55DDBE37709__INCLUDED_)
