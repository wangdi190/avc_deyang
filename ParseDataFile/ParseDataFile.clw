; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLoginDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ParseDataFile.h"

ClassCount=5
Class1=CParseDataFileApp
Class2=CParseDataFileDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_DIALOG_LOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG_LOGIN
Class4=CDialog_Log
Resource4=IDD_PARSEDATAFILE_DIALOG
Resource5=IDD_ABOUTBOX
Class5=CLoginDialog
Resource6=IDR_MENU1

[CLS:CParseDataFileApp]
Type=0
HeaderFile=ParseDataFile.h
ImplementationFile=ParseDataFile.cpp
Filter=N

[CLS:CParseDataFileDlg]
Type=0
HeaderFile=ParseDataFileDlg.h
ImplementationFile=ParseDataFileDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CParseDataFileDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ParseDataFileDlg.h
ImplementationFile=ParseDataFileDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PARSEDATAFILE_DIALOG]
Type=1
Class=CParseDataFileDlg
ControlCount=3
Control1=IDC_LIST_INFO,SysListView32,1350631425
Control2=IDC_STATIC_INFO,static,1342308865
Control3=IDC_BTN_LOG,button,1342242816

[DLG:IDD_DIALOG_LOG]
Type=1
Class=CDialog_Log
ControlCount=1
Control1=IDC_LIST_LOG,SysListView32,1350631425

[CLS:CDialog_Log]
Type=0
HeaderFile=Dialog_Log.h
ImplementationFile=Dialog_Log.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_DELETE_DAT
VirtualFilter=dWC

[MNU:IDR_MENU1]
Type=1
Class=CParseDataFileDlg
Command1=ID_DELETE_DAT
CommandCount=1

[DLG:IDD_DIALOG_LOGIN]
Type=1
Class=CLoginDialog
ControlCount=6
Control1=IDC_USERNAME,edit,1350631552
Control2=IDC_PASSWORD,edit,1350631584
Control3=IDC_BTN_OK,button,1342242816
Control4=IDC_BTN_CANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:CLoginDialog]
Type=0
HeaderFile=LoginDialog.h
ImplementationFile=LoginDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CLoginDialog
VirtualFilter=dWC

