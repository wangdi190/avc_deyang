// Utils.cpp: implementation of the Utils class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Utils.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include <direct.h>

#define is_space(c) \
	(((c) == ' ') || ((c) == '\r') || ((c) == '\n') || ((c) == '\t'))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
void FormatDate(SYSTEMTIME& time, char* sz)
{
	sprintf(sz, "%d-%02d-%02d", time.wYear, time.wMonth, time.wDay);
}
void FormatTime(SYSTEMTIME& time, char* sz)
{
	sprintf(sz, "%02d:%02d:%02d", time.wHour, time.wMinute, time.wSecond);
}

char* getExePath(char* path)
{
		char file [MAX_PATH];
		GetModuleFileName(NULL, file, sizeof(file));
		splitFName(file, path, NULL);
		return path;
}

char* trim_whites(char *s)

{
	char *from = s;
	while(*from)
	{
		if(!is_space(*from))
			break;
		from++;
	}
	char* to = from+strlen(from) - 1;
	while(to >= from)
	{
		if(!is_space(*to))
			break;
		to--;
	}
	*(to+1) = 0;
	return from;
}

char* c_strncpy(char* dest, const char* src, int size)
{
	strncpy(dest, src, size-1);
	dest[size-1] = 0;
	return dest;
}

void ErrMessage(DWORD error)
{
	LPVOID lpMsgBuf;
	FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM | 
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		error,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf,
		0,
		NULL 
	);
	// Process any inserts in lpMsgBuf.
	// ...
	// Display the string.
	MessageBox( NULL, (LPCTSTR)lpMsgBuf, "Error", MB_OK | MB_ICONINFORMATION );
	// Free the buffer.
	LocalFree( lpMsgBuf );
}


void splitFName(const char* fname, char* dir, char* basename)
{
	char* p = strrchr(fname, '\\');
	if(!p)
		p = strrchr(fname,'/');
	if(p == NULL)
	{
		if(dir)
			*dir = 0;
		if(basename)
			strcpy(basename, fname);
	}
	else
	{
		p++;
		if(dir)
		{
			memcpy(dir, fname, p - fname);
			dir[p - fname] = 0;
		}
		if(basename)
			strcpy(basename, p);
	}
}

/*bool split2(const char* s, char c, char*d1, char* d2); //host in cim reader
void splitBaseName(const char* baseName,  char* name, char* postfix)
{
	if(!split2(baseName,'.', name, postfix))
	{
		strcpy(name, baseName);
		*postfix = 0;
	}
}
*/
char* basename(char* fullName)
{
	char* p = strrchr(fullName, '/');
	if(!p)
		p = strrchr(fullName, '\\');
	if(!p)
		p = fullName;
	else
		p = p+1;
	return p;
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

void GetDevName(DWORD id, BYTE devtype, char* devname)
{
	if(devname==NULL||id<=0)
		return;
	devname[0]=0;
	if(strlen(DevTableName[devtype])<2)
		return;

	BYTE* ptempdata=NULL;
	int datanum=0;
	CUIntArray posarray;
	CString szsql;
	szsql.Format("NU=%d", id);
	while(1)
	{
		if(!SearchData("visualpw", (char*)DevTableName[devtype], szsql, "", (void**)&ptempdata, datanum, posarray))
		{
			if(devtype==EQUIP_TYPE_BITRS)
			{
				devtype=EQUIP_TYPE_TRITRS;
				if(!SearchData("visualpw", (char*)DevTableName[devtype], szsql, "", (void**)&ptempdata, datanum, posarray))
					return;
			}
			else
				return;
		}

		if(ptempdata==NULL)
			return;
		switch(devtype)
		{
		case EQUIP_TYPE_GEN:	//发电机
			{
				visualpw_Gen* pgen = (visualpw_Gen*)ptempdata;
				strcat(devname, pgen->Name);
				break;
			}
		case EQUIP_TYPE_BUS:	//母线
			{
				visualpw_Bus* pbus = (visualpw_Bus*)ptempdata;
				strcat(devname, pbus->Name);
				break;
			}
		case EQUIP_TYPE_LINE:	//线路
			{
				visualpw_Line* pline = (visualpw_Line*)ptempdata;
				strcat(devname, pline->Name);
				break;
			}
		case EQUIP_TYPE_BITRS:	//双绕组变
			{
				visualpw_Tfm1* ptfm = (visualpw_Tfm1*)ptempdata;
				strcat(devname, ptfm->Name);
				break;
			}
		case EQUIP_TYPE_TRITRS://三绕组变
			{
				visualpw_Tfm2* ptfm = (visualpw_Tfm2*)ptempdata;
				strcat(devname, ptfm->Name);
				break;
			}
		case EQUIP_TYPE_LOAD:	//负荷
			{
				visualpw_Load* pload = (visualpw_Load*)ptempdata;
				strcat(devname, pload->Name);
				break;
			}
		case EQUIP_TYPE_SHUNT:	//并联无功设备
			{
				visualpw_Shunt* pshunt = (visualpw_Shunt*)ptempdata;
				strcat(devname, pshunt->Name);
				break;
			}
		case EQUIP_TYPE_SWITCH://开关
			{
				visualpw_Switch* pbreak = (visualpw_Switch*)ptempdata;
				strcat(devname, pbreak->Name);
				break;
			}
		case EQUIP_TYPE_DCLINE://直流线路
		case EQUIP_TYPE_REACT://电抗器
			break;
		case EQUIP_TYPE_SUB: //厂站
			{
				visualpw_Station* pstation = (visualpw_Station*)ptempdata;
				strcat(devname, pstation->Name);
				break;
			}
		case EQUIP_TYPE_AREA: //区域
			{
				visualpw_Zone* pzone = (visualpw_Zone*)ptempdata;
				strcat(devname, pzone->Name);
				break;
			}
		default:
			break;
		}
		break;
	}
	if(ptempdata!=NULL)
		delete []ptempdata;
	ptempdata=NULL;
}

void GetIDByName(char* devname, BYTE devtype, DWORD& id)			//厂站ID	
{
	if(devname==NULL)
		return;
	id=0;

	if(strlen(DevTableName[devtype])<2)
		return;

	BYTE* ptempdata=NULL;
	int datanum=0;
	CUIntArray posarray;
	CString szsql;
	szsql.Format("Name=%s", devname);
	szsql.TrimLeft();
	szsql.TrimRight();
	while(1)
	{
		if(!SearchData("visualpw", (char*)DevTableName[devtype], szsql, "", (void**)&ptempdata, datanum, posarray))
		{
			if(devtype==EQUIP_TYPE_BITRS)
			{
				devtype=EQUIP_TYPE_TRITRS;
				if(!SearchData("visualpw", (char*)DevTableName[devtype], szsql, "", (void**)&ptempdata, datanum, posarray))
					return;
			}
			else
				return;
		}

		if(ptempdata==NULL)
			return;
		switch(devtype)
		{
		case EQUIP_TYPE_GEN:	//发电机
			{
				visualpw_Gen* pgen = (visualpw_Gen*)ptempdata;
				id=pgen->NU;
				break;
			}
		case EQUIP_TYPE_BUS:	//母线
			{
				visualpw_Bus* pbus = (visualpw_Bus*)ptempdata;
				id=pbus->NU;
				break;
			}
		case EQUIP_TYPE_LINE:	//线路
			{
				visualpw_Line* pline = (visualpw_Line*)ptempdata;
				id=pline->NU;
				break;
			}
		case EQUIP_TYPE_BITRS:	//双绕组变
			{
				visualpw_Tfm1* ptfm = (visualpw_Tfm1*)ptempdata;
				id=ptfm->NU;
				break;
			}
		case EQUIP_TYPE_TRITRS://三绕组变
			{
				visualpw_Tfm2* ptfm = (visualpw_Tfm2*)ptempdata;
				id=ptfm->NU;
				break;
			}
		case EQUIP_TYPE_LOAD:	//负荷
			{
				visualpw_Load* pload = (visualpw_Load*)ptempdata;
				id=pload->NU;
				break;
			}
		case EQUIP_TYPE_SHUNT:	//并联无功设备
			{
				visualpw_Shunt* pshunt = (visualpw_Shunt*)ptempdata;
				id=pshunt->NU;
				break;
			}
		case EQUIP_TYPE_SWITCH://开关
			{
				visualpw_Switch* pbreak = (visualpw_Switch*)ptempdata;
				id=pbreak->NU;
				break;
			}
		case EQUIP_TYPE_DCLINE://直流线路
		case EQUIP_TYPE_REACT://电抗器
			break;
		case EQUIP_TYPE_SUB: //厂站
			{
				visualpw_Station* pstation = (visualpw_Station*)ptempdata;
				id=pstation->NU;
				break;
			}
		case EQUIP_TYPE_AREA: //区域
			{
				visualpw_Zone* pzone = (visualpw_Zone*)ptempdata;
				id=pzone->NU;
				break;
			}
		default:
			break;
		}
		break;
	}
	if(ptempdata!=NULL)
		delete []ptempdata;
	ptempdata=NULL;
}

bool LoadSystemLimit(CPtrArray& m_syslimit)
{
	ClearSysLimit(m_syslimit);

	CTime curtm = CTime::GetCurrentTime();
	CTimeSpan spantime = curtm-CTime(curtm.GetYear(), curtm.GetMonth(), curtm.GetDay(),0,0,0);
	LONG Curseconds = spantime.GetTotalSeconds();

	void* m_char = NULL;
	int recnum = 0;
	CUIntArray posarray;

	char szdb[32]={"ScadaAVC"};

	if(SearchData(szdb, "AVCRunParam", "", "srttm", (void**)&m_char, recnum, posarray))
	{
		_AVCLimit* pnew[6];
		pnew[0]= new _AVCLimit();
		pnew[1]= new _AVCLimit();
		pnew[2]= new _AVCLimit();
		pnew[3]= new _AVCLimit();
		pnew[4]= new _AVCLimit();
		pnew[5]= new _AVCLimit();

		ScadaAVC_AVCRunParam* prun = (ScadaAVC_AVCRunParam*)m_char;
		for(int i=0;  i<recnum; i++)
		{
			ScadaAVC_AVCRunParam* ptmp = prun+i;
			if(ptmp==NULL)
				continue;

			for(int n=0; n<6; n++)
			{
				pnew[n]->m_limit[i].nu=0;
				pnew[n]->m_limit[i].startt=ptmp->srttm;
				pnew[n]->m_limit[i].endt=ptmp->endtm;
				pnew[n]->m_limit[i].cosdn=ptmp->SCosDn;
				pnew[n]->m_limit[i].cosup=ptmp->SCosUp;
				pnew[n]->m_limit[i].gcosdn=ptmp->CosDn;
				pnew[n]->m_limit[i].gcosup=ptmp->CosUp;
				pnew[n]->m_limit[i].capnum=ptmp->CPNum;
				pnew[n]->m_limit[i].xfmnum=ptmp->XfrNum;
			}
			pnew[0]->m_limit[i].bvol=6.0;
			pnew[0]->m_limit[i].voldn=ptmp->V6Dn;
			pnew[0]->m_limit[i].volup=ptmp->V6Up;

			pnew[1]->m_limit[i].bvol=10.0;
			pnew[1]->m_limit[i].voldn=ptmp->V10Dn;
			pnew[1]->m_limit[i].volup=ptmp->V10Up;

			pnew[2]->m_limit[i].bvol=35.0;
			pnew[2]->m_limit[i].voldn=ptmp->V35Dn;
			pnew[2]->m_limit[i].volup=ptmp->V35Up;

			pnew[3]->m_limit[i].bvol=110.0;
			pnew[3]->m_limit[i].voldn=ptmp->V110Dn;
			pnew[3]->m_limit[i].volup=ptmp->V110Up;

			pnew[4]->m_limit[i].bvol=220.0;
			pnew[4]->m_limit[i].voldn=ptmp->V220Dn;
			pnew[4]->m_limit[i].volup=ptmp->V220Up;

			pnew[5]->m_limit[i].bvol=330.0;
			pnew[5]->m_limit[i].voldn=ptmp->V330Dn;
			pnew[5]->m_limit[i].volup=ptmp->V330Up;

		}
			for(int n=0; n<6; n++)
			{
				m_syslimit.Add(pnew[n]);
			}
		if(m_char!=NULL)
			delete []m_char;
		m_char=NULL;

	}
	else
		return false;

	if(SearchData(szdb, "AVCTimePart", "", "", (void**)&m_char, recnum, posarray))
	{
		ScadaAVC_AVCTimePart* ptpart = (ScadaAVC_AVCTimePart*)m_char;
		for(int i=0;  i<recnum; i++)
		{
			ScadaAVC_AVCTimePart* ptmp = ptpart+i;
			if(ptmp==NULL)
				continue;
			_AVCLimit* pnew = new _AVCLimit();
			
			pnew->m_limit[0].nu=ptmp->ID;
			pnew->m_limit[0].bvol=0.0;
			pnew->m_limit[0].startt=CTime(2000,1,1,0,0,0);
			pnew->m_limit[0].endt=ptmp->Tm1;
			pnew->m_limit[0].voldn=ptmp->VDn1;
			pnew->m_limit[0].volup=ptmp->VUp1;
			pnew->m_limit[0].cosdn=ptmp->CosDn1;
			pnew->m_limit[0].cosup=ptmp->CosUp1;
			pnew->m_limit[0].capnum=ptmp->CP_Num1;
			pnew->m_limit[0].xfmnum=ptmp->XF_Num1;

			pnew->m_limit[1].nu=ptmp->ID;
			pnew->m_limit[1].bvol=0.0;
			pnew->m_limit[1].startt=ptmp->Tm1;
			pnew->m_limit[1].endt=ptmp->Tm2;
			pnew->m_limit[1].voldn=ptmp->VDn2;
			pnew->m_limit[1].volup=ptmp->VUp2;
			pnew->m_limit[1].cosdn=ptmp->CosDn2;
			pnew->m_limit[1].cosup=ptmp->CosUp2;
			pnew->m_limit[1].capnum=ptmp->CP_Num2;
			pnew->m_limit[1].xfmnum=ptmp->XF_Num2;

			pnew->m_limit[2].nu=ptmp->ID;
			pnew->m_limit[2].bvol=0.0;
			pnew->m_limit[2].startt=ptmp->Tm2;
			pnew->m_limit[2].endt=ptmp->Tm3;
			pnew->m_limit[2].voldn=ptmp->VDn3;
			pnew->m_limit[2].volup=ptmp->VUp3;
			pnew->m_limit[2].cosdn=ptmp->CosDn3;
			pnew->m_limit[2].cosup=ptmp->CosUp3;
			pnew->m_limit[2].capnum=ptmp->CP_Num3;
			pnew->m_limit[2].xfmnum=ptmp->XF_Num3;

			pnew->m_limit[3].nu=ptmp->ID;
			pnew->m_limit[3].bvol=0.0;
			pnew->m_limit[3].startt=ptmp->Tm3;
			pnew->m_limit[3].endt=ptmp->Tm4;
			pnew->m_limit[3].voldn=ptmp->VDn4;
			pnew->m_limit[3].volup=ptmp->VUp4;
			pnew->m_limit[3].cosdn=ptmp->CosDn4;
			pnew->m_limit[3].cosup=ptmp->CosUp4;
			pnew->m_limit[3].capnum=ptmp->CP_Num4;
			pnew->m_limit[3].xfmnum=ptmp->XF_Num4;

			pnew->m_limit[4].nu=ptmp->ID;
			pnew->m_limit[4].bvol=0.0;
			pnew->m_limit[4].startt=ptmp->Tm4;
			pnew->m_limit[4].endt=ptmp->Tm5;
			pnew->m_limit[4].voldn=ptmp->VDn5;
			pnew->m_limit[4].volup=ptmp->VUp5;
			pnew->m_limit[4].cosdn=ptmp->CosDn5;
			pnew->m_limit[4].cosup=ptmp->CosUp5;
			pnew->m_limit[4].capnum=ptmp->CP_Num5;
			pnew->m_limit[4].xfmnum=ptmp->XF_Num5;

			pnew->m_limit[5].nu=ptmp->ID;
			pnew->m_limit[5].bvol=0.0;
			pnew->m_limit[5].startt=ptmp->Tm5;
			pnew->m_limit[5].endt=CTime(2000,1,1,23,59,59);
			pnew->m_limit[5].voldn=ptmp->VDn6;
			pnew->m_limit[5].volup=ptmp->VUp6;
			pnew->m_limit[5].cosdn=ptmp->CosDn6;
			pnew->m_limit[5].cosup=ptmp->CosUp6;
			pnew->m_limit[5].capnum=ptmp->CP_Num6;
			pnew->m_limit[5].xfmnum=ptmp->XF_Num6;

			m_syslimit.Add(pnew);
		}
		if(m_char!=NULL)
			delete []m_char;
		m_char=NULL;
	}
	else
		return false;
	return true;
}

bool GetVolLimit(CPtrArray& m_syslimit, DWORD pltyp, float* flimit, float vl, CTime curtime, bool isgate)
{
	memset(flimit, 0, sizeof(float)*4);

	AVCLimitParam* plimit = NULL;
	CTime curtm=CTime(2000,1,1, curtime.GetHour(), curtime.GetMinute(), curtime.GetSecond());
	CString sztext;

	int count = m_syslimit.GetSize();
	for(int i=0; i<count; i++)
	{
		_AVCLimit* ptmp = (_AVCLimit*)m_syslimit.GetAt(i);
		if(ptmp==NULL)
			continue;

		bool isfind=false;
		for(int n=0; n<7; n++)
		{
			AVCLimitParam* psublimit = &ptmp->m_limit[n];
			if(psublimit->nu!=pltyp)
				break;

			sztext.Format("%s,%s-%s", curtm.Format("%Y-%m-%d %H:%M:%S"), psublimit->startt.Format("%Y-%m-%d %H:%M:%S"), psublimit->endt.Format("%Y-%m-%d %H:%M:%S"));
			if(curtm<psublimit->startt||curtm>psublimit->endt)
				continue;

			if(pltyp==0&&vl>0.5)
			{
				if(pltyp==0&&fabs(vl-psublimit->bvol)/psublimit->bvol>0.12)
					continue;
			}
			plimit=psublimit;
			isfind=true;
			break;
		}

		if(isfind==false)
			continue;
		else
			break;


		/*if(devtype==EQUIP_TYPE_BUS)
		{
			if(fabs(vl-ptmp->bvol)/ptmp->bvol>0.12)
				continue;
		}*/
		break;
	}

	if(plimit!=NULL)
	{
		flimit[0]=plimit->volup;						//电压上限
		flimit[1]=plimit->voldn;						//电压下限
		if(isgate==true)
		{
			flimit[2]=plimit->gcosup;						//功率上限
			flimit[3]=plimit->gcosdn;						//功率下限
		}
		else
		{
			flimit[2]=plimit->cosup;						//功率上限
			flimit[3]=plimit->cosdn;						//功率下限
		}
		return true;
	}
	return false ;

/*	if(flimit==NULL)
		return false;

	memset(flimit, 0, sizeof(float)*4);

	if(pltyp<0)
		return false;

	float Volup=0.0;						//电压上限
	float Voldn=0.0;						//电压下限
	float Cosup=0.0;						//功率上限
	float Cosdn=0.0;						//功率下限
	bool Isfind=false;

	CTime curtm = CTime::GetCurrentTime();
	CTimeSpan spantime = curtm-CTime(curtm.GetYear(), curtm.GetMonth(), curtm.GetDay(),0,0,0);
	LONG Curseconds = spantime.GetTotalSeconds();
	CString szsql;

	if(pltyp==0)		//系统基础配置
	{
		int paramnum = 0;
		refavc_Avc_RunParam* pParam=NULL;
		CUIntArray parampos;
		
		if(!SearchData("refavc", "Avc_RunParam", "", "", (void**)&pParam, paramnum, parampos))
			return false;
		
		CString secfile;
		for(int j=0; j<paramnum; j++)
		{
			refavc_Avc_RunParam* ptmp = pParam+j;
			if(ptmp==NULL)
				continue;
			
			LONG starttm, endtm;
			starttm = (ptmp->starttime-CTime(ptmp->starttime.GetYear(), ptmp->starttime.GetMonth(), ptmp->starttime.GetDay(), 0 ,0,0)).GetTotalSeconds();
			endtm = (ptmp->endtime-CTime(ptmp->endtime.GetYear(), ptmp->endtime.GetMonth(), ptmp->endtime.GetDay(), 0 ,0,0)).GetTotalSeconds();
			if(Curseconds>starttm&&Curseconds<=endtm)
			{
				Volup = ptmp->Volup;
				Voldn = ptmp->Voldn;
				if(isgate==false)
				{
					Cosup = ptmp->FacCosup;
					Cosdn = ptmp->FacCosdn;
				}
				else
				{
					Cosup = ptmp->GateCosup;
					Cosdn = ptmp->GateCosdn;
				}
				Isfind=true;
				break;
			}
		}
		if(pParam!=NULL)
			delete []pParam;
		pParam=NULL;
	}
	else
	{
		int paramnum = 0;
		refavc_SetLim_table* pSet=NULL;
		CUIntArray parampos;
		
		szsql.Format("shLimitNo=%ld", pltyp);
		if(!SearchData("refavc", "SetLim_table", szsql, "shOrderNo", (void**)&pSet, paramnum, parampos))
			return false;
		
		CString secfile;
		for(int j=0; j<paramnum; j++)
		{
			refavc_SetLim_table* ptmp = pSet+j;
			if(ptmp==NULL)
				continue;
			
			LONG starttm, endtm;
			starttm = (ptmp->tStartTime-CTime(ptmp->tStartTime.GetYear(), ptmp->tStartTime.GetMonth(), ptmp->tStartTime.GetDay(), 0 ,0,0)).GetTotalSeconds();
			endtm = (ptmp->tEndTime-CTime(ptmp->tEndTime.GetYear(), ptmp->tEndTime.GetMonth(), ptmp->tEndTime.GetDay(), 0 ,0,0)).GetTotalSeconds();
			if(Curseconds>starttm&&Curseconds<=endtm)
			{
				Cosup = ptmp->fVarUp;
				Cosdn = ptmp->fVarDown;
				Isfind=true;
				break;
			}
		}
		if(pSet!=NULL)
			delete []pSet;
		pSet=NULL;
	}

	flimit[0]=Volup;						//电压上限
	flimit[1]=Voldn;						//电压下限
	flimit[2]=Cosup;						//功率上限
	flimit[3]=Cosdn;						//功率下限

	return Isfind;*/
}

char MeasTypeName[][20]={"有功","无功","电压","电流","功率因数","温度","其他"};
char MeasSubName[][20]={"首端","末端","高压侧","中压侧","低压侧"};

void GetDevMeasureName(SEMEAS_RTNET_EMS_Model* pmeas, char* measinfo)
{
	if(pmeas==NULL||measinfo==NULL)
		return;

	measinfo[0]=0;

	DWORD devid = pmeas->devid;
	if(devid<=0)
		return;

	char devname[64]={0};
	for(int i=EQUIP_TYPE_GEN; i<EQUIP_TYPE_DUMMY; i++)
	{
		GetDevName(devid, i, devname);
		if(strlen(devname)<=0)
			continue;
		else
			break;
	}

	if(strlen(devname)<0)
		return;
	
	sprintf(measinfo,"%s", devname);
	//sprintf(measinfo,"%s:%s%s", devname, MeasSubName[pmeas->meassub], MeasTypeName[pmeas->devmtyp]);
}
