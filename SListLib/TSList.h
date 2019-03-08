#pragma once
#include <iostream>
#include "../ListLib/TList.h"
#include "../Exception/Exception.h"
using namespace std;
template <class T>
class TSList : public TList<T>
{
protected:
  int size;
public:
  TSList<T>(int _size = 10);
  TSList<T>(TSList<T> &A);
  ~TSList();
  void Put(T A);
  T Get();
  int GetMaxSize();
  int GetSize();
  bool IsEmpty();
  bool IsFull();
};

template <class T>
TSList<T>::TSList(int _size) : TList<T>()
{
  if (_size <= 0)
    throw TException("Error. Wrong size");
  size = _size;
}
//-----------------------------------------------------------------
template <class T>
TSList<T>::TSList(TSList<T> &A) : TList<T>(A)
{}
//-----------------------------------------------------------------
template<class T>
TSList<T>::~TSList()
{}
//-----------------------------------------------------------------
template <class T>
void TSList<T>::Put(T A)
{
  if (this->IsFull())
    throw TException("Error. SList is Full");
  TList<T>::PutBegin(A);
}
//-----------------------------------------------------------------
template <class T>
T TSList<T>::Get()
{
  if (this->IsEmpty())
    throw TException("Error. SList is Empty");
  return TList<T>::GetBegin();
}
//-----------------------------------------------------------------
template <class T>
int TSList<T>::GetMaxSize()
{
  return size;
}
//-----------------------------------------------------------------
template<class T>
inline int TSList<T>::GetSize()
{
  return TList<T>::GetSize();
}//-----------------------------------------------------------------

template <class T>
bool TSList<T>::IsEmpty()
{
  if (TList<T>::GetSize() == 0)
    return true;
  return false;
}
//-----------------------------------------------------------------
template<class T>
bool TSList<T>::IsFull()
{
  if (TList<T>::GetSize() == size)
    return true;
  return false;
}
//-----------------------------------------------------------------
