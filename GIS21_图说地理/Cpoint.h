#pragma once
#include "draw.h"
#include<afxtempl.h>
class Cpoint :
	public CDraw
{
public:
	Cpoint(void);
	~Cpoint(void);
	Cpoint(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short BrushType,short LineType,int id_only,BOOL Delete,float CircleX,float CircleY,float CircleR,short Lb);
	void Draw(CDC *pDC,int Mode,int buff);
	DECLARE_SERIAL(Cpoint);
protected:
	float m_CircleX,m_CircleY;//Բ�İ뾶
	float m_CircleR;//�뾶
	short m_Lb;//���
public:
	virtual void Serialize(CArchive& ar);
};

