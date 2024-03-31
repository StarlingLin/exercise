
// MFC_01_模态与非模态对话框Dlg.h: 头文件
//

#pragma once

#include "CDlgShow.h"

// CMFC01模态与非模态对话框Dlg 对话框
class CMFC01模态与非模态对话框Dlg : public CDialogEx
{
// 构造
public:
	CMFC01模态与非模态对话框Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_01__DIALOG };
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
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
private:
	CDlgShow m_dlgShow;
};
