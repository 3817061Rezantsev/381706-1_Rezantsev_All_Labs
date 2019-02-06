#pragma once
#include <iostream>
#include "../Exception/Exception.h"
#include "../Exception/Exeption.cpp"
using namespace std;
class TMonom
{
protected:
	int* power;
	int n;
	double coeff;
	TMonom *next;
public:
	TMonom();
	TMonom(int _Size, int *M, double _Coeff);
	TMonom(const TMonom &A);
	virtual ~TMonom();

	void SetPower(int *M);
	void SetN(int _Size);
	void SetCoeff(double _Coeff);
	void SetNext(TMonom* _Next);

	int *GetPower();
	int GetN();
	double GetCoeff();
	TMonom* GetNext();

	TMonom &operator = ( const TMonom &A);
	TMonom operator + (TMonom &A);
	TMonom operator += (TMonom &A);
	TMonom operator - (TMonom &A);
	TMonom operator -= (TMonom &A);
	TMonom operator * (const TMonom &A) const;
	TMonom operator *= (TMonom &A);

	bool operator == (TMonom &A);
	bool operator < (TMonom &A);
	bool operator > (TMonom &A);

	friend istream& operator>>(istream &in, TMonom &m);
	friend ostream& operator<<(ostream &out, TMonom &m);
};

