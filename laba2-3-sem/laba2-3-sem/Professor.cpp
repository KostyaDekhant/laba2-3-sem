#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Professor.h"

Professor ProfessorInit(int wg, int exp, string sub)
{
	Professor prof;
	prof.wage = wg;
	prof.experience = exp;
	prof.subject = sub;
	return prof;
}