
// MFCHelloworld.h : MFCHelloworld Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCHelloworldApp:
// �йش����ʵ�֣������ MFCHelloworld.cpp
//

class CMFCHelloworldApp : public CWinApp
{
public:
	CMFCHelloworldApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCHelloworldApp theApp;
