
// GIS21_ͼ˵����View.cpp : CGIS21_ͼ˵����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "GIS21_ͼ˵����.h"
#endif

#include "GIS21_ͼ˵����Doc.h"
#include "GIS21_ͼ˵����View.h"
#include "Tool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGIS21_ͼ˵����View

IMPLEMENT_DYNCREATE(CGIS21_ͼ˵����View, CView)

BEGIN_MESSAGE_MAP(CGIS21_ͼ˵����View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGIS21_ͼ˵����View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_yuan, &CGIS21_ͼ˵����View::OnYuan)
	ON_UPDATE_COMMAND_UI(ID_yuan, &CGIS21_ͼ˵����View::OnUpdateYuan)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_sanjiaoxin, &CGIS21_ͼ˵����View::OnSanjiaoxin)
	ON_UPDATE_COMMAND_UI(ID_sanjiaoxin, &CGIS21_ͼ˵����View::OnUpdateSanjiaoxin)
	ON_COMMAND(ID_wujiaoxin, &CGIS21_ͼ˵����View::OnWujiaoxin)
	ON_UPDATE_COMMAND_UI(ID_wujiaoxin, &CGIS21_ͼ˵����View::OnUpdateWujiaoxin)
	ON_COMMAND(ID_xinxin, &CGIS21_ͼ˵����View::OnXinxin)
	ON_UPDATE_COMMAND_UI(ID_xinxin, &CGIS21_ͼ˵����View::OnUpdateXinxin)
	ON_COMMAND(ID_draw_zhexian, &CGIS21_ͼ˵����View::OnDrawZhexian)
	ON_UPDATE_COMMAND_UI(ID_draw_zhexian, &CGIS21_ͼ˵����View::OnUpdateDrawZhexian)
	ON_COMMAND(ID_draw_duobianxin, &CGIS21_ͼ˵����View::OnDrawDuobianxin)
	ON_UPDATE_COMMAND_UI(ID_draw_duobianxin, &CGIS21_ͼ˵����View::OnUpdateDrawDuobianxin)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_Tool, &CGIS21_ͼ˵����View::OnTool)
END_MESSAGE_MAP()

// CGIS21_ͼ˵����View ����/����

CGIS21_ͼ˵����View::CGIS21_ͼ˵����View():m_pen(PS_SOLID,2,RGB(255,0,0)),m_brush(1,RGB(0,0,255))
{
	// TODO: �ڴ˴���ӹ������
	m_pColor=RGB(0,0,255);  //���ñ�ɫ
	m_brColor=RGB(0,0,255);  //��ˢɫ
	m_LineWide=3;  //���ñʿ�
	m_LineType=0;  //��������
	m_BrushType=3;  //���û�ˢɫ
	PointXyz=new PointStruct[100];  //�洢����ֱ�ߵ������
}

CGIS21_ͼ˵����View::~CGIS21_ͼ˵����View()
{
	delete PointXyz;
}

BOOL CGIS21_ͼ˵����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CGIS21_ͼ˵����View ����

void CGIS21_ͼ˵����View::OnDraw(CDC* pDC)
{
	CGIS21_ͼ˵����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->Draw(pDC,0);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CGIS21_ͼ˵����View ��ӡ


void CGIS21_ͼ˵����View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGIS21_ͼ˵����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGIS21_ͼ˵����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGIS21_ͼ˵����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CGIS21_ͼ˵����View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGIS21_ͼ˵����View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGIS21_ͼ˵����View ���

#ifdef _DEBUG
void CGIS21_ͼ˵����View::AssertValid() const
{
	CView::AssertValid();
}

void CGIS21_ͼ˵����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGIS21_ͼ˵����Doc* CGIS21_ͼ˵����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGIS21_ͼ˵����Doc)));
	return (CGIS21_ͼ˵����Doc*)m_pDocument;
}
#endif //_DEBUG


// CGIS21_ͼ˵����View ��Ϣ�������


void CGIS21_ͼ˵����View::OnYuan()
{
	// TODO: �ڴ���������������
	PushNumb=0;
	m_DrawCurrent=1;

}


void CGIS21_ͼ˵����View::OnUpdateYuan(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetRadio(m_DrawCurrent==1);
}


void CGIS21_ͼ˵����View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CGIS21_ͼ˵����Doc* pDoc=GetDocument();  //�õ��ĵ�ָ��
	CClientDC ht(this);
	int id_only;
	float xx,yy;
	if(m_DrawCurrent==1||m_DrawCurrent==2||m_DrawCurrent==3||m_DrawCurrent==4)  //������ڻ��Ƶ�
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


void CGIS21_ͼ˵����View::OnSanjiaoxin()
{
	// TODO: �ڴ���������������
	PushNumb=0;
	m_DrawCurrent=2;
}


void CGIS21_ͼ˵����View::OnUpdateSanjiaoxin(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetRadio(m_DrawCurrent==2);
}


void CGIS21_ͼ˵����View::OnWujiaoxin()
{
	// TODO: �ڴ���������������
	PushNumb=0;
	m_DrawCurrent=3;
}


void CGIS21_ͼ˵����View::OnUpdateWujiaoxin(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetRadio(m_DrawCurrent==3);
}


void CGIS21_ͼ˵����View::OnXinxin()
{
	// TODO: �ڴ���������������
	PushNumb=0;
	m_DrawCurrent=4;
}


void CGIS21_ͼ˵����View::OnUpdateXinxin(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetRadio(m_DrawCurrent==4);
}


void CGIS21_ͼ˵����View::OnDrawZhexian()
{
	// TODO: �ڴ���������������
	PushNumb=0;
	m_DrawCurrent=5;
}


void CGIS21_ͼ˵����View::OnUpdateDrawZhexian(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetRadio(m_DrawCurrent==5);
}


void CGIS21_ͼ˵����View::OnDrawDuobianxin()
{
	// TODO: �ڴ���������������
	PushNumb=0;
	m_DrawCurrent=6;
}


void CGIS21_ͼ˵����View::OnUpdateDrawDuobianxin(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetRadio(m_DrawCurrent==6);
}


void CGIS21_ͼ˵����View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CGIS21_ͼ˵����Doc* pDoc=GetDocument();
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


void CGIS21_ͼ˵����View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC ddd(this);
	ddd.SelectObject(&m_pen);
	ddd.SetROP2(R2_NOTXORPEN);  //ѡ�񻭱ʷ�ɫ�Ļ滭ģʽ
	if((m_DrawCurrent==5||m_DrawCurrent==6)&&PushNumb>=1)
	{
		if(mPointOld!=point)
		{
			ddd.MoveTo(mPointOrign);
			ddd.LineTo(mPointOld);  //����ԭ����ֱ��
			ddd.MoveTo(mPointOrign);
			ddd.LineTo(point);  //�ػ��ƶ������ֱ��
			mPointOld=point;
		}
	}

	CView::OnMouseMove(nFlags, point);
}


void CGIS21_ͼ˵����View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC ddd(this);
	int x1,y1;
	ddd.SelectObject(&m_pen);
	ddd.SetROP2(R2_NOTXORPEN);
	if((m_DrawCurrent==5||m_DrawCurrent==6))
	{
		CPoint *ppoint;
		ppoint=new CPoint[PushNumb];
		for(int i=0;i<PushNumb;i++)  //��ʵ������ת������Ļ�������꣬����ppoint
		{
			ppoint[i].x=PointXyz[i].x;
			ppoint[i].y=PointXyz[i].y;
		}
		ddd.Polyline(ppoint,PushNumb);
		ddd.MoveTo(mPointOrign);
		ddd.LineTo(mPointOld);
		PushNumb=0;
		ReleaseCapture();  //�ͷŲ�׽�����
	}
	CView::OnRButtonDown(nFlags, point);
}


void CGIS21_ͼ˵����View::OnTool()
{
	// TODO: �ڴ���������������
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
