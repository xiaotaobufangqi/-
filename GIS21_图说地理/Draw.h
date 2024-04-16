#pragma once
#include "afx.h"
typedef struct
{
	float x;//顶点的横坐标
	float y;//顶点的纵坐标
	float z;
}PointStruct;//存储每个顶点坐标的结构

class CDraw :
	public CObject
{
public:
	CDraw(void);
	~CDraw(void);
	CDraw(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,BOOL Delete);
	int GetID();
protected:
	COLORREF m_ColorPen;//笔色
	COLORREF m_ColorBrush;//填充刷颜色
	short m_LineWide;//线宽（像素）
	short m_BrushType;//填充型
	short m_LineType;//线型
	int m_id_only;//图形元素唯一的识别号
	BOOL b_Delete;//是否处于删除状态
	short m_layer;//所处图层

};

