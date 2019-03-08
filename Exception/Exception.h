#pragma once

#include <iostream>
#include <string>

class TException
{
private:
 	std::string str;
public:	TException(std::string _str);
	void Show();
};

inline TException::TException(std::string _str) : str(_str) {}

inline void TException::Show()
{
	std::cout << "\nWarning! \nMessage: " << str << std::endl;
}
