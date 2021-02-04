
// 连点器测试程序 v2.0Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "连点器测试程序 v2.0.h"
#include "连点器测试程序 v2.0Dlg.h"
#include "afxdialogex.h"
#include <iostream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int i;

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


// C连点器测试程序v20Dlg 对话框



C连点器测试程序v20Dlg::C连点器测试程序v20Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_V20_DIALOG, pParent)
	, mins(0)
	, sec(0)
	, ms(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C连点器测试程序v20Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mins);
	DDX_Text(pDX, IDC_EDIT2, sec);
	DDX_Text(pDX, IDC_EDIT3, ms);
}

BEGIN_MESSAGE_MAP(C连点器测试程序v20Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C连点器测试程序v20Dlg::OnClickedStart)
	ON_BN_CLICKED(IDC_BUTTON2, &C连点器测试程序v20Dlg::OnClickedAc)
END_MESSAGE_MAP()


// C连点器测试程序v20Dlg 消息处理程序

BOOL C连点器测试程序v20Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	beginTime = CTime::GetCurrentTime();
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C连点器测试程序v20Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C连点器测试程序v20Dlg::OnPaint()
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
HCURSOR C连点器测试程序v20Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C连点器测试程序v20Dlg::OnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	i++;
	endTime = CTime::GetCurrentTime();
	timeSpan = endTime - beginTime;
	float second = (float)(timeSpan.GetSeconds());
	if (second >= 1)
	{
		if (i <= 1)
		{
			;
		}
		else
		{
			sec = i / second;
			mins = sec * 60;
			ms = 1 / sec * 1000;
			second = 0;
			i = 0;
			beginTime = CTime::GetCurrentTime();
		}
	}
	UpdateData(FALSE);
}


void C连点器测试程序v20Dlg::OnClickedAc()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mins = 0;
	sec = 0;
	ms = 0;
	timeSpan = 0;
	UpdateData(FALSE);
}
