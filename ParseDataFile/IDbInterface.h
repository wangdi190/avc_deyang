// IDbInterface.h: interface for the IDbInterface class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IDBINTERFACE_H__FF30B032_3C0B_4430_8CC1_CE5E2A000197__INCLUDED_)
#define AFX_IDBINTERFACE_H__FF30B032_3C0B_4430_8CC1_CE5E2A000197__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class IDbInterface  
{
public:
	//返回存取标识
	virtual int GetAccessSign()=0;
	//设置存取标志
	virtual BOOL SetAccessSign(int iNewSign)=0;
	//查询记录
	virtual void* QueryRecord(char* pszTable, char* pszWhere,int &num,char* pszDB=NULL)=0;
	//修改记录
	virtual BOOL UpdateRecord(char* pszTable, char* pszWhere,void* pRecVal,char* pszDB=NULL)=0;
	//删除数据记录
	virtual BOOL DeleteRecord(char* pszTable, char* pszWhere,char* pszDB=NULL)=0;
	//插入数据记录
	virtual BOOL InsertRecord(char* pszTable,void* pRecVal,char* pszFields=NULL,char* pszDB=NULL)=0;
	//添加数据记录
	virtual BOOL AppendRecord(char* pszTable,void* pRecVal,char* pszFields=NULL,char* pszDB=NULL)=0;
	//初始化数据库
	virtual BOOL IniDatabase(char* pszDB,char* pszUser,char* pszPassWord) =0;
	//关闭数据库
	virtual void ReleaseDatabase() =0;

	//返回写标志
	virtual int GetWriteSign()=0;

	IDbInterface();
	virtual ~IDbInterface();

};

#endif // !defined(AFX_IDBINTERFACE_H__FF30B032_3C0B_4430_8CC1_CE5E2A000197__INCLUDED_)
