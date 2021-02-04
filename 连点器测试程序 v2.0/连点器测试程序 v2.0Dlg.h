
// 连点器测试程序 v2.0Dlg.h : 头文件
//

#pragma once


// C连点器测试程序v20Dlg 对话框
class C连点器测试程序v20Dlg : public CDialogEx
{
// 构造
public:
	C连点器测试程序v20Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_V20_DIALOG };
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
	int mins;
	float sec;
	float ms;
	CTimeSpan timeSpan;
	CTime endTime;
	CTime beginTime;
	afx_msg void OnClickedStart();
	afx_msg void OnClickedAc();
};
