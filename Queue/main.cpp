#include <iostream>
#include "TQueue.h"
using namespace std;
int main() 
{
	setlocale(LC_ALL, "Russian");
	TQueue<int> st(5);
	int temp;
	cout << "������������ �������� ��������� ��������� ���� �������" << endl;
	for (int i = 0; i < 5; i++) {
		st.Put(i);
		cout << "�������� �������� " << i << endl;
	}
	while (!st.IsEmpty()) {
		temp = st.Get();
		cout << "����� �������� " << temp << endl;
	}
}