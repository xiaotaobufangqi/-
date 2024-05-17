
// GIS21_ͼ˵����Doc.cpp : CGIS21_ͼ˵����Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "GIS21_ͼ˵����.h"
#endif

#include "GIS21_ͼ˵����Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGIS21_ͼ˵����Doc

IMPLEMENT_DYNCREATE(CGIS21_ͼ˵����Doc, CDocument)

BEGIN_MESSAGE_MAP(CGIS21_ͼ˵����Doc, CDocument)
END_MESSAGE_MAP()


// CGIS21_ͼ˵����Doc ����/����

CGIS21_ͼ˵����Doc::CGIS21_ͼ˵����Doc()
{
	// TODO: �ڴ����һ���Թ������
	m_Index=new int[20000];
	GraphSelect=new GraphSelectStruct[2000];
	n_GraphSelect=0;
}

CGIS21_ͼ˵����Doc::~CGIS21_ͼ˵����Doc()
{
	delete m_Index;
	delete GraphSelect;
}

BOOL CGIS21_ͼ˵����Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CGIS21_ͼ˵����Doc ���л�

void CGIS21_ͼ˵����Doc::Serialize(CArchive& ar)
{
	m_PLineArray.Serialize(ar);
	m_PointArray.Serialize(ar);
	m_TextArray.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CGIS21_ͼ˵����Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CGIS21_ͼ˵����Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CGIS21_ͼ˵����Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CGIS21_ͼ˵����Doc ���

#ifdef _DEBUG
void CGIS21_ͼ˵����Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGIS21_ͼ˵����Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGIS21_ͼ˵����Doc ����
CText* CGIS21_ͼ˵����Doc::AddText(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,float StartX,float StartY,float Angle,float TextHeight,float TextWide,float FontWeight,CString Text)
{
	CText* p_Text=new CText(ColorPen,ColorBrush,LineWide,LineType,BrushType,id_only,0,StartX,StartY,Angle,TextHeight,TextWide,FontWeight,Text);
	m_TextArray.Add(p_Text);
	return p_Text;
}

CPLine* CGIS21_ͼ˵����Doc::AddPLine(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,int Numble,PointStruct* PointList,BOOL Lb)
{
	CPLine* p_Pline=new CPLine(ColorPen,ColorBrush,LineWide,LineType,BrushType,id_only,0,Numble,PointList,Lb);
	m_PLineArray.Add(p_Pline);
	return p_Pline;
}

Cpoint* CGIS21_ͼ˵����Doc::AddPoint(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,float CircleX,float CircleY,float CircleR,short Lb)
{
	Cpoint* p_Point=new Cpoint(ColorPen,ColorBrush,LineWide,LineType,BrushType,id_only,0,CircleX,CircleY,CircleR,Lb);
	m_PointArray.Add(p_Point);
	return p_Point;
}

CDraw* CGIS21_ͼ˵����Doc::GetGraph(short Lb,int Index)
{
	switch(Lb)
	{
	case 1:
		if(Index<0||Index>m_PointArray.GetUpperBound())   return 0;
		return m_PointArray.GetAt(Index);
		break;
	case 2:
		if(Index<0||Index>m_PLineArray.GetUpperBound())   return 0;
		return m_PLineArray.GetAt(Index);
		break;
	case 3:
		if(Index<0||Index>m_TextArray.GetUpperBound())   return 0;
		return m_TextArray.GetAt(Index);
		break;
	default:
		return 0;
	}
}

int CGIS21_ͼ˵����Doc::GetGraphUpperBound(short Lb)
{
	switch(Lb)
	{
	case 1:
		return m_PointArray.GetUpperBound();
		break;
	case 2:
		return m_PLineArray.GetUpperBound();
		break;
	case 3:
		return m_TextArray.GetUpperBound();
		break;
	default:
		return -1;
	}
}

int CGIS21_ͼ˵����Doc::GetGraphNumb(short Lb)
{
	switch(Lb)
	{
	case 1:
		return m_PointArray.GetSize();
		break;
	case 2:
		return m_PLineArray.GetSize();
		break;
	case 3:
		return m_TextArray.GetSize();
		break;
	default:
		return 0;
	}
}

int CGIS21_ͼ˵����Doc::GetGraphID(short Lb)
{
	int nn=GetGraphUpperBound(Lb);
	for(int i=0;i<20000;i++)
	{
		m_Index[i]=0;
	}
	for(int i=0;i<=nn;i++)
	{
		if(GetGraph(Lb,i))
		{
			m_Index[GetGraph(Lb,i)->GetID()]=1;
		}
	}
	for(int i=0;i<20000;i++)
	{
		if(m_Index[i]==0)
			return i;
	}
	return -1;
}

void CGIS21_ͼ˵����Doc::clea()
{
	m_PointArray.RemoveAll();
	m_PLineArray.RemoveAll();
	m_TextArray.RemoveAll();
	//m_ArcArray.RemoveAll();
}

void CGIS21_ͼ˵����Doc::DeleteGraph(short Lb,int Index)
{
	switch(Lb)
	{
	case 1:
		if(Index<0||Index>m_PointArray.GetUpperBound())
			return ;
		m_PointArray.RemoveAt(Index);
		break;
	case 2:
		if(Index<0||Index>m_PLineArray.GetUpperBound())
			return ;
		m_PLineArray.RemoveAt(Index);
		break;
	case 3:
		if(Index<0||Index>m_TextArray.GetUpperBound())
			return ;
		m_TextArray.RemoveAt(Index);
		break;
	default:
		return ;
	}
}

void CGIS21_ͼ˵����Doc::Draw(CDC *pDC,int m_DrawMode)
{
	for(int i=1;i<=3;i++)
	{
		int nn=GetGraphUpperBound(i);
		for(int j=0;j<=nn;j++)
		{
			GetGraph(i,j)->Draw(pDC,m_DrawMode,0);
		}
	}
	//�ػ�ѡ���ͼ��
	for(int i=0;i<n_GraphSelect;i++)
	{
		GetGraph(GraphSelect[i].Lb,GraphSelect[i].Index)->Draw(pDC,1,0); //ѡ����ʾ

		if(GraphSelect[i].buff!=0)
		{
			int x=(GraphSelect[i].buff);
			GetGraph(GraphSelect[i].Lb,GraphSelect[i].Index)->Draw(pDC,2,x); //��������ʾ
		}
	}
}

BOOL CGIS21_ͼ˵����Doc::AddSelectList(int Lb,int Index)
{
	for(int i=0;i<n_GraphSelect;i++)
	{
		if(Lb==GraphSelect[i].Lb&&Index==GraphSelect[i].Index)
			return FALSE;
	}
	GraphSelect[n_GraphSelect].Lb=Lb;
	GraphSelect[n_GraphSelect].buff=0;
	GraphSelect[n_GraphSelect++].Index=Index;
	return TRUE;
}

void CGIS21_ͼ˵����Doc::OnPack()
{
	for(int i=0;i<=3;i++)
	{
		int nn=GetGraphUpperBound(i);
		for(int j=0;j<=nn;j++)
		{
			if(GetGraph(i,j))
				if(GetGraph(i,j)->IsDelete()) 
					DeleteGraph(i,j);
		}
	}
	n_GraphSelect=0;
	SetModifiedFlag(1);
	UpdateAllViews(NULL);
}