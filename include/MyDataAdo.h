//CString const strConnection="driver={SQL Server};Server=192.168.0.1;DATABASE=lcx;UID=sa;PWD=";
#if !defined(AFX_ADODB_H__505060AD_C06C_456A_BCC2_F672D288D703__INCLUDED_)
#define AFX_ADODB_H__505060AD_C06C_456A_BCC2_F672D288D703__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct  _FILEDVALUE{
	char fn[64];	//域名
	CString m_str;  //域值
	bool update;    //=0不更改 1=更改
}FILEDVALUE;

class	CMyADO 
{
private:
	// 定义ADO连接、命令、记录集变量指针m_pConnection
	_ConnectionPtr	m_pConnection;
	_CommandPtr		m_pCommand;
	_RecordsetPtr	m_pRecordset;
	//ParametersPtr   *m_Params=NULL;
	//_ParameterPtr	m_Param1;
	
public:		
	//取数据库中的配置信息
	void ReadIni(char *databasename,char *username,char *password,char *ip);
	void Open_database_init();
	int ExecuteSQLNoTrans(CString StrSQL,CString &StrMsg);
	void CommitTrans();
	void BeginTrans();
	int ExecuteCMD(CString StrSQL,CString &StrMsg);
	void InitADO(char *StrIP,char *StrDatadame,char *UserName,char *Pwd,int iType,int iPath);		
	bool MyDatabaseOpen(CString &StrMsg,BOOL bCommand=FALSE);		
	void MyADOClose();	
	FILEDVALUE fd[128]; //最大128个域
	int  fdsum;
	void SetField(int i,char *name);
	void SetFieldSum(int sum);
	int ExecuteSQL(CString StrSQL,CString &StrMsg);	
	_RecordsetPtr ExecuteDataSet(CString StrWhere,CString StrSrc,CString &StrMsg);
	int ExecuteRecordSet(CString StrWhere,CString StrSrc,_RecordsetPtr &Rs,CString &StrMsg);
	bool JudgeRecord(CString  StrSql,CString &StrMsg);		
	CString GetValues(CString  StrSql,CString &StrMsg);
	CString GetManyValues(CString  StrSql,CString &StrMsg);
	int ExecuteSQLType(CString StrSQL,CString arrayvalues[],CString arrayType[],CString &StrMsg);

	CMyADO();
	virtual ~CMyADO();
	bool IsOpen(CString &strError);
private:
};
#endif // !defined(AFX_ADODB_H__505060AD_C06C_456A_BCC2_F672D288D703__INCLUDED_)