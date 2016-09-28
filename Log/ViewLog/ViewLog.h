// ViewLog.h : main header file for the VIEWLOG application
//

#if !defined(AFX_VIEWLOG_H__31758BB7_EE64_4E11_85AF_CD0D0B21497F__INCLUDED_)
#define AFX_VIEWLOG_H__31758BB7_EE64_4E11_85AF_CD0D0B21497F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CViewLogApp:
// See ViewLog.cpp for the implementation of this class
//

class CViewLogApp : public CWinApp
{
public:
	CViewLogApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewLogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CViewLogApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWLOG_H__31758BB7_EE64_4E11_85AF_CD0D0B21497F__INCLUDED_)
