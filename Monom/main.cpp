#include <iostream>
#include "../MonomLib/TMonom.h"
#include "../MonomLib/TMonom.cpp"
using namespace std;
int main()
{
  try
  {
    setlocale(LC_ALL, "Russian");
    int* f = new  int[5];
    for (int i = 0;i < 5;i++)
      f[i] = 0;
    TMonom a(5, f, 5);
    for (int i = 0;i < 5;i++)
      f[i] = 1;
    TMonom b(a);
    TMonom c(5, f, 5);
    if (a == b)
      cout << "true ==";
    if (c > b)
      cout << "true >";
    if (c < b)
      cout << "false >";
  }
  catch (TException ex)
  {
    ex.Show();
  }
}