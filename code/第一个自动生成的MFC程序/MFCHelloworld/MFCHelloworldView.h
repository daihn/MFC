
// MFCHelloworldView.h : CMFCHelloworldView ��Ľӿ�
//

#pragma once


class CMFCHelloworldView : public CView
{
protected: // �������л�����
	CMFCHelloworldView();
	DECLARE_DYNCREATE(CMFCHelloworldView)

// ����
public:
	CMFCHelloworldDoc* GetDocument() const;

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
	virtual ~CMFCHelloworldView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCHelloworldView.cpp �еĵ��԰汾
inline CMFCHelloworldDoc* CMFCHelloworldView::GetDocument() const
   { return reinterpret_cast<CMFCHelloworldDoc*>(m_pDocument); }
#endif

