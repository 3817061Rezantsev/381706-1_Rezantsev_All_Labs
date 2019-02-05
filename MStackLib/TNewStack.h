#pragma once
#include "../StackLib/TStack.h"
#include "../Exception/Exception.h"

template <class T>
class TNewStack :public TStack<T> {
public:
	TNewStack(int _size, T* mas);
	TNewStack(TNewStack <T> &A);
	int CountFree();
	int GetSize();
	int GetTop();
	void SetMas(int _size, T* mas);
};
template <class T>
TNewStack<T>::TNewStack(int _size, T* mas) : TStack<T>(_size)
{
	if (_size <= 0)
		throw TException("Error. Negative size");
	TStack<T>::size = _size;
	TStack<T>::r = 0;
	if (mas == 0) TStack<T>::m = 0;
	else
		TStack<T>::m = mas;
}
//------------------------------------------------------------------------------------------------
template <class T>
TNewStack<T>::TNewStack(TNewStack <T> &A) : TStack<T>(A)
{
	TStack<T>::size = A.TStack<T>::size;
	TStack<T>::r = A.TStack<T>::r;
	TStack<T>::m = A.TStack<T>::m;
}
//-------------------------------------------------------------------------------------------------
template <class T>
int TNewStack<T>::CountFree()
{
	return (TStack<T>::size - TStack<T>::r);
}
	//-------------------------------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetSize()
{
	return TStack<T>::size;
}
//-------------------------------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetTop()
{
	return TStack<T>::r;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TNewStack<T>::SetMas(int _size, T* mas)
{
	if (_size <= 0)
		throw TException("Error. Negative size");
	TStack<T>::size = _size;
	TStack<T>::m = mas;
}