#pragma once
#include "draw.h"
class CText :
	public CDraw
{
public:
	CText(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,BOOL Delete,float StartX,float StartY,float Angle,float TextHeight,float TextWide,float FontWeight,CString Text);
	
	~CText(void);
protected:
	float m_StartX;//�ı���������
	float m_StartY;//�ı����������
	float m_Angle;//��ע�Ƕ�
	float m_TextHeight;//����߶�
	float m_TextWide;//������
	float m_FontWeight;//��ϸ�̶�
	CString m_Text;//��ע���ı���Ϣ
	WORD m_TextLong;//��ע����Ϣ���ȣ����ô��Σ�ͨ��Text.GetLength()����
};

