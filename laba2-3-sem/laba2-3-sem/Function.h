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

void print_change_choise(class Student stud[], int count_stud, int* stud_num);
void print_change_choise_prof(class Professor prof[], int count_prof, int* prof_num);

void stud_info(int sum_ages, int count_st, int sum_scholarship, int max_scholarship, int min_scholarship);
void prof_info(int sum_ages, int count_pr, int sum_wage, int max_wage, int min_wage, int sum_exp);