// CDlgManage.cpp: 实现文件
//

#include "pch.h"
#include "MFC_07_标签页.h"
#include "afxdialogex.h"
#include "CDlgManage.h"


// CDlgManage 对话框

IMPLEMENT_DYNAMIC(CDlgManage, CDialogEx)

CDlgManage::CDlgManage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MANAGE, pParent)
{

}

CDlgManage::~CDlgManage()
{
}

void CDlgManage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgManage, CDialogEx)
END_MESSAGE_MAP()


// CDlgManage 消息处理程序
