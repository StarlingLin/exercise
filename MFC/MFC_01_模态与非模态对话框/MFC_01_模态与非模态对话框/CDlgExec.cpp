﻿// CDlgExec.cpp: 实现文件
//

#include "pch.h"
#include "MFC_01_模态与非模态对话框.h"
#include "afxdialogex.h"
#include "CDlgExec.h"


// CDlgExec 对话框

IMPLEMENT_DYNAMIC(CDlgExec, CDialogEx)

CDlgExec::CDlgExec(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXEC, pParent)
{

}

CDlgExec::~CDlgExec()
{
}

void CDlgExec::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgExec, CDialogEx)
END_MESSAGE_MAP()


// CDlgExec 消息处理程序
