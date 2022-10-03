#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Professor.h"

Professor ProfessorInit(int wg, int exp, string sub, struct Human Human)
{
	Professor prof;
	prof.human = Human;
	prof.wage = wg;
	prof.experience = exp;
	prof.subject = sub;
	return prof;
}