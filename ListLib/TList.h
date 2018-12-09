#pragma once
#include <iostream>
#include "TNode.h"
using namespace std;
template <class T>
class TList
{
protected:
	TNode<T>* list;
public:
	TList();
	TList(TList<T> &A);
	void PutBegin(T A);
	void PutAfter(T A, TNode<T>* node);
	void PutEnd(T A);
	int GetSize();
	TNode<T>* Search(T A);
	void Delete(T A);
	void Clean();
	template <class T> friend ostream & operator<<(ostream &out, const TList<T> &B);
};
//-----------------------------------------------------------
template <class T>
TList<T>::TList()
{
	list = NULL;
}
//-----------------------------------------------------------
template <class T>
TList<T>::TList(TList<T> &A)
{
	TNode<T>* C = A.list, B;
	if (A.list == 0)
		list = 0;
	else {
		list = new TNode<T>(*A.list);
		B = list;
		while (C->GetNext() != 0)
		{
			B->SetNext(new TNode<T>(*(C->GetNext())));
			C = C->GetNext();
			B = B->GetNext();
		}
	}
}
//-----------------------------------------------------------
template <class T>
void TList<T>::PutBegin(T A)
{
	if (list == 0)
	{
		TNode<T>* temp = new TNode<T>(A, NULL);
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
	if (node && list)
	{
		TNode<T>* u = node->next;
		node->next = new TNode<T>(A, u);
	}
	else
		if (list == NULL)
			throw 1;
}
//-----------------------------------------------------------
template <class T>
void TList<T>::PutEnd(T A)
{
	if (list != 0)
	{
		TNode<T> *B = list;
		while (B->GetNext() != 0)
			B = B->GetNext();
		B->SetNext(new TNode<T>(A, NULL));
	}
	else
		list = new TNode<T>(A, NULL);
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
		u = u->next;
	}
	return NULL;
}
//-----------------------------------------------------------
template <class T>
void TList<T>::Clean()
{
	TNode<T>* u = list;
	TNode<T>* u2;
	if (u != NULL)
	{
		while (u->next != NULL)
		{
			u2 = u->next;
			delete u;
			u = u2;
		}
		delete u;
		list = NULL;
	}
}
//-----------------------------------------------------------
template <class T> ostream & operator<<(ostream &out, const TList<T> &B)
{
	TNode<T> * u = B.list;
	while (u)
	{
		out << u->data << " ";
		u = u->next;
	}
	return out;
}