
// MessageView.cpp : CMessageView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMessageView ����/����

CMessageView::CMessageView()
	: m_nLine(0)
{
	// TODO: �ڴ˴���ӹ������
	m_sMousePoint = "";
}

CMessageView::~CMessageView()
{
}

BOOL CMessageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMessageView ����

void CMessageView::OnDraw(CDC* pDC)
{
	CMessageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CMessageView ��ӡ


void CMessageView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMessageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMessageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMessageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CMessageView ���

#ifdef _DEBUG
void CMessageView::AssertValid() const
{
	CView::AssertValid();
}

void CMessageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMessageDoc* CMessageView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMessageDoc)));
	return (CMessageDoc*)m_pDocument;
}
#endif //_DEBUG


// CMessageView ��Ϣ�������


void CMessageView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_sMousePoint.Format(_T("�������ڵ�(%d,%d)����"),point.x,point.y);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMessageView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_sMousePoint = _T("���������ͷ�");
	CView::OnLButtonUp(nFlags, point);
}


void CMessageView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_sMousePoint.Format(_T("���λ�ڵ�(%d,%d)"), point.x, point.y);
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMessageView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
