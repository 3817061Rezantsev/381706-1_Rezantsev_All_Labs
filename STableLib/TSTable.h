#pragma once
#include "TElem.h"
template <class T>
class TSTable
{
protected:
  TElem<T> not_find;
  TElem<T>* mas;
  int size, count;
public:
  TSTable(int _size = 10);
  TSTable(TSTable<T> &A);

  void SetSize(int _size);
  int GetSize();
  int GetCount();

  void Put(string _key, T c);
  void Del(string _key);
  TElem<T>& Search(string _key);
  T& operator[](string _key);
};
// ---------------------------------------------------------------------------
template <class T>
TSTable<T>::TSTable(int _size)
{
  if (_size <= 0)
    throw TException("Error");
  size = _size;
  count = 0;
  mas = new TElem<T>[size];
}
// ---------------------------------------------------------------------------
template <class T>
TSTable<T>::TSTable(TSTable<T> &A)
{
  size = A.size;
  count = A.count;
  mas = new TElem<T>[size];
  for (int i = 0; i < count; i++)
    mas[i] = A.mas[i];
}
// ---------------------------------------------------------------------------
template <class T>
void TSTable<T>::Put(string _key, T _data)
{
  if (count == size)
    throw TException("Error");
  mas[count].SetKey(_key);
  mas[count].SetData(_data);
  count++;
}
// ---------------------------------------------------------------------------
template <class T>
void TSTable<T>::Del(string _key)
{
  if (count == 0)
    throw TException("Error");
  TElem<T>& temp = Search(_key);
  if (temp != not_find)
    temp = not_find;
}
// ---------------------------------------------------------------------------
template <class T>
TElem<T>& TSTable<T>::Search(string _key)
{
  int k = 1;
  for (int i = 0; i < count; i++)
  {
    if (mas[i].GetKey() == _key)
      return mas[i];
  }
  return not_find;
}
// ---------------------------------------------------------------------------
template <class T>
T& TSTable<T>::operator[](string _key)
{
  TElem<T>& temp = Search(_key);
  if (temp == not_find)
  {
    T a;
    cout << "Enter the data:\n";
    cin >> a;
    Put(_key, a);
    return mas[count - 1].GetData();
  }
  else return temp.GetData();;
}
// ---------------------------------------------------------------------------
template <class T>
void TSTable<T>::SetSize(int _size)
{
  if (_size < count)
    throw TException("Error");
  TElem<T>* t = new TElem<T>[count];
  for (int i = 0; i < count; i++)
    t[i] = mas[i];
  delete[]mas;
  mas = new TElem<T>[_size];
  for (int i = 0; i < count; i++)
    mas[i] = t[i];
  size = _size;
  delete[]t;
}
// ---------------------------------------------------------------------------
template <class T>
int TSTable<T>::GetSize()
{
  return size;
}
// ---------------------------------------------------------------------------
template <class T>
int TSTable<T>::GetCount()
{
  return count;
}
