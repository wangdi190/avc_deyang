#if !defined(AFX_DEFV30_H__INCLUDED_)
#define AFX_DEFV30_H__INCLUDED_
#include "jhsyslibl.h"
#include "ptdefine.h"





//�����ʽV4.0��
////////////////////////////////////////////////
typedef struct N4_BASATTR{   //�����������  
	WORD  type;				 //��������
	BYTE  belong:3;			 //�������� ֻ�����ͼԪ����Ч
	BYTE  reserved:5;		 //����
	WORD  ID;				 //����ID
	WORD  size;              //�����ֽ���
	char  nouse[16];		 //����δ��
}N4_BASATTR;

typedef struct N4_DBX{		 //����� type=1  r1
	BYTE  fill:1;		     //0=����� 1=���
	BYTE  fillmode:3;		 //���ģʽ
	BYTE  ltype:3;			 //������
	BYTE  bgmode:1;			 //����ģʽ 0=ǰ�� 1=����
	DWORD lcolor;			 //����ɫ
	DWORD bcolor1;			 //�����ɫ1
	char  nouse[16];		 //����δ��
	WORD  ptsum;			 //������
	DPOINT pt[1];			 //������еĵ�
}N4_DBX;


typedef  struct N4_RECT{	 //���� type=2 r2
	DRECT  rt;				 //����
	BYTE   fill:1;			 //0=����� 1=��� 
	BYTE   fillmode:3;		 //��䷽ʽ 
	BYTE   type:2;			 //0=һ�����  1=�� 2=͹ 
	BYTE   reserved:2;		 //����
	DWORD  lcolor;			 //����ɫ
	DWORD  bcolor1;			 //�����ɫ1
	char   nouse[16];		 //����δ��
}N4_RECT;

typedef N4_RECT N4_CIRCLE;	 //԰ type=3  r3


typedef struct N4_HSIN{		 //���Ұ벨�� type=4  r4
	DRECT  rt;				 //����
	BYTE   hv:1;			 //ˮƽ��ֱ 0=ˮƽ 1=��ֱ
	BYTE   pirodic:7;		 //������
	DWORD  color;			 //����ɫ
	char   nouse[16];		 //����δ��
}N4_HSIN;

typedef struct N4_SIN{		 //���Ҳ���  type=5 r5
	DRECT rt;				 //����
	BYTE  hv:1;			     //������ 0=ˮƽ 1=��ֱ
	BYTE  pirodic:7;		 //������
	WORD  startdeg;			 //��ʼ�Ƕ�0-359
	DWORD color;			 //����ɫ
	char  nouse[16];		 //����δ��
}N4_SIN;

typedef struct N4_ARC{		 //԰�� type=6  r6
	DRECT  rt;				 //����
	DWORD  color;			 //��ɫ
	WORD   start;			 //��ʼ�Ƕ�
	WORD   end;				 //�����Ƕ�	
	char   nouse[16];		 //����δ��
}N4_ARC;

typedef struct N4_ARROW{     //�����ͷ  type=7  r7
	DPOINT  pt[2];			 //��������
	DWORD   color;			 //����ɫ
	char    nouse[16];		 //����δ��
}N4_ARROW;

typedef struct N4_GLASS{     //������    type=8
	DRECT  rt;				 //����
	BYTE   depth;			 //���
	BYTE   outline:1;		 //�Ƿ񻭱���
	BYTE   reserved:7;		 //����
	DWORD  color;			 //��ɫ
	DWORD  lcolor;			 //����ɫ
	char   nouse[16];		 //����δ��
}N4_GLASS;

typedef struct N4_TEXT{      //�ı�  type=10    r9
	DRECT   rt;				 //����
	double  zm;				 //��ͼʱ�ı���
	LOGFONT font;			 //����
    DWORD   color;			 //��ɫ
	BYTE    autofit:1;		 //����Ӧ
    BYTE    style:2;		 //ʽ��
	BYTE    reserved:5;
	WORD    angle;			 //�Ƕ�
	char    nouse[16];		 //����δ��
    char    text[1];		 //�ı�����,������е��ַ�
}N4_TEXT;

typedef struct N4_ESITE{	 //��������type=11
	DRECT  rt;				 //����
	DWORD  color;			 //������ʾ��ɫ
	BYTE   solder:1;		 //���� 0=���� 1=û��
	BYTE   reserved:7;		 //����
	char   nouse[16];		 //����δ��
}N4_ESITE;

typedef struct N4_EGPMB{	 //���ͼԪĸ�� type=12 
	DRECT  rt;				 //����
	DWORD  color;			 //��ɫ
	BYTE   mode:1;			 //0=���� 1=��ʾ
	BYTE   reserved:7;		 //����
	char   nouse[16];		 //����δ��
}N4_EGPMB;

typedef struct N4_COORDINATE{ //���� type=13
	DRECT  rt;				 //����
	long   xmin;			 //X������Сֵ
	long   xmax;			 //X�������ֵ
	long   ymin;			 //Y������Сֵ
	long   ymax;			 //Y�������ֵ
	DWORD  colorc;			 //��������ɫ
	DWORD  colorw;			 //ˮ����ɫ
	DWORD  colort;			 //�ı���ɫ
	BYTE   xdot;			 //X�������
	BYTE   ydot;			 //Y�������
	BYTE   wxdraw:1;		 //X����ˮ���Ƿ�
	BYTE   wydraw:1;		 //y����ˮ���Ƿ�
	BYTE   xvshow:1;		 //x����ֵ��ʾ
	BYTE   yvshow:1;		 //y����ֵ��ʾ
	BYTE   reserved:4;		 //����δ��
	LOGFONT fontx;			 //X�ַ���ʾ����
	LOGFONT fonty;			 //Y�ַ���ʾ����
	char    nouse[64];		 //����δ��
}N4_COORDINATE;

typedef struct N4_TABLE{	 //����� type=14
	DRECT  rt;				 //����
	DWORD  color;			 //����ɫ
	double width;			 //�߿��
	BYTE   dbline;			 //���߼Ӵ�
	WORD   line;			 //����
	char   nouse[64];		 //����δ��
}N4_TABLE;


typedef struct N4_IMG{		 //��̬ͼ��type=15
	DRECT rt;				 //����
	BYTE  shadow:1;			 //��Ӱ
	BYTE  zoom:1;			 //֧�����ų�0=No 1=Yes
	BYTE  reserved:6;		 //����
	BYTE  depth;		     //͸����
	WORD  imgID;			 //ID
	char  nouse[16];		 //����δ��
}N4_IMG;

typedef struct N4_PATH{		 //·�� type=16  r10
	WORD  ID;				 //·��ID
	char  nouse[32];		 //����δ��
	WORD  ptsum;			 //������
	DPOINT pt[1];			 //������еĵ�
}N4_PATH;


typedef struct N4_SPIC{	     //��̬Сͼ��type=17
	DRECT rt;				 //����
	WORD  picID;			 //ID
	BYTE  zoom:1;			 //֧�ַ��� 0=no 1=yes
	BYTE  reserved:7;		 //����
	char  nouse[16];		 //����δ��
}N4_SPIC;


///////////////////���⶯̬��//////////////////////////////////////////////

//��̬�Ǳ�1
typedef struct N4_METER1     //�Ǳ����   type=32
{
	DPOINT  pt[2];			//2�������� ��1����ָ�붥�� �ڶ�����԰��
	LOGFONT font;			//��������
	float   Vmin;			//��Сֵ
	float	Vmax;			//���ֵ
	BYTE    showarc;		//�Ƿ���ʾ����
	BYTE    shownum;		//�Ƿ���ʾ����
	BYTE    numdot;			//С����
	BYTE    rev;			//����
	BYTE    scale;			//�̶���
	BYTE    scales;			//ÿ���С�̶���
	BYTE    slen;			//�̶ȳ���
	BYTE    angle;			//�Ǳ����,ָ���ܵ�ƫת�Ƕ�/2
	BYTE    pstyle;			//ָ��ʽ��
	DWORD   pcr;			//ָ����ɫ
	BYTE    axw;			//��Ŀ��
	BYTE    pw;				//��ͷ���
	DWORD   scr;			//�̶���ɫ
	BYTE	alarm;			//�Ƿ�֧�ָ澯�̶� 0=û�� 1,2=��
	float	val[4];			//2��ֵ(����յ�)
	DWORD	cr[2];			//���֧��2����ɫ
	BYTE    stype;			//�̶�����
	BYTE    lstype;			//С�̶�����
	char    reserved[32];	//����32�ֽ�
}N4_METER1;
//��̬�Ǳ�2
typedef struct N4_METER2     //ˮƽ�̶� type=33
{
	DRECT	rt;
	float   Vmin;			//��Сֵ
	float	Vmax;			//���ֵ
	BYTE    rev;			//����
	BYTE    scale;			//�̶���
	BYTE    scales;			//ÿ���С�̶���
	BYTE    showbl;			//�Ƿ���ʾ����
	BYTE    shownum;		//�Ƿ���ʾ����0û�� 1=��ʾ
	BYTE    numdot;			//С����
	DWORD	scr;			//�̶���ɫ
	DWORD	pcr;			//ָ����ɫ
	BYTE	alarm;			//�Ƿ�֧�ָ澯�̶� 0=û�� 1,2=��
	float	val[4];			//2��ֵ(����յ�)
	DWORD	cr[2];			//���֧��2����ɫ
	char    reserved[32];	//����32�ֽ�
}N4_METER2;

//��̬�Ǳ�3
typedef struct N4_METER3     //��ֱ�̶� type=34
{
	DRECT	rt;
	float   Vmin;			//��Сֵ
	float	Vmax;			//���ֵ
	BYTE    rev;			//����
	BYTE    scale;			//�̶���
	BYTE    scales;			//ÿ���С�̶���
	BYTE    showbl;			//�Ƿ���ʾ����
	BYTE    shownum;		//�Ƿ���ʾ����0û�� 1=������� 2=�ұ�����
	BYTE    numdot;			//С����
	DWORD	scr;			//�̶���ɫ
	DWORD	pcr;			//ָ����ɫ
	BYTE	alarm;			//�Ƿ�֧�ָ澯�̶� 0=û�� 1,2=��
	float	val[4];			//2��ֵ(����յ�)
	DWORD	cr[2];			//���֧��2����ɫ
	char    reserved[32];	//����32�ֽ�
}N4_METER3;

//��̬�Ǳ�4
typedef struct N4_METER4       //�����Ǳ����(����) type=35
{
	DRECT	rt;
	BYTE    num;			 //��λ��
	BYTE    numdot;			 //С��λ��
	DWORD   bcr;			 //�߿���ɫ
	DWORD   ncr[2];			 //������С�����ֵ���ɫ
	char    reserved[32];	//����32�ֽ�
}N4_METER4;

typedef struct N4_ANL{       //ģ������ʾ�ṹ type=64 r11
	DRECT    rt;			 //����
	LOGFONT  lf;		     //����
	COLORREF acolor;	     //�澯��ɫ
	COLORREF ncolor;	     //������ɫ
	BYTE     xs:4;			 //С��λ
	BYTE     style:4;		 //��ʾ���
	WORD     angle;			 //��ʾ�Ƕ�=��*10
	char     dev_name[64];	 //�豸��
	char     tablename[24];	 //�ڴ���еı���
	char     fieldname[24];	 //���е�����
	long	 did;			 //�豸ID
	BYTE     dbmode;		 //����ģʽ0=��ģʽ 1=��ģʽ
	BYTE     dtype:4;		 //�豸���� 0=����� 1=������· 2=ֱ����· 3=ĸ�� 4=����  5=2�����ѹ�� 
							 //	6=3�����ѹ�� 7=������ 8=�翹�� 9=SVC
	BYTE     yh;			 //libin��ʱ��Ϊ����λ�ã�0��ѹ���׶ˣ�1��ѹ��ĩ�ˣ�2��ѹ//�Ż� 0=�Ż�ǰ 1=�Ż���
	BYTE     xsmode:4;		 //������,��ͬ�����в�ͬ�ĺ���
	char     nouse[16];		 //����δ��
}N4_ANL;


/*
	xsmode���壺
	�ڵ㣺  0=����ѹ�ȼ��ͱ���ֵ��ʾ 1=��ʾ��ѹ����ֵ�����
	��·��  0=ʼ��   1=ĩ��
	��ѹ����0=������ 1=������
 */
typedef struct N4_RESERVOIR{ //ˮ�����   type=65
	DWORD color;			 //����ɫ
	DWORD ncolor;			 //����ʱ��ɫ
	DWORD hcolor;			 //��ˮλ��ɫ
	DWORD lcolor;			 //��ˮλ��ɫ
	char  dev_name[64];		 //ˮ����
	char  rev[32];			 //����32�ֽ�
	long  did;				 //ˮ��ID
	WORD  ptsum;			 //������
	DPOINT pt[1];			 //������еĵ�
}N4_RESERVOIR;

typedef struct N4_ELEGRPA{   //���ͼԪ��ʾ�ṹtype=66  r13
	DRECT    rt;			 //����
	BYTE     type:2;		 //������������ 0=״̬�� 1=�豸 2=վ 3=��˾
	BYTE     subtype:6;		 //������ ��type=1 ʱΪ�豸����
	WORD     egrpid;		 //���ͼԪID��
	BYTE     showno:1;		 //��ͼʱ����ʾ��0��1
	byte     sitesum:2;		 //������
	BYTE     genrev:1;		 //�Ƿ���ʾ���������(�����ʱ��Ч)
	BYTE     runshow:1;		 //����ʱ�Ƿ���ʾ
	BYTE     reserved:3;	 //����
	D_SITE   site[3];		 //��������
	char     dev_name[64];	 //�豸��
	char     cimname[64];	 //CIM������
	char     cimid[64];		 //CIM�е�ID
	long     did;			 //�豸��¼��
	char     nouse[32];		 //����δ��
}N4_ELEGRPA;


//���嵥������Դ��ֻ��ѡ������һ������)
typedef struct _SINGLEDBS4{  //��������Դ
	char  name[64];			 //�豸����
	int   did;				 //�豸ID
	BYTE  dtype;			 //�豸����
	BYTE  xsmode;			 //ֵ����
	char  nouse[32];		 //δ��
}SINGLEDBS4,DBSRC4;

typedef struct MTRRANGE4{	 //�Ǳ����в�������ֵ
	BYTE     ptype;			 //�������� 0=ʹ���Զ��� 1=ʹ�����ݿ�
	float    vmin;			 //��Сֵ
	float    vmax;			 //���ֵ
	BYTE	 alarm;			 //�Ƿ�֧�ָ澯�̶� 0=û�� 1,2=��
	float	 val[4];		 //2��ֵ(����յ�)
	DWORD    color[2];		 //2����ɫ
}MTRRANGE4;

typedef struct N4_ELEGRPYB{  //���ͼԪ�Ǳ�ṹ type=67 
	DRECT	 rt;			 //����
	WORD     egrpid;		 //���ͼԪID��
	BYTE     dbsum;			 //����Դ����
	DBSRC4   dbs[8];		 //16������Դ����Ӧ16��˳���Ǳ������
	MTRRANGE4 pam[8];		 //�û��Զ�������
}N4_ELEGRPYB;


typedef struct N4_BAR{		 //��ͼ type=69
	DRECT rt;				 //����
	float max;				 //���ֵ
	float min;				 //��Сֵ
	BYTE  xy:1;              //0=x���� 1=Y����
    BYTE  outline:1;		 //���
    BYTE  style:3;			 //ʽ��
	BYTE  reserved:4;		 //����
    DWORD ncolor;			 //������ɫ
    DWORD acolor;			 //�澯��ɫ
    float aval;				 //�澯ֵ
    SINGLEDBS4 dsrc;		 //����Դ
	char  nouse[32];		 //����δ��
}N4_BAR;


typedef struct N4_PIE{        //��ͼ�ṹ���� type=70
	DRECT   rt;				 //����
	BYTE    style:2;		 //0=һ�� 1=���� 2=���� 3=��������
	BYTE    outline:1;		 //��Χ�� 0=�� 1=��
	BYTE    shad:1;			 //����ɫ 0=�� 1=��
	BYTE    sum:4;			 //����
	DWORD   fcolor;			 //�ַ�ɫ
	WORD    angle;			 //��ʼ�Ƕ�0-360��
	DWORD   color[8];		 //8����ɫ
	NPIEDAT pd[8];			 //8������
	char    name[64];		 //��������
	int     did;			 //����ID
	char    nouse[32];		 //����δ��
}N4_PIEPAM;

typedef struct N4_DATE{       //���ڸ�ʽ     type=71 r14
	DRECT   rt;				 //����
	double  zm;
	BYTE    fmt:4;			 //���ڸ�ʽ 0=yyyy-mm-dd 1=mm/dd/yyyy 2=yyyy��mm��dd��
	BYTE    outline:2;		 //�߿� 0=�� 1=�� 2=͹
	BYTE    tran:1;			 //����͸����0=No 1=Yes
	BYTE    shadow:1;		 //������Ӱ��ʾ
	DWORD   outcolor;		 //����ɫ
	DWORD   fcolor;			 //�ַ���ɫ
	DWORD   bcolor;			 //����ɫ
	LOGFONT font;			 //����
}N4_DATE;

typedef N4_DATE N4_TIME;     //ʱ���ʽ     type=72 r15



typedef struct N4_GIFAML{    //����ͼ��  type=73
	DRECT rt;				 //����
	char  fname[256];		 //�ļ���
	WORD  rec;				 //GIFͼ���ڲ���¼,��ʾ��
	//BYTE  type;				 //�������ͣ�״̬��,�豸,վ
	SINGLEDBS4 dsrc;		 //����Դ
	char  nouse[32];		 //����δ��
}N4_GIFAML;

typedef struct N4_SRLTEXT{	 //�����ı�  type=74
	DRECT   rt;				 //����
	double  zm;				 
	BYTE direct:3;			 //����   0=��̬�ı� 1=���� 2=���� 
							 //3=���� 4=����
	BYTE glass:1;			 //�Ƿ��ò����� 0=No 1=Yes
	BYTE outline:1;			 //�Ƿ������
	BYTE align:2;		     //���з�ʽ 0=���� 1=���� 2=����
	BYTE reserved:1;
	BYTE depth;				 //���
	DWORD fcolor;			 //�߿�
	DWORD gcolor;			 //������ɫ
	DWORD tcolor;			 //�ı���ɫ
	LOGFONT lf;				 //��������
	char text[1];			 //���ִ�
}N4_SRLTEXT;

typedef struct N4_PUSH{		 //��ť��ʽ   type=75
	DRECT   rt;				 //����
	double  zm;
	BYTE   style:4;			 //��ťʽ��0=��ͨ��ť 1=���ɼ���ť
							 //2=����͹�ΰ�ť 3=�������ΰ�ť 
							 //4=������ɫ 5=ͼ�갴ť
	BYTE  cmdtype:4;		 //��������
	char  title[64];		 //��ť����
	WORD  spicid;			 //Сͼ��ID��
	WORD  cmdnum;		     //�Զ���ʱ��WM_COMMAND��ϢwParam
	char  command[64];		 //�����ַ���
	DWORD color1;			 //��ɫ1
	DWORD color2;			 //��ɫ2
	int   selfid;			 //Ҫ���Ƶ������ؼ���ID
	LOGFONT lf;				 //����
	BYTE  tosta;			 //Ŀ��״̬,�򿪻���ʱ��
	BYTE  autlin:1;			 //λͼ��ťʱ,�Զ�����
	BYTE  shadow:1;			 //��Ӱ
	BYTE  reserved:6;		 //����
	char  nouse[64];		    //����δ��
}N4_PUSH;

typedef struct N4_SELFCTL{  //�����ؼ�  type=76
	DRECT rt;			    //����
	char  dllname[256];		//��̬���ӿ���
    DWORD style;			//����,�ɿؼ�����
    int	  id;				//ID��,�Ա��໥����
    char  lkbuf[255];		//����ʱ�����ӻ�����
    BYTE  aleft:1;			//�����
    BYTE  aright:1;			//�Ҷ���
    BYTE  atop:1;			//�϶���
    BYTE  abottom:1;		//�¶���
	BYTE  mode:1;			//����:0=�༭λ�� 1=������δ��
	BYTE  reserved:3;		//����
	char  nouse[32];		 //����δ��
}N4_SELFCTL;


typedef struct N4_FLOW{		//������    type=77 r16
	BYTE  style:3;			//ʽ�� 0=һ������ 1=ֻ���й� 2=ֻ���޹� 3=ͬʱ��ʾ
	BYTE  direct:1;			//����0=���������뻭�߷���һ�� 1=�뻭�߷����෴
	BYTE  type:2;			//���� 0=���� 1=ֱ��
	BYTE  reserved:2;		//����
	BYTE  vl;				//��ѹ�ȼ�	 
	D_SITEB site[2];		//����
	DWORD color1;			//�й���ɫ
	DWORD color2;			//�޹���ɫ
	char  dev_name[64];		//�豸��
	char  cimname[64];		//CIM������
	char  cimid[64];		//CIM�е�ID
	long  did;				//�豸��¼��(ID)
	BYTE  linewidth;		//�߿�
	char  nouse[32];		//����δ��
	WORD  ptsum;			//������
	DPOINT pt[1];			//������еĵ�
}N4_FLOW;



typedef struct N4_CONLINE{	//������  type=78 r17
	BYTE	solder1:1;		//���ӵ�1��ʾ0=����ʾ 1=��ʾ
	BYTE	solder2:1;		//���ӵ�2��ʾ0=����ʾ 1=��ʾ
	BYTE    conobj:1;		//���ӵ��豸��־ =0 δ���� =1 ������
	BYTE    reserved:5;		//����
	BYTE	vl;				//��ѹ�ȼ�
	LOGOBJ  lobj[2];		//�����������ӵĶ���
	WORD	ptsum;			//������
	DPOINT	pt[1];			//������еĵ�
}N4_CONLINE;

typedef struct N4_BUS{		//ĸ��  type=79 r18
	DRECT   rt;				 //����
	BYTE    type:2;			//����
	BYTE    valarm:2;		//��ѹ�澯״̬ 0=���� 1=Խ���� 2=Խ����
	BYTE    reserved:4;		//����
	BYTE	vl;				//��ѹ�ȼ�
	WORD    eid;			//���ͼԪID
	char    dev_name[64];	//�豸��
	char    cimname[64];	//CIM������
	char    cimid[64];		//CIM�е�ID
	long    did;			//�豸ID��
	char    nouse[32];		//����δ��
}N4_BUS;

typedef struct N4_ACTOBJ{	//С�ͻ����  type=80
	DRECT   rt;				 //����
	short   gid;			//ͼ��ID
	WORD	pathid;			//����path ID
	BYTE	runmode:1;		//����ģʽ 0=�Զ� 1=ͬ��
	BYTE	speed:3;		//�Զ��������� 0,1,2,3
	BYTE    reserved:4;		//����
	float	skip;			//�Զ�����
	SINGLEDBS4 dsrc;		//����Դ
	char     nouse[32];		//����δ��
}N4_ACTOBJ;

typedef struct N4_FLASH{	//FLASH����  type=81
	DRECT rt;				 //����
	char  fname[256];		//swf�ļ���
	BYTE  playmode:1;		//����ģʽ0=һ�� 1=ѭ��
	BYTE  align_left:1;		//�����
	BYTE  align_top:1;		//�϶���
	BYTE  align_right:1;	//�Ҷ���
	BYTE  align_buttom:1;	//�¶���
	BYTE  reserved:4;		//����
	char  nouse[32];		//����δ��
}N4_FLASH;


typedef struct N4_PCTPIE{	//�ٷֱȱ�ͼ type=82
	DRECT   rt;				//����
	double  zm;
	char    dev_name[64];   //�豸��
	int     did;			//�豸ID
	BYTE    type;			//�������� 0=������ 1=�����
	DWORD   color1,color2;  //������ɫ
	DWORD   fcolor;			//������ɫ
	LOGFONT lf;				//��������
	float   maxv;			//���ֵ
	char    nouse[32];		 //����δ��
}N4_PCTPIE;


//�����Ǳ���ؽṹ
typedef struct N4_ISTMT{	//�Ǳ�ṹ type=83
	DRECT   rt;				//ռ�õľ���
	char    type;			//������
	char    dev_name[64];   //�豸��
	int     did;			//�豸ID
	char    nouse[64];		//δ��
}N4_ISTMT;

//����
typedef struct N4_ZONE{		//����    type=83
	DWORD lcolor;			//������ɫ
	char  zone_name[64];	//������
	long  did;				//����(ID)
	LOGFONT lf;				//����
	DWORD fcolor;			//������ɫ
	char  nouse[32];		//δ��
	WORD  ptsum;			//������
	DPOINT pt[1];			//������еĵ�
}N4_ZONE;


typedef struct N4_MTTEXT{	//����    type=84
	DRECT rt;				//ռ�õľ���
	DWORD fcolor;			//��ɫ
	char  name[64];			//����
	int   did;				//(ID)
	BYTE  type;				//����
	LOGFONT lf;				//����
	char  text[256];		//�ı�����
	char  rev[64];
}N4_MTTEXT;


//�����ʽV3.0
////////////////////////////////////////////////
typedef struct N3_BASATTR{    //�����������  
	BYTE  type;				 //��������
	BYTE  belong:3;			 //�������� ֻ�����ͼԪ����Ч
	BYTE  reserved:5;		 //����
	WORD  ID;				 //����ID
	WORD  size;              //�����ֽ���
}N3_BASATTR;

typedef struct N3_DBX{		 //����� type=1  r1
	BYTE  fill:1;		     //0=����� 1=���
	BYTE  close:1;			 //���
	BYTE  fillmode:2;		 //���ģʽ
	BYTE  ltype:3;			 //������
	BYTE  bgmode:1;			 //����ģʽ 0=ǰ�� 1=����
//	double width;			 //�߿��
	DWORD lcolor;			 //����ɫ
	DWORD bcolor1;			 //�����ɫ1
	WORD  ptsum;			 //������
	BYTE  vl;				//��ѹ�ȼ�	 ����ѹ�ȼ���Чʱ�����õ�ѹ��ɫ����Чʱ�������ɫ
	DPOINT pt[1];			 //������еĵ�
}N3_DBX;

typedef  struct N3_RECT{	 //���� type=2 r2
	DRECT  rt;				 //����
	BYTE   fill:1;			 //0=����� 1=��� 
	BYTE   fillmode:3;		 //��䷽ʽ 
	BYTE   type:2;			 //0=һ�����  1=�� 2=͹ 
	BYTE   reserved:2;		 //����
	DWORD  lcolor;			 //����ɫ
	DWORD  bcolor1;			 //�����ɫ1
}N3_RECT;

typedef N3_RECT N3_CIRCLE;	 //԰ type=3  r3


typedef struct N3_HSIN{		 //���Ұ벨�� type=4  r4
	DRECT  rt;				 //����
	BYTE   hv:1;			 //ˮƽ��ֱ 0=ˮƽ 1=��ֱ
	BYTE   pirodic:7;		 //������
	DWORD  color;			 //����ɫ
}N3_HSIN;



typedef struct N3_SIN{		 //���Ҳ���  type=5 r5
	DRECT rt;				 //����
	BYTE  hv:1;			     //������ 0=ˮƽ 1=��ֱ
	BYTE  pirodic:7;		 //������
	WORD  startdeg;			 //��ʼ�Ƕ�0-359
	DWORD color;			 //����ɫ
}N3_SIN;


typedef struct N3_ARC{		 //԰�� type=6  r6
	DRECT  rt;				 //����
	DWORD  color;			 //��ɫ
	WORD   start;			 //��ʼ�Ƕ�
	WORD   end;				 //�����Ƕ�	
}N3_ARC;

typedef struct N3_ARROW{     //�����ͷ  type=7  r7
	DPOINT  pt[2];			 //��������
	DWORD   color;			 //����ɫ	
}N3_ARROW;

typedef struct N3_GLASS{     //������    type=8
	DRECT  rt;				 //����
	BYTE   depth;			 //���
	BYTE   outline:1;		 //�Ƿ񻭱���
	BYTE   reserved:7;		 //����
	DWORD  color;			 //��ɫ
	DWORD  lcolor;			 //����ɫ
}N3_GLASS;


typedef struct N3_TEXT{      //�ı�  type=10    r9
	DRECT   rt;				 //����
	double  zm;				 //��ͼʱ�ı���
	LOGFONT font;			 //����
    DWORD   color;			 //��ɫ
	BYTE    autofit:1;		 //����Ӧ
    BYTE    style:2;		 //ʽ��
	BYTE    reserved:5;
	WORD    angle;			 //�Ƕ�
  	BYTE  vl;				//��ѹ�ȼ�	 ����ѹ�ȼ���Чʱ�����õ�ѹ��ɫ����Чʱ�������ɫ
	char    text[1];		 //�ı�����,������е��ַ�
}N3_TEXT;

typedef struct N3_ESITE{	 //��������type=11
	DRECT  rt;				 //����
	DWORD  color;			 //������ʾ��ɫ
	BYTE   solder:1;		 //���� 0=���� 1=û��
	BYTE   reserved:7;		 //����
}N3_ESITE;

typedef struct N3_EGPMB{	 //���ͼԪĸ�� type=12 
	DRECT  rt;				 //����
	DWORD  color;			 //��ɫ
	BYTE   mode:1;			 //0=���� 1=��ʾ
	BYTE   reserved:7;		 //����
}N3_EGPMB;

typedef struct N3_COORDINATE{ //���� type=13
	DRECT  rt;				 //����
	long   xmin;			 //X������Сֵ
	long   xmax;			 //X�������ֵ
	long   ymin;			 //Y������Сֵ
	long   ymax;			 //Y�������ֵ
	DWORD  colorc;			 //��������ɫ
	DWORD  colorw;			 //ˮ����ɫ
	DWORD  colort;			 //�ı���ɫ
	BYTE   xdot;			 //X�������
	BYTE   ydot;			 //Y�������
	BYTE   wxdraw:1;		 //X����ˮ���Ƿ�
	BYTE   wydraw:1;		 //y����ˮ���Ƿ�
	BYTE   xvshow:1;		 //x����ֵ��ʾ
	BYTE   yvshow:1;		 //y����ֵ��ʾ
	BYTE   reserved:4;		 //����δ��
	LOGFONT fontx;			 //X�ַ���ʾ����
	LOGFONT fonty;			 //Y�ַ���ʾ����
	double zm;				 //��ͼʱ�ı���
}N3_COORDINATE;

typedef struct N3_TABLE{	 //����� type=14
	DRECT  rt;				 //����
	DWORD  color;			 //����ɫ
	double width;			 //�߿��
	BYTE   dbline;			 //���߼Ӵ�
	WORD   line;			 //����
}N3_TABLE;


typedef struct N3_IMG{		 //��̬ͼ��type=15
	DRECT rt;				 //����
	BYTE  shadow:1;			 //��Ӱ
	BYTE  zoom:1;			 //֧�����ų�0=No 1=Yes
	BYTE  reserved:6;		 //����
	BYTE  depth;		     //͸����
	WORD  imgID;			 //ID
	char filepath[50];
}N3_IMG;

typedef struct N3_PATH{		 //·�� type=16  r10
	WORD  ID;				 //·��ID
	WORD  ptsum;			 //������
	DPOINT pt[1];			 //������еĵ�
}N3_PATH;

typedef struct N3_SPIC{	     //��̬Сͼ��type=17
	DRECT rt;				 //����
	WORD  picID;			 //ID
	BYTE  zoom:1;			 //֧�ַ��� 0=no 1=yes
	BYTE  reserved:7;		 //����
}N_3SPIC;

///////////////////���⶯̬��//////////////////////////////////////////////

//��̬�Ǳ�1
typedef struct N3_METER1     //�Ǳ����   type=32
{
	DPOINT  pt[2];			//2�������� ��1����ָ�붥�� �ڶ�����԰��
	LOGFONT font;			//��������
	float   Vmin;			//��Сֵ
	float	Vmax;			//���ֵ
	BYTE    showarc;		//�Ƿ���ʾ����
	BYTE    shownum;		//�Ƿ���ʾ����
	BYTE    numdot;			//С����
	BYTE    rev;			//����
	BYTE    scale;			//�̶���
	BYTE    scales;			//ÿ���С�̶���
	BYTE    slen;			//�̶ȳ���
	BYTE    angle;			//�Ǳ����,ָ���ܵ�ƫת�Ƕ�/2
	BYTE    pstyle;			//ָ��ʽ��
	DWORD   pcr;			//ָ����ɫ
	BYTE    axw;			//��Ŀ��
	BYTE    pw;				//��ͷ���
	DWORD   scr;			//�̶���ɫ
	BYTE	alarm;			//�Ƿ�֧�ָ澯�̶� 0=û�� 1,2=��
	float	val[4];			//2��ֵ(����յ�)
	DWORD	cr[2];			//���֧��2����ɫ
	BYTE    stype;			//�̶�����
	BYTE    lstype;			//С�̶�����
	char    reserved[30];	//����32�ֽ�
}N3_METER1;
//��̬�Ǳ�2
typedef struct N3_METER2     //ˮƽ�̶� type=33
{
	DRECT	rt;
	float   Vmin;			//��Сֵ
	float	Vmax;			//���ֵ
	BYTE    rev;			//����
	BYTE    scale;			//�̶���
	BYTE    scales;			//ÿ���С�̶���
	BYTE    showbl;			//�Ƿ���ʾ����
	BYTE    shownum;		//�Ƿ���ʾ����0û�� 1=��ʾ
	BYTE    numdot;			//С����
	DWORD	scr;			//�̶���ɫ
	DWORD	pcr;			//ָ����ɫ
	BYTE	alarm;			//�Ƿ�֧�ָ澯�̶� 0=û�� 1,2=��
	float	val[4];			//2��ֵ(����յ�)
	DWORD	cr[2];			//���֧��2����ɫ
	char    reserved[32];	//����32�ֽ�
}N3_METER2;

//��̬�Ǳ�3
typedef struct N3_METER3     //��ֱ�̶� type=34
{
	DRECT	rt;
	float   Vmin;			//��Сֵ
	float	Vmax;			//���ֵ
	BYTE    rev;			//����
	BYTE    scale;			//�̶���
	BYTE    scales;			//ÿ���С�̶���
	BYTE    showbl;			//�Ƿ���ʾ����
	BYTE    shownum;		//�Ƿ���ʾ����0û�� 1=������� 2=�ұ�����
	BYTE    numdot;			//С����
	DWORD	scr;			//�̶���ɫ
	DWORD	pcr;			//ָ����ɫ
	BYTE	alarm;			//�Ƿ�֧�ָ澯�̶� 0=û�� 1,2=��
	float	val[4];			//2��ֵ(����յ�)
	DWORD	cr[2];			//���֧��2����ɫ
	char    reserved[32];	//����32�ֽ�
}N3_METER3;

//��̬�Ǳ�4
typedef struct N3_METER4       //�����Ǳ����(����) type=35
{
	DRECT	rt;
	BYTE    num;			 //��λ��
	BYTE    numdot;			 //С��λ��
	DWORD   bcr;			 //�߿���ɫ
	DWORD   ncr[2];			 //������С�����ֵ���ɫ
}N3_METER4;

/////////////
typedef struct N3_ANL{       //ģ������ʾ�ṹ type=64 r11
	DRECT    rt;			 //����
	double   zm;			 //��ͼʱ�ı���
	LOGFONT  lf;		     //����
	COLORREF acolor;	     //�澯��ɫ
	COLORREF ncolor;	     //������ɫ
	BYTE     xs:4;			 //С��λ
	BYTE     style:4;		 //��ʾ���
	WORD     angle;			 //��ʾ�Ƕ�=��*10
	char     dev_name[64];	 //�豸��
	long	 did;			 //�豸ID
	BYTE     dtype;			 //�豸���� 0=����� 1=������· 2=ֱ����· 3=ĸ�� 4=����  5=2�����ѹ�� 
							 //	6=3�����ѹ�� 7=������ 8=�翹�� 9=SVC
	BYTE     yh;			 //libin��ʱ��Ϊ����λ�ã�0��ѹ���׶ˣ�1��ѹ��ĩ�ˣ�2��ѹ//�Ż� 0=�Ż�ǰ 1=�Ż���
	BYTE     xsmode:4;		 //������,��ͬ�����в�ͬ�ĺ���
	char     nouse[8];		 //����δ��
}N3_ANL;
/*
	xsmode���壺
	�ڵ㣺  0=����ѹ�ȼ��ͱ���ֵ��ʾ 1=��ʾ��ѹ����ֵ�����
	��·��  0=ʼ��   1=ĩ��
	��ѹ����0=������ 1=������
 */
typedef struct N3_RESERVOIR{  //ˮ�����   type=65
	DWORD color;			 //����ɫ
	DWORD ncolor;			 //����ʱ��ɫ
	DWORD hcolor;			 //��ˮλ��ɫ
	DWORD lcolor;			 //��ˮλ��ɫ
	char rev[32];			 //����32�ֽ�
	char  dev_name[24];		 //ˮ����
	long  did;				 //ˮ��ID
	WORD  ptsum;			 //������
	DPOINT pt[1];			 //������еĵ�
}N3_RESERVOIR;

typedef struct N3_ELEGRPA{   //���ͼԪ��ʾ�ṹtype=66  r13
	DRECT    rt;			 //����
	BYTE     type:2;		 //������������ 0=״̬�� 1=�豸 2=վ 3=��˾
	BYTE     subtype:6;		 //������ ��type=1 ʱΪ�豸����
	WORD     egrpid;		 //���ͼԪID��
	BYTE     showno:1;		 //��ͼʱ����ʾ��0��1
	byte     sitesum:2;		 //������
	BYTE     genrev:1;		 //�Ƿ���ʾ���������(�����ʱ��Ч)
	BYTE     runshow:1;		 //����ʱ�Ƿ���ʾ
	BYTE     reserved:3;	 //����
	D_SITE   site[3];		 //��������
	char     dev_name[64];	 //�豸��
	long     did;			 //�豸��¼��
	short startang;				//��ʼ�Ƕ�(��չ����ʱ��Ч)
	short endang;			//��ֹ�Ƕ�(��չ����ʱ��Ч)
	double center[3];		//�ֱ������ĵ����꣬�Ͱ뾶(��չ����ʱ��Ч)	
	char     nouse[8];		 //����δ��
}N3_ELEGRPA;

typedef struct N3_ELEGRPYB{  //���ͼԪ�Ǳ�ṹ type=67 
	DRECT	 rt;			 //����
	WORD     egrpid;		 //���ͼԪID��
	BYTE     dbsum;			 //����Դ����
	DBSRC    dbs[8];		 //16������Դ����Ӧ16��˳���Ǳ������
	MTRRANGE pam[8];		 //�û��Զ�������
}N3_ELEGRPYB;


typedef struct N3_BAR{		 //��ͼ type=69
	DRECT rt;				 //����
	float max;				 //���ֵ
	float min;				 //��Сֵ
	BYTE  xy:1;              //0=x���� 1=Y����
    BYTE  outline:1;		 //���
    BYTE  style:3;			 //ʽ��
	BYTE  reserved:4;		 //����
    DWORD ncolor;			 //������ɫ
    DWORD acolor;			 //�澯��ɫ
    float aval;				 //�澯ֵ
    SINGLEDBS dsrc;			 //����Դ
	char     nouse[8];		 //����δ��
}N3_BAR;


typedef struct N3_PIE{        //��ͼ�ṹ���� type=70
	DRECT   rt;				 //����
	BYTE    style:2;		 //0=һ�� 1=���� 2=���� 3=��������
	BYTE    outline:1;		 //��Χ�� 0=�� 1=��
	BYTE    shad:1;			 //����ɫ 0=�� 1=��
	BYTE    sum:4;			 //����
	DWORD   fcolor;			 //�ַ�ɫ
	WORD    angle;			 //��ʼ�Ƕ�0-360��
	DWORD   color[8];		 //8����ɫ
	NPIEDAT pd[8];			 //8������
	char    name[24];		 //��������
	int     did;			 //����ID
	char    nouse[8];		 //����δ��
}N3_PIEPAM;

typedef struct N3_DATE{       //���ڸ�ʽ     type=71 r14
	DRECT   rt;				 //����
	double  zm;
	BYTE    fmt:4;			 //���ڸ�ʽ 0=yyyy-mm-dd 1=mm/dd/yyyy 2=yyyy��mm��dd��
	BYTE    outline:2;		 //�߿� 0=�� 1=�� 2=͹
	BYTE    tran:1;			 //����͸����0=No 1=Yes
	BYTE    shadow:1;		 //������Ӱ��ʾ
	DWORD   outcolor;		 //����ɫ
	DWORD   fcolor;			 //�ַ���ɫ
	DWORD   bcolor;			 //����ɫ
	LOGFONT font;			 //����
}N3_DATE;

typedef N3_DATE N3_TIME;     //ʱ���ʽ     type=72 r15



typedef struct N3_GIFAML{    //����ͼ��  type=73
	DRECT rt;				 //����
	char  fname[64];		 //�ļ���
	WORD  rec;				 //GIFͼ���ڲ���¼,��ʾ��
	BYTE  type;				 //�������ͣ�״̬��,�豸,վ
	SINGLEDBS dsrc;			 //����Դ
}N3_GIFAML;

typedef struct N3_SRLTEXT{	 //�����ı�  type=74
	DRECT   rt;				 //����
	double  zm;				 
	BYTE direct:3;			 //����   0=��̬�ı� 1=���� 2=���� 
							 //3=���� 4=����
	BYTE glass:1;			 //�Ƿ��ò����� 0=No 1=Yes
	BYTE outline:1;			 //�Ƿ������
	BYTE align:2;		     //���з�ʽ 0=���� 1=���� 2=����
	BYTE reserved:1;
	BYTE depth;				 //���
	DWORD fcolor;			 //�߿�
	DWORD gcolor;			 //������ɫ
	DWORD tcolor;			 //�ı���ɫ
	LOGFONT lf;				 //��������
	char text[1];			 //���ִ�
}N3_SRLTEXT;

typedef struct N3_PUSH{		 //��ť��ʽ   type=75
	DRECT   rt;				 //����
	double  zm;
	BYTE   style:4;			 //��ťʽ��0=��ͨ��ť 1=���ɼ���ť
							 //2=����͹�ΰ�ť 3=�������ΰ�ť 
							 //4=������ɫ 5=ͼ�갴ť
	BYTE  cmdtype:4;		 //��������
	char  title[32];		 //��ť����
	WORD  spicid;			 //Сͼ��ID��
	WORD  cmdnum;		     //�Զ���ʱ��WM_COMMAND��ϢwParam
	char  command[45];		 //�����ַ���
	DWORD color1;			 //��ɫ1
	DWORD color2;			 //��ɫ2
	int   selfid;			 //Ҫ���Ƶ������ؼ���ID
	LOGFONT lf;				 //����
	BYTE  tosta;			 //Ŀ��״̬,�򿪻���ʱ��
	BYTE  autlin:1;			 //λͼ��ťʱ,�Զ�����
	BYTE  shadow:1;			 //��Ӱ
	BYTE  reserved:6;		 //����
	char  nouse[6];		     //����δ��
}N3_PUSH;

typedef struct N3_SELFCTL{   //�����ؼ�  type=76
	DRECT rt;				 //����
	char  dllname[64];		//��̬���ӿ���
    DWORD style;			//����,�ɿؼ�����
    int	  id;				//ID��,�Ա��໥����
    char  lkbuf[255];		//����ʱ�����ӻ�����
    BYTE  aleft:1;			//�����
    BYTE  aright:1;			//�Ҷ���
    BYTE  atop:1;			//�϶���
    BYTE  abottom:1;		//�¶���
	BYTE  mode:1;			//����:0=�༭λ�� 1=������δ��
	BYTE  reserved:3;		//����
	char     nouse[8];		 //����δ��
}N3_SELFCTL;


typedef struct N3_FLOW{		//������    type=77 r16
	BYTE  style:3;			//ʽ�� 0=һ������ 1=ֻ���й� 2=ֻ���޹� 3=ͬʱ��ʾ
	BYTE  direct:1;			//����0=���������뻭�߷���һ�� 1=�뻭�߷����෴
	BYTE  type:2;			//���� 0=���� 1=ֱ��
	BYTE  reserved:2;		//����
	BYTE  vl;				//��ѹ�ȼ�	 
	D_SITEB site[2];		//����
	DWORD color1;			//�й���ɫ
	DWORD color2;			//�޹���ɫ
	char  dev_name[24];		//�豸��
	long  did;				//�豸��¼��(ID)
	BYTE  linewidth;		//�߿�
	char    nouse[7];		 //����δ��
	WORD  ptsum;			//������
	DPOINT pt[1];			//������еĵ�
}N3_FLOW;



typedef struct N3_CONLINE{	//������  type=78 r17
	BYTE	solder1:1;		//���ӵ�1��ʾ0=����ʾ 1=��ʾ
	BYTE	solder2:1;		//���ӵ�2��ʾ0=����ʾ 1=��ʾ
	BYTE    conobj:1;		//���ӵ��豸��־ =0 δ���� =1 ������
	BYTE    reserved:5;		//����
	BYTE	vl;				//��ѹ�ȼ�
	LOGOBJ  lobj[2];		//�����������ӵĶ���
	WORD	ptsum;			//������
	DPOINT	pt[1];			//������еĵ�
}N3_CONLINE;

typedef struct N3_BUS{		//ĸ��  type=79 r18
	DRECT   rt;				 //����
	BYTE    type:2;			//����
	BYTE    valarm:2;		//��ѹ�澯״̬ 0=���� 1=Խ���� 2=Խ����
	BYTE    reserved:4;		//����
	BYTE	vl;				//��ѹ�ȼ�
	WORD    eid;			//���ͼԪID
	char    dev_name[24];	//�豸��
	long    did;			//�豸ID��
	char    nouse[8];		 //����δ��
}N3_BUS;

typedef struct N3_ACTOBJ{	//С�ͻ����  type=80
	DRECT   rt;				 //����
	short   gid;			//ͼ��ID
	WORD	pathid;			//����path ID
	BYTE	runmode:1;		//����ģʽ 0=�Զ� 1=ͬ��
	BYTE	speed:3;		//�Զ��������� 0,1,2,3
	BYTE    reserved:4;		//����
	float	skip;			//�Զ�����
	SINGLEDBS dsrc;			//����Դ
	char     nouse[8];		 //����δ��
}N3_ACTOBJ;

typedef struct N3_FLASH{	//FLASH����  type=81
	DRECT rt;				 //����
	char  fname[128];		//swf�ļ���
	BYTE  playmode:1;		//����ģʽ0=һ�� 1=ѭ��
	BYTE  align_left:1;		//�����
	BYTE  align_top:1;		//�϶���
	BYTE  align_right:1;	//�Ҷ���
	BYTE  align_buttom:1;	//�¶���
	BYTE  reserved:4;		//����
}N3_FLASH;


typedef struct N3_PCTPIE{	//�ٷֱȱ�ͼ type=82
	DRECT   rt;				 //����
	double  zm;
	char    dev_name[24];   //�豸��
	int     did;			//�豸ID
	BYTE    type;			//�������� 0=������ 1=�����
	DWORD   color1,color2;  //������ɫ
	DWORD   fcolor;			//������ɫ
	LOGFONT lf;				//��������
	float   maxv;			//���ֵ
	char    nouse[8];		 //����δ��
}N3_PCTPIE;


//�����Ǳ���ؽṹ
typedef struct N3_ISTMT{	//�Ǳ�ṹ type=83
	DRECT   rt;				//ռ�õľ���
	char    type;			//������
	char    dev_name[24];   //�豸��
	int     did;			//�豸ID
}N3_ISTMT;

//����
typedef struct N3_ZONE{		//����    type=83
	DWORD lcolor;			//������ɫ
	char  zone_name[24];	//������
	long  did;				//����(ID)
	LOGFONT lf;				//����
	DWORD fcolor;			//������ɫ
	WORD  ptsum;			//������
	DPOINT pt[1];			//������еĵ�
}N3_ZONE;


typedef struct N3_MTTEXT{	//����    type=84
	DRECT rt;				//ռ�õľ���
	DWORD fcolor;			//��ɫ
	char  name[40];			//����
	int   did;				//(ID)
	BYTE  type;				//����
	LOGFONT lf;				//����
	char  text[256];		//�ı�����
	char  rev[64];
}N3_MTTEXT;

typedef struct N3_SECTOR	 //���� type=200  r6
{
	DRECT rt;				//ռ�õľ���
	DPOINT cpt;				//Բ������
	float r;				//�뾶
	DWORD   color;			 //��ɫ
	double  width;			 //���
	short    start;			 //��ʼ�Ƕ�
	short    end;			 //�����Ƕ�	
	BYTE   fillmode;		 //��䷽ʽ 
	BYTE   close;			//���״̬
	DWORD  bcolor;			 //�����ɫ
	DWORD  ptnum;			//�ܱߵ���
	DPOINT arcpt[362];		//�ܱ߶����	����72�㣬���ĵ�1����//������3����		//���ʱ�ö������ߣ����Ի�������	
	char     dev_name[64];	 //�豸��
	long	 did;			 //�豸ID
	BYTE     dtype;			 //�豸���ͼ�enum _EQUIP_TYPE����. 0=����� 1=������· 2=ֱ����· 3=ĸ�� 4=����  5=2�����ѹ�� 
							 //	6=3�����ѹ�� 7=������ 8=�翹�� 9=SVC
	char    nouse[8];		 //����δ��
}N3_SECTOR;

///////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////
//����Ϊ2.0�ṹ
typedef struct N2_BASATTR{    //�����������  
	BYTE  type;				 //��������
	BYTE  belong;			 //�������� ֻ�����ͼԪ����Ч
	DWORD ID;				 //����ID
	WORD  size;              //�����ֽ���
}N2_BASATTR;

typedef struct N2_DBX{		 //����� type=1  r1
	BYTE  fill;			     //0=����� 1=���
	BYTE  fillmode;			 //��䷽ʽ
	BYTE  close;			 //0=�����   1=��� 
	BYTE  ltype;			 //������
	BYTE  autozoom;			 //�Ƿ��Զ��Ŵ�����
	BYTE  lmode;			 //ģʽ 0=���� 1=�߿�
	BYTE  endcap;			 //��ͷģʽ
	double width;			 //�߿��
	DWORD lcolor;			 //����ɫ
	DWORD bcolor1;			 //�����ɫ1
	DWORD bcolor2;			 //�����ɫ2
	WORD  ptsum;			 //������
	DPOINT pt[1];			 //������еĵ�
}N2_DBX;

typedef  struct N2_RECT{		 //���� type=2 r2
	DPOINT pt[4];			 //4��������
	BYTE   fill;			 //0=����� 1=��� 
	BYTE   fillmode;		 //��䷽ʽ 
	BYTE   autozoom;		 //�Ƿ��Զ��Ŵ�����
	BYTE   type;			 //0=һ�����  1=3D����/(԰)���� 
	double width;			 //�߿��
	DWORD  lcolor;			 //����ɫ
	DWORD  bcolor1;			 //�����ɫ1
	DWORD  bcolor2;			 //�����ɫ2
}N2_RECT;

typedef N2_RECT N2_CIRCLE;	 //԰ type=3  r3

typedef struct N2_HSIN{		 //���Ұ벨�� type=4  r4
	DPOINT pt[4];			 //4��������
	BYTE  ltype;			 //������
	BYTE  lmode;			 //ģʽ 0=���� 1=�߿�
	BYTE  endcap;			 //��ͷģʽ
    BYTE  pirodic;			 //������
	BYTE  autozoom;			 //�Ƿ��Զ��Ŵ�����
	double  width;			 //�߿��
	DWORD color;			 //����ɫ
	DWORD bcolor;			 //���ɫ
}N2_HSIN;



typedef struct N2_SIN{		 //���Ҳ���  type=5 r5
	DPOINT pt[4];			 //4��������
	BYTE  ltype;			 //������ 0=ˮƽ 1=��ֱ
	WORD  startdeg;			 //��ʼ�Ƕ�0-359
	char  reserved[9];		 //����
	BYTE  pirodic;			 //������
	DWORD color;			 //����ɫ
	char resed[4];			 //����
}N2_SIN;


typedef struct N2_ARC{		 //԰�� type=6  r6
	DPOINT  pt[4];			 //4��������
	DWORD   color;			 //��ɫ
	BYTE  autozoom;			 //�Ƿ��Զ��Ŵ�����
	double  width;			 //���
	WORD    start;			 //��ʼ�Ƕ�
	WORD    end;			 //�����Ƕ�	
}N2_ARC;

typedef struct N2_ARROW{      //�����ͷ  type=7  r7
	DPOINT  pt[2];			 //��������
	BYTE    autozoom;		 //�Ƿ��Զ��Ŵ�����
	double  width;			 //�߿��
	DWORD   color;			 //����ɫ	
}N2_ARROW;

typedef struct N2_GLASS{      //������    type=8
	DPOINT  pt[4];			 //4��������
	BYTE    depth;			 //���
	DWORD   color;			 //����ɫ
	BYTE    outline;		 //�Ƿ񻭱���
	DWORD   ocolor;			 //����ɫ
}N2_GLASS;

typedef struct N2_CBAR{       //Բ����ͼ  type=9  r8
	DPOINT pt[4];			 //4��������
	BYTE  xy;				 //XY����0=x 1=y
	BYTE  outline;		     //���
	DWORD color;		     //����ɫ
}N2_CBAR;

typedef struct N2_TEXT{       //�ı�  type=10    r9
	DPOINT  pt[4];			 //4��������
	double  zm;				 //��ͼʱ�ı���
	LOGFONT font;			 //����
    DWORD   color;			 //��ɫ
    char    style;			 //ʽ��
    BYTE    autofill;		 //�Զ�����
    char    text[45];		 //�ı�����
}N2_TEXT;

typedef struct N2_ESITE{		 //��������type=11
	DPOINT pt[4];			 //4��������
	DWORD  color;			 //������ʾ��ɫ
	BYTE   solder;			 //���� 0=���� 1=û��
}N2_ESITE;

typedef struct N2_EGPMB{	 //���ͼԪĸ�� type=12 
	DPOINT pt[4];			 //4��������
	BYTE   mode;			 //0=���� 1=��ʾ
	DWORD  color;			 //��ɫ
}N2_EGPMB;

typedef struct N2_COORDINATE{ //���� type=13
	DPOINT pt[4];			 //4��������
	long  xmin;				 //X������Сֵ
	long  xmax;				 //X�������ֵ
	long  ymin;				 //Y������Сֵ
	long  ymax;				 //Y�������ֵ
	DWORD  colorc;			 //��������ɫ
	DWORD  colorw;			 //ˮ����ɫ
	DWORD  colort;			 //�ı���ɫ
	BYTE   xdot;			 //X�������
	BYTE   ydot;			 //Y�������
	BYTE   wxdraw;			 //X����ˮ���Ƿ�
	BYTE   wydraw;			 //y����ˮ���Ƿ�
	BYTE   xvshow;			 //x����ֵ��ʾ
	BYTE   yvshow;			 //y����ֵ��ʾ
	double width1;			 //�����߿�
	double width2;			 //ˮ���߿�
	LOGFONT fontx;			 //X�ַ���ʾ����
	LOGFONT fonty;			 //Y�ַ���ʾ����
	double zm;				 //��ͼʱ�ı���
	char  reserved[8];		 //����8�ֽ�
}N2_COORDINATE;

typedef struct N2_TABLE{		 //����� type=14
	DPOINT pt[4];			 //4��������
	DWORD  color;			 //����ɫ
	double   width;			 //�߿��
	BYTE   dbline;			 //���߼Ӵ�
	WORD   line;			 //����
	char   reserved[4];		 //����4�ֽ�
}N2_TABLE;


typedef struct N2_IMG{		 //��̬ͼ��type=15
	DPOINT pt[4];			 //4��������
	BYTE  shadow;			 //��Ӱ
	BYTE  depth;		     //͸����
	BYTE  zoom;				 //֧�����ų�0=No 1=Yes
	WORD  imgID;			 //ID
}N2_IMG;

typedef struct N2_PATH{		 //·�� type=16  r10
	WORD  ID;				 //·��ID
	double  start;			 //�������
	double  end;			 //�յ�����
	DWORD color;			 //�༭ʱ��ʾ��ɫ
	WORD  ptsum;			 //������
	DPOINT pt[1];			 //������еĵ�
}N2_PATH;

typedef struct N2_SPIC{	     //��̬Сͼ��type=17
	DPOINT pt[4];			 //4��������
	WORD  picID;			 //ID
	BYTE  zoom;				 //֧�ַ��� 0=no 1=yes
	char  reserved[10];		 //����
}N2_SPIC;

/////////////
typedef struct N2_ANL{        //ģ������ʾ�ṹ type=64 r11
	DPOINT   pt[4];			 //4��������
	double   zm;			 //��ͼʱ�ı���
	LOGFONT  lf;		     //����
	COLORREF acolor;	     //�澯��ɫ
	COLORREF ncolor;	     //������ɫ
	BYTE     xs;			 //С��λ
	BYTE     style;		     //��ʾ���
	BYTE     direction;		 //����0=x���� 1=Y����
	R_ANL    rval[5];		 //ʵʱֵ
	char     dev_name[24];	 //�豸��
	long	 did;			 //�豸ID
	BYTE     dtype;			 //�豸���� 0=����� 1=������· 2=ֱ����· 3=ĸ�� 4=����  5=2�����ѹ�� 
							 //	6=3�����ѹ�� 7=������ 8=�翹�� 9=SVC
	BYTE     yh;			 //�Ż� 0=�Ż�ǰ 1=�Ż���
	BYTE     xsmode;		 //������,��ͬ�����в�ͬ�ĺ���
	char     reserved[23];   //����
}N2_ANL;
/*
	xsmode���壺
	�ڵ㣺  0=����ѹ�ȼ��ͱ���ֵ��ʾ 1=��ʾ��ѹ����ֵ�����
	��·��  0=ʼ��   1=ĩ��
	��ѹ����0=������ 1=������
 */



typedef struct N2_ELEGRPA{    //���ͼԪ��ʾ�ṹtype=66  r13
	DPOINT   pt[4];			 //4��������
	BYTE     type;			 //������������ 0=״̬�� 1=�豸 2=վ 3=��˾
	BYTE     subtype;		 //������ ��type=1 ʱΪ�豸����
	WORD     egrpid;		 //���ͼԪID��
	BYTE     showno;		 //��ͼʱ����ʾ��0��1
	R_STA	 rval[3];		 //��ǰ���ӵ�״̬
	byte     sitesum;		 //������
	D_SITE   site[3];		 //��������
	short    dydeg;			 //��̬�Ƕ�(��Ҫ��̬��ʾ��ͼ��)
	float    p;				 //�й�(���豸�й�)
	float    q;				 //�޹�(���豸�й�)
	float    maxp;			 //����й�
	float    minp;			 //��С�й�
	short    angle;			 //������Ƕ�
	float    sen;			 //������=0ʱ,����ʾ
	BYTE     genrev;		 //�Ƿ���ʾ���������(�����ʱ��Ч)
	BYTE     runshow;		 //����ʱ�Ƿ���ʾ
	char     reserve[2];	 //����  
	char     dev_name[24];	 //�豸��
	long     did;			 //�豸��¼��
	char     reserved[8];	 //����8�ֽ�
}N2_ELEGRPA;




typedef struct N2_TREND{		 //����  type=68
   DPOINT pt[4];			 //4��������
   int  id;					 //����ID�ڲ���
   BYTE seg;				 //ʱ�����
   BYTE jg;					 //���
   float max;				 //���ֵ
   float min;				 //��Сֵ
   DWORD lcolor;			 //����ɫ
   DWORD bcolor;			 //����ɫ
   DWORD wcolor;			 //ˮ��ɫ
   BYTE  border;			 //�߿�
   BYTE  tran;				 //����͸��
   BYTE  width;				 //�߿��
   R_ANL rval;				 //ʵʱ����
   float qx[25];			 //�ܹ�24������
   char  ds_name[24];		 //ģ������
   long  jlh;				 //��ؼ�¼��
}N2_TREND;

typedef struct N2_BAR{		 //��ͼ type=69
	DPOINT pt[4];			 //4��������
	int   xy;                //0=x���� 1=Y����
	int   id;				 //����ID�ڲ���
	float max;				 //���ֵ
	float min;				 //��Сֵ
    BYTE  outline;			 //���
    BYTE  style;			 //ʽ��
    DWORD ncolor;			 //������ɫ
    DWORD acolor;			 //�澯��ɫ
    float aval;				 //�澯ֵ
    R_ANL rval;				 //��ǰֵ
    SINGLEDBS dsrc;			 //����Դ
}N2_BAR;


typedef struct N2_PIE{        //��ͼ�ṹ���� type=70
	DPOINT  pt[4];			 //4��������
	WORD    ID;				 //ID��
	BYTE    style;			 //0=һ�� 1=���� 2=���� 3=��������
	BYTE    outline;		 //��Χ�� 0=�� 1=��
	BYTE    shad;			 //����ɫ 0=�� 1=��
	BYTE    sum;			 //����
	DWORD   fcolor;			 //�ַ�ɫ
	WORD    angle;			 //��ʼ�Ƕ�0-360��
	DWORD   color[8];		 //8����ɫ
	NPIEDAT pd[8];			 //8������
	char    name[24];		 //��������
	int     did;			 //����ID
	BYTE    type;			 //δ��
	BYTE    yh;				 //�Ż�0=�Ż�ǰ 1=�Ż���
	char    reserved[32];	 //�����ֽ�
}N2_PIEPAM;

typedef struct N2_DATE{       //���ڸ�ʽ     type=71 r14
	DPOINT  pt[4];			 //4��������
	double  zm;
	BYTE    fmt;			 //���ڸ�ʽ 0=yyyy-mm-dd 1=mm/dd/yyyy 2=yyyy��mm��dd��
	BYTE    outline;		 //�߿� 0=�� 1=���� 1=�� 2=͹
	BYTE    tran;			 //����͸����0=No 1=Yes
	DWORD   outcolor;		 //����ɫ
	DWORD   fcolor;			 //�ַ���ɫ
	DWORD   bcolor;			 //����ɫ
	LOGFONT font;			 //����
	BYTE    style;			 //������ʾ 0=���� 1=�� 2=͹
	BYTE    shadow;			 //������Ӱ��ʾ
	CTime   tm;				 //ʱ��
}N2_DATE;

typedef struct N2_TIME{		 //ʱ���ʽ     type=72 r15
	DPOINT  pt[4];			 //4��������
	double  zm;
	BYTE    fmt;			 //ʱ���ʽ 0=hh:mm:ss 1=hh:mm 2=hhʱmm��ss��
							 //3=hh��mm��ss�� 4=mm��ss��	
	BYTE    outline;		 //�߿� 0=�� 1=���� 1=�� 2=͹
	BYTE    tran;			 //����͸����0=No 1=Yes
	DWORD   outcolor;		 //����ɫ
	DWORD   fcolor;			 //�ַ���ɫ
	DWORD   bcolor;			 //����ɫ
	LOGFONT font;			 //����
	BYTE    style;			 //������ʾ 0=���� 1=�� 2=͹
	BYTE    shadow;			 //������Ӱ��ʾ
	CTime   tm;				 //ʱ��
}N2_TIME;

typedef struct N2_GIFAML{     //��̬ͼ��  type=73
	DPOINT  pt[4];			 //4��������
	char  fname[64];		 //�ļ���
	WORD  rec;				 //GIFͼ���ڲ���¼,��ʾ��
	BYTE  type;				 //�������ͣ�״̬��,�豸,վ
	R_STA rval;				 //��ǰ״̬
	SINGLEDBS dsrc;			 //����Դ
}N2_GIFAML;

typedef struct N2_SRLTEXT{	 //�����ı�  type=74
	DPOINT  pt[4];			 //4��������
	double  zm;
	BYTE direct;			 //����   0=��̬�ı� 1=���� 2=���� 
							 //3=���� 4=����
	BYTE tstyle;			 //�ı���ʽ 0=���� 1=�� 2=͹
	BYTE glass;				 //�Ƿ��ò����� 0=No 1=Yes
	BYTE outline;			 //�Ƿ������
	BYTE depth;				 //���
	DWORD fcolor;			 //�߿�
	DWORD gcolor;			 //������ɫ
	DWORD tcolor;			 //�ı���ɫ
	LOGFONT lf;				 //��������
	BYTE  align;		     //���з�ʽ 0=���� 1=���� 2=����
	BYTE  shadow;			 //�Ƿ���Ӱ
	WORD  id;				 //ID��
	char text[256];			 //���ִ�
}N2_SRLTEXT;

typedef struct N2_PUSH{		 //��ť��ʽ   type=75
	DPOINT  pt[4];			 //4��������
	double  zm;
	BYTE  style;			 //��ťʽ��0=��ͨ��ť 1=���ɼ���ť
							 //2=����͹�ΰ�ť 3=�������ΰ�ť 
							 //4=������ɫ 5=ͼ�갴ť
	char  title[32];		 //��ť����
	WORD  spicid;			 //Сͼ��ID��
	BYTE  autlin;			 //λͼ��ťʱ,�Զ�����
	BYTE  fstyle;			 //�ı���ʾ����
	BYTE  shadow;			 //��Ӱ
	BYTE  cmdtype;			 //��������
	WORD  cmdnum;		     //�Զ���ʱ��WM_COMMAND��ϢwParam
	char  command[45];		 //�����ַ���
	DWORD color1;			 //��ɫ1
	DWORD color2;			 //��ɫ2
	int   selfid;			 //Ҫ���Ƶ������ؼ���ID
	LOGFONT lf;				 //����
	WORD  id;				 //����ID
	BYTE  down;				 //ѹ��״̬
	BYTE  edit;				 //�༭״̬
	char reserved[8];		 //�����ֽ�
}N2_PUSH;

typedef struct N2_SELFCTL{   //�����ؼ�  type=76
	DPOINT  pt[4];			//4��������
	char  dllname[64];		//��̬���ӿ���
    DWORD style;			//����,�ɿؼ�����
    int	  id;				//ID��,�Ա��໥����
    char  lkbuf[255];		//����ʱ�����ӻ�����
    BYTE  aleft;			//�����
    BYTE  aright;			//�Ҷ���
    BYTE  atop;				//�϶���
    BYTE  abottom;			//�¶���
	BYTE  mode;				//����:0=�༭λ�� 1=������δ��
    BYTE  reserved1[3];		//����

    HINSTANCE hinst;        //DLL������
	HMENU hmenu;			 //�ؼ��˵�
    HWND  hwnd;				//���ھ��
    void  *rc;				//��ʼ����������Դ(�����)
    int  (WINAPI*DfGetVer)();//���ذ汾��
    void (WINAPI*DfDrawDemo)(HDC,RECT,DWORD,char *);		//��ʾ��ͼ
    void*(WINAPI*DfInit)(HWND,HWND&,RECT,int,DWORD,char*);	//��ʼ��
    void (WINAPI*DfClose)(void *rc);						//�ر�
    void (WINAPI*DfAbout)();								//���ڸÿؼ�
    void (WINAPI*DfSetParam)(DWORD&,char*);					//���ò���
	void (WINAPI*DfPrint)(HDC,RECT,BYTE);					//�ṩ��ӡ֧��
	HMENU (WINAPI*DfLoadMenu)();							//���ò���
    char reserved[108];										//�����ֽ�,���ŷ�չ
}N2_SELFCTL;


typedef struct N2_FLOW{		//������    type=77 r16
	R_FLOW  rf;				//���в���
	BYTE  style;			//ʽ�� 0=һ������ 1=ֻ���й� 2=ֻ���޹� 3=ͬʱ��ʾ
	R_FLW rval;				//��ǰֵ
	BYTE  vl;				//��ѹ�ȼ�	 
	D_SITEB site[2];		//����
	DWORD color1;			//�й���ɫ
	DWORD color2;			//�޹���ɫ
	BYTE  yh;				//�Ż�0=�Ż�ǰ 1=�Ż���
	BYTE  direct;			//����0=���������뻭�߷���һ�� 1=�뻭�߷����෴
	BYTE  type;				//���� 0=���� 1=ֱ��
	BYTE  linestyle;		//�������� 0=Բ�� 1=���� 2=����
	char  reserved[33];		//ģ������
	char  dev_name[24];		//�豸��
	long  did;				//�豸��¼��(ID)
	WORD  ptsum;			//������
	DPOINT pt[1];			//������еĵ�
}N2_FLOW;


typedef struct N2_CONLINE{	//������  type=78 r17
	BYTE    autozoom;		//�Ƿ��Զ��Ŵ�����
	double  width;			//�߿��
	BYTE	shadow;			//��Ӱ
	BYTE	solder1;		//���ӵ�1��ʾ0=����ʾ 1=��ʾ
	BYTE	solder2;		//���ӵ�2��ʾ0=����ʾ 1=��ʾ
	BYTE	vl;				//��ѹ�ȼ�
	BYTE    conobj;			//���ӵ��豸��־ =0 δ���� =1 ������
	BYTE    el;				//����״̬ =0 ������ =1 ����
	LOGOBJ  lobj[2];		//�����������ӵĶ���
	char	rev[2];			//����
	WORD	ptsum;			//������
	DPOINT	pt[1];			//������еĵ�
}N2_CONLINE;

typedef struct N2_BUS{		//ĸ��  type=79 r18
	DPOINT  pt[4];			//4��������
	BYTE    type;			//����
	BYTE    shadow;			//��Ӱ
	BYTE	vl;				//��ѹ�ȼ�
	R_STA	rval;			//ʵʱֵ
	char    yh;				//�Ż�ǰ��
	char    valarm;			//��ѹ�澯״̬ 0=���� 1=Խ���� 2=Խ����
	WORD    eid;			//���ͼԪID
	char	rev[30];		//����
	char    dev_name[24];	//�豸��
	long    did;			//�豸ID��
}N2_BUS;

typedef struct N2_ACTOBJ{	//С�ͻ����  type=80
	DPOINT  pt[4];			//4��������
	short   gid;			//ͼ��ID
	WORD	pathid;			//����path ID
	BYTE	runmode;		//����ģʽ 0=�Զ� 1=ͬ��
	BYTE	speed;			//�Զ��������� 0,1,2,3
	float	skip;			//�Զ�����
	SINGLEDBS dsrc;			//����Դ
	char	rev[64];		//����
}N2_ACTOBJ;

typedef struct N2_FLASH{		//FLASH����  type=81
	DPOINT  pt[4];			//4��������
	char  fname[128];		//swf�ļ���
	BYTE  playmode;			//����ģʽ0=һ�� 1=ѭ��
	BYTE  align_left;		//�����
	BYTE  align_top;		//�϶���
	BYTE  align_right;		//�Ҷ���
	BYTE  align_buttom;		//�¶���
	char  reserved[28];		//����
}N2_FLASH;


typedef struct N2_PCTPIE{	//�ٷֱȱ�ͼ type=82
	DPOINT  pt[4];			//4��������
	double  zm;
	char    dev_name[24];   //�豸��
	int     did;			//�豸ID
	BYTE    type;			//�������� 0=������ 1=�����
	DWORD   color1,color2;  //������ɫ
	DWORD   fcolor;			//������ɫ
	LOGFONT lf;				//��������
	float   maxv;			//���ֵ
	float   curval;			//��ǰֵ
	char    reserved[24];	//��������
}N2_PCTPIE;

////////////////////////////////////////////////////////////////////////////////////////////////

#endif