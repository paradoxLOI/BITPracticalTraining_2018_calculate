
// calculateDlg.h : ͷ�ļ�
//

#pragma once


// CcalculateDlg �Ի���
class CcalculateDlg : public CDialogEx
{
// ����
public:
	CcalculateDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATE_DIALOG };

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
  afx_msg void OnEnChangeEditNumadded1();
  afx_msg void OnBnClickedButtonCalculate();
  afx_msg void OnEnChangeEditNumresult();
  afx_msg void OnEnChangeEditNumadded2();
  afx_msg void OnBnClickedButtonReset();
  afx_msg void OnBnClickedRadio4();
  afx_msg void OnBnClickedRadioPlus();
  afx_msg void OnBnClickedRadioMinus();
  afx_msg void OnBnClickedRadioMultiply();
  afx_msg void OnBnClickedRadioDivide();
  afx_msg void OnBnClickedCheck2();
  afx_msg void OnBnClickedCheckHavepayed();
  afx_msg void OnBnClickedButton1();
  afx_msg void OnBnClickedButtonGetvip();
};
