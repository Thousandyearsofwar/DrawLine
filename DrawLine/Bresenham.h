#pragma once
class Bresenham
{
public:
	CDC *pdc;
	Bresenham();
	~Bresenham();
	void SetDc(CDC *dc);
	void Moveline(CPoint start, CPoint end);
	void swap_value(int &a,int &b);
};

