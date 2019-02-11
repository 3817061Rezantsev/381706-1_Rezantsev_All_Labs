#include <iostream>
#include "../QueueLib/TQueue.h"
#include "../Exception/Exception.h"
using namespace std;
int main() 
{
	try
	{
		setlocale(LC_ALL, "Russian");
		TQueue<int> st(5);
		int temp;
		cout << "Тестирование программ поддержки структуры типа очереди" << endl;
		for (int i = 0; i < 5; i++) 
		{
			st.Put(i);
			cout << "Положили значение " << i << endl;
		}
		while (!st.IsEmpty()) 
		{
			temp = st.Get();
			cout << "Взяли значение " << temp << endl;
		}
	}
	catch (TException xd)
	{
		xd.Show();
	}
	
}