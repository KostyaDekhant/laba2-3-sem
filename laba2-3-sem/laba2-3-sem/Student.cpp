#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student.h"
#include "Function.h"


void Student::InputStud()
{
	system("cls");
	cout << "������� ������� ��������: ";
	this->human.fio.lastname = write_str(29);
	cout << "������� ��� ��������: ";
	this->human.fio.firstname = write_str(29);
	cout << "������� �������� ��������: ";
	this->human.fio.middle = write_str(29);
	cout << "������� �������: ";
	this->human.age = write_num(125);
	cout << "������� ����� ��������: ";
	this->human.pd.number = write_pd(4);
	cout << "������� ����� ��������: ";
	this->human.pd.series = write_pd(6);
	cout << "������� ������ ���������: ";
	this->scholarship = write_num(100000);
	cout << "������� ����� ������: ";
	cin >> this->group;
}
void Student::OutputStud(int i)
{
	system("cls");
	cout << to_string(i + 1) + "-� �������: " << endl;
	cout << "---------------------------------" << endl;
	cout << "���: " + this->human.fio.lastname + " " + this->human.fio.firstname + " " + this->human.fio.middle << endl;
	cout << "���������� ������: " + this->human.pd.number + " " + this->human.pd.series << endl;
	cout << "�������: " + to_string(this->human.age) << endl;
	cout << "������� ������: " + this->group << endl;
	cout << "���������: " + to_string(this->scholarship) << endl;
	cout << "---------------------------------\n\n" << endl;
}
//void ChangeInfo(struct Student stud[], int count_stud)
//{
//	int inp, stud_num = 0;
//	stud_num = print_change_choise(stud, count_stud);
//	if (!stud_num)
//		return;
//	stud_num--;
//	inp = write_num(6);
//	if (inp == 6)
//		return;
//	else if (inp == 1)
//	{
//		printf("������� ������� ��������: ");
//		strcpy(stud[stud_num].human.fio.lastname, write_str(29));
//		printf("������� ��� ��������: ");
//		strcpy(stud[stud_num].human.fio.firstname, write_str(29));
//		printf("������� �������� ��������: ");
//		strcpy(stud[stud_num].human.fio.middle, write_str(29));
//	}
//	else if (inp == 2)
//	{
//		printf("������� ����� ��������: ");
//		strcpy(stud[stud_num].human.pd.number, write_pd(4));
//		printf("������� ����� ��������: ");
//		strcpy(stud[stud_num].human.pd.series, write_pd(6));
//	}
//	else if (inp == 3)
//	{
//		printf("������� �������: ");
//		stud[stud_num].human.age = write_num(125);
//	}
//	else if (inp == 4)
//	{
//		printf("������� ����� ������: ");
//		char group[10];
//		gets_s(group);
//		strcpy(stud[stud_num].group, group);
//	}
//	else if (inp == 5)
//	{
//		printf("������� ������ ���������: ");
//		stud[stud_num].scholarship = write_num(100000);
//	}
//}
//void stud_analysis(struct Student stud[], int count_stud)
//{
//	system("cls");
//	int stud_sum_age = 0, stud_sum_scholarship = 0, count_students = 0, max_scholarship = 0, min_scholarship = 0;
//	int prof_sum_age = 0, prof_sum_wage = 0, count_professors = 0, max_wage = 0, min_wage = 0, sum_experience = 0;
//	for (int i = 0; i < count_stud; i++)
//	{
//		if (!count_students)
//		{
//			max_scholarship = stud[i].scholarship;
//			min_scholarship = stud[i].scholarship;
//		}
//		else if (stud[i].scholarship > max_scholarship)
//		{
//			max_scholarship = stud[i].scholarship;
//		}
//		else if (stud[i].scholarship < min_scholarship)
//		{
//			min_scholarship = stud[i].scholarship;
//		}
//		stud_sum_scholarship += stud[i].scholarship;
//		count_students++;
//		stud_sum_age += stud[i].human.age;
//	}
//	if (count_students)
//		stud_info(stud_sum_age, count_students, stud_sum_scholarship, max_scholarship, min_scholarship);
//	else
//		printf("������ �� �������!\n\n");
//	printf("������� ����� �������, ����� ����������");
//	_getch();
//}