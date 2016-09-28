#if !defined(AFX_DIALOG_LOG_H__77224515_CB02_4FF6_A8F4_CAC87048FA38__INCLUDED_)
#define AFX_DIALOG_LOG_H__77224515_CB02_4FF6_A8F4_CAC87048FA38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_Log.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Log dialog

class CDialog_Log : public CDialog
{
// Construction
public:
	CDialog_Log(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Log)
	enum { IDD = IDD_DIALOG_LOG };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Log)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Log)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CImageList m_ImageList;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_LOG_H__77224515_CB02_4FF6_A8F4_CAC87048FA38__INCLUDED_)
