#pragma once
#include <iostream>
#include <math.h>
#include "../VectorLib/TVector.h"

template <class T>

class TMatrix: public TVector<T>
{
public:
	TMatrix(int = 0);
	TMatrix(TMatrix &A);
	TMatrix(TVector<TVector<T>> &A);
	TMatrix<T> operator+(TMatrix<T> &A);
	TMatrix<T> operator-(TMatrix<T> &A);
	TMatrix<T> operator*(TMatrix<T> &A);
	TMatrix<T>& operator=(TMatrix<T> &A);
	TMatrix<T>& operator==(TMatrix<T> &A);
	template <class T>
	friend std::istream& operator>>(std::istream& A, TMatrix<T>& B);
	template <class T>
	friend std::ostream& operator<<(std::ostream& A, TMatrix<T>& B);
};
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(int = 0)
{
	vector = 0;
	length = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(TMatrix &A)
{
	length = A.length;
	int n = length * (length + 1) / 2;
	if (length != 0)
	{
		vector = new T[length];
		for (int i = 0; i < n; i++)
			vector[i] = A.vector[i];
	}
	else
		vector = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(TVector<TVector<T>> &A)
{
	
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator+(TMatrix<T> &A)
{
	TMatrix<T> S;
	if (length == A.length)
	{
		if (length == 0)
			S.vector = 0;
		else
		{
			S.length = length;
			int n = length * (length + 1) / 2;
			S.vector = new T[n];
			for (int i = 0; i < n; i++)
				S.vector[i] = vector[i] + A.vector[i];
		}
	}
	else
		throw 1;
	return S;
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator-(TMatrix<T> &A)
{
	TMatrix<T> S;
	if (length == A.length)
	{
		if (length == 0)
			S.vector = 0;
		else
		{
			S.length = length;
			int n = length * (length + 1) / 2;
			S.vector = new T[n];
			for (int i = 0; i < n; i++)
				S.vector[i] = vector[i] - A.vector[i];
		}
	}
	else
		throw 1;
	return S;
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>  TMatrix<T>::operator*(TMatrix<T> &A)
{
	
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator=(TMatrix<T> &A)
{
	if (this != &A)
	{
		length = A.length;
		if (length != 0)
		{
			if (vector != 0)
				delete[]vector;
			int n = length * (length + 1) / 2;
			vector = new T[n];
			for (int i = 0; i < n; i++)
				vector[i] = A.vector[i];
		}
		else
		{
			if (vector != 0)
				delete[]vector;
			vector = 0;
		}
	}
	return *this;
}
// ---------------------------------------------------------------------------
template <class T>
std::istream& operator>>(std::istream &A, TMatrix<T> &B)
{
	A >> B.length;
	int n = length * (length + 1) / 2;
	B.vector = new T[n];
	for (int i = 0; i < n; i++)
	{
		A >> B.vector[i];
	}
	return A;
}
// ---------------------------------------------------------------------------
template <class T>
std::ostream& operator<<(std::ostream &A, TMatrix<T> &B)
{
	A << B.length << "\n";
	int n = length * (length + 1) / 2;
	for (int i = 0; i < n; i++)
		A << B.vector[i] << "\n";
	return A;
}
// ---------------------------------------------------------------------------
