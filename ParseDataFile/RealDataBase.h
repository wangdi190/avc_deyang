// RealDataBase.h: interface for the CRealDataBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REALDATABASE_H__78C80D41_324B_4CB0_A837_8F5FF549F7C5__INCLUDED_)
#define AFX_REALDATABASE_H__78C80D41_324B_4CB0_A837_8F5FF549F7C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IDbInterface.h"
#include "dbapi.h"
#include "USERAPI.H"

#define real_db(c)	("visualpw."+c)
#define ems_db(c)	("apppw."+c)
#define his_db(c)	("hisview."+c)

class CRealDataBase : public IDbInterface
{
public:
	//返回存取标识
	virtual int GetAccessSign();
	//设置存取标志
	virtual BOOL SetAccessSign(int iNewSign);

	int GetTableID(char* pszDB, char* pszTable);
	void ModifyRecord(int nTableID, char* pszWhere, char *pszColumn, void* pData);

	//查询记录
	virtual void* QueryRecord(char* pszTable, char* pszWhere,int &num,char* pszDB=NULL);
	virtual void* QueryRecord(int nTableID, char* pszWhere, int &num);

	//修改记录
	virtual BOOL UpdateRecord(char* pszTable, char* pszWhere,void* pRecVal,char* pszDB=NULL);

	//删除数据记录
	virtual BOOL DeleteRecord(char* pszTable, char* pszWhere,char* pszDB=NULL);
	//插入数据记录
	virtual BOOL InsertRecord(char* pszTable,void* pRecVal,char* pszFields=NULL,char* pszDB=NULL);
	//插入数据记录
	virtual BOOL AppendRecord(char* pszTable,void* pRecVal,char* pszFields=NULL,char* pszDB=NULL);

	//返回实时记录
	void* GetRealRecords(char *table,int &recn,MEMTABLE** pMem,char *db="visualpw");
	//修改表记录
	void UpdateRealRecord(char *table,int recno,void* dbuf,char *db="visualpw");

	//初始化数据库
	virtual BOOL IniDatabase(char* pszDB,char* pszUser,char* pszPassWord) ;
	//关闭数据库
	virtual void ReleaseDatabase();

	//返回写标志
	virtual int GetWriteSign();

	CRealDataBase();
	virtual ~CRealDataBase();

};

#endif // !defined(AFX_REALDATABASE_H__78C80D41_324B_4CB0_A837_8F5FF549F7C5__INCLUDED_)
