#pragma once
#include <iostream>
#include "../MonomLib/TMonom.h"
#include "../MonomLib/TMonom.cpp"
#include "../Exception/Exception.h"
class TPolynom {
protected:
	TMonom *start;
	int n; 
	int size;
public:
	TPolynom(int _n);
	TPolynom(TPolynom &p);
  ~TPolynom();
	int GetSize();
	TMonom* GetStart();

	TPolynom& operator+=(TMonom &m);
	TPolynom& operator=(const TPolynom &p);
	TPolynom operator+(TPolynom &p);
	TPolynom operator*(TPolynom &p);
	TPolynom operator-(TPolynom &p);
	TPolynom& operator-=(TMonom &m);
	bool operator==(const TPolynom &p);

	friend std::ostream& operator << (std::ostream& _s, TPolynom& Tm);
};

