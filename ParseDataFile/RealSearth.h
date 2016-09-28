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
	void* pdata;//记录
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
	DATAMAP* pRec;//记录
	BYTE  f_type;				//数据类型
	WORD  f_len;				//域长度
	WORD  f_offset;				//字节偏移量
	bool isasc;					//升序还是降序
};


typedef std::vector<SEARCHMAP*> MAPVTR;
typedef std::vector<DATAMAP*> DATAMAPVTR;
typedef std::vector<void*> DATAVTR;

class CRealSearch  
{
public:
	//刷新排序
	BOOL RefreshSort(char *pDB,char *pTable, LPCTSTR fieldname=NULL, bool isasc=true);
	//通过查询条件返回记录格式为"NU=123"或者"NAME=名称" 时间必须遵循格式"字段名=2007-01-01 01:01:01"
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
	CPtrArray m_curField;			//当前表的字段信息
	unsigned short m_sortfield;			//用于查询排序的字段位置
	DATAMAPVTR m_alldatavtr;
//	MAPVTR m_MapVtr;
//	void* m_pData;
//	char m_tablebase[32];
//	char m_tablename[32];
};

bool CmpSearch(const SEARCHMAP* pOne, const SEARCHMAP* pTwo);

//查询函数:库名,表名,SQL语句("字段名=值&字段名=值", 最多五个字段), 返回数据内容,数据数量
bool SearchData(char* szdb, char* sztable, LPCTSTR szsql, LPCTSTR szorder, void** pdata, int& datanum, CUIntArray& posarray);

//修改函数:库名,表名,SQL语句("字段名=值&字段名=值", 最多五个字段), 需要修改的数据
bool UpdateData(char* szdb, char* sztable, LPCTSTR szsql, void* pdata);
bool UpdateData(char* szdb, char* sztable, LPCTSTR szsql, char* szfiled, void* pdata);

//闭锁状态
bool CheckLocksta(unsigned short status);

//优化状态
bool CheckOpfsta(unsigned short status);

//调压控制状态
unsigned char CheckCtrlsta(unsigned short status);

//发电机控制状态
unsigned char CheckGensta(unsigned short status);

//电压控制状态
bool CheckJPVsta(unsigned short status);

//电压变化状态
bool CheckJPCsta(unsigned short status);

//发电机控制状态
unsigned char CheckBusType(unsigned short status);

#endif // !defined(AFX_REALSEARCH_H__946CEA6B_E433_4AD0_BDFA_9C6210BCCDA9__INCLUDED_)
