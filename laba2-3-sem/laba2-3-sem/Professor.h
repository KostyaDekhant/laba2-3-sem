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
void InputProf(int* age, int* wg, int* exp, char* num, char* ser, char* first, char* mid, char* last, char* sub);
void OutputProf(struct Professor prof[], int count_prof, bool flag);
void prof_analysis(struct Professor prof[], int count_prof);
void prof_info(int sum_ages, int count_pr, int sum_wage, int max_wage, int min_wage, int sum_exp);