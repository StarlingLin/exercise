#define _CRT_SECURE_NO_WARNINGS

#include "mfc.h"

MyApp app;

BOOL MyApp::InitInstance()
{
	//��������
	MyFrame *pFrame = new MyFrame();
	//��ʾ����
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	//����Ϊ������
	m_pMainWnd = pFrame;
	return TRUE;
}

MyFrame::MyFrame()
{
	Create(NULL, _T("MFC Window"));
}