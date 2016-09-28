// AVCPQVFun.h: interface for the AVCPQVFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AVCPQVFUN_H__0D197B86_8B67_42D5_A0DE_7149C6DEAE00__INCLUDED_)
#define AFX_AVCPQVFUN_H__0D197B86_8B67_42D5_A0DE_7149C6DEAE00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//�豸���Ͷ���
#define DEV_TRANS2 1			//˫�����豸
#define DEV_TRANS3 2			//�������豸
#define DEV_GEN 3				//����豸

//��ͼ���ߣ���ѹ��AVC�����趨
//�༭̬��ʾ��ͼ�Σ�byType=2,�����飻byType=1,������
void WINAPI OpenPropertyDlg(DWORD dwTransNo,BYTE byType);


//���������AVC��PQV�ӿ�
//��������(����������ʱ����)
HWND WINAPI	CreateAVCPQVWnd(CWnd* pParent);
//��ʾ����(�Ҽ��豸�Ҽ��˵�����)
BOOL WINAPI	ShowAVCPQVWnd(DWORD devnu,BYTE devtype,BOOL bShow=TRUE);
//�رմ���(������ر�ʱ����)
void WINAPI	CloseAVCPQVWnd();

#endif // !defined(AFX_AVCPQVFUN_H__0D197B86_8B67_42D5_A0DE_7149C6DEAE00__INCLUDED_)
