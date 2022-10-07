#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Professor.h"
#include "Function.h"

Professor ProfessorInit(int wg, int exp, char *sub, struct Human Human)
{
	Professor prof;
	prof.human = Human;
	prof.wage = wg;
	prof.experience = exp;
	strcpy(prof.subject,sub);
	return prof;
}

void InputProf(int* age, int* wg, int *exp, char* num, char* ser, char* first, char* mid, char* last, char* sub)
{
	system("cls");
	printf("Введите фамилию преподавателя: ");
	strcpy(last, write_str(29));
	printf("Введите имя преподавателя: ");
	strcpy(first, write_str(29));
	printf("Введите отчество преподавателя: ");
	strcpy(mid, write_str(29));
	printf("Введите возраст: ");
	*age = write_num(125);
	printf("Введите номер паспорта: ");
	strcpy(num, write_pd(4));
	printf("Введите серию паспорта: ");
	strcpy(ser, write_pd(6));
	printf("Введите стаж преподавателя: ");
	*exp = write_num(*age);
	printf("Введите размер заработной платы: ");
	*wg = write_num(1000000);
	printf("Введите преподаваемый предмет: ");
	strcpy(sub, write_str(30));
}

void OutputProf(struct Professor prof[], int count_prof, bool flag)
{
	system("cls");
	for (int i = 0; i < count_prof; i++)
	{
		printf("%d-й человек: \n", i + 1);
		printf("---------------------------------\n");
		printf("ФИО: %s %s %s\n", prof[i].human.fio.lastname, prof[i].human.fio.firstname, prof[i].human.fio.middle);
		printf("Паспортные данные: %s %s\n", prof[i].human.pd.number, prof[i].human.pd.series);
		printf("Возраст: %d\n", prof[i].human.age);
		printf("Стаж преподавателя: %d\n", prof[i].experience);
		printf("Размер заработной платы: %d\n", prof[i].wage);
		printf("Предмет: %s\n", prof[i].subject);
		printf("---------------------------------\n\n\n");
	}
	if (!count_prof)
		printf("Данные не введены\n");
	if (flag)
	{
		printf("\nНажмите любую клавишу, чтобы продолжить");
		_getch();
	}
}

void ChangeInfo_prof(struct Professor prof[], int count_prof)
{
	int inp, prof_num = 0;
	prof_num = print_change_choise_prof(prof, count_prof);
	if (!prof_num)
		return;
	prof_num--;
	inp = write_num(7);
	if (inp == 7)
		return;
	else if (inp == 1)
	{
		printf("Введите фамилию преподавателя: ");
		strcpy(prof[prof_num].human.fio.lastname, write_str(29));
		printf("Введите имя преподавателя: ");
		strcpy(prof[prof_num].human.fio.firstname, write_str(29));
		printf("Введите отчество преподавателя: ");
		strcpy(prof[prof_num].human.fio.middle, write_str(29));
	}
	else if (inp == 2)
	{
		printf("Введите номер паспорта: ");
		strcpy(prof[prof_num].human.pd.number, write_pd(4));
		printf("Введите серию паспорта: ");
		strcpy(prof[prof_num].human.pd.series, write_pd(6));
	}
	else if (inp == 3)
	{
		printf("Введите возраст: ");
		prof[prof_num].human.age = write_num(125);
	}
	else if (inp == 4)
	{
		printf("Введите предмет: ");
		char subject[30];
		gets_s(subject);
		strcpy(prof[prof_num].subject, subject);
	}
	else if (inp == 5)
	{
		printf("Введите размер зарплаты: ");
		prof[prof_num].wage = write_num(100000);
	}
	else if (inp == 6)
	{
		printf("Введите стаж преподавания: ");
		prof[prof_num].experience = write_num(prof[prof_num].human.age);
	}
}

void prof_analysis(struct Professor prof[], int count_prof)
{
	system("cls");
	int prof_sum_age = 0, prof_sum_wage = 0, count_professors = 0, max_wage = 0, min_wage = 0, sum_experience = 0;
	for (int i = 0; i < count_prof; i++)
	{
		if (!count_professors)
		{
			max_wage = prof[i].wage;
			min_wage = prof[i].wage;
		}
		else if (prof[i].wage > max_wage)
		{
			max_wage = prof[i].wage;
		}
		else if (prof[i].wage < min_wage)
		{
			min_wage = prof[i].wage;
		}
		prof_sum_wage += prof[i].wage;
		count_professors++;
		prof_sum_age += prof[i].human.age;
		sum_experience += prof[i].experience;
	}
	if (count_professors)
		prof_info(prof_sum_age, count_professors, prof_sum_wage, max_wage, min_wage, sum_experience);
	else
		printf("Данные не введены!\n\n");
	printf("Нажмите любую клавишу, чтобы продолжить");
	_getch();
}

void prof_info(int sum_ages, int count_pr, int sum_wage, int max_wage, int min_wage, int sum_exp)
{
	printf("Статистика о преподавателях: \n\n");
	printf("---------------------------------\n");
	printf("Средний возраст преподавателя: %d\n", sum_ages / count_pr);
	printf("Средняя стипендия преподавателя: %d\n", sum_wage / count_pr);
	printf("Средний стаж преподавателя: %d\n", sum_exp / count_pr);
	printf("Максимальная стипендия преподавателя: %d\n", max_wage);
	printf("Минимальная стипендия преподавателя: %d\n", min_wage);
	printf("---------------------------------\n");
}