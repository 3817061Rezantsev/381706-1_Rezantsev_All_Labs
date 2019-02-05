#pragma once
#include "TNewStack.h"
#include "../Exception/Exception.h"
template <class T>
class TMStack {
protected:
	int size;
	T* mas;
	int n;
	TNewStack<T>** ns;
	int GetFreeMem();
	void Repack(int k);
public:
	TMStack(int _size, int _n);
	TMStack(TMStack<T> &MS);
	void Put(int _n, T A);
	T Get(int _n);
	bool IsFull(int _n);
	bool IsEmpty(int _n);
	void Print();
};
//-------------------------------------------------------------------------------------------------
template <class T>
TMStack<T>::TMStack(int _size, int _n)
{
	if ((_n <= 0) || (_size <= 0))
	{
		throw TException("Error. Negative info");
	}
	n = _n;
	size = _size;
	mas = new T[size];
	for (int i = 0;i < size;i++)
	{
		mas[i] = 0;
	}
	ns = new TNewStack<T>*[n];

	int* p = new int[n]; 
	p[0] = (int(double(size) / n) + (size % n));
	for (int i = 1; i < n; i++)
		p[i] = int(double(size) / n);
	ns[0] = new TNewStack<T>(p[0], &mas[0]);
	for (int i = 1; i < n; i++)
		ns[i] = new TNewStack<T>(p[i], &mas[p[0] + (i - 1) * p[i]]);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMStack<T>::TMStack(TMStack<T> &MS)
{
	size = MS.size;
	n = MS.n;
	mas = new T[size];
	ns = new TNewStack<T>*[n];
	for (int i = 0; i < size; i++)
		mas[i] = MS.mas[i];
	int* p = new int[n];
	for (int i = 0; i < n; i++)
		p[i] = MS.ns[i]->TNewStack<T>::GetSize();
	int sizeCounter = 0;
	ns[0] = new TNewStack<T>(*(MS.ns[0]));
	ns[0]->TNewStack<T>::SetMas(p[0], mas);
	for (int i = 1; i < n; i++)
	{
		ns[i] = new TNewStack<T>(*(MS.ns[i]));
		ns[i]->TNewStack<T>::SetMas(p[i], &mas[p[0] + sizeCounter]);
		sizeCounter += p[i];
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
int TMStack<T>::GetFreeMem()
{
	int count = 0;
	for (int i = 0; i < n; i++)
		count += ns[i]->CountFree();
	return count;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TMStack<T>::Repack(int k)
{
	int freeMem = GetFreeMem();
	if (freeMem == 0)
	{
		throw TException("Error. Negative info");
	}
	int addEvery = int(double(freeMem) / n);
	int addFull = freeMem % n;
	int* newSize = new int[n];
	T** oldStart = new T*[n];
	T** newStart = new T*[n];
	for (int i = 0; i < n; i++)
		newSize[i] = addEvery + ns[i]->TNewStack<T>::GetTop();
	newSize[k] += addFull;
	newStart[0] = oldStart[0] = mas;
	for (int i = 1; i < n; i++)
	{
		newStart[i] = newStart[i - 1] + newSize[i - 1];
		oldStart[i] = oldStart[i - 1] + ns[i - 1]->TNewStack<T>::GetSize();
	}
	for (int i = 0; i < n; i++)
	{
		if (newStart[i] <= oldStart[i])
			for (int j = 0; j < ns[i]->TNewStack<T>::GetTop(); j++)
				newStart[i][j] = oldStart[i][j];
		else
		{
			int s = i + 1;
			for (; s < n; s++)
				if (newStart[s] <= oldStart[s])
					break;
			for (int j = s - 1; j >= i; j--)
				for (int r = ns[i]->TNewStack<T>::GetTop() - 1; r >= 0; r--)
					newStart[j][r] = oldStart[j][r];
			i = s - 1; 
		}
	}
	for (int i = 0; i < n; i++)
		ns[i]->TNewStack<T>::SetMas(newSize[i], newStart[i]);
	delete[] newSize;
	delete[] newStart;
	delete[] oldStart;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TMStack<T>::Put(int _n, T A)
{
	if ((_n < 0) || (_n >= size))
		throw TException("Error. Negative index");
	if (IsFull(_n)) 
		Repack(_n);
	ns[_n]->TStack<T>::Put(A);
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TMStack<T>::Get(int _n)
{
	if (_n >= 0 && _n < n)
		return (ns[_n]->TStack<T>::Get());
	else
	{
		throw 0;
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMStack<T>::IsFull(int _n)
{
	if (_n < 0 || _n >= size)
	{
		throw TException("Error. Negative info");
	}
	return ns[_n]->TStack<T>::IsFull();
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMStack<T>::IsEmpty(int _n)
{
	if (_n < 0 || _n >= size)
	{	
		throw TException("Error. Negative info");
	}
	return ns[_n]->TStack<T>::IsEmply();
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TMStack<T>::Print()
{
	for (int i = 0; i < size; i++)
		std::cout << i << " " << TMStack<T>::mas[i] << std::endl;
	std::cout << std::endl;
}