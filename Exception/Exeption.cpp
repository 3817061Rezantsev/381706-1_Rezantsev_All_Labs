#include "Exception.h"
TException::TException(std::string _str) : str(_str) {}

void TException::Show()
{
	std::cout << "\nWarning! \nMessage: " << str << std::endl;
}
