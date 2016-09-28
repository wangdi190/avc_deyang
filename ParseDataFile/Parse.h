// Parse.h: interface for the Parse class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSE_H__FD3EB868_408C_4608_9FD9_C3DCEBAB06BB__INCLUDED_)
#define AFX_PARSE_H__FD3EB868_408C_4608_9FD9_C3DCEBAB06BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <fstream>

#include "DB_pwSwitch.h"
#include "DB_pwBus.h"
#include "DB_pwGen.h"
#include "DB_pwLine.h"
#include "DB_pwLoad.h"
#include "DB_pwTfm.h"
#include "DB_pwTfmTap.h"
#include "DB_pwStation.h"
#include "DB_pwShuntSreact.h"
#include "DB_pwZone.h"
#include "DB_CommonVec.h"

#include "DB_AvcStation.h"
#include "DB_AvcBus.h"
#include "DB_AvcShunt.h"
#include "DB_AvcTrans.h"
#include "DB_AvcRunParam.h"
#include "DB_AvcRunTimePart.h"
#include "DB_AVCCtrlParam.h"
#include "DB_AvcRelay.h"
#include "DB_AVCWarnType.h"
#include "DB_AVCWarnInfo.h"

#include "DB_AvcRunParam.h"
#include "DB_AVCVolEvent.h"
#include "DB_AVCCtrlEvent.h"
#include "DB_AVCShuntEvent.h"
#include "DB_AVCTranEvent.h"
#include "DB_AVCCtrlPloy.h"
#include "DB_AVCCtrlZone.h"
#include "DB_AVCStatInfo.h"
#include "DB_AVCZoneChange.h"

#include "DB_PASIsland.h"
#include "DB_PASRuninfo.h"
#include "DB_PASParam.h"
#include "DB_PASMeasure.h"

#pragma pack(4)
struct DataInfo_Struct
{
	char top;
	int nTypeID;
	int nAppNo;
	int nTableNo;
	int nBufSize;
	char pName[256];
	char bottom;
};
#pragma pack()


class Parse  
{
public:
	Parse();
	virtual ~Parse();

	DB_pwSwitch m_pwSwitch;					//���ر�
	DB_pwBus m_pwBus;						//ĸ�߱�
	DB_pwGen m_pwGen;						//�������
	DB_pwLine m_pwLine;						//��·��
	DB_pwLoad m_pwLoad;						//���ɱ�
	DB_pwTfm m_pwTfm;						//��ѹ����
	DB_pwTfmTap m_pwTfmTap;					//��ѹ����λ���ͱ�
	DB_pwStation m_pwStation;				//��վ��
	DB_pwShuntSreact m_pwShuntSreact;		//���ݵ翹��
	DB_pwZone m_pwZone;						//�����
	DB_CommonVec m_CommonVec;				//��ѹ���ͱ�

	DB_AvcStation m_avcstation;				//AVC��վ��
	DB_AvcBus m_avcbus;						//AVCĸ�߱�
	DB_AvcShunt m_avcshunt;					//AVC���ݱ�
	DB_AvcTrans m_avctrans;					//AVC��ѹ����
	DB_AvcRunParam m_avcrunparam;			//AVC����Ĭ�ϲ�����
	DB_AvcRunTimePart m_timepart;			//AVC����ʱ�α�
	DB_AVCCtrlParam m_avcctrlparam;			//AVC���Ʋ�����

	DB_AvcRelay m_relay;					//AVC������
	DB_AVCWarnType m_warntype;				//AVC�澯����
	DB_AVCWarnInfo m_warninfo;				//AVC�澯��Ϣ��

	DB_AVCVolEvent m_avcvolevent;			//AVC��ѹԽ�ޱ�
	DB_AVCCtrlEvent m_avcctrlevent;			//AVC�����¼���
	DB_AVCShuntEvent m_avcshuntevent;		//AVC���ݿ����¼�
	DB_AVCTranEvent m_avctranevent;			//AVC��ѹ�������¼�
	DB_AVCCtrlPloy m_avcctrlcmd;			//AVC����ָ���
	DB_AVCCtrlZone m_avcctrlzone;			//AVC���������
	DB_AVCStatInfo m_avcstainfo;			//ͳ����Ϣ��
	DB_AVCZoneChange m_avczonechange;			//���򽻻���

	DB_PASIsland m_pasisland;				//PAS������
	DB_PASRuninfo m_pasruninfo;				//PAS������Ϣ
	DB_PASParam m_pasparam;					//PAS���в���
	DB_PASMeasure m_pasmeasure;				//PAS��������
public:
	void InitParamer();
	void StartPrase(char *pFilePath);
	void SwitchPrase(char* pPacket, DataInfo_Struct *pdInfo);
};

#endif // !defined(AFX_PARSE_H__FD3EB868_408C_4608_9FD9_C3DCEBAB06BB__INCLUDED_)
