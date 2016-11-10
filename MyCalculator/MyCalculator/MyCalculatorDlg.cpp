
// MyCalculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyCalculator.h"
#include "MyCalculatorDlg.h"
#include "afxdialogex.h"
#include "Math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMyCalculatorDlg �Ի���



CMyCalculatorDlg::CMyCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYCALCULATOR_DIALOG, pParent)
	, m_display(_T(""))
	, m_first(0.0)
	, m_second(0.0)
	, m_coff(1.0)
	, m_operator(_T("+"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DISPLAY, m_display);
}

BEGIN_MESSAGE_MAP(CMyCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_DISPLAY, &CMyCalculatorDlg::OnEnChangeDisplay)
	ON_BN_CLICKED(IDC_BUTTON_0, &CMyCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CMyCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CMyCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CMyCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CMyCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CMyCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CMyCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CMyCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CMyCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CMyCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &CMyCalculatorDlg::OnBnClickedButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_SIGN, &CMyCalculatorDlg::OnBnClickedButtonSign)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMyCalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CMyCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CMyCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CMyCalculatorDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMyCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_SQRT, &CMyCalculatorDlg::OnBnClickedButtonSqrt)
	ON_BN_CLICKED(IDC_BUTTON_RECIPROCAL, &CMyCalculatorDlg::OnBnClickedButtonReciprocal)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CMyCalculatorDlg::OnBnClickedButtonEqual)
END_MESSAGE_MAP()


// CMyCalculatorDlg ��Ϣ�������

BOOL CMyCalculatorDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMyCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyCalculatorDlg::OnPaint()
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
HCURSOR CMyCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyCalculatorDlg::OnEnChangeDisplay()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMyCalculatorDlg::OnBnClickedButton0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_coff == 1.0)
	{
		m_second = m_second * 10 + 0;
	}
	else
	{
		m_second = m_second + 0 * m_coff;
		m_coff *= 0.1;
	}
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_coff == 1.0)
	{
		m_second = m_second * 10 + 1;
	}
	else
	{
		m_second = m_second + 1 * m_coff;
		m_coff *= 0.1;
	}
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_coff == 1.0)
	{
		m_second = m_second * 10 + 2;
	}
	else
	{
		m_second = m_second + 2 * m_coff;
		m_coff *= 0.1;
	}
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_coff == 1.0)
	{
		m_second = m_second * 10 + 3;
	}
	else
	{
		m_second = m_second + 3 * m_coff;
		m_coff *= 0.1;
	}
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_coff == 1.0)
	{
		m_second = m_second * 10 + 4;
	}
	else
	{
		m_second = m_second + 4 * m_coff;
		m_coff *= 0.1;
	}
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_coff == 1.0)
	{
		m_second = m_second * 10 + 5;
	}
	else
	{
		m_second = m_second + 5 * m_coff;
		m_coff *= 0.1;
	}
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_coff == 1.0)
	{
		m_second = m_second * 10 + 6;
	}
	else
	{
		m_second = m_second + 6 * m_coff;
		m_coff *= 0.1;
	}
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_coff == 1.0)
	{
		m_second = m_second * 10 + 7;
	}
	else
	{
		m_second = m_second + 7 * m_coff;
		m_coff *= 0.1;
	}
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_coff == 1.0)
	{
		m_second = m_second * 10 + 8;
	}
	else
	{
		m_second = m_second + 8 * m_coff;
		m_coff *= 0.1;
	}
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_coff == 1.0)
	{
		m_second = m_second * 10 + 9;
	}
	else
	{
		m_second = m_second + 9 * m_coff;
		m_coff *= 0.1;
	}
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButtonPoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_coff = 0.1;
}


void CMyCalculatorDlg::OnBnClickedButtonSign()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_second = -m_second;
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButtonAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Calculate();
	m_operator = "+";
}


void CMyCalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Calculate();
	m_operator = "-";
}


void CMyCalculatorDlg::OnBnClickedButtonMultiply()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Calculate();
	m_operator = "*";
}


void CMyCalculatorDlg::OnBnClickedButtonDiv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Calculate();
	m_operator = "/";
}


void CMyCalculatorDlg::OnBnClickedButtonClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_second = 0.0;
	m_operator = "+";
	m_coff = 1.0;
	UpdateDisplay(0.0);
}


void CMyCalculatorDlg::OnBnClickedButtonSqrt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_second = sqrt(m_second);
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButtonReciprocal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (fabs(m_second) <= 0.000001)
	{
		m_display = "�������ܵ���0";
		UpdateData(false);
		return;
	}
	m_second = 1.0 / m_second;
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Calculate();
	m_first = 0.0;
	m_operator = "+";
}


void CMyCalculatorDlg::UpdateDisplay(double lVal)
{
	m_display.Format(_T("%f"), lVal);
	int i = m_display.GetLength();
	while (m_display.GetAt(i - 1) == '0')
	{
		m_display.Delete(i - 1, 1);
		i--;
	}
	UpdateData(false);
}



void CMyCalculatorDlg::Calculate()
{
	switch (m_operator.GetAt(0))
	{
	case '+':
		m_first += m_second;
		break;
	case '-':
		m_first -= m_second;
		break;
	case '*':
		m_first *= m_second;
		break;
	case '/':
		if (fabs(m_second) <= 0.000001)
		{
			m_display = "�������ܵ�����";
			UpdateData(false);
			return;
		}
		m_first /= m_second;
		break;
	}
	m_second = 0.0;
	m_coff = 1.0;
	UpdateDisplay(m_first);
}
