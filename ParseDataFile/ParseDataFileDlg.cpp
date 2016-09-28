// ParseDataFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ParseDataFile.h"
#include "ParseDataFileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_SHOWTASK WM_USER+100
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
extern bool g_firstrun;

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
// CParseDataFileDlg dialog

CParseDataFileDlg::CParseDataFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CParseDataFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CParseDataFileDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CParseDataFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParseDataFileDlg)
	DDX_Control(pDX, IDC_LIST_INFO, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CParseDataFileDlg, CDialog)
	//{{AFX_MSG_MAP(CParseDataFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_LOG, OnBtnLog)
	ON_MESSAGE(WM_SHOWTASK,OnShowTask)
	ON_COMMAND(ID_DELETE_DAT, OnDeleteDat)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParseDataFileDlg message handlers

#include "LoginDialog.h"

BOOL CParseDataFileDlg::OnInitDialog()
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

	InitParam();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

DWORD WINAPI _RefreshDataThread(LPVOID lp);

static LONG WINAPI TopLevelFilter(struct _EXCEPTION_POINTERS* pExceptionInfo)
{
	pExceptionInfo->ContextRecord;
	//AfxMessageBox("1");
	return 1;
}

void CParseDataFileDlg::InitParam()
{
	SetUnhandledExceptionFilter(TopLevelFilter);  //将程序没有拦截到的异常,发送到系统的异常拦截掉,直接使程序退出
	
	//初始化界面
	RECT rect;
	GetClientRect(&rect);
	
	m_list.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_FLATSB|LVS_EX_TWOCLICKACTIVATE);
	m_list.InsertColumn(0, "时间", LVCFMT_LEFT, rect.right/4);
	m_list.InsertColumn(1, "信息", LVCFMT_LEFT, rect.right/4*3);
	
	m_ImageList.Create(16, 16, ILC_COLOR32|ILC_MASK, 1, 4);
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_R));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_W));
	m_list.SetImageList(&m_ImageList, LVSIL_SMALL);

	ZeroMemory(findFilter, MAX_PATH);
	GetPrivateProfileString("LOG", "Filter", "", findFilter, MAX_PATH, ".//ParseDataFile.ini");

	g_DataBase.InitParamer();//初始化一些东西
	g_firstrun=true;

	HANDLE hThread = CreateThread(NULL, 0, _RefreshDataThread, this, 0, NULL);
	CloseHandle(hThread);
}

void CParseDataFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CParseDataFileDlg::OnPaint() 
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
HCURSOR CParseDataFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CParseDataFileDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN&&pMsg->wParam==VK_RETURN)
		return TRUE;
	if(pMsg->message==WM_KEYDOWN&&pMsg->wParam==VK_ESCAPE)
		return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}

LRESULT CParseDataFileDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (message == WM_SYSCOMMAND)
	{
		switch (wParam)
		{
		case SC_MINIMIZE:
			{
				ShowWindow(SW_HIDE);
				m_nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
				m_nid.hWnd = this->m_hWnd;
				m_nid.uID = IDR_MAINFRAME;
				m_nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP ;
				m_nid.uCallbackMessage = WM_SHOWTASK; // 自定义的消息名称
				m_nid.hIcon = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
				strcpy(m_nid.szTip, "SCADA"); // 信息提示条为"服务器程序"
				Shell_NotifyIcon(NIM_ADD, &m_nid); // 在托盘区添加图标
			}
			return 0;
		}
	}
	return CDialog::WindowProc(message, wParam, lParam);
}

void CParseDataFileDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	/*if (MessageBox("退出程序", "温馨提示", MB_ICONEXCLAMATION | MB_OKCANCEL) != IDOK)
	{
		return;
	}*/

	CLoginDialog login;
	login.szTitle = "退出";
	if(login.DoModal() != IDOK)
	{
		return;
	}

	CDialog::OnClose();
}

void CParseDataFileDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	Shell_NotifyIcon(NIM_DELETE, &m_nid);
	// TODO: Add your message handler code here
	
}

void CParseDataFileDlg::AddTip(CString szTip, bool bWarn)
{
	if(m_list.GetItemCount() > 200)
		m_list.DeleteAllItems();
	
	CTime time = CTime::GetCurrentTime();
	int nRow = m_list.InsertItem(0, time.Format("%m-%d %H:%M:%S"), bWarn);//插入行
	m_list.SetItemText(nRow, 1, szTip);//设置数据
	
}

LRESULT CParseDataFileDlg::OnShowTask(WPARAM wParam, LPARAM lParam)
{
	if(wParam != IDR_MAINFRAME)
		return 1;
	
	switch(lParam)
	{
	case WM_LBUTTONDBLCLK: // 双击左键的处理
		{
			this->ShowWindow(SW_SHOWNORMAL); // 显示主窗口
			Shell_NotifyIcon(NIM_DELETE, &m_nid); // 在托盘区删除图标
		}
		break;
	}
	return 0;
}



DWORD WINAPI _RefreshDataThread(LPVOID lp)
{
	CParseDataFileDlg *pDlg = (CParseDataFileDlg*)lp;
	char fname[MAX_PATH];
	char path[MAX_PATH];
	char name[MAX_PATH];
	char tmp[MAX_PATH];
	CString strTmp;
	
	CTime time;
	CTime time24h(2000,1,1);
	int nYear,nMonth,nDay,nHour,nMinute,nSecond, nn;
	g_firstrun=true;
	struct _stat info;

	CTime timenow;

	while (1)
	{
		timenow = CTime::GetCurrentTime();
		memset(fname, 0, MAX_PATH);
		memset(path, 0, MAX_PATH);
		memset(name, 0, MAX_PATH);
		memset(tmp, 0, MAX_PATH);


		if(findFile(pDlg->findFilter, fname) == TRUE)
		{
			::splitFName(fname, path, name);
			strcat(path, "log");
			
			if(!findFile(path, NULL))
				_mkdir(path);

			strcat(path, "\\");
			strcat(path, name);
			
			if(MoveFileEx(fname, path, MOVEFILE_REPLACE_EXISTING) == TRUE)
			{
				sscanf(name, "Data_%d_%4d%2d%2d%2d%2d%2d.dat", &nn, &nYear, &nMonth, &nDay, &nHour, &nMinute, &nSecond );
				g_TimeFile = CTime(nYear, nMonth, nDay, nHour, nMinute, nSecond);

				strTmp.Format("开始刷新文件%s", name);
				pDlg->AddTip(strTmp);
				g_DataBase.StartPrase(path);
				_stat(path, &info);

				strTmp.Format("最近刷新的文件:\n%s", name);
				pDlg->SetDlgItemText(IDC_STATIC_INFO, strTmp);

				sprintf(tmp, "解析文件 %s 成功", name);
				WriteRecord("PhraseDataFile.exe", tmp);
			}
		}
		Sleep(1000);

		time = CTime::GetCurrentTime();
		if((time-time24h).GetTotalHours()>=1)
		{
			system("python DeleteLogFile.py");
			time24h = time;
		}

	}
	return 0;
}

#include "Dialog_Log.h"
void CParseDataFileDlg::OnBtnLog() 
{
	// TODO: Add your control notification handler code here
	CDialog_Log log;
	log.DoModal();
}

void CParseDataFileDlg::OnDeleteDat() 
{
	// TODO: Add your command handler code here
	system("python DeleteFile.py");
}
