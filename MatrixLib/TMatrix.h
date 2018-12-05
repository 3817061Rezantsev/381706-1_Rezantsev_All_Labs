#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../VectorLib/TVector.h"
using namespace std;
#define MAX_SIZE 10000;
template <class T>
class TMatrix : public TVector<TVector<T>>
{
public:
	TMatrix(int n = 10);
	TMatrix(const TMatrix &B);
	TMatrix(const TVector<TVector<T>> &B);
	bool operator==(const TMatrix &B) const;
	bool operator!=(const TMatrix &B) const;
	TMatrix& operator= (TVector<TVector<T>> &B);
	TMatrix  operator+ (const TMatrix &B);
	TMatrix  operator- (const TMatrix &B);
	TMatrix operator*(TMatrix<T> &A);

	template <class FriendT> friend istream& operator>>(istream &in, TMatrix<FriendT> &B);

	template <class FriendT> friend ostream & operator<<(ostream &out, const TMatrix<FriendT> &B);

};
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(int n) : TVector<TVector<T>>(n)
{
	int a = MAX_SIZE;
	if (n < 0 || n > a)
		throw -1;
	else
		for (int i = 0; i < n; i++)
			this->vector[i] = TVector <T>(n - i);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &B) : TVector<TVector<T>>(B) {}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T>> &B) : TVector<TVector<T>>(B) {}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &B) const
{
	return TVector<TVector<T>>::operator==(B);
}
//-------------------------------------------------------------------------------------------------

template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &B) const
{
	return TVector<TVector<T>>::operator!=(B);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator=(TVector<TVector<T>> &B)
{
	TVector<TVector<T>>::operator=(B);
	return *this;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &B)
{
	if (this->size != B.size)
		throw 0;
	else
		return TVector<TVector<T>> :: operator+(B);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &B)
{
	if (this->size != B.size)
		throw 0;
	else
		return TVector<TVector<T>> :: operator-(B);
}

template <class T>
TMatrix<T>  TMatrix<T>::operator*(TMatrix<T> &A)
{
	if (size == A.size)
	{
		TMatrix<T> B = *this;
		TMatrix<T> result(size);
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size - i; ++j)
			{
				int sum = 0;
				int f = j;
				for (int k = 0; k <= j; k++)
				{
					
					sum += B[i][k]*A[k][f];
					f--;
				}	
				result[i][j] = sum;
			}
		}
		return result;
	}
	else
		throw 0;
}

//-------------------------------------------------------------------------------------------------
template <class FriendT>  istream& operator>>(istream &in, TMatrix<FriendT> &B)
{
	for (int i = 0; i < B.size; i++)
		in >> B.vector[i];
	return in;
}
//-------------------------------------------------------------------------------------------------
template <class FriendT>  ostream & operator<<(ostream &out, const TMatrix<FriendT> &B)
{
	for (int i = 0; i < B.size; i++)
	{
		for (int j = 0; j < i; j++)
			out << "\t";
		out << B.vector[i] << endl;
	
	}
		return out;	
}
//-------------------------------------------------------------------------------------------------