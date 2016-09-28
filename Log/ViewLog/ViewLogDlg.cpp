// ViewLogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ViewLog.h"
#include "ViewLogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewLogDlg dialog

CViewLogDlg::CViewLogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CViewLogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CViewLogDlg)
	m_time = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CViewLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewLogDlg)
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Control(pDX, IDC_LIST_LOG, m_list);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_time);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CViewLogDlg, CDialog)
	//{{AFX_MSG_MAP(CViewLogDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, OnDatetimechangeDatetimepicker1)
	ON_BN_CLICKED(IDC_BTN_REFRESH, OnBtnRefresh)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewLogDlg message handlers
#include "LoginDialog.h"
BOOL CViewLogDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CLoginDialog login;
	login.szTitle = "登录";
	if(login.DoModal() != IDOK)
	{
		CDialog::OnOK();
		return TRUE;
	}


	Init();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CViewLogDlg::Init()
{
	RECT rect;
	GetClientRect(&rect);
	
	m_list.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_FLATSB|LVS_EX_TWOCLICKACTIVATE);
	m_list.InsertColumn(0, "时间", LVCFMT_LEFT, rect.right/5);
	m_list.InsertColumn(1, "所属程序", LVCFMT_LEFT, rect.right/5);
	m_list.InsertColumn(2, "日志", LVCFMT_LEFT, rect.right/5*3);

	m_time = CTime::GetCurrentTime();
	UpdateData(FALSE);

	ReadRecord(m_VecRecord, m_VecApp);
	for (int i=0; i<m_VecApp.size(); i++)
	{
		m_Combo.InsertString(0, m_VecApp.at(i));
	}
	m_Combo.InsertString(0, "全部");
	m_Combo.SetCurSel(0);
	ViewLog();
}

void CViewLogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CViewLogDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CViewLogDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CViewLogDlg::OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	ViewLog();
	
	*pResult = 0;
}

void CViewLogDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	ViewLog();
	//AfxMessageBox("1");
}

void CViewLogDlg::ViewLog()
{
	UpdateData(TRUE);
	
	
	int nSel = m_Combo.GetCurSel();
	m_Combo.GetLBText(nSel, m_combostring);


	m_list.DeleteAllItems();

	
	for (int i=0; i<m_VecRecord.size(); i++)
	{
		TRACE("%s  %s  %s\n", m_VecRecord.at(i).time.Format("%Y-%m-%d %H:%M:%S"),
			m_VecRecord.at(i).App, m_VecRecord.at(i).Data);

		if(strcmp(m_VecRecord.at(i).time.Format("%Y-%m-%d"), m_time.Format("%Y-%m-%d")) == 0
			&& (strcmp(m_VecRecord.at(i).App, m_combostring)==0 || m_combostring=="全部"))
		{
			int nRow = m_list.InsertItem(0, m_VecRecord.at(i).time.Format("%Y-%m-%d %H:%M:%S"));
			m_list.SetItemText(nRow, 1, m_VecRecord.at(i).App);//
			m_list.SetItemText(nRow, 2, m_VecRecord.at(i).Data);//
		}
	}
}

void CViewLogDlg::OnBtnRefresh() 
{
	
	m_Combo.ResetContent();
	ReadRecord(m_VecRecord, m_VecApp);
	for (int i=0; i<m_VecApp.size(); i++)
	{
		m_Combo.InsertString(0, m_VecApp.at(i));
	}
	m_Combo.InsertString(0, "全部");

	bool bFound = false;
	CString szTmp;
	for (i=0; i<m_Combo.GetCount(); i++)
	{
		m_Combo.GetLBText(i, szTmp);
		if (szTmp == m_combostring)
		{
			bFound = true;
			m_Combo.SetCurSel(i);
			break;
		}
	}

	if(bFound == false)
		m_Combo.SetCurSel(0);
	ViewLog();
}





void CViewLogDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	CLoginDialog login;
	login.szTitle = "退出";
	if(login.DoModal() != IDOK)
	{
		return;
	}
	CDialog::OnClose();
}
