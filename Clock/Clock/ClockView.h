
// ClockView.h : CClockView ��Ľӿ�
//

#pragma once


class CClockView : public CFormView
{
protected: // �������л�����
	CClockView();
	DECLARE_DYNCREATE(CClockView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_CLOCK_FORM };
#endif

// ����
public:
	CClockDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CClockView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CString m_strTime;
	unsigned int m_timer;
	bool m_btimer;
	int h;
	int m;
	int s;
	int ms;
	afx_msg void OnTimeStart();
	afx_msg void OnTimeStop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnUpdateTimeStart(CCmdUI *pCmdUI);
	afx_msg void OnTimeCurrent();
};

#ifndef _DEBUG  // ClockView.cpp �еĵ��԰汾
inline CClockDoc* CClockView::GetDocument() const
   { return reinterpret_cast<CClockDoc*>(m_pDocument); }
#endif

