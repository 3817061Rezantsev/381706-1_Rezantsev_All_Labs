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
		cout << "������������ �������� ��������� ��������� ���� ������" << endl;
		cout << "����� �������� ������" << endl;
		cout << a << endl;
		a.PutBegin(6);
		cout << "���������� ����� 6 � ������ ������" << endl;
		cout << "����� �������� ������" << endl;
		cout << a << endl;
		TNode<int>* c = a.Search(4);
		a.PutAfter(3, c);
		cout << "���������� ����� 3 ����� 4" << endl;
		cout << "����� �������� ������" << endl;
		cout << a << endl;
		int b = a.GetSize();
		cout << "������ ������: ";
		cout << b << endl;
		cout << "�������� ����� 5" << endl;
		a.Delete(5);
		cout << "����� �������� ������" << endl;
		cout << a << endl;
		cout << "����� �������, ��������, ����������" << endl;
		cout << a.GetBegin() << endl;
		cout << a.GetCurrent(c) << endl;
		cout << a.GetEnd() << endl;
		cout << "������ ������: ";
		b = a.GetSize();
		cout << b << endl;
		a.Clean();
		cout << "������� ������ " << endl;
		b = a.GetSize();
		cout << "������ ������: ";
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