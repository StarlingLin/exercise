
// MFC_02_静态文本控件Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC_02_静态文本控件.h"
#include "MFC_02_静态文本控件Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC02静态文本控件Dlg 对话框



CMFC02静态文本控件Dlg::CMFC02静态文本控件Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_02__DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC02静态文本控件Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TXT1, m_txt1);
	DDX_Control(pDX, IDC_IMG, m_img);
	DDX_Control(pDX, IDC_BUTTON4, m_btn);
}

BEGIN_MESSAGE_MAP(CMFC02静态文本控件Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC02静态文本控件Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC02静态文本控件Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC02静态文本控件Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC02静态文本控件Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFC02静态文本控件Dlg 消息处理程序

BOOL CMFC02静态文本控件Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_img.ModifyStyle(1, SS_BITMAP | SS_CENTERIMAGE);
#define HBMP(filepath, width, height) (HBITMAP)LoadImage(AfxGetInstanceHandle(), filepath, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION)
	CRect rect;
	m_img.GetWindowRect(rect);
	m_img.SetBitmap(HBMP(L"./img.bmp", rect.Width(), rect.Height()));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC02静态文本控件Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC02静态文本控件Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC02静态文本控件Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC02静态文本控件Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_txt1.SetWindowTextW(L"呜呜");
}


void CMFC02静态文本控件Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_txt1.SetWindowTextW(L"呃呃");
}


void CMFC02静态文本控件Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_txt1.GetWindowTextW(str);
	MessageBox(str, L"文本");
}


void CMFC02静态文本控件Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_btn.SetWindowTextW(L"饿啊~");
	CString str;
	m_btn.GetWindowTextW(str);
	MessageBox(str, L"按钮");
	m_btn.EnableWindow(FALSE);
}
