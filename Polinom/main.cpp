#include <iostream>
#include "../Exception/Exception.h"
#include "TPolinom.h"
#include "TPolinom.cpp"
using namespace std;
void main() 
{
	try
	{
	setlocale(LC_ALL, "Russian");
	TPolynom a(3);
	TPolynom b(a);
	b = a + b;
	int* f = new  int[5];
	for (int i = 0;i < 5;i++)
		f[i] = 0;
	TMonom l(5, f, 5);
	for (int i = 0;i < 5;i++)
		f[i] = 1;
	TMonom j(l);
	TMonom c(5, f, 5);

	}
	catch (TException ex)
	{
		ex.Show();
	}
}