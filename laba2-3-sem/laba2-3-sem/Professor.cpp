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
	printf("������� ������� �������������: ");
	strcpy(last, write_str(29));
	printf("������� ��� �������������: ");
	strcpy(first, write_str(29));
	printf("������� �������� �������������: ");
	strcpy(mid, write_str(29));
	printf("������� �������: ");
	*age = write_num(125);
	printf("������� ����� ��������: ");
	strcpy(num, write_pd(4));
	printf("������� ����� ��������: ");
	strcpy(ser, write_pd(6));
	printf("������� ���� �������������: ");
	*exp = write_num(*age);
	printf("������� ������ ���������� �����: ");
	*wg = write_num(1000000);
	printf("������� ������������� �������: ");
	strcpy(sub, write_str(30));
}

void OutputProf(struct Professor prof[], int count_prof, bool flag)
{
	system("cls");
	for (int i = 0; i < count_prof; i++)
	{
		printf("%d-� �������: \n", i + 1);
		printf("---------------------------------\n");
		printf("���: %s %s %s\n", prof[i].human.fio.lastname, prof[i].human.fio.firstname, prof[i].human.fio.middle);
		printf("���������� ������: %s %s\n", prof[i].human.pd.number, prof[i].human.pd.series);
		printf("�������: %d\n", prof[i].human.age);
		printf("���� �������������: %d\n", prof[i].experience);
		printf("������ ���������� �����: %d\n", prof[i].wage);
		printf("�������: %s\n", prof[i].subject);
		printf("---------------------------------\n\n\n");
	}
	if (!count_prof)
		printf("������ �� �������\n");
	if (flag)
	{
		printf("\n������� ����� �������, ����� ����������");
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
		printf("������� ������� �������������: ");
		strcpy(prof[prof_num].human.fio.lastname, write_str(29));
		printf("������� ��� �������������: ");
		strcpy(prof[prof_num].human.fio.firstname, write_str(29));
		printf("������� �������� �������������: ");
		strcpy(prof[prof_num].human.fio.middle, write_str(29));
	}
	else if (inp == 2)
	{
		printf("������� ����� ��������: ");
		strcpy(prof[prof_num].human.pd.number, write_pd(4));
		printf("������� ����� ��������: ");
		strcpy(prof[prof_num].human.pd.series, write_pd(6));
	}
	else if (inp == 3)
	{
		printf("������� �������: ");
		prof[prof_num].human.age = write_num(125);
	}
	else if (inp == 4)
	{
		printf("������� �������: ");
		char subject[30];
		gets_s(subject);
		strcpy(prof[prof_num].subject, subject);
	}
	else if (inp == 5)
	{
		printf("������� ������ ��������: ");
		prof[prof_num].wage = write_num(100000);
	}
	else if (inp == 6)
	{
		printf("������� ���� ������������: ");
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
		printf("������ �� �������!\n\n");
	printf("������� ����� �������, ����� ����������");
	_getch();
}

void prof_info(int sum_ages, int count_pr, int sum_wage, int max_wage, int min_wage, int sum_exp)
{
	printf("���������� � ��������������: \n\n");
	printf("---------------------------------\n");
	printf("������� ������� �������������: %d\n", sum_ages / count_pr);
	printf("������� ��������� �������������: %d\n", sum_wage / count_pr);
	printf("������� ���� �������������: %d\n", sum_exp / count_pr);
	printf("������������ ��������� �������������: %d\n", max_wage);
	printf("����������� ��������� �������������: %d\n", min_wage);
	printf("---------------------------------\n");
}