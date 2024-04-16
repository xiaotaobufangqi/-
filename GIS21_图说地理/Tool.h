#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CTool �Ի���

class CTool : public CDialogEx
{
	DECLARE_DYNAMIC(CTool)

public:
	CTool(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTool();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
