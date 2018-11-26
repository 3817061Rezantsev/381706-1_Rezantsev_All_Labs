#include <iostream>
#include "../MatrixLib/TMatrix.h"
using namespace std;
void main()
{
	TMatrix<int> a(5), b(5);
	int i, j;
	
	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки представления треугольных матриц"
		<< endl;
	for (int k = 0;k < 15;k++) 
	{
		a.SetValue(k, k);
		b.SetValue(k, 2 * k);
	}
	TMatrix<int> c = a + b;
	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b = " << endl << b << endl;
	cout << "Matrix c = a + b" << endl << c << endl;
	
}