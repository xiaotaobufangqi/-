// Mess.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GIS21_ͼ˵����.h"
#include "Mess.h"
#include "afxdialogex.h"


// CMess �Ի���

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


// CMess ��Ϣ�������


void CMess::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
