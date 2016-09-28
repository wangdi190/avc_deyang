#pragma once


#define AVCALARM_YX 0
#define AVCALARM_TRANSREFUSE 1
#define AVCALARM_TRANSSLIP 2
#define AVCALARM_CPREFUSE 3
#define AVCALARM_DISLOCATION 4
#define AVCALARM_MANUAL 5
#define AVCALARM_YCYXCLASH 6
#define AVCALARM_TOPU 7
#define AVCALARM_TRANSOVERLOAD 8
#define AVCALARM_BUSOVERVOL 9
#define AVCALARM_BUSLOWVOL 10
#define AVCALARM_CTRLOVER 11
#define AVCALARM_COLDBACK 12
#define AVCALARM_CANNOCTRL 13
#define AVCALARM_MEASURE 14
#define AVCALARM_WINDVOLFAIL 15
#define AVCALARM_TIMEPARTFAOL 16
#define AVCALARM_ONEGROUD 17
#define AVCALARM_VOLBALANCE 18
#define AVCALARM_BADDATA 19
#define AVCALARM_DEVICEFLAG 20
#define AVCALARM_SHUNTLOCK 21
#define AVCALARM_TRANSSERIES 22
const char AVCALARM_NAME[][20]={"ң���쳣","�ֽ�ͷ�ܶ�","�ֽ�ͷ����","�ݿ����ܶ�","���������","�ֹ�����","ң��ң�Ų�ƥ��","�����쳣","�������","ĸ�߹���ѹ","ĸ��Ƿ��ѹ",\
"��������Խ��","�豸�䱸��","�޵��ڴ�ʩ","���ⲻˢ��","������ѹ�쳣","ʱ�����ô���","����ӵ�","�����ѹ��ƽ��","���⻵����","�豸����","�������ݱ���","��������ͬ�����",};

#define ALARMDEVICE_AVC 1
#define ALARMDEVICE_TRANS 2
#define ALARMDEVICE_SHUNT 3
#define ALARMDEVICE_GEN 4
#define ALARMDEVICE_BUS 5
#define ALARMDEVICE_STATION 6






#define RC_SHUNT 1							//��������	
#define RC_REACT 2							//�����翹
#define RC_SERIESSHUNT 3					//��������
#define RC_SERIESREACT 4					//�����翹
#define RC_SPLITREACT 5						//���ѵ翹


#define WINDING_HIGH 0
#define WINDING_MID 1
#define WINDING_LOW 2

#define LOADTRANS_NO 0					//���ز��ɵ�ѹ
#define LOADTRANS_YES 1					//���ؿɵ�ѹ