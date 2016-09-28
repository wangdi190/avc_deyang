// FileBroker.cpp: implementation of the FileBroker class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FileBroker.h"
#include "settingmanager.h"
//#include "minigzip.h"
//#include "tar.h"
//#include "log.h"
#include "utils.h"
#include <string.h>
#include <direct.h>
#include "BJ_SCFileDLL.h"
#include "ImportService.h"
//#include "..\ArithmeticService\ArithmeticService.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//int g_tmCurDay=0;
//SCADA处理线程
UINT ScadaProcess(LPVOID pParam);
//SCADA处理线程
UINT EmsProcess(LPVOID pParam);
BOOL g_ScadaEnd=TRUE;
BOOL g_EmsEnd=TRUE;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
BOOL findFile(const char* fname, char* finded);
FileBroker::FileBroker()
{

}

FileBroker::~FileBroker()
{

}
typedef char (*FNAME_ARRAY_PTR)[MAX_PATH];
UINT fileBrokerProc(LPVOID);
UINT fileBrokerProc1(LPVOID);
UINT fileBrokerProc22(LPVOID);
void systemTimeToFilePost(char *post);
//int extractTar(const char* tar, 
//			   char (*subFile)[SUB_FILE_NAMELEN], 
//			   int numSubFile,
//			   const char* time,
//			   FNAME_ARRAY_PTR extractedFiles);
BOOL processFile(const char* type, const char* fName);

void initializeFileBroker()
{
	AfxBeginThread(fileBrokerProc, NULL, THREAD_PRIORITY_ABOVE_NORMAL); //SCADA
	AfxBeginThread(fileBrokerProc1, NULL, THREAD_PRIORITY_ABOVE_NORMAL);//EMS
}
UINT fileBrokerProc(LPVOID)
{
	char fname[MAX_PATH];
	CSetting* setting = ::accessSettingForConsume();
	char *type,*src=NULL;
	char timePrefix[50];
	CTime pertime = 0;

	while(TRUE)
	{
		//删除1天前的备份文件
		CTime curtime = CTime::GetCurrentTime();
		if((curtime-pertime).GetDays()>=1)
		{
			pertime = curtime;
			CTime deltime = pertime-CTimeSpan(1,0,0,0);
			FILE_FILTER *filter = setting->GetFilter(0);
			CString delpath(filter->fName);
			delpath = delpath.Left(delpath.ReverseFind('\\')+1);
			delpath += "log\\*.*";
			WIN32_FIND_DATA filedata;
			HANDLE hande = FindFirstFile(delpath, &filedata);
			FindNextFile(hande, &filedata);
			while(hande!=INVALID_HANDLE_VALUE)
			{
				CTime filetime = filedata.ftCreationTime ;
				if(filetime<=deltime)
				{
					CString szfilename(delpath);
					szfilename = szfilename.Left(szfilename.ReverseFind('\\')+1);
					szfilename+=filedata.cFileName;
					unlink(_T(szfilename));
				}
				if(!FindNextFile(hande, &filedata))
					break;
			}
		}//删除1天前的备份文件

		systemTimeToFilePost(timePrefix);
		FILE_FILTER* filter = setting->GetFilter(0);
		type=filter->appType;
		if(!filter)
		{
			Sleep(1000);
			continue;
		}
		
		if(!tryAccessFile(filter->fName, timePrefix, fname, sizeof(fname)))
		{
			Sleep(1000);
			continue;
		}
		incStatus(0);

		if (strcmp(type,"SCADA")==0)
		{
			if(g_ScadaEnd)
			{
				src = fname;
				g_ScadaEnd=FALSE;
				AfxBeginThread(ScadaProcess,(LPVOID)src);
			}
		}
/*		else if(strcmp(type,"EMS")==0)
		{
			if(g_EmsEnd)
			{
				src = fname;
				g_EmsEnd=FALSE;
				AfxBeginThread(EmsProcess,(LPVOID)src);
			}	
		}*/
		if(src!=NULL)
			DeleteOldFile(src,type);
	}

	return 0;
}


UINT fileBrokerProc1(LPVOID)
{
	char fname[MAX_PATH];
	CSetting* setting = ::accessSettingForConsume();
	char *type,*src=NULL;
	char timePrefix[50];

	while(TRUE)
	{
		systemTimeToFilePost(timePrefix);
		FILE_FILTER* filter = setting->GetFilter(1);
		type=filter->appType;
		if(!filter)
		{
			Sleep(1000);
			continue;
		}
		
		if(!tryAccessFile(filter->fName, timePrefix, fname, sizeof(fname)))
		{
			Sleep(1000);
			continue;
		}
		incStatus(1);

		if (strcmp(type,"SCADA")==0)
		{
			if(g_ScadaEnd)
			{
				src = fname;
				g_ScadaEnd=FALSE;
				AfxBeginThread(ScadaProcess,(LPVOID)src);
			}
		}
		else if(strcmp(type,"EMS")==0)
		{
			if(g_EmsEnd)
			{
				src = fname;
				g_EmsEnd=FALSE;
				AfxBeginThread(EmsProcess,(LPVOID)src);
			}	
		}
		if(src!=NULL)
			DeleteOldFile(src,type);
	}

	return 0;
}
UINT fileBrokerProc22(LPVOID)
{
	char fname[MAX_PATH];
	while(TRUE)
	{
		DWORD startTime = GetTickCount();
		CSetting* setting = ::accessSettingForConsume();
		FILE_FILTER* filter = setting->GetFilter(0);

		char timePrefix[50];
		systemTimeToFilePost(timePrefix);

		for(int iSetting = 0; iSetting < setting->GetSize(); iSetting++)
		{
			FILE_FILTER *filter = setting->GetFilter(iSetting);
			if(!filter)
				continue;
			if(!tryAccessFile(filter->fName, timePrefix, fname, sizeof(fname)))
				continue;
			char* src = fname;
			
		//	DeleteOldFile(src,type);//lcx

			if((filter->format & FILE_TAR) == 0)
			{
				BOOL bResult=processFile(filter->appType, src);
				incStatus(iSetting);
			}
			else
			{
				int count = 0;
				for(int i = 0; i < MAX_SUB_FILE; i++)
				{
					if(filter->subFile[i][0] == 0)
						break;
					count++;
				}
				BOOL tarAsFolder = TRUE;
				if(count == 0)
				{
					count++;
					tarAsFolder = FALSE;
				}

				FNAME_ARRAY_PTR extractedFiles = NULL;
				int extracted = 0;
				extractedFiles = (FNAME_ARRAY_PTR)malloc(count*MAX_PATH);
				if(extracted < count)
				{
					char allFiles[300];
					char base[MAX_PATH];
					char *p;
					allFiles[0] = 0;
					p = allFiles;
					for(int i = 0; i < extracted; i++)
					{
						splitFName(extractedFiles[i], NULL, base);
						c_strncpy(p, base, sizeof(allFiles) - (p-allFiles));
						p += strlen(p);
						if(sizeof(allFiles) - (p-allFiles) >= 2)
						{
							*p++ = ',';
							*p = 0;
						}
						else
							break;
					}
				}
				if(!tarAsFolder)
				{
					for(int idx = 0; idx < extracted; idx++)
					{
						BOOL bResult=processFile(filter->appType, extractedFiles[idx]);
						incStatus(iSetting);
					}
				}
				else
				{
					if(extracted > 0)
					{
						char dir[MAX_PATH];
						splitFName(src, dir, NULL);
						BOOL bResult=processFile(filter->appType, dir);
						incStatus(iSetting);
	
					//	DeleteOldFile(src,type);
					}
				}
				free(extractedFiles);
				
			}
		}
		int elapse = GetTickCount() - startTime;
		Sleep(1000);
	}

	return 0;
}


BOOL tryAccessFile(const char* fnameLocate, const char* time, char* fAccessed, int size)
{
	char fname[MAX_PATH];
	char path[MAX_PATH];
	char name[MAX_PATH];
	const char *strs[] = {path, "log\\", time,  name};
	if(!findFile(fnameLocate, fname))
		return FALSE;
	
	::splitFName(fname, path, name);

	char *p = fAccessed;
	for(int i = 0; i < sizeof(strs)/sizeof(strs[0]); i++)
	{
		int cp = strlen(strs[i]);
		if(cp >= size)
		{
		//	log_error("文件名太长%s\n", fname);
			return FALSE;
		}
		memcpy(p, strs[i], cp);
		p += cp;
		size -= cp;
	}
	*p = 0;
	strcat(path, "log\\");
	if(!findFile(path, NULL))
		_mkdir(path);
	if(MoveFile(fname, fAccessed))
		return TRUE;
	return FALSE;
}
BOOL findFile(const char* fname, char* finded)
{
	WIN32_FIND_DATA data;
	memset(&data, 0, sizeof(data));
	HANDLE handle = FindFirstFile(fname, &data);
	if(handle != INVALID_HANDLE_VALUE)
	{
		if(finded)
		{
			splitFName(fname, finded, NULL);
			strcat(finded, data.cFileName);
		}
		FindClose(handle);
		return TRUE;
	}
	return FALSE;
}
void systemTimeToFilePost(char *post)
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	sprintf(post, "%04d%02d%02d%02d%02d%02d", tm.wYear, tm.wMonth, tm.wDay, tm.wHour,tm.wMinute,tm.wSecond);
}



BOOL processFile(const char* type, const char* fName)
{
	if (strcmp(type,"SCADA")==0)
	{
		if(g_ScadaEnd)
		{
		   g_ScadaEnd=FALSE;
		   AfxBeginThread(ScadaProcess,(LPVOID)fName);
		}
	}
	if(strcmp(type,"EMS")==0)
	{
		if(g_EmsEnd)
		{
		   g_EmsEnd=FALSE;
		   AfxBeginThread(EmsProcess,(LPVOID)fName);
		}	
	}
	return true;
}

BOOL runCtgAnalyse(time_t tmIntime)
{
	TCHAR fullpath[256];
	if(GetModuleFileName(NULL,fullpath,256)==0)
		return FALSE;
	char *last=strrchr(fullpath,'\\');
	if(last==NULL)
		return FALSE;
	*(last+1)=0;
	strcat(fullpath,"temp_ctg.out");

	char tmData[256];
	time(&tmIntime);
	strftime(tmData,256,"%Y-%m-%d %H:%M:%S",localtime(&tmIntime));
	NT_FileOutCtgInput(fullpath,3,tmData);
	return TRUE;
}

//删除老的未删除的数据文件
void DeleteOldFile(char* pszFileName,char* type)
{
	CTime tmCur=CTime::GetCurrentTime();
	CTime tm;
/*	if(g_tmCurDay==0)
	{
		g_tmCurDay=tmCur.GetDay();
		return;
	}
	else if(g_tmCurDay==tmCur.GetDay())
		return;
	else
		g_tmCurDay=tmCur.GetDay();
	if(g_tmCurDay==0)
		g_tmCurDay=tmCur.GetDay();
	else if(g_tmCurDay!=tmCur.GetDay())
		g_tmCurDay=tmCur.GetDay();
*/
	if(tmCur.GetHour()>=1)
		return;
	if(tmCur.GetMinute()>10)
		return;
	char szPath[256];
	strcpy(szPath,pszFileName);
	char* pszEnd=strrchr(szPath,'\\');
	*(pszEnd+1)=0;

	CString strFile;
	if(strcmp(type,"rtdata")==0)
	{
		strFile.Format("%s*.dt",szPath);
		tm=tmCur-CTimeSpan(10,0,0,0);    //设置删除好久之前的文件（单位：天）
		CString strName=tm.Format("%Y%m%d");
		long lTwoWeekDate=atol((LPCSTR)strName);
		CFileFind find;
		BOOL bFind=find.FindFile(strFile);
		while(bFind)
		{
			bFind=find.FindNextFile();
			strFile=find.GetFileName();
			strName=strFile.Left(8);
			if(strName.GetLength()<8)
				continue;
			
			BOOL bNotDate=FALSE;
			LPCSTR lpName=(LPCSTR)strName;
			for(int i=0;i<8;i++)
			{
				if(lpName[i]<'0'||lpName[i]>'9')
				{
					bNotDate=TRUE;
					break;
				}
			}
			if(bNotDate)
				continue;
			long lFileDate=atol((LPCSTR)strName);
			if(lTwoWeekDate>lFileDate)
			{
				char szFile[512];
				sprintf(szFile,"%s%s",szPath,strFile);
				unlink(szFile);
			}
		}
		find.Close();
	}

  

	else if(strcmp(type,"sedata")==0)
	{
		strFile.Format("%s*.txt",szPath);
		tm=tmCur-CTimeSpan(10,0,0,0); //设置删除好久之前的文件（单位：天）
		CString strName=tm.Format("%Y%m%d");
		long lTwoWeekDate=atol((LPCSTR)strName);
		CFileFind find;
		BOOL bFind=find.FindFile(strFile);
		while(bFind)
		{
			bFind=find.FindNextFile();
			strFile=find.GetFileName();
			strName=strFile.Left(8);
			if(strName.GetLength()<8)
				continue;
			
			BOOL bNotDate=FALSE;
			LPCSTR lpName=(LPCSTR)strName;
			for(int i=0;i<8;i++)
			{
				if(lpName[i]<'0'||lpName[i]>'9')
				{
					bNotDate=TRUE;
					break;
				}
			}
			if(bNotDate)
				continue;
			long lFileDate=atol((LPCSTR)strName);
			if(lTwoWeekDate>lFileDate)
			{
				char szFile[512];
				sprintf(szFile,"%s%s",szPath,strFile);
				unlink(szFile);
			}
		}
		find.Close();
	}
}

//SCADA处理线程
UINT ScadaProcess(LPVOID pParam)
{
	/*char *pFileName1=(char*)pParam;
	char *temp1=strrchr(pFileName1,'\\');
	char *pFileName2={0};
	strncpy(temp1,pFileName1,temp1-pFileName1);

	char *temp2=strrchr(pFileName2,'\\');
	char *pFileName3;
	strncpy(pFileName3,pFileName2,temp2-pFileName2);

	char *temp3=strrchr(pFileName3,'\\');
	char *pFileName4;
	strncpy(pFileName4,pFileName3,temp3-pFileName3);

	char *temp4=strrchr(pFileName4,'\\');
	char *pFileName5;
	strncpy(pFileName5,pFileName4,temp4-pFileName4);
*/

	char* pFileName=(char*)pParam;
	ImportMeasure(pFileName);
	g_ScadaEnd=TRUE;
	return 0;
}

//Ems处理线程
UINT EmsProcess(LPVOID pParam)
{
	time_t intime=0;
	char* pFileName=(char*)pParam;
//	intime=CreateInputFile(pFileName);
	if(intime>0)//基本潮流收敛时才计算
		runCtgAnalyse(intime);
	g_EmsEnd=TRUE;
	return 0;
}