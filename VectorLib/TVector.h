#pragma once
#include <iostream>
#include <math.h>
using namespace std;
template <class T>
class TVector
{
protected:
  int size;
  T *vector;
public:
  TVector<T>(int n = 0);
  TVector<T>(const TVector<T> &A);
  virtual ~TVector<T>();

  int GetSize() const;
  T& operator[](int i);
  bool operator==(const TVector<T> &A);
  TVector& operator=(const TVector<T> &A);

  TVector operator++();
  TVector operator++(int);
  TVector operator--();
  TVector operator--(int);
  TVector operator+() const;
  TVector operator-() const;
  TVector operator+(const TVector<T> &A);
  TVector operator-(const TVector<T> &A);

  T operator*(const TVector<T> &A);
  TVector operator*(T A);
  template <class FriendT> friend TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &A);

  template <class FriendT> friend istream& operator>>(istream &in, TVector<FriendT> &A);
  template <class FriendT> friend ostream& operator<<(ostream &out, const TVector<FriendT> &AV);
};
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>::TVector(int n) 
{
  if (n < 0)
	throw -1;
  else
	if (n == 0) 
	{
	  size = n;
	  vector = NULL;
	}
	else 
	{
	  size = n;
	  vector = new T[size];
	  for (int i = 0; i < size; i++)
		vector[i] = 0;
	}
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>::TVector(const TVector<T> &A) 
{
  size = A.size;
  if (size == 0)
	vector = NULL;
  else {
	vector = new T[size];
	for (int i = 0; i < size; i++)
	  vector[i] = A.vector[i];
  }
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>::~TVector() 
{
  if (size > 0) {
	size = 0;
	delete[] vector;
	vector = NULL;
  }
}
//-------------------------------------------------------------------------------------------------
template<class T>
int TVector<T>::GetSize() const
{
  return size;
}
//-------------------------------------------------------------------------------------------------
template <class T>
T& TVector<T>::operator[](int i)
{
  if (i < 0 || i >= size)
	
	  throw -1;
  else 
	  return vector[i];
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T> &A) 
{
  if (this == &A)
	return *this;
  delete[] vector;
  size = A.size;
  vector = new T[size];
  for (int i = 0; i < size; i++)
	(*this)[i] = A.vector[i];
  return *this;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator+() const 
{
  TVector<T> res(*this);
  return res;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator-() const 
{
  TVector<T> res(size);
  for (int i = 0; i < size; i++) 
	res[i] = -vector[i];
  return res;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator+(const TVector<T> &A) 
{
  if (size != A.size)
	throw 0;
  TVector<T> res(size);
  for (int i = 0; i < size; i++)
	res[i] = (*this)[i] + A.vector[i];
  return res;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator-(const TVector<T> &A) 
{
  if (size != A.size)
	throw 0;
  TVector<T> res(size);
  for (int i = 0; i < size; i++)
	res[i] = (*this)[i] - A.vector[i];
  return res;
}
//-------------------------------------------------------------------------------------------------
template<class T>
T TVector<T>::operator*(const TVector <T> &A) 
{
  if (size != A.size)
	throw 0;
  T res = 0;
  for (int i = 0; i < size; i++)
	res += (*this)[i] * A.vector[i];
  return res;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator*(T A) 
{
  TVector<T> res(size);
  for (int i = 0; i < size; i++)
	res[i] = (*this)[i] * A;
  return res;
}
//-------------------------------------------------------------------------------------------------
template<class FriendT>
TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &A)
{
  TVector<FriendT> res(A.size);
  for (int i = 0; i < A.size; i++)
	res[i] = A.vector[i] * a;
  return res;
}
//-------------------------------------------------------------------------------------------------
template<class T>
bool TVector<T>::operator==(const TVector<T> &A) 
{
  if (size != A.size) 
	return false;
  else 
  {
	T diff = 0.0001;
	for (int i = 0; i < size; i++)
		if ((A.vector[i] - vector[i])|| (vector[i] - A.vector[i]) > diff)
		return false;
  }
  return true;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator++() 
{
  for (int i = 0; i < size; i++)
	vector[i] = vector[i] + 1;
  return *this;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator++(int) 
{
  TVector<T> res(*this);
  for (int i = 0; i < size; i++)
	vector[i] = vector[i] + 1;
  return res;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator--() 
{
  for (int i = 0; i < size; i++)
	vector[i] = vector[i] - 1;
  return *this;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator--(int) 
{
  TVector<T> res(*this);
  for (int i = 0; i < size; i++)
	vector[i] = vector[i] - 1;
  return res;
}
//-------------------------------------------------------------------------------------------------
template<class FriendT>
istream& operator>>(istream &istr, TVector<FriendT> &A)
{
  cout << "\nEnter the " << A.size << " coordinates: ";
  for (int i = 0; i < A.size; i++)
	istr >> A.vector[i];
  return istr;
}
//-------------------------------------------------------------------------------------------------
template<class FriendT>
ostream& operator<<(ostream &ostr, const TVector<FriendT> &A)
{
  for (int i = 0; i < A.size; i++)
	ostr << A.vector[i] << "\t";
  return ostr;
}
//-------------------------------------------------------------------------------------------------