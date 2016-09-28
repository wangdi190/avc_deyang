#ifndef VISHISSOEINFO_H
#define VISHISSOEINFO

#include "dbapi.h"
#include "userapi.h"
#include "visualdb.h"

#define STATE_CLOSE  0
#define STATE_OPEN  1

typedef struct _SoeInfo
{
	DWORD soe_DevNu;					//SOE������
	BYTE soe_State;						//SOE״̬	0 �� 1��
	CTime soe_SoeTime;					//SOE����ʱ��
	unsigned short soe_MilliS;			//SOE��������
}SoeInfo, *LPSoeInfo;


void WINAPI LoadNewSOEFile(char* filepath);				//�����µ�SOE�����ļ���������������
void WINAPI GetHisSoe(char** phissoe, int* soelen);		//�����ʷ��¼��ѯ�ͽ���ռ䷵�� soelenָ�ռ��ܳ���, ������ٸ�SoeInfo�ṹ����ĿΪ��soenum/sizeof(SoeInfo)
void WINAPI ReleaseHisSoe();							//���һ�β�ѯ���ͷŲ�ѯ�ռ�
void WINAPI GetNewSOE(char* szsoe);						//�µ�SOE���ݼ�¼
void WINAPI CloseSOEDB();								//�ر����ݿ�����

#endif