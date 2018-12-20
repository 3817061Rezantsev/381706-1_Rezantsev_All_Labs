#include <iostream>
#include "TMonom.h"
using namespace std;
void main() 
{
	try
	{
	setlocale(LC_ALL, "Russian");
	unsigned* f = new unsigned int[5];
	for (int i = 0;i < 5;i++)
		f[i] = 0;
	TMonom a(5, f, 5);
	for (int i = 0;i < 5;i++)
		f[i] = 1;
	TMonom b(a);
	TMonom c(5,f,5);
	if (a == b)
		cout << "true ==";
	if (c > b)
		cout << "true >";
	if (c < b)
		cout << "false >";
	}
	catch (int a)
	{
		if (a == -1)
			cout << "Just an error" << "\n";
	
	}
}