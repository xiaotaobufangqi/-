#include "StdAfx.h"
#include "Cpoint.h"
#include <math.h>
IMPLEMENT_SERIAL(Cpoint,CObject,1)


Cpoint::Cpoint(void)
{
}


Cpoint::~Cpoint(void)
{
}

Cpoint::Cpoint(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,BOOL Delete,float CircleX,float CircleY,float CircleR,short Lb):CDraw(ColorPen,ColorBrush,LineWide,LineType,BrushType,id_only,Delete)
{
	 m_CircleX=CircleX;
	 m_CircleY=CircleY;
	 m_CircleR=CircleR;
	 m_Lb=Lb;
}

void Cpoint::Draw(CDC *pDC,int Mode,int buff)
{
	if(b_Delete)  return;  //如果已经处于删除状态
	int x,y,r;
	CPen pen;
	CBrush *oldbrush;
	x=m_CircleX;
	y=m_CircleY;
	r=m_CircleR;
	//三角形
	CPoint c[3];
	c[0].x=x;   c[0].y=y-10;
	c[1].x=x-cos(10*3.14/180)*8;   c[1].y=y+2;
	c[2].x=x+cos(10*3.14/180)*8;   c[2].y=y+2;
	//五角星
	CPoint pts[5];
	 for(int i = 0; i < 5; i++)
	{
		pts[i].x = (long)(m_CircleX - 10 * cos((i * 144 - 18) * 3.14 / 180));
		pts[i].y = (long)(m_CircleY + 10 * sin((i * 144 - 18) * 3.14 / 180));
	}
	 //心
	CArray<CPoint,const CPoint &> lines;
	for(float t=0;t<2*3.14;t+=0.001)
	{
		float x=16*pow(sinf(t),3);
		float y=13*cosf(t)-5*cosf(2*t)-2*cosf(3*t)-cosf(4*t);
		lines.Add(CPoint(x*1+m_CircleX,-y*1+m_CircleY));
	}
	CBrush brush(m_ColorBrush);
	oldbrush=pDC->SelectObject(&brush);

	if(Mode==1)
	{
		pen.CreatePen(m_LineType,(int)m_LineWide+12,RGB(255,255,0));
		pDC->SelectObject(&pen);
		if(m_Lb==1)  pDC->Ellipse(x-r,y-r,x+r,y+r);  //绘制圆
	if(m_Lb==2) pDC->Polygon(c,3);  //三角形
	if(m_Lb==3) pDC->Polygon(pts, 5);  //五角星
	if(m_Lb==4) pDC->Polygon(&lines[0], lines.GetSize());//心形
	}
	pen.DeleteObject();

	if(Mode==2)  //缓冲区后特殊显示
	{
		CRgn rgn;
		CPen penb(1,(int)buff,RGB(255,255,0));
		CBrush brushb(m_BrushType,m_ColorBrush);
		pDC->BeginPath();
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&penb);
		if(m_Lb==1)  pDC->Ellipse(x-r,y-r,x+r,y+r);  //绘制圆
	if(m_Lb==2) pDC->Polygon(c,3);  //三角形
	if(m_Lb==3) pDC->Polygon(pts, 5);  //五角星
	if(m_Lb==4) pDC->Polygon(&lines[0], lines.GetSize());//心形
		pDC->EndPath();
		pDC->WidenPath();
		rgn.CreateFromPath(pDC);
		pDC->FillRgn(&rgn,&brushb);
		return;
	}

	pen.CreatePen(m_LineType,(int)m_LineWide,m_ColorPen);   //设定画笔的线型，宽度，颜色
	pDC->SelectObject(&pen);
	pDC->SetBkMode(OPAQUE);
	pDC->SetBkColor(m_ColorBrush);
	pDC->SetPolyFillMode(WINDING);
	if(m_Lb==1)  pDC->Ellipse(x-r,y-r,x+r,y+r);  //绘制圆
	if(m_Lb==2) pDC->Polygon(c,3);  //三角形
	if(m_Lb==3) pDC->Polygon(pts, 5);  //五角星
	if(m_Lb==4) pDC->Polygon(&lines[0], lines.GetSize());//心形
	pDC->SelectObject(oldbrush);

}

void Cpoint::Serialize(CArchive& ar)
{
	CDraw::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		ar<<m_CircleR<<m_CircleX<<m_CircleY<<m_Lb;
	}
	else
	{	// loading code
		ar>>m_CircleR>>m_CircleX>>m_CircleY>>m_Lb;
	}
}

bool Cpoint::IsPoint(CDC* pDC,float px,float py)
{
	if(b_Delete) return FALSE;
	CRgn rgn;
	int i,x,y;
	float r;
	x=m_CircleX;
	y=m_CircleY;
	r=m_CircleR;

	//三角形
	CPoint c[3];
	c[0].x=x;   c[0].y=y-10;
	c[1].x=x-cos(10*3.14/180)*8;   c[1].y=y+2;
	c[2].x=x+cos(10*3.14/180)*8;   c[2].y=y+2;
	//五角星
	CPoint pts[5];
	 for(int i = 0; i < 5; i++)
	{
		pts[i].x = (long)(m_CircleX - 10 * cos((i * 144 - 18) * 3.14 / 180));
		pts[i].y = (long)(m_CircleY + 10 * sin((i * 144 - 18) * 3.14 / 180));
	}
	 //心
	CArray<CPoint,const CPoint &> lines;
	for(float t=0;t<2*3.14;t+=0.001)
	{
		float x=16*pow(sinf(t),3);
		float y=13*cosf(t)-5*cosf(2*t)-2*cosf(3*t)-cosf(4*t);
		lines.Add(CPoint(x*1+m_CircleX,-y*1+m_CircleY));
	}

	if(m_Lb==1)  rgn.CreateEllipticRgn(x-r,y-r,x+r,y+r);  //绘制圆
	if(m_Lb==2) rgn.CreatePolygonRgn(c,3,1);  //三角形
	if(m_Lb==3) rgn.CreatePolygonRgn(pts, 5,1);  //五角星
	if(m_Lb==4) rgn.CreatePolygonRgn(&lines[0], lines.GetSize(),1);//心形
	i=rgn.PtInRegion(px,py);
	rgn.DeleteObject();
	return i;
}

bool Cpoint::IsRect(CDC* pDC,CRect rr)
{
	if(b_Delete) return FALSE;
	CRgn rgn;
	int i,x,y;
	float r;
	x=m_CircleX;
	y=m_CircleY;
	r=m_CircleR;

	//三角形
	CPoint c[3];
	c[0].x=x;   c[0].y=y-10;
	c[1].x=x-cos(10*3.14/180)*8;   c[1].y=y+2;
	c[2].x=x+cos(10*3.14/180)*8;   c[2].y=y+2;
	//五角星
	CPoint pts[5];
	 for(int i = 0; i < 5; i++)
	{
		pts[i].x = (long)(m_CircleX - 10 * cos((i * 144 - 18) * 3.14 / 180));
		pts[i].y = (long)(m_CircleY + 10 * sin((i * 144 - 18) * 3.14 / 180));
	}
	 //心
	CArray<CPoint,const CPoint &> lines;
	for(float t=0;t<2*3.14;t+=0.001)
	{
		float x=16*pow(sinf(t),3);
		float y=13*cosf(t)-5*cosf(2*t)-2*cosf(3*t)-cosf(4*t);
		lines.Add(CPoint(x*1+m_CircleX,-y*1+m_CircleY));
	}

	if(m_Lb==1)  rgn.CreateEllipticRgn(x-r,y-r,x+r,y+r);  //绘制圆
	if(m_Lb==2) rgn.CreatePolygonRgn(c,3,1);  //三角形
	if(m_Lb==3) rgn.CreatePolygonRgn(pts, 5,1);  //五角星
	if(m_Lb==4) rgn.CreatePolygonRgn(&lines[0], lines.GetSize(),1);//心形
	i=rgn.RectInRegion(rr);
	rgn.DeleteObject();
	return i;
}
