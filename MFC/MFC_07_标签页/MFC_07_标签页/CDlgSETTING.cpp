// CDlgSETTING.cpp: 实现文件
//

#include "pch.h"
#include "MFC_07_标签页.h"
#include "afxdialogex.h"
#include "CDlgSETTING.h"


// CDlgSETTING 对话框

IMPLEMENT_DYNAMIC(CDlgSETTING, CDialogEx)

CDlgSETTING::CDlgSETTING(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETTING, pParent)
{

}

CDlgSETTING::~CDlgSETTING()
{
}

void CDlgSETTING::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgSETTING, CDialogEx)
END_MESSAGE_MAP()


// CDlgSETTING 消息处理程序
