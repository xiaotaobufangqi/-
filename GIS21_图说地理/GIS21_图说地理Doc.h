
// GIS21_图说地理Doc.h : CGIS21_图说地理Doc 类的接口
//

#include <AfxTempl.h>

#pragma once
#include"Draw.h"
#include"Cpoint.h"
#include"PLine.h"
#include"Text.h"


class CGIS21_图说地理Doc : public CDocument
{
protected: // 仅从序列化创建
	CGIS21_图说地理Doc();
	DECLARE_DYNCREATE(CGIS21_图说地理Doc)

	CTypedPtrArray<CObArray,Cpoint*>m_PointArray; //管理点对象的指针数组
	CTypedPtrArray<CObArray,CPLine*>m_PLineArray;  //管理折线和多边形对象的指针数组
	CTypedPtrArray<CObArray,CText*>m_TextArray;  //管理标注文字对象的指针数组

	CPLine* AddPLine(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,int Numble,PointStruct* PointList,BOOL Lb);
	CText* AddText(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,float StartX,float StartY,float Angle,float TextHeight,float TextWide,float FontWeight,CString Text);
    Cpoint* AddPoint(COLORREF ColorPen,COLORREF ColorBrush,short LineWide,short LineType,short BrushType,int id_only,float CircleX,float CircleY,float CircleR,short Lb);

	CDraw* GetGraph(short Lb,int Index);  //得到指向图形元素的指针
	int GetGraphUpperBound(short Lb);  //得到图形元素的最大下标
	int GetGraphNumb(short Lb);  //得到图形元素的数量
	int GetGraphID(short Lb);  //获得ID算法
	int* m_Index;
	void clea();  //清空图形元素
	void DeleteGraph(short Lb,int Index);

	void Draw(CDC *pDC,int m_DrawMode);

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CGIS21_图说地理Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()


protected:


#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
