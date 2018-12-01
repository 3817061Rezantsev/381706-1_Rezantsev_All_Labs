#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../VectorLib/TVector.h"
using namespace std;
template <class T>
class TMatrix: public TVector<T>
{
public:
	TMatrix();
	TMatrix(int a);
	TMatrix(TMatrix &A);
	T& element(int i, int j);
	TMatrix(const TVector<TVector<T>> &A);
	TMatrix<T> operator+(TMatrix<T> &A);
	TMatrix<T> operator-(TMatrix<T> &A);
	TMatrix<T> operator*(TMatrix<T> &A);
	TMatrix<T>& operator=(TMatrix<T> &A);
	bool operator==(const TMatrix &A);
	template <class T>
	friend std::istream& operator>>(std::istream& A, TVector<T>& B);
	template <class T>
	friend std::ostream& operator<<(std::ostream& A, TVector<T>& B);
	};
template <class T>
TMatrix<T>::TMatrix()
{
	vector = 0;
	length = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(int a)
{
	length = a;
	if (length != 0)
	{
		int n = length * (length + 1) / 2;
		vector = new T[n];
		for (int i = 0; i < n; i++)
			vector[i] = 0;
	}
}
// ---------------------------------------------------------------------------

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
T& TMatrix<T>::element(int i, int j) 
{
	if ((i > j) || (i >= length) || (j >= length) || (i < 0) || (j < 0))	
	return vector[i*length - i * (i - 1) / 2 + (j - i)];
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T>> &A) :
	TVector<TVector<T>>(mt) {}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator+(TMatrix<T> &A)
{
	TMatrix<T>* S = new TMatrix<T>(A.GetLength());
	int n = A.GetLength() * (A.GetLength() + 1) / 2;
	for (int i = 0; i < n; i++)
	{
		T a = GetValue(i) + A.GetValue(i);
		S->SetValue(i, a);
	}
	
	return *S;
}
// ---------------------------------------------------------------------------
template <class T> 
bool TMatrix<T>::operator==(const TMatrix<T> &A) 
{
	if (length != A.length)
		return false;
	int f = 0;
	int n = length * (length + 1) / 2;
	for (int i = 0; i < n; i++)
		if (vector[i] != A.vector[i])
			f = 1;
	if (f == 1)
		return false;
	return true;
} 
//-----------------------------------------------------------------------------
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
	TMatrix<T> result(length);
	for (int i = 0; i < length; ++i)
	{
		for (int j = i; j < length; ++j)
		{
			int sum = 0;
			for (int k = i; k <= j; k++)
			{
				sum += element(i, k)*A.element(k, j);
			}
			result.element(i, j) = sum;
		}
	}
	return result;
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator=(TMatrix<T> &A)
{
	if (this != &A)
	{
		length = A.GetLength();
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
	A >> B.GetLength();
	int n = B.GetLength() * (B.GetLength() + 1) / 2;
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
	int a = B.GetLength();
	printf("%d", a);
	A << "\n";
	int n = B.GetLength() * (B.GetLength() + 1) / 2;
	for (int i = 0; i < n; i++)
	{
		int b = B.GetValue(i);
		cout << b << "\t";
	}
		A << "\n";	
	return A;
}
// ---------------------------------------------------------------------------