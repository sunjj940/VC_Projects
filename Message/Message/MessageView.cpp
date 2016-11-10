
// MessageView.cpp : CMessageView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Message.h"
#endif

#include "MessageDoc.h"
#include "MessageView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMessageView

IMPLEMENT_DYNCREATE(CMessageView, CView)

BEGIN_MESSAGE_MAP(CMessageView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMessageView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMessageView 构造/析构

CMessageView::CMessageView()
	: m_nLine(0)
{
	// TODO: 在此处添加构造代码
	m_sMousePoint = "";
}

CMessageView::~CMessageView()
{
}

BOOL CMessageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMessageView 绘制

void CMessageView::OnDraw(CDC* pDC)
{
	CMessageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOut(100, 100, m_sMousePoint);
	if (m_mapMessageAndIndex.size() > 0) {
		std::map< int , CString>::iterator it = m_mapMessageAndIndex.begin();
		
		for (int i = 0; i < m_mapMessageAndIndex.size(); i ++)
		{
			pDC->TextOut(0, it->first* 20, it->second);
			it++;
		}
	}
	pDC->TextOut(0, m_nLine * 20, m_strDisplay);
		
}


// CMessageView 打印


void CMessageView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMessageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMessageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMessageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMessageView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMessageView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMessageView 诊断

#ifdef _DEBUG
void CMessageView::AssertValid() const
{
	CView::AssertValid();
}

void CMessageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMessageDoc* CMessageView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMessageDoc)));
	return (CMessageDoc*)m_pDocument;
}
#endif //_DEBUG


// CMessageView 消息处理程序


void CMessageView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_sMousePoint.Format(_T("鼠标左键在点(%d,%d)按下"),point.x,point.y);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMessageView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_sMousePoint = _T("鼠标左键被释放");
	CView::OnLButtonUp(nFlags, point);
}


void CMessageView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_sMousePoint.Format(_T("鼠标位于点(%d,%d)"), point.x, point.y);
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMessageView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == VK_RETURN)
	{
		m_mapMessageAndIndex[m_nLine] = m_strDisplay;
		m_strDisplay.Empty();
		m_nLine++;
	} 
	else
	{
		m_strDisplay += (TCHAR)nChar;
	}
	CClientDC dc(this);
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
