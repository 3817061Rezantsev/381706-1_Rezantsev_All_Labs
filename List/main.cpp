#include <iostream>
#include "TList.h"
#include "TNode.h"
#include <time.h>
#include "../Exception/Exception.h"
using namespace std;
int main() 
{	
	try
	{
		TList<int> a;
		setlocale(LC_ALL, "Russian");
		a.PutEnd(4);
		a.PutEnd(5);
		cout << "Тестирование программ поддержки структуры типа списка" << endl;
		cout << "Вывод значений списка" << endl;
		cout << a << endl;
		a.PutBegin(6);
		cout << "Размещение цифры 6 в начале списка" << endl;
		cout << "Вывод значений списка" << endl;
		cout << a << endl;
		TNode<int>* c = a.Search(4);
		a.PutAfter(3, c);
		cout << "Размещение цифры 3 после 4" << endl;
		cout << "Вывод значений списка" << endl;
		cout << a << endl;
		int b = a.GetSize();
		cout << "Размер списка: ";
		cout << b << endl;
		cout << "Удаление цифры 5" << endl;
		a.Delete(5);
		cout << "Вывод значений списка" << endl;
		cout << a << endl;
		cout << "Вывод первого, текущего, последнего" << endl;
		cout << a.GetBegin() << endl;
		cout << a.GetCurrent(c) << endl;
		cout << a.GetEnd() << endl;
		cout << "Размер списка: ";
		b = a.GetSize();
		cout << b << endl;
		a.Clean();
		cout << "Очистка списка " << endl;
		b = a.GetSize();
		cout << "Размер списка: ";
		cout << b << endl;
		/*
		TList<int> k, l;
		double t1, t2, startPut, endPut;
		
		for (int i = 0;i < 1000000;i++)
		{
			k.PutBegin(1);
		}
		startPut = clock();
		k.PutBegin(1);
		t1 = (clock() - startPut) / CLOCKS_PER_SEC;
	
		for (int i = 0;i < 1000000;i++)
		{
			l.PutEnd(1);
		}
		endPut = clock();
		l.PutEnd(1);
		t2 = (clock() - endPut) / CLOCKS_PER_SEC;
		cout << t1 << endl;
		cout << t2 << endl;*/
	}
	catch (TException ex)
	{
		ex.Show();
	}
	
}