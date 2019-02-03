#pragma once
#include <iostream>
#include "TNode.h"
#include "../Exception/Exception.h"
using namespace std;
template <class T>
class TList
{
protected:
	TNode<T>* list;
public:
	TList();
	TList(TList<T> &list2);
	void PutBegin(T A);
	void PutAfter(T A, TNode<T>* node);
	void PutEnd(T A);
	int GetSize();
	TNode<T>* Search(T A);
	void Delete(T A);
	void Clean();
	T GetBegin();
	T GetCurrent(TNode<T>* A);
	T GetEnd();
	bool IsFull();
	bool IsEmpty();
	template <class Tfriend> friend ostream & operator<<(ostream &out, const TList<Tfriend> &B);
};
//-----------------------------------------------------------
template <class T>
TList<T>::TList()
{
	list = 0;
}
//-----------------------------------------------------------
template <class T>
TList<T>::TList(TList<T> &list2)
{
	if (list2.list)
	{
		list = new TNode<T>(list2.list->data, list2.list);
		TNode<T> *u = list;
		TNode<T> *u2 = list2.list->next;
		while (u2 != 0)
		{
			u->next = new TNode<T>(u2->data, u2->next);
			u = u->next;
			u2 = u2->next;
		}
	}
	else
		list = list2.list;;
}
//-----------------------------------------------------------
template <class T>
void TList<T>::PutBegin(T A)
{
	if (this->IsFull())
		throw TException("Error. List is full");
	if (list == 0)
	{
		TNode<T>* temp = new TNode<T>(A, 0);
		list = temp;
	}
	else
	{
		TNode<T>* temp = new TNode<T>(A, list);
		list = temp;
	}
}
//-----------------------------------------------------------
template <class T>
void TList<T>::PutAfter(T A, TNode<T>* node)
{
	if (this->IsFull())
		throw TException("Error. List is full");
	if (node && list)
	{
		TNode<T>* u = node->next;
		node->next = new TNode<T>(A, u);
	}
	else
		throw TException("Error. Uncorrect info");
}
//-----------------------------------------------------------
template <class T>
void TList<T>::PutEnd(T A)
{
	if (this->IsFull())
		throw TException("Error. List is full");
	if (list != 0)
	{
		TNode<T> *B = list;
		while (B->GetNext() != 0)
			B = B->GetNext();
		B->SetNext(new TNode<T>(A, 0));
	}
	else
		list = new TNode<T>(A, 0);
}
//-----------------------------------------------------------
template <class T>
void TList<T>::Delete(T A)
{
	TNode<T>* u = list;
	TNode<T>* u2 = u;
	if (u)
	{
		while ((u->next) && (u->data != A))
		{
			u2 = u;
			u = u->next;
		}

		if (u->data == A)
		{
			u2->next = u->next;
			if (u == list)
				list = list->next;
			delete u;
		}
	}

}
//-----------------------------------------------------------
template <class T>
int TList<T>::GetSize()
{
	int res = 0;
	TNode<T>* u = list;
	while (u)
	{
		res++;
		u = u->next;
	}
	return res;
}
//-----------------------------------------------------------
template <class T>
TNode<T>* TList<T>::Search(T A)
{
	TNode<T>* u = list;
	while (u)
	{
		if (u->data == A)
			return u;
		u = u->GetNext();
	}
	return 0;
}
//-----------------------------------------------------------
template <class T>
void TList<T>::Clean()
{
	TNode<T>* u = list;
	TNode<T>* u2;
	if (u != 0)
	{
		while (u->next != 0)
		{
			u2 = u->next;
			delete u;
			u = u2;
		}
		delete u;
		list = 0;
	}
}
//-----------------------------------------------------------
template <class Tfriend> ostream & operator<<(ostream &out, const TList<Tfriend> &B)
{
	TNode<Tfriend> * u = B.list;
	while (u)
	{
		out << u->data << " ";
		u = u->next;
	}
	return out;
}
//-----------------------------------------------------------
template <class T>
T TList<T>::GetBegin()
{
	TList<T> a = *this;
	int b = a.GetSize();
	if (b == 0)
		throw TException("Error. List is empty");
	else
	{
		TNode<T> *A = list;
		T temp = list->TNode<T>::GetData();
		list = list->TNode<T>::GetNext();
		delete A;
		return temp;
	}
}
//-----------------------------------------------------------
template <class T>
T TList<T>::GetCurrent(TNode<T>* A)
{
	if (A && list)
	{
		TNode<T>* B = list;
		while (A != list)
		{
			list = list->TNode<T>::GetNext();
		}
		T temp = list->TNode<T>::GetData();
		list = B;
		return temp;
	}
	else
		throw TException("Error. Uncorrect info");
}
//-----------------------------------------------------------
template <class T>
T TList<T>::GetEnd()
{
	if (list != 0)
	{
		TNode<T> *B = list->GetNext();
		TNode<T> *A = list;
		if (B == 0)
		{
			T temp = A->TNode<T>::GetData();
			delete A;
			list = 0;
			return temp;
		}
		else
		{
			while (B->GetNext() != 0)
			{
				A = B;
				B = B->GetNext();
			}
			T temp = B->GetData();
			delete B;
			A->SetNext(0);
			return temp;
		}
	}
	else
		throw TException("Error. List is empty");
}
//-----------------------------------------------------------
template <class T>
bool TList<T>::IsFull()
{
	try
	{
		TNode<T>* a = new TNode<T>();
		if (a == 0)
			return 1;
		else
		{
			delete a;
			return 0;
		}
	}
	catch (...)
	{
		return 0;
	}
	return true;
}//-------------------------------------------------------------------------
template <class T>
bool TList<T>::IsEmpty()
{
	TList<T> a = *this;
	int b = a.GetSize();
	if (b == 0)
		return true;
	else
		return false;
}