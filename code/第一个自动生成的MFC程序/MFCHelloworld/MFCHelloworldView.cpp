
// MFCHelloworldView.cpp : CMFCHelloworldView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCHelloworldView 构造/析构

CMFCHelloworldView::CMFCHelloworldView()
{
	// TODO: 在此处添加构造代码

}

CMFCHelloworldView::~CMFCHelloworldView()
{
}

BOOL CMFCHelloworldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCHelloworldView 绘制

void CMFCHelloworldView::OnDraw(CDC* pDC)
{
	CMFCHelloworldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(100,100,300,300);
}


// CMFCHelloworldView 打印

BOOL CMFCHelloworldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCHelloworldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCHelloworldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCHelloworldView 诊断

#ifdef _DEBUG
void CMFCHelloworldView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCHelloworldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCHelloworldDoc* CMFCHelloworldView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCHelloworldDoc)));
	return (CMFCHelloworldDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCHelloworldView 消息处理程序


void CMFCHelloworldView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);

	CString cstr;
	cstr.Format(TEXT("x = %d, y = %d"), point.x, point.y);
	MessageBox(cstr,TEXT("app"));
}


void CMFCHelloworldView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CView::OnPaint()
	dc.Rectangle(300,300,400,400);
}
