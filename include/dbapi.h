
#if !defined(_DBAPI_H__B__INCLUDED_)
#define _DBAPI_H__B__INCLUDED_


#ifdef DBAPI_EXPORTS
#define DBAPI_API __declspec(dllexport)
#else
#define DBAPI_API __declspec(dllimport)
#endif


#define  APPENDREC  1301  //���һ�հ׼�¼
#define  ADDCYCREC  1302  //��ѭ�����һ����¼
#define  ADDEVTREC  1303  //���¼��������һ����¼
#define  INSERTREC	1304  //����һ����¼
#define  DELETEREC  1305  //ɾ��һ����¼��ֻ����ǣ�
#define  UPDATEFILE 1306  //�����ļ�
#define  SENDFILE   1307  //���ͱ����ļ�
#define  SAVEDBF    1308  //����ϵͳ���� 
#define  CLEARREC   1309  //���һ����¼���Ӽ�¼����ȥ����


#define  SENDZERO   1320  //�������¼
#define  CMD_TOCLI	1310  //���ͻ�������
#define  notify_SVRCLOSE	 1		//�������ر�
#define  notify_DATACHG		 2		//���ݷ����仯
#define  notify_RECCYC		 3		//ѭ������յ�������
#define  notify_RECEVT		 4		//�¼�����յ�������
#define  notify_FILEOK		 5		//�ļ��������

/*DBAPI_API*/ bool  LSI_InitNTDbi();
DBAPI_API bool  LSI_CheckUser(char *name, char *pw);
DBAPI_API void  LSI_RegistWindow(HWND hwnd,BYTE type=0,DWORD tblid=0);
DBAPI_API void  LSI_UnRegistWindow(HWND hwnd);
DBAPI_API void* LSI_QueryRecord(char *qstring,int &recn,
					  int&error,bool showmsg);
DBAPI_API void* LSI_QueryRecord(DWORD tbid, int &recn,
					  int &error,bool showmsg);
DBAPI_API int  LSI_UpdateARecord(char *tbstr, void *dbuf, int recno);
DBAPI_API int  LSI_AppendRec(char *tbstr, void *dbuf);
DBAPI_API int  LSI_InsertRecord(char *tbstr, void *dbuf, int recno);
DBAPI_API int  LSI_DeleteRecord(char *tbstr,int recno);
DBAPI_API int  LSI_UpdateAll(char *tbstr, void *dbuf, int n);
DBAPI_API int  LSI_EmptyTable(char *tbstr,bool showmsg) ;
DBAPI_API void LSI_SetChanged(DWORD tbid,int n);
DBAPI_API void LSI_SetChangedField(DWORD tbid, int n,WORD fld_pos);
DBAPI_API bool LSI_GetTableIDExt(char *dtstr, DWORD &idi);
DBAPI_API bool LSI_GetTableID(char *dbname,char *tablename,DWORD &idi);
DBAPI_API void *LSI_GetTableAdd(int tblno);
DBAPI_API void *LSI_GetStructAdd(int &num);
DBAPI_API int  LSI_AddCycRec(char *tbstr,void *dbuf);
DBAPI_API int  LSI_AddEvtRec(char *tbstr, void *dbuf);
DBAPI_API bool LSI_AppendRec(DWORD tblid);
DBAPI_API bool LSI_InsertRecord(DWORD tbid, int recno);
DBAPI_API bool LSI_DeleteRecord(DWORD tbid, int recno);
DBAPI_API int  LSI_SetChangedTran(char *tbstr,BYTE tran);
DBAPI_API int  LSI_SetChangedRec(char *tbstr, BYTE rec);
DBAPI_API int  LSI_SaveTable(char *filename, char *tbstr);
DBAPI_API int  LSI_LoadTable(char *filename, char *tbstr);
DBAPI_API int  LSI_GetRecord(char *tbstr,int jlh,char *buf);
DBAPI_API int  LSI_GetFirstRecno(char *qstring);
DBAPI_API bool LSI_GetCurServer(char *curserver);
DBAPI_API bool LSI_GetHmiPath(char *path);
DBAPI_API void LSI_UpdateHmiFile();
DBAPI_API bool LSI_SendHmiFile(char *filename);
DBAPI_API bool LSI_GetLastRecFile(char *filename);
DBAPI_API int  LSI_CheckCtlUser(char *name, char *pw);
DBAPI_API int  LSI_ClearRecord(char *tbstr,int recno);
DBAPI_API bool LSI_ClearRecord(DWORD tbid, int recno);
DBAPI_API void LSI_UpdateUsedRecToplat(DWORD tbid);
//ϵͳר��
DBAPI_API int  LSI_RegEvtHwnd(HWND hwnd, DWORD tblid);
DBAPI_API void LSI_UnRegEvtHwnd(HWND hwnd, DWORD tblid);
DBAPI_API int  LSI_ReadAEvt(HWND hwnd, DWORD tblid, char *buf);
DBAPI_API void LSI_SaveDBF();
//wyj
DBAPI_API int LSI_GetColVal(DWORD tblid, int recno,char *colname,void *buf);
DBAPI_API int LSI_PutColVal(DWORD tblid, int recno,char *colname,void *buf);
//���º�����ƽ̨�����Ա����,�������,�����������
DBAPI_API void *MEM_GetCurQueryTbl();

#endif