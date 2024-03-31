#define _CRT_SECURE_NO_WARNINGS

#include "mfc.h"

MyApp app;

BOOL MyApp::InitInstance()
{
	//创建窗口
	MyFrame *pFrame = new MyFrame();
	//显示窗口
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	//设置为主窗口
	m_pMainWnd = pFrame;
	return TRUE;
}

MyFrame::MyFrame()
{
	Create(NULL, _T("MFC Window"));
}