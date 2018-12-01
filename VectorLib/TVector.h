#pragma once
#include <iostream>
#include <math.h>
template <class T>
class TVector
{
protected:
	T* vector;
	int length;
public:
	TVector();
	TVector(TVector &A);
	TVector(T* s, int _length);
	
	int GetLength();
	T& GetValue(int i);
	void SetValue(int i, T a);
	TVector<T> operator+(TVector<T> &A);
	TVector<T> operator-(TVector<T> &A);
	T operator*(TVector<T> &A);
	TVector<T> operator*(T a);
	TVector<T> operator+(T a);
	TVector<T> operator-(T a);
	TVector<T>& operator=(TVector<T> &A);
	int operator==(TVector<T> &A);
	T& operator[](int i);
	template <class T>
	friend std::istream& operator>>(std::istream& A, TVector<T>& B);
	template <class T>
	friend std::ostream& operator<<(std::ostream& A, TVector<T>& B);
};
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector()
{
	vector = 0;
	length = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(TVector &A)
{
	length = A.length;
	if (length != 0)
	{
		vector = new T[length];
		for (int i = 0; i < length; i++)
			vector[i] = A.vector[i];
	}
	else
		vector = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(T* s, int _length)
{
	length = _length;
	vector = new T[length];
	for (int i = 0; i < length; i++)
		vector[i] = s[i];
}
// ---------------------------------------------------------------------------
template <class T>
void TVector<T>::SetValue(int i, T a)
{
	vector[i] = a;
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
template <class T>
int TVector<T>::GetLength()
{
	return length;
}
// ---------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator+(T a)
{
	vector[0] = vector[0] + a;
	return vector;
}
// ---------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator-(T a)
{
	vector[0] = vector[0] - a;
	return vector;
}
// ---------------------------------------------------------------------------

template <class T>
TVector<T> TVector<T>::operator+(TVector<T> &A)
{
	TVector<T> S;
	if (length == A.length)
	{
		if (length == 0)
			S.vector = 0;
		else
		{
			S.length = length;
			S.vector = new T[length];
			for (int i = 0; i < length; i++)
				S.vector[i] = vector[i] + A.vector[i];
		}
	}
	else
		throw 1;
	return S;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator-(TVector<T> &A)
{
	TVector<T> S;
	if (length == A.length)
	{
		if (length == 0)
			S.vector = 0;
		else
		{
			S.length = length;
			S.vector = new T[length];
			for (int i = 0; i < length; i++)
				S.vector[i] = vector[i] - A.vector[i];
		}
	}
	else
		throw 1;
	return S;
}
// ---------------------------------------------------------------------------
template <class T>
T TVector<T>::operator*(TVector<T> &A)
{
	T summ = 0;
	if (length == A.length)
	{
		if (length == 0)
			return summ;
		else
		{
			for (int i = 0; i < length; i++)
				summ += vector[i] * A.vector[i];
		}
	}
	else
		throw 1;
	return summ;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator*(T a)
{
	TVector<T> S;
	if (length == 0)
		S.vector = 0;
	else
	{
		S.length = length;
		S.vector = new T[length];
		for (int i = 0; i < length; i++)
			S.vector[i] = vector[i] * a;
	}
	return S;
}
// ---------------------------------------------------------------------------
template <class T>
int TVector<T>::operator==(TVector<T> &A)
{
	int res = 1;
	if (length != A.length)
		res = 0;
	else for (int i = 0; i < length;i++)
	{
		if (vector[i] != A.vector[i])
		{
			res = 0;
			break;
		}
	}
	return res;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator=(TVector<T> &A)
{
	if (this != &A)
	{
		length = A.length;
		if (length != 0)
		{
			if (vector != 0)
				delete[]vector;
			vector = new T[length];
			for (int i = 0; i < length; i++)
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
T& TVector<T>::GetValue(int i)
{
	return vector[i];
	throw 1;
}
// ---------------------------------------------------------------------------
template <class T>
T& TVector<T>::operator[](int i)
{
	if (i >= 0 && i <= length)
		return vector[i];
	throw 1;
}
// ---------------------------------------------------------------------------
template <class T>
std::istream& operator>>(std::istream &A, TVector<T> &B)
{
	A >> B.length;
	B.vector = new T[B.length];
	for (int i = 0; i < B.length; i++)
	{
		A >> B.vector[i];
	}
	return A;
}
// ---------------------------------------------------------------------------
template <class T>
std::ostream& operator<<(std::ostream &A, TVector<T> &B)
{
	A << B.length << "\n";
	for (int i = 0; i < B.length; i++)
		A << B.vector[i] << "\n";
	return A;
}
// ---------------------------------------------------------------------------