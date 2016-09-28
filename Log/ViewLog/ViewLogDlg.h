// ViewLogDlg.h : header file
//

#if !defined(AFX_VIEWLOGDLG_H__1999966F_F9EF_420C_9285_41C9F1A4C583__INCLUDED_)
#define AFX_VIEWLOGDLG_H__1999966F_F9EF_420C_9285_41C9F1A4C583__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CViewLogDlg dialog

#pragma comment(lib, "..//LogLibrary//Debug//LogLibrary.lib")

#include <VECTOR>
using namespace std;


//#pragma pack(1)
//日志表
typedef struct common_LogRecord
{
	CTime  time;						//记录时间
	char  App[64];						//应用
	char  Data[256];					//日志
}common_LogRecord;
//#pragma pack()

typedef std::vector<common_LogRecord> VecRecord;
typedef std::vector<CString> VecApp;

bool WINAPI WriteRecord(char *pApp, char *pData);
bool WINAPI ReadRecord(VecRecord &vecRecord, VecApp &vecApp);
//bool WINAPI ReadRecord(VecRecord &vecRecord, CTime time);

class CViewLogDlg : public CDialog
{
// Construction
public:
	CViewLogDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CViewLogDlg)
	enum { IDD = IDD_VIEWLOG_DIALOG };
	CComboBox	m_Combo;
	CListCtrl	m_list;
	CTime	m_time;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewLogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CViewLogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnRefresh();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void Init();
	VecRecord m_VecRecord;
	VecApp m_VecApp;
	void ViewLog();
	CString m_combostring;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWLOGDLG_H__1999966F_F9EF_420C_9285_41C9F1A4C583__INCLUDED_)
