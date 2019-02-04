#include <iostream>
#include "TAList.h"
using namespace std;
int main() 
{
	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки структуры типа очереди" << endl;
	TAList <int> L1(5);
	L1.PutStart(60);
	L1.PutStart(40);
	std::cout << "Положили в начало списка 60, потом 40\n";
	std::cout << "Взяли первое значение\n";
	std::cout << L1.GetStart() << "\n";
	std::cout << "Взяли первое значение\n";
	std::cout << L1.GetStart() << "\n";
	L1.PutEnd(60);
	L1.PutEnd(40);
	std::cout << "Положили в конец списка 60, потом 40\n";
	std::cout << "Взяли последнее значение\n";
	std::cout << L1.GetEnd() << "\n";
}