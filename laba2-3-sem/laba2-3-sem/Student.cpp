#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Student.h"

Student StudentInit(string gr, int scholar, struct Human human)
{
	Student stud;
	stud.human = human;
	stud.group = gr;
	stud.scholarship = scholar;
	return stud;
}

void InputStud(int* age, int* scholar, char* num, char* ser, char* first, char* mid, char* last, char* gr)
{
	*age = 10;
	strcpy(num, "1212");
	strcpy(ser, "121214");
}