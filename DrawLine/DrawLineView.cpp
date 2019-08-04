
// DrawLineView.cpp: CDrawLineView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DrawLine.h"
#endif

#include "DrawLineDoc.h"
#include "DrawLineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawLineView

IMPLEMENT_DYNCREATE(CDrawLineView, CView)

BEGIN_MESSAGE_MAP(CDrawLineView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDrawLineView 构造/析构

CDrawLineView::CDrawLineView() noexcept
{
	// TODO: 在此处添加构造代码

}

CDrawLineView::~CDrawLineView()
{
}

BOOL CDrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawLineView 绘图

void CDrawLineView::OnDraw(CDC* /*pDC*/)
{
	CDrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDrawLineView 打印

BOOL CDrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDrawLineView 诊断

#ifdef _DEBUG
void CDrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawLineDoc* CDrawLineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawLineDoc)));
	return (CDrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawLineView 消息处理程序


void CDrawLineView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (this->flag == false)
	{
		this->flag = true;
		this->start = point;
	}
	CView::OnRButtonDown(nFlags, point);
}


void CDrawLineView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (this->flag == true)
	{
		CDC *pdc = this->GetDC();
		this->flag = false;
		this->end = point;

		this->dda.SetDc(pdc);
		this->dda.Moveline(this->start,this->end);

		this->ptp.SetDc(pdc);
		this->ptp.Moveline(*new CPoint(this->start.x+20, this->start.y), *new CPoint(this->end.x+ 20, this->end.y));

		this->Bresen.SetDc(pdc);
		this->Bresen.Moveline(*new CPoint(this->start.x + 40, this->start.y ), *new CPoint(this->end.x + 40, this->end.y));

		this->Midpoi.SetDc(pdc);
		this->Midpoi.Moveline(*new CPoint(this->start.x + 60, this->start.y ), *new CPoint(this->end.x + 60, this->end.y ));

		ReleaseDC(pdc);
	}

	CView::OnRButtonUp(nFlags, point);
}
