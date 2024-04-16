#include "StdAfx.h"
#include "Text.h"


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


CText::~CText(void)
{
}
