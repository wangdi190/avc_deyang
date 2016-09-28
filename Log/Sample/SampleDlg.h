// SampleDlg.h : header file
//

#if !defined(AFX_SAMPLEDLG_H__7351EF4C_77B6_41F6_985B_CE6D8E2D8482__INCLUDED_)
#define AFX_SAMPLEDLG_H__7351EF4C_77B6_41F6_985B_CE6D8E2D8482__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSampleDlg dialog


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

bool WINAPI WriteRecord(char *pApp, char *pData);
//bool WINAPI ReadRecord(VecRecord &vecRecord);

class CSampleDlg : public CDialog
{
// Construction
public:
	CSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSampleDlg)
	enum { IDD = IDD_SAMPLE_DIALOG };
	CListCtrl	m_loglist;
	CString	m_logData;
	CString	m_logApp;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnAdd();
	afx_msg void OnBtnRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	VecRecord m_VecRecord;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLEDLG_H__7351EF4C_77B6_41F6_985B_CE6D8E2D8482__INCLUDED_)
