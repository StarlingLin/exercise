#pragma once

#include <afxwin.h>

class MyApp :public CWinApp
{
public:
	//³ÌÐòÈë¿Ú
	virtual BOOL InitInstance();

};

class MyFrame :public CFrameWnd
{
public:
	MyFrame();
};