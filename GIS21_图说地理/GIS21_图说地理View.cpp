
// GIS21_图说地理View.cpp : CGIS21_图说地理View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "GIS21_图说地理.h"
#endif

#include "GIS21_图说地理Doc.h"
#include "GIS21_图说地理View.h"
#include "Tool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGIS21_图说地理View

IMPLEMENT_DYNCREATE(CGIS21_图说地理View, CView)

BEGIN_MESSAGE_MAP(CGIS21_图说地理View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGIS21_图说地理View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_yuan, &CGIS21_图说地理View::OnYuan)
	ON_UPDATE_COMMAND_UI(ID_yuan, &CGIS21_图说地理View::OnUpdateYuan)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_sanjiaoxin, &CGIS21_图说地理View::OnSanjiaoxin)
	ON_UPDATE_COMMAND_UI(ID_sanjiaoxin, &CGIS21_图说地理View::OnUpdateSanjiaoxin)
	ON_COMMAND(ID_wujiaoxin, &CGIS21_图说地理View::OnWujiaoxin)
	ON_UPDATE_COMMAND_UI(ID_wujiaoxin, &CGIS21_图说地理View::OnUpdateWujiaoxin)
	ON_COMMAND(ID_xinxin, &CGIS21_图说地理View::OnXinxin)
	ON_UPDATE_COMMAND_UI(ID_xinxin, &CGIS21_图说地理View::OnUpdateXinxin)
	ON_COMMAND(ID_draw_zhexian, &CGIS21_图说地理View::OnDrawZhexian)
	ON_UPDATE_COMMAND_UI(ID_draw_zhexian, &CGIS21_图说地理View::OnUpdateDrawZhexian)
	ON_COMMAND(ID_draw_duobianxin, &CGIS21_图说地理View::OnDrawDuobianxin)
	ON_UPDATE_COMMAND_UI(ID_draw_duobianxin, &CGIS21_图说地理View::OnUpdateDrawDuobianxin)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_Tool, &CGIS21_图说地理View::OnTool)
END_MESSAGE_MAP()

// CGIS21_图说地理View 构造/析构

CGIS21_图说地理View::CGIS21_图说地理View():m_pen(PS_SOLID,2,RGB(255,0,0)),m_brush(1,RGB(0,0,255))
{
	// TODO: 在此处添加构造代码
	m_pColor=RGB(0,0,255);  //设置笔色
	m_brColor=RGB(0,0,255);  //画刷色
	m_LineWide=3;  //设置笔宽
	m_LineType=0;  //设置线型
	m_BrushType=3;  //设置画刷色
	PointXyz=new PointStruct[100];  //存储连续直线点的数组
}

CGIS21_图说地理View::~CGIS21_图说地理View()
{
	delete PointXyz;
}

BOOL CGIS21_图说地理View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGIS21_图说地理View 绘制

void CGIS21_图说地理View::OnDraw(CDC* pDC)
{
	CGIS21_图说地理Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->Draw(pDC,0);
	// TODO: 在此处为本机数据添加绘制代码
}


// CGIS21_图说地理View 打印


void CGIS21_图说地理View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGIS21_图说地理View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGIS21_图说地理View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGIS21_图说地理View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CGIS21_图说地理View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGIS21_图说地理View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGIS21_图说地理View 诊断

#ifdef _DEBUG
void CGIS21_图说地理View::AssertValid() const
{
	CView::AssertValid();
}

void CGIS21_图说地理View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGIS21_图说地理Doc* CGIS21_图说地理View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGIS21_图说地理Doc)));
	return (CGIS21_图说地理Doc*)m_pDocument;
}
#endif //_DEBUG


// CGIS21_图说地理View 消息处理程序


void CGIS21_图说地理View::OnYuan()
{
	// TODO: 在此添加命令处理程序代码
	PushNumb=0;
	m_DrawCurrent=1;

}


void CGIS21_图说地理View::OnUpdateYuan(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_DrawCurrent==1);
}


void CGIS21_图说地理View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CGIS21_图说地理Doc* pDoc=GetDocument();  //得到文档指针
	CClientDC ht(this);
	int id_only;
	float xx,yy;
	if(m_DrawCurrent==1||m_DrawCurrent==2||m_DrawCurrent==3||m_DrawCurrent==4)  //如果正在绘制点
	{
		if(PushNumb==0)
		{
			PushNumb++;
			SetCapture();
			id_only=pDoc->GetGraphID(1);
			xx=point.x;     yy=point.y;
			pDoc->AddPoint(m_pColor,m_brColor,m_LineWide,m_LineType,m_BrushType,id_only,xx,yy,10,m_DrawCurrent)->Draw(&ht,0,0);
			PushNumb=0;
			ReleaseCapture();
		}
	}
	else if(m_DrawCurrent==5||m_DrawCurrent==6)
	{
		PointXyz[PushNumb].x=point.x;
		PointXyz[PushNumb].y=point.y;
		if(PushNumb==0)
		{
			SetCapture();
			mPointOrign=point;
			mPointOld=point;
		}
		mPointOrign=mPointOld;
		mPointOld=point;
		PushNumb++;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CGIS21_图说地理View::OnSanjiaoxin()
{
	// TODO: 在此添加命令处理程序代码
	PushNumb=0;
	m_DrawCurrent=2;
}


void CGIS21_图说地理View::OnUpdateSanjiaoxin(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_DrawCurrent==2);
}


void CGIS21_图说地理View::OnWujiaoxin()
{
	// TODO: 在此添加命令处理程序代码
	PushNumb=0;
	m_DrawCurrent=3;
}


void CGIS21_图说地理View::OnUpdateWujiaoxin(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_DrawCurrent==3);
}


void CGIS21_图说地理View::OnXinxin()
{
	// TODO: 在此添加命令处理程序代码
	PushNumb=0;
	m_DrawCurrent=4;
}


void CGIS21_图说地理View::OnUpdateXinxin(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_DrawCurrent==4);
}


void CGIS21_图说地理View::OnDrawZhexian()
{
	// TODO: 在此添加命令处理程序代码
	PushNumb=0;
	m_DrawCurrent=5;
}


void CGIS21_图说地理View::OnUpdateDrawZhexian(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_DrawCurrent==5);
}


void CGIS21_图说地理View::OnDrawDuobianxin()
{
	// TODO: 在此添加命令处理程序代码
	PushNumb=0;
	m_DrawCurrent=6;
}


void CGIS21_图说地理View::OnUpdateDrawDuobianxin(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_DrawCurrent==6);
}


void CGIS21_图说地理View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CGIS21_图说地理Doc* pDoc=GetDocument();
	CClientDC ddd(this);
	float x1,y1;
	int id_only;
	if((m_DrawCurrent==5||m_DrawCurrent==6)&&PushNumb>1)
	{
		id_only=pDoc->GetGraphID(2);
		for(int i=0;i<PushNumb;i++)
		{
			x1=PointXyz[i].x;
			y1=PointXyz[i].y;
			PointXyz[i].x=x1;
			PointXyz[i].y=y1;
		}
		pDoc->AddPLine(m_pColor,m_brColor,m_LineWide,m_LineType,m_BrushType,id_only,PushNumb,PointXyz,m_DrawCurrent)->Draw(&ddd,0,0);
		ReleaseCapture();
		PushNumb=0;
	}

	CView::OnLButtonDblClk(nFlags, point);
}


void CGIS21_图说地理View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC ddd(this);
	ddd.SelectObject(&m_pen);
	ddd.SetROP2(R2_NOTXORPEN);  //选择画笔反色的绘画模式
	if((m_DrawCurrent==5||m_DrawCurrent==6)&&PushNumb>=1)
	{
		if(mPointOld!=point)
		{
			ddd.MoveTo(mPointOrign);
			ddd.LineTo(mPointOld);  //擦除原来的直线
			ddd.MoveTo(mPointOrign);
			ddd.LineTo(point);  //重画移动到点的直线
			mPointOld=point;
		}
	}

	CView::OnMouseMove(nFlags, point);
}


void CGIS21_图说地理View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC ddd(this);
	int x1,y1;
	ddd.SelectObject(&m_pen);
	ddd.SetROP2(R2_NOTXORPEN);
	if((m_DrawCurrent==5||m_DrawCurrent==6))
	{
		CPoint *ppoint;
		ppoint=new CPoint[PushNumb];
		for(int i=0;i<PushNumb;i++)  //将实际坐标转换成屏幕点阵坐标，存入ppoint
		{
			ppoint[i].x=PointXyz[i].x;
			ppoint[i].y=PointXyz[i].y;
		}
		ddd.Polyline(ppoint,PushNumb);
		ddd.MoveTo(mPointOrign);
		ddd.LineTo(mPointOld);
		PushNumb=0;
		ReleaseCapture();  //释放捕捉的鼠标
	}
	CView::OnRButtonDown(nFlags, point);
}


void CGIS21_图说地理View::OnTool()
{
	// TODO: 在此添加命令处理程序代码
	CTool dd;
	dd.pColor=m_pColor;
	dd.brColor=m_brColor;
	dd.kd=m_LineWide;
	dd.pent=m_LineType;
	dd.brusht=m_BrushType;
	if(dd.DoModal()==IDOK)
	{
		m_LineWide=dd.kd;
		m_pColor=dd.pColor;
		m_brColor=dd.brColor ;
		m_LineType=dd.pent;
		m_BrushType=dd.brusht;
		
		m_pen.DeleteObject();
		m_pen.CreatePen(m_LineType,m_LineWide,m_pColor);
		m_brush.DeleteObject();
		m_brush.CreateHatchBrush(m_BrushType,m_brColor);
	}
}
