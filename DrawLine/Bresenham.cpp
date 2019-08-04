#include "stdafx.h"
#include "Bresenham.h"


Bresenham::Bresenham()
{
}


Bresenham::~Bresenham()
{
}

void Bresenham::SetDc(CDC * dc)
{
	this->pdc = dc;
}

void Bresenham::Moveline(CPoint start, CPoint end)
{
	int x1=start.x, y1=start.y;
	int x2=end.x, y2=end.y;

	this->pdc->SetPixel(start.x,start.y,RGB(0,0,0));
	int dx, dy;
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	int flag=0;
	if (dx == 0 && dy == 0)
		return;
	if (dy > dx)
	{
		flag = 1;
		swap_value(x1,y1);
		swap_value(x2,y2);
		swap_value(dx,dy);
	}
	int tx = (x2 - x1) > 0 ? 1 : -1;
	int ty = (y2 - y1) > 0 ? 1 : -1;
	int curx = x1 + 1;
	int cury = y1;
	int dS = 2 * dy;
	int dT = 2 * (dy-dx);
	int d =dS-dx;
	while (curx != x2)
	{
		if (d >= 0) {
			d += dT;
			cury += ty;
		}
		else
		{
			d += dS;
		}
		if (flag)
			this->pdc->SetPixel(cury,curx,RGB(0,0,255));
		else
			this->pdc->SetPixel(curx, cury, RGB(0, 0, 255));
		curx+=tx;
	}
}

void Bresenham::swap_value(int & a, int & b)
{
	/*
	a ^= b;
	b ^= a;
	a ^= b;
	*/
	int temp = a;
	a = b;
	b = temp;

}
