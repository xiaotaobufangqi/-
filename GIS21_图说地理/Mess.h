#pragma once


// CMess �Ի���

class CMess : public CDialogEx
{
	DECLARE_DYNAMIC(CMess)

public:
	CMess(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMess();


// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	short bufflong;
};
