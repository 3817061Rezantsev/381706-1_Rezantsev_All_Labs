#pragma once
class TMonom
{
protected:
	TMonom* next;
	unsigned* power;
	double c;
	int n;
public:
	TMonom() :n(0) { next = 0; power = 0; c = 0; }
	TMonom(int _n, unsigned* _power, double c);
	TMonom(TMonom& monom);
	TMonom* GetNext();
	unsigned* GetPower();
	double GetC();
	const int GetN();

	void SetNext(TMonom* _next);
	void SetpPower(unsigned* _power);
	void SetC(double _c);

	TMonom& operator =(TMonom& monom);
	TMonom operator +(TMonom& monom);
	TMonom operator *(TMonom& monom);
	TMonom operator -(TMonom& monom);
	bool operator ==(TMonom& monom);
	bool operator >(TMonom& monom);
	bool operator <(TMonom& monom);

	friend std::istream& operator >> (std::istream& _s, TMonom& Tm);
	friend std::ostream& operator << (std::ostream& _s, TMonom& Tm);

};
