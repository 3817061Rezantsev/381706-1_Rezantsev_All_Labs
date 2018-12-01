#include <iostream>
using namespace std;
template <class T>
class TStak
{
private:
	int size;
	int r;
	T* m;
public:
	TStak(int n);
	TStak(TStak<T> &A);
	void Put(T A);
	T Get();
	bool IsFull();
	bool IsEmply();
};
template <class T>
TStak<T>::TStak(int n)
{
	if (n < 0)
		throw -1;
	else if (n = 0)
	{
		size = 0;
		r = 0;
		m = NULL;
	}
	else
	{
		r = 0;
		size = n;
		m = new T[size];
	}
}
template <class T>
TStak<T>::TStak(TStak<T> &A)
{
	size = A.size;
	r = A.r;
	if (size == 0)
		m = NULL;
	else
	{
		m = new T[size];
		for (int i = 0; i < size; r++)
			m[i] = A.m[i];
	}
}
template <class T>
void TStak<T>::Put(T A)
{
	if (IsFull())
		throw 0;
	else
	{
		m[r] = A;
		r++;
	}
}
template <class T>
T TStak<T>::Get()
{
	if (IsEmply())
		throw 1;
	else
	{
		r--;
		return m[r];
	}
}
template <class T>
bool TStak<T>::IsFull()
{
	if ((r >= size)&&(size!=0))
		return true;
	else
		return false;
}
template <class T>
bool TStak<T>::IsEmply()
{
	if (r == 0)
		return true;
	else
		return false;
}