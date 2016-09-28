// RealSearch.h: interface for the CRealSearch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REALSEARCH_H__946CEA6B_E433_4AD0_BDFA_9C6210BCCDA9__INCLUDED_)
#define AFX_REALSEARCH_H__946CEA6B_E433_4AD0_BDFA_9C6210BCCDA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
#include "dbapi.h"
#include "userapi.h"
#include "visualdb.h"

struct DATAMAP
{
	DATAMAP(){memset(this, 0, sizeof(DATAMAP));};
	~DATAMAP()
	{
		char* ptemp = (char*)pdata;
		if(ptemp!=NULL)  delete []ptemp;
		pdata = NULL;
	};
	void* pdata;//��¼
	int pos;
};

struct SEARCHMAP
{
	SEARCHMAP(){memset(this, 0, sizeof(SEARCHMAP));};
	~SEARCHMAP()
	{
//		if(pRec!=NULL)  delete []pRec;
		pRec = NULL;
	};
	DATAMAP* pRec;//��¼
	BYTE  f_type;				//��������
	WORD  f_len;				//�򳤶�
	WORD  f_offset;				//�ֽ�ƫ����
	bool isasc;					//�����ǽ���
};


typedef std::vector<SEARCHMAP*> MAPVTR;
typedef std::vector<DATAMAP*> DATAMAPVTR;
typedef std::vector<void*> DATAVTR;

class CRealSearch  
{
public:
	//ˢ������
	BOOL RefreshSort(char *pDB,char *pTable, LPCTSTR fieldname=NULL, bool isasc=true);
	//ͨ����ѯ�������ؼ�¼��ʽΪ"NU=123"����"NAME=����" ʱ�������ѭ��ʽ"�ֶ���=2007-01-01 01:01:01"
//	bool SearchObject(char* pdata, DATAVTR* vdata);
	bool SearchOneObject(char* pdata, DATAMAPVTR* vdata, MAPVTR MapVtr, DBFIELD field);

	void RefreshSort(DATAMAPVTR* datavtr, LPCTSTR order);
	bool SearchSubObject(DATAMAPVTR pdata, LPCTSTR sql, DATAMAPVTR* sdata);
	bool SearchObject(char *pDB,char *pTable, char* sql, char* order,  DATAVTR* vdata);

	CRealSearch();
	virtual ~CRealSearch();

	int m_datalen;
	CUIntArray m_subdatapos;
private:
	void ReleaseInfo();
	void GetMulData(MAPVTR MapVtr, char* sampdata, DBFIELD field, long pos, DATAMAPVTR* vdata);
	CPtrArray m_curField;			//��ǰ����ֶ���Ϣ
	unsigned short m_sortfield;			//���ڲ�ѯ������ֶ�λ��
	DATAMAPVTR m_alldatavtr;
//	MAPVTR m_MapVtr;
//	void* m_pData;
//	char m_tablebase[32];
//	char m_tablename[32];
};

bool CmpSearch(const SEARCHMAP* pOne, const SEARCHMAP* pTwo);

//��ѯ����:����,����,SQL���("�ֶ���=ֵ&�ֶ���=ֵ", �������ֶ�), ������������,��������
bool SearchData(char* szdb, char* sztable, LPCTSTR szsql, LPCTSTR szorder, void** pdata, int& datanum, CUIntArray& posarray);

//�޸ĺ���:����,����,SQL���("�ֶ���=ֵ&�ֶ���=ֵ", �������ֶ�), ��Ҫ�޸ĵ�����
bool UpdateData(char* szdb, char* sztable, LPCTSTR szsql, void* pdata);
bool UpdateData(char* szdb, char* sztable, LPCTSTR szsql, char* szfiled, void* pdata);

//����״̬
bool CheckLocksta(unsigned short status);

//�Ż�״̬
bool CheckOpfsta(unsigned short status);

//��ѹ����״̬
unsigned char CheckCtrlsta(unsigned short status);

//���������״̬
unsigned char CheckGensta(unsigned short status);

//��ѹ����״̬
bool CheckJPVsta(unsigned short status);

//��ѹ�仯״̬
bool CheckJPCsta(unsigned short status);

//���������״̬
unsigned char CheckBusType(unsigned short status);

#endif // !defined(AFX_REALSEARCH_H__946CEA6B_E433_4AD0_BDFA_9C6210BCCDA9__INCLUDED_)
