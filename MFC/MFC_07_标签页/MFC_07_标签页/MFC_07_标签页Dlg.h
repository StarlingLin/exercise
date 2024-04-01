
// MFC_07_标签页Dlg.h: 头文件
//

#pragma once

#include "TabSheet.h"
#include "CDlgManage.h"
#include "CDlgSetting.h"


// CMFC07标签页Dlg 对话框
class CMFC07标签页Dlg : public CDialogEx
{
// 构造
public:
	CMFC07标签页Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_07__DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CTabSheet m_tab;
	CDlgManage dlgManage;
	CDlgSETTING dlgSetting;
};
