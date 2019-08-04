#include "stdafx.h"
#include "MidpointLine.h"


MidpointLine::MidpointLine()
{
}


MidpointLine::~MidpointLine()
{
}

void MidpointLine::SetDc(CDC * dc)
{
	this->pdc = dc;
}

void MidpointLine::Moveline(CPoint start, CPoint end)
{
	int x0 = start.x, x1 = end.x, y0 = start.y, y1 = end.y;
	int a, b, d2, x, y, flag = 0;
	if (abs(x1 - x0) < abs(y1 - y0))
	{
		swap_value(x0,y0);
		swap_value(x1, y1);
		flag = 1;
	}
	if (x0 > x1) {//保证x0<x1,方便判别斜率
		swap_value(x0, x1);
		swap_value(y0, y1);
	}
	a = y0 - y1;
	b = x1 - x0;
	d2 = 2*a + b;//摆脱小数点，提高效率
	if (y0 < y1) {//k>0
		x = x0; y = y0;
		this->pdc->SetPixel(x,y,RGB(0,0,0));
		while (x < x1)
		{
			if (d2 < 0)
			{
				x++;
				y++;
				d2 =d2+ 2*a + 2*b;
			}
			else {
				x++;
				d2 =d2+ 2 * a;
			}

			if(flag)//|k|>1
				this->pdc->SetPixel(y, x, RGB(0, 0, 0));
			else
				this->pdc->SetPixel(x, y, RGB(0, 0, 0));
		}
	}
	else {//k<0
		x = x1;
		y = y1;
		this->pdc->SetPixel(x, y, RGB(0, 0, 0));
		while (x >x0)
		{
			if (d2 < 0)
			{
				x--;
				y++;
				d2 = d2-2 * a + 2 * b;
			}
			else {
				x--;
				d2 =d2- 2 * a;
			}

			if (flag)//|k|>1
				this->pdc->SetPixel(y, x, RGB(0, 0, 0));
			else
				this->pdc->SetPixel(x, y, RGB(0, 0, 0));
		}
	}
}

void MidpointLine::swap_value(int & a, int & b)
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
