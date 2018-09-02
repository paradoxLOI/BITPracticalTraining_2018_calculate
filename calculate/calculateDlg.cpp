
// calculateDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculate.h"
#include "calculateDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CcalculateDlg �Ի���




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


// CcalculateDlg ��Ϣ�������

BOOL CcalculateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculateDlg::OnEnChangeEditNumadded1()
{
  // TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
  // ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
  // ���������� CRichEditCtrl().SetEventMask()��
  // ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

  // TODO:  �ڴ���ӿؼ�֪ͨ����������
}

//+   1
//-   2
//*   3
///   4
int nOperatorSymbol;
bool bHavePayed  = false;

void CcalculateDlg::OnBnClickedButtonCalculate()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  float fNumAdded1, fNumAdded2, fNumResult;
  CString sNumAdded1, sNumAdded2, sNumResult;
  
  GetDlgItemText(IDC_EDIT_NumAdded1, sNumAdded1);
  GetDlgItemText(IDC_EDIT_NumAdded2, sNumAdded2);
  fNumAdded1 = atof(sNumAdded1);//GetDlgItemInt(IDC_EDIT_NumAdded1, NULL);
  fNumAdded2 = atof(sNumAdded2);//GetDlgItemInt(IDC_EDIT_NumAdded2, NULL);

  if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK_HavePayed))
  {
    // ��ѡ
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
        SetDlgItemText(IDC_EDIT_NumResult, "��ȥ봽�");
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
        SetDlgItemText(IDC_EDIT_NumResult, "��ȥ봽�");
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
        SetDlgItemText(IDC_EDIT_NumResult, "��ȥ봽�");
      }
      break;
    }
    default:
    {
      SetDlgItemText(IDC_EDIT_NumResult, "ȥѡ��������QAQ");
      break;
    }
  }
}


void CcalculateDlg::OnEnChangeEditNumresult()
{
  // TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
  // ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
  // ���������� CRichEditCtrl().SetEventMask()��
  // ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

  // TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculateDlg::OnEnChangeEditNumadded2()
{
  // TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
  // ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
  // ���������� CRichEditCtrl().SetEventMask()��
  // ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

  // TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculateDlg::OnBnClickedButtonReset()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  SetDlgItemText(IDC_EDIT_NumAdded1, NULL);
  SetDlgItemText(IDC_EDIT_NumAdded2, NULL);
  SetDlgItemText(IDC_EDIT_NumResult, NULL);
}


void CcalculateDlg::OnBnClickedRadio4()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculateDlg::OnBnClickedRadioPlus()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  nOperatorSymbol = 1;
}


void CcalculateDlg::OnBnClickedRadioMinus()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  nOperatorSymbol = 2;
}


void CcalculateDlg::OnBnClickedRadioMultiply()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  nOperatorSymbol = 3;
}


void CcalculateDlg::OnBnClickedRadioDivide()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  nOperatorSymbol = 4;
}


void CcalculateDlg::OnBnClickedCheck2()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculateDlg::OnBnClickedCheckHavepayed()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculateDlg::OnBnClickedButton1()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
}