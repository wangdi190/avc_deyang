// ParseDataFileDlg.h : header file
//

#if !defined(AFX_PARSEDATAFILEDLG_H__B562D157_78BB_4397_9ACA_1DE3A3112C6D__INCLUDED_)
#define AFX_PARSEDATAFILEDLG_H__B562D157_78BB_4397_9ACA_1DE3A3112C6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



/////////////////////////////////////////////////////////////////////////////
// CParseDataFileDlg dialog

//#include "Parse.h"

class CParseDataFileDlg : public CDialog
{
// Construction
public:
	CParseDataFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CParseDataFileDlg)
	enum { IDD = IDD_PARSEDATAFILE_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParseDataFileDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CParseDataFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg void OnBtnLog();
	afx_msg void OnDeleteDat();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	Parse m_Parse;
	char findFilter[MAX_PATH];
	CImageList m_ImageList;
	NOTIFYICONDATA m_nid;					//用于托盘图标设置
	LRESULT OnShowTask(WPARAM wParam, LPARAM lParam);
	void InitParam();
	void AddTip(CString szTip, bool bWarn=false);//增加提示信息到ListCtrl中取
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARSEDATAFILEDLG_H__B562D157_78BB_4397_9ACA_1DE3A3112C6D__INCLUDED_)
