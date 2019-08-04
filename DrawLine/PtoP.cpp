#include "stdafx.h"
#include "PtoP.h"


PtoP::PtoP()
{
}


PtoP::~PtoP()
{
}

void PtoP::SetDc(CDC * dc)
{
	this->pdc = dc;
}

void PtoP::Moveline(CPoint start, CPoint end)
{
	int xA, yA;
	if (start.y > end.y) {
		xA = start.x - end.x;
		yA = start.y - end.y;
	}
	else
	{
		xA = end.x - start.x;
		yA = end.y - start.y;
	}

	int n = abs(xA) + abs(yA);

	int x = 0, y = 0, F = 0;
	/*
	if (xA > 0)//1
	{
		for (int i = 0; i < n; i++)
		{
			if (F >= 0)
			{
				x += 1;
				F -= yA;
				if(start.y>end.y)
				this->pdc->SetPixel(x+end.x,y+end.y, RGB(0, 0, 0));
				else
				this->pdc->SetPixel(x + start.x, y + start.y, RGB(0, 0, 0));
			}
			else
			{
				y += 1;
				F += xA;
				if (start.y > end.y)
					this->pdc->SetPixel(x + end.x, y + end.y, RGB(0, 0, 0));
				else
					this->pdc->SetPixel(x + start.x, y + start.y, RGB(0, 0, 0));
			}
		}

	}
	else//2
	{
		for (int i = 0; i < n; i++)
		{
			if (F >= 0)
			{
				y += 1;
				F += xA;
				if (start.y > end.y)
					this->pdc->SetPixel(x + end.x, y + end.y, RGB(0, 0, 0));
				else
					this->pdc->SetPixel(x + start.x, y + start.y, RGB(0, 0, 0));
			}
			else
			{
				x-= 1;
				F += yA;
				if (start.y > end.y)
					this->pdc->SetPixel(x + end.x, y + end.y, RGB(0, 0, 0));
				else
					this->pdc->SetPixel(x + start.x, y + start.y, RGB(0, 0, 0));
			}

		}

	}
	*/
	for (int i = 0; i < n; i++) {
		if (xA > 0) {
			if (F >= 0)
			{
				x++;
				F -= yA;
			}
			else
			{
				y++;
				F += xA;
			}
		}
		else {
			if (F >= 0)
			{
				y++;
				F += xA;
			}
			else
			{
				x--;
				F += yA;
			}
		}
		if (start.y > end.y)
			this->pdc->SetPixel(x + end.x, y + end.y, RGB(0, 0, 0));
		else
			this->pdc->SetPixel(x + start.x, y + start.y, RGB(0, 0, 0));
	}
}
