#include "StdAfx.h"
#include "Draw.h"


CDraw::CDraw(void)
{
}


CDraw::~CDraw(void)
{
}


CDraw::CDraw(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short BrushType,short LineType,int id_only,BOOL Delete)//�������Ĺ��캯��
{
	m_ColorPen=ColorPen;
	m_ColorBrush=ColorBrush;
	m_LineWide=LineWide;
	m_BrushType=BrushType;
	b_Delete=Delete;
	m_id_only=id_only;

}

int CDraw::GetID()
{
	return m_id_only;
}