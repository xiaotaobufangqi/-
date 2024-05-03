
// GIS21_图说地理View.h : CGIS21_图说地理View 类的接口
//

#pragma once


class CGIS21_图说地理View : public CView
{
protected: // 仅从序列化创建
	CGIS21_图说地理View();
	DECLARE_DYNCREATE(CGIS21_图说地理View)

	int m_DrawCurrent;  //当前正进行操作的序号
	int PushNumb;  //记录按下鼠标的次数

	COLORREF m_pColor;  //设置笔色
	COLORREF m_brColor;  //画刷色
	short m_LineWide;  //设置线宽
	short m_LineType;  //设置线型
	short m_BrushType;  //设置填充型
	CPen m_pen;
	CBrush m_brush;
	CPoint mPointOrign,mPointOrignl,mPointOld;
	PointStruct *PointXyz;

// 特性
public:
	CGIS21_图说地理Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CGIS21_图说地理View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnYuan();
	afx_msg void OnUpdateYuan(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSanjiaoxin();
	afx_msg void OnUpdateSanjiaoxin(CCmdUI *pCmdUI);
	afx_msg void OnWujiaoxin();
	afx_msg void OnUpdateWujiaoxin(CCmdUI *pCmdUI);
	afx_msg void OnXinxin();
	afx_msg void OnUpdateXinxin(CCmdUI *pCmdUI);
	afx_msg void OnDrawZhexian();
	afx_msg void OnUpdateDrawZhexian(CCmdUI *pCmdUI);
	afx_msg void OnDrawDuobianxin();
	afx_msg void OnUpdateDrawDuobianxin(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTool();
	afx_msg void OnDrawText();
	afx_msg void OnUpdateDrawText(CCmdUI *pCmdUI);
	afx_msg void OnJiazaiditu();
};

#ifndef _DEBUG  // GIS21_图说地理View.cpp 中的调试版本
inline CGIS21_图说地理Doc* CGIS21_图说地理View::GetDocument() const
   { return reinterpret_cast<CGIS21_图说地理Doc*>(m_pDocument); }
#endif

