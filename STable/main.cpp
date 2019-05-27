#include <iostream>
#include "../Exception/Exception.h"
#include "TSTable.h"
using namespace std;
int main() 
{
	try 
	{
    TSTable<int> table(20000);
    TElem<int> elem;
    table.Put("Key1", 1);
    table.Put("Key2", 3);
    table.Put("Key3", 5);
    table.Put("Key5", 7);
    table.Put("Key7", 9);
    cout << "Searching element with key: \"Key3\"...\n";
    elem = table.Search("Key3");
    cout << "Key: " << elem.GetKey() << "  Data: " << elem.GetData() << "\n";
    cout << "Deleting element with key: \"Key3\"...\n";
    table.Del("Key3");
    cout << "Searching element with key: \"Key3\"...\n";
    elem = table.Search("Key3");
    cout << "Key: " << elem.GetKey() << "  Data: " << elem.GetData() << "\n";

    return 0;
	}
	catch (TException ex)
	{
		ex.Show();
	}
}