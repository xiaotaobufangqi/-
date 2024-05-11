#pragma once

#include "draw.h"


class CPLine :
	public CDraw
{
public:
	CPLine();
	~CPLine(void);
	CPLine(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,BOOL Delete,int Numble,PointStruct* PointList,BOOL Lb);
	void Draw(CDC *pDC,int Mode,int buff);
	DECLARE_SERIAL(CPLine);
	
protected:
	int m_Numble;//连续直线或多边形区域的顶点数
	BOOL m_lb;//连续直线或多边形
	PointStruct* m_PointList;//存储顶点的数组指针

public:
	virtual void Serialize(CArchive& ar);
	bool IsPoint(CDC* pDC,float px,float py);
	bool IsRect(CDC* pDC,CRect r);
};
