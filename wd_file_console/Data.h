#ifndef DATA_H
#define DATA_H

//#include <qmessagebox.h>

//#include "CommonModel.h"
//#include "CommonRealtime.h"
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <unistd.h>
#include <vector>
#include <fstream>
using namespace std;

struct DataInfo_Struct
{
	char top;
	int nTypeID;
	int nAppNo;
	int nTableNo;
	int nBufSize;
	char pName[256];
	char bottom;	
};

struct Data_Struct
{
		int SendTag;
    int nTypeID;
    int nAppNo;
    int nTableNo;
    int nIntervalTime;
    char pName[256];
    char field_name[1024];	 
};
typedef std::vector<Data_Struct> VecData;
	
struct TimeData_Struct
{
	struct timeval timevalue;
	int nIntervalTime;
	VecData vecdata;
	bool bStartProgram;
};
typedef std::vector<TimeData_Struct> VecTimeData;

class CData
{
public:
    VecData m_VecData;
    VecTimeData m_VecTimeData;
    
    static bool SortByInterval(TimeData_Struct a, TimeData_Struct b);
    
    char* GetDataByFieldName(int AppNo, int TableNo, char *pFiledName, int &bufSize);
    int Parse_ProfileXml(char *profile_name);
   void GetPropValueToInt(xmlNodePtr cur, char *Prop, int &nValue);
    void GetPropValueToPtr(xmlNodePtr cur, char *Prop, char *pValue);
    void Run();
};

#endif // DATA_H