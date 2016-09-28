// RealDataBase.cpp: implementation of the CRealDataBase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RealDataBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRealDataBase::CRealDataBase()
{

}

CRealDataBase::~CRealDataBase()
{
//	ReleaseDatabase();
}

//���ش�ȡ��ʶ
int CRealDataBase::GetAccessSign()
{
	return 0;
}

//���ô�ȡ��־
BOOL CRealDataBase::SetAccessSign(int iNewSign)
{
	return TRUE;
}

int CRealDataBase::GetTableID(char* pszDB, char* pszTable)
{
	DWORD idi;
	if(!LSI_GetTableID(pszDB,pszTable,idi)) 
		return -1;
	
	int tbid=LOWORD(idi);
	return tbid;
}


void CRealDataBase::ModifyRecord(int nTableID, char* pszWhere, char *pszColumn, void* pData)
{
	if(pszWhere==NULL)
		return;

	int recno=LSI_GetFirstRecno(pszWhere);
	if (recno>=0)
	{
		LSI_PutColVal(nTableID, recno, pszColumn, pData);
	}
}



//��ѯ��¼
void* CRealDataBase::QueryRecord(char* pszTable, char* pszWhere,int &num,char* pszDB)
{
	if(pszDB==NULL || pszTable==NULL)
		return FALSE;

	num=-1;
	void* pReturn=NULL;
	if(pszWhere!=NULL)
	{
	//	char chSql[256];	
	//	sprintf(chSql,"TABLE(%s.%s),WHERE(%s)",pszDB,pszTable,pszWhere);
		
		//TABLE(���ݿ���.����)��WHERE(����=XXX)
		int error;
		char* pRec=(char*)LSI_QueryRecord(pszWhere,num,error,TRUE);
		pReturn=(void*)(pRec+num*2*sizeof(char));
		num = LSI_GetFirstRecno(pszWhere);
	}
	else
	{
		DWORD idi;
		MEMTABLE *mtb;
		if(!LSI_GetTableID(pszDB,pszTable,idi)) return 0;
		int addr=LOWORD(idi);
		mtb=(MEMTABLE *)LSI_GetTableAdd(addr);
		if(mtb!=NULL)
		{
			num=mtb->userec;
			pReturn=mtb->data;
		}
	}
	return pReturn;
}

//��ѯ��¼
void* CRealDataBase::QueryRecord(int nTableID, char* pszWhere, int &num)
{
	num=0;
	void* pReturn=NULL;
	if(pszWhere!=NULL)
	{
		int error;
		char* pRec=(char*)LSI_QueryRecord(pszWhere,num,error,TRUE);
		pReturn=(void*)(pRec+num*2*sizeof(char));
	}
	else
	{
		//		DWORD idi;
		MEMTABLE *mtb;
		//		if(!LSI_GetTableID(pszDB,pszTable,idi)) return 0;
		//		int addr=LOWORD(idi);
		mtb=(MEMTABLE *)LSI_GetTableAdd(nTableID);
		if(mtb!=NULL)
		{
			num=mtb->userec;
			pReturn=mtb->data;
		}
	}
	return pReturn;
}



//�޸ļ�¼
BOOL CRealDataBase::UpdateRecord(char* pszTable, char* pszWhere,void* pRecVal,char* pszDB)
{
	if(pszDB==NULL || pszTable==NULL || pRecVal==NULL)
		return FALSE;

//	char chSql[256];	
//	sprintf(chSql,"TABLE(%s.%s),WHERE(%s)",pszDB,pszTable,pszWhere);

	int recno=LSI_GetFirstRecno(pszWhere);
	if(recno>=0)//�޸�
	{
		char chUpdate[256];	
		sprintf(chUpdate,"%s.%s",pszDB,pszTable);
		LSI_UpdateARecord(chUpdate, pRecVal, recno);
	//	DWORD dwtid=0;
	//	if(LSI_GetTableIDExt(chUpdate,dwtid))
	//		LSI_SetChanged(dwtid,recno);
		return TRUE;
	}
	return FALSE;
}

//ɾ�����ݼ�¼
BOOL CRealDataBase::DeleteRecord(char* pszTable, char* pszWhere,char* pszDB)
{
	if(pszDB==NULL || pszTable==NULL)
		return FALSE;

	char chDelete[256];	
	sprintf(chDelete,"%s.%s",pszDB,pszTable);
	if(pszWhere==NULL)
		return LSI_EmptyTable(chDelete,false);

	char chSql[256];	
	sprintf(chSql,"TABLE(%s.%s),WHERE(%s)",pszDB,pszTable,pszWhere);

	int recno=LSI_GetFirstRecno(chSql);
	if(recno>=0)//ɾ��
	{
		if(!LSI_DeleteRecord(chDelete, recno))
			return TRUE;
	}
	return FALSE;
}

//�������ݼ�¼
BOOL CRealDataBase::InsertRecord(char* pszTable,void* pRecVal,char* pszFields,char* pszDB)
{
	if(pszDB==NULL || pszTable==NULL || pRecVal==NULL)
		return FALSE;

	char chSql[256],chInsert[256];	
	sprintf(chInsert,"%s.%s",pszDB,pszTable);
	sprintf(chSql,"TABLE(%s.%s)",pszDB,pszTable);

	int recno=LSI_GetFirstRecno(chSql);
	if(recno>=0)
	{
		if(!LSI_InsertRecord(chInsert, pRecVal, recno))
			return TRUE;
	}
	return FALSE;
}

//������ݼ�¼
BOOL CRealDataBase::AppendRecord(char* pszTable,void* pRecVal,char* pszFields,char* pszDB)
{
	if(pszDB==NULL || pszTable==NULL || pRecVal==NULL)
		return FALSE;

	char chSql[256];	
	sprintf(chSql,"%s.%s",pszDB,pszTable);

	return LSI_AppendRec(chSql,pRecVal);
}

//��ʼ�����ݿ�
BOOL CRealDataBase::IniDatabase(char* pszDB,char* pszUser,char* pszPassWord)
{
	if(!LSI_InitNTDbi())
		return FALSE;
	if(!LSI_CheckUser("sa",""))
		return FALSE;
	return TRUE;
}

//�ر����ݿ�
void CRealDataBase::ReleaseDatabase()
{
}

//����д��־
int CRealDataBase::GetWriteSign()
{
	return 0;
}

//����ʵʱ��¼
void* CRealDataBase::GetRealRecords(char *table,int &recn,MEMTABLE** pMem,char *db)
{
	DWORD idi;
	if(!LSI_GetTableID(db,table,idi)) return NULL;
	int tbAdd=LOWORD(idi);
	(*pMem)=(MEMTABLE *)LSI_GetTableAdd(tbAdd);
	if((*pMem)==NULL) return NULL;
	recn=(*pMem)->userec;
	if(recn==0)
		return NULL;

	return (*pMem)->data;
}

//�޸ı��¼
void CRealDataBase::UpdateRealRecord(char *table,int recno,void* dbuf,char *db)
{
	if(recno>=0)//�޸�
	{
		char chUpdate[256];	
		sprintf(chUpdate,"%s.%s",db,table);
		LSI_UpdateARecord(chUpdate, dbuf, recno);
		DWORD dwtid=0;
		if(LSI_GetTableIDExt(chUpdate,dwtid))
			LSI_SetChanged(dwtid,recno);
	}
}



