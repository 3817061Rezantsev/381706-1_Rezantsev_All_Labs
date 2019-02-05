#pragma once
#include <iostream>
#include "../Exception/Exception.h"
using namespace std;
template <class T>
class TStack
{
protected:
	int size;
	int r;
	T* m;
public:
	TStack(int n);
	TStack(TStack<T> &A);
	void Put(T A);
	T Get();
	bool IsFull();
	bool IsEmply();
};
//-------------------------------------------------------------------------------------------------
template <class T>
TStack<T>::TStack(int n)
{
	if (n < 0)
		throw TException("Error. Negative size.");
	else if (n == 0)
	{
		size = 0;
		r = 0;
		m = 0;
	}
	if (n > 0)
	{
		r = 0;
		size = n;
		m = new T[size];
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
TStack<T>::TStack(TStack<T> &A)
{
	size = A.size;
	r = A.r;
	if (size == 0)
		m = 0;
	else
	{
		m = new T[size];
		if (A.m != 0)
			for (int i = 0; i < size; i++)
				m[i] = A.m[i];
		else
			m = 0;
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TStack<T>::Put(T A)
{
	if (IsFull())
		throw TException("Error. Stack is full");
	else
	{
		m[r] = A;
		r++;
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TStack<T>::Get()
{
	if (IsEmply())
		throw TException("Error.Stack is empty");
	else
	{
		r--;
		return m[r];
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TStack<T>::IsFull()
{
	if (((r >= size)&&(size!=0))||(size == 0))
		return true;
	else
		return false;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TStack<T>::IsEmply()
{
	if (r == 0)
		return true;
	else
		return false;
}