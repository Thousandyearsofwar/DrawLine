#pragma once
class MyDDA
{
public:
	CDC *pdc;
	MyDDA();
	~MyDDA();
	void SetDc(CDC *dc);
	void Moveline(CPoint start,CPoint end);

};

