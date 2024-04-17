#include "StdAfx.h"
#include "Draw.h"


CDraw::CDraw(void)
{
}


CDraw::~CDraw(void)
{
}


CDraw::CDraw(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,BOOL Delete)//带参数的构造函数
{
	m_ColorPen=ColorPen;
	m_ColorBrush=ColorBrush;
	m_LineWide=LineWide;
	m_LineType=LineType;
	m_BrushType=BrushType;
	b_Delete=Delete;
	m_id_only=id_only;

}

int CDraw::GetID()
{
	return m_id_only;
}