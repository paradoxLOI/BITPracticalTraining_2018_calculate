
// calculateDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculate.h"
#include "calculateDlg.h"
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
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculateDlg 对话框




CcalculateDlg::CcalculateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculateDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcalculateDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_EN_CHANGE(IDC_EDIT_NumAdded1, &CcalculateDlg::OnEnChangeEditNumadded1)
  ON_BN_CLICKED(IDC_BUTTON_Calculate, &CcalculateDlg::OnBnClickedButtonCalculate)
  ON_EN_CHANGE(IDC_EDIT_NumResult, &CcalculateDlg::OnEnChangeEditNumresult)
  ON_EN_CHANGE(IDC_EDIT_NumAdded2, &CcalculateDlg::OnEnChangeEditNumadded2)
  ON_BN_CLICKED(IDC_BUTTON_Reset, &CcalculateDlg::OnBnClickedButtonReset)
  ON_BN_CLICKED(IDC_RADIO_Plus, &CcalculateDlg::OnBnClickedRadioPlus)
  ON_BN_CLICKED(IDC_RADIO_Minus, &CcalculateDlg::OnBnClickedRadioMinus)
  ON_BN_CLICKED(IDC_RADIO_Multiply, &CcalculateDlg::OnBnClickedRadioMultiply)
  ON_BN_CLICKED(IDC_RADIO_Divide, &CcalculateDlg::OnBnClickedRadioDivide)
  ON_BN_CLICKED(IDC_CHECK_HavePayed, &CcalculateDlg::OnBnClickedCheckHavepayed)
END_MESSAGE_MAP()


// CcalculateDlg 消息处理程序

BOOL CcalculateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculateDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculateDlg::OnPaint()
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
HCURSOR CcalculateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculateDlg::OnEnChangeEditNumadded1()
{
  // TODO:  如果该控件是 RICHEDIT 控件，它将不
  // 发送此通知，除非重写 CDialogEx::OnInitDialog()
  // 函数并调用 CRichEditCtrl().SetEventMask()，
  // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

  // TODO:  在此添加控件通知处理程序代码
}

//+   1
//-   2
//*   3
///   4
int nOperatorSymbol;
bool bHavePayed  = false;

void CcalculateDlg::OnBnClickedButtonCalculate()
{
  // TODO: 在此添加控件通知处理程序代码
  float fNumAdded1, fNumAdded2, fNumResult;
  CString sNumAdded1, sNumAdded2, sNumResult;
  
  GetDlgItemText(IDC_EDIT_NumAdded1, sNumAdded1);
  GetDlgItemText(IDC_EDIT_NumAdded2, sNumAdded2);
  fNumAdded1 = atof(sNumAdded1);//GetDlgItemInt(IDC_EDIT_NumAdded1, NULL);
  fNumAdded2 = atof(sNumAdded2);//GetDlgItemInt(IDC_EDIT_NumAdded2, NULL);

  if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK_HavePayed))
  {
    // 勾选
    bHavePayed = true;
  }
  else
  {
    bHavePayed = false;
  }

  switch (nOperatorSymbol)
  {
    case 1:
    {
      fNumResult = fNumAdded1 + fNumAdded2;
      sNumResult.Format(_T("%.2f"), fNumResult);
      SetDlgItemText(IDC_EDIT_NumResult, sNumResult);
      break;
    }
    case 2:
    {
      if (bHavePayed)
      {
        fNumResult = fNumAdded1 - fNumAdded2;
        sNumResult.Format(_T("%.2f"), fNumResult);
        SetDlgItemText(IDC_EDIT_NumResult, sNumResult);
      }
      else
      {
        SetDlgItemText(IDC_EDIT_NumResult, "快去氪金！");
      }
      break;
    }
    case 3:
    {
      if (bHavePayed)
      {
        fNumResult = fNumAdded1 * fNumAdded2;
        sNumResult.Format(_T("%.2f"), fNumResult);
        SetDlgItemText(IDC_EDIT_NumResult, sNumResult);
      }
      else
      {
        SetDlgItemText(IDC_EDIT_NumResult, "快去氪金！");
      }
      break;
    }
    case 4:
    {
      if (bHavePayed)
      {
        fNumResult = fNumAdded1 / fNumAdded2;
        sNumResult.Format(_T("%.2f"), fNumResult);
        SetDlgItemText(IDC_EDIT_NumResult, sNumResult);
      }
      else
      {
        SetDlgItemText(IDC_EDIT_NumResult, "快去氪金！");
      }
      break;
    }
    default:
    {
      SetDlgItemText(IDC_EDIT_NumResult, "去选个操作啊QAQ");
      break;
    }
  }
}


void CcalculateDlg::OnEnChangeEditNumresult()
{
  // TODO:  如果该控件是 RICHEDIT 控件，它将不
  // 发送此通知，除非重写 CDialogEx::OnInitDialog()
  // 函数并调用 CRichEditCtrl().SetEventMask()，
  // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

  // TODO:  在此添加控件通知处理程序代码
}


void CcalculateDlg::OnEnChangeEditNumadded2()
{
  // TODO:  如果该控件是 RICHEDIT 控件，它将不
  // 发送此通知，除非重写 CDialogEx::OnInitDialog()
  // 函数并调用 CRichEditCtrl().SetEventMask()，
  // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

  // TODO:  在此添加控件通知处理程序代码
}


void CcalculateDlg::OnBnClickedButtonReset()
{
  // TODO: 在此添加控件通知处理程序代码
  SetDlgItemText(IDC_EDIT_NumAdded1, NULL);
  SetDlgItemText(IDC_EDIT_NumAdded2, NULL);
  SetDlgItemText(IDC_EDIT_NumResult, NULL);
}


void CcalculateDlg::OnBnClickedRadio4()
{
  // TODO: 在此添加控件通知处理程序代码
}


void CcalculateDlg::OnBnClickedRadioPlus()
{
  // TODO: 在此添加控件通知处理程序代码
  nOperatorSymbol = 1;
}


void CcalculateDlg::OnBnClickedRadioMinus()
{
  // TODO: 在此添加控件通知处理程序代码
  nOperatorSymbol = 2;
}


void CcalculateDlg::OnBnClickedRadioMultiply()
{
  // TODO: 在此添加控件通知处理程序代码
  nOperatorSymbol = 3;
}


void CcalculateDlg::OnBnClickedRadioDivide()
{
  // TODO: 在此添加控件通知处理程序代码
  nOperatorSymbol = 4;
}


void CcalculateDlg::OnBnClickedCheck2()
{
  // TODO: 在此添加控件通知处理程序代码
}


void CcalculateDlg::OnBnClickedCheckHavepayed()
{
  // TODO: 在此添加控件通知处理程序代码
}


void CcalculateDlg::OnBnClickedButton1()
{
  // TODO: 在此添加控件通知处理程序代码
}