// Dialog_Log.cpp : implementation file
//

#include "stdafx.h"
#include "ParseDataFile.h"
#include "Dialog_Log.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Log dialog


CDialog_Log::CDialog_Log(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Log::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Log)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog_Log::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Log)
	DDX_Control(pDX, IDC_LIST_LOG, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Log, CDialog)
	//{{AFX_MSG_MAP(CDialog_Log)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Log message handlers

BOOL CDialog_Log::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	RECT rect;
	GetClientRect(&rect);
	
	m_list.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_FLATSB|LVS_EX_TWOCLICKACTIVATE);
	m_list.InsertColumn(0, "刷新时间", LVCFMT_LEFT, rect.right/5);
	m_list.InsertColumn(1, "刷新文件", LVCFMT_LEFT, rect.right/5*3);
	m_list.InsertColumn(2, "文件大小", LVCFMT_LEFT, rect.right/5);
	
	m_ImageList.Create(16, 16, ILC_COLOR32|ILC_MASK, 1, 4);
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_R));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_W));
	m_list.SetImageList(&m_ImageList, LVSIL_SMALL);

	/*ListLog::iterator i;
	CString szTmp;

	for (i=g_ComFunc.m_Listlog.begin(); i!=g_ComFunc.m_Listlog.end(); ++i)
	{
		int nRow = m_list.InsertItem(0, i->time.Format("%m-%d %H:%M:%S"), false);//插入行
		m_list.SetItemText(nRow, 1, i->file);//
		szTmp.Format("%d", i->size);
		m_list.SetItemText(nRow, 2, szTmp);
		
	}*/

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
