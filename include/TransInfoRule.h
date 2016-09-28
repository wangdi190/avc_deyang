#ifndef TRANSINFORULE_H
#define TRANSINFORULE

void WINAPI ShowTransInfo(int devtype, int devNU);		//调用输变电设备基本信息
void WINAPI ShowTransRule(int devtype, int devNU);		//调用输变电设备规程
void WINAPI LinkRelay();					//关联遥信、保护信号到屏或相关设备

#endif