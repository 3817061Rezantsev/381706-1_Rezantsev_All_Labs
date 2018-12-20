#pragma once

template <class T>
class TArrayList
{
public:
	int size, count, start;
	T* mas;
	int *index;
public:
	TArrayList(int n = 1);
	TArrayList(TArrayList<T> &A);
	bool IsFul();
	bool IsEmpty();
	void PutStart(T B);
	void PutEnd(T B);
	T GetStart();
	T GetEnd();
};

//---------------------------------------------------------------------
template <class T>
TArrayList<T>::TArrayList(int n)
{
	if (n <= 0)
		throw -1;
	else
	{
		size = n;
		count = 0;
		start = -1;
		mas = new T[size];
		index = new int[size];
		for (int i = 0; i < size; i++)
			index[i] = -2;
	}
}
//---------------------------------------------------------------------
template <class T>
bool TArrayList<T>::IsEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}
//---------------------------------------------------------------------
template <class T>
bool TArrayList<T>::IsFul()
{
	if (count == size)
		return true;
	else
		return false;
}
//---------------------------------------------------------------------
template <class T>
TArrayList<T>::TArrayList(TArrayList<T> &A)
{
	start = A.start;
	size = A.size;
	count = A.count;
	if (size <= 0)
		throw -1;
	else
	{
		mas = new T[size];
		index = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		mas[i] = A.mas[i];
		index[i] = A.index[i];
	}

}
//---------------------------------------------------------------------
template <class T>
void TArrayList<T>::PutStart(T B)
{
	if (IsFul())
		throw -1;
	else
	{
		for (int i = 0; i < size; i++)
			if (index[i] == -2)
			{
				index[i] = start;
				mas[i] = B;
				start = i;
				count++;
				break;
			}
	}
}
//---------------------------------------------------------------------
template <class T>
void TArrayList<T>::PutEnd(T B)
{
	if (IsFul())
		throw -1;
	else
		for (int i = 0; i < size; i++)
			if (index[i] == -2)
			{
				mas[i] = B;
				int f = 0;
				for (int j = 0; j < size; j++)
				{
					if (index[j] == -1)
					{
						index[j] = i;
						index[i] = -1;
						break;
					}
					f++;
				}
				if (f == size)
				{
					index[i] = -1;
					start = i;
				}
				count++;
				break;
			}
}
//---------------------------------------------------------------------
template <class T>
T TArrayList<T>::GetStart()
{
	if (IsEmpty())
		throw -1;
	else
	{
		T temporary = mas[start];
		int _Start = index[start];
		index[start] = -2;
		start = _Start;
		count--;
		return temporary;
	}
}
//---------------------------------------------------------------------
template <class T>
T TArrayList<T>::GetEnd()
{
	if (IsEmpty())
		throw -1;
	else
	{
		
		for (int i = 0;i < size;i++)
		{
			if (index[i] == -1)
			{
				int max = -2;
				int f = 0;
				for (int j = 0;j < size;j++)
				{
					if (max < index[j]) 
					{
						max = index[j];
						f = j;
					}
				}
				index[f] = -1;
				index[i] = -2;
				count--;
				return mas[i];
			}
		}
		
	}
}
//---------------------------------------------------------------------