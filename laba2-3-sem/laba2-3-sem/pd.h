#pragma once

#include <string>

using namespace std;

struct passport_data
{
	string series;
	string number;
};

passport_data passport_dataInit(string num, string ser);