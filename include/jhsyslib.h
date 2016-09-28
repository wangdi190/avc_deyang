#if !defined(AFX_JHSYSLIB_H__INCLUDED_)
#define AFX_JHSYSLIB_H__INCLUDED_


#ifdef JHSYSLIB_EXPORTS
#define JHSYSLIB_API __declspec(dllexport)
#else
#define JHSYSLIB_API __declspec(dllimport)
#endif

//-------------------------------------------------------------------------
//  ͼ�δ���DLL:2000.11
//  ����:�½�
//  �޸ļ�¼:
//	1999.10   ��һ�� jhdclib.dll jhdclib2.h
//  2000.11   ��ԭ����JHDCLIB������JHDCLIB2
//  2000.12   ���ӱ�ͼ��class piechart  ԭ��������"format.h"
//  2001.3.1  ������jhdclib3 �����ݾɰ汾���ɰ汾������湤�߿��Լ���ʹ��
//			  �ص��޸���Ӱ���ֳ��򣬶�CDIB CMemDC������޸�
//  2005.10   ȫ��İ棬����һЩ�����ͼ���ȸ��ߵ��࣬����CIPoint CIRect�࣬
//			  ȥ��ԭ����ͼ�α�Ե����
//-------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////

#define  mpi  3.1415926535897932
#define  MAXCONTOUR    400
//////////////// ����˫���ȸ��������;�������//////////////////////////////
typedef struct _DPOINT{		 //��
	double x;				 //X����
	double y;				 //Y����
}DPOINT;

typedef struct _DRECT{		//����
	double left;			//���Ͻ�X����
	double top;				//���Ͻ�y����
	double right;			//���½�X����
	double bottom;			//���½�Y����
}DRECT;
//////////////////////////////////////////////////////////
typedef struct _PIEDAT{ //��ͼ���ݽṹ
	char name[12];       //��������
	float value;		 //ֵ
}PIEDAT;
typedef struct OBJ_PIEPAM{  //��ͼ�ṹ����
	WORD   ID;			 //ID��
	BYTE   style;		 //0=һ�� 1=���� 2=���� 3=��������
	BYTE   outline;		 //��Χ�� 0=�� 1=��
	BYTE   shad;		 //����ɫ 0=�� 1=��
	BYTE   sum;			 //����
	DWORD  fcolor;		 //�ַ�ɫ
	WORD   angle;		 //��ʼ�Ƕ�0-360��
	DWORD  color[8];     //8����ɫ
	PIEDAT pd[8];		 //8������ 
	char   reserved[12]; //�����ֽ�
}OBJ_PIEPAM;
/////////////////////////////////////////////////////////////////////////////
//-----���º��������⴦��Ļ�ͼ����----------------------------------------------------------------
//�������κ�HDC�ϻ���

void  JHSYSLIB_API GLLine(HDC hdc,int x1,int y1,int x2,int y2,DWORD color,int width=1);
void  JHSYSLIB_API GLLineXor(HDC hdc,int x1,int y1,int x2,int y2,DWORD color=0xffffff,int w=1);
void  JHSYSLIB_API GLCircleXor(HDC hdc,int x1,int y1,int x2,int y2);
void  JHSYSLIB_API GLRectXor(HDC hdc,int x1,int y1,int x2,int y2);
void  JHSYSLIB_API GLEllipse(HDC hdc,int x1,int y1,int x2,int y2,DWORD color);
void  JHSYSLIB_API GL3DRect(HDC hdc,RECT rt,DWORD color);
void  JHSYSLIB_API GLRectc(HDC hdc,RECT rt,DWORD color1,DWORD color2,WORD style);
void  JHSYSLIB_API GLPolygonc(HDC hdc,POINT *point,int count,DWORD color1,DWORD color2,WORD style);
void  JHSYSLIB_API GLEllipsec(HDC hdc,RECT rt,DWORD color1,DWORD color2,WORD style);
void  JHSYSLIB_API GL3DEllipsec(HDC hdc,RECT rt,DWORD color,int shad,int outline);
void  JHSYSLIB_API GL3DXEllipsec(HDC hdc,RECT rt,DWORD color,int shad,int outline);
SIZE  JHSYSLIB_API GLDGetTextSize(HDC hdc,LOGFONT *font,char *text);
void  JHSYSLIB_API GLDrawLine(HDC hdc,int x1,int y1,int x2,int y2,BYTE width,DWORD color);
void  JHSYSLIB_API GLDrawDbx(HDC hdc,int num,POINT *pt,BYTE width,DWORD color);
void  JHSYSLIB_API GLDrawOutLine(HDC hdc,int num,POINT *pt,BYTE width,DWORD color);
void  JHSYSLIB_API GLCircle(HDC hdc,int x1,int y1,int x2,int y2,int width,DWORD color);
void  JHSYSLIB_API GLRect(HDC hdc,int x1,int y1,int x2,int y2,int width,DWORD color);
void  JHSYSLIB_API GLDDraw3DRect(HDC hdc,RECT rt,DWORD color1=0,DWORD color2=0xffffff,int width=1);
void  JHSYSLIB_API GLDDrawText(HDC hdc,RECT *rt,LOGFONT *lf,char *text,DWORD color,int style,DWORD align=DT_LEFT);
void  JHSYSLIB_API GLFillRect(HDC hdc,RECT rt,DWORD color);
void  JHSYSLIB_API GLDrawButton(HDC hdc,RECT rt,char *text,int enable=0);
void  JHSYSLIB_API GLDrawDownButton(HDC hdc,RECT rt,char *text);
void  JHSYSLIB_API GLDrawTrend(HDC hdc,float *val,RECT rt,void *param);
void  JHSYSLIB_API GLDrawCure(HDC hdc,RECT drt,void *param);
void  JHSYSLIB_API GLDrawFormDemo(HDC hdc,RECT rt,char *name,int tranbg);
void  JHSYSLIB_API GLDrawBar(HDC hdc,RECT rt,void *data);
RECT  JHSYSLIB_API GLDrawCtrlOutline(HDC hdc,RECT rt,BYTE style=0);
void  JHSYSLIB_API GLDrawScroll(HDC hdc,RECT rt,int style);
void  JHSYSLIB_API GLDrawScrollA(HDC hdc,RECT rt,int style);
void  JHSYSLIB_API GLDrawHSin(HDC hdc,RECT rt,BYTE width,DWORD color,int xy,int pe,int mode);
void  JHSYSLIB_API GLDrawSin(HDC hdc,RECT rt,BYTE width,DWORD color,int xy,int pe);
void  JHSYSLIB_API DrawDIRSingle(HDC hdc,POINT ps,POINT pe,DWORD color,BYTE width); 
void  JHSYSLIB_API DrawBall(HDC hdc,RECT rt,DWORD color);
void  JHSYSLIB_API GLDrawArc(HDC hdc,RECT drt,DWORD color,WORD start,WORD end,BYTE w);
void  JHSYSLIB_API GLDraw2Pie(HDC hdc,RECT drt,DWORD c1,DWORD c2,DWORD c3,float percent);
/////////////////////////////////////////////////////////////////////////////////////////////
//�������
void  JHSYSLIB_API CptLookDown(DPOINT *tp,int tpsum,int wx,int wy);
void  JHSYSLIB_API CptLookDown(POINT *tp,int tpsum,int wx,int wy);
//����ת�������⴦��
void  JHSYSLIB_API GetDoubleStr(double value,char *str,int xs);
void  JHSYSLIB_API GetDtStr(int s,char *str);
HRGN  JHSYSLIB_API CreatePolyRgn(int ptsum,POINT *pt);
HRGN  JHSYSLIB_API CrealeLineRGN(POINT ps, POINT pe,double w);
RECT  JHSYSLIB_API CreateRt(int ptsum,POINT *pt);
////////////////24λ��ʽṹ����/////////////////////////////////////////////
typedef struct _RGB24{
	BYTE b,g,r;
}RGB24;
/////////////////////////////////////////////////////////////////////////////
class JHSYSLIB_API CIPoint:public tagPOINT
{
public:
	CIPoint();
	CIPoint(int initX, int initY);
	CIPoint(POINT initPt);
	void Offset(int xOffset,int yOffset);
	void Offset(POINT point);
	void Offset(SIZE size);
	void operator = (CIPoint point);
	void operator -=(CIPoint point);
	void operator +=(CIPoint point);
	CIPoint operator - (CIPoint point);
	CIPoint operator + (CIPoint point);
	bool operator == (CIPoint point);
};
//////////////////////////////////////////////////////////////////////////////
class JHSYSLIB_API CDPoint:public DPOINT
{
public:
	CDPoint();
	CDPoint(double initX, double initY);
	CDPoint(DPOINT initPt);
	void Offset(double xOffset,double yOffset);
	void Offset(DPOINT point);
	void ActPtToScr(double zoomm);
	void ScrPtToAct(double zoom);
	void GetPOINT(POINT&pt);
	void SetPOINT(POINT pt);
	void operator = (CDPoint point);
	void operator -=(CDPoint point);
	void operator +=(CDPoint point);
	CDPoint operator - (CDPoint point);
	CDPoint operator + (CDPoint point);
	bool operator == (CDPoint point);
};
//////////////////////////////////////////////////////////////////////////////
class JHSYSLIB_API CIRect:public tagRECT 
{
public:
	CIRect();
	public:
	POINT CenterPoint();
	void SetRectEmpty();
	void NormalizeRect();
	bool PtInRect(POINT point);
	bool IsRectEmpty();
	int  Height();
	int  Width();
	void SetRect(int x1, int y1, int x2, int y2);
	void SetRect(POINT topLeft, POINT bottomRight);
	void Offset(int dx,int dy);
	CIRect(int Left,int Top,int Right,int Bottom);
	void operator =(CIRect &rt);
	void operator &=(CIRect &rt);
	void operator |=(CIRect &rt);
};
///////////////////////////////////////////////////////////////////////////
class JHSYSLIB_API CDRect:public DRECT  
{
public:
	CDRect();
	virtual ~CDRect();
	public:
	DPOINT CenterPoint();
	void SetRectEmpty();
	void ActRtToScr(double zoom);
	void ScrRtToAct(double zoom);
	void GetDRECT(DRECT &rt);
	void GetRECT(RECT&rt);
	void NormalizeRect();
	BOOL PtInRect(CDPoint point);
	BOOL PtInRect(POINT point);
	BOOL IsRectEmpty( );
	double Height();
	double Width();
	void Offset(double dx,double dy);
	void Offset(int dx,int dy);
	CDRect(double ILeft,double ITop,double IRight,double IBottom);
	void operator =(CDRect &rt);
	void operator &=(CDRect &rt);
	void operator |=(CDRect &rt);
	void SetCRect(RECT &rt);
	void SetDRECT(DRECT &rt);
};

/////////////////////////////////////////////////////////////////////
//����ͼ��DC����ImageDC
class JHSYSLIB_API ImageDC  
{
public:
	void CreateRGN(BYTE index);
	void Show(HDC hdc,int x,int y,int w=0,int h=0);
	void FreeMem();
	void Create(char *sdib);
	ImageDC();
	virtual ~ImageDC();
	HDC m_hDC;              //HDC
	BITMAPINFO *bi;			//ͼ����Ϣ
	char    *bnf;			//BITMAPINFO������
	void    *dib;			//ͼ�ε�ַ
	HBITMAP hbitmap;		//λͼ���
	int     sPerline;		//ÿ���ֽ���
	int     nWidth,nHeight;	//��ȡ��߶�
	HRGN    hrgn;	        //ͼ�β��ֵ�����
	BYTE    tranflag;		//͸����־
	BYTE    colorindex;	    //͸������
private:
	int colornums(int bits);
};
//////////////////////////////////////////////////////////////
//������GIFAnm
struct IMGFRM{
	int    x,y;        //��ͼ��X,Yλ��
	int    w,h;		   //���
	BYTE   disposal;
	BYTE   tranflag;   //͸����־
	BYTE   tranIndex;  //͸����ɫ
	WORD   delay;	   //�ӳ�ʱ��
	int    count;	   //������
	ImageDC *imgdc;    //ͼƬ
};


class JHSYSLIB_API CGIFAnm  
{
public:
	bool CanShow();
	void FreeMem();
	void Show(HDC hdc,int x,int y,int w=0,int h=0);
	void ShowSel(HDC hdc,int n, int x, int y, int w=0, int h=0);
	void ReadGifFile(char *filename);
	CGIFAnm();
	virtual ~CGIFAnm();
	IMGFRM frm[60];      //60֡����
	int frmsum;          //��ǰ������
	int last;			 //��һ��
	int curfrm;			 //��ǰ֡
	WORD  width,height;  //����ռ�õĿ�ȸ߿�
	HDC m_hDC;              //HDC
	BITMAPINFO bi;			//ͼ����Ϣ
	void    *dib;			//ͼ�ε�ַ
	HBITMAP hbitmap;		//λͼ���
	int     sPerline;		//ÿ���ֽ���
private:
	void CreateDDB_buf();
};
//////////////////////////////////////////////////////////////////////////////////////////
class JHSYSLIB_API JpegFile 
{
public:
	char *m_dib;         //�豸�޹�λͼ
	BYTE *rgbbuf;		 //RGBͼ��
	int  width,height;	 //ͼ��߿�
	int  bytes_per_line;  //ÿ���ֽ���
public:
	void FreeMem();
	void read(char * fileName);

	static BOOL RGBToJpegFile(char * fileName,BYTE *dataBuf,UINT width,						
							UINT height,BOOL color,int quality);					
	static BOOL GetJPGDimensions(char * fileName,UINT *width,UINT *height);
	static BYTE * MakeDwordAlignedBuf(BYTE *dataBuf,UINT widthPix,UINT height,
									 UINT *uiOutWidthBytes);
	static BYTE *RGBFromDWORDAligned(BYTE *inBuf,UINT widthPix,UINT widthBytes,UINT height);
	static BOOL VertFlipBuf(BYTE * inbuf,UINT widthBytes,UINT height);							// height
	static BOOL MakeGrayScale(BYTE *buf,UINT widthPix,UINT height);	
	static BOOL BGRFromRGB(BYTE *buf,UINT widthPix,UINT height);								// lines
	JpegFile();
	~JpegFile();
private:
	void RGBToDIB();
};
///////////////////////////////////////////////////////////////////
//������ͼ�ε���CMImage

class JHSYSLIB_API CMImage : public ImageDC  
{
public:
	bool ReadImage(char *filename);
	CMImage();
	virtual ~CMImage();

private:
	void LoadMor(char *filename);
	void LoadPcx(char *filename);
	void LoadGif(char *filename);
	void LoadJpeg(char *filename);
	int GetTypeOfImg(char *filename);
};
///////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
class JHSYSLIB_API CMemDC  
{
public:
	CMemDC();
	virtual ~CMemDC();
	void Create(int width,int height);

//----------�ⲿ���ú���-------------------------------
public:							
	void CutNoUse();
	void SizeChange(int width,int height);		//�ı��С
	void FillBG(DWORD color);					//��ɫ���
	void BitBlt(HDC hdc,RECT rt,DWORD dwRop);	//��λͼ���䵽HDC
	void FillSolidRect(RECT rt,DWORD color);	//������
	void TranImage(DWORD color,DWORD Tolerance);//͸������
	void ReadImageFile(char *filename);			//����ͼ���ļ�	
	void FloodFill(POINT pt);					//ѩ�lʽ���
	bool GetPixel(int x,int y,RGB24&color);  //��������ɫ
	void SetPixel(int x,int y,RGB24 color);	//�������ص�
	void DrawBrushDot(int x,int y,int k,RGB24 rgb);
	void PenBrush(int x,int y,int ra,DWORD color);
	void AddBrushDot(int x,int y,int k);
	void AddPenBrush(int x,int y,int ra);
	HDC m_hDC;              //HDC
	BITMAPINFO bi;			//ͼ����Ϣ
	void    *dib;								//ͼ�ε�ַ
	HBITMAP hbitmap;							//λͼ���
	int     sPerline;							//ÿ���ֽ���
	int     nWidth,nHeight;						//��ȡ��߶�
	
};
////////////////////////////////////////////////////////////////////////////////////
//--------------C D I B--------------------------------
class JHSYSLIB_API CDIB
{
public:
	CDIB();
	~CDIB();
	//----------�ⲿ���ú���-------------------------------
	void Create(int width,int height);
	void SizeChange(int newWidth,int newHeight); //�ı�DIB�Ŀ�͸�
	void FillBG(DWORD color);
	void BitBlt(HDC hdc,RECT rt);
	void BitBltRect(HDC hdc,RECT rts,RECT rtd);
	void FillSolidRect(RECT rt,DWORD color);
	void ShadowRect(RECT rt,int style);
	void CopyDIB(CDIB&sdib);  //����DIB��ͼ�󵽱�CDIB������CDIB����һ���Ŀ�͸ߣ�
	void TranDIB(CDIB&sdib,DWORD trancolor);     //͸��DIB��ͼ�󵽱�CDIB������CDIB����һ���Ŀ�͸ߣ�
	//------��ͼ������ͼ����----------------------------------------------------------------------------------
	void CopyImg(CMemDC&mdc,RECT drt);				     //����ͼ�ε�������
	void TranImg(CMemDC&mdc,RECT drt,DWORD color=1);     //͸��
	void TranImgShadow(CMemDC&mdc,RECT drt,int shadow=0);//͸��+��Ӱ
	void FillImg(CMemDC&mdc);							 //��mdc�����
	void CopyImgPercent(CMemDC&mdc,RECT drt,BYTE depth); //���ٷֱȴ���(��͸��)
	void DrawArrow(POINT p1,POINT p2,DWORD color,int width);
	void CTextOut(char *str,RECT drt,LOGFONT *lf,DWORD color,int style,DWORD align=DT_LEFT) ;
	void CLine(POINT pt1,POINT pt2,DWORD color,int width);
	void CDLine(DPOINT p1,DPOINT p2,DWORD color);
	void CRectc(RECT rt,DWORD color1,DWORD color2,WORD style);
	void CDrawOutLine(POINT *point,int count,DWORD color);
	void CDrawOutDLine(DPOINT *point,int count,DWORD color);
	void CDrawDbx(POINT *point,int count,BYTE width,DWORD color);
	void CDrawDbx(DPOINT *point,int count,BYTE width,DWORD color);
	void CDrawFLow(POINT *point,int count,BYTE width,DWORD color,int start=0,int style=0);
	void CEllipsec(RECT rt,DWORD color);
	void CEllipsec(DRECT rt,DWORD color);
	void CCircle(RECT rt,int width,DWORD color);
	void CCircle(DRECT rt,int width,DWORD color);
	void CPolygonc(POINT *point,int count,DWORD color);
	void DrawBmp(HBITMAP hbmp,int xrc=0, int yrc=0,int xto=0,int yto=0,int w=0, int h=0,int rop=SRCCOPY);
	void CDrawRect(RECT drt,int Penw,DWORD Pcolor);                  //���ض���ɫ��һ���վ���
	void CDraw3DRect(RECT drt,DWORD color1,DWORD color2);            //��3D����
	void CDrawGlass(RECT rt,DWORD bcolor,DWORD fcolor,BYTE oline,BYTE dp);		  //��������
	void CDrawHSin(RECT rt,BYTE width,DWORD color,int xy,int pe,int mode);
	void CDrawSin(RECT rt,BYTE width,DWORD color,int xy,int pe,int startdeg);
	void CDrawArc(RECT rt,DWORD color,WORD s,WORD e,BYTE width);
	void CSetLineStyle(int LStyle);
	void CopyLookDownDIB(int sx,int sy,int dx,int dy,CDIB&mdc,int wx,int wy,RGB24 color);
	void LDCircle(DRECT rt,DWORD color,DWORD bcolor,int fill,int dx,int dy,int wx,int wy);
	//---------------------------------------------------------------------------------------------------------
public:
	void CDrawBar(RECT drt,void *data);
	void StrechImg(CMemDC &mdc,RECT rt,int shadow);
	RGB24 *GetDibAddr(int x,int y);
	void  ShadowPattern(BYTE *sdata,RECT rt,int sw,int sh);
	void  SmoothPattern(BYTE *sdata,RECT rt,int sw,int sh,DWORD color,int ss);
	//--------------------��������------------------------------------------------
	int		nWidth,nHeight;				//��ȡ��߶�
	HDC		m_hDC;						//���ڴ�DC
	void	*dib;						//ͼ�����ݵ�ַ	
	int		dibsize;							//DIB�ֽ���
	int		sPerline;					//ÿ���ֽ���
	HBITMAP hbitmap;					//�뱾DC��ص�λͼ
	BITMAPINFO bi;						//BMP��Ϣ
private:
	void    SubBright(int x,int y,BYTE *brush);
	void    SetRGB24(DWORD color);
	bool    PTIsInDC(POINT pt);
	double	tlx,tly;
	RGB24	tlrgb;
	int		linestyle;			//0=ʵ�� 1=���� 2=�㻮��
	int     lstym,lstya,lstyb;	//��������������Ҫ�Ĳ���
	void	QDrawDot();
	void    DrawSTyleDot();
	void	QLine(POINT p1,POINT p2,DWORD color); //�������ߣ����=1��
	void	QDrawLineX(double xs,double y,double xe,int yoff);
	void	QDrawLineY(double ys,double x,double ye,int xoff);
};

/////////////////////////////////////////////////////////////////////////////////////////////
//--------����ѹ���ࣺ�㷨ͬARJ,��ʧ�棬���Ϊ�ڴ��ַ-------------------------------------------------------

class JHSYSLIB_API cmpress{
  public:
	cmpress();
	~cmpress();
	int EEnCode(char *in,char *out,int sizein,int sizeout);
	void initdata();
  private:
	int PutChar(int c);
	int GetChar();
    BYTE  *inbuf,*outbuf; //���롢���������
    int   insize,outsize; //���롢�����������С���ֽڣ�
    int   injs,outjs;     //���롢���������
    DWORD textsize,codesize,printcount;
    BYTE  text_buf[4155];
	short match_position, match_length,lson[4097],rson[4353], dad[4097];
	unsigned short freq[628];
	short prnt[941];
	short son[627];
	unsigned short getbuf;
	BYTE getlen;
	unsigned short putbuf;
	BYTE putlen;
	unsigned short code,len;
	void InitTree(void);
	void InsertNode(int r);
	void DeleteNode(int p);
	void Putcode(short l, unsigned short c);
	void StartHuff();
	void reconst();
	void update(short c);
	void EncodeChar(unsigned short c);
	void EncodePosition(unsigned short c);
	void EncodeEnd();
	void Encode(void);
};

//---------��ѹ������ѹ���෴-----------------------------------------------------------------------
class JHSYSLIB_API uncmpres{
  public:
	uncmpres();
	~uncmpres();
	int DDeCode(char *in,char *out,int sizein,int sizeout);
	void initdata();
  private:
	int PutChar(int c);
	int GetChar();
	BYTE  *inbuf,*outbuf; //���롢���������
	int   insize,outsize; //���롢�����������С���ֽڣ�
	int   injs,outjs;     //���롢���������
	DWORD textsize , codesize, printcount;
	BYTE  text_buf[4155];
	short match_position, match_length,lson[4097],rson[4353], dad[4097];
	unsigned  short freq[628];
	short prnt[941];
	short son[627];
	unsigned short getbuf;
	BYTE getlen;
	unsigned short putbuf;
	BYTE putlen;
	unsigned short code,len;
	void DeleteNode(int p);
	int  GetBit(void);
	int  GetByte(void);
	void Putcode(int l, unsigned c);
	void StartHuff();
	void reconst();
	void update(int c);
	int  DecodeChar();
	int  DecodePosition();
	void Decode(void);
};
//////////////////////////////////////////////////////////////
//��ͼ������ 2000.12.29 �ɳ½����
//////////////////////////////////////////////////////////////
class JHSYSLIB_API piedraw  
{
public:
	void SetThisParam(OBJ_PIEPAM*piepam);
	void Show(HDC hdc,RECT rt);
	void OnDraw(HDC hdc);
	piedraw();
	virtual ~piedraw();
	int w,h;
	double   bf[8];
	double   vsum;
	OBJ_PIEPAM   pp;		//����
	POINT   point[380],pt3d[380];
private:
	void ShowText(HDC hdc,POINT pt,int c,char *text);
	void computpoint();
	void ShowValue(HDC hdc,int ax,int ay,int c,int index,int div=1);
	void computdata();
	void DrawPie4(HDC hdc);
	void DrawPie3(HDC hdc);
	void DrawPie2(HDC hdc);
	void DrawPie1(HDC hdc);
	void ComputXY();
	void CreateDemoData();
	void SizeChange(int wd,int hg);
	void GetMColor(DWORD color1, DWORD &c1, DWORD &c2);
	LOGFONT lf2;
	//����ϵͳ
	int  x,y,r;//Բ��,�뾭
	int  x0,x1,x2,x3;
	int  y0,y1,y2,y3,y4;
	//ԭ��ƫ��
	POINT org;
};
////////////////////////////////////////////////////////////////////////
typedef struct COLORPAL{ //��ɫ��
	DWORD color;         //��ɫ
	BYTE r,g,b;			 //��ɫ����
}COLORPAL;

typedef struct CTR_COLOR{		//�ȸ�����ɫ����
	float value[5];				//��Ӧ��5��ֵ
	DWORD color[5];				//��Ӧ�������ɫ
	char  unit[12];				//��λpu,h.mw
	char  vhow;					//ȡֵԼ��
	BYTE  emptyfill;			//�հ����
	/*
	  vhow=0  ȫ����Ч 
		  =1  ������Ч
		  =2  ������Ч
	  emptyfill=127
			   =255
			   =0
    */
}CTR_COLOR;

typedef struct SHOWCFG{
	WORD ver;					//�汾=0x1000;
	char first;					//��һ�α�־ 0=��һ�� 1=��
	char showdgx;				//�Ƿ���ʾ�ȸ���0=���� 1=��ʾ
	char gendyn;				//��̬��ʾ����� 
	char showrev;				//��������� 1=�й� 2=�޹� 3=��ѹ��
	char flowover;				//�����Ƴ�
	char ctrtype;				//�ȸ�������0=ĸ�ߵ�ѹ 1=ĸ�ߵ�ѹ�� 2=ĸ�ߵ�ѹ�� 3=�����״̬ 
								//4=�ڵ���
	char tranbg;				//�ȸ���͸������
	BYTE smooth;				//�ȸ���ƽ����1-30;
	BYTE oneline;				//�ȸ����Ƿ��� 0=����ɫ 1=����
	CTR_COLOR cr[20];			//��ǰϵͳ���еĵȸ�����ɫĿǰ6�� ������������ 
	char lookdown;				//���ӱ�־ 0=ƽ�� 1=����
	char cpu;					//CPU����0=��CPU 1=��CPU
	char flowdyn;				//������̬��ʾ
	char lmd;					//��������ʾ
	float flowzoom;				//������ͷ�Ŵ���
	float senzoom;				//�����ȷŴ���
	float pqzoom;				//�й��޹��Ŵ���
	float tpzoom;				//��ѹ�����ʷŴ���
	float tptzoom;				//��ѹ���¶ȷŴ�ϵ��
	char reserved[116];			//��������
}SHOWCFG;

class JHSYSLIB_API CContour  
{
public:
	void Draw(BYTE *pb,int w,int h,double zoom,int dx,int dy);
	CContour();
	virtual ~CContour();
	/////////////////////////////
	int    wx,wy;
	BYTE   *cb;
	BYTE   enable;	//�Ƿ���Ч0=��Ч 1=��Ч
	int    type;    //�ȸ�����״���� 0=���� 1=�߶�
	RECT   rt;		//����
	CIPoint cpt;	//���ĵ�λ��
	DPOINT *point;	//�߶ε�
	WORD   ptsum;	//����
	double v_pu;	//��ǰֵ
	BYTE   val;		//��ǰֵ ��ת����0-255֮���ֵ
	int    dis;		//����(��԰����С����)
private:
	void DrawLineDgx(POINT ps,POINT pe,int length);
	void DrawFirstLine(POINT ps, POINT pe,int depth);
	void FillRect(RECT &rect,int depth);
	void DrawRectDgx(RECT rect,int length);
};

class JHSYSLIB_API CSysContour  
{
public:
	bool SetContourEnable(int i);
	void MemSetPb();
	void ComputeMinDis();
	void SmoothDgx();
	void DrawDGX(CDIB&mdc,CIRect rt,int dx,int dy);
	void DrawDgxinMem(double zomm,int dx,int dy);
	bool SetVal(int i,double val);
	void ScrSizeChange(int width,int height);
	void SetNPOINTPos(DPOINT *np,int ptsum,int i);
	void SetRectPos(RECT rt,int i);
	void CreatePalette();
	void SetCfg(SHOWCFG  *cfg);
	CSysContour();
	virtual ~CSysContour();
	SHOWCFG  *p_cfg;	//��ʾ���õ�ַ
	COLORPAL cmap[256]; //256ɫ��ɫ��
	int  w,h;			//��Ļ�ĸߺͿ�
	BYTE *pb;			//�ȸ��߻�����
	CContour contr[MAXCONTOUR];//�ȸ��߻���Ԫ��
	int  csum;			//�ȸ��߸���
	double curzoom;		//��ǰ����Ļ�Ŵ�ϵ��
private:
	void ShowDgxOneLine(CDIB &mdc, RECT rt);
	void ShowDgx3(CDIB&mdc,RECT rt);
	void ShowDgx012(CDIB&mdc,RECT rt);
	void ComputAVal(int i);
};
/**********************************************
ͼ��������ӳ���2000.11.12 CJH
***********************************************/
//24λͼ�ε�Ƭ����
void JHSYSLIB_API img24_reverse(BYTE  *dib,int w,int h); 
//24λͼ�λҶȴ���
void JHSYSLIB_API img24_gray(BYTE  *dib,int w,int h); 
//24λͼ�ξ�����
void JHSYSLIB_API img24_glass(BYTE  *dib,int w,int h);   
//24λͼ�ε��ô���
void JHSYSLIB_API img24_updown(BYTE  *dib,int w,int h);  
//24λͼ��ƽ������
void JHSYSLIB_API img24_smooth(BYTE  *dib,int w,int h);  
//24λͼ�μ�ɫ����
void JHSYSLIB_API img24_rcolor(BYTE  *dib,int w,int h,
				  BYTE MaxColor);  
//24λͼ������Ե
void JHSYSLIB_API img24_bd_bright(BYTE  *dib,int w,int h);
//24λͼ�Ӻڱ�Ե
void JHSYSLIB_API img24_bd_black(BYTE *dib,int w,int h); 
//24λͼ�Ӻڱ߿�
void JHSYSLIB_API img24_bd_hard(BYTE  *dib,int w,int h);  
//24λͼ��ˮ��
void JHSYSLIB_API img24_bd_wl(BYTE  *dib,int w,int h);	 
//24λͼ����С
void JHSYSLIB_API img24_stratch(BYTE *dib1,	BYTE *dib2,int w1,int h1,int w2,int h2);
//////////////////////////////////////////////////////////////////////////////////////
//���⴦���ӳ���
HRGN JHSYSLIB_API BCreateLine1RGN(POINT ps, POINT pe,double width);
int  JHSYSLIB_API GetTowPtDistance(POINT p1,POINT p2);
///////////////////////////////////////////////////////////////////////////////////////
#endif