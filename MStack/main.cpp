#include <iostream>
#include "../Exception/Exception.h"
#include "TMStack.h"

using namespace std;

int main()
{
  try
  {
    cout << "An example of using the TMStack will be implemented here" << endl;
    TMStack <int> MS(10, 3);
    MS.Print();
    MS.Put(2, 1);
    MS.Put(2, 2);
    MS.Put(2, 3);
    MS.Print();
    MS.Put(2, 4);
    MS.Print();
    cout << "MS.Get(2)x4: " << MS.Get(2);
    cout << MS.Get(2);
    cout << MS.Get(2);
    cout << MS.Get(2) << endl;

  }
  catch (TException a)
  {
    a.Show();
  }

}
