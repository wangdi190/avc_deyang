#if !defined(AFX_LOGINDIALOG_H__918BF8E6_3484_49B2_A7C0_D8E77005B579__INCLUDED_)
#define AFX_LOGINDIALOG_H__918BF8E6_3484_49B2_A7C0_D8E77005B579__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog dialog

#pragma comment(lib, "LogLibrary.lib")
bool WINAPI WriteRecord(char *pApp, char *pData);

#pragma comment(lib, "CUserApi.lib")
bool WINAPI V_CheckUser(char *name, char *pw,int &type);

class CLoginDialog : public CDialog
{
// Construction
public:
	CLoginDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDialog)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnIdok();
	afx_msg void OnBtnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	int m_checkcount;
	CString szTitle;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDIALOG_H__918BF8E6_3484_49B2_A7C0_D8E77005B579__INCLUDED_)
