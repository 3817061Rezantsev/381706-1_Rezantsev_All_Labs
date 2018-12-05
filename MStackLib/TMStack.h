#pragma once
#include "TNewStack.h"

template <class T>
class TMStack {
protected:
	int size;
	T* mas;
	int n;
	TNewStack<T>** h;
	
public:
	int GetFreeMem();
	void Repack();
	TMStack(int _n, int _size);
	int GetSize() { return size; }
	TMStack(TMStack<T> &A); // конструктор копирования
	void Set(int _n, T p); // положить в стек номер _n данные p
	T Get(int _n); // взять из стека номер _n
	bool isFull(int _n); // если стек заполнен = true
	bool isEmrty(int _n); // если стек пустой = true
};

template <class T>
TMStack<T> ::TMStack(int _n, int _size)
{
	if (_n <= 0 || _size <= 0) throw -1;
	n = _n;
	size = _size;
	h = new TNewStack<T>*[n];
	mas = new T[size];
	int* p;
	p = new int[n];
	p[0] = (size / n) + (size%n);
	for (int i = 0; i < n; i++)
		p[i] = size / n;
	h[0] = new TNewStack<T>(p[0], &mas[0]);
	for (int i = 0; i < n; i++)
		h[i] = new TNewStack<T>(p[i], &mas[p[0] + (i - 1)*(size / n)]);
}

template <class T>
TMStack<T> ::TMStack(TMStack &A)
{
	int sizeST = 0; // сюда кидаем количество размеров пришедших массивов
	size = A.size;
	n = A.n;
	mas = new T[size];
	n = new TNewStack<T>*[n];
	for (int i = 0; i < n; i++) // копируем данные общего массива
		mas[i] = A.mas[i];

	int* p = new int[n]; // для размеров массив
	for (int i = 0; i < n; i++)
		p[i] = A.h[i]->GetSize();
	h[0] = new TNewStack<T>(*A.h[0]);
	for (int i = 1; i < n; i++)
	{
		n[i] = new TNewStack<T>(*A.h[i]);
		h[i]->SetMas(p[i], &mas[-p[0] + sizeST]);
		sizeST += p[i - 1];
	}
}
template <class T>
int TMStack<T>::GetFreeMem()
{
	int count = 0;
	for (int i = 0;i < n;i++)
	{
		count += m[i]->GetFreeMem();
	}
	return count;
}
template <class T>
void TMStack<T>::Set(int _n, T p)
{
	if (IsFull())
		repack();
	else
		m[i]->Set(p);
}
template <class T>
T TMStack<T>::Get(int _n)
{
	if ((_n >= 0) && (_n <= n))
		return m[_n]->Get();
	else
		throw 1;
}
