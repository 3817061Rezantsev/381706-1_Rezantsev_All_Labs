#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Exception/Exception.h"
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
	TMatrix operator/(TMatrix<T> &A);
	TVector<T>& operator [] (int i);
	template <class FriendT> friend istream& operator>>(istream &in, TMatrix<FriendT> &B);

	template <class FriendT> friend ostream & operator<<(ostream &out, const TMatrix<FriendT> &B);

};
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(int n) : TVector<TVector<T>>(n)
{
	int a = MAX_SIZE;
	if (n < 0 || n > a)
		throw TException("Overflow");
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
		throw TException("Different dimensions.");
	else
		return TVector<TVector<T>> :: operator+(B);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &B)
{
	if (this->size != B.size)
		throw TException("Different dimensions.");
	else
		return TVector<TVector<T>> :: operator-(B);
}

template <class T>
TMatrix<T>  TMatrix<T>::operator*(TMatrix<T> &A)
{
	if (this->size != A.size)
		throw TException("Error! Differen dimentions.");

	int _size = this->size;
	TMatrix <T> result(_size);
	for (int i = 0; i < _size; i++) 
		for (int j = i; j < _size; j++) 
		{
			for (int k = i; k <= j; k++)
				result.vector[i][j - i] += this->vector[i][k - i] * A.vector[k][j - k];
		}
	return result;
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
template <class T>
TMatrix<T> TMatrix<T>::operator/(TMatrix<T> &A)
{
	if (this->size != A.size)
		throw TException("Different dimentions");
	int N = (*this).size;

	double detChecking = 1;

	for (int i = 0; i < N; i++)
		detChecking *= (*this).vector[i][0];

	if (detChecking < 0.000001)
		throw TException("Cannot work with matrixes that have det = 0");

	TMatrix <T> replicaMatr(A);
	TMatrix <T> middleStepMatr(N);

	for (int i = 0; i < N; i++)
	{
		middleStepMatr[i][0] = 1;
		T k = replicaMatr[i][0];
		for (int j = 0; j < N - i; j++)
		{
			replicaMatr[i][j] = replicaMatr[i][j] / k;
			middleStepMatr[i][j] = middleStepMatr[i][j] / k;
		}
	}

	for (int j = 1; j < N; j++)
	{
		for (int i = 0; i < j; i++)
		{
			T temporary = replicaMatr[i][j - i];
			for (int k = j - i, c = 0; k < N - i; k++)
			{
				replicaMatr[i][k] = replicaMatr[i][k] - replicaMatr[j][c] * temporary;
				middleStepMatr[i][k] = middleStepMatr[i][k] - middleStepMatr[j][c++] * temporary;
			}
		}
	}
	return ((*this) * middleStepMatr);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T>& TMatrix<T>::operator[](int i)
{
	if (i >= 0)
		if (i < this->size)
			return this->vector[i];
		else throw 1;
	else throw - 1;
}
//-------------------------------------------------------------------------------------------------
