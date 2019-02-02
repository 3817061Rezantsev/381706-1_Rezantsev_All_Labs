#pragma once
#include <iostream>
#include "../Exception/Exception.h"
#include "TStack.h"
using namespace std;
template <class T>
class TQueue :public TStack<T>
{
protected:
	int start;
	int count;
public:
	TQueue(int n);
	TQueue(TQueue<T> &A);
	void Put(T A);
	T Get();
	bool IsFull();
	bool IsEmpty();
};
//-------------------------------------------------------------------------------------------------
template <class T>
bool TQueue<T>::IsEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TQueue<T>::IsFull()
{
	if (count == size)
		return true;
	else
		return false;
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TQueue<T>::Get()
{
	if (IsEmpty())
		throw TException("Error.Queue is empty");
	else 
	{
		T res = m[start];
		start++;
		count--;
		if (start > size - 1)
			start = 0;
		return res;
	}

}
//-------------------------------------------------------------------------------------------------
template <class T>
TQueue<T>::TQueue(int n) : TStack(n)
{
	if (n < 0)
		throw TException("Error. Wrong size");
	else if (n == 0)
	{
		start = 0;
		size = 0;
		count = 0;
		r = 0;
		m = 0;
	}
	if (n > 0)
	{
		start = 0;
		count = 0;
		size = n;
		m = new T[size];
		for (int i = 0; i < size; i++)
			m[i] = 0;
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
TQueue<T>::TQueue(TQueue<T> &A)
{
	start = A.start;
	count = A.count;
	r = A.r;
	if (size == 0)
		m = 0;
	else
	{
		m = new T[size];
		for (int i = 0; i < size;i++)
			m[i] = A.m[i];
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TQueue<T>::Put(T A)
{
	if (IsFull())
		throw TException("Error. Queue is full.");
	else 
	{
		m[r++] = A;
		count++;
		if (r > size - 1)
			r = 0;
	}
}
