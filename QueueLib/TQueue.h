#pragma once
#include <iostream>
#include "../Exception/Exception.h"
#include "../StackLib/TStack.h"
using namespace std;
template <class T>
class TQueue :public TStack<T>
{
protected:
	int start;
	int count;
public:
  TQueue();
	TQueue(int n);
	TQueue(TQueue<T> &A);
	void Put(T A);
	T Get();
	T Top();
	bool IsFull();
	bool IsEmpty();
	void Print();
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
	if (count == this->size)
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
		T res = this->m[start];
		start++;
		count--;
		if (start > this->size - 1)
			start = 0;
		return res;
	}

}
//-------------------------------------------------------------------------------------------------
template <class T>
TQueue<T>::TQueue(int n) : TStack<T>(n)
{
	if (n < 0)
		throw TException("Error. Wrong size");
	else if (n == 0)
	{
		start = 0;
		this->size = 0;
		count = 0;
		this->r = 0;
		this->m = 0;
	}
	if (n > 0)
	{
		start = 0;
		count = 0;
		this->size = n;
		this->m = new T[this->size];
		for (int i = 0; i < this->size; i++)
			this->m[i] = 0;
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
TQueue<T>::TQueue(TQueue<T> &q) : TStack<T>(q)
{
	start = q.start;
	count = q.count;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TQueue<T>::Put(T A)
{
	if (IsFull())
		throw TException("Error. Queue is full.");
	else 
	{
		this->m[this->r++] = A;
		count++;
		if (this->r > this->size - 1)
			this->r = 0;
	}
}
//-------------------------------------------------------------------------------------------------
template<class T>
void TQueue<T>::Print()
{
	for (int i = start; i < TStack<T>::r; i = (i + 1) % TStack<T>::size)
		cout << TStack<T>::m[i];
}
//-------------------------------------------------------------------------------------------------
template<class T>
inline T TQueue<T>::Top()
{
	return TStack<T>::m[start];
}
//-------------------------------------------------------------------------------------------------
template <class T>
TQueue<T>::TQueue() : TStack<T>(0)
{
  start = 0;
  count = 0;
}
//-------------------------------------------------------------------------------------------------