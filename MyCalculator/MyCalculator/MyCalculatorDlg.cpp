
// MyCalculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyCalculator.h"
#include "MyCalculatorDlg.h"
#include "afxdialogex.h"
#include "Math.h"

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


// CMyCalculatorDlg 对话框



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


// CMyCalculatorDlg 消息处理程序

BOOL CMyCalculatorDlg::OnInitDialog()
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyCalculatorDlg::OnPaint()
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
HCURSOR CMyCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyCalculatorDlg::OnEnChangeDisplay()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMyCalculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	m_coff = 0.1;
}


void CMyCalculatorDlg::OnBnClickedButtonSign()
{
	// TODO: 在此添加控件通知处理程序代码
	m_second = -m_second;
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculate();
	m_operator = "+";
}


void CMyCalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculate();
	m_operator = "-";
}


void CMyCalculatorDlg::OnBnClickedButtonMultiply()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculate();
	m_operator = "*";
}


void CMyCalculatorDlg::OnBnClickedButtonDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculate();
	m_operator = "/";
}


void CMyCalculatorDlg::OnBnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	m_second = 0.0;
	m_operator = "+";
	m_coff = 1.0;
	UpdateDisplay(0.0);
}


void CMyCalculatorDlg::OnBnClickedButtonSqrt()
{
	// TODO: 在此添加控件通知处理程序代码
	m_second = sqrt(m_second);
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButtonReciprocal()
{
	// TODO: 在此添加控件通知处理程序代码
	if (fabs(m_second) <= 0.000001)
	{
		m_display = "除数不能等于0";
		UpdateData(false);
		return;
	}
	m_second = 1.0 / m_second;
	UpdateDisplay(m_second);
}


void CMyCalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: 在此添加控件通知处理程序代码
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
			m_display = "除数不能等于零";
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
