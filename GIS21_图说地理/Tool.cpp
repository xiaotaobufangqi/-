// Tool.cpp : 实现文件
//

#include "stdafx.h"
#include "GIS21_图说地理.h"
#include "Tool.h"
#include "afxdialogex.h"



// CTool 对话框

IMPLEMENT_DYNAMIC(CTool, CDialogEx)

CTool::CTool(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTool::IDD, pParent)
	, pent(0)
	, brusht(0)
	, kd(0)
{

}

CTool::~CTool()
{
}

void CTool::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ptype);
	DDX_LBIndex(pDX, IDC_LIST1, pent);
	DDX_Control(pDX, IDC_LIST2, btype);
	DDX_LBIndex(pDX, IDC_LIST2, brusht);
	DDX_Control(pDX, IDC_SLIDER1, slider);
	DDX_Slider(pDX, IDC_SLIDER1, kd);
}


BEGIN_MESSAGE_MAP(CTool, CDialogEx)
	ON_WM_PAINT()
	ON_LBN_SELCHANGE(IDC_LIST1, &CTool::OnLbnSelchangeList1)
	ON_LBN_SELCHANGE(IDC_LIST2, &CTool::OnLbnSelchangeList2)
	ON_BN_CLICKED(IDC_BUTTON2, &CTool::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CTool::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CTool::OnBnClickedOk)
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CTool 消息处理程序


BOOL CTool::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	ptype.AddString (_T("实线___________"));
	ptype.AddString (_T("虚线- - - - - -"));
	ptype.AddString (_T("点线······"));
	ptype.AddString (_T("点划线·-·-·-·"));
	ptype.AddString (_T("双点划线··-··-"));
	ptype.AddString (_T("空笔              "));
	btype.AddString (_T("水平   "));
	btype.AddString (_T("垂直   "));
	btype.AddString (_T("右斜   "));
	btype.AddString (_T("左斜   "));
	btype.AddString (_T("十字交叉   "));
	btype.AddString (_T("斜线交叉   "));
	btype.AddString(_T("空白   "));
	//btype.AddString (_T("爱心位图填充   "));
	slider.SetRange(1,20,TRUE);    slider.SetPos(kd);
	ptype.SetCurSel (pent);   btype.SetCurSel (brusht);
	UpdateData(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CTool::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	

	CBrush bkBrush(pColor);
	CRect rc(600,150,700,200);
	dc.FillRect(&rc,&bkBrush);
	CBrush bkBrush1(brusht,brColor);
	CRect rc1(600,250,700,300);
	dc.FillRect(&rc1,&bkBrush1);

}


void CTool::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码

	pent=(unsigned char)ptype.GetCurSel();
	if(pent!=0)
	{
		kd=1;
		slider.SetPos(kd);
	}
	UpdateData(0);
}


void CTool::OnLbnSelchangeList2()
{
	// TODO: 在此添加控件通知处理程序代码
	brusht=(unsigned char)btype.GetCurSel();
	CDC *pDC=GetDC();
	CBrush bkBrushl(brusht,brColor);
	CRect rcl(600,250,700,300);
	pDC->FillRect(&rcl,&bkBrushl);
	UpdateData(0);
	
}


void CTool::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog dd;
	if(dd.DoModal()==IDOK)
	{
	brColor=dd.GetColor();
	Invalidate();
	}
}


void CTool::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog dd;
	if(dd.DoModal()==IDOK)
	{
	pColor=dd.GetColor();
	Invalidate();
	}
}


void CTool::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL CTool::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*m_cursor=AfxGetApp()->LoadCursor(IDC_CURSOR1);
ASSERT(m_cursor !=NULL);
SetCursor(m_cursor);
return true;*/

	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}
