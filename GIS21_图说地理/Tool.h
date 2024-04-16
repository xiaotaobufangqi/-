#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CTool 对话框

class CTool : public CDialogEx
{
	DECLARE_DYNAMIC(CTool)

public:
	CTool(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTool();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	COLORREF pColor;
	COLORREF brColor;
	CListBox ptype;
	int pent;
	CListBox btype;
	int brusht;
	CSliderCtrl slider;
	int kd;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnLbnSelchangeList2();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	HCURSOR m_cursor;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};
