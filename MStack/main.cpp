#include <iostream>

#include "TMStack.h"

using namespace std;

int main()
{
	try 
	{
	std::cout << "An example of using the TMStack will be implemented here" << std::endl;
	TMStack <int> MS(10, 3);
	MS.Print();
	MS.Put(2, 1);
	MS.Put(2, 2);
	MS.Put(2, 3);
	MS.Print();
	MS.Put(2, 4);
	MS.Print();
	std::cout << "\tMS.Get(2): " << MS.Get(2);
	std::cout << MS.Get(2);
	std::cout << MS.Get(2);
	std::cout << MS.Get(2) << endl;
	
	}
	catch (int a) {
		if (a == -1)
			cout << "Wrong size" << endl;
		if (a == 0)
			cout << "Non-equal size" << endl;
		if (a == 1)
			cout << "Cant resize" << endl;
	}
	return 0;
}
