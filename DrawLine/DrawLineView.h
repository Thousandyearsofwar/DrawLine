
// DrawLineView.h: CDrawLineView 类的接口
//

#pragma once
#include"MyDDA.h"
#include"PtoP.h"
#include"Bresenham.h"
#include"MidpointLine.h"

class CDrawLineView : public CView
{
protected: // 仅从序列化创建
	CDrawLineView() noexcept;
	DECLARE_DYNCREATE(CDrawLineView)
	MyDDA dda;
	PtoP ptp;
	Bresenham Bresen;
	MidpointLine Midpoi;
	CPoint start, end;
	bool flag=false;

// 特性
public:
	CDrawLineDoc* GetDocument() const;

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
	virtual ~CDrawLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DrawLineView.cpp 中的调试版本
inline CDrawLineDoc* CDrawLineView::GetDocument() const
   { return reinterpret_cast<CDrawLineDoc*>(m_pDocument); }
#endif

