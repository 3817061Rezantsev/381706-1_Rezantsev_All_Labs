#include <iostream>
#include "TList.h"
#include "TNode.h"
using namespace std;
void main() 
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
	}
	catch (int a)
	{
		if (a == 1)
			cout << "IsEmpty" << "\n";
	}
}