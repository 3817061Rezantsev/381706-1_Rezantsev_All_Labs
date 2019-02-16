#pragma once
#include <iostream>
#include "../Exception/Exception.h"
#include "../PolskLib/TString.h"
#include "../PolskLib/TString.cpp"
using namespace std;
#include "../QueueLib/TQueue.h"
int GetPrt(const char op);
bool IsOp(char a);
TQueue<char> ConvertToPol(TString s);
double Rez(TQueue<char> q);