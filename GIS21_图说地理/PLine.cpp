#include "StdAfx.h"
#include "PLine.h"
IMPLEMENT_SERIAL(CPLine,CObject,1)

CPLine::CPLine(void)
{
}


/*CPLine::~CPLine(void)
{
}*/

CPLine::CPLine(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,BOOL Delete,int Numble,PointStruct* PointList,BOOL Lb):CDraw(ColorPen,ColorBrush,LineWide,LineType,BrushType,id_only,Delete)
{
	m_Numble=Numble;
	m_lb=Lb;
	m_PointList=new PointStruct[Numble];//分配空间
    if(Numble>0)
	{
		for(int i=0;i<Numble;i++)
			m_PointList[i]=PointList[i];
	}
}

CPLine::~CPLine()
{
	if(m_Numble>0)
		delete m_PointList;
}

void CPLine::Draw(CDC *pDC,int Mode,int buff)
{
	if(b_Delete)
		return;
	CPoint *ppoint;
	ppoint=new CPoint[m_Numble];
	for(int i=0;i<m_Numble;i++)  //将实际坐标转换成屏幕点阵坐标，存入ppoint
	{
		ppoint[i].x=m_PointList[i].x;
		ppoint[i].y=m_PointList[i].y;
	}
		CPen pen;
		pen.DeleteObject();
		pen.CreatePen(m_LineType,(int)m_LineWide,m_ColorPen);
		pDC->SelectObject(&pen);
		pDC->SetROP2(R2_COPYPEN);
		pDC->SetBkMode(TRANSPARENT);
		CBrush *oldbrush;
		CBrush brush(m_BrushType,m_ColorBrush);
	    oldbrush=pDC->SelectObject(&brush);
		pDC->SetBkColor(m_ColorBrush);
	    pDC->SetPolyFillMode(WINDING);

		if(m_lb==5)  //绘制直线
		{
			pDC->Polyline(ppoint,m_Numble);
		}
		if(m_lb==6)  //绘制多边形
		{
			if(m_BrushType==6) pDC->SelectStockObject(NULL_BRUSH);
			pDC->Polygon(ppoint,m_Numble);
		}
}

void CPLine::Serialize(CArchive& ar)
{
	CDraw::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		ar<<m_lb<<m_Numble;
		for(int i=0;i<m_Numble;i++)
			ar<<m_PointList[i].x<<m_PointList[i].y;
	}
	else
	{	// loading code
		ar>>m_lb>>m_Numble;
		m_PointList=new PointStruct[m_Numble];
		for(int i=0;i<m_Numble;i++)
			ar>>m_PointList[i].x>>m_PointList[i].y;
	}
}
