
// MessageView.h : CMessageView ��Ľӿ�
//

#pragma once
#include <map>

class CMessageView : public CView
{
protected: // �������л�����
	CMessageView();
	DECLARE_DYNCREATE(CMessageView)
	CString m_sMousePoint; //�洢�����ķ�ʽ��λ��
	CString m_strDisplay;
	std::map<int, CString>  m_mapMessageAndIndex;
// ����
public:
	CMessageDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMessageView();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int m_nLine;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MessageView.cpp �еĵ��԰汾
inline CMessageDoc* CMessageView::GetDocument() const
   { return reinterpret_cast<CMessageDoc*>(m_pDocument); }
#endif

