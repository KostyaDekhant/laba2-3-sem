#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Professor.h"
#include "Function.h"

Professor::Professor()
{
	Human initHuman;
	this->human = initHuman;
	this->wage = 25000;
	this->subject = "����������";
	this->experience = 20;
}
Professor::Professor(int wg)
{
	Human initHuman;
	this->human = initHuman;
	this->wage = wg;
	this->subject = "�����������";
	this->experience = 15;
}
Professor::Professor(int wg, int exp, string sub, class Human human)
{
	this->human = human;
	this->wage = wg;
	this->subject = sub;
	this->experience = exp;
}
Professor::~Professor()
{

}


void Professor::ChangeInfo()
{
	int inp;
	inp = write_num(7);
	if (inp == 7)
		return;
	else if (inp == 1)
	{
		string first, mid, last;
		cout << "������� ������� �������������: ";
		last = write_str(29);
		cout << "������� ��� �������������: ";
		first = write_str(29);
		cout << "������� �������� �������������: ";
		mid = write_str(29);
		this->human.setFIO(first, mid, last);
	}
	else if (inp == 2)
	{
		string num, ser;
		cout << "������� ����� ��������: ";
		num = write_pd(4);
		cout << "������� ����� ��������: ";
		ser = write_pd(6);
		this->human.setPD(num, ser);
	}
	else if (inp == 3)
	{
		cout << "������� �������: ";
		this->human.setAge(write_num(125));
	}
	else if (inp == 4)
	{
		cout << "������� �������� ��������: ";
		cin >> this->subject;
	}
	else if (inp == 5)
	{
		cout << "������� ������ ���������� �����: ";
		this->wage = write_num(100000);
	}
	else if (inp == 6)
	{
		cout << "������� ����: ";
		this->experience = write_num(this->human.getAge()-1);
	}
}

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
	*prof_sum_age += this->human.getAge();
}

void Professor::InputProf()
{
	system("cls");
	string first, mid, last, num, ser;
	cout << "������� ������� �������������: ";
	last = write_str(29);
	cout << "������� ��� �������������: ";
	first = write_str(29);
	cout << "������� �������� �������������: ";
	mid = write_str(29);
	this->human.setFIO(first, mid, last);
	cout << "������� �������: ";
	this->human.setAge(write_num(125));
	cout << "������� ����� ��������: ";
	num = write_pd(4);
	cout << "������� ����� ��������: ";
	ser = write_pd(6);
	this->human.setPD(num, ser);
	cout << "������� ������ ���������� �����: ";
	this->wage = write_num(100000);
	cout << "������� �������: ";
	cin >> this->subject;
	cout << "������� ����: ";
	this->experience = write_num(this->human.getAge() - 1);
}
void Professor::OutputProf(int i)
{
	cout << to_string(i + 1) + "-� �������: " << endl;
	cout << "---------------------------------" << endl;
	cout << "���: " + this->human.getFIO().getLast() + " " + this->human.getFIO().getFirst() + " " + this->human.getFIO().getMid() << endl;
	cout << "���������� ������: " + this->human.getPD().getNum() + " " + this->human.getPD().getSer() << endl;
	cout << "�������: " + to_string(this->human.getAge()) << endl;
	cout << "�������: " + this->subject << endl;
	cout << "���������� �����: " + to_string(this->wage) << endl;
	cout << "����: " + to_string(this->experience) << endl;
	cout << "---------------------------------\n\n" << endl;
}