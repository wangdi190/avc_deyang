// WebProvider.h : main header file for the WEBPROVIDER DLL
/************************************************/
//��  �룺��ǿ
//ʱ  �䣺2007-07-08
//����������ͨ���ļ���ʽ����ʵʱ���ݵ��������
//���÷�ʽ��
//    1����������Ϊ�ļ�  
//		OpenProvider-��RegWebData(��ʼ���ڲ�����)
//      SaveWebData(����Ƶ��ʹ��,�ɷ�������)
//      CloseProvider
//    2����ȡ���ݵ��ڴ��
//		OpenProvider
//      GetWebData(����Ƶ��ʹ��,�ɷ�������)
//      CloseProvider
/************************************************/

#if !defined(AFX_WEBPROVIDER_H__D4CC5552_FBEA_4091_AEF3_F0448E700834__INCLUDED_)
#define AFX_WEBPROVIDER_H__D4CC5552_FBEA_4091_AEF3_F0448E700834__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct _REGWEBSTRUCT  //ע��ṹ
{
	_REGWEBSTRUCT()
	{memset(this,0,sizeof(_REGWEBSTRUCT));};
	char chDataBase[32];		//���ݿ���
	char chTable[32];			//����
}REGWEBSTRUCT,LPREGWEBSTRUCT;

//�������ṩ��,ָ����ȡ�ļ�·�����ļ���
BOOL WINAPI OpenWebProvider(LPCSTR lpPath);

//ע����Ҫ��������ݱ�,����ע��ɹ�����Ŀ,retid��Ҫ���ڵ���,��λ
//ȷ����Щ��δע��ɹ�,���64�ű�
int WINAPI RegWebData(REGWEBSTRUCT* pReg,int num,__int64 &retid);

//������Ҫ���������
BOOL WINAPI SaveWebData();

//��ȡ�����ļ�����,���ش�����ʹ�����
int WINAPI GetWebData(__int64 &retid);
          
//�ر������ṩ��
void WINAPI CloseWebProvider();


#endif // !defined(AFX_WEBPROVIDER_H__D4CC5552_FBEA_4091_AEF3_F0448E700834__INCLUDED_)
