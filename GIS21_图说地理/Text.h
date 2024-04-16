#pragma once
#include "draw.h"
class CText :
	public CDraw
{
public:
	CText(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,BOOL Delete,float StartX,float StartY,float Angle,float TextHeight,float TextWide,float FontWeight,CString Text);
	
	~CText(void);
protected:
	float m_StartX;//文本起点横坐标
	float m_StartY;//文本起点纵坐标
	float m_Angle;//标注角度
	float m_TextHeight;//字体高度
	float m_TextWide;//字体宽度
	float m_FontWeight;//粗细程度
	CString m_Text;//标注的文本信息
	WORD m_TextLong;//标注的信息长度，不用传参，通过Text.GetLength()计算
};

