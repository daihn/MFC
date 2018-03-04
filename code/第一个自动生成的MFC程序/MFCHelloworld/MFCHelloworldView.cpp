
// MFCHelloworldView.cpp : CMFCHelloworldView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCHelloworld.h"
#endif

#include "MFCHelloworldDoc.h"
#include "MFCHelloworldView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCHelloworldView

IMPLEMENT_DYNCREATE(CMFCHelloworldView, CView)

BEGIN_MESSAGE_MAP(CMFCHelloworldView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCHelloworldView ����/����

CMFCHelloworldView::CMFCHelloworldView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCHelloworldView::~CMFCHelloworldView()
{
}

BOOL CMFCHelloworldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCHelloworldView ����

void CMFCHelloworldView::OnDraw(CDC* pDC)
{
	CMFCHelloworldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(100,100,300,300);
}


// CMFCHelloworldView ��ӡ

BOOL CMFCHelloworldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCHelloworldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCHelloworldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCHelloworldView ���

#ifdef _DEBUG
void CMFCHelloworldView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCHelloworldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCHelloworldDoc* CMFCHelloworldView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCHelloworldDoc)));
	return (CMFCHelloworldDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCHelloworldView ��Ϣ�������


void CMFCHelloworldView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);

	CString cstr;
	cstr.Format(TEXT("x = %d, y = %d"), point.x, point.y);
	MessageBox(cstr,TEXT("app"));
}


void CMFCHelloworldView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CView::OnPaint()
	dc.Rectangle(300,300,400,400);
}
