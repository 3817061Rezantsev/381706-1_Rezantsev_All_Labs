#include <iostream>
using namespace std;
void main() 
{
	try
	{
	setlocale(LC_ALL, "Russian");
	
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