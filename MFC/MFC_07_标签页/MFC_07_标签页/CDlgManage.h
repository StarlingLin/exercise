#pragma once
#include "afxdialogex.h"


// CDlgManage 对话框

class CDlgManage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgManage)

public:
	CDlgManage(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgManage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
