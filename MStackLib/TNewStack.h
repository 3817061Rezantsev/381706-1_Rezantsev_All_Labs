#pragma once
template <class T>
class TNewStack {
	int size;
	T* top;
	T* mas;
public:
	TNewStack(int n, T* m)
	{
		size = n;
		top = 0;
		mas = m;
	}
	TNewStack(TNewStack &A)
	{
		size = A.size;
		top = A.top;
		mas = A.mas;
	}
	int Free()
	{
		return size - top;
	}
	void SetMas(int n, T* m)
	{
		size = n;
		mas = m;
	}
};