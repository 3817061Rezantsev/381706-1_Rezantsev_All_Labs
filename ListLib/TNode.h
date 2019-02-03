#pragma once
template <class T>
class TNode
{
public:
	T data;
	TNode<T>* next;
public:
	TNode(T d = 0, TNode<T>* n = 0)
	{
		data = d;
		next = n;
	}
	TNode(const TNode<T> &A)
	{
		data = A.data;
		next = 0;
	}
	T GetData()
	{
		return data;
	}
	TNode<T>* GetNext()
	{
		return next;
	}
	void SetData(T d)
	{
		data = d;
	}
	void SetNext(TNode<T>* n)
	{
		next = n;
	}
};

