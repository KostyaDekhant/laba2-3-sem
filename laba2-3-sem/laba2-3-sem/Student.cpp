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
	cout << "Введите фамилию студента: ";
	this->human.fio.lastname = write_str(29);
	cout << "Введите имя студента: ";
	this->human.fio.firstname = write_str(29);
	cout << "Введите отчество студента: ";
	this->human.fio.middle = write_str(29);
	cout << "Введите возраст: ";
	this->human.age = write_num(125);
	cout << "Введите номер паспорта: ";
	this->human.pd.number = write_pd(4);
	cout << "Введите серию паспорта: ";
	this->human.pd.series = write_pd(6);
	cout << "Введите размер стипендии: ";
	this->scholarship = write_num(100000);
	cout << "Введите номер группы: ";
	cin >> this->group;
}
void Student::OutputStud(int i)
{
	system("cls");
	cout << to_string(i + 1) + "-й человек: " << endl;
	cout << "---------------------------------" << endl;
	cout << "ФИО: " + this->human.fio.lastname + " " + this->human.fio.firstname + " " + this->human.fio.middle << endl;
	cout << "Паспортные данные: " + this->human.pd.number + " " + this->human.pd.series << endl;
	cout << "Возраст: " + to_string(this->human.age) << endl;
	cout << "Студент группы: " + this->group << endl;
	cout << "Стипендия: " + to_string(this->scholarship) << endl;
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
//		printf("Введите фамилию студента: ");
//		strcpy(stud[stud_num].human.fio.lastname, write_str(29));
//		printf("Введите имя студента: ");
//		strcpy(stud[stud_num].human.fio.firstname, write_str(29));
//		printf("Введите отчество студента: ");
//		strcpy(stud[stud_num].human.fio.middle, write_str(29));
//	}
//	else if (inp == 2)
//	{
//		printf("Введите номер паспорта: ");
//		strcpy(stud[stud_num].human.pd.number, write_pd(4));
//		printf("Введите серию паспорта: ");
//		strcpy(stud[stud_num].human.pd.series, write_pd(6));
//	}
//	else if (inp == 3)
//	{
//		printf("Введите возраст: ");
//		stud[stud_num].human.age = write_num(125);
//	}
//	else if (inp == 4)
//	{
//		printf("Введите номер группы: ");
//		char group[10];
//		gets_s(group);
//		strcpy(stud[stud_num].group, group);
//	}
//	else if (inp == 5)
//	{
//		printf("Введите размер стипендии: ");
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
//		printf("Данные не введены!\n\n");
//	printf("Нажмите любую клавишу, чтобы продолжить");
//	_getch();
//}