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

class Student
{
public:
	class Human human;
	int scholarship;
	string group;
	void InputStud();
	void OutputStud(int i);
};

//Student StudentInit(char *gr, int scholar, struct Human Human);
void ChangeInfo(struct Student stud[], int count_stud);
void stud_analysis(struct Student stud[], int count_stud);