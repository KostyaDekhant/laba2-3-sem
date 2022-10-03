#pragma once
#include <string>

using namespace std;

struct FIO
{
	string firstname;
	string middle;
	string lastname;
};

FIO FIOInit(string first, string mid, string last);