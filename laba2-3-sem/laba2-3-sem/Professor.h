#pragma once
#define MAX_SIZE 100
#include "Human.h"
#include <string>

using namespace std;

class Professor
{
private:
	int wage;
	int experience;
	string subject;
	class Human human;
public:
	void InputProf();
	void OutputProf(int i);
	void prof_analysis(int count_prof, int* prof_sum_age, int* prof_sum_wage,
		int* count_professors, int* max_wage, int* min_wage, int* sum_experience);
};

//Professor ProfessorInit(int wg, int exp, char* sub, struct Human Human);
//void OutputProf(struct Professor prof[], int count_prof, bool flag);
//void ChangeInfo_prof(struct Professor prof[], int count_prof);
//void prof_analysis(struct Professor prof[], int count_prof);