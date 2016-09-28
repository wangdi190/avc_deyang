// WebProvider.h : main header file for the WEBPROVIDER DLL
/************************************************/
//编  码：张强
//时  间：2007-07-08
//功能描述：通过文件方式交换实时数据的输出函数
//调用方式：
//    1、保存数据为文件  
//		OpenProvider-〉RegWebData(初始化内部对象)
//      SaveWebData(若需频繁使用,可反复调用)
//      CloseProvider
//    2、提取数据到内存库
//		OpenProvider
//      GetWebData(若需频繁使用,可反复调用)
//      CloseProvider
/************************************************/

#if !defined(AFX_WEBPROVIDER_H__D4CC5552_FBEA_4091_AEF3_F0448E700834__INCLUDED_)
#define AFX_WEBPROVIDER_H__D4CC5552_FBEA_4091_AEF3_F0448E700834__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct _REGWEBSTRUCT  //注册结构
{
	_REGWEBSTRUCT()
	{memset(this,0,sizeof(_REGWEBSTRUCT));};
	char chDataBase[32];		//数据库名
	char chTable[32];			//表名
}REGWEBSTRUCT,LPREGWEBSTRUCT;

//打开数据提供者,指定存取文件路径和文件名
BOOL WINAPI OpenWebProvider(LPCSTR lpPath);

//注册需要输出的数据表,返回注册成功的数目,retid主要用于调试,按位
//确定哪些表未注册成功,最多64张表
int WINAPI RegWebData(REGWEBSTRUCT* pReg,int num,__int64 &retid);

//保存需要输出的数据
BOOL WINAPI SaveWebData();

//获取交换文件数据,返回错误码和处理结果
int WINAPI GetWebData(__int64 &retid);
          
//关闭数据提供者
void WINAPI CloseWebProvider();


#endif // !defined(AFX_WEBPROVIDER_H__D4CC5552_FBEA_4091_AEF3_F0448E700834__INCLUDED_)
