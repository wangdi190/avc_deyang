// RealSearch.cpp: implementation of the CRealSearth class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RealSearth.h"
#include <algorithm>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRealSearch::CRealSearch()
{
//	m_pData=NULL;
	m_datalen = 0;
	m_alldatavtr.clear();
}

CRealSearch::~CRealSearch()
{
	ReleaseInfo();
}

void CRealSearch::ReleaseInfo()
{
	int count = m_curField.GetSize();
	for(int i=0; i<count; i++)
	{
		DBFIELD* ptemp = NULL;
		ptemp = (DBFIELD*)m_curField.GetAt(i);
		if(ptemp!=NULL)
		{
			delete ptemp;
			ptemp=NULL;
		}
	}
	m_curField.RemoveAll();

	count = m_alldatavtr.size();
	for(i=0; i<count; i++)
	{
		DATAMAP* ptemp = NULL;
		ptemp = m_alldatavtr.at(i);
		if(ptemp!=NULL)
		{
			delete ptemp;
			ptemp=NULL;
		}
	}
	m_alldatavtr.clear();
}

void CRealSearch::RefreshSort(DATAMAPVTR* datavtr, LPCTSTR order)
{
	if(datavtr==NULL||order==NULL||strlen(order)<=0)
		return;
	if(m_curField.GetSize()<=0)
		return;
	MAPVTR	MapVtr;
	MapVtr.clear();

	//�õ���Ӧ���ֶ���Ϣ
	DBFIELD dbField;
	memset(&dbField, 0, sizeof(DBFIELD));
	for(int i=0; i<m_curField.GetSize(); i++)
	{
		DBFIELD* pfield = (DBFIELD*)m_curField.GetAt(i);
		if(pfield==NULL)
			continue;
		
		if(strcmp(pfield->f_name, order)==0)
		{
			memcpy(&dbField, pfield, sizeof(DBFIELD));
			break;
		}
	}

	int count = datavtr->size();
	for(i=0; i<count; i++)
	{
		SEARCHMAP* pMap=new SEARCHMAP;
		pMap->pRec = datavtr->at(i);
		pMap->f_type = dbField.f_type;				//��������
		pMap->f_len = dbField.f_len;				//�򳤶�
		pMap->f_offset = dbField.f_offset;				//�ֽ�ƫ����
		pMap->isasc = true;
		MapVtr.push_back(pMap);
	}
	std::sort(MapVtr.begin(),MapVtr.end(),CmpSearch);

	datavtr->clear();
	for(i=0; i<count; i++)
	{
		datavtr->push_back(MapVtr.at(i)->pRec);
	}

	count = MapVtr.size();
	for(i=0; i<count; i++)
	{
		SEARCHMAP* ptemp = NULL;
		ptemp = MapVtr.at(i);
		if(ptemp!=NULL)
		{
			delete ptemp;
			ptemp=NULL;
		}
	}
	MapVtr.clear();
}

BOOL CRealSearch::RefreshSort(char *pDB, char *pTable, LPCTSTR fieldname, bool isasc)
{
	m_sortfield = 0;
	CString szname(fieldname);
	szname.MakeLower();

//	for(MAPVTR::iterator itr=m_MapVtr.begin();itr<m_MapVtr.begin();itr++)
//		delete (*itr);
	MAPVTR	m_MapVtr;//.clear();

//	if(m_pData!=NULL)
//		delete []m_pData;
//	m_pData=NULL;
//	m_tablebase[0]=0;
//	m_tablename[0]=0;

	int recn=0;
	m_datalen=0;
	//��ȡ���ݿ���Ϣ
//	ReleaseFieldInfo();

	DWORD idi;
	if(!LSI_GetTableID(pDB,pTable,idi)) return false;
	int tbAdd=LOWORD(idi);
	MEMTABLE* memtable = NULL;
	memtable=(MEMTABLE *)LSI_GetTableAdd(tbAdd);
	if(memtable==NULL) return false;
	//�����ܳ���
	int datalen = memtable->reclen;
	m_datalen = datalen;
//	sprintf(m_tablebase, "%s", pDB);
//	sprintf(m_tablename, "%s", pTable);

	 //��ȡ��ǰ���ֶ���Ϣ
	int fieldnum = memtable->tbl->n_fd;
	for(int i=0; i<fieldnum; i++)
	{
		M_DBFIELD* pfield=NULL;
		pfield = memtable->tbl->field+i;
		if(pfield==NULL)
			break;

		DBFIELD* pnewfield;
		pnewfield = new DBFIELD;
		memcpy(pnewfield, &pfield->field, sizeof(DBFIELD));
//		m_curFieldInfo.Add(pnewfield);
		if(fieldname==NULL)
			continue;

		CString szfield(pnewfield->f_name);
		szfield.MakeLower();
		if(szfield==szname)
			m_sortfield=i;
	}

	recn = memtable->userec;
	//����������Ϣ
	for(i=0; i<recn; i++)
	{
		SEARCHMAP* pMap=new SEARCHMAP;
//		pMap->pRec = memtable->data+i*datalen;
//		memcpy(&pMap->field, &(memtable->tbl->field+m_sortfield)->field, sizeof(DBFIELD));
		pMap->f_type = (memtable->tbl->field+m_sortfield)->field.f_type;				//��������
		pMap->f_len = (memtable->tbl->field+m_sortfield)->field.f_len;				//�򳤶�
		pMap->f_offset = (memtable->tbl->field+m_sortfield)->field.f_offset;				//�ֽ�ƫ����
		pMap->isasc = isasc;
		m_MapVtr.push_back(pMap);
		if((i+1)==recn)
			int ii=0;
	}

	std::sort(m_MapVtr.begin(),m_MapVtr.end(),CmpSearch);
	return recn>0 ? TRUE:FALSE;
}

//ͨ����ѯ�������ؼ�¼
bool CRealSearch::SearchOneObject(char* pdata, DATAMAPVTR* vdata, MAPVTR MapVtr, DBFIELD field)
{
	vdata->empty();
	if(pdata==NULL||strlen(pdata)<=0)
		return false;
	if(MapVtr.size()<=0)
		return false;

	//����ѯ����
	int len = strlen(pdata);
	char* tempdata = new char[len+1];
	memset(tempdata, 0, len+1);
//	sprintf(tempdata, "%s", sztemp.Mid(sztemp.Find("=")+1));
	strcat(tempdata, pdata);

	bool isasc = MapVtr[0]->isasc;
	BYTE datatype = field.f_type;
	try
	{
		long lMin=0;
		long lMax=MapVtr.size()-1;
		while(lMin<=lMax)
		{
			long lHalf=(lMax+lMin)/2;
			if(lHalf>=0)
			{
				int iCompare = 0;
				switch(datatype)
				{
				case  DB_CHAR:
					{
					char* data = (char*)MapVtr[lHalf]->pRec->pdata+field.f_offset;
					iCompare=strcmp(data, tempdata);
					break;
					}
				case  DB_BYTE:
					{
					BYTE bdata = (BYTE)atoi(tempdata);
					BYTE data = *((BYTE*)((BYTE*)MapVtr[lHalf]->pRec->pdata+field.f_offset));
					iCompare=data-bdata;
					break;
					}
				case  DB_SHORT:
					{
					short sdata = (short)atoi(tempdata);
					short data = *(short*)((BYTE*)MapVtr[lHalf]->pRec->pdata+field.f_offset);
					iCompare=data-sdata;
					break;
					}
				case  DB_WORD:
					{
					WORD wdata = (WORD)atol(tempdata);
					WORD data = *(WORD*)((BYTE*)MapVtr[lHalf]->pRec->pdata+field.f_offset);
					iCompare=data-wdata;
					break;
					}
				case  DB_INT:
					{
					int idata = (int)atoi(tempdata);
					int data = *(int*)((BYTE*)MapVtr[lHalf]->pRec->pdata+field.f_offset);
					iCompare=data-idata;
					break;
					}
				case  DB_DWORD:
					{
					DWORD dwdata = (DWORD)_atoi64(tempdata);
					DWORD data = *(DWORD*)((BYTE*)MapVtr[lHalf]->pRec->pdata+field.f_offset);
					iCompare=data-dwdata;
					break;
					}
				case  DB_FLOAT:
					{
					float fdata = atof(tempdata);
					float data = *(float*)((BYTE*)MapVtr[lHalf]->pRec->pdata+field.f_offset);
					if(data>fdata)
						iCompare=1;
					else if(data<fdata)
						iCompare=-1;
					else 
						iCompare=0;
					break;
					}
				case  DB_DOUBLE:
					{
					double ddata = (double)atof(tempdata);
					double data = *(double*)((BYTE*)MapVtr[lHalf]->pRec->pdata+field.f_offset);
					if(data>ddata)
						iCompare=1;
					else if(data<ddata)
						iCompare=-1;
					else 
						iCompare=0;
					break;
					}
				case  DB_DTIME:
				case  DB_DATE:
				case  DB_TIME:
					{
					int itime[6];
					memset(itime, 0, sizeof(itime));
					sscanf(tempdata, "%d-%d-%d %d:%d:%d",
						&itime[0], &itime[1], &itime[2], &itime[3], &itime[4], &itime[5]);
					CTime tdata(itime[0], itime[1], itime[2], itime[3], itime[4], itime[5]);
					CTime data;
					memcpy(&data, (BYTE*)MapVtr[lHalf]->pRec->pdata+field.f_offset, sizeof(CTime));
					if(data==tdata)
						iCompare=0;
					else if(data>tdata)
						iCompare=1;
					else
						iCompare=-1;
					break;
					}
				default:
					return NULL;
				}
				if(iCompare<0)
					if(isasc)
						lMin=lHalf+1;
					else
						lMax=lHalf-1;
				else if(iCompare>0)
					if(isasc)
						lMax=lHalf-1;
					else
						lMin=lHalf+1;
				else
				{
					delete []tempdata;
					vdata->push_back(MapVtr[lHalf]->pRec);
					GetMulData(MapVtr, (char*)MapVtr[lHalf]->pRec->pdata+field.f_offset, field, lHalf, vdata);
					return true;
				}
			}
			else
				break;
		}
	}
	catch(CException* e)
	{
		e->Delete();
		delete []tempdata;
		return false;
	}

	delete []tempdata;
	return false;
}

bool CRealSearch::SearchSubObject(DATAMAPVTR pdata, LPCTSTR sql, DATAMAPVTR* sdata)
{
	sdata->clear();

	if(pdata.size()==0)
		return false;
	if(sql==NULL||strlen(sql)<=0)
	{
		int count = pdata.size();
		for(int i=0; i<count; i++)
			sdata->push_back(pdata.at(i));
		return true;
	}
	else
	{
		//ȡ��Ӧ�ֶ���Ϣ
		char field[50];
		field[0]=0;
		char value[50];
		value[0]=0;
		CString szsql(sql);
		sprintf(field, "%s", szsql.Left(szsql.Find("=")));
		sprintf(value, "%s", szsql.Mid(szsql.Find("=")+1));

		DBFIELD dbField;
		memset(&dbField, 0, sizeof(DBFIELD));
		for(int i=0; i<m_curField.GetSize(); i++)
		{
			DBFIELD* pfield = (DBFIELD*)m_curField.GetAt(i);
			if(pfield==NULL)
				continue;

			if(strcmp(pfield->f_name, field)==0)
			{
				memcpy(&dbField, pfield, sizeof(DBFIELD));
				break;
			}
		}
		if(dbField.f_len==0)
			return false;

		MAPVTR MapVtr;
		MapVtr.clear();
		//����������Ϣ
		int count = pdata.size();
		for(i=0; i<count; i++)
		{
			SEARCHMAP* pMap=new SEARCHMAP;
			pMap->pRec = pdata.at(i);
			//		memcpy(&pMap->field, &(memtable->tbl->field+m_sortfield)->field, sizeof(DBFIELD));
			pMap->f_type = dbField.f_type;				//��������
			pMap->f_len = dbField.f_len;				//�򳤶�
			pMap->f_offset = dbField.f_offset;			//�ֽ�ƫ����
			pMap->isasc = true;
			MapVtr.push_back(pMap);
		}

		std::sort(MapVtr.begin(),MapVtr.end(),CmpSearch);

		if(!SearchOneObject(value, sdata, MapVtr, dbField))
		{
			//�ͷſռ�
			count = MapVtr.size();
			for(i=0; i<count; i++)
			{
				SEARCHMAP* ptemp = NULL;
				ptemp = MapVtr.at(i);
				if(ptemp!=NULL)
				{
					delete ptemp;
					ptemp=NULL;
				}
			}
			MapVtr.clear();

			return false;
		}
		//�ͷſռ�
		count = MapVtr.size();
		for(i=0; i<count; i++)
		{
			SEARCHMAP* ptemp = NULL;
			ptemp = MapVtr.at(i);
			if(ptemp!=NULL)
			{
				delete ptemp;
				ptemp=NULL;
			}
		}
		MapVtr.clear();
	}

	return true;
}

bool CRealSearch::SearchObject(char *pDB,char *pTable, char* sql, char* order,  DATAVTR* vdata)
{
	if(pDB==NULL||pTable==NULL||sql==NULL||order==NULL||vdata==NULL)
		return false;
	
	m_subdatapos.RemoveAll();

	DWORD idi;
	if(!LSI_GetTableID(pDB,pTable,idi)) return false;
	int tbAdd=LOWORD(idi);
	MEMTABLE* memtable = NULL;
	memtable=(MEMTABLE *)LSI_GetTableAdd(tbAdd);
	if(memtable==NULL) return false;

	//��ȡ�ֶ���Ϣ
	m_datalen = memtable->reclen;

	//��ȡ��ǰ���ֶ���Ϣ
	ReleaseInfo();
	//��¼����
	int recn = memtable->userec;
	for(int i=0; i<recn; i++)
	{
		char* ponedata = NULL;
		ponedata = new char[m_datalen];
		memset(ponedata, 0, sizeof(char)*m_datalen);
		memcpy(ponedata, memtable->data+i*m_datalen, m_datalen);
		DATAMAP* pdata = new DATAMAP;
		pdata->pdata = ponedata;
		pdata->pos = i;
		m_alldatavtr.push_back(pdata);
	}

	int fieldnum = memtable->tbl->n_fd;
	for(i=0; i<fieldnum; i++)
	{
		M_DBFIELD* pfield=NULL;
		pfield = memtable->tbl->field+i;
		if(pfield==NULL)
			break;

		DBFIELD* pnewfield;
		pnewfield = new DBFIELD;
		memcpy(pnewfield, &pfield->field, sizeof(DBFIELD));
		m_curField.Add(pnewfield);
	}
	if(m_curField.GetSize()<=0)
		return false;
	
	//���ֶβ�ѯ
	CStringArray sqlarray;
	if(strlen(sql)>2)
	{
		CString szsql(sql);
		int pos = szsql.Find("&");
		while(pos!=-1)
		{
			CString subsql = szsql.Left(pos);
			sqlarray.Add(subsql);
			szsql = szsql.Mid(pos+1);
			pos = szsql.Find("&");
		}
		sqlarray.Add(szsql);

		if(sqlarray.GetSize()>0)
		{
			int count = sqlarray.GetSize();
			for(int i=0; i<count; i++)
			{
				szsql = sqlarray.GetAt(i);
			}
		}
	}

	DATAMAPVTR* tmpdata;
	DATAMAPVTR subdata;
	subdata.clear();
	tmpdata = &m_alldatavtr;
	if(sqlarray.GetSize()<=0)
	{
		if(!SearchSubObject(*tmpdata, "", &subdata))
			return false;
	}
	else
	{
		CString szsql = sqlarray[0];
		if(!SearchSubObject(*tmpdata, szsql, &subdata))
			return false;
	}

	tmpdata = &subdata;
	for(i=1; i<sqlarray.GetSize(); i++)
	{
		CString szsql = sqlarray[i];
		if(!SearchSubObject(*tmpdata, szsql, &subdata))
			return false;
		tmpdata = &subdata;
	}
	
	//�������
	if(strlen(order)>=2)
	{
		CStringArray orderarray;
		CString szorder(order);
		int pos = szorder.Find(",");
		while(pos!=-1)
		{
			CString subszorder = szorder.Left(pos);
			orderarray.Add(subszorder);
			szorder = szorder.Mid(pos+1);
			pos = szorder.Find(",");
		}
		orderarray.Add(szorder);
		RefreshSort(&subdata, szorder);
	}
	
	vdata->clear();
	for(i=0; i<subdata.size(); i++)
	{
/*		char* temp = new char[m_datalen];
		memset(temp, 0, m_datalen);
		void* pdata = subdata.at(i);
		memcpy(temp, pdata, m_datalen);*/
		vdata->push_back(subdata.at(i)->pdata);
		m_subdatapos.Add(subdata.at(i)->pos);
	}

	return true;
}

//sampdata�������ݣ�field�����ֶΣ�pos�����������ڶ���λ��
void CRealSearch::GetMulData(MAPVTR MapVtr, char* sampdata, DBFIELD field, long pos, DATAMAPVTR* vdata)
{
	if(sampdata==NULL)
		return;

	//����Ѱ��
	long newpos = pos-1;
	while(newpos>=0)
	{
		char* temp = (char*)MapVtr[newpos]->pRec->pdata+field.f_offset;
		if(memcmp(sampdata, temp, field.f_len)==0)
			vdata->push_back(MapVtr[newpos]->pRec);
		else
			break;
		newpos--;
	}

	//����Ѱ��
	newpos = pos+1;
	while(newpos<=MapVtr.size()-1)
	{
		char* temp = (char*)MapVtr[newpos]->pRec->pdata+field.f_offset;
		if(memcmp(sampdata, temp, field.f_len)==0)
			vdata->push_back(MapVtr[newpos]->pRec);
		else
			break;
		newpos++;
	}
}

bool CmpSearch(const SEARCHMAP* pOne, const SEARCHMAP* pTwo)
{
	bool iCompare = false;
	if(pOne==NULL||pTwo==NULL)
		return iCompare;
	if(pOne->pRec==NULL||pTwo->pRec==NULL)
		return iCompare;

	char *pOnedata, *pTwodata;
//	pOnedata = (char*)pOne->pRec+pOne->field.f_offset;
//	pTwodata = (char*)pTwo->pRec+pTwo->field.f_offset;
	pOnedata = (char*)pOne->pRec->pdata+pOne->f_offset;
	pTwodata = (char*)pTwo->pRec->pdata+pOne->f_offset;
	if(pOnedata==pTwodata)
		return iCompare;

	bool isasc = pOne->isasc;
	BYTE datatype = pOne->f_type;
	try
	{
		switch(datatype)
		{
		case  DB_CHAR:
			{
				if(isasc)
					iCompare=(strcmp(pOnedata, pTwodata)<0)?true:false;
				else
					iCompare=(strcmp(pOnedata, pTwodata)>0)?true:false;
			break;
			}
		case  DB_BYTE:
			{
				BYTE bdata[2];
				bdata[0]= *(BYTE*)pOnedata;
				bdata[1]= *(BYTE*)pTwodata;
				if(isasc)
					iCompare=bdata[0]<bdata[1]?true:false;
				else
					iCompare=bdata[0]>bdata[1]?true:false;
				break;
			}
		case  DB_SHORT:
			{
				short sdata[2];
				sdata[0]= *(short*)pOnedata;
				sdata[1]= *(short*)pTwodata;
				iCompare=sdata[0]<sdata[1]?true:false;
				break;
			}
		case  DB_WORD:
			{
				WORD wdata[2];
				wdata[0] = *((WORD*)pOnedata);
				wdata[1] = *((WORD*)pTwodata);
				iCompare=wdata[0]<wdata[1]?true:false;
				break;
			}
		case  DB_INT:
			{
				int idata[2];
				idata[0] = *(int*)pOnedata;
				idata[1] = *(int*)pTwodata;
				iCompare=idata[0]<idata[1]?true:false;
				break;
			}
		case  DB_DWORD:
			{
				DWORD dwdata[2];
				dwdata[0] = *(DWORD*)pOnedata;
				dwdata[1] = *(DWORD*)pTwodata;
//				TRACE("%d    %d\n", dwdata[0], dwdata[1]);
				iCompare=dwdata[0]<dwdata[1]?true:false;
			}
				break;
		case  DB_FLOAT:
			{
				float fdata[2];
				fdata[0] = *(float*)pOnedata;
				fdata[1] = *(float*)pTwodata;
				iCompare=fdata[0]<fdata[1]?true:false;
				break;
			}
		case  DB_DOUBLE:
			{
				double ddata[2];
				ddata[0] = *(double*)pOnedata;
				ddata[1] = *(double*)pTwodata;
				iCompare=ddata[0]<ddata[1]?true:false;
				break;
			}
		case  DB_DTIME:
		case  DB_DATE:
		case  DB_TIME:
			{
				CTime tdata[2];
				memcpy(&tdata[0], pOnedata, sizeof(CTime));
				memcpy(&tdata[1], pTwodata, sizeof(CTime));
				iCompare=tdata[0]<tdata[1]?true:false;
				break;
			}
		default:
			return iCompare;
		}
	}
	catch(CException* e)
	{
		e->Delete();
		return iCompare;
	}

	return iCompare;
};

//����,����,SQL���("�ֶ���=ֵ&�ֶ���=ֵ", �������ֶ�), ������������,��������
bool SearchData(char* szdb, char* sztable, LPCTSTR szsql, LPCTSTR szorder, void** pdata, int& datanum, CUIntArray& posarray)
{
	posarray.RemoveAll();
	if(szdb==NULL||sztable==NULL||szsql==NULL||szorder==NULL)
		return false;

	if(pdata==NULL)
		return false;
	*pdata=NULL;
	datanum=0;

	DWORD idi;
	if(!LSI_GetTableID(szdb,sztable,idi)) 
		return false;

	CRealSearch  realsearch;

	DATAVTR resultdata;
	if(!realsearch.SearchObject(szdb, sztable, (char*)szsql, (char*)szorder, &resultdata))
		return false;

	datanum = resultdata.size();
	*pdata = new char[datanum*realsearch.m_datalen];
	memset(*pdata, 0, sizeof(char)*datanum*realsearch.m_datalen);

	//��������
	for(int i=0; i<datanum; i++)
	{
		char* ptemp = (char*)resultdata[i];
		memcpy((char*)(*pdata)+i*realsearch.m_datalen, ptemp, sizeof(char)*realsearch.m_datalen);
	}
	posarray.Append(realsearch.m_subdatapos);

/*	for(i=0; i<datanum; i++)
	{
		char* ptemp = (char*)resultdata[i];
		if(ptemp!=NULL)
		{
			delete []ptemp;
		}
	}
	resultdata.clear();*/

	return true;
}

//����,����,SQL���("�ֶ���=ֵ&�ֶ���=ֵ", �������ֶ�), ��Ҫ�޸ĵ�����
bool UpdateData(char* szdb, char* sztable, LPCTSTR szsql, void* pdata)
{
	if(szdb==NULL||sztable==NULL||szsql==NULL||pdata==NULL)
		return false;

	DWORD idi;
	if(!LSI_GetTableID(szdb,sztable,idi)) 
		return false;

	BYTE* ptempdata=NULL;
	int datanum=0;
	CUIntArray posarray;
	SearchData(szdb, sztable, szsql, "", (void**)&ptempdata, datanum, posarray);
	if(datanum!=1)
		return false;

	if(ptempdata==NULL||datanum!=1)
		return false;

	CString tabstr;
	tabstr.Format("%s.%s", szdb, sztable);
	LSI_UpdateARecord(tabstr.GetBuffer(tabstr.GetLength()), pdata, posarray[0]);
	delete []ptempdata;
	return true;
}

bool UpdateData(char* szdb, char* sztable, LPCTSTR szsql, char* szfiled, void* pdata)
{
	if(szdb==NULL||sztable==NULL||szsql==NULL||pdata==NULL||szfiled==NULL)
		return false;

	DWORD idi;
	if(!LSI_GetTableID(szdb,sztable,idi)) 
		return false;

	BYTE* ptempdata=NULL;
	int datanum=0;
	CUIntArray posarray;
	SearchData(szdb, sztable, szsql, "", (void**)&ptempdata, datanum, posarray);
	if(datanum!=1)
		return false;

	if(ptempdata==NULL&&datanum!=1)
		return false;

	LSI_PutColVal(idi, posarray[0], szfiled, pdata);
	delete []ptempdata;
	ptempdata = NULL;
	return true;
}

