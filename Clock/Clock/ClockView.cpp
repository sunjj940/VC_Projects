
// ClockView.cpp : CClockView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Clock.h"
#endif

#include "ClockDoc.h"
#include "ClockView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClockView

IMPLEMENT_DYNCREATE(CClockView, CFormView)

BEGIN_MESSAGE_MAP(CClockView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TIME_START, &CClockView::OnTimeStart)
	ON_COMMAND(ID_TIME_STOP, &CClockView::OnTimeStop)
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_TIME_START, &CClockView::OnUpdateTimeStart)
	ON_COMMAND(ID_TIME_CURRENT, &CClockView::OnTimeCurrent)
END_MESSAGE_MAP()

// CClockView ����/����

CClockView::CClockView()
	: CFormView(IDD_CLOCK_FORM)
	, m_strTime(_T(""))
	, m_timer(0)
	, m_btimer(true)
	, h(0)
	, m(0)
	, s(0)
	, ms(0)
{
	// TODO: �ڴ˴���ӹ������

}

CClockView::~CClockView()
{
}

void CClockView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TIME, m_strTime);
}

BOOL CClockView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CClockView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CClockView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CClockView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CClockView ���

#ifdef _DEBUG
void CClockView::AssertValid() const
{
	CFormView::AssertValid();
}

void CClockView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CClockDoc* CClockView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClockDoc)));
	return (CClockDoc*)m_pDocument;
}
#endif //_DEBUG


// CClockView ��Ϣ�������


void CClockView::OnTimeStart()
{
	// TODO: �ڴ���������������
	m_timer = SetTimer(1, 100, NULL);
	m_btimer = FALSE;
}


void CClockView::OnTimeStop()
{
	// TODO: �ڴ���������������
	KillTimer(m_timer);
	m_btimer = TRUE;
}


void CClockView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_strTime.Format("%d:%d:%d.%d", h, m, s, ms);
	UpdateData(FALSE);
	ms++;
	if (ms == 10) { ms = 0; s++; }
	if (s == 60) { s = 0; m++; }
	if (m == 60) { m = 0; h++; }
	CFormView::OnTimer(nIDEvent);
}


void CClockView::OnUpdateTimeStart(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if (!m_btimer)
		pCmdUI->Enable(FALSE);
}


void CClockView::OnTimeCurrent()
{
	// TODO: �ڴ���������������
	OnTimeStop();
	CTime t = CTime::GetCurrentTime();
	CString str;
	str.Format("Current Time is %02d:%02d:%02d",t.GetHour(), t.GetMinute(), t.GetSecond());
	MessageBox(str, NULL, MB_OK);
	h = m = s = ms = 0;
	m_strTime.Format("%02d:%02d:%02d.%01d", h, m, s, ms);
	UpdateData(FALSE);
}
