
// GIS21_ͼ˵����.h : GIS21_ͼ˵���� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CGIS21_ͼ˵����App:
// �йش����ʵ�֣������ GIS21_ͼ˵����.cpp
//

class CGIS21_ͼ˵����App : public CWinAppEx
{
public:
	CGIS21_ͼ˵����App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGIS21_ͼ˵����App theApp;
