#include <iostream>
#include "TAList.h"
using namespace std;
void main() 
{
	try
	{
	setlocale(LC_ALL, "Russian");
	cout << "������������ �������� ��������� ��������� ���� �������" << endl;
	TArrayList <int> L1(5);
	L1.PutStart(60);
	L1.PutStart(40);
	std::cout << "�������� � ������ ������ 60, ����� 40\n";
	std::cout << "����� ������ ��������\n";
	std::cout << L1.GetStart() << "\n";
	std::cout << "����� ������ ��������\n";
	std::cout << L1.GetStart() << "\n";
	
	L1.PutEnd(60);
	L1.PutEnd(40);
	std::cout << "�������� � ����� ������ 60, ����� 40\n";
	std::cout << "����� ������ ��������\n";
	std::cout << L1.GetStart() << "\n";
	std::cout << "����� ������ ��������\n";
	std::cout << L1.GetStart() << "\n";
	
	L1.PutEnd(60);
	L1.PutEnd(40);
	std::cout << "�������� � ����� ������ 60, ����� 40\n";
	std::cout << "����� ��������� ��������\n";
	std::cout << L1.GetEnd() << "\n";
	}
	catch (int a)
	{
		if (a == -1)
			cout << "JustAnError" << "\n";
	}
}