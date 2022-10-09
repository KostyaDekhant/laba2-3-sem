#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string>
#include <windows.h>
#include "Human.h"
#include "Student.h"
#include "Professor.h"
#include "Function.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool exit = false;
	int count_stud = 0, count_prof = 0;
	int inp;
	Student* stud = (struct Student*)malloc(MAX_SIZE * sizeof(struct Student));
	Professor* prof = (struct Professor*)malloc(MAX_SIZE * sizeof(struct Professor));
	//
	//Student stud[MAX_SIZE];
	//Professor prof[MAX_SIZE];
	init_stud(stud, &count_stud);
	init_prof(prof, &count_prof);
	do {
		print_choise();
		inp = write_num(9);
		if (inp == 9)
			exit = true;
		else
			act_choise(inp, &count_stud, &count_prof, stud, prof);
	} while (!exit);
	free(stud);
	free(prof);
}