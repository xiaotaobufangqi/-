#include "StdAfx.h"
#include "Cpoint.h"
#include <math.h>


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
	c[0].x=x;   c[0].y=y-15;
	c[1].x=x-cos(30*3.14/180)*10;   c[1].y=y+2;
	c[2].x=x+cos(30*3.14/180)*10;   c[2].y=y+2;
	//五角星
	CPoint pts[5];
	 for(int i = 0; i < 5; i++)
	{
		pts[i].x = (long)(m_CircleX - 15 * cos((i * 144 - 18) * 3.14 / 180));
		pts[i].y = (long)(m_CircleY + 15 * sin((i * 144 - 18) * 3.14 / 180));
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