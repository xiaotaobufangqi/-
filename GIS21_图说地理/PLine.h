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
	int m_Numble;//����ֱ�߻���������Ķ�����
	BOOL m_lb;//����ֱ�߻�����
	PointStruct* m_PointList;//�洢���������ָ��

public:
	virtual void Serialize(CArchive& ar);
	bool IsPoint(CDC* pDC,float px,float py);
	bool IsRect(CDC* pDC,CRect r);
};
