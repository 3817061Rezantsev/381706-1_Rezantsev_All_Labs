#include <iostream>
#include "../PolskLib/TPolsk.h"
#include "../PolskLib/TPolsk.cpp"
using namespace std;
int main()
{
  try
  {
    setlocale(LC_ALL, "Russian");
    cout << "Тестирование программ поддержки обратной польской записи" << endl;
    char* m = "(7-2)*3+4";
    TString s(m);
    cout << s << " ~ ";
    TQueue<char> B(0);
    B = ConvertToPol(s);
    B.Print();
    cout << " = " << Rez(B) << endl;
  }
  catch (TException ex)
  {
    ex.Show();
  }
}