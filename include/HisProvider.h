// HisProvider.h : main header file for the HISPROVIDER DLL
/************************************************/
//��  �룺��ǿ
//ʱ  �䣺2007-06-13
//������������ʷ�����ṩ���������
/************************************************/


#if !defined(AFX_HISPROVIDER_H__93D53415_6572_4FA9_BE35_FCB9A182080F__INCLUDED_)
#define AFX_HISPROVIDER_H__93D53415_6572_4FA9_BE35_FCB9A182080F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif


//��ʷ�������Ͷ���
const int HIS_GEN=0;		//�����
const int HIS_LOAD=1;		//����
const int HIS_SHUNT=2;		//����
const int HIS_SREACT=3;		//�翹
const int HIS_TFM1=4;		//˫�����

const int HIS_TFM2=5;		//�������
const int HIS_BUS=6;		//ĸ��
const int HIS_LINE=7;		//������·
const int HIS_SWITCH=8;		//����
const int HIS_DCLINE=9;		//ֱ����·

const int HIS_GND=10;		//�ӵ�
const int HIS_SVC=11;		//��̬�޹�����
const int HIS_STATION=12;	//���վ
const int HIS_ZONE=13;		//����
const int HIS_PT=14;		//PT

const int HIS_CVT=15;		//CTV
const int HIS_SYSALARM=16;		//����
const int HIS_AVC=17;		//��ѹ��������
const int HIS_DYNMONITOR=18;		//PT
const int HIS_RELAY=19;		//CTV
const int HIS_TANK=20;		//���
const int HIS_BAY=21;		//��Ԫ

const int HIS_END=22;		//���һ����ʷ����ţ�����±�˱�˳�ӣ�����

//��ʷ���ݿ�ȫ����
static const char* chHisName[]={"HIS_Gen","HIS_Load","HIS_Shunt","HIS_Sreact","HIS_Tfm1",
"HIS_Tfm2","HIS_Bus","HIS_Line","HIS_Switch","HIS_DCLine",
"HIS_GND","HIS_SVC","HIS_STATION","HIS_ZONE","HIS_PT",
"HIS_CVT","HIS_SYSALARM","HIS_AVC","HIS_DYNMONITOR","HIS_RELAY", "HIS_TANK", "HIS_BAY"};

//��ʷ���ݿ����ݱ����
static const char* chHisData[]={"HIS_Gen2","HIS_Load2","HIS_Shunt2","HIS_Sreact2","HIS_Tfm12",
"HIS_Tfm22","HIS_Bus2","HIS_Line2","HIS_Switch2","HIS_DCLine2",
"HIS_GND2","HIS_SVC2","HIS_STATION2","HIS_ZONE2","HIS_PT2",
"HIS_CVT2","HIS_SYSALARM2","HIS_AVC2","HIS_DYNMONITOR2","HIS_RELAY2", "HIS_TANK2", "HIS_BAY2"};

//�����ݿ����
static const char* chMemName[]={"Gen","Load","Shunt","Sreact","Tfm1",
"Tfm2","Bus","Line","Switch","DCLine",
"GND","SVC","Station","Zone","PT",
"CVT","SysAlarm","AVC","DynMonitor","Relay", "Tank", "Bay"};

/////////////////////////////////////////////////////////////////////////////
// CHisProvider
// See HisProvider.cpp for the implementation of this class
//
//�������ṩ��,��ʼ�����ݿ�����
BOOL WINAPI IniProvider();

//�ر������ṩ��
void WINAPI	CloseProvider();
//***********************************************************************************//
//�ȵ�IniProvider,�ڵ��ú���ĺ���,������Ҫ�˿���CloseProvider�ر����ݿ�����,�ͷ��ڴ�//
//***********************************************************************************//

//������ʷ����
void WINAPI	SaveHisData();

//***********************************************************************************//
//������������ʷ���ݲ��ź����ӿ�,��˳�����,GetNextSection��tmCur,����GetFirstSection//
//��tmList�е�ֵ����ѡȡ                                                             //
//***********************************************************************************//
//ע����Ҫ���ŵ�����(pRecord:���ݼ�¼ָ�룬num:������type:����)
int WINAPI RegPlayData(DWORD* pRecord,int num,int type);

//��ȡ��ʷ���ݶ�����(tmStart:��ʼʱ�䣬tmEnd:������ʱ�䣬tmList:������ʱ���б�iMaxSection:tmList�ɷ��������)(��δʵ��)
int WINAPI GetSectionList(time_t tmStart,time_t tmEnd,time_t* pList,int iMaxSection);

//��ʼ��ȡ����
BOOL WINAPI	BeginGettingData();

//��ȡ��ʷ���ݶ��棬�������ڴ���ʷ��(tmCur:Ҫ���ŵ����ݶ�ʱ�䣬tmNext:��һ��Ҫ���ŵ�ʱ���)
BOOL WINAPI	GetNextSection(time_t tmCur,time_t &tmNext);

//��ȡ��ʷ���ݶ��棬�������ڴ���ʷ��(tmCur:Ҫ���ŵ����ݶ�ʱ�䣬tmNext:��һ��Ҫ���ŵ�ʱ���)
BOOL WINAPI	GetPreSection(time_t tmCur,time_t &tmNext);

//���ȫ��ע������
void WINAPI ClearAllRegData();
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISPROVIDER_H__93D53415_6572_4FA9_BE35_FCB9A182080F__INCLUDED_)
