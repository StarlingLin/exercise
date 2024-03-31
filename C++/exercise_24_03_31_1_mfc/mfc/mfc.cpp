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

BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_WM_PAINT()
END_MESSAGE_MAP()

MyFrame::MyFrame()
{
	Create(NULL, _T("MFC Window"));
}

void MyFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	CString str;
	str.Format(_T("x=%d,y=%d"), point.x, point.y);
	MessageBox(str, TEXT("Point"));
}

void MyFrame::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString str;
	str.Format(_T("Char=%c"), nChar);
	MessageBox(str, TEXT("Char"));
}

void MyFrame::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	dc.TextOutW(10, 10, _T("Hello, MFC!"));
	dc.Ellipse(rect);
}