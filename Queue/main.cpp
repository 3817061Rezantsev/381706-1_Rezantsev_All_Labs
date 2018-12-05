#include <iostream>
#include "TQueue.h"
using namespace std;
void main() 
{
	try
	{
	setlocale(LC_ALL, "Russian");
	TQueue<int> st(5);
	int temp;
	cout << "Тестирование программ поддержки структуры типа очереди" << endl;
	for (int i = 0; i < 5; i++) {
		st.Put(i);
		cout << "Положили значение " << i << endl;
	}
	while (!st.IsEmpty()) {
		temp = st.Get();
		cout << "Взяли значение " << temp << endl;
	}
	}
	catch (int a)
	{
		if (a == -1)
			cout << "n < 0" << "\n";
		if (a == 0)
			cout << "IsFull" << "\n";
		if (a == 1)
			cout << "IsEmpty" << "\n";
	}
}