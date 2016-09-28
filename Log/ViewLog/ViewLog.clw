; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CViewLogDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ViewLog.h"

ClassCount=4
Class1=CViewLogApp
Class2=CViewLogDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_VIEWLOG_DIALOG
Resource4=IDD_ABOUTBOX
Class4=CLoginDialog
Resource5=IDR_MENU1

[CLS:CViewLogApp]
Type=0
HeaderFile=ViewLog.h
ImplementationFile=ViewLog.cpp
Filter=N

[CLS:CViewLogDlg]
Type=0
HeaderFile=ViewLogDlg.h
ImplementationFile=ViewLogDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COMBO1

[CLS:CAboutDlg]
Type=0
HeaderFile=ViewLogDlg.h
ImplementationFile=ViewLogDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_VIEWLOG_DIALOG]
Type=1
Class=CViewLogDlg
ControlCount=4
Control1=IDC_LIST_LOG,SysListView32,1350631425
Control2=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242848
Control3=IDC_BTN_REFRESH,button,1342242816
Control4=IDC_COMBO1,combobox,1344340226

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=IDC_CHOOSEDAY
CommandCount=1

[DLG:IDD_DIALOG1]
Type=1
Class=CLoginDialog
ControlCount=6
Control1=IDC_USERNAME,edit,1350631552
Control2=IDC_PASSWORD,edit,1350631584
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BTN_IDOK,button,1342242816
Control6=IDC_BTN_CANCEL,button,1342242816

[CLS:CLoginDialog]
Type=0
HeaderFile=LoginDialog.h
ImplementationFile=LoginDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLoginDialog

