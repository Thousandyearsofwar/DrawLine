#include "stdafx.h"
#include "MyDDA.h"


MyDDA::MyDDA()
{
}


MyDDA::~MyDDA()
{
}

void MyDDA::SetDc(CDC * dc)
{
	this->pdc = dc;
}

void MyDDA::Moveline(CPoint start, CPoint end)
{
	int x1, x2;
	int y1, y2;
	x1 = start.x;
	x2 = end.x;
	y1 = start.y;
	y2 = end.y;
	float dm = 0;
	if (abs(x2 - x1) >= abs(y2 - y1))
		dm = abs(x2 - x1);
	else
		dm = abs(y2 - y1);
	float dx = (float)(x2 - x1) / dm;
	float dy = (float)(y2 - y1) / dm;
	float x = x1 + 0.5;
	float y = y1 + 0.5;
	int i = 0;
	while (i<dm) {
		this->pdc->SetPixel((int)x, (int)y, RGB(255, 0, 0));
		x += dx;
		y += dy;
		i += 1;
	}

}
