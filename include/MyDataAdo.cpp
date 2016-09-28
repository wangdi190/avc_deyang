
/*------------------------------------------
//   本程序电力系统数据入库的动态库程序	 
//	 第一版 V1.0
//	 程序：唐玉贵
//	 时间：2004.10.18
//	 功能说明：MyDataAdo.cpp完成的ADO访问数据库	
//   修改1: 2007.7.5  修改人：张强
//   内容1:添加了命令处理,建立了将事务处理分开的函数
//   修改2: 2008.2.16  修改人：张强
//   内容2:修改了连接是否打开的判断(IsOpen)，由判断变量改为传SQL查询检查
*/------------------------------------------
#include "StdAfx.h"
#include "MyDataAdo.h"
	
CString MyConnection;

void CMyADO::InitADO(char *StrIP,char *StrDatadame,char *UserName,char *Pwd,int iType,int iPath)
{		
	CString str="";
	CString tmp="";			  
	switch (iType)
	{
	case 0:  //access
		{
			int i=0,n=0;
			TCHAR exeFullPath[255]; 
			GetModuleFileName(NULL,exeFullPath,255);
			str.Format("%s",exeFullPath);
			for (i=str.GetLength();i>0;i--)
			{
				n++;
				tmp=str.Mid(i,1);
				if (tmp=="\\") 
				{
					break;
				}
			}
			//确定ACCESS文件的目录
			if (iPath==0)
			{
				str=str.Mid(0,str.GetLength()-n+2)+StrDatadame;
			}
			else
				str.Format("%s",StrDatadame);
			
			MyConnection="Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+str;
			break;
		}
	case 1:  // sql server 2000
		
		str.Format("driver={SQL Server};Server=%s;DATABASE=%s;UID=%s;PWD=%s",StrIP,StrDatadame,UserName,Pwd); 
		MyConnection=str;
		break;
	case 2://ORACLE
		//Provider=OraOLEDB.Oracle.1;Password=1;Persist Security Info=True;User ID=power;Data Source=center
		str.Format("Provider=OraOLEDB.Oracle;User ID=%s;Persist Security Info=True;Password=%s;Data Source=%s",UserName,Pwd,StrDatadame); 
		MyConnection=str;
		break;
	case 3://Sybase 		 
		break;
	}	
};

CMyADO::CMyADO()
{
	m_pConnection=NULL;
    m_pRecordset=NULL;
	m_pCommand=NULL;
};

CMyADO::~CMyADO()
{
	MyADOClose();
}

bool CMyADO::MyDatabaseOpen(CString &StrMsg,BOOL bCommand)
{	
	if (IsOpen(StrMsg)) 
		return true;
	
	HRESULT hr=m_pConnection.CreateInstance(__uuidof(Connection));
	if(hr!=S_OK)
		return false;
	if(bCommand)
		m_pCommand.CreateInstance(__uuidof(Command));
	
	try                 
	{			
		m_pConnection->Open((_bstr_t)(MyConnection),"","",adModeUnknown);
		if(bCommand)
			m_pCommand->ActiveConnection=m_pConnection;
	}
	catch(_com_error &e)
	{
		m_pConnection.Release();
		m_pConnection=NULL;
		StrMsg="数据库连接失败，确认数据库连接配置是否正确！";
		StrMsg=e.ErrorMessage();
		return false;
	} 
	return true;
}
bool CMyADO::IsOpen(CString &strError)
{
	if(MyConnection.IsEmpty())
	{
		strError="连接字符串不能为空！";
		return FALSE;
	}
	
	if(m_pConnection==NULL || m_pConnection->GetState()!=adStateOpen)
		return FALSE;
	
	try  
	{  
		_variant_t rstAffected;
		_bstr_t bstrSQL("select 1");
		m_pConnection->Execute(bstrSQL,&rstAffected,adCmdText);  
	}  
	catch(_com_error e)  
	{  
		if(m_pConnection->GetState()==adStateOpen)
			m_pConnection->Close();
		
		return FALSE;
	}
	return TRUE;
}
void CMyADO::MyADOClose()
{
	if (m_pRecordset!=NULL)
		m_pRecordset->Close();
	if (m_pConnection!=NULL)
	{
		if(m_pConnection->State)
			m_pConnection->Close();
		m_pConnection= NULL;
	}
	if(m_pCommand!=NULL)
		m_pCommand->Release();
}
int CMyADO::ExecuteSQL(CString StrSQL,CString &StrMsg)
{	
	CString strError="";
	if (!IsOpen(strError)) 
	{
		if(!MyDatabaseOpen(strError))
			return 1;
	}
	
	_variant_t RecordsAffected;
	BSTR _bstrSQl;
	
	try
	{
		_bstrSQl=StrSQL.AllocSysString();
		//m_pConnection->BeginTrans();	
		m_pConnection->Execute(_bstrSQl,&RecordsAffected,adCmdText);
		//m_pConnection->CommitTrans();
		SysFreeString(_bstrSQl);
        return 0;
	}
	catch (_com_error &e)
	{
		//m_pConnection->RollbackTrans();
		StrMsg=(LPCSTR)e.Description();
		SysFreeString(_bstrSQl);
		return 1;
	}
	
}
int CMyADO::ExecuteSQLType(CString StrSQL,CString arrayvalues[],CString arrayType[],CString &StrMsg)
{	
	CString strError="";
	if (!IsOpen(strError))
	{
		if(!MyDatabaseOpen(strError))
			return 1;
	}
	
	_variant_t RecordsAffected;
	BSTR _bstrSQl;
	
	try
	{
		_bstrSQl=StrSQL.AllocSysString();
		m_pConnection->BeginTrans();	
		m_pConnection->Execute(_bstrSQl,&RecordsAffected,adCmdText);
		m_pConnection->CommitTrans();
		SysFreeString(_bstrSQl);
        return 0;
	}
	catch (_com_error &e)
	{
		m_pConnection->RollbackTrans();
		StrMsg=(LPCSTR)e.Description();
		SysFreeString(_bstrSQl);
		return 1;
	}
	
}

//设置域总数
void CMyADO::SetFieldSum(int sum)
{
	fdsum=sum;
	fdsum=fdsum>128 ? 128:fdsum;
}
//设置域名
void CMyADO::SetField(int i, char *name)
{
	if(i>=fdsum) return;
	strcpy(fd[i].fn,name);
	fd[i].update=0;
}
bool CMyADO::JudgeRecord(CString  StrSql,CString &StrMsg)
{
	CString strError="";
	if (!IsOpen(strError))
	{
		if(!MyDatabaseOpen(strError))
			return false;
	}
	
	_RecordsetPtr m_pRecord; // Recordset对象
	_variant_t RecordsAffected;
	BSTR _bstrSQl;
	try
	{		
		_bstrSQl=StrSql.AllocSysString();
		m_pRecord=m_pConnection->Execute(_bstrSQl,&RecordsAffected,adCmdText);
		SysFreeString(_bstrSQl);
		if (m_pRecord!=NULL)
		{
			_variant_t vindex=(long)0;		
			if (!m_pRecord->BOF)
			{
				return true;
			}
			else
				return false;		
		}
		else
			return false;
		
		if (m_pRecord!=NULL)
		{
			if(m_pRecord->GetState()==adStateOpen) 
				m_pRecord->Close();
			m_pRecord.Release();
		};
	}
	catch (_com_error &e)
	{	
		StrMsg=(LPCSTR)e.Description();
		if (m_pRecord!=NULL)
		{
			if(m_pRecord->GetState()==adStateOpen) 
				m_pRecord->Close();
			m_pRecord.Release();
		};
		SysFreeString(_bstrSQl);
		return false;
	}		
	
}
CString CMyADO::GetValues(CString  StrSql,CString &StrMsg)
{	
	CString strError="";
	if (!IsOpen(strError))
	{
		if(!MyDatabaseOpen(strError))
			return "";
	}
	
	CString strTmp="";
	_variant_t var;
	_RecordsetPtr m_pRecord; // Recordset对象
	_variant_t RecordsAffected;
	BSTR _bstrSQl;
	try
	{		
		_bstrSQl=StrSql.AllocSysString();
		m_pRecord=m_pConnection->Execute(_bstrSQl,&RecordsAffected,adCmdText);
		SysFreeString(_bstrSQl);
		_variant_t vindex=(long)0;
		if (m_pRecord!=NULL)
		{
			var=m_pRecord->GetCollect(vindex);
			if (var.vt!=VT_NULL)
			{
				return (LPCSTR)_bstr_t(var);
			}
			else
			{					
				return "";
			}
			if (m_pRecord!=NULL)
			{
				if(m_pRecord->GetState()==adStateOpen) 
					m_pRecord->Close();
				m_pRecord.Release();
			}
		}
	}
	catch (_com_error &e)
	{	
		StrMsg=(LPCSTR)e.Description();
		if (m_pRecord!=NULL)
		{
			if(m_pRecord->GetState()==adStateOpen) 
				m_pRecord->Close();
			m_pRecord.Release();
		};
		SysFreeString(_bstrSQl);
	}			
	return "";
}
CString CMyADO::GetManyValues(CString  StrSql,CString &StrMsg)
{	
	CString strError="";
	int i,m_cols=0;
	long int j;
	if (!IsOpen(strError)) 
	{
		if(!MyDatabaseOpen(strError))
			return "";
	}
	
	for (i=0;i<StrSql.GetLength();i++)
	{
		if (StrSql.Mid(i,1)==",") m_cols++;
	}
	m_cols=m_cols+1;
	CString strTmp="";
	_variant_t var;
	_RecordsetPtr m_pRecord; // Recordset对象
	_variant_t RecordsAffected;
	BSTR _bstrSQl;
	try
	{		
		_bstrSQl=StrSql.AllocSysString();
		m_pRecord=m_pConnection->Execute(_bstrSQl,&RecordsAffected,adCmdText);
		SysFreeString(_bstrSQl);
		_variant_t vindex;
		if (m_pRecord!=NULL)
		{
			
			for(j=0;j<m_cols;j++)
			{
				vindex=(long)j;
				var=m_pRecord->GetCollect(vindex);
				if (var.vt!=VT_NULL)
				{
					if (j==m_cols-1)
						strTmp=strTmp+(LPCSTR)_bstr_t(var);
					else
					{
						strTmp=strTmp+(LPCSTR)_bstr_t(var);
						strTmp=strTmp+",";
					}
				}
				else
				{					
					if (j==m_cols-1)
						strTmp=strTmp+" ";
					else
						strTmp=strTmp+" ,";
				}
			} //for j=0
			
			if (m_pRecord!=NULL)
			{
				if(m_pRecord->GetState()==adStateOpen) 
					m_pRecord->Close();
				m_pRecord.Release();
			};
		}
		else
			strTmp="";
		
		return strTmp;
	}
	catch (_com_error &e)
	{	
		StrMsg=(LPCSTR)e.Description();
		if (m_pRecord!=NULL)
		{
			if(m_pRecord->GetState()==adStateOpen) 
				m_pRecord->Close();
			m_pRecord.Release();
		};
		SysFreeString(_bstrSQl);
		return "";
	}			
}
_RecordsetPtr CMyADO::ExecuteDataSet(CString StrWhere,CString StrSrc,CString &StrMsg)
{
	CString strError="";
	if (!IsOpen(strError)) 
	{
		if(!MyDatabaseOpen(strError))
			return NULL;
	}
	
	_RecordsetPtr rs;
	CString str;	
	str=StrSrc+ " "+ StrWhere;
	_variant_t RecordsAffected;
	BSTR _bstrSQl;
	try
	{
		if (m_pRecordset!=NULL)
			m_pRecordset->Close();
		_bstrSQl=str.AllocSysString();
		m_pRecordset=m_pConnection->Execute(_bstrSQl,&RecordsAffected,adCmdText);
		SysFreeString(_bstrSQl);
		rs= m_pRecordset;
        return rs;
	}
	catch (_com_error &e)
	{	
		StrMsg=(LPCSTR)e.Description();
		SysFreeString(_bstrSQl);
		return rs;
	}
}
int CMyADO::ExecuteRecordSet(CString StrWhere,CString StrSrc,_RecordsetPtr &Rs,CString &StrMsg)
{
	CString strError="";
	if (!IsOpen(strError)) 
	{
		if(!MyDatabaseOpen(strError))
			return 1;
	}
	
	CString str;	
	str=StrSrc+ " "+ StrWhere;
	_variant_t RecordsAffected;
	BSTR _bstrSQl;
	try
	{
		if (m_pRecordset!=NULL)
			m_pRecordset->Close();
		_bstrSQl=str.AllocSysString();
		Rs=m_pConnection->Execute(_bstrSQl,&RecordsAffected,adCmdText);
		SysFreeString(_bstrSQl);
        return 0;
	}
	catch (_com_error &e)
	{	
		StrMsg=(LPCSTR)e.Description();
		SysFreeString(_bstrSQl);
		return 1;
	}		
	
}

int CMyADO::ExecuteCMD(CString StrSQL, CString &StrMsg)
{
	CString strError="";
	if (!IsOpen(strError)) 
	{
		if(!MyDatabaseOpen(strError))
			return 1;
	}
	
	BSTR _bstrSQl;
	try
	{
		m_pConnection->BeginTrans();
		_bstrSQl=StrSQL.AllocSysString();
		m_pCommand->CommandText=_bstrSQl;
		m_pCommand->Execute(NULL,NULL,adCmdText);
		m_pConnection->CommitTrans();
		SysFreeString(_bstrSQl);
        return 0;
	}
	catch (_com_error &e)
	{
		m_pConnection->RollbackTrans();
		StrMsg=(LPCSTR)e.Description();
		SysFreeString(_bstrSQl);
		return 1;
	}
}

void CMyADO::BeginTrans()
{
	if(m_pConnection!=NULL)
		m_pConnection->BeginTrans();
}

void CMyADO::CommitTrans()
{
	if(m_pConnection!=NULL)
		m_pConnection->CommitTrans();
}

//取数据库中的配置信息
void CMyADO::ReadIni(char *databasename,char *username,char *password,char *ip)
{
	CString tmp,input;	
	TCHAR exefullpath[256];
	CStdioFile file;
	CString strFileName;
	int i_file=0;
	int i=1,n=0;
	//读写配置文件
	GetModuleFileName(NULL,exefullpath,128);
	tmp.Format("%s",exefullpath);

	for (i=tmp.GetLength();i>0;i--)
	{
		if (tmp.Mid(i,1)=="\\") break;
	}

	tmp=tmp.Mid(0,i+1)+"FtpAgent.ini";
	try
	{
		i_file=file.Open(tmp,CFile::modeRead);	
		if (i_file==NULL) return ;
	}
	catch( CException * e )
	{
		e->Delete();
		if (file!=NULL) file.Close();
		return ;
	}
	try
	{
		i=1;
		n=0;
		while( file.ReadString( input )) 	
		{
			switch (i)
			{
				case 4:
					   n=input.Find("=");
					   tmp=input.Mid(n+1,input.GetLength()-n);
					   sprintf(databasename,"%s",tmp);
					   break;
				case 5:
						n=input.Find("=");
					   tmp=input.Mid(n+1,input.GetLength()-n-1);
					   sprintf(username,"%s",tmp);
					   break;
				case 6:
						n=input.Find("=");
					   tmp=input.Mid(n+1,input.GetLength()-n-1);
					   sprintf(password,"%s",tmp);
					  break;
				case 7:
						n=input.Find("=");
					   tmp=input.Mid(n+1,input.GetLength()-n-1);
					   sprintf(ip,"%s",tmp);
					  break;
			}
			i++;
			if (i>8) break;
		}
		file.Close();	
	}
	catch( CException * e )
	{
		e->Delete();
		if (file!=NULL) file.Close();
		return ;
	}
}

void CMyADO::Open_database_init()
{
	CString strError="";
	if (!IsOpen(strError))
	{
		char StrIP[50];
		char StrDatadame[100];
		char UserName[50];
		char Pwd[50];
		ReadIni(StrDatadame,UserName,Pwd,StrIP);
		strcat(StrDatadame,"_ems");
		::CoInitialize(NULL);
		InitADO(StrIP,StrDatadame,UserName,Pwd,1,0);
		if (MyDatabaseOpen(strError)==false)
		{
			::CoUninitialize();
			return ;
		};
	}
}

int CMyADO::ExecuteSQLNoTrans(CString StrSQL,CString &StrMsg)
{	
	CString strError="";
	if (!IsOpen(strError)) 
	{
		if(!MyDatabaseOpen(strError,TRUE))
			return 1;
	}
	
	_variant_t RecordsAffected;
	BSTR _bstrSQl;
	
	try
	{
		_bstrSQl=StrSQL.AllocSysString();
		m_pConnection->Execute(_bstrSQl,&RecordsAffected,adCmdText);
		SysFreeString(_bstrSQl);
	}
	catch (_com_error &e)
	{
		StrMsg=(LPCSTR)e.Description();
		SysFreeString(_bstrSQl);
		return 1;
	}
	return 0;
}

