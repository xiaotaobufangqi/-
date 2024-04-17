
// GIS21_ͼ˵����Doc.h : CGIS21_ͼ˵����Doc ��Ľӿ�
//

#include <AfxTempl.h>

#pragma once
#include"Draw.h"
#include"Cpoint.h"
#include"PLine.h"
#include"Text.h"


class CGIS21_ͼ˵����Doc : public CDocument
{
protected: // �������л�����
	CGIS21_ͼ˵����Doc();
	DECLARE_DYNCREATE(CGIS21_ͼ˵����Doc)

	CTypedPtrArray<CObArray,Cpoint*>m_PointArray; //���������ָ������
	CTypedPtrArray<CObArray,CPLine*>m_PLineArray;  //�������ߺͶ���ζ����ָ������
	CTypedPtrArray<CObArray,CText*>m_TextArray;  //�����ע���ֶ����ָ������

	CPLine* AddPLine(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,int Numble,PointStruct* PointList,BOOL Lb);
	CText* AddText(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,float StartX,float StartY,float Angle,float TextHeight,float TextWide,float FontWeight,CString Text);
    Cpoint* AddPoint(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,float CircleX,float CircleY,float CircleR,short Lb);

	CDraw* GetGraph(short Lb,int Index);  //�õ�ָ��ͼ��Ԫ�ص�ָ��
	int GetGraphUpperBound(short Lb);  //�õ�ͼ��Ԫ�ص�����±�
	int GetGraphNumb(short Lb);  //�õ�ͼ��Ԫ�ص�����
	int GetGraphID(short Lb);  //���ID�㷨
	int* m_Index;
	void clea();  //���ͼ��Ԫ��
	void DeleteGraph(short Lb,int Index);

	void Draw(CDC *pDC,int m_DrawMode);

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CGIS21_ͼ˵����Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()


protected:


#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
