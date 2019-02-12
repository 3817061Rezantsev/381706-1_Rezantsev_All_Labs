#pragma once
#include <iostream>
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
    throw - 1;
  else if (n == 0)
  {
    size = 0;
    r = 0;
    m = NULL;
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
    m = NULL;
  else
  {
    m = new T[size];
    for (int i = 0; i < size; r++)
      m[i] = A.m[i];
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TStack<T>::Put(T A)
{
  if (IsFull())
    throw 0;
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
    throw 1;
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
  if (((r >= size) && (size != 0)) || (size == 0))
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