#pragma once

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

#pragma pack(8)

struct MODEL_VL_TYPE
{
	int vlty_id; //��ѹ����ID��
	float vbase; //��ѹ��ֵ
};

//��·����Ϣ��
struct MODEL_BRK_DEVICE
{
	int brk_id;
	int fac_id;//��վID
	char brk_name[64];//��·������
	int vlty_id; //��ѹ����ID��
	int nd1_no;//�ڵ�1��
	int nd2_no;//�ڵ�2��
	int run_state;//ң��״̬
};

//��բ��
struct MODEL_DISCR_DEVICE
{
	int discr_id;
	int fac_id;//��վID
	char discr_name[64];//��բ����
	int vlty_id; //��ѹ����ID��
	int nd1_no;  //�ڵ�1��
	int nd2_no;  //�ڵ�2��
	int run_state;//ң��״̬
};

//�ӵص�բ��
struct MODEL_GDDISCR_DEVICE
{
	int gddiscr_id;
	int fac_id;//��վID
	char gddiscr_name[64];//�ӵص�բ����
	int vlty_id; //��ѹ����ID��
	int nd_no;//�ڵ��
};

//ĸ�߱�
struct MODEL_BS_DEVICE
{
	int bs_id;  //
	int fac_id;//��վID
	char bs_name[64];//ĸ������
	int vlty_id; //��ѹ����ID��
	float vmax; //��ѹ����
	float vmin; //��ѹ����
	int nd_no;//�ڵ��
	int run_state;  //Ͷ��״̬
};

//��ѹ����
struct MODEL_TR_DEVICE
{
	int tr_id;          //��ѹ��ID��
	int fac_id;			//��վID
	char tr_name[64];   //��ѹ������
	char trty;		    //��������
	int run_state;		//Ͷ��״̬
};

//��ѹ������
struct MODEL_TRWD_DEVICE
{
	int trwd_id;        //��ѹ������ID
	int fac_id;         //��վID
	char trwd_name[64]; //��ѹ����������
	int tr_id;          //��ѹ��ID��
	char trwd_type;     //��ѹ����������
	float vnom;         //���ѹ
	int nd_no;          //�ڵ��
	int vlty_id; //��ѹ����ID��
	float snom;//�����
	int tapty_id;//�ֽ�ͷ
	float pk;//��·���
	float uk; //��·��ѹ�ٷ�
	float tapty_pos;
	float r_value_pu;//����������ֵ
	float x_value_pu;//����翹����ֵ
	float r0_value_pu;//����������ֵ
	float x0_value_pu;//����翹����ֵ
};

//��ѹ�����鵵λ
struct MODEL_TAP_DEVICE
{
	int tapty_id;				//����ID
	char taptye_name[64];        //��ѹ������ID
	int tapty_mn;
	int tapty_mx;
	int tapty_nom;
	float tapty_step;
};

//�������
struct MODEL_GN_DEVICE
{
	int gn_id;    //�����id
	int fac_id;    //��վID��
	char gn_name[64]; //���������
	int vlty_id;   //��ѹ����ID��
	float pmax;    //�й�����
	int nd_no;     //�ڵ��
	int run_state;      //�����״̬
};

//����
struct MODEL_LD_DEVICE
{
	int ld_id;
	int fac_id;//��վID��
	char ld_name[64];//��������
	int vlty_id;   //��ѹ����ID��
	int nd_no;     //�ڵ��
	int run_state;      //����״̬
};

//�����߶α�
struct MODEL_ACLN_DEVICE
{
	int acln_id;
	int fac_id_s;        //һ�˳�վID
	int fac_id_e;        //���˳�վID;
	char acln_name[64];  //�����߶�����
	int vlty_id;         //��ѹ����ID��
	int line_id;         //��·ID��
	float smax;          //������ֵ
	float imax1;			//��������
	unsigned char eq_fg;//��ֵ����
	int run_state;       //��·״̬

	float r_value_pu;     //����������ֵ
	float x_value_pu;	  //����翹����ֵ
	float bch_value_pu;   //������ɱ���ֵ

	float r0_value_pu;     //����������ֵ
	float x0_value_pu;	   //����翹����ֵ
	float bch0_value_pu;   //������ɱ���ֵ

};

//�����߶ζ˵��
struct MODEL_ACLN_DOT
{
	int fac_id;            //��վID
	char acln_dot_name[64];//�����߶ζ˵������
	int acln_id;           //���������߶�ID��
	int vlty_id;           //��ѹ����ID��
	int nd_no;             //�ڵ��
};

//��վ��Ϣ��
struct MODEL_FAC_INFO
{
	int fac_id;        //��վID
	char fac_name[64]; //��վ����
	short fac_serial;  //��վ���
	int area_id;       //����ID
	int fac_type;      //��վ����
	int vlty_id;       //��ѹ����ID��
};

//���������
struct MODEL_DIV_INFO
{
	int area_id;
	char area_name[64]; //��������
	short area_no;      //������
};

//�ݿ�����  ���ݺ͵翹
struct MODEL_RC_DEVICE
{
	int rc_id;
	int fac_id;            //��վID
	char rc_name[64]; //�ݿ�������
	int vlty_id;       //��ѹ����ID��
	unsigned char rc_type;//�ݿ�������
	int nd1_no;      //�ڵ�1��
	int nd2_no;//�ڵ�2��
	int nd3_no;//�ڵ�3��
	int run_state;  //״̬
	float qnom;		//�����
	float vnom;		//���ѹ
	int q_status;	//����״̬
};

//AVC��վ���ƶ���
struct AVC_STATION			
{
	int fac_id;					//��վID
	int respar;					//����������
	unsigned char remove;		//��վ�ų�
	unsigned char qaut;			//�Զ�����
	int pltyp;					//ʱ������
	unsigned char qdevlck;		//�����豸����
};


//AVCĸ�߿���
struct AVC_BUS
{
	int fac_id;					//��վID
	int bsid;					//ĸ��ID
	int pltyp;					//ʱ������
//	float val;					//��ѹֵ
//	float vup;					//��ѹ����
//	float vdn;					//��ѹ����
	unsigned char offavr;		//����״̬
	unsigned char qavr;			//�������
	unsigned char qgate;		//�ؿ�ĸ��
//	int iszone;					//��������
};

//AVC��ѹ������
struct AVC_TRANS
{
	int fac_id;					//��վID
	int trid;					//��ѹ��ID
	int pltyp;					//ʱ������
	unsigned char offavr;		//����״̬
	unsigned char qavr;			//�������
	short limtnum;				//������ֵ
	int upyxid;					//����ң��ID
	int upykno;					//����ң�ص��
	int dnyxid;					//����ң��ID
	int dnykno;					//����ң�ص��
};

//AVC���ݿ���
struct AVC_SHUNT
{
	int fac_id;					//��վID
	int cpid;					//����ID
	unsigned char offavr;		//����״̬
	unsigned char qavr;			//�������
	int pltyp;					//ʱ������
//	int iszone;					//��������
};

//AVC���Ʋ���
struct AVC_CtrlParam
{
	int fac_id;					//��վID
	int shid;					//ĸ��ID
	int pltyp;					//ʱ������
	unsigned char offavr;		//����״̬
	unsigned char qavr;			//�������
	int iszone;					//��������
};

//AVC���в���
struct AVC_RunParam
{
	int strtm;					//��ʼʱ��
	int endtm;					//��ֹʱ��
	short type;					//ʱ������
	int cpnum;					//���ݿ�����
	int xfnum;					//��ѹ��������
	float cosfup;				//�ؿڹ�������
	float cosfdn;				//�ؿڹ�������
	float scosfup;				//��վ��������
	float scosfdn;				//��վ��������
	float v6up;					//6kv��ѹ����
	float v6dn;					//6kv��ѹ����
	float v10up;				//10kv��ѹ����
	float v10dn;				//10kv��ѹ����
	float v35up;				//35kv��ѹ����
	float v35dn;				//35kv��ѹ����
	float v110up;				//110kv��ѹ����
	float v110dn;				//110kv��ѹ����
	float v220up;				//220kv��ѹ����
	float v220dn;				//220kv��ѹ����
	float v500up;				//500kv��ѹ����
	float v500dn;				//500kv��ѹ����
};

//AVC�豸����ʱ�ζ���
struct AVC_TimePart
{
	int keyno;					//���
	char idname[32];			//ʱ�ζ�������
	float vup1;					//��ѹ����1
	float vdn1;					//��ѹ����1
	short cpnum1;				//���ݿ�����1
	short xfnum1;				//����������1
	float cosfup1;				//��������1
	float cosfdn1;				//��������1
	int tm1;					//ʱ��1
	float vup2;					//��ѹ����2
	float vdn2;					//��ѹ����2
	int cpnum2;				//���ݿ�����2
	int xfnum2;				//����������2
	float cosfup2;				//��������2
	float cosfdn2;				//��������2
	int tm2;					//ʱ��2
	float vup3;					//��ѹ����3
	float vdn3;					//��ѹ����3
	int cpnum3;				//���ݿ�����3
	int xfnum3;				//����������3
	float cosfup3;				//��������3
	float cosfdn3;				//��������3
	int tm3;					//ʱ��3
	float vup4;					//��ѹ����4
	float vdn4;					//��ѹ����4
	int cpnum4;				//���ݿ�����4
	int xfnum4;				//����������4
	float cosfup4;				//��������4
	float cosfdn4;				//��������4
	int tm4;					//ʱ��4
	float vup5;					//��ѹ����5
	float vdn5;					//��ѹ����5
	int cpnum5;				//���ݿ�����5
	int xfnum5;				//����������5
	float cosfup5;				//��������5
	float cosfdn5;				//��������5
	int tm5;					//ʱ��5
//	int tm6;					//ʱ��6
	float vup6;					//��ѹ����6
	float vdn6;					//��ѹ����6
	int cpnum6;				//���ݿ�����6
	int xfnum6;				//����������6
	float cosfup6;				//��������6
	float cosfdn6;				//��������6
};

//�����źű�
struct AVC_Relay
{
	int fac_id;					//����
	int rlyid;					//��������
	unsigned char stat;			//״̬
	short qlock;				//�������鷽ʽ
	int devid1;					//�����豸
	int ontm;					//����ʱ��
	int offtm;					//����ʱ��
};

#pragma pack()