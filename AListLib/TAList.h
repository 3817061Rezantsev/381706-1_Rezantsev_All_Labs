#pragma once
#include "../QueueLib/TQueue.h"
#include "../Exception/Exception.h"
template <class T>
class TAList
{
private:
  T* mas;
  int *nextIndex;
  int *prevIndex;
  int size;
  int count;
  int start;
  int end;
  TQueue <int> freeElem;
public:
  TAList(int _size = 10);
  TAList(TAList<T> &A);
  ~TAList();
  void Put(int n, T elem);
  T Get(int n);
  void PutStart(T elem);
  void PutEnd(T elem);
  T GetStart();
  T GetEnd();
  bool IsFull();
  bool IsEmpty();
  void Print();
};

template <class T>
TAList<T>::TAList(int _size) : freeElem(_size)
{
  if (_size <= 0)
    throw TException("Error. False size list");
  size = _size;
  count = 0;
  start = -1;
  end = -1;
  mas = new T[size];
  nextIndex = new int[size];
  prevIndex = new int[size];
  for (int i = 0; i < size; i++)
  {
    nextIndex[i] = -2;
    prevIndex[i] = -2;
    freeElem.Put(i);
  }
}
//-------------------------------------------------------------------------------------------------

template <class T>
TAList<T>::TAList(TAList<T> &A)
{
  start = A.start;
  end = A.end;
  size = A.size;
  count = A.count;
  mas = new T[size];
  nextIndex = new int[size];
  prevIndex = new int[size];
  freeElem = A.freeElem;
  for (int i = 0; i < size; i++)
  {
    mas[i] = A.mas[i];
    nextIndex[i] = A.nextIndex[i];
    prevIndex[i] = A.prevIndex[i];
  }
}
//-------------------------------------------------------------------------------------------------

template<class T>
inline TAList<T>::~TAList()
{
  if (mas != 0)
    delete[] mas;
  if (nextIndex != 0)
    delete[] nextIndex;
  if (prevIndex != 0)
    delete[] prevIndex;
}
//-------------------------------------------------------------------------------------------------

template<class T>
void TAList<T>::Put(int n, T elem)
{
  if (IsFull())
    throw TException("Error. List is full");
  if (n < 1 || n > count - 1)
    throw TException("Error. Uncurrent index");
  int ifree = freeElem.Get();
  mas[ifree] = elem;
  int one = start;
  int two = nextIndex[start];
  for (int i = 0; i < n - 1; i++)
  {
    one = two;
    two = nextIndex[two];
  }
  nextIndex[ifree] = two;
  nextIndex[one] = ifree;

  prevIndex[ifree] = one;
  prevIndex[two] = ifree;
  count++;
}
//-------------------------------------------------------------------------------------------------

template<class T>
T TAList<T>::Get(int n)
{
  if (IsEmpty())
    throw TException("Error. List is empty");
  if (n < 1 || n > count - 1)
    throw TException("Error. Uncurrent index");
  int ind = start;
  for (int i = 0; i < n; i++)
    ind = nextIndex[ind];
  nextIndex[prevIndex[ind]] = nextIndex[ind];
  prevIndex[nextIndex[ind]] = prevIndex[ind];
  T temp = mas[ind];
  freeElem.Put(ind);
  count--;
  return temp;
}
//-------------------------------------------------------------------------------------------------

template <class T>
void TAList<T>::PutStart(T elem)
{
  if (IsFull())
    throw TException("Error. List is full");
  int ifree = freeElem.Get();
  mas[ifree] = elem;
  nextIndex[ifree] = start;
  if (start != -1)
    prevIndex[start] = ifree;
  else
    end = ifree;
  start = ifree;
  count++;
}
//-------------------------------------------------------------------------------------------------

template <class T>
void TAList<T>::PutEnd(T elem)
{
  if (IsFull())
    throw TException("Error. List is full");
  int ifree = freeElem.Get();
  mas[ifree] = elem;
  if (end != -1)
    nextIndex[end] = ifree;
  else
  {
    start = ifree;
    prevIndex[ifree] = -1;
  }
  prevIndex[ifree] = end;
  end = ifree;
  count++;
}
//-------------------------------------------------------------------------------------------------

template <class T>
T TAList<T>::GetStart()
{
  if (IsEmpty())
    throw TException("Error. List is empty");
  T elem = mas[start];
  freeElem.Put(start);
  int newstart = nextIndex[start];
  nextIndex[start] = prevIndex[start] = -2;
  if (newstart != -1)
    prevIndex[newstart] = -1;
  count--;
  start = newstart;
  return elem;
}
//-------------------------------------------------------------------------------------------------

template <class T>
T TAList<T>::GetEnd()
{
  if (IsEmpty())
    throw TException("Error. List is empty");
  T elem = mas[end];
  int newFinish = prevIndex[end];
  prevIndex[end] = nextIndex[end] = -2;
  freeElem.Put(end);
  end = newFinish;
  if (newFinish != -1)
    nextIndex[newFinish] = -1;
  else
    start = -1;
  count--;
  return elem;
}
//-------------------------------------------------------------------------------------------------

template <class T>
bool TAList<T>::IsFull()
{
  if (count == size)
    return true;
  return false;
}
//-------------------------------------------------------------------------------------------------

template <class T>
bool TAList<T>::IsEmpty()
{
  if (count == 0)
    return true;
  return false;
}
//-------------------------------------------------------------------------------------------------

template<class T>
inline void TAList<T>::Print()
{
  int it = start;
  for (int i = 0; i < count; i++)
  {
    cout << mas[it] << " ";
    it = nextIndex[it];
  }
}
//-------------------------------------------------------------------------------------------------