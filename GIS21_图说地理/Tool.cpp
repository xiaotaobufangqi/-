// Tool.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GIS21_ͼ˵����.h"
#include "Tool.h"
#include "afxdialogex.h"



// CTool �Ի���

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


// CTool ��Ϣ�������


BOOL CTool::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	ptype.AddString (_T("ʵ��___________"));
	ptype.AddString (_T("����- - - - - -"));
	ptype.AddString (_T("���ߡ�����������"));
	ptype.AddString (_T("�㻮�ߡ�-��-��-��"));
	ptype.AddString (_T("˫�㻮�ߡ���-����-"));
	ptype.AddString (_T("�ձ�              "));
	btype.AddString (_T("ˮƽ   "));
	btype.AddString (_T("��ֱ   "));
	btype.AddString (_T("��б   "));
	btype.AddString (_T("��б   "));
	btype.AddString (_T("ʮ�ֽ���   "));
	btype.AddString (_T("б�߽���   "));
	btype.AddString(_T("�հ�   "));
	//btype.AddString (_T("����λͼ���   "));
	slider.SetRange(1,20,TRUE);    slider.SetPos(kd);
	ptype.SetCurSel (pent);   btype.SetCurSel (brusht);
	UpdateData(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CTool::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	

	CBrush bkBrush(pColor);
	CRect rc(600,150,700,200);
	dc.FillRect(&rc,&bkBrush);
	CBrush bkBrush1(brusht,brColor);
	CRect rc1(600,250,700,300);
	dc.FillRect(&rc1,&bkBrush1);

}


void CTool::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	brusht=(unsigned char)btype.GetCurSel();
	CDC *pDC=GetDC();
	CBrush bkBrushl(brusht,brColor);
	CRect rcl(600,250,700,300);
	pDC->FillRect(&rcl,&bkBrushl);
	UpdateData(0);
	
}


void CTool::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CColorDialog dd;
	if(dd.DoModal()==IDOK)
	{
	brColor=dd.GetColor();
	Invalidate();
	}
}


void CTool::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CColorDialog dd;
	if(dd.DoModal()==IDOK)
	{
	pColor=dd.GetColor();
	Invalidate();
	}
}


void CTool::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


BOOL CTool::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*m_cursor=AfxGetApp()->LoadCursor(IDC_CURSOR1);
ASSERT(m_cursor !=NULL);
SetCursor(m_cursor);
return true;*/

	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}
