#ifndef VISHISSOEINFO_H
#define VISHISSOEINFO

#include "dbapi.h"
#include "userapi.h"
#include "visualdb.h"

#define STATE_CLOSE  0
#define STATE_OPEN  1

typedef struct _SoeInfo
{
	DWORD soe_DevNu;					//SOE对象编号
	BYTE soe_State;						//SOE状态	0 开 1合
	CTime soe_SoeTime;					//SOE发生时间
	unsigned short soe_MilliS;			//SOE发生毫秒
}SoeInfo, *LPSoeInfo;


void WINAPI LoadNewSOEFile(char* filepath);				//加载新的SOE数据文件，完成新数据入库
void WINAPI GetHisSoe(char** phissoe, int* soelen);		//完成历史记录查询和结果空间返回 soelen指空间总长度, 具体多少个SoeInfo结构体数目为：soenum/sizeof(SoeInfo)
void WINAPI ReleaseHisSoe();							//完成一次查询，释放查询空间
void WINAPI GetNewSOE(char* szsoe);						//新的SOE数据记录
void WINAPI CloseSOEDB();								//关闭数据库连接

#endif