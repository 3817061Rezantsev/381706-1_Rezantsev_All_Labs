#pragma once

#include <iostream>
#include <string>

class TException
{
private:
	std::string str;
public:
	TException(std::string _str);
	void Show();
};
