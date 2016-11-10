
// MessageView.h : CMessageView 类的接口
//

#pragma once
#include <map>

class CMessageView : public CView
{
protected: // 仅从序列化创建
	CMessageView();
	DECLARE_DYNCREATE(CMessageView)
	CString m_sMousePoint; //存储数鼠标的方式和位置
	CString m_strDisplay;
	std::map<int, CString>  m_mapMessageAndIndex;
// 特性
public:
	CMessageDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMessageView();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int m_nLine;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MessageView.cpp 中的调试版本
inline CMessageDoc* CMessageView::GetDocument() const
   { return reinterpret_cast<CMessageDoc*>(m_pDocument); }
#endif

