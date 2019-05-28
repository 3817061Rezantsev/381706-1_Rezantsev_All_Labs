#include <iostream>
#include "../Exception/Exception.h"
#include "THTable.h"
using namespace std;
int main() 
{
	try 
	{
   
    THTable<int> A(4);
    A.Put("a", 5);
    cout << A.Find("a") << endl;
    A.Del("a");
    cout << A.Find("a");
    return 0;
   
	}
	catch (TException ex)
	{
		ex.Show();
	}
}