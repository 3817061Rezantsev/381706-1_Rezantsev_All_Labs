#include <iostream>
#include "../MatrixLib/TMatrix.h"
#include <time.h>
#include "../Exception/Exception.h"
using namespace std;
int main()
{
  try
  {
    double t1, t2, startMult, endMult, startDel, endDel;
    cout << "An example of using the Matrix will be implemented here" << endl;
    TMatrix <double> M1(3), M2(3), M6(1), Res1(3), Res2(3), Res3(3), Res4(3);
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3 - i; j++)
      {
        M1[i][j] = 1 + i;
        M2[i][j] = 2 + 2 * i;
      }
    Res1 = M1 + M2;
    Res2 = M1 - M2;
    startDel = clock();
    Res3 = M1 / M2;
    t2 = (clock() - startDel) / CLOCKS_PER_SEC;
    startMult = clock();
    Res4 = M1 * M2;
    t1 = (clock() - startMult) / CLOCKS_PER_SEC;
    cout << "M1" << endl << M1 << endl;
    cout << "M2" << endl << M2 << endl;
    cout << "M1 + M2" << endl << Res1 << endl;
    cout << "M1 - M2" << endl << Res2 << endl;
    cout << "M1 / M2" << endl << Res3 << endl;
    cout << "M1 * M2" << endl << Res4 << endl;
    cout << "MultTime = " << t1;
    cout << endl;
    cout << "DelTime = " << t2;
    cout << endl;
    return 0;
  }
  catch (TException ch)
  {
    ch.Show();
  }

}