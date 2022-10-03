#pragma once
#include <string>
#include "Human.h"

using namespace std;

struct Student
{
	struct Human human;
	int scholarship;
	string group;
};

Student StudentInit(string gr, int scholar, struct Human Human);
void InputStud(int *age, int *scholar, char *num, char* ser, char* first, char* mid, char* last, char* gr);