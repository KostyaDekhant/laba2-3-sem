#pragma once
#include "Human.h"
#include <string>

using namespace std;

struct Professor
{
	int wage;
	int experience;
	string subject;
	struct Human human;
};

Professor ProfessorInit(int wg, int exp, string sub, struct Human Human);