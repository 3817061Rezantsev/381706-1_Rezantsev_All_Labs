#pragma once
#include "TElem.h"

template <class T>
class THTable
{
protected:
  TElem<T> not_find;
  TElem<T>** mas;
  int size;
  int Hash(string _key);
public:
  THTable(int _size = 10);
  THTable(THTable<T> &A);

  void SetSize(int _size);
  int GetSize();

  void Put(string _key, T c);
  void Del(string _key);
  T Find(string _key);
};
template <class T>
THTable<T>::THTable(int _size)
{
  if (_size <= 0)
    throw TException("Error size");
  size = _size;
  mas = new TElem<T>*[size];
  for (int i = 0; i < size; i++)
    mas[i] = 0;
}
template <class T>
THTable<T>::THTable(THTable<T> &A)
{
  size = A.size;
  mas = new TElem<T>*[size];
  for (int i = 0; i < size; i++)
    mas[i] = A.mas[i];
}
template <class T>
void THTable<T>::Put(string _key, T c)
{
  int h = Hash(_key);
  if (mas[h] == 0)
    mas[h] = new TElem<T>(_key, c);
  else
  {
    TElem<T> *n = new TElem<T>(_key, c);
    n->SetNext(mas[h]);
    mas[h] = n;
  }
}
template <class T>
int THTable<T>::Hash(string _key)
{
  int c = _key[0];
  int h;
  h = c % size;
  return h;
}
template <class T>
void THTable<T>::Del(string _key)
{
  int h = Hash(_key);
  TElem<T> *j = mas[h];
  TElem<T> *p = 0;
  if (mas[h] == 0)
    throw TException("Table is empty");
  if (mas[h]->GetNext() == 0)
    mas[h] = 0;
  else
  {
    while (j->GetKey() != _key && j->GetNext() != 0)
    {
      p = j;
      j = j->GetNext();
    }
    if (j->GetKey() == _key)
    {
      if (p != 0)
        p->SetNext(j->GetNext());
      else
        mas[h] = j->GetNext();
    }
  }
}
template <class T>
T THTable<T>::Find(string _key)
{
  int h = Hash(_key);
  if (mas[h] == 0)
    return not_find.GetData();
  if (mas[h]->GetKey() == _key)
    return mas[h]->GetData();
  else if (mas[h]->GetNext() != 0)
  {
    TElem<T> *tmp = mas[h];
    while (tmp != 0)
    {
      tmp = tmp->GetNext();
      if (tmp->GetKey() == _key)
        return tmp->GetData();
    }
  }
  return not_find.GetData();
}
template <class T>
void THTable<T>::SetSize(int _size)
{
  if (_size <= size)
    throw TException("Error new size");
  TElem<T> **tmp;
  tmp = new TElem<T>*[_size];
  for (int i = 0; i < size; i++)
    tmp[i] = mas[i];
  delete mas;
  int old = size;
  size = _size;
  mas = new TElem<T>*[size];
  for (int i = 0; i < old; i++)
    mas[i] = tmp[i];
  for (int i = old; i < size; i++)
    mas[i] = 0;
  delete tmp;
}
template <class T>
int THTable<T>::GetSize()
{
  return size;
}
