#include <iostream>
#include "../Exception/Exception.h"
#include "../PolinomLib/TPolinom.h"
#include "../PolinomLib/TPolinom.cpp"
using namespace std;
int main() 
{
	try
	{
	setlocale(LC_ALL, "Russian");
	cout << "������ ������������� ���������" << endl;
	TPolynom a(5);
	TPolynom b(a);
	TPolynom v(a);
	
	cout << "����� 1" << endl;
	
	
	b = a + b;
	int* f = new  int[5];
	for (int i = 0;i < 5;i++)
		f[i] = 1;
	TMonom l(5, f, 5);
	cout << l << endl;
	int* g = new  int[5];
	cout << "����� 2" << endl;
	for (int i = 0;i < 5;i++)
		g[i] = 1;
	TMonom j(l);
	TMonom c(5, g, 7);
	cout << c << endl;
	a += c;
	cout << "������� � += ����� 1" << endl;
	cout << a << endl;
	a += l;
	cout << "������� � += ����� 2" << endl;
	cout << a << endl;
	int m1[] = { 1,2,3,4,5 };
	int m2[] = { 1,2,3,4,6 };
	cout << "����� 3" << endl;
	TMonom y(5, m1, 8);
	cout << y << endl;
	cout << "����� 4" << endl;
	TMonom s(5, m2, 12);
	cout << s << endl;
	b += y;
	cout << "������� B += ����� 3" << endl;
	cout << b << endl;
	b += s;
	cout << "������� B += ����� 4" << endl;
	cout << b << endl;
	v = a + b;
	cout << "������� � + ������� B" << endl;
	cout << v << endl;
	v = a - b;
	cout << "������� � - ������� B" << endl;
	cout << v << endl;
	v = a * b;
	cout << "������� � * ������� B" << endl;
	cout << v << endl;
	return 0;
	}
	catch (TException ex)
	{
		ex.Show();
	}
}