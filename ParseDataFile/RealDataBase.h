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
	//���ش�ȡ��ʶ
	virtual int GetAccessSign();
	//���ô�ȡ��־
	virtual BOOL SetAccessSign(int iNewSign);

	int GetTableID(char* pszDB, char* pszTable);
	void ModifyRecord(int nTableID, char* pszWhere, char *pszColumn, void* pData);

	//��ѯ��¼
	virtual void* QueryRecord(char* pszTable, char* pszWhere,int &num,char* pszDB=NULL);
	virtual void* QueryRecord(int nTableID, char* pszWhere, int &num);

	//�޸ļ�¼
	virtual BOOL UpdateRecord(char* pszTable, char* pszWhere,void* pRecVal,char* pszDB=NULL);

	//ɾ�����ݼ�¼
	virtual BOOL DeleteRecord(char* pszTable, char* pszWhere,char* pszDB=NULL);
	//�������ݼ�¼
	virtual BOOL InsertRecord(char* pszTable,void* pRecVal,char* pszFields=NULL,char* pszDB=NULL);
	//�������ݼ�¼
	virtual BOOL AppendRecord(char* pszTable,void* pRecVal,char* pszFields=NULL,char* pszDB=NULL);

	//����ʵʱ��¼
	void* GetRealRecords(char *table,int &recn,MEMTABLE** pMem,char *db="visualpw");
	//�޸ı��¼
	void UpdateRealRecord(char *table,int recno,void* dbuf,char *db="visualpw");

	//��ʼ�����ݿ�
	virtual BOOL IniDatabase(char* pszDB,char* pszUser,char* pszPassWord) ;
	//�ر����ݿ�
	virtual void ReleaseDatabase();

	//����д��־
	virtual int GetWriteSign();

	CRealDataBase();
	virtual ~CRealDataBase();

};

#endif // !defined(AFX_REALDATABASE_H__78C80D41_324B_4CB0_A837_8F5FF549F7C5__INCLUDED_)
