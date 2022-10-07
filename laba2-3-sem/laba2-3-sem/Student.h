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
void OutputStud(struct Student stud[], int count_stud, bool flag);
void ChangeInfo(struct Student stud[], int count_stud);
void stud_analysis(struct Student stud[], int count_stud);