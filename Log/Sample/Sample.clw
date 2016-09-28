; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSampleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Sample.h"

ClassCount=3
Class1=CSampleApp
Class2=CSampleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SAMPLE_DIALOG

[CLS:CSampleApp]
Type=0
HeaderFile=Sample.h
ImplementationFile=Sample.cpp
Filter=N

[CLS:CSampleDlg]
Type=0
HeaderFile=SampleDlg.h
ImplementationFile=SampleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CSampleDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=SampleDlg.h
ImplementationFile=SampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SAMPLE_DIALOG]
Type=1
Class=CSampleDlg
ControlCount=7
Control1=IDC_BTN_ADD,button,1342242816
Control2=IDC_EDIT_APP,edit,1350631552
Control3=IDC_EDIT_DATA,edit,1350631556
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,button,1342177287
Control6=IDC_LIST_LOG,SysListView32,1350631425
Control7=IDC_BTN_REFRESH,button,1342242816

