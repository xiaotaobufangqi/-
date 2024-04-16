#pragma once
#include "afx.h"
typedef struct
{
	float x;//����ĺ�����
	float y;//�����������
	float z;
}PointStruct;//�洢ÿ����������Ľṹ

class CDraw :
	public CObject
{
public:
	CDraw(void);
	~CDraw(void);
	CDraw(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,BOOL Delete);
	int GetID();
protected:
	COLORREF m_ColorPen;//��ɫ
	COLORREF m_ColorBrush;//���ˢ��ɫ
	short m_LineWide;//�߿����أ�
	short m_BrushType;//�����
	short m_LineType;//����
	int m_id_only;//ͼ��Ԫ��Ψһ��ʶ���
	BOOL b_Delete;//�Ƿ���ɾ��״̬
	short m_layer;//����ͼ��

};

