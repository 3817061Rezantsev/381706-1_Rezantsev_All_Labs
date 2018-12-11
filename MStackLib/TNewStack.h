#pragma once
#include "..\StackLib\TStack.h"


template <class T>
class TNewStack :public TStack<T> {
public:
	TNewStack(int _size = 0, T* mas = 0) : TStack(_size)
	{
		TStack<T>::size = _size;
		TStack<T>::r = 0;
		if (mas == 0) TStack<T>::m = 0;
		else
			TStack<T>::m = mas;
	}
	//-------------------------------------------------------------------------------------------------
	TNewStack(TNewStack <T> &A) : TStack(A)
	{
		TStack<T>::size = A.TStack<T>::size;
		TStack<T>::r = A.TStack<T>::r;
		if (A.TStack<T>::m == 0) TStack<T>::m = 0;
		else
			TStack<T>::m = A.TStack<T>::m;
	}
	//-------------------------------------------------------------------------------------------------
	int CountFree()
	{
		return (TStack<T>::size - TStack<T>::r);
	}
	//-------------------------------------------------------------------------------------------------
	int GetSize()
	{
		return TStack<T>::size;
	}
	//-------------------------------------------------------------------------------------------------
	int GetTop()
	{
		return TStack<T>::r;
	}
	//-------------------------------------------------------------------------------------------------
	void SetMas(int _size, T* mas)
	{
		TStack<T>::size = _size;
		TStack<T>::m = mas;
	}
};