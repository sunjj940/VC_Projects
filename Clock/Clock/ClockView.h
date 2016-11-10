
// ClockView.h : CClockView 类的接口
//

#pragma once


class CClockView : public CFormView
{
protected: // 仅从序列化创建
	CClockView();
	DECLARE_DYNCREATE(CClockView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_CLOCK_FORM };
#endif

// 特性
public:
	CClockDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CClockView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // ClockView.cpp 中的调试版本
inline CClockDoc* CClockView::GetDocument() const
   { return reinterpret_cast<CClockDoc*>(m_pDocument); }
#endif

