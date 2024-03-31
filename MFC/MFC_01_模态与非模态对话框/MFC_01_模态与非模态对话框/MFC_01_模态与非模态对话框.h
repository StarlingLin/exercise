
// MFC_01_模态与非模态对话框.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CMFC01模态与非模态对话框App:
// 有关此类的实现，请参阅 MFC_01_模态与非模态对话框.cpp
//

class CMFC01模态与非模态对话框App : public CWinApp
{
public:
	CMFC01模态与非模态对话框App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMFC01模态与非模态对话框App theApp;
