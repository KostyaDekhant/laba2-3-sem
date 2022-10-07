#pragma once
#define MAX_SIZE 100
#include "Human.h"
#include <string>

using namespace std;

struct Professor
{
	int wage;
	int experience;
	char subject[25];
	struct Human human;
};

Professor ProfessorInit(int wg, int exp, char* sub, struct Human Human);
void OutputProf(struct Professor prof[], int count_prof, bool flag);
void ChangeInfo_prof(struct Professor prof[], int count_prof);
void prof_analysis(struct Professor prof[], int count_prof);