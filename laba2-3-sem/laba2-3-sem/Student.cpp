#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student.h"
#include "Function.h"

Student StudentInit(char *gr, int scholar, struct Human human)
{
	Student stud;
	stud.human = human;
	strcpy(stud.group,gr);
	stud.scholarship = scholar;
	return stud;
}

void InputStud(int* age, int* scholar, char* num, char* ser, char* first, char* mid, char* last, char* gr)
{
	system("cls");
	printf("Введите фамилию студента: ");
	strcpy(last, write_str(29));
	printf("Введите имя студента: ");
	strcpy(first, write_str(29));
	printf("Введите отчество студента: ");
	strcpy(mid, write_str(29));
	printf("Введите возраст: ");
	*age = write_num(125);
	printf("Введите номер паспорта: ");
	strcpy(num, write_pd(4));
	printf("Введите серию паспорта: ");
	strcpy(ser, write_pd(6));
	printf("Введите размер стипендии: ");
	*scholar = write_num(100000);
	printf("Введите номер группы: ");
	char group[10];
	gets_s(group);
	strcpy(gr, group);
}

void OutputStud(struct Student stud[], int count_stud, bool flag)
{
	system("cls");
	for (int i = 0; i < count_stud; i++)
	{
		printf("%d-й человек: \n", i+1);
		printf("---------------------------------\n");
		printf("ФИО: %s %s %s\n", stud[i].human.fio.lastname, stud[i].human.fio.firstname, stud[i].human.fio.middle);
		printf("Паспортные данные: %s %s\n", stud[i].human.pd.number, stud[i].human.pd.series);
		printf("Возраст: %d\n", stud[i].human.age);
		printf("Студент группы: %s\n", stud[i].group);
		printf("Стипендия: %d\n", stud[i].scholarship);
		printf("---------------------------------\n\n\n");
	}
	if (!count_stud)
		printf("Данные не введены\n");
	if (flag)
	{
		printf("\nНажмите любую клавишу, чтобы продолжить");
		_getch();
	}
}

void ChangeInfo(struct Student stud[], int count_stud)
{
	int inp, stud_num = 0;
	stud_num = print_change_choise(stud, count_stud);
	if (!stud_num)
		return;
	stud_num--;
	inp = write_num(6);
	if (inp == 6)
		return;
	else if (inp == 1)
	{
		printf("Введите фамилию студента: ");
		strcpy(stud[stud_num].human.fio.lastname, write_str(29));
		printf("Введите имя студента: ");
		strcpy(stud[stud_num].human.fio.firstname, write_str(29));
		printf("Введите отчество студента: ");
		strcpy(stud[stud_num].human.fio.middle, write_str(29));
	}
	else if (inp == 2)
	{
		printf("Введите номер паспорта: ");
		strcpy(stud[stud_num].human.pd.number, write_pd(4));
		printf("Введите серию паспорта: ");
		strcpy(stud[stud_num].human.pd.series, write_pd(6));
	}
	else if (inp == 3)
	{
		printf("Введите возраст: ");
		stud[stud_num].human.age = write_num(125);
	}
	else if (inp == 4)
	{
		printf("Введите номер группы: ");
		char group[10];
		gets_s(group);
		strcpy(stud[stud_num].group, group);
	}
	else if (inp == 5)
	{
		printf("Введите размер стипендии: ");
		stud[stud_num].scholarship = write_num(100000);
	}
}

void stud_analysis(struct Student stud[], int count_stud)
{
	system("cls");
	int stud_sum_age = 0, stud_sum_scholarship = 0, count_students = 0, max_scholarship = 0, min_scholarship = 0;
	int prof_sum_age = 0, prof_sum_wage = 0, count_professors = 0, max_wage = 0, min_wage = 0, sum_experience = 0;
	for (int i = 0; i < count_stud; i++)
	{
		if (!count_students)
		{
			max_scholarship = stud[i].scholarship;
			min_scholarship = stud[i].scholarship;
		}
		else if (stud[i].scholarship > max_scholarship)
		{
			max_scholarship = stud[i].scholarship;
		}
		else if (stud[i].scholarship < min_scholarship)
		{
			min_scholarship = stud[i].scholarship;
		}
		stud_sum_scholarship += stud[i].scholarship;
		count_students++;
		stud_sum_age += stud[i].human.age;
	}
	if (count_students)
		stud_info(stud_sum_age, count_students, stud_sum_scholarship, max_scholarship, min_scholarship);
	else
		printf("Данные не введены!\n\n");
	printf("Нажмите любую клавишу, чтобы продолжить");
	_getch();
}

void stud_info(int sum_ages, int count_st, int sum_scholarship, int max_scholarship, int min_scholarship)
{
	printf("Статистика о студентах: \n\n");
	printf("---------------------------------\n" );
	printf("Средний возраст студента: %d\n", sum_ages / count_st);
	printf("Средняя стипендия студента: %d\n", sum_scholarship / count_st);
	printf("Максимальная стипендия студента: %d\n", max_scholarship);
	printf("Минимальная стипендия студента: %d\n", min_scholarship);
	printf("---------------------------------\n");
}