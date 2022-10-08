#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>

int write_num(int size);
string write_str(int size);
string write_pd(int size);
void print_choise();
void act_choise(int inp, int* count_stud, int* count_prof, class Student *stud, class Professor prof[]);
int print_change_choise(struct Student stud[], int count_stud);
int print_change_choise_prof(struct Professor prof[], int count_prof);
void init_stud(struct Student stud[], int* count_stud);
void init_prof(struct Professor prof[], int* count_prof);
//void InputStud(int* age, int* scholar, string num, string ser, string first, string mid, string last, string sub);
void stud_info(int sum_ages, int count_st, int sum_scholarship, int max_scholarship, int min_scholarship);
void InputProf(int* age, int* wg, int* exp, string num, string ser, string first, string mid, string last, string sub);
void prof_info(int sum_ages, int count_pr, int sum_wage, int max_wage, int min_wage, int sum_exp);