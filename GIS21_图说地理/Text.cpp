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
	if(b_Delete) return; //����Ѿ�����ɾ��״̬
	pDC->SetROP2(R2_COPYPEN); //�趨���ǵĻ���ģʽ
	pDC->SetBkMode(TRANSPARENT);
	CFont cjcf;  //����һ����ģ
	int high,wide,cc1,cc2,angg;
	float x1,y1,angl;
	angl=(float)(m_Angle*3.14/180);
	angg=(int)(m_Angle*10);
	high=m_TextHeight; //�õ�����ĵ���߶�
	x1=m_StartX-m_TextHeight*(float)sin(angl);
	y1=m_StartY-m_TextHeight*(float)cos(angl);
	wide=m_TextWide;
	cc1=x1;
	cc2=y1;
	cjcf.CreateFont(high,wide,angg,0,m_FontWeight,0,0,0,1,OUT_TT_PRECIS,CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,FIXED_PITCH,_T("cjc"));
	CFont* cjcbakf=pDC->SelectObject(&cjcf);
	pDC->SetTextColor(m_ColorPen); //�趨�ı���ɫ
	pDC->TextOut(cc1,cc2,m_Text); //����Ļ��д�ַ�//�ı��ַ�
	pDC->SetBkMode(OPAQUE);
	pDC->SelectObject(cjcbakf); //�ָ���ģ
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
