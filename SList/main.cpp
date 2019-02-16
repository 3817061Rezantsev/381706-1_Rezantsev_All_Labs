#include <iostream>
#include "TSList.h"
#include <time.h>
#include "../Exception/Exception.h"
using namespace std;
int main()
{
  try
  {
    setlocale(LC_ALL, "Russian");
    cout << "Тестирование программ поддержки структуры типа стек на списке" << endl;
    cout << "Размер списка: ";
    TSList<int> S(3);
    int a = S.GetSize();
    cout << a << endl;
    S.Put(1), S.Put(2), S.Put(3);
    cout << "Ввод значений 1,2,3" << endl;
    cout << "Вывод значений списка" << endl;
    a = S.Get();
    cout << a << endl;
    a = S.Get();
    cout << a << endl;
    a = S.Get();
    cout << a << endl;
  }
  catch (TException ex)
  {
    ex.Show();
  }

}