#pragma once
#include "FIO.h"
#include "pd.h"
#include "Student.h"
#include "Professor.h"

struct Human
{
	struct FIO fio;
	struct passport_data pd;
	int age;
};

Human HumanInit();