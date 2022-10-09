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
private:
	class Human human;
	int scholarship;
	string group;
public:
	Student();
	Student(class Human human);
	Student(class Human human, int scholarship, string group);
	~Student();

	void InputStud();
	void OutputStud(int i);
	void stud_analysis(int count_stud, int* stud_sum_age, int* stud_sum_scholarship,
		int* count_students, int* max_scholarship, int* min_scholarship);
	void ChangeInfo();
};