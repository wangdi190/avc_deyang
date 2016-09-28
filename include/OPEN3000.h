////


#if !defined(AFX_OPEN3000_H__FDA2D0C6_635E_4EC2_8614_F6A36E15D888_INCLUDED_)
#define AFX_OPEN3000_H__FDA2D0C6_635E_4EC2_8614_F6A36E15D888_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define M_SCADA_BRK_DEVICE 60      //��·����Ϣ��
#define M_SCADA_DISCR_DEVICE 61    //��բ��
#define M_SCADA_GDDISCR_DEVICE 62  //�ӵص�բ��
#define M_SCADA_BS_DEVICE 63       //ĸ�߱�
#define M_SCADA_TR_DEVICE 64       //��ѹ����
#define M_SCADA_TRWD_DEVICE 65     //��ѹ������
#define M_SCADA_GN_DEVICE 66       //�������
#define M_SCADA_LD_DEVICE 67       //����
#define M_SCADA_ACLN_DEVICE 68     //�����߶α�
#define M_SCADA_ACLN_DOT 69        //�����߶ζ˵��
#define M_SCADA_FAC_INFO 70        //��վ��Ϣ��
#define M_SCADA_DIV_INFO 71        //���������
#define M_SCADA_RC_DEVICE 72       //�ݿ�����  ���ݺ͵翹
#define M_SCADA_VL_TYPE 73         //��ѹ���ͱ�
#define M_SCADA_TAP_TYPE 74         //��λ���ͱ�

#define M_AVC_STATION 75			//AVC��վ����
#define M_AVC_BUS 76				//AVCĸ�߿��ƶ���
#define M_AVC_TRANS 77				//AVC��ѹ�����ƶ���
#define M_AVC_SHUNT 78				//AVC���������ƶ���
#define M_AVC_CONTROL 79			//AVC���ƶ���
#define M_AVC_RUNPARAM 80			//AVC���в���
#define M_AVC_TIMEPART 81			//AVCʱ�ο��ƶ���
#define M_AVC_WARMTYPE 82			//�澯����
#define M_AVC_CONPLOY 83			//���Ʋ���
#define M_AVC_WARMSIGN 84			//�澯�ź�
#define M_AVC_PROTECTSIGN 85		//�����ź�


#define R_SCADA_BRK_DEVICE 10      //��·����Ϣ��
#define R_SCADA_DISCR_DEVICE 11    //��բ��
#define R_SCADA_GDDISCR_DEVICE 12  //�ӵص�բ��
#define R_SCADA_BS_DEVICE 13       //ĸ�߱�
#define R_SCADA_TR_DEVICE 14       //��ѹ����
#define R_SCADA_TRWD_DEVICE 15     //��ѹ������
#define R_SCADA_GN_DEVICE 16       //�������
#define R_SCADA_LD_DEVICE 17       //����
#define R_SCADA_ACLN_DEVICE 18     //�����߶α�
#define R_SCADA_ACLN_DOT 19        //�����߶ζ˵��
#define R_SCADA_FAC_INFO 20        //��վ��Ϣ��
#define R_SCADA_DIV_INFO 21        //���������
#define R_SCADA_RC_DEVICE 22       //�ݿ�����  ���ݺ͵翹
#define R_SCADA_VL_TYPE 23         //��ѹ���ͱ�

typedef struct MODEL_VOLTAGE			//��ѹ���ͱ�_ģ��
{
	int vlty_id;					//��ѹ����ID��
	char vlty_name[64];				//��ѹ��������
	float vbase;					//��ѹ��׼
	int vlColor;					//��ѹ������ɫ
	float hlim;						//��ѹ����
	float llim;						//��ѹ����
	float vbase_kh;					//��ѹ���˻�׼
	float sbse_kh;					//���ʿ��˻�׼
}MODEL_VOLTAGE;

typedef struct MODEL_ZONE				//���������_ģ��
{
	int area_id;					//����ID��
	char area_name[64];				//��������
	int area_no;					//������
}MODEL_ZONE;

#define STATION_HOT 0
#define STATION_WATER 1
#define STATION_NUCLEAR 2
#define STATION_TRANS 3
#define STATION_VIR 4
#define STATION_SHIFT 5
#define STATION_STAT 10
typedef struct MODEL_STATION			//��վ��Ϣ��_ģ��
{
	int fac_id;								//��վID
	int area_id;							//����ID
	char fac_name[64];						//��վ����
	unsigned char fac_type;					//��վ����    0��硢1ˮ�硢2�˵硢3���վ��4����վ��ֵվ��5ת������10ͳ�Ƴ�
	int vlty_id;							//��ߵ�ѹ�ȼ�
	char graph_name[64];					//����ͼ����
}MODEL_STATION;

typedef struct MODEL_VOLLEVEL		//��ѹ�ȼ���_ģ��
{
}MODEL_VOLLEVEL;

#define STATE_RUN 0
#define STATE_QUIT 1
#define STATE_READQUIT 2
typedef struct MODEL_BREAKE			//��·����Ϣ��_ģ��
{
	int brk_id;									//��·��ID��
	int fac_id;									//��վID��
	char brk_name[64];							//��·������
	int vlty_id;								//��ѹ����ID��
	int nd1_no;									//�ڵ�1��
	int nd2_no;									//�ڵ�2��
	int bay_id;									//���ID��
	int run_state;								//����״̬				0Ͷ�ˡ�1δͶ�ˡ�2������
	unsigned char yx_value;						//ң��ֵ
	int bw_number;								//��λ����
}MODEL_BREAKE;

typedef struct MODEL_DISCR			//��բ��_ģ��
{
	int discr_id;								//��բID��
	int fac_id;									//��վID��
	char discr_name[64];						//��բ����
	int vlty_id;								//��ѹ����ID��
	int nd1_no;									//�ڵ�1��
	int nd2_no;									//�ڵ�2��
	int bay_id;									//���ID��
	int run_state;								//����״̬
	unsigned char yx_value;						//ң��ֵ
	int bw_number;								//��λ����
}MODEL_DISCR;

typedef struct MODEL_GDISCR			//�ӵص�բ��_ģ��
{
	int gddiscr_id;							//�ӵص�բID��
	int fac_id;								//��վID��
	char gddiscr_name[64];					//�ӵص�բ����
	int vlty_id;							//��ѹ����ID��
	int nd_no;								//�ڵ��
	int bay_id;								//���ID��
	int run_state;							//����״̬
	unsigned char yx_value;					//ң��ֵ
	int bw_number;							//��λ����
}MODEL_GDISCR;

typedef struct MODEL_BUS					//ĸ�߱�_ģ��
{
	int bs_id;								//ĸ��ID��
	int fac_id;								//��վID��
	char bs_name[64];						//ĸ������
	int vlty_id;							//��ѹ����ID��
	float vmax;								//��ѹ����
	float vmin;								//��ѹ����
	int bay_id;								//���ID��
	int nd_no;								//�ڵ��
	int run_state;							//Ͷ��״̬
	float v_value;							//�ߵ�ѹ��ֵ
	float c_value;							//��ѹ���
}MODEL_BUS;

#define EQUAL_NO 0							//0����ֵ
#define EQUAL_LOAD 1						//1��ֵΪ����
#define EQUAL_GEN 3							//2��ֵΪ�����
typedef struct MODEL_LINE					//�����߶α�_ģ��
{
	int acln_id;							//�����߶�ID��
	int fac_id_s;							//һ�˳�վID��
	int fac_id_e;							//���˳�վID��
	char acln_name[64];						//�����߶�����
	int vlty_id;							//��ѹ����ID��
	int line_id;							//��·ID��
	float smax;								//������ֵ
	float imax1;							//����������
	int area_id;							//����ID��
	unsigned char eq_fg;					//��ֵ��־						0����ֵ��1��ֵΪ���ɡ�2��ֵΪ�����
	int run_state;							//Ͷ��״̬
	float r_value_pu;						//����������ֵ
	float x_value_pu;						//����翹����ֵ
	float bch_value_pu;						//������ɱ���ֵ
}MODEL_LINE;

typedef struct MODEL_LINEDOT				//�����߶ζ˵��_ģ��
{
	int fac_id;									//��վID��
	char acln_dot_name[64];						//�����߶ζ˵�����
	int acln_id;								//���������߶�ID��
	int vlty_id;								//���������߶�ID��
	int bay_id;									//���ID��
	int nd_no;									//�ڵ��
}MODEL_LINEDOT;

typedef struct MODEL_TRANS				//��ѹ����_ģ��
{		
	int tr_id;									//��ѹ��ID��
	int fac_id;									//��վID��
	char tr_name[64];							//��ѹ������
	unsigned char trty;							//��������
	int run_state;								//Ͷ��״̬
}MODEL_TRANS;

#define WINDING_HIGH 0
#define WINDING_MID 1
#define WINDING_LOW 2

#define LOADTRANS_NO 0					//���ز��ɵ�ѹ
#define LOADTRANS_YES 1					//���ؿɵ�ѹ

typedef struct MODEL_TRANSWIND				//��ѹ������_ģ��
{
	int trwd_id;									//��ѹ������ID��
	int fac_id;										//��վID��
	char trwd_name[64];								//��ѹ����������
	int tr_id;										//��ѹ��ID��
	unsigned char trwd_type;						//��ѹ����������				0�ߡ�1�С�2��
	int tapty_id;									//�ֽ�ͷ����ID��
	int vlty_id;									//��ѹ����ID��
	int nd_no;										//�ڵ��
	unsigned char ltc_fg;							//���ص�ѹ��־        0���ɵ���1�ɵ�
	float snom;										//�����
	float vnom;										//���ѹ
	int bay_id;										//���ID
	float r_value_pu;								//����������ֵ
	float x_value_pu;								//����翹����ֵ
}MODEL_TRANSWIND;


typedef struct MODEL_TAPTYPE				//��ѹ�����鵵λ_ģ��
{
	int tapty_id;									//��ѹ���ֽ�ͷ����ID��
	char tapty_name[64];							//��ѹ���ֽ�ͷ��������
	int tapty_mn;									//��С��λ
	int tapty_mx;									//���λ
	int tapty_nom;									//���λ
	float tapty_step;								//����
}MODEL_TAPTYPE;

typedef struct MODEL_GEN							//�������_ģ��
{
	int gn_id;										//�����ID��
	int fac_id;										//��վID��
	char gn_name[64];								//���������
	int vlty_id;									//��ѹ����ID��
	float snom;										//�����
	int nd_no;										//�ڵ���
	int run_state;									//Ͷ��״̬
}MODEL_GEN;

typedef struct MODEL_LOAD						//����_ģ��
{
	int ld_id;										//����ID��
	int fac_id;										//��վID��
	char ld_name[64];								//��������
	int vlty_id;									//��ѹ����ID��
	int bay_id;										//���ID��
	int nd_no;										//�ڵ��
	int run_state;									//Ͷ��״̬
}MODEL_LOAD;

#define RC_SHUNT 1							//��������	
#define RC_REACT 2							//�����翹
#define RC_SERIESSHUNT 3					//��������
#define RC_SERIESREACT 4					//�����翹
#define RC_SPLITREACT 5						//���ѵ翹

typedef struct MODEL_SHUNT							//���ݺ͵翹_ģ��
{
	int rc_id;										//�ݿ���ID��
	int fac_id;										//��վID��
	char rc_name[64];								//�ݿ�������
	int vlty_id;									//��ѹ����ID��
	unsigned char rc_type;							//�ݿ�������			1�������ݡ�2�����翹��3�������ݡ�4�����翹��5���ѵ翹
	int nd1_no;										//�ڵ�1�� 
	int nd2_no;										//�ڵ�2��
	int nd3_no;										//�ڵ�3��
	int run_state;									//Ͷ��״̬
	float qnom;										//�����
	float vnom;										//���ѹ
	int bay_id;										//���ID��
	float r_value_pu;								//����������ֵ
	float x_value_pu;								//����翹����ֵ
}MODEL_SHUNT;

#define RELAY_OTHER 0
#define RELAY_ALL 1
#define RELAY_FORECAST 2
#define RELAY_ACT 3
#define RELAY_FAULT 4
#define RELAY_COMMON 5
#define RELAY_CTRL 6
#define RELAY_DEVICE 7
#define RELAY_REPEAT 9
#define RELAY_BACKUP 10

const char RELAY_NAME[][12]={"����","�¹���","Ԥ���ź�","�����ź�","�����ź�","ͨѶ�ź�","�����ź�","�豸�ź�","","�غ�բ�ź�","����Ͷ�ź�"};
typedef struct MODEL_RELAY							//�����ڵ��_ģ��
{
	int rly_id;										//����ID��
	int fac_id;										//��վID��
	char rly_name[64];								//��������
	unsigned char rly_type;							//��������			0������1�¹��ܡ�2Ԥ���źš�3�����źš�4�����źš�5ͨѶ�źš�6�����źš�7�豸�źš�9�غ�բ�źš�10����Ͷ�ź�
	int vlty_id;									//��ѹ����
	unsigned char yx_value;							//ң��ֵ
	int bay_id;										//���ID��
	int devid_avc;									//AVC����豸ID
}MODEL_RELAY;

#define YKTYPE_YK 0
#define YKTYPE_DAYK 1
#define YKTYPE_DIRYK 2
#define YKTYPE_AVCYK 3
#define YKTYPE_DOUYK 4
const char YKTYPE_NAME[][12]={"ң��","DAң��","ֱ��ң��","AVCң��","˫��ң��"};

#define YKSTATE_NORMAL 0
#define YKSTATE_YKLOCK 1
#define YKSTATE_LOCKOPEN 2
#define YKSTATE_LOCKCLOSE 3
const char YKSTATE_NAME[][12]={"ң������","ң�ر���","ң�ر�����","ң�ر�����"};

#define AVCCTRL_NO 0
#define AVCCTRL_YES 1
const char AVCCTRL_NAME[][12]={"AVC���ɿ�","AVC�ɿ�"};

typedef struct MODEL_YK									//ң�ع�ϵ��_ģ��
{
	unsigned char yx_id[14];						//ң��ID��
	int fac_id;										//��վID��
	int yk_no;										//ң�ص��
	unsigned char yk_type;							//ң������					0ң�ء�1DAң�ء�2ֱ��ң�ء�3AVCң�ء�4˫��ң��
	unsigned char yk_status;						//ң��״̬					0ң��������1ң�ر�����2ң�ر����֡�3ң�ر�����
	unsigned char if_avc_yk;						//�Ƿ�AVC�ɿ�				0��1��
}MODEL_YK;

#define YTTYPE_YT 0
#define YTTYPE_AVCYT 1
const char YTTYPE_NAME[][12]={"ң��","AVCң��"};

typedef struct MODEL_YT									//ң����ϵ��_ģ��
{
	unsigned char yc_id[14];						//ң��ID��
	int fac_id;										//��վID��
	int yt_no;										//ң�����
	unsigned char yt_type;							//ң������				0ң����1AVCң��
}MODEL_YT;

#define TRANS_YKSTATE_OPEN 0				//��
#define TRANS_YKSTATE_CLOSE 1				//��
typedef struct MODEL_WINDYT								//��λң����ϵ��_ģ��
{
	int trwd_id;								//��ѹ������ID
	unsigned char up_yx[14];					//��ң��ID
	unsigned char up_yx_state;					//����״̬				0�֡�1��
	unsigned char down_yx_id[14];				//��ң��ID
	unsigned char down_yx_state;				//�ؽ�״̬				0�֡�1��
	unsigned char stop_yx_id[14];				//��ͣң��ID
	unsigned char stop_yx_state;				//��ͣ״̬				0�֡�1��
	int max_dw;									//���λ
	int min_dw;									//��С��λ
}MODEL_WINDYT;

#define SWITCHTYPE_OTHER 1					//����
#define SWITCHTYPE_CAPBREAK 2				//���ݿ���
#define SWITCHTYPE_WINDBREAK 3				//��ѹ������
#define YKMODE_TEST 0						//����
#define YKMODE_RUN 1						//����
typedef struct MODEL_AVCRELATION				//AVCң�ع�ϵ��_ģ��
{
	unsigned char yx_id[14];					//ң��ID��
	int fac_id;									//��վiD��
	unsigned char enable_avc;					//����AVC����				0��1��
	unsigned char cb_type;						//��������					1������2���������ء�3��ѹ���ֽӿ���
	unsigned char yk_mode;						//����ģ��					0����̬��1����̬
}MODEL_AVCRELATION;


typedef struct REAL_BREAKE					//��·����Ϣ��_ʵʱ
{
	int brk_id;									//��·��ID��
	int run_state;								//����״̬
	unsigned char yx_value;						//ң��ֵ
}REAL_BREAKE;

typedef struct REAL_DISCR							//��բ��_ʵʱ
{
	int discr_id;								//��բID��
	int run_state;								//����״̬
	unsigned char yx_value;						//ң��ֵ
}REAL_DISCR;

typedef struct REAL_GDDISCR						//�ӵص�բ��_ʵʱ
{
	int gddiscr_id;								//�ӵص�բID��
	int run_state;								//����״̬
	unsigned char yx_value;						//ң��ֵ
}REAL_GDDISCR;

typedef struct REAL_BUS								//ĸ�߱�_ʵʱ
{
	int bs_id;											//ĸ��ID��
	int run_state;										//����״̬
	float v_value;										//ĸ���ߵ�ѹ
	float c_value;										//��ѹ���
}REAL_BUS;

typedef struct REAL_TRANSWIND						//��ѹ������_ʵʱ
{
	int trwd_id;										//��ѹ������ID��
	int tr_id;
	unsigned char trwd_type;
	int run_state;										//����״̬
	float p_value;										//�й�����
	float q_value;										//�޹�����
	float i_value;										//����
	float tap_pos;										//���鵵λ
}REAL_TRANSWIND;

typedef struct REAL_LINEDOT							//�����߶ζ˵��_ʵʱ
{
	int acln_dot_id;									//�����߶�ID��
	int fac_id;											//��վID
	int run_state;										//����״̬
	float p_value;										//�й�����
	float q_value;										//�޹�����
	float i_value;										//����
}REAL_LINEDOT;

typedef struct REAL_GEN									//�������_ʵʱ
{		
	int gn_id;											//�����ID��
	int run_state;										//����״̬
	float p_value;										//�й�����
	float q_value;										//�޹�����
	float v_value;										//��ѹ
}REAL_GEN;

typedef struct REAL_LOAD								//����_ʵʱ
{
	int ld_id;											//����ID��
	int run_state;										//����״̬
	float p_value;										//�й�����
	float q_value;										//�޹�����
	float i_value;										//����
}REAL_LOAD;

typedef struct REAL_SHUNT							//�ݿ�����(���ݺ͵翹)_ʵʱ
{
	int rc_id;											//�ݿ�ID��
	unsigned char rc_type;
	int run_state;										//����״̬
	float q_value;										//�޹�����
}REAL_SHUNT;

typedef struct REAL_RELAY								//�����ڵ��_ʵʱ
{
	int rly_id;									//����ID��
	unsigned char yx_value;						//ң��
}REAL_RELAY;

#define ITERSTATE_YES 0
#define ITERSTATE_LIMIT 5
#define ITERSTATE_FAIL 6
#define ITERSTATE_NOJION 9
const char ITERSTATE_NAME[][16]={"����","","","","","�����������","��ɢ","","","δ�μӼ���"};

typedef struct PASREAL_ISLAND						//PAS��������Ϣ��
{
	int keyno;											//���
	short isrec;										//����
	char chst[16];										//ƽ�����վ��
	int stid;											//ƽ�����վID
	char un[20];										//ƽ�������
	int unid;											//ƽ���ID
	short bus;											//�ڵ���
	unsigned char stat;								//����״̬										0������5����������ޡ�6��ɢ��9δ�μӼ���
	unsigned char obisle;							//�Ƿ�ɹ۲�									0��1��
	unsigned char lvbadp;							//�й�������
	unsigned char lvbadq;							//�޹�������
}PASREAL_ISLAND;

typedef struct PASREAL_RUNINFO					//PAS���������Ϣ��
{
	int runtime;										//ʱ��
	char msg[160];										//��Ϣ
}PASREAL_RUNINFO;

typedef struct PASREAL_SEPARAMINFO			//״̬���Ʋ�������Ϣ��
{
	unsigned char pause_flag;						//��ͣ�����־
	int conv_state;									//����״̬										0������5����������ޡ�6��ɢ��9δ�μӼ���
	int run_state;									//�����б�־									0��1��
	float estimeble_rate;							//���⸲����
	int datemark;									//�մ�
	int hourmark;									//ʱ��
	float conv_rate;								//����������
	int cycle_period;								//�������ڣ��֣�
	int iter_step_limit;							//����������
	float epsp;										//�й���������
	float epsq;										//�޹���������
}PASREAL_SEPARAMINFO;

typedef struct PASREAL_SEMEASURE					//״̬��������һ����
{
	int keyno;											//���
	int stid;											//��վID
	int devid;											//�豸ID
	short meassub;										//�����±�
	short meastype;										//��������
	int devmtyp;										//�豸��������
	float measval;										//����ֵ
	float seval;										//״̬����ֵ
	float err;											//���ٷ���
	float qbigerr;										//�����
	float qbad;											//������
	int island;											//����
}PASREAL_SEMEASURE;

typedef struct AVCMODEL_STATION						//AVC��վ����_ģ��
{
	int fac_id;											//��վID��
	int resper;											//������������
	unsigned char remove;								//��վ�ų�									0��1��
	unsigned char qaut;									//�Զ�����									0��1��
	int pltyp;											//ʱ������
	unsigned char qdevlck;								//�����豸����							0��1��
}AVCMODEL_STATION;

#define LOCKTYPE_NORMAL 0
#define LOCKTYPE_MAN 1
#define LOACKTYPE_AUTO 2
#define LOACKTYPE_COMPLEX 3
const char LOCKTYPE_NAME[][12]={"����Ͷ��","�˹�����","�Զ�����","�ۺϱ���"};

typedef struct AVCMODEL_BUS								//AVCĸ�߶���_ģ��
{
	int fac_id;											//��վID��
	int bsid;											//ĸ��ID��
	int pltyp;											//ʱ������
	unsigned char offavr;								//����״̬									0����Ͷ�롢1�˹�������2�Զ�������3�ۺϱ���
	unsigned char qavr;									//�������									0��1��
	unsigned char qgate;								//�ؿ�ĸ��									0��1��
}AVCMODEL_BUS;

typedef struct AVCMODEL_TRANS								//AVC��ѹ������_ģ��
{
	int fac_id;											//��վID��
	int trid;											//��ѹ��ID��
	int pltyp;											//ʱ������
	unsigned char offavr;								//����״̬									0����Ͷ�롢1�˹�������2�Զ�������3�ۺϱ���
	unsigned char qavr;									//�������									0��1��
	short limtnum;										//������������
	int upyxid;											//����ң��ID
	int upykno;											//����ң��ID
	int dnyxid;											//����ң��ID
	int dnykno;											//����ң��ID
	int isbsid;											//����ĸ��
	int numday;											//��AVC��������
	int tnumday;										//���ܶ�������
	int cnumday;										//��AVC���ƴ���
	int nummoon;										//��AVC��������
	int tnummoon;										//���ܶ�������
	int cnummoon;										//��AVC���ƴ���
	int numyea;											//��AVC��������
	int tnumyea;										//���ܶ�������
	int cnumyea;										//��AVC���ƴ���
	unsigned char qgate;								//uchar�ؿ�����									0��1��
}AVCMODEL_TRANS;

typedef struct AVCMODEL_SHUNT					//AVC����������_ģ��
{
	int fac_id;											//��վID��
	int cpid;											//����ID��
	int pltyp;											//ʱ������
	unsigned char offavr;								//����״̬									0����Ͷ�롢1�˹�������2�Զ�������3�ۺϱ���
	unsigned char qavr;									//�������									0��1��
	short limtnum;										//������������
	int yxid;											//ң��ID
	int ykno;											//ң��ID
	int isbsid;											//����ĸ��
	int bkid;											//���ƿ���
	int numday;											//��AVC��������
	int tnumday;										//���ܶ�������
	int cnumday;										//��AVC���ƴ���
	int nummoon;										//��AVC��������
	int tnummoon;										//���ܶ�������
	int cnummoon;										//��AVC���ƴ���
	int numyea;											//��AVC��������
	int tnumyea;										//���ܶ�������
	int cnumyea;										//��AVC���ƴ���
	int rtmday;											//������ʱ��
	int rtmmoon;										//������ʱ��
	int rtmyea;											//������ʱ��
}AVCMODEL_SHUNT;

#define AVCCALCULATION_DEFAULT 0
#define AVCCALCULATION_OPF 1
#define AVCCALCULATION_CTRL 2
const char CALCULATION_NAME[][20]={"Ĭ��ģʽ","�Ż��㷨ģʽ","�����㷨ģʽ"};

typedef struct AVCMODEL_CTRLPARAM				//AVC���Ʋ�����_ģ��
{
	char sysinfo[16];								//ϵͳ��Ϣ
	char avcmsg[64];								//������Ϣ
	int avcnum;										//���д���
	int strtime;									//��ʼʱ��
	int avctime;									//�������ʱ��
	unsigned char run;								//����״̬									0��1��
	unsigned char aut;								//�Զ�����									0��1��
	unsigned char abort;							//�����˳�									0��1��
	unsigned char cmd;								//�����·�									0��1��
	unsigned char remote;							//Զ��ģʽ									0��1��
	short cycvol;									//��������
	int ctrlmtd;									//�����㷨									0Ĭ��ģʽ��1�Ż��㷨ģʽ��2�����㷨ģʽ
	unsigned char ctrlre;							//����������									0��1��
	unsigned char ctrlcq;							//�����޹�����									0��1��
	unsigned char ctrltcv;							//�����ѹ����									0��1��
	int xfregin;									//�������ʱ����
	int cpouin;										//����Ͷ����г�ʱ��
	int cpinin;										//�����г���Ͷ��ʱ��
	int znctlin;									//�������ʱ����
	float xfnvid;									//float�������ϵ��
	float avcuper;									//AVC������
	int avcautt;									//AVC�ջ�ʱ��
	int ctrlnum;									//����ָ�����
	int ctrlsuc;									//���Ƴɹ�����
	float sucper;									//���Ƴɹ���
	int mxopnum;									//���ɶ��豸��
	int cpacfnm;									//�ݿ��ܶ�����
	int xfacfnm;									//����ܶ�����
	int enable;										//AVC���ñ�־
	float lossdec;									//�ս�����
}AVCMODEL_CTRLPARAM;

typedef struct AVCMODEL_RUNPARAM					//AVC���в���_ģ��
{
	int keyno;												//���
	int strtm;												//��ʼʱ��
	int endtm;												//����ʱ��
	short type;												//ʱ������
	int cpnum;												//���ݿ��ô���
	int xfnum;												//��ѹ�����ô���
	float cosfup;											//�ؿڹ�����������
	float cosfdn;											//�ؿڹ�����������
	float scosfup;											//��վ������������
	float scosfdn;											//��վ������������
	float v6up;												//6kv��ѹ����
	float v6dn;												//6kv��ѹ����
	float v10up;											//10kv��ѹ����
	float v10dn;											//10kv��ѹ����
	float v35up;											//35kv��ѹ����
	float v35dn;											//35kv��ѹ����
	float v110up;											//110kv��ѹ����
	float v110dn;											//110kv��ѹ����
	float v220up;											//220kv��ѹ����
	float v220dn;											//220kv��ѹ����
	float v330up;											//330kv��ѹ����
	float v330dn;											//330kv��ѹ����
	float v500up;											//330kv��ѹ����
	float v500dn;											//330kv��ѹ����
}AVCMODEL_RUNPARAM;

typedef struct AVCMODEL_TIMEPART						//AVCʱ�ο��ƶ���_ģ��
{
	int keyno;												//���
	char id[32];											//ʱ������
	float vup1;												//��ѹ����1
	float vdn1;												//��ѹ����1
	float cpnum1;											//���ݿ��ô���1
	float xfnum1;											//��ѹ�����ô���1
	float cosfup1;											//������������1
	float cosfdn1;											//������������1
	int tm1;												//ʱ��1�ָ��
	float vup2;												//��ѹ����2
	float vdn2;												//��ѹ����2
	float cpnum2;											//���ݿ��ô���2
	float xfnum2;											//��ѹ�����ô���2
	float cosfup2;											//������������2
	float cosfdn2;											//������������2
	int tm2;												//ʱ��2�ָ��
	float vup3;												//��ѹ����3
	float vdn3;												//��ѹ����3
	float cpnum3;											//���ݿ��ô���3
	float xfnum3;											//��ѹ�����ô���3
	float cosfup3;											//������������3
	float cosfdn3;											//������������3
	int tm3;												//ʱ��3�ָ��
	float vup4;												//��ѹ����4
	float vdn4;												//��ѹ����4
	float cpnum4;											//���ݿ��ô���4
	float xfnum4;											//��ѹ�����ô���4
	float cosfup4;											//������������4
	float cosfdn4;											//������������4
	int tm4;												//ʱ��4�ָ��
	float vup5;												//��ѹ����5
	float vdn5;												//��ѹ����5
	float cpnum5;											//���ݿ��ô���5
	float xfnum5;											//��ѹ�����ô���5
	float cosfup5;											//������������5
	float cosfdn5;											//������������5
	int tm5;												//ʱ��5�ָ��			
	float vup6;												//��ѹ����6
	float vdn6;												//��ѹ����6
	float cpnum6;											//���ݿ��ô���6
	float xfnum6;											//��ѹ�����ô���6
	float cosfup6;											//������������6
	float cosfdn6;											//������������6
}AVCMODEL_TIMEPART;

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
typedef struct AVCMODEL_WARNTYPE				//AVC�澯���Ͷ���_ģ��
{
	int keyno;										//���
	int id;											//�澯ID
	//0ң���쳣��1�ֽ�ͷ�ܶ���2�ֽ�ͷ������3�ݿ����ܶ���4�����������5�ֹ�������6ң��ң�Ų�ƥ�䡢7�����쳣��8������ء�9ĸ�߹���ѹ��10ĸ��Ƿ��ѹ��11��������Խ�ޡ�12�豸�䱸�á�
	//13�޵��ڴ�ʩ��14���ⲻˢ�¡�15������ѹ�쳣��16ʱ�����ô���17����ӵء�18�����ѹ��ƽ�⡢19���⻵���ݡ�20�豸���ơ�21�������ݱ�����22��������ͬ�����
	short ot;										//�澯�豸����									��ѡ��1AVCϵͳ��2��ѹ����3��������4�������5ĸ�ߡ�6��վ
	char txt[32];									//�澯����
	unsigned char qskip;							//�Ƿ����Ƹ澯									0��1��									
	unsigned char qlock;							//�������鷽ʽ									0�˹�������1�Զ�����
	unsigned char qsend;							//�Ƿ��͸澯										0��1��
	int deltm;										//������ʱʱ��
}AVCMODEL_WARNTYPE;

typedef struct AVCMODEL_CTRLPLOY						//AVC���Ʋ���_ģ��
{
	int keyno;												//���
	char stm[32];											//��վ������
	char id[24];											//�豸��
	int facid;												//��վID
	int devid;												//�豸ID
	int devsub;												//�����豸�±�
	int	isstm;												//����ʱ��
	int comtm;												//ִ��ʱ��
	char cause[80];										//ԭ��
	char result[80];									//��ʩ
	char text[120];										//������Ϣ
	char cmdtype[8];									//��������
	short opftype;										//��������
	char rslttype[12];								//����״̬
	unsigned char qcheck;							//����ȷ��										0��1��
	unsigned char qaut;								//�Կ�����										0��1��
	int seq;													//������
	int zone;													//����ID
	int resp;													//������
}AVCMODEL_CTRLPLOY;

#define RESETLOCK_MANUAL 0
#define RESETLOCK_AUTO 1
const char RESETLOCK_NAME[][10]={"�˹�����","�Զ�����"};
typedef struct AVCMODEL_WARNDEFINE						//AVC�澯�ź�_ģ��
{
	int fac_id;												//��վID��
	int devid;												//�澯�豸ID��
	int atyid;												//�澯����ID��
	unsigned char qlock;							//�������鷽ʽ								0�˹�������1�Զ�����
	unsigned char stat;								//����״̬										0��1��
	short almtyp;											//�澯����
	int ontm;													//����ʱ��
	int offtm;												//����ʱ��
}AVCMODEL_WARNDEFINE;

typedef struct AVCMODEL_RELAY							//AVC������Ϣ����_ģ��
{
	int fac_id;												//��վID
	int rlyid;												//��������
	unsigned char stat;										//״̬										0��1��
	short qlock;											//�������鷽ʽ								0�˹�������1�Զ�����
	int devid1;												//�����豸
	int ontm;												//����ʱ��
	int offtm;												//����ʱ��
}AVCMODEL_RELAY;

typedef struct AVCREAL_VOLEVENT						//AVC��ѹԽ���¼���
{
	int keyno;												//���
	char st[32];											//��վ
	char id[32];											//ĸ����
	float val;												//��ѹֵ
	float lmt;												//��ѹ��ֵ
}AVCREAL_VOLEVENT;

typedef struct AVCREAL_CMDEVENT						//AVC������Ϣ�¼���
{		
	int keyno;												//���
	char usr[12];											//�û���
	_int64 time;											//����ʱ��
	char opefunc[24];										//������
	char text[120];											//��������
}AVCREAL_CMDEVENT;	

typedef struct AVCREAL_TRANSEVENT					//AVC��ѹ�������¼���
{
	int keyno;												//���
	char stm[32];											//��վ��
	char chid[16];											//��ѹ����
	short sub;												//�������
	int fadid;												//��վId
	int id;													//��ѹ��ID
	_int64 optime;											//����ʱ��
	short afttap;											//������λ
	short pretap;											//����ǰ��λ
	float val;												//�������ѹ
	char optypt[8];											//��������
	float prekv;											//����ǰ��ѹ
	float prevh;											//����ǰ��ѹ��ѹ
	float prewh;											//����ǰ��ѹ�й�
	float prerh;											//����ǰ��ѹ�޹�
	float prevm;											//����ǰ��ѹ��ѹ
	float prewm;											//����ǰ��ѹ�й�
	float prerm;											//����ǰ��ѹ�޹�
	float prevl;											//����ǰ��ѹ��ѹ
	float prewl;											//����ǰ��ѹ�й�
	float prerl;											//����ǰ��ѹ�޹�
	float aftvh;											//�������ѹ��ѹ
	float aftwh;											//�������ѹ�й�
	float aftrh;											//�������ѹ�޹�
	float aftvm;											//��������ѹ��ѹ
	float aftwm;											//��������ѹ�й�
	float aftrm;											//��������ѹ�޹�
	float aftvl;											//�������ѹ��ѹ
	float aftwl;											//�������ѹ�й�
	float aftrl;											//�������ѹ�޹�
	unsigned char qavc;										//�Ƿ�AVC����										0��1��
}AVCREAL_TRANSEVENT;

typedef struct AVCREAL_SHUNTEVENT							//AVC���ݿ��ƶ����¼���
{
	int keyno;												//���
	char stm[32];											//��վ��
	char chid[32];											//��������
	short sub;												//���������
	int facid;												//��վID
	int id;													//������ID
	_int64 optime;											//����ʱ��
	char optype[8];											//��������
	float val;												//�������ѹ
	float prekv;											//����ǰ��ѹ
	unsigned char qopen;									//����������״̬								0Ͷ�롢1�˳�
	unsigned char qavc;										//�Ƿ�AVCָ��										0��1��
}AVCREAL_SHUNTEVENT;

typedef struct AVCREAL_CTRLZONE								//AVC���������
{
	int keyno;												//���
	char chid[32];											//��������
	int vovnum;												//��ѹ����Խ����
	int qovnum;												//�޹�����Խ����
	float wloss;											//��������ֵ
	int normcp;												//�ɿص�����
	int lockcp;												//����������
	int normxf;												//�ɿر�ѹ����
	int lockxf;												//������ѹ����
	float varin;											//��Ͷ�޹�������
	float varoff;											//δͶ�޹�������
	float cosfi;											//�ؿڹ�������
	float score;											//����״̬�÷�
}AVCREAL_CTRLZONE;

typedef struct AVCREAL_STATE						//AVCͳ����Ϣ��
{
	int keyno;												//���
	int devid;												//�豸ID
	int fac_id;												//��վID
	int numall;												//�ն�������
	int numavc;												//�ճɹ�����
	int numorder;											//���������
	int numfail;											//��ʧ�ܴ���
	float sucrate;											//float�ճɹ���
	char devname[32];										//�豸������
}AVCREAL_STATE;

typedef struct AVCREAL_ZONECHANGE					//AVCʡ�ؽ�����Ϣ��
{
	int keyno;												//���
	int objtype;											//��������
	int objid;												//����ID
	int objcdid;											//������ID
	float fval;												//����ֵ
	int datdir;												//���ݴ��䷽��
}AVCREAL_ZONECHANGE;

#endif // !defined(AFX_OPEN3000_H__INCLUDED_)