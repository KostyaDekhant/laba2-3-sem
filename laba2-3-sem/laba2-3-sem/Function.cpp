#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student.h"
#include "Professor.h"
#include "Function.h"

int write_num(int size) 
{
	int inp = 0;
	do {
		while (scanf("%d", &inp) != 1) {
			while (getchar() != '\n');
			printf("Ошибка. Введите число: ");
		}
		if (inp < 1 || inp > size)
			printf("Введено неправильное число, введите ещё раз: \n");
	} while (inp < 1 || inp > size);
	while (getchar() != '\n');
	return inp;
}

string write_str(int size)
{
	bool correct;
	//char word[30];
	string word;
	do {
		correct = true;
		cin >> word;
		int word_len = word.length();
		if (word_len > size) {
			cout << "Строка слишком длинная!\nВведите ещё раз: ";
			continue;
		}
		for (int i = 0; i < word_len; i++)
		{
			if (!isalpha((unsigned char)word[i]))
			{
				correct = false;
				cout << "Строка должна состоять только из букв!\nВведите ещё раз: ";
				break;
			}
		}
	} while (!correct);
	return word;
}

string write_pd(int size)
{
	bool correct;
	string word;
	do {
		correct = true;
		cin >> word;
		int word_len = word.length();
		if (word_len != size){
			cout << "Строка не соотвествует стандартам!\nВведите ещё раз: ";
			correct = false;
		}
		else
			for (int i = 0; i < word_len; i++)
			{
				if (!isdigit(word[i]))
				{
					correct = false;
					while (getchar() != '\n');
					cout << "Строка должна состоять только из цифр!\nВведите ещё раз: ";
					break;
				}
			}
	} while (!correct);
	return word;
}

void print_choise()
{
	system("cls");
	printf("Выберите действие:\n"
		"1. Ввести данные о студенте\n"
		"2. Ввести данные о преподавателе\n"
		"3. Вывести данные о студентах\n"
		"4. Вывести данные о преподавателях\n"
		"5. Анализ информации о студентах\n"
		"6. Анализ информации о преподавателях\n"
		"7. Изменить данные о студентах\n"
		"8. Изменить данные о преподателях\n"
		"9. Закончить работу.\n");
}

void stud_info(int sum_ages, int count_st, int sum_scholarship, int max_scholarship, int min_scholarship)
{
	cout << "Статистика о студентах: \n" << endl;;
	cout << "---------------------------------" << endl;
	cout << "Средний возраст студента: " + to_string(sum_ages / count_st) << endl;
	cout << "Средняя стипендия студента: " + to_string(sum_scholarship / count_st) << endl;
	cout << "Максимальная стипендия студента: " + to_string(max_scholarship) << endl;
	cout << "Минимальная стипендия студента: " + to_string(min_scholarship) << endl;
	cout << "---------------------------------" << endl;
}

void InputProf(int* age, int* wg, int* exp, string num, string ser, string first, string mid, string last, string sub)
{
	system("cls");
	cout << "Введите фамилию преподавателя: ";
	last = write_str(29);
	cout << "Введите имя преподавателя: ";
	first = write_str(29);
	cout << "Введите отчество преподавателя: ";
	mid = write_str(29);
	cout << "Введите возраст: ";
	*age = write_num(125);
	cout << "Введите номер паспорта: ";
	num = write_str(4);
	cout << "Введите серию паспорта: ";
	ser = write_str(6);
	cout << "Введите стаж преподавателя: ";
	*exp = write_num(*age);
	cout << "Введите размер заработной платы: ";
	*wg = write_num(1000000);
	cout << "Введите преподаваемый предмет: ";
	cin >> sub;
}

void prof_info(int sum_ages, int count_pr, int sum_wage, int max_wage, int min_wage, int sum_exp)
{
	cout << "Статистика о студентах: \n" << endl;;
	cout << "---------------------------------" << endl;
	cout << "Средний возраст преподавателя:: " + to_string(sum_ages / count_pr) << endl;
	cout << "Средняя стипендия преподавателя:: " + to_string(sum_wage / count_pr) << endl;
	cout << "Средний стаж преподавателя: " +  to_string(sum_exp / count_pr) << endl;
	cout << "Максимальная зарплата: " + to_string(max_wage) << endl;
	cout << "Минимальная зарплата: " + to_string(min_wage) << endl;
	cout << "---------------------------------" << endl;
}

void act_choise(int inp, int *count_stud, int *count_prof, class Student *stud, class Professor prof[])
{
	int age = 0, scholar = 0, wg = 0, exp = 0; string num = "" ,ser = "", first = "", mid = "",
		last = "", gr = "",  sub = "";
	if (inp == 1)
	{
		stud[*count_stud].InputStud();
		*count_stud += 1;
	}
	else if (inp == 2)
	{
		prof[*count_prof].InputProf();
		*count_prof += 1;
	}
	else if (inp == 3)
	{
		system("cls");
		if (*count_stud)
		{
			for (int i = 0; i < *count_stud; i++)
			{
				stud[i].OutputStud(i);
			}
		}
		else
		{
			cout << "Данные не введены" << endl;
		}
		cout << "Нажмите любую клавишу, чтобы продолжить" << endl;
		_getch();
	}
	else if (inp == 4)
	{
		system("cls");
		if (*count_prof)
		{
			for (int i = 0; i < *count_prof; i++)
			{
				prof[i].OutputProf(i);
			}
		}
		else
		{
			cout << "Данные не введены" << endl;
		}
		cout << "Нажмите любую клавишу, чтобы продолжить" << endl;
		_getch();
	}
	else if (inp == 5)
	{
		int stud_sum_age = 0, stud_sum_scholarship = 0,
			count_students = 0, max_scholarship = 0, min_scholarship = 0;
		if (*count_stud)
		{
			for (int i = 0; i < *count_stud; i++)
			{
				stud[i].stud_analysis(*count_stud, &stud_sum_age, &stud_sum_scholarship,
				&count_students, &max_scholarship, &min_scholarship);
			}
			stud_info(stud_sum_age, count_students, 
				stud_sum_scholarship, max_scholarship, min_scholarship);
		}
		else
		{
			system("cls");
			cout << "Данные не введены" << endl;
		}
		cout << "Нажмите любую клавишу, чтобы продолжить";
		_getch();
	}
	else if (inp == 6)
	{
		int prof_sum_age = 0, prof_sum_wage = 0,
			count_professors = 0, max_wage = 0, min_wage = 0, sum_experience = 0;
		if (*count_prof)
		{
			for (int i = 0; i < *count_prof; i++)
			{
				prof[i].prof_analysis(*count_prof, &prof_sum_age, &prof_sum_wage,
					&count_professors, &max_wage, &min_wage, &sum_experience);
			}
			prof_info(prof_sum_age, count_professors,
				prof_sum_wage, max_wage, min_wage, sum_experience);
		}
		else
		{
			system("cls");
			cout << "Данные не введены" << endl;
		}
		cout << "Нажмите любую клавишу, чтобы продолжить";
		_getch();
	}
	else if (inp == 7)
	{
		//ChangeInfo(stud, *count_stud);
	}
	else if (inp == 8)
	{
		//ChangeInfo_prof(prof, *count_prof);
	}
}

int print_change_choise(class Student stud[], int count_stud)
{
	system("cls");
	//OutputStud(stud, count_stud, false);
	if (!count_stud)
	{
		printf("\nНажмите любую клавишу, чтобы продолжить");
		_getch();
		return 0;
	}
	printf("Выберите номер студента: ");
	int stud_num = write_num(count_stud);
	system("cls");
	printf("Выберите, что нужно изменить: \n"
		"1. ФИО\n"
		"2. Паспортные данные\n"
		"3. Возраст\n"
		"4. Группа\n"
		"5. Размер стипендии\n\n"
		"6. Вернуться обратно\n");
	return stud_num;
}

int print_change_choise_prof(struct Professor prof[], int count_prof)
{
	system("cls");
	//OutputProf(prof, count_prof, false);
	if (!count_prof)
	{
		printf("\nНажмите любую клавишу, чтобы продолжить");
		_getch();
		return 0;
	}
	printf("Выберите номер преподавателя: ");
	int stud_num = write_num(count_prof);
	system("cls");
	printf("Выберите, что нужно изменить: \n"
		"1. ФИО\n"
		"2. Паспортные данные\n"
		"3. Возраст\n"
		"4. Предмет\n"
		"5. Размер зарплаты\n"
		"6. Стаж преподавателя\n\n"
		"7. Вернуться обратно\n");
	return stud_num;
}

void init_stud(struct Student stud[], int *count_stud)
{
	char gr[10] = "ПИ11", f[25] = "Васильев", i[25] = "Иван", o[25] = "Петрович", num[5] = "1234", ser[7] = "567890";
	//stud[0] = StudentInit(gr, 10000, HumanInit(19, FIOInit(i, o, f), passport_dataInit(num, ser)));
	strcpy(f, "Соболев");
	strcpy(i, "Игорь");
	strcpy(o, "Александрович");
	strcpy(num, "0987");
	strcpy(ser, "654321");
	//stud[1] = StudentInit(gr, 8000, HumanInit(18, FIOInit(i, o, f), passport_dataInit(num, ser)));
	*count_stud += 2;
}

void init_prof(struct Professor prof[], int *count_prof)
{
	char f[25] = "Петров", i[25] = "Алексей", o[25] = "Константинович", num[5] = "1234", 
		ser[7] = "567890", sub[20] = "Математика";
	//prof[0] = ProfessorInit(25000, 20, sub, HumanInit(45, FIOInit(i, o ,f), passport_dataInit(num, ser)));
	strcpy(f, "Иванов");
	strcpy(i, "Иван");
	strcpy(o, "Иванович");
	strcpy(num, "8765");
	strcpy(ser, "094321");
	strcpy(sub, "Физика");
	//prof[1] = ProfessorInit(20000, 15, sub, HumanInit(40, FIOInit(i, o, f), passport_dataInit(num, ser)));
	*count_prof += 2;
}