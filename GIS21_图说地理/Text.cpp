#include "StdAfx.h"
#include "Text.h"
#include <math.h>
IMPLEMENT_SERIAL(CText,CObject,1);

CText::CText(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,BOOL Delete,float StartX,float StartY,float Angle,float TextHeight,float TextWide,float FontWeight,CString Text):CDraw(ColorPen,ColorBrush,LineWide,LineType,BrushType,id_only,Delete)
{
	m_StartX=StartX;
	m_StartY=StartY;
	m_Angle=Angle;
	m_TextHeight=TextHeight;
	m_TextWide=TextWide;
	m_FontWeight=FontWeight;
	m_Text=Text;
	m_TextLong=Text.GetLength();
}

CText::CText(void)
{
}

CText::~CText(void)
{
}

void CText::Draw(CDC *pDC,int Mode,int buff)
{
	if(b_Delete) return; //如果已经处于删除状态
	pDC->SetROP2(R2_COPYPEN); //设定覆盖的绘制模式
	pDC->SetBkMode(TRANSPARENT);
	CFont cjcf;  //定义一个字模
	int high,wide,cc1,cc2,angg;
	float x1,y1,angl;
	angl=(float)(m_Angle*3.14/180);
	angg=(int)(m_Angle*10);
	high=m_TextHeight; //得到字体的点阵高度
	x1=m_StartX-m_TextHeight*(float)sin(angl);
	y1=m_StartY-m_TextHeight*(float)cos(angl);
	wide=m_TextWide;
	cc1=x1;
	cc2=y1;
	cjcf.CreateFont(high,wide,angg,0,m_FontWeight,0,0,0,1,OUT_TT_PRECIS,CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,FIXED_PITCH,_T("cjc"));
	CFont* cjcbakf=pDC->SelectObject(&cjcf);

	if(Mode==1) //被鼠标选择选择后黄色显示
	{
		pDC->SetBkMode(OPAQUE);
		if(GetRValue(m_ColorPen)==255&&GetGValue(m_ColorPen)==255)
			pDC->SetBkColor(RGB(100,100,100));
		else
			pDC->SetBkColor(RGB(255,255,0));
	}

	pDC->SetTextColor(m_ColorPen); //设定文本颜色
	pDC->TextOut(cc1,cc2,m_Text); //在屏幕上写字符//文本字符
	pDC->SetBkMode(OPAQUE);
	pDC->SelectObject(cjcbakf); //恢复字模
}

void CText::Serialize(CArchive& ar)
{
	CDraw::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		ar<<m_Angle<<m_FontWeight<<m_StartX<<m_StartY<<m_Text<<m_TextHeight<<m_TextLong<<m_TextWide;
	}
	else
	{	// loading code
		ar>>m_Angle>>m_FontWeight>>m_StartX>>m_StartY>>m_Text>>m_TextHeight>>m_TextLong>>m_TextWide;
	}
}

bool CText::IsPoint(CDC* pDC,float px,float py)
{
	if(b_Delete)
		return FALSE;
	CRgn rgn;
	float xx1,yy1,xx2,yy2;
	int xx3,yy3,xx4,yy4;
	bool i;
	GetRect(&xx1,&yy1,&xx2,&yy2);
	xx3=xx1;yy3=yy1;
	xx4=xx2;yy4=yy2;
	rgn.CreateRectRgn(xx3,yy3,xx4,yy4);
	i=rgn.PtInRegion(px,py);
	rgn.DeleteObject();
	return i;
}

void CText::GetRect(float* minX,float* minY,float* maxX,float* maxY)
{
	float x[4],y[4];
	double ang=3.14*m_Angle/180;
	TCHAR c1;   const TCHAR* ls1;
	ls1=(const TCHAR*)m_Text;
	c1=*ls1;
	x[0]=m_StartX;   y[0]=m_StartY;
	if(c1>127)  //如果是一个汉字
	{
		x[1]=m_StartX+(float)((m_TextWide*2)*m_TextLong*cos(ang));
		y[1]=m_StartY-(float)((m_TextWide*2)*m_TextLong*sin(ang));
	}
	else
	{
		x[1]=m_StartX+(float)((m_TextWide)*m_TextLong*cos(ang));
		y[1]=m_StartY-(float)((m_TextWide)*m_TextLong*sin(ang));
	}
		x[2]=x[1]-(float)(sin(ang)*m_TextHeight);
		y[2]=y[1]-(float)(cos(ang)*m_TextHeight);
		x[3]=m_StartX-(float)(sin(ang)*m_TextHeight);
		y[3]=m_StartY-(float)(cos(ang)*m_TextHeight);
		*minX=m_StartX; *minY=m_StartY; *maxX=m_StartX; *maxY=m_StartY;
		for(int i=1;i<4;i++)
		{
			if(*minX>x[i])*minX=x[i];   if(*minY>y[i])*minY=y[i];
			if(*maxX<x[i])*maxX=x[i];   if(*maxY<y[i])*maxY=y[i];
		}
}

bool CText::IsRect(CDC* pDC,CRect r)
{
	if(b_Delete)
		return FALSE;
	CRgn rgn;
	float xx1,yy1,xx2,yy2;
	float xx3,yy3,xx4,yy4;
	bool i;
	GetRect(&xx1,&yy1,&xx2,&yy2);
	xx3=xx1;yy3=yy1;
	xx4=xx2;yy4=yy2;
	if(xx3==xx4||xx4==yy4)
	{
		xx3-=10;yy3-=10;xx4+=10;yy4+=10;
	}
	rgn.CreateRectRgn(xx3,yy3,xx4,yy4);
	i=rgn.RectInRegion(r);
	rgn.DeleteObject();
	return i;
}