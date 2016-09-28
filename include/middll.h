#if !defined(AFX_MIDDLL_H__INCLUDED_)
#define AFX_MIDDLL_H__INCLUDED_

///////////////////////////////////////////////////////////////////
typedef struct _DEVDEF{	//�豸
	char name[24];		//�豸��
	int  id;			//�豸ID
}DEVDEF,SELRESERVOIR;	
//һ����������ʵ������ѡ��
typedef struct _SELDATA_DEV{	//���ݽ����ṹ
	char mdbnm[256];			//���ݿ���
	char name[24];				//�豸��
	int  did;					//�豸ID
	BYTE dtype;					//�豸����
	BYTE xsmode;				//��ʾģʽ
	/*
	xsmode���壺
	�ڵ㣺  0=����ѹ�ȼ��ͱ���ֵ��ʾ 1=��ʾ��ѹ����ֵ�����
	��·��  0=ʼ��   1=ĩ��
	��ѹ����0=������ 1=������
	*/
	BYTE yh;					//�Ż�ǰ��
	BYTE tseg;					//ʱ��
	int  mtype;					//���з�ʽ
	char extend[128];			//����
}SELDATA_DEV;



typedef struct _SELSINGLE_DEV{	//��ֵ���ݽ����ṹ
	char mdbnm[256];			//���ݿ���
	SINGLEDBS dbs;				//����Դ
	char extend[128];			//����
}SELSINGLE_DEV;


typedef struct _SELECTDEV		//ѡ������豸
{
	char  dbname[256];			//���ݿ���
	char  name[24];				//�豸����
	int   did;					//�豸ID
	BYTE  type;					//������
	BYTE  dtype;				//�豸���� type=2ʱ
	/*
	0="PT" 1="�����" 2="����,��բ",3="����",4="����",5="�翹",
	6="�ӵ�",7="�������ѹ��"
	8="�������ѹ��",9="��̬�޹�������",10="��䡢������"
	33=ĸ�� 34=���� 35=ֱ��
	*/ 
}SELECTDEV;

typedef struct _SELECTPIE		//ѡ��ٷֱ�ͼ����
{
	char  dbname[256];			//���ݿ���
	char  name[24];				//�豸����
	int   did;					//�豸ID
	BYTE  dtype;				//�豸����	0=������· 1=ֱ����· 2=����� 
}SELECTPIE;

typedef struct my_user
{
	WORD  id;					//�û�ID
	char  Name[15];				//�û���
	char  password[16];			//�û�����
	char  type;					//�û�����
	char  exp[32];				//ע��
}my_user;


//PMUSVR�ṹ
typedef struct _PSvrIpPort
{
	DWORD ip;
	WORD  port;
}PSvrIpPort;

//seldev.dll�����ӿ�	
bool WINAPI SelAnlSHow(SELDATA_DEV &indata);
bool WINAPI SelSingleAnl(SELSINGLE_DEV&indata);
bool WINAPI SelDevSta(SELSINGLE_DEV&indata);
bool WINAPI SelZone(SELDATA_DEV&indata);
bool WINAPI GetNameByID(SELECTDEV&dev);
bool WINAPI SelPie(SELECTPIE&indata);
bool WINAPI SelReservoir(SELRESERVOIR&indata);
//readdata.dll�����ӿ�
bool WINAPI InitMemDbf();
bool WINAPI ReadColorData(DEFCOLOR*cr,int &crsum);
bool WINAPI SetColorData(char *vname,BYTE R,BYTE G,BYTE B);
bool WINAPI GetHmiPath(char  *path);
void WINAPI RegistFileOK(HWND hwnd);
void WINAPI UnRegistFileOK(HWND hwnd);
bool WINAPI GetLastRecFile(char *filename);
bool WINAPI SendHmiFile(char *filename);
bool WINAPI ReadDevViewMsg(void *data,int dtype);
bool WINAPI ReadStaData(READDEV_STA&data);
bool WINAPI ReadDevData(READDEV&data);
void WINAPI SetCurDbf(char *dbfname);
void WINAPI SetSenDemo(int type);
bool WINAPI ReadSenData(READSEN&sn);
bool WINAPI ReadPwSys(PWSYSSUM&ps);
bool WINAPI IsLowFLine(DWORD lineid,int type);
int  WINAPI ReadPmuSvrIpPort(PSvrIpPort *pip);
//NT_DEVICE.DLL�����ӿ�
bool WINAPI NT_SelDev(SELECTDEV &indata);
bool WINAPI NT_EditDev(int &intNU,char *devname,int type,int subtype);

//��ʷ�����browhis.dll�����ӿ�
bool WINAPI SelHisFile(char *path,int &sum,int &year,int &month,int&day);
int  WINAPI GotoNextTime(int &hour,int &min,int &sec);
int  WINAPI GotoSegTime(int &hour,int &min,int &sec,int n);
void WINAPI StopBrowHis();
bool WINAPI InitDbPlat();
bool WINAPI OpenhDlg(char *filename,char *hmifile,int &page);

//�����ȼ������ؽӿ�NT_SCFileDLL.dll�����ӿ�
int  WINAPI NT_CreateDAT(char *FileNameDat);
int  WINAPI NT_FileOutInput(char *FileNameOut,int sentype);
int  WINAPI NT_FileConvertInput(char *FileConvert);

//CUserApi.dll�����ӿ�
bool WINAPI V_GetAllUSer(my_user *usr, int &un, int usrmax);
void WINAPI V_Encryptpwd(char *pwd,char *name,char *encrypt);
bool WINAPI V_CheckUser(char *name, char *pw,int &type);
bool WINAPI V_ChangePassword(char *name, char *newpw);
bool WINAPI V_DeleteAUser(char *name);
bool WINAPI V_AddNewUser(void *usrdata);
bool WINAPI V_CanUse();


#endif