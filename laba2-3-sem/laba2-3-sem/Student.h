#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Human.h"

using namespace std;

struct Student
{
	struct Human human;
	int scholarship;
	char group[10];
};

Student StudentInit(char *gr, int scholar, struct Human Human);
void InputStud(int *age, int *scholar, char *num, char* ser, char* first, char* mid, char* last, char* gr);
void OutputStud(struct Student stud[], int count_stud, bool flag);
void ChangeInfo(struct Student stud[], int count_stud);
void ChangeInfo_prof(struct Professor prof[], int count_prof);
void stud_analysis(struct Student stud[], int count_stud);
void stud_info(int sum_ages, int count_st, int sum_scholarship, int max_scholarship, int min_scholarship);