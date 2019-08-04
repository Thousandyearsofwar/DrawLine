#pragma once
class PtoP
{
public:
	CDC *pdc;
	PtoP();
	~PtoP();
	void SetDc(CDC *dc);
	void Moveline(CPoint start, CPoint end);
};

