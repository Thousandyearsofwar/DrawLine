#pragma once
class MidpointLine
{
public:
	CDC *pdc;
	MidpointLine();
	~MidpointLine();
	void SetDc(CDC *dc);
	void Moveline(CPoint start, CPoint end);
	void swap_value(int &a, int &b);
};

