
// ���������Գ��� v2.0Dlg.h : ͷ�ļ�
//

#pragma once


// C���������Գ���v20Dlg �Ի���
class C���������Գ���v20Dlg : public CDialogEx
{
// ����
public:
	C���������Գ���v20Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_V20_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
