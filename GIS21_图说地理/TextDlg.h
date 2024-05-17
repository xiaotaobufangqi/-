#pragma once
#include "afxcmn.h"


// CTextDlg 对话框

class CTextDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextDlg)

public:
	CTextDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTextDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	COLORREF pColor;
	afx_msg void OnEnChangeEdit1();
	virtual BOOL OnInitDialog();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit3();
	
	CString m_text;
	UINT m_high;
	
	UINT m_width;
	UINT m_angle;
	CSliderCtrl m_slider;
	int m_weight;
	afx_msg void OnBnClickedOk();
};
