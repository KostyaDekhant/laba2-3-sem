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
	printf("������� ������� ��������: ");
	strcpy(last, write_str(29));
	printf("������� ��� ��������: ");
	strcpy(first, write_str(29));
	printf("������� �������� ��������: ");
	strcpy(mid, write_str(29));
	printf("������� �������: ");
	*age = write_num(125);
	printf("������� ����� ��������: ");
	strcpy(num, write_pd(4));
	printf("������� ����� ��������: ");
	strcpy(ser, write_pd(6));
	printf("������� ������ ���������: ");
	*scholar = write_num(100000);
	printf("������� ����� ������: ");
	char group[10];
	gets_s(group);
	strcpy(gr, group);
}

void OutputStud(struct Student stud[], int count_stud, bool flag)
{
	system("cls");
	for (int i = 0; i < count_stud; i++)
	{
		printf("%d-� �������: \n", i+1);
		printf("---------------------------------\n");
		printf("���: %s %s %s\n", stud[i].human.fio.lastname, stud[i].human.fio.firstname, stud[i].human.fio.middle);
		printf("���������� ������: %s %s\n", stud[i].human.pd.number, stud[i].human.pd.series);
		printf("�������: %d\n", stud[i].human.age);
		printf("������� ������: %s\n", stud[i].group);
		printf("���������: %d\n", stud[i].scholarship);
		printf("---------------------------------\n\n\n");
	}
	if (!count_stud)
		printf("������ �� �������\n");
	if (flag)
	{
		printf("\n������� ����� �������, ����� ����������");
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
		printf("������� ������� ��������: ");
		strcpy(stud[stud_num].human.fio.lastname, write_str(29));
		printf("������� ��� ��������: ");
		strcpy(stud[stud_num].human.fio.firstname, write_str(29));
		printf("������� �������� ��������: ");
		strcpy(stud[stud_num].human.fio.middle, write_str(29));
	}
	else if (inp == 2)
	{
		printf("������� ����� ��������: ");
		strcpy(stud[stud_num].human.pd.number, write_pd(4));
		printf("������� ����� ��������: ");
		strcpy(stud[stud_num].human.pd.series, write_pd(6));
	}
	else if (inp == 3)
	{
		printf("������� �������: ");
		stud[stud_num].human.age = write_num(125);
	}
	else if (inp == 4)
	{
		printf("������� ����� ������: ");
		char group[10];
		gets_s(group);
		strcpy(stud[stud_num].group, group);
	}
	else if (inp == 5)
	{
		printf("������� ������ ���������: ");
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
		printf("������ �� �������!\n\n");
	printf("������� ����� �������, ����� ����������");
	_getch();
}

void stud_info(int sum_ages, int count_st, int sum_scholarship, int max_scholarship, int min_scholarship)
{
	printf("���������� � ���������: \n\n");
	printf("---------------------------------\n" );
	printf("������� ������� ��������: %d\n", sum_ages / count_st);
	printf("������� ��������� ��������: %d\n", sum_scholarship / count_st);
	printf("������������ ��������� ��������: %d\n", max_scholarship);
	printf("����������� ��������� ��������: %d\n", min_scholarship);
	printf("---------------------------------\n");
}