
// GIS21_ͼ˵����View.h : CGIS21_ͼ˵����View ��Ľӿ�
//

#pragma once


class CGIS21_ͼ˵����View : public CView
{
protected: // �������л�����
	CGIS21_ͼ˵����View();
	DECLARE_DYNCREATE(CGIS21_ͼ˵����View)

	int m_DrawCurrent;  //��ǰ�����в��������
	int PushNumb;  //��¼�������Ĵ���

	COLORREF m_pColor;  //���ñ�ɫ
	COLORREF m_brColor;  //��ˢɫ
	short m_LineWide;  //�����߿�
	short m_LineType;  //��������
	short m_BrushType;  //���������
	CPen m_pen;
	CBrush m_brush;
	CPoint mPointOrign,mPointOrignl,mPointOld;
	PointStruct *PointXyz;

// ����
public:
	CGIS21_ͼ˵����Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CGIS21_ͼ˵����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // GIS21_ͼ˵����View.cpp �еĵ��԰汾
inline CGIS21_ͼ˵����Doc* CGIS21_ͼ˵����View::GetDocument() const
   { return reinterpret_cast<CGIS21_ͼ˵����Doc*>(m_pDocument); }
#endif

