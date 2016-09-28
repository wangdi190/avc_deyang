#ifndef Open3000Model_H
#define Open3000Model_H


#define VL_TYPE_MODEL 16777416
#define DIV_INFO_MODEL 16777425
#define FAC_INFO_MODEL 16777426
#define BRK_DEVICE_MODEL 16777436
#define DISCR_DEVICE_MODEL 16777437
#define GDDISCR_DEVICE_MODEL 16777438
#define BS_DEVICE_MODEL 16777446
#define ACLN_DEVICE_MODEL 16777456
#define ACLN_DOT_MODEL 16777458
#define TR_DEVICE_MODEL 16777466
#define TRWD_DEVICE_MODEL 16777467
#define TAP_TYPE_MODEL 16777468
#define GN_DEVICE_MODEL 16777476
#define LD_DEVICE_MODEL 16777486
#define RC_DEVICE_MODEL 16777491
#define DIILND_COMM_EMS_MODEL 16778228
#define RECENTMSG_COMM_EMS_MODEL 16778231
#define PARA_RTNET_EMS_MODEL 16778236
#define SEMEAS_RTNET_EMS_MODEL 16778246
#define STM_AVC_EMS_MODEL 16778387
#define NDM_AVC_EMS_MODEL 16778388
#define XFM_AVC_EMS_MODEL 16778389
#define CPM_AVC_EMS_MODEL 16778390
#define ITEM_AVC_EMS_MODEL 16778391
#define RUNPLT_AVC_EMS_MODEL 16778392
#define DEVPLT_AVC_EMS_MODEL 16778393
#define ALMTYP_AVC_EMS_MODEL 16778394
#define OPBUFF_AVC_EMS_MODEL 16778398
#define ALMYX_AVC_EMS_MODEL 16778399
#define RELAY_AVC_EMS_MODEL 16778400
#define OVBUS_AVC_EMS_MODEL 16778401
#define AOPMSG_AVC_EMS_MODEL 16778402
#define XFACT_AVC_EMS_MODEL 16778404
#define CPACT_AVC_EMS_MODEL 16778405
#define ZONE_AVC_EMS_MODEL 16778407
#define STAT_AVC_EMS_MODEL 16778410
#define EXCHG_AVC_EMS_MODEL 16778414


//��ѹ���ͱ� Model
struct VL_TYPE_Model
{
  int vlty_id;    //��ѹ����ID��
  float vbase;    //��ѹ��ֵ

};

//��������� Model
struct DIV_INFO_Model
{
  int area_id;    //����ID��
  char area_name[64];    //��������
  short area_no;    //������

};

//��վ��Ϣ�� Model
struct FAC_INFO_Model
{
  int fac_id;    //��վID
  int area_id;    //����ID
  char fac_name[64];    //��վ����
  short fac_serial;    //��վ���
  unsigned char fac_type;    //��վ����
  int vlty_id;    //��ߵ�ѹ�ȼ�

};

//��·����Ϣ�� Model
struct BRK_DEVICE_Model
{
  int brk_id;    //��·��ID��
  int fac_id;    //��վID��
  char brk_name[64];    //��·������
  int vlty_id;    //��ѹ����ID��
  int nd1_no;    //�ڵ�1��
  int nd2_no;    //�ڵ�2��
  int run_state;    //Ͷ��״̬

};

//��բ�� Model
struct DISCR_DEVICE_Model
{
  int discr_id;    //��բID��
  int fac_id;    //��վID��
  char discr_name[64];    //��բ����
  int vlty_id;    //��ѹ����ID��
  int nd1_no;    //�ڵ�1��
  int nd2_no;    //�ڵ�2��
  int run_state;    //Ͷ��״̬

};

//�ӵص�բ�� Model
struct GDDISCR_DEVICE_Model
{
  int gddiscr_id;    //�ӵص�բID��
  int fac_id;    //��վID��
  char gddiscr_name[64];    //�ӵص�բ����
  int vlty_id;    //��ѹ����ID��
  int nd_no;    //�ڵ��

};

//ĸ�߱� Model
struct BS_DEVICE_Model
{
  int bs_id;    //ĸ��ID��
  int fac_id;    //��վID��
  char bs_name[64];    //ĸ������
  int vlty_id;    //��ѹ����ID��
  float vmax;    //��ѹ����
  float vmin;    //��ѹ����
  int nd_no;    //�ڵ��
  int run_state;    //Ͷ��״̬

};

//�����߶α� Model
struct ACLN_DEVICE_Model
{
  int acln_id;    //�����߶�ID��
  int fac_id_s;    //һ�˳�վID��
  int fac_id_e;    //���˳�վID��
  char acln_name[64];    //�����߶�����
  int line_id;    //��·ID��
  float smax;    //������ֵ
  float imax1;    //����������
  int vlty_id;    //��ѹ����ID��
  unsigned char eq_fg;    //��ֵ��־
  float r_value_pu;    //����������ֵ
  float x_value_pu;    //����翹����ֵ
  float bch_value_pu;    //������ɱ���ֵ
  float r0_value_pu;    //����������ֵ
  float x0_value_pu;    //����翹����ֵ
  float bch0_value_pu;    //������ɱ���ֵ
  int run_state;    //Ͷ��״̬

};

//�����߶ζ˵�� Model
struct ACLN_DOT_Model
{
  int fac_id;    //��վID��
  char acln_dot_name[64];    //�����߶ζ˵�����
  int acln_id;    //���������߶�ID��
  int vlty_id;    //��ѹ����ID��
  int nd_no;    //�ڵ��

};

//��ѹ���� Model
struct TR_DEVICE_Model
{
  int tr_id;    //��ѹ��ID��
  int fac_id;    //��վID��
  char tr_name[64];    //��ѹ������
  unsigned char trty;    //��������
  int run_state;    //Ͷ��״̬

};

//��ѹ������� Model
struct TRWD_DEVICE_Model
{
  int trwd_id;    //��ѹ������ID��
  int fac_id;    //��վID��
  char trwd_name[64];    //��ѹ����������
  int tr_id;    //��ѹ��ID��
  int vlty_id;    //��ѹ����ID��
  unsigned char trwd_type;    //��ѹ����������
  int tapty_id;    //�ֽ�ͷ����ID��
  float snom;    //�����
  float vnom;    //���ѹ
  int nd_no;    //�ڵ��
  float pk;    //��·���
  float uk;    //��·��ѹ�ٷ�ֵ
  float r_value_pu;    //����������ֵ
  float x_value_pu;    //����翹����ֵ
  float r0_value_pu;    //����������ֵ
  float x0_value_pu;    //����翹����ֵ
  float tap_pos;    //�ֽ�ͷλ��

};

//��ѹ���ֽ�ͷ���ͱ� Model
struct TAP_TYPE_Model
{
  int tapty_id;    //��ѹ���ֽ�ͷ����ID
  char tapty_name[64];    //��ѹ���ֽ�ͷ��������
  int tapty_mn;    //��С��λ
  int tapty_mx;    //���λ
  int tapty_nom;    //���λ
  float tapty_step;    //����

};

//������� Model
struct GN_DEVICE_Model
{
  int gn_id;    //�����ID��
  int fac_id;    //��վID��
  char gn_name[64];    //���������
  int vlty_id;    //��ѹ����ID��
  float snom;    //�����
  float pmax;    //�й�����
  int nd_no;    //�ڵ��
  int run_state;    //Ͷ��״̬

};

//���ɱ� Model
struct LD_DEVICE_Model
{
  int ld_id;    //����ID��
  int fac_id;    //��վID��
  char ld_name[64];    //��������
  int vlty_id;    //��ѹ����ID��
  int nd_no;    //�ڵ��
  int run_state;    //Ͷ��״̬

};

//�ݿ����� Model
struct RC_DEVICE_Model
{
  int rc_id;    //�ݿ���ID��
  int fac_id;    //��վID��
  char rc_name[64];    //�ݿ�������
  int vlty_id;    //��ѹ����ID��
  unsigned char rc_type;    //�ݿ�������
  float qnom;    //�����
  float vnom;    //���ѹ
  int nd1_no;    //�ڵ�1��
  int nd2_no;    //�ڵ�2��
  int nd3_no;    //�ڵ�3��
  int q_status;    //�޹�״̬
  int run_state;    //Ͷ��״̬

};

//PAS��������Ϣ�� Model
struct DIILND_COMM_EMS_Model
{
  int keyno;    //���
  short isrec;    //����
  char chst[16];    //ƽ�����վ��
  int stid;    //ƽ�����վID
  char un[20];    //ƽ�������
  int unid;    //ƽ���ID
  short bus;    //�ڵ���
  unsigned char stat;    //����״̬
  unsigned char obisle;    //�Ƿ�ɹ۲�
  unsigned char lvbadp;    //�й������ݵ���
  unsigned char lvbadq;    //�޹������ݵ���

};

//PAS���������Ϣ�� Model
struct RECENTMSG_COMM_EMS_Model
{
  CTime time;    //ʱ��
  char msg[160];    //��Ϣ

};

//״̬���Ʋ�������Ϣ�� Model
struct PARA_RTNET_EMS_Model
{
  unsigned char pause_flag;    //��ͣ�����־
  int conv_state;    //����״̬
  int run_flag;    //�����б�־
  float estimable_rate;    //���⸲����
  CTime datemark;    //�մ�
  float conv_rate;    //����������
  CTime hourmark;    //ʱ��
  float cycle_period;    //��������(��)
  int iter_step_limit;    //����������
  float epsp;    //�й���������
  float epsq;    //�޹���������

};

//״̬��������һ���� Model
struct SEMEAS_RTNET_EMS_Model
{
  int keyno;    //���
  int stid;    //��վ����
  int devid;    //�豸����
  short meassub;    //�����±�
  short type;    //��������
  int devmtyp;    //�豸��������
  float measval;    //����ֵ
  float seval;    //״̬����ֵ
  float err;    //���ٷ���
  unsigned char qbigerr;    //������
  unsigned char qbad;    //������

};

//AVC��վ���Ʊ� Model
struct STM_AVC_EMS_Model
{
  int fac_id;    //��վID
  int respar;    //����������
  unsigned char remove;    //��վ�ų�
  unsigned char qaut;    //�Զ�����
  int pltyp;    //ʱ������
  unsigned char qdevlck;    //�����豸����

};

//AVCĸ�߿��Ʊ� Model
struct NDM_AVC_EMS_Model
{
  int fac_id;    //��վID
  int bsid;    //ĸ��ID��
  int pltyp;    //ʱ������
  unsigned char offavr;    //����״̬
  unsigned char qavr;    //�������
  unsigned char qgate;    //�ؿ�ĸ��

};

//AVC��ѹ�����Ʊ� Model
struct XFM_AVC_EMS_Model
{
  int fac_id;    //��վID
  int trid;    //��ѹ��ID��
  unsigned char offavr;    //����״̬
  unsigned char qavr;    //�������
  int pltyp;    //ʱ������
  short limtnum;    //����������ֵ
  int upyxid;    //����ң��ID
  int upykno;    //����ң�ص��
  int dnyxid;    //����ң��ID
  int dnykno;    //����ң�ص��
  int isbsid;    //����ĸ��ID
  int numday;    //��AVC��������
  int tnumday;    //���ܶ�������
  int cnumday;    //��AVC���ƴ���
  int nummon;    //��AVC��������
  int tnummon;    //���ܶ�������
  int cnummon;    //��AVC���ƴ���
  int numyea;    //��AVC��������
  int tnumyea;    //���ܶ�������
  int cnumyea;    //��AVC���ƴ���
  unsigned char qgate;    //�ؿ�����

};

//AVC���������Ʊ� Model
struct CPM_AVC_EMS_Model
{
  int fac_id;    //��վID
  int cpid;    //������ID��
  unsigned char offavr;    //����״̬
  unsigned char qavr;    //�������
  int pltyp;    //ʱ������
  short limtnum;    //����������ֵ
  int yxid;    //���ƿ���ID
  int ykno;    //ң�����
  int isbsid;    //����ĸ��ID
  int numday;    //��AVC��������
  int tnumday;    //���ܶ�������
  int cnumday;    //��AVC���ƴ���
  int nummon;    //��AVC��������
  int tnummon;    //���ܶ�������
  int cnummon;    //��AVC���ƴ���
  int numyea;    //��AVC��������
  int tnumyea;    //���ܶ�������
  int cnumyea;    //��AVC���ƴ���
  int rtmday;    //������ʱ��
  int rtmmon;    //������ʱ��
  int rtmyea;    //������ʱ��

};

//AVC���Ʋ����� Model
struct ITEM_AVC_EMS_Model
{
  char sysinfo[16];    //ϵͳ��Ϣ
  char avcmsg[64];    //������Ϣ
  int avcnum;    //���д���
  CTime strtime;    //��ʼʱ��
  CTime avctime;    //�������ʱ��
  unsigned char run;    //����״̬
  unsigned char aut;    //�Զ�����
  unsigned char abort;    //�����˳�
  unsigned char cmd;    //�����·�
  unsigned char remote;    //Զ��ģʽ
  short cycvol;    //��������
  int ctrlmtd;    //�����㷨
  unsigned char ctrlre;    //�翹������
  unsigned char ctrlcq;    //�����޹�����
  unsigned char ctrltcv;    //�����ѹ����
  int xfregin;    //�������ʱ����
  int cpouin;    //������Ͷ����г�ʱ��
  int cpinin;    //�������г���Ͷ��ʱ��
  int znctlin;    //�������ʱ����
  float xfhvld;    //���������ϵ��
  float avcuper;    //AVC������
  int avcautt;    //AVC�ջ�ʱ��
  int ctrlnum;    //����ָ�����
  int ctrlsuc;    //���Ƴɹ�����
  float sucper;    //���Ƴɹ���
  int mxopnum;    //���ɶ��豸��
  int cpacfnm;    //�ݿ����оܶ�����
  int xfacfnm;    //�����оܶ�����
  int enable;    //AVC���ñ�־
  float lossdec;    //�ս�����

};

//AVC���в����� Model
struct RUNPLT_AVC_EMS_Model
{
  int keyno;    //���
  int strtm;    //��ʼʱ��
  int endtm;    //����ʱ��
  short type;    //ʱ������
  int cpnum;    //�������ɶ�����
  int xfnum;    //��ѹ���ɶ�����
  float cosfup;    //�ؿڹ�����������
  float cosfdn;    //�ؿڹ�����������
  float scosfup;    //��վ������������
  float scosfdn;    //��վ������������
  float v6up;    //6kV��ѹ����
  float v6dn;    //6kV��ѹ����
  float v10up;    //10kV��ѹ����
  float v10dn;    //10kV��ѹ����
  float v35up;    //35kV��ѹ����
  float v35dn;    //35kV��ѹ����
  float v110up;    //110kV��ѹ����
  float v110dn;    //110kV��ѹ����
  float v220up;    //220kV��ѹ����
  float v220dn;    //220kV��ѹ����
  float v330up;    //330kV��ѹ����
  float v330dn;    //330kV��ѹ����

};

//AVC�豸ʱ�����ͱ� Model
struct DEVPLT_AVC_EMS_Model
{
  int keyno;    //���
  char id[32];    //ʱ������
  float vup1;    //��ѹ����1
  float vdn1;    //��ѹ����1
  short cpnum1;    //�������ɶ�����1
  short xfnum1;    //��ѹ���ɶ�����1
  float cosfup1;    //������������1
  float cosfdn1;    //������������1
  int tm1;    //ʱ��1�ָ���
  float vup2;    //��ѹ����2
  float vdn2;    //��ѹ����2
  int cpnum2;    //�������ɶ�����2
  int xfnum2;    //��ѹ���ɶ�����2
  float cosfup2;    //������������2
  float cosfdn2;    //������������2
  int tm2;    //ʱ��2�ָ���
  float vup3;    //��ѹ����3
  float vdn3;    //��ѹ����3
  int cpnum3;    //�������ɶ�����3
  int xfnum3;    //��ѹ���ɶ�����3
  float cosfup3;    //������������3
  float cosfdn3;    //������������3
  int tm3;    //ʱ��3�ָ���
  float vup4;    //��ѹ����4
  float vdn4;    //��ѹ����4
  int cpnum4;    //�������ɶ�����4
  int xfnum4;    //��ѹ���ɶ�����4
  float cosfup4;    //������������4
  float cosfdn4;    //������������4
  int tm4;    //ʱ��4�ָ���
  float vup5;    //��ѹ����5
  float vdn5;    //��ѹ����5
  int cpnum5;    //�������ɶ�����5
  int xfnum5;    //��ѹ���ɶ�����5
  float cosfup5;    //������������5
  float cosfdn5;    //������������5
  int tm5;    //ʱ��5�ָ���
  float vup6;    //��ѹ����6
  float vdn6;    //��ѹ����6
  int cpnum6;    //�������ɶ�����6
  int xfnum6;    //��ѹ���ɶ�����6
  float cosfup6;    //������������6
  float cosfdn6;    //������������6

};

//AVC�澯���ͱ� Model
struct ALMTYP_AVC_EMS_Model
{
  int keyno;    //���
  int id;    //�澯����
  short ot;    //�澯�豸����
  char txt[32];    //�澯����
  unsigned char qskip;    //�Ƿ����Ƹ澯
  unsigned char qlock;    //�������鷽ʽ
  unsigned char qsend;    //�Ƿ��͸澯
  int deltm;    //������ʱʱ��

};

//AVC���Ʋ��Ա� Model
struct OPBUFF_AVC_EMS_Model
{
  int keyno;    //���
  char stm[32];    //��վ������
  char id[24];    //�豸��
  int facid;    //��վID
  int devid;    //�豸ID
  int devsub;    //�����豸�±�
  CTime isstm;    //����ʱ��
  CTime comtm;    //ִ��ʱ��
  char cause[80];    //ԭ��
  char result[80];    //��ʩ
  char text[120];    //������Ϣ
  char cmdtype[8];    //��������
  short optype;    //��������
  char rslttyp[12];    //����״̬
  unsigned char qcheck;    //����ȷ��
  unsigned char qaut;    //�Կ�����
  int seq;    //������
  int zone;    //����ID
  int resp;    //������

};

//AVC�澯�źű� Model
struct ALMYX_AVC_EMS_Model
{
  int fac_id;    //��վID��
  int devid;    //�澯�豸ID��
  int atyid;    //�澯����ID��
  unsigned char qlock;    //�������鷽ʽ
  unsigned char stat;    //����״̬
  short almtyp;    //�澯����
  int ontm;    //����ʱ��
  int offtm;    //����ʱ��

};

//AVC�����źű� Model
struct RELAY_AVC_EMS_Model
{
  int fac_id;    //��վID
  int rlyid;    //��������
  unsigned char stat;    //״̬
  short qlock;    //�������鷽ʽ
  int devid1;    //�����豸1
  int ontm;    //����ʱ��
  int offtm;    //����ʱ��

};

//AVC��ѹԽ�ޱ� Model
struct OVBUS_AVC_EMS_Model
{
  int keyno;    //���
  char st[32];    //��վ
  char id[32];    //ĸ����
  float val;    //��ѹֵ
  float lmt;    //��ѹ��ֵ

};

//AVC������Ϣ�� Model
struct AOPMSG_AVC_EMS_Model
{
  int keyno;    //���
  char usr[12];    //�û���
  CTime time;    //����ʱ��
  char opefunc[24];    //������
  char text[120];    //��������

};

//AVC��ѹ�������¼��� Model
struct XFACT_AVC_EMS_Model
{
  int keyno;    //���
  char stm[32];    //��վ��
  char chid[16];    //��ѹ��������
  short sub;    //�������
  int facid;    //��վID
  int id;    //��ѹ����
  CTime optime;    //����ʱ��
  short afttap;    //������λ
  short pretap;    //����ǰ��λ
  float val;    //�������ѹ
  char optype[8];    //��������
  float prekv;    //����ǰ��ѹ
  float prevh;    //����ǰ��ѹ���ѹ
  float prewh;    //����ǰ��ѹ���й�
  float prerh;    //����ǰ��ѹ���޹�
  float prevm;    //����ǰ��ѹ���ѹ
  float prewm;    //����ǰ��ѹ���й�
  float prerm;    //����ǰ��ѹ���޹�
  float prevl;    //����ǰ��ѹ���ѹ
  float prewl;    //����ǰ��ѹ���й�
  float prerl;    //����ǰ��ѹ���޹�
  float aftvh;    //�������ѹ���ѹ
  float aftwh;    //�������ѹ���й�
  float aftrh;    //�������ѹ���޹�
  float aftvm;    //��������ѹ���ѹ
  float aftwm;    //��������ѹ���й�
  float aftrm;    //��������ѹ���޹�
  float aftvl;    //�������ѹ���ѹ
  float aftwl;    //�������ѹ���й�
  float aftrl;    //�������ѹ���޹�
  unsigned char qavc;    //�Ƿ�AVCָ��

};

//AVC�����������¼��� Model
struct CPACT_AVC_EMS_Model
{
  int keyno;    //���
  char stm[32];    //��վ��
  char chid[32];    //������������
  short sub;    //���������
  int facid;    //��վID
  int id;    //��������
  CTime optime;    //����ʱ��
  char optype[8];    //��������
  float val;    //�������ѹ
  float prekv;    //����ǰ��ѹ
  unsigned char qopen;    //����������״̬
  unsigned char qavc;    //�Ƿ�AVCָ��

};

//AVC��������� Model
struct ZONE_AVC_EMS_Model
{
  int keyno;    //���
  char chid[32];    //��������
  int vovnum;    //��ѹ���˵�Խ����
  int qovnum;    //�޹����˵�Խ����
  float wloss;    //��������ֵ
  int normcp;    //�ɿ��ݿ�����
  int lockcp;    //�����ݿ�����
  int normxf;    //�ɿ�������
  int lockxf;    //����������
  float varin;    //��Ͷ�޹�������
  float varoff;    //δͶ�޹�������
  float cosfi;    //�ؿڹ�������
  float score;    //����״̬�÷�

};

//AVCͳ����Ϣ�� Model
struct STAT_AVC_EMS_Model
{
  int keyno;    //���
  int devid;    //�豸����
  int fac_id;    //��վ����
  int numall;    //�ն�������
  int numavc;    //�ճɹ�����
  int numorder;    //���������
  int numfail;    //��ʧ�ܴ���
  float sucrate;    //�ճɹ���
  char devname[64];    //�豸������

};

//AVCʡ�ؽ�����Ϣ�� Model
struct EXCHG_AVC_EMS_Model
{
  int keyno;    //���
  int objtyp;    //��������
  int objid;    //����ID
  int objcdid;    //������ID
  float fval;    //�������ֵ
  int datdir;    //���ݴ��ͷ���

};

#endif
