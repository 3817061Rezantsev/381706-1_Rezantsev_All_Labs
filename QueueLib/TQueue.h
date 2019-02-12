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
  TQueue(int n);
  TQueue(TQueue<T> &A);
  virtual ~TQueue();
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
TQueue<T>::TQueue(TQueue<T> &A) : TStack<T>(A)
{
  start = A.start;
  count = A.count;
  this->size = A.size;
  this->r = A.r;
  if (this->size == 0)
    this->m = 0;
  else
  {
    this->m = new T[this->size];
    for (int i = 0; i < this->size;i++)
      this->m[i] = A.m[i];
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
    this->m[this->r++] = A;
    count++;
    if (this->r > this->size - 1)
      this->r = 0;
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
TQueue<T>::~TQueue()
{}