
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
#include "TextDlg.h"
#include "Mess.h"

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
	ON_COMMAND(ID_draw_text, &CGIS21_ͼ˵����View::OnDrawText)
	ON_UPDATE_COMMAND_UI(ID_draw_text, &CGIS21_ͼ˵����View::OnUpdateDrawText)
	ON_COMMAND(ID_jiazaiditu, &CGIS21_ͼ˵����View::OnJiazaiditu)
	ON_COMMAND(ID_dianxuan, &CGIS21_ͼ˵����View::OnDianxuan)
	ON_UPDATE_COMMAND_UI(ID_dianxuan, &CGIS21_ͼ˵����View::OnUpdateDianxuan)
	ON_COMMAND(ID_kuangxuan, &CGIS21_ͼ˵����View::OnKuangxuan)
	ON_UPDATE_COMMAND_UI(ID_kuangxuan, &CGIS21_ͼ˵����View::OnUpdateKuangxuan)
	ON_COMMAND(ID_fial_select, &CGIS21_ͼ˵����View::OnFialSelect)
	ON_COMMAND(ID_SeleDele, &CGIS21_ͼ˵����View::OnSeledele)
	ON_COMMAND(ID_quxiaodelete, &CGIS21_ͼ˵����View::OnQuxiaodelete)
	ON_COMMAND(ID_SelePack, &CGIS21_ͼ˵����View::OnSelepack)
	ON_COMMAND(ID_Buffer, &CGIS21_ͼ˵����View::OnBuffer)
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
			pDoc->AddPoint(m_pColor,m_brColor,m_LineWide,m_LineType,m_BrushType,id_only,xx,yy,5,m_DrawCurrent)->Draw(&ht,0,0);
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
	else if(m_DrawCurrent==7)
	{
		float m_FontHeight,m_FontWide,m_TextAngle,m_FontWeight;
		float m_TextX,m_TextY;
		CString m_TextString; //�洢��ע������
		int TextLong;
		CTextDlg dd;
		dd.pColor=m_pColor;
		if(dd.DoModal()==IDOK)
		{
			m_TextString=dd.m_text;
			m_TextAngle=dd.m_angle;
			m_FontHeight=dd.m_high;
			m_FontWide=dd.m_width;
			m_FontWeight=dd.m_weight;
			TextLong=dd.m_text.GetLength(); //��ע���ֵĳ���
			if(TextLong>0)
			{
				m_TextX=point.x,m_TextY=point.y;
				id_only=pDoc->GetGraphID(3);
				pDoc->AddText(m_pColor,m_brColor,m_LineWide,m_LineType,m_BrushType,id_only,m_TextX,m_TextY,m_TextAngle,m_FontHeight,m_FontWide,m_FontWeight,m_TextString)->Draw(&ht,0,0);
			}
		}
	}
	else if(m_DrawCurrent==81)  //��������ѡͼ�β���
	{
		if(pDoc->n_GraphSelect==2000) 
		{
			AfxMessageBox(_T("���ֻ��ѡ��2000��ͼ��Ԫ��"));
			return;
		}

		for(int i=1;i<=3;i++)
		{
			int nn=pDoc->GetGraphUpperBound(i);
			for(int j=0;j<=nn;j++)
			{
				BOOL pb=pDoc->GetGraph(i,j)->IsPoint(&ht,point.x,point.y);
				if(pb) //���ѡ����ͼ��Ԫ�أ���¼��ѡ�ж�ͼ��Ԫ�أ�������ʾ��ͼ��Ԫ��
				{
					BOOL pb1=pDoc->AddSelectList(i,j);
					if(pb1)
						pDoc->GetGraph(i,j)->Draw(&ht,1,0);
				}
			}
		}
	}
	else if(m_DrawCurrent==82)  //�����������ѡ��ͼ�β���
	{
		int xx1,yy1,xx2,yy2;
		if(pDoc->n_GraphSelect==2000) 
		{
			AfxMessageBox(_T("���ֻ��ѡ��2000��ͼ��Ԫ��"));
			return;
		}
		CRectTracker tracker;
		tracker.TrackRubberBand(this,point);
		xx1=min(tracker.m_rect.left,tracker.m_rect.right);
		yy1=min(tracker.m_rect.top,tracker.m_rect.bottom);
		xx2=max(tracker.m_rect.right,tracker.m_rect.left);
		yy2=max(tracker.m_rect.bottom,tracker.m_rect.top);
		CRect rr(xx1,yy1,xx2,yy2);
		for(int i=1;i<=3;i++)
		{
			int nn=pDoc->GetGraphUpperBound(i);
			for(int j=0;j<=nn;j++)
			{
				BOOL pb=pDoc->GetGraph(i,j)->IsRect(&ht,rr);
				if(pb) //���ѡ����ͼ��Ԫ�أ���¼��ѡ�ж�ͼ��Ԫ�أ�������ʾ��ͼ��Ԫ��
				{
					BOOL pb1=pDoc->AddSelectList(i,j);
					if(pb1)
						pDoc->GetGraph(i,j)->Draw(&ht,1,0);
				}
			}
		}
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


void CGIS21_ͼ˵����View::OnDrawText()
{
	// TODO: �ڴ���������������
	PushNumb=0; 
	m_DrawCurrent=7;
}


void CGIS21_ͼ˵����View::OnUpdateDrawText(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetRadio(m_DrawCurrent==7); 
}


void CGIS21_ͼ˵����View::OnJiazaiditu()
{
	// TODO: �ڴ���������������
	m_DrawCurrent=0;
	CClientDC ddd(this);
	CImage m_image;
	CFileDialog dlg(TRUE); 
if(dlg.DoModal()==IDOK)
    {  CString  name=dlg.GetPathName();
	m_image.Load(name);
	if ( m_image.IsNull()){	MessageBox(_T("û���سɹ�")); return ;} 
if ( m_image.GetBPP() == 32) 
{	int i, j;
	for (i = 0; i <  m_image.GetWidth(); i++)
	{	for (j = 0; j <  m_image.GetHeight(); j++)
		{	byte *pByte = (byte *) m_image.GetPixelAddress(i, j);
			pByte[0] = pByte[0] * pByte[3] / 255;
			pByte[1] = pByte[1] * pByte[3] / 255;
			pByte[2] = pByte[2] * pByte[3] / 255;
		}
	}
}
 m_image.Draw(ddd.m_hDC, 0, 0); 
 m_image.Destroy();
}

}


void CGIS21_ͼ˵����View::OnDianxuan()
{
	// TODO: �ڴ���������������;
	m_DrawCurrent=81;
	PushNumb=0;
}


void CGIS21_ͼ˵����View::OnUpdateDianxuan(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_DrawCurrent==81);
}


void CGIS21_ͼ˵����View::OnKuangxuan()
{
	// TODO: �ڴ���������������
	m_DrawCurrent=82;
	PushNumb=0;
}


void CGIS21_ͼ˵����View::OnUpdateKuangxuan(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_DrawCurrent==82);
}


void CGIS21_ͼ˵����View::OnFialSelect()
{
	// TODO: �ڴ���������������
	m_DrawCurrent=83;
	PushNumb=0;
	CGIS21_ͼ˵����Doc* pDoc=GetDocument();
	pDoc->n_GraphSelect--;
	Invalidate();
}


void CGIS21_ͼ˵����View::OnSeledele()
{
	// TODO: �ڴ���������������
	m_DrawCurrent=84;
	PushNumb=0;
	CGIS21_ͼ˵����Doc* pDoc=GetDocument();
	CClientDC ht(this);
	CDraw* pDraw;
	for(int i=0;i<pDoc->n_GraphSelect;++i) //ɾ��ѡ�е�ͼ��
	{
		pDraw=pDoc->GetGraph(pDoc->GraphSelect[i].Lb,pDoc->GraphSelect[i].Index);
		pDraw->Delete(1);
		Invalidate();
	}
}


void CGIS21_ͼ˵����View::OnQuxiaodelete()
{
	// TODO: �ڴ���������������
	m_DrawCurrent=85;
	PushNumb=0;
	CGIS21_ͼ˵����Doc* pDoc=GetDocument();
	CClientDC ht(this);
	CDraw* pDraw;
	for(int i=0;i<pDoc->n_GraphSelect;++i) //ɾ��ѡ�е�ͼ��
	{
		pDraw=pDoc->GetGraph(pDoc->GraphSelect[i].Lb,pDoc->GraphSelect[i].Index);
		pDraw->Delete(0);
		Invalidate();
	}
}


void CGIS21_ͼ˵����View::OnSelepack()
{
	// TODO: �ڴ���������������
	m_DrawCurrent=86;
	PushNumb=0;
	CGIS21_ͼ˵����Doc* pDoc=GetDocument();
	pDoc->OnPack();
	pDoc->n_GraphSelect=0;
	Invalidate();
}


void CGIS21_ͼ˵����View::OnBuffer()
{
	// TODO: �ڴ���������������
	MessageBox(_T("��ע�⣬��ǰ�Ƕ������ѡ�е�ͼ������������"));
	CGIS21_ͼ˵����Doc* pDoc=GetDocument();
	if(pDoc->n_GraphSelect==0||pDoc->GraphSelect[pDoc->n_GraphSelect-1].Lb==3)
	{
		MessageBox(_T("��ѡ��һ��ͼ��!"));
		return;
	}
	CMess dlg;
	if(dlg.DoModal()==IDOK)
		pDoc->GraphSelect[pDoc->n_GraphSelect-1].buff=dlg.bufflong;
	int x=(dlg.bufflong);
	CClientDC ddd(this);
	pDoc->GetGraph(pDoc->GraphSelect[pDoc->n_GraphSelect-1].Lb,pDoc->GraphSelect[pDoc->n_GraphSelect-1].Index)->Draw(&ddd,2,x);
}
