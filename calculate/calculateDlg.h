
// calculateDlg.h : 头文件
//

#pragma once


// CcalculateDlg 对话框
class CcalculateDlg : public CDialogEx
{
// 构造
public:
	CcalculateDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATE_DIALOG };

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
  afx_msg void OnEnChangeEditNumadded1();
  afx_msg void OnBnClickedButtonCalculate();
  afx_msg void OnEnChangeEditNumresult();
  afx_msg void OnEnChangeEditNumadded2();
  afx_msg void OnBnClickedButtonReset();
  afx_msg void OnCbnSelchangeComboOperator();
  CComboBox m_ComboOperator;
  afx_msg void OnBnClickedButtonPay();
  afx_msg void OnBnClickedButtonOpenkey();
};

CString GetModuleDir();