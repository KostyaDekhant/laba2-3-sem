#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Student.h"

Student StudentInit(string gr, int scholar)
{
	Student stud;
	stud.group = gr;
	stud.scholarship = scholar;
	return stud;
}