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
	//���ش�ȡ��ʶ
	virtual int GetAccessSign()=0;
	//���ô�ȡ��־
	virtual BOOL SetAccessSign(int iNewSign)=0;
	//��ѯ��¼
	virtual void* QueryRecord(char* pszTable, char* pszWhere,int &num,char* pszDB=NULL)=0;
	//�޸ļ�¼
	virtual BOOL UpdateRecord(char* pszTable, char* pszWhere,void* pRecVal,char* pszDB=NULL)=0;
	//ɾ�����ݼ�¼
	virtual BOOL DeleteRecord(char* pszTable, char* pszWhere,char* pszDB=NULL)=0;
	//�������ݼ�¼
	virtual BOOL InsertRecord(char* pszTable,void* pRecVal,char* pszFields=NULL,char* pszDB=NULL)=0;
	//������ݼ�¼
	virtual BOOL AppendRecord(char* pszTable,void* pRecVal,char* pszFields=NULL,char* pszDB=NULL)=0;
	//��ʼ�����ݿ�
	virtual BOOL IniDatabase(char* pszDB,char* pszUser,char* pszPassWord) =0;
	//�ر����ݿ�
	virtual void ReleaseDatabase() =0;

	//����д��־
	virtual int GetWriteSign()=0;

	IDbInterface();
	virtual ~IDbInterface();

};

#endif // !defined(AFX_IDBINTERFACE_H__FF30B032_3C0B_4430_8CC1_CE5E2A000197__INCLUDED_)
