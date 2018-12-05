#include <iostream>
#include "TStack.h"
using namespace std;
void main()
{
	try 
	{
		TStack<int> A(5);
		A.Put(10);
		A.Put(5);
		int b = A.Get();
		cout << b << "\n";
		A.Put(8);
		b = A.Get();
		cout << b << "\n";
	}
	catch (int a)
	{
		if (a == -1)
			cout << "n < 0" << "\n";
		if (a == 0)
			cout << "IsFull" << "\n";
		if (a == 1)
			cout << "IsEmpty" << "\n";
	}
}