#pragma once
#include <string>

using namespace std;

struct FIO
{
	char firstname[25];
	char middle[25];
	char lastname[25];
};

FIO FIOInit(char *first, char* mid, char* last);