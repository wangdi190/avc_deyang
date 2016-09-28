//Avcpublic.h
#if !defined(AFX_AVCPUBLIC_H__1C9E58CB_CB2D_41ED_9A47_1EA466F1CC8C__INCLUDED_)
#define AFX_AVCPUBLIC_H__1C9E58CB_CB2D_41ED_9A47_1EA466F1CC8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const int RELATION_BUS_MAX=3;	//最多相关母线
const int RELATION_SWITCH_MAX=12;//最多相关开关

const int RUNNING_PATH_MAX=12;	//最大运行轨迹点数

struct SWITCHINFO//开关信息
{
	DWORD dwNo;   //开关号
	BYTE byVal;//状态值
};

struct AVCVALUE//AVC值
{
	float fVol;   //电压
	float fVar;   //无功
};

#define DEV_TRANS2 1
#define DEV_TRANS3 2
#define DEV_GEN 3

#define Limit_P 5.0f
#define Limit_Q 5.0f
#define Limit_COS 0.01f
#define Limit_U 1.0f

//===============传输类型=====================
#define TCP_HAND 1					//握手
#define TCP_ALLDATA 2				//全数据
#define TCP_NEWDATA 3				//新数据
#define TCP_ALARM 4					//告警
#define TCP_CLOSE 5					//通讯关闭
#define TCP_ALLALARM 6				//全告警
#define TCP_HISDATA 7				//历史数据
#define TCP_ENDTRANS 8				//数据传输结束
//===============传输类型=====================

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
	BYTE pos;			//九区图位置,该项为0；
	float limit[4];		//AVC监控区域	顺序为电压（有功）上限，下限，功率因数（无功）上限，下限
	CTime time;
}Hisdata, *LPHisdata;

//九区图属性
struct NINEAREA
{
	NINEAREA(){memset(this,0,sizeof(NINEAREA));};
//	char szName[64];	//名称
	DWORD dwSubNo;			//厂站号
	DWORD dwBus[RELATION_BUS_MAX];		//母线号，所存母线分别对应逻辑表达式1、2、3
	DWORD dwTrans;			//变压器号
	BYTE bThreeWind;	//是否三绕组变压器
	float fVolUp;		//电压上限
	float fVolDown;		//电压下限
	BYTE byQType;		//无功类型，0=力率，1=无功功率
	BOOL bRevPower;		//功率值是否取反
	float fQUp;			//无功上限
	float fQDown;		//无功下限
	COLORREF rcBack;	//背景色 
	COLORREF rcArea;	//区域色 
	COLORREF rcGrid;	//网格颜色
	COLORREF rcTip;		//提示框颜色
	SWITCHINFO logic[RELATION_BUS_MAX][RELATION_SWITCH_MAX];	//母线开关逻辑表达式
	BYTE bylogic[RELATION_BUS_MAX];	//母线开关逻辑表达式开关数
};

typedef struct BusConnectSwitch
{
	BusConnectSwitch(){memset(this,0,sizeof(BusConnectSwitch));};
	DWORD dwSubNo;			//厂站号
	DWORD dwBus[RELATION_BUS_MAX];		//母线号，所存母线分别对应逻辑表达式1、2、3
	SWITCHINFO logic[RELATION_BUS_MAX][RELATION_SWITCH_MAX];	//母线开关逻辑表达式
	BYTE bylogic[RELATION_BUS_MAX];	//母线开关逻辑表达式开关数
}BusConnectSwitch;

//产生事件并等待事件返回
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


//打开事件并设置事件返回
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
