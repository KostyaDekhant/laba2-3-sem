#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Professor.h"
#include "Function.h"


void ChangeInfo_prof(struct Professor prof[], int count_prof);
//{
//	int inp, prof_num = 0;
//	prof_num = print_change_choise_prof(prof, count_prof);
//	if (!prof_num)
//		return;
//	prof_num--;
//	inp = write_num(7);
//	if (inp == 7)
//		return;
//	else if (inp == 1)
//	{
//		/*printf("Введите фамилию преподавателя: ");
//		strcpy(prof[prof_num].human.fio.lastname, write_str(29));
//		printf("Введите имя преподавателя: ");
//		strcpy(prof[prof_num].human.fio.firstname, write_str(29));
//		printf("Введите отчество преподавателя: ");
//		strcpy(prof[prof_num].human.fio.middle, write_str(29));*/
//	}
//	else if (inp == 2)
//	{
//		/*printf("Введите номер паспорта: ");
//		strcpy(prof[prof_num].human.pd.number, write_pd(4));
//		printf("Введите серию паспорта: ");
//		strcpy(prof[prof_num].human.pd.series, write_pd(6));*/
//	}
//	else if (inp == 3)
//	{
//		printf("Введите возраст: ");
//		prof[prof_num].human.age = write_num(125);
//	}
//	else if (inp == 4)
//	{
//		printf("Введите предмет: ");
//		char subject[30];
//		gets_s(subject);
//		strcpy(prof[prof_num].subject, subject);
//	}
//	else if (inp == 5)
//	{
//		printf("Введите размер зарплаты: ");
//		prof[prof_num].wage = write_num(100000);
//	}
//	else if (inp == 6)
//	{
//		printf("Введите стаж преподавания: ");
//		prof[prof_num].experience = write_num(prof[prof_num].human.age);
//	}
//}
void Professor::prof_analysis(int count_prof, int* prof_sum_age, int* prof_sum_wage,
	int* count_professors, int* max_wage, int* min_wage, int* sum_experience)
{
	system("cls");
	if (!*count_professors)
	{
		*max_wage = this->wage;
		*min_wage = this->wage;
	}
	else if (this->wage > *max_wage)
	{
		*max_wage = this->wage;
	}
	else if (this->wage < *min_wage)
	{
		*min_wage = this->wage;
	}
	*prof_sum_wage += this->wage;
	*count_professors += 1;
	*sum_experience += this->experience;
	*prof_sum_age += this->human.age;
}

//void prof_analysis(struct Professor prof[], int count_prof)
//{
//	system("cls");
//	int prof_sum_age = 0, prof_sum_wage = 0, count_professors = 0, max_wage = 0, min_wage = 0, sum_experience = 0;
//	for (int i = 0; i < count_prof; i++)
//	{
//		if (!count_professors)
//		{
//			max_wage = prof[i].wage;
//			min_wage = prof[i].wage;
//		}
//		else if (prof[i].wage > max_wage)
//		{
//			max_wage = prof[i].wage;
//		}
//		else if (prof[i].wage < min_wage)
//		{
//			min_wage = prof[i].wage;
//		}
//		prof_sum_wage += prof[i].wage;
//		count_professors++;
//		prof_sum_age += prof[i].human.age;
//		sum_experience += prof[i].experience;
//	}
//	if (count_professors)
//		prof_info(prof_sum_age, count_professors, prof_sum_wage, max_wage, min_wage, sum_experience);
//	else
//		printf("Данные не введены!\n\n");
//	printf("Нажмите любую клавишу, чтобы продолжить");
//	_getch();
//}
//

void Professor::InputProf()
{
	system("cls");
	cout << "Введите фамилию преподавателя: ";
	this->human.fio.lastname = write_str(29);
	cout << "Введите имя преподавателя: ";
	this->human.fio.firstname = write_str(29);
	cout << "Введите отчество преподавателя: ";
	this->human.fio.middle = write_str(29);
	cout << "Введите возраст: ";
	this->human.age = write_num(125);
	cout << "Введите номер паспорта: ";
	this->human.pd.number = write_pd(4);
	cout << "Введите серию паспорта: ";
	this->human.pd.series = write_pd(6);
	cout << "Введите размер заработной платы: ";
	this->wage = write_num(100000);
	cout << "Введите предмет: ";
	cin >> this->subject;
	cout << "Введите стаж: ";
	this->experience = write_num(this->human.age-1);
}
void Professor::OutputProf(int i)
{
	cout << to_string(i + 1) + "-й человек: " << endl;
	cout << "---------------------------------" << endl;
	cout << "ФИО: " + this->human.fio.lastname + " " + this->human.fio.firstname + " " + this->human.fio.middle << endl;
	cout << "Паспортные данные: " + this->human.pd.number + " " + this->human.pd.series << endl;
	cout << "Возраст: " + to_string(this->human.age) << endl;
	cout << "Предмет: " + this->subject << endl;
	cout << "Заработная плата: " + to_string(this->wage) << endl;
	cout << "Стаж: " + to_string(this->experience) << endl;
	cout << "---------------------------------\n\n" << endl;
}