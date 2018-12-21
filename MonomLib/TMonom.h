#pragma once
#include <iostream>
using namespace std;
class TMonomial
{
protected:
	int* power;
	int size;
	double coeff;
	TMonomial *next;
public:
	TMonomial(int _Size, int *M, double _Coeff, TMonomial *_Next);
	TMonomial(TMonomial &A);
	void SetPower(int *M);
	void SetSize(int _Size);
	void SetCoeff(double _Coeff);
	void SetNext(TMonomial* _Next);
	int *GetPower();
	int GetSize();
	double GetCoeff();
	TMonomial* GetNext();
	TMonomial &operator = (TMonomial &A);
	TMonomial operator + (TMonomial &A);
	TMonomial operator - (TMonomial &A);
	TMonomial operator * (TMonomial &A);
	bool operator == (TMonomial &A);
	bool operator < (TMonomial &A);
	bool operator > (TMonomial &A);

	friend istream& operator>>(istream &in, TMonomial &m)
	{
		in >> m.coeff >> m.power;
		return in;
	}
	friend ostream& operator<<(ostream &out, TMonomial &m)
	{
		out << m.GetCoeff() << ' ' << m.GetPower();
		return out;
	}
};

//------------------------------------------------------------------
TMonomial::TMonomial(int _Size, int *M, double _Coeff, TMonomial *_Next)
{
	if (_Size > 999999)
	{
		throw -1;
	}
	else
	{
		if (_Size <= 0) throw -1;
		else size = _Size;
		coeff = _Coeff;
		power = M;
		next = _Next;
	}
}
//------------------------------------------------------------------
TMonomial::TMonomial(TMonomial &A)
{
	size = A.size;
	power = new int[size];
	for (int i = 0; i < size; i++)
		power[i] = A.power[i];
	coeff = A.coeff;
	next = A.next;
}
//------------------------------------------------------------------
void TMonomial::SetPower(int *M)
{
	try
	{
		for (int i = 0; i < size; i++)
		{
			if (M[i] >= 0)
				power[i] = M[i];
			else
				throw - 1; 
		}
	}
	catch (...)
	{
		throw - 2;
	}
}
//------------------------------------------------------------------
void TMonomial::SetSize(int _Size)
{
	if (_Size <= 0)
		throw -1;
	else
	{
		size = _Size;
		TMonomial temp(*this);
		if (_Size == size)
		{
			temp = *this;
		}
		else if (_Size < size)
		{
			temp.power = new int[_Size];
			for (int i = 0; i < _Size; i++)
				temp.power[i] = power[i];
			delete[]power;
			size = _Size;
			power = new int[size];
			for (int i = 0; i < size; i++)
				power[i] = temp.power[i];
		}
		else if (_Size > size)
		{
			temp.power = new int[size];
			for (int i = 0; i < size; i++)
				temp.power[i] = power[i];
			delete[]power;
			size = _Size;
			power = new int[size];
			for (int i = 0; i < size; i++)
				power[i] = temp.power[i];
		}
	}
}
//------------------------------------------------------------------
void TMonomial::SetCoeff(double _Coeff)
{
	coeff = _Coeff;
}
//------------------------------------------------------------------
void TMonomial::SetNext(TMonomial* _Next)
{

}
//------------------------------------------------------------------
int *TMonomial::GetPower()
{
	return power;
}
//------------------------------------------------------------------
int TMonomial::GetSize()
{
	return size;
}
//------------------------------------------------------------------
double TMonomial::GetCoeff()
{
	return coeff;
}
//------------------------------------------------------------------
TMonomial* TMonomial::GetNext()
{
	return next;
}
//------------------------------------------------------------------
TMonomial &TMonomial::operator = (TMonomial &A)
{
	coeff = A.coeff;
	delete[]power;
	size = A.size;
	power = new int[size];
	for (int i = 0; i < size; i++)
		power[i] = A.power[i];
	next = A.next;
}
//------------------------------------------------------------------
TMonomial TMonomial::operator + (TMonomial &A)
{
	TMonomial temporary(*this);
	if (size != A.size)
		throw -1;
	else
	{
		for (int i = 0; i < size; i++)
			if (power[i] != A.power[i])
				throw -1;
		temporary.coeff = coeff + A.coeff;
		return temporary;
	}
}
//------------------------------------------------------------------
TMonomial TMonomial::operator - (TMonomial &A)
{
	TMonomial temporary(*this);
	if (size != A.size)
		throw -1;
	else
	{
		for (int i = 0; i < size; i++)
			if (power[i] != A.power[i])
				throw -1;
		temporary.coeff = coeff - A.coeff;
		return temporary;
	}
}
//------------------------------------------------------------------
TMonomial TMonomial::operator * (TMonomial &A)
{
	TMonomial temporary(*this);
	if (size != A.size)
		throw -1;
	else
	{
		coeff = coeff * A.coeff;
		for (int i = 0; i < size; i++)
			temporary.power[i] = power[i] + A.power[i];
		return temporary;
	}
}
//------------------------------------------------------------------
bool TMonomial::operator == (TMonomial &A)
{
	if (size == A.size)
	{
		for (int i = 0; i < size; i++)
			if (power[i] != A.power[i])
				return false;
		return true;
	}
	else
		return false;
}
//------------------------------------------------------------------
bool TMonomial::operator < (TMonomial &A)
{
	if (size != A.size)
		throw -1;
	for (int i = 0; i < size; i++)
		if (power[i] > A.power[i])
			return false;
	return true;
}
//------------------------------------------------------------------
bool TMonomial::operator > (TMonomial &A)
{
	if (size != A.size)
		throw -1;
	for (int i = 0; i < size; i++)
		if (power[i] < A.power[i])
			return false;
	return true;
}