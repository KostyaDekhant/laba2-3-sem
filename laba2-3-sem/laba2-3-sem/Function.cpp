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

char *write_str(int size)
{
	bool correct;
	char word[30];
	//string word;
	do {
		correct = true;
		gets_s(word);
		int word_len = strlen(word);
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

char* write_pd(int size)
{
	bool correct;
	char word[100];
	do {
		correct = true;
		gets_s(word);
		int word_len = strlen(word);
		if (word_len != size){
			printf("������ �� ������������ ����������!\n������� ��� ���: ");
			correct = false;
		}
		else
			for (int i = 0; i < word_len; i++)
			{
				if (!isdigit(word[i]))
				{
					correct = false;
					while (getchar() != '\n');
					printf("������ ������ �������� ������ �� ����!\n������� ��� ���: ");
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

void stud_info(int sum_ages, int count_st, int sum_scholarship, int max_scholarship, int min_scholarship)
{
	printf("���������� � ���������: \n\n");
	printf("---------------------------------\n");
	printf("������� ������� ��������: %d\n", sum_ages / count_st);
	printf("������� ��������� ��������: %d\n", sum_scholarship / count_st);
	printf("������������ ��������� ��������: %d\n", max_scholarship);
	printf("����������� ��������� ��������: %d\n", min_scholarship);
	printf("---------------------------------\n");
}

void InputProf(int* age, int* wg, int* exp, char* num, char* ser, char* first, char* mid, char* last, char* sub)
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

void act_choise(int inp, int *count_stud, int *count_prof, class Student stud[], struct Professor *prof)
{
	int age = 0, scholar = 0, wg = 0, exp = 0; char num[5] = "", ser[7] = "", first[25] = "", mid[25] = "", 
		last[25] = "", gr[10] = "",  sub[30] = "";
	if (inp == 1)
	{
		InputStud(&age, &scholar, num, ser, first, mid, last, gr);
		stud[*count_stud] = StudentInit(gr, scholar, HumanInit(age, FIOInit(first, mid, last), passport_dataInit(num, ser)));
		//stud[*count_stud] = Student(gr, last, first, mid, num, ser,scholar, age);
		*count_stud += 1;
	}
	else if (inp == 2)
	{
		InputProf(&age, &wg, &exp, num, ser, first, mid, last, sub);
		prof[*count_prof] = ProfessorInit(wg, exp, sub, HumanInit(age, FIOInit(first, mid, last), passport_dataInit(num, ser)));
		*count_prof += 1;
	}
	else if (inp == 3)
	{
		OutputStud(stud, *count_stud, true);
	}
	else if (inp == 4)
	{
		OutputProf(prof, *count_prof, true);
	}
	else if (inp == 5)
	{
		stud_analysis(stud, *count_stud);
	}
	else if (inp == 6)
	{
		prof_analysis(prof, *count_prof);
	}
	else if (inp == 7)
	{
		ChangeInfo(stud, *count_stud);
	}
	else if (inp == 8)
	{
		ChangeInfo_prof(prof, *count_prof);
	}
}

int print_change_choise(struct Student stud[], int count_stud)
{
	system("cls");
	OutputStud(stud, count_stud, false);
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
	OutputProf(prof, count_prof, false);
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
	stud[0] = StudentInit(gr, 10000, HumanInit(19, FIOInit(i, o, f), passport_dataInit(num, ser)));
	strcpy(f, "�������");
	strcpy(i, "�����");
	strcpy(o, "�������������");
	strcpy(num, "0987");
	strcpy(ser, "654321");
	stud[1] = StudentInit(gr, 8000, HumanInit(18, FIOInit(i, o, f), passport_dataInit(num, ser)));
	*count_stud += 2;
}

void init_prof(struct Professor prof[], int *count_prof)
{
	char f[25] = "������", i[25] = "�������", o[25] = "��������������", num[5] = "1234", 
		ser[7] = "567890", sub[20] = "����������";
	prof[0] = ProfessorInit(25000, 20, sub, HumanInit(45, FIOInit(i, o ,f), passport_dataInit(num, ser)));
	strcpy(f, "������");
	strcpy(i, "����");
	strcpy(o, "��������");
	strcpy(num, "8765");
	strcpy(ser, "094321");
	strcpy(sub, "������");
	prof[1] = ProfessorInit(20000, 15, sub, HumanInit(40, FIOInit(i, o, f), passport_dataInit(num, ser)));
	*count_prof += 2;
}