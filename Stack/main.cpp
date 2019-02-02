#include <iostream>
#include "TStack.h"
using namespace std;
int main()
{
	TStack<int> A(5);
	A.Put(10);
	A.Put(5);
	int b = A.Get();
	cout << "Put 10 then 5" << endl;
	cout << "Get val" << endl;
	cout << b << "\n";
	A.Put(8);
	b = A.Get();
	cout << "Put 8" << endl;
	cout << "Get val" << endl;
	cout << b << "\n";

}