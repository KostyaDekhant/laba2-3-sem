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
			printf("������. ������� �����: ");
		}
		if (inp < 1 || inp > size)
			printf("������� ������������ �����, ������� ��� ���: \n");
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
			cout << "������ ������� �������!\n������� ��� ���: ";
			continue;
		}
		for (int i = 0; i < word_len; i++)
		{
			if (!isalpha((unsigned char)word[i]))
			{
				correct = false;
				cout << "������ ������ �������� ������ �� ����!\n������� ��� ���: ";
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
			cout << "������ �� ������������ ����������!\n������� ��� ���: ";
			correct = false;
		}
		else
			for (int i = 0; i < word_len; i++)
			{
				if (!isdigit(word[i]))
				{
					correct = false;
					while (getchar() != '\n');
					cout << "������ ������ �������� ������ �� ����!\n������� ��� ���: ";
					break;
				}
			}
	} while (!correct);
	return word;
}

void print_choise()
{
	system("cls");
	printf("�������� ��������:\n"
		"1. ������ ������ � ��������\n"
		"2. ������ ������ � �������������\n"
		"3. ������� ������ � ���������\n"
		"4. ������� ������ � ��������������\n"
		"5. ������ ���������� � ���������\n"
		"6. ������ ���������� � ��������������\n"
		"7. �������� ������ � ���������\n"
		"8. �������� ������ � ������������\n"
		"9. ��������� ������.\n");
}

void stud_info(int sum_ages, int count_st, int sum_scholarship, int max_scholarship, int min_scholarship)
{
	cout << "���������� � ���������: \n" << endl;;
	cout << "---------------------------------" << endl;
	cout << "������� ������� ��������: " + to_string(sum_ages / count_st) << endl;
	cout << "������� ��������� ��������: " + to_string(sum_scholarship / count_st) << endl;
	cout << "������������ ��������� ��������: " + to_string(max_scholarship) << endl;
	cout << "����������� ��������� ��������: " + to_string(min_scholarship) << endl;
	cout << "---------------------------------" << endl;
}

void InputProf(int* age, int* wg, int* exp, string num, string ser, string first, string mid, string last, string sub)
{
	system("cls");
	cout << "������� ������� �������������: ";
	last = write_str(29);
	cout << "������� ��� �������������: ";
	first = write_str(29);
	cout << "������� �������� �������������: ";
	mid = write_str(29);
	cout << "������� �������: ";
	*age = write_num(125);
	cout << "������� ����� ��������: ";
	num = write_str(4);
	cout << "������� ����� ��������: ";
	ser = write_str(6);
	cout << "������� ���� �������������: ";
	*exp = write_num(*age);
	cout << "������� ������ ���������� �����: ";
	*wg = write_num(1000000);
	cout << "������� ������������� �������: ";
	cin >> sub;
}

void prof_info(int sum_ages, int count_pr, int sum_wage, int max_wage, int min_wage, int sum_exp)
{
	cout << "���������� � ���������: \n" << endl;;
	cout << "---------------------------------" << endl;
	cout << "������� ������� �������������:: " + to_string(sum_ages / count_pr) << endl;
	cout << "������� ��������� �������������:: " + to_string(sum_wage / count_pr) << endl;
	cout << "������� ���� �������������: " +  to_string(sum_exp / count_pr) << endl;
	cout << "������������ ��������: " + to_string(max_wage) << endl;
	cout << "����������� ��������: " + to_string(min_wage) << endl;
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
			cout << "������ �� �������" << endl;
		}
		cout << "������� ����� �������, ����� ����������" << endl;
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
			cout << "������ �� �������" << endl;
		}
		cout << "������� ����� �������, ����� ����������" << endl;
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
			cout << "������ �� �������" << endl;
		}
		cout << "������� ����� �������, ����� ����������";
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
			cout << "������ �� �������" << endl;
		}
		cout << "������� ����� �������, ����� ����������";
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
		printf("\n������� ����� �������, ����� ����������");
		_getch();
		return 0;
	}
	printf("�������� ����� ��������: ");
	int stud_num = write_num(count_stud);
	system("cls");
	printf("��������, ��� ����� ��������: \n"
		"1. ���\n"
		"2. ���������� ������\n"
		"3. �������\n"
		"4. ������\n"
		"5. ������ ���������\n\n"
		"6. ��������� �������\n");
	return stud_num;
}

int print_change_choise_prof(struct Professor prof[], int count_prof)
{
	system("cls");
	//OutputProf(prof, count_prof, false);
	if (!count_prof)
	{
		printf("\n������� ����� �������, ����� ����������");
		_getch();
		return 0;
	}
	printf("�������� ����� �������������: ");
	int stud_num = write_num(count_prof);
	system("cls");
	printf("��������, ��� ����� ��������: \n"
		"1. ���\n"
		"2. ���������� ������\n"
		"3. �������\n"
		"4. �������\n"
		"5. ������ ��������\n"
		"6. ���� �������������\n\n"
		"7. ��������� �������\n");
	return stud_num;
}

void init_stud(struct Student stud[], int *count_stud)
{
	char gr[10] = "��11", f[25] = "��������", i[25] = "����", o[25] = "��������", num[5] = "1234", ser[7] = "567890";
	//stud[0] = StudentInit(gr, 10000, HumanInit(19, FIOInit(i, o, f), passport_dataInit(num, ser)));
	strcpy(f, "�������");
	strcpy(i, "�����");
	strcpy(o, "�������������");
	strcpy(num, "0987");
	strcpy(ser, "654321");
	//stud[1] = StudentInit(gr, 8000, HumanInit(18, FIOInit(i, o, f), passport_dataInit(num, ser)));
	*count_stud += 2;
}

void init_prof(struct Professor prof[], int *count_prof)
{
	char f[25] = "������", i[25] = "�������", o[25] = "��������������", num[5] = "1234", 
		ser[7] = "567890", sub[20] = "����������";
	//prof[0] = ProfessorInit(25000, 20, sub, HumanInit(45, FIOInit(i, o ,f), passport_dataInit(num, ser)));
	strcpy(f, "������");
	strcpy(i, "����");
	strcpy(o, "��������");
	strcpy(num, "8765");
	strcpy(ser, "094321");
	strcpy(sub, "������");
	//prof[1] = ProfessorInit(20000, 15, sub, HumanInit(40, FIOInit(i, o, f), passport_dataInit(num, ser)));
	*count_prof += 2;
}