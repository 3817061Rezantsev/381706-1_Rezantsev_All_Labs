#include <iostream>
#include "TAList.h"
using namespace std;
int main() 
{
	setlocale(LC_ALL, "Russian");
	cout << "������������ �������� ��������� ��������� ���� �������" << endl;
	TAList <int> L1(5);
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
	std::cout << "����� ��������� ��������\n";
	std::cout << L1.GetEnd() << "\n";
}