//Avcpublic.h
#if !defined(AFX_AVCPUBLIC_H__1C9E58CB_CB2D_41ED_9A47_1EA466F1CC8C__INCLUDED_)
#define AFX_AVCPUBLIC_H__1C9E58CB_CB2D_41ED_9A47_1EA466F1CC8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const int RELATION_BUS_MAX=3;	//������ĸ��
const int RELATION_SWITCH_MAX=12;//�����ؿ���

const int RUNNING_PATH_MAX=12;	//������й켣����

struct SWITCHINFO//������Ϣ
{
	DWORD dwNo;   //���غ�
	BYTE byVal;//״ֵ̬
};

struct AVCVALUE//AVCֵ
{
	float fVol;   //��ѹ
	float fVar;   //�޹�
};

#define DEV_TRANS2 1
#define DEV_TRANS3 2
#define DEV_GEN 3

#define Limit_P 5.0f
#define Limit_Q 5.0f
#define Limit_COS 0.01f
#define Limit_U 1.0f

//===============��������=====================
#define TCP_HAND 1					//����
#define TCP_ALLDATA 2				//ȫ����
#define TCP_NEWDATA 3				//������
#define TCP_ALARM 4					//�澯
#define TCP_CLOSE 5					//ͨѶ�ر�
#define TCP_ALLALARM 6				//ȫ�澯
#define TCP_HISDATA 7				//��ʷ����
#define TCP_ENDTRANS 8				//���ݴ������
//===============��������=====================

typedef struct _Hisdata
{
	_Hisdata()
	{
		pos=0;
	}
	float P;
	float Q;
	float U;
	float cos;
	BYTE pos;			//����ͼλ��,����Ϊ0��
	float limit[4];		//AVC�������	˳��Ϊ��ѹ���й������ޣ����ޣ������������޹������ޣ�����
	CTime time;
}Hisdata, *LPHisdata;

//����ͼ����
struct NINEAREA
{
	NINEAREA(){memset(this,0,sizeof(NINEAREA));};
//	char szName[64];	//����
	DWORD dwSubNo;			//��վ��
	DWORD dwBus[RELATION_BUS_MAX];		//ĸ�ߺţ�����ĸ�߷ֱ��Ӧ�߼����ʽ1��2��3
	DWORD dwTrans;			//��ѹ����
	BYTE bThreeWind;	//�Ƿ��������ѹ��
	float fVolUp;		//��ѹ����
	float fVolDown;		//��ѹ����
	BYTE byQType;		//�޹����ͣ�0=���ʣ�1=�޹�����
	BOOL bRevPower;		//����ֵ�Ƿ�ȡ��
	float fQUp;			//�޹�����
	float fQDown;		//�޹�����
	COLORREF rcBack;	//����ɫ 
	COLORREF rcArea;	//����ɫ 
	COLORREF rcGrid;	//������ɫ
	COLORREF rcTip;		//��ʾ����ɫ
	SWITCHINFO logic[RELATION_BUS_MAX][RELATION_SWITCH_MAX];	//ĸ�߿����߼����ʽ
	BYTE bylogic[RELATION_BUS_MAX];	//ĸ�߿����߼����ʽ������
};

typedef struct BusConnectSwitch
{
	BusConnectSwitch(){memset(this,0,sizeof(BusConnectSwitch));};
	DWORD dwSubNo;			//��վ��
	DWORD dwBus[RELATION_BUS_MAX];		//ĸ�ߺţ�����ĸ�߷ֱ��Ӧ�߼����ʽ1��2��3
	SWITCHINFO logic[RELATION_BUS_MAX][RELATION_SWITCH_MAX];	//ĸ�߿����߼����ʽ
	BYTE bylogic[RELATION_BUS_MAX];	//ĸ�߿����߼����ʽ������
}BusConnectSwitch;

//�����¼����ȴ��¼�����
int WaitForEvent(CString szEventName,int iOverTime);
inline int WaitForEvent(CString szEventName,int iOverTime)
{
  int iResult=WAIT_FAILED;
  HANDLE hThreadEvents; 
  hThreadEvents = CreateEvent(NULL,TRUE,TRUE,szEventName); 
  if (hThreadEvents != NULL) 
  {
    ResetEvent(hThreadEvents);   
    iResult=WaitForSingleObject(hThreadEvents,iOverTime);
    CloseHandle(hThreadEvents);
  }
  return iResult; 
};


//���¼��������¼�����
int ReponseEvent(CString szEventName);
inline int ReponseEvent(CString szEventName)
{
  HANDLE hThreadEvents=OpenEvent(EVENT_MODIFY_STATE,TRUE,szEventName);
  if(hThreadEvents!=NULL)
  {
    SetEvent(hThreadEvents);
    CloseHandle(hThreadEvents);
  }
  else
    return 0;
  return 1;
};

#endif // !defined(AFX_AVCPUBLIC_H__1C9E58CB_CB2D_41ED_9A47_1EA466F1CC8C__INCLUDED_)
