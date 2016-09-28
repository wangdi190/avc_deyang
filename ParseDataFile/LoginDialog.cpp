// LoginDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ParseDataFile.h"
#include "LoginDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog dialog


CLoginDialog::CLoginDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_checkcount = 0;
}


void CLoginDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	
}


BEGIN_MESSAGE_MAP(CLoginDialog, CDialog)
	//{{AFX_MSG_MAP(CLoginDialog)
	ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnBtnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog message handlers

void CLoginDialog::OnBtnOk() 
{
	// TODO: Add your control notification handler code here
	int type;
	char pass[64],urnm[64],tmp[MAX_PATH]={0};
	pass[0]=0;
	urnm[0]=0;
	GetDlgItemText(IDC_USERNAME,urnm,19);
	GetDlgItemText(IDC_PASSWORD,pass,19);
	bool blogin = V_CheckUser(urnm, pass,type);
	if (type != 0)
	{
		AfxMessageBox("�û�Ȩ��̫�ͣ����ù���Ա�û�����");
		return;
	}

	if(blogin == false)
	{
		MessageBox("�û��������!","����",MB_OK|MB_ICONSTOP);
		m_checkcount++;
		if(m_checkcount>=3) 
		{
			if(szTitle == "��¼")
				sprintf(tmp, "%s����3�ε�¼�����������ʧ��", urnm);
			else if (szTitle == "�˳�")
				sprintf(tmp, "%s����3���˳������������ʧ��", urnm);

			WriteRecord("PhraseDataFile.exe", tmp);
			CDialog::OnCancel();
		}
		return;
	}
	m_checkcount = 0;

	if(szTitle == "��¼")
		sprintf(tmp, "%s ��¼�����������ɹ�", urnm);
	else if (szTitle == "�˳�")
		sprintf(tmp, "%s �˳������������ɹ�", urnm);

	WriteRecord("PhraseDataFile.exe", tmp);
	
	CDialog::OnOK();
}

BOOL CLoginDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowText(szTitle);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLoginDialog::OnBtnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
