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

		if(Mode==1) //被鼠标选择后黄颜色显示
		{
			pen.CreatePen(m_LineType,(int)m_LineWide+7,RGB(255,255,0));
			pDC->SelectObject(&pen);
			if(m_lb==5)  //绘制直线
		{
			pDC->Polyline(ppoint,m_Numble);
		}
		if(m_lb==6)  //绘制多边形
		{
			if(m_BrushType==6) pDC->SelectStockObject(NULL_BRUSH);
			pDC->Polygon(ppoint,m_Numble);
		}
		pen.DeleteObject();
		}

		if(Mode==2)  //缓冲区后特殊显示
	{
		CRgn rgn;
		CPen penb(1,(int)buff,RGB(255,255,0));
		CBrush brushb(m_BrushType,m_ColorBrush);
		pDC->BeginPath();
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&penb);
		if(m_lb==5)  //绘制直线
		{
			pDC->Polyline(ppoint,m_Numble);
		}
		if(m_lb==6)  //绘制多边形
		{
			if(m_BrushType==6) pDC->SelectStockObject(NULL_BRUSH);
			pDC->Polygon(ppoint,m_Numble);
		}
		pDC->EndPath();
		pDC->WidenPath();
		rgn.CreateFromPath(pDC);
		pDC->FillRgn(&rgn,&brushb);
		return;
	}

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

bool CPLine::IsPoint(CDC* pDC,float px,float py)
{
	if(b_Delete)
		return FALSE;
	CRgn rgn;
	int x1,y1;
	int i;
	POINT* ppoint;
	ppoint=new POINT[m_Numble];
	for(i=0;i<m_Numble;i++)
	{
		x1=m_PointList[i].x,y1=m_PointList[i].y;
		ppoint[i].x=x1;     ppoint[i].y=y1;
	}
	if(m_lb==6)
		rgn.CreatePolygonRgn(ppoint,m_Numble,1);
	else
	{
		pDC->BeginPath();
		pDC->Polyline(ppoint,m_Numble);
		pDC->EndPath();
		pDC->WidenPath();
		pDC->WidenPath();
		pDC->WidenPath();
		pDC->WidenPath();
		pDC->WidenPath();
		rgn.CreateFromPath(pDC);
	}
	i=rgn.PtInRegion(px,py);
	rgn.DeleteObject();
	return i;
}

bool CPLine::IsRect(CDC* pDC,CRect r)
{
	if(b_Delete)
		return FALSE;
	CRgn rgn;
	int x1,y1;
	int i;
	POINT* ppoint;
	ppoint=new POINT[m_Numble];
	for(i=0;i<m_Numble;i++)
	{
		x1=m_PointList[i].x,y1=m_PointList[i].y;
		ppoint[i].x=x1;     ppoint[i].y=y1;
	}
	if(m_lb==6)
		rgn.CreatePolygonRgn(ppoint,m_Numble,1);
	else
	{
		pDC->BeginPath();
		pDC->Polyline(ppoint,m_Numble);
		pDC->EndPath();
		pDC->WidenPath();
		pDC->WidenPath();
		pDC->WidenPath();
		pDC->WidenPath();
		pDC->WidenPath();
		rgn.CreateFromPath(pDC);
	}
	i=rgn.RectInRegion(r);
	rgn.DeleteObject();
	return i;
}