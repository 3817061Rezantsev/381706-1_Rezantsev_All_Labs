#include <iostream>
#include "../MatrixLib/TMatrix.h"
using namespace std;
void main()
{
	try 
	{

			cout << "An example of using the Matrix will be implemented here" << endl;
			TMatrix <int> M1(5), M2(5), M3(5), M4(3), M5(3),M6(3), Res1(5), Res2(5), Res3(5), Res4(3), Res5(3);
			int i, j;
			for (i = 0; i < 5; i++)
				for (j = 0; j < 5 - i; j++)
				{
					M1[i][j] = 1;
					M2[i][j] = 2;
					M3[i][j] = i + j;
				}
			Res1 = M1 + M2;
			Res2 = M1 - M2;
			for (i = 0; i < 3; i++)
				for (j = 0; j < 3 - i; j++)
				{
					M5[i][j] = 1;
					M4[i][j] = 1;
					
				}
			Res4 = M4 * M5;
			cin >> M6;
			cout << M6 << endl;
			cout << M1 << endl;
			cout << M2 << endl;
			cout << M3 << endl;
			cout << Res1 << endl;
			cout << Res2 << endl;
			cout << Res3 << endl;
			cout << Res4 << endl;
	}
	catch (int a)
	{
		if (a == -1)
			cout << "Wrong size" << endl;
		if (a == 0)
			cout << "Non-equal size" << endl;
	}
	
	
}