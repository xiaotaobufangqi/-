// TextDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GIS21_ͼ˵����.h"
#include "TextDlg.h"
#include "afxdialogex.h"


// CTextDlg �Ի���

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


// CTextDlg ��Ϣ�������


void CTextDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL CTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_slider.SetRange(0,900,TRUE);
	m_slider.SetTicFreq(1);
	m_slider.SetLineSize(100);
	m_slider.SetPageSize(100);
	m_slider.SetPos(m_weight);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CTextDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(1);
	CDC *pDC=GetDC();
	int high,width;
	high=m_high;width=m_width;
	if(m_high>=30) high=30;
	if(m_width>=30) width=30;
	CFont cjcf;  //����һ����ģ
	cjcf.CreateFont(high,width,m_angle*10,0,m_weight,0,0,0,1,OUT_TT_PRECIS,CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,FIXED_PITCH,_T("GIS"));
	CFont* cjcbakf=pDC->SelectObject(&cjcf); //ѡ����ģ
	pDC->SetBkMode(TRANSPARENT);
	CRect rc(400,150,850,500);
	CBrush bkBrush(pDC->GetBkColor());
	pDC->FillRect(&rc,&bkBrush);
	pDC->SetTextColor(pColor); //�趨�ı���ɫ
	pDC->TextOut(650,300,m_text);
	*pResult = 0;
}


void CTextDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
