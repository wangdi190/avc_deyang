// AVCPQVFun.h: interface for the AVCPQVFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AVCPQVFUN_H__0D197B86_8B67_42D5_A0DE_7149C6DEAE00__INCLUDED_)
#define AFX_AVCPQVFUN_H__0D197B86_8B67_42D5_A0DE_7149C6DEAE00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//设备类型定义
#define DEV_TRANS2 1			//双绕组设备
#define DEV_TRANS3 2			//三绕组设备
#define DEV_GEN 3				//电机设备

//绘图工具：变压器AVC参数设定
//编辑态显示的图形，byType=2,三绕组；byType=1,两绕组
void WINAPI OpenPropertyDlg(DWORD dwTransNo,BYTE byType);


//主程序调用AVC、PQV接口
//建立窗口(主程序启动时调用)
HWND WINAPI	CreateAVCPQVWnd(CWnd* pParent);
//显示窗口(右键设备右键菜单调用)
BOOL WINAPI	ShowAVCPQVWnd(DWORD devnu,BYTE devtype,BOOL bShow=TRUE);
//关闭窗口(主程序关闭时调用)
void WINAPI	CloseAVCPQVWnd();

#endif // !defined(AFX_AVCPQVFUN_H__0D197B86_8B67_42D5_A0DE_7149C6DEAE00__INCLUDED_)
