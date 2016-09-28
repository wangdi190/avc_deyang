/*******************************************************************
ModuleName: sam_service
FileName:   sam_service.h
DESCRIPTION:common data struct define
Author:     liangyi
History:
Date		Version
==========================
17/05/2004   1.3
07/22/2003	 1.2
04/16/2003	 1.1
11/20/2002	 1.0
********************************************************************/

#ifndef SAM_SERVICE_H_
#define SAM_SERVICE_H_

//#ifdef _WINDOWS32
#include <string>
//#else
//#include <string.h>
//#endif

#include <vector>
using namespace std;

#ifdef _WINDOWS32
#include <winsock.h>
#ifdef SAM_SERVICE_EXPORTS
#define SAM_SERVICE_API __declspec(dllexport)
#else
#define SAM_SERVICE_API __declspec(dllimport)
#endif
#else
#include <netinet/in.h>
#ifdef _SUN
#undef TRANSPARENT
#endif
#endif

struct APPINFO
{
		int app_id;
		int policy;
		char host_name[40];
		short context;
};

#ifdef _WINDOWS32
class SAM_SERVICE_API CServicesManage
#else
class CServicesManage
#endif
{
public:
    CServicesManage();
    ~CServicesManage();

    int	   InitReceiveSockets();
    //void   ReceiveLoop();
    int	   CheckAppStatus();
    //int	   ProcessReport(const char *recv_buf,const int recv_len);
    int    IsOnDuty( const int app_id, const short context = 0 ); //my node is on duty
    int    GetAppActiveNodes(int app_no, vector<string> &node_name, vector<int> &node_id, const short context = 0);
    int    GetActiveApps(vector<int> &app_id, const short context = 0);
    int 	 IsTeleDomain(char *domain);
    int    RequestService(const int app_id, const int policy, char *host_name, const short context=0);
    int    RequestService_Client(const int app_id, const int policy, char *host_name, const short context=0); //add 20100901 gaoyuan
    int    RequestService(const int app_id, const int policy, char *host_name, const short context, char *domain);
    int    RequestService(const int app_id, const int policy, vector<string> &hosts_name, const short context=0);
    int    RequestServices(vector<APPINFO> &app_info, char *domain);
    int    RequestServices(vector<APPINFO> &app_info);
    int	   TransTime(time_t time_in, char *time_str);	   //convert param time_in to string
    int	   StringCopy(char *des,const char *src,int max_len);
    void   StripBlank(char *str);
    int    GetDefaultContext(short &context);
public:
    int	   SetSystemInfo();
    static char* MapFile(const char* file_name, const int stab_total_size);
    static int UMapFile(char* addr_t, const int size);

public:
#ifndef _WINDOWS32
    //semaphore operations
    static int InitSem(const key_t key, const int nsems = 1);  //inital all semaphore
    static int p(const int sem_id, const int sem_num = 0);
    static int v(const int sem_id, const int sem_num = 0);
#else
    static int p(const char* sem_name, const int sem_num);
    static int v(const char* sem_name, const int sem_num = 1, const int release_num = 1);
#endif
public:
    int	   m_AppStatusSemid;
    int	   m_ReceiveSockets;
    char   m_MyProjectName[256];
    struct sockaddr_in m_ReceiveAddr;
    struct APP_STATUS_TABLE_INFO_SERV  *m_AppStatusPtr;
private:
    int    m_TotalBufSize;
};

#endif
