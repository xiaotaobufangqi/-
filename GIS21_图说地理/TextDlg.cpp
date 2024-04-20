// TextDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GIS21_图说地理.h"
#include "TextDlg.h"
#include "afxdialogex.h"


// CTextDlg 对话框

IMPLEMENT_DYNAMIC(CTextDlg, CDialogEx)

CTextDlg::CTextDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTextDlg::IDD, pParent)
	, m_text(_T(""))
	, m_high(0)
	, m_width(0)
	, m_angle(0)
	, m_weight(0)
{

}

CTextDlg::~CTextDlg()
{
}

void CTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT3, m_width);
	//DDX_Control(pDX, IDC_SLIDER1, m_slider);
	//DDX_Control(pDX, IDC_EDIT1, m_text);
	//DDX_Control(pDX, IDC_EDIT2, m_high);
	//DDX_Control(pDX, IDC_EDIT3, m_width);
	//DDX_Control(pDX, IDC_EDIT4, m_angle);
	DDX_Text(pDX, IDC_EDIT1, m_text);
	DDX_Text(pDX, IDC_EDIT2, m_high);
	//DDX_Text(pDX, IDC_EDIT3, m_width);
	//DDX_Text(pDX, IDC_EDIT4, m_angle);
	DDX_Text(pDX, IDC_EDIT3, m_width);
	DDX_Text(pDX, IDC_EDIT4, m_angle);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Slider(pDX, IDC_SLIDER1, m_weight);
}


BEGIN_MESSAGE_MAP(CTextDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CTextDlg::OnEnChangeEdit1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CTextDlg::OnNMCustomdrawSlider1)
	ON_EN_CHANGE(IDC_EDIT3, &CTextDlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CTextDlg 消息处理程序


void CTextDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL CTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_slider.SetRange(0,900,TRUE);
	m_slider.SetTicFreq(1);
	m_slider.SetLineSize(100);
	m_slider.SetPageSize(100);
	m_slider.SetPos(m_weight);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CTextDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	CDC *pDC=GetDC();
	int high,width;
	high=m_high;width=m_width;
	if(m_high>=30) high=30;
	if(m_width>=30) width=30;
	CFont cjcf;  //定义一个字模
	cjcf.CreateFont(high,width,m_angle*10,0,m_weight,0,0,0,1,OUT_TT_PRECIS,CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,FIXED_PITCH,_T("GIS"));
	CFont* cjcbakf=pDC->SelectObject(&cjcf); //选中字模
	pDC->SetBkMode(TRANSPARENT);
	CRect rc(400,150,850,500);
	CBrush bkBrush(pDC->GetBkColor());
	pDC->FillRect(&rc,&bkBrush);
	pDC->SetTextColor(pColor); //设定文本颜色
	pDC->TextOut(650,300,m_text);
	*pResult = 0;
}


void CTextDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
