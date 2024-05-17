// Mess.cpp : 实现文件
//

#include "stdafx.h"
#include "GIS21_图说地理.h"
#include "Mess.h"
#include "afxdialogex.h"


// CMess 对话框

IMPLEMENT_DYNAMIC(CMess, CDialogEx)

CMess::CMess(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMess::IDD, pParent)
	, bufflong(0)
{

}

CMess::~CMess()
{
}

void CMess::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, bufflong);
}


BEGIN_MESSAGE_MAP(CMess, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CMess::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CMess 消息处理程序


void CMess::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
