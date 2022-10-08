#pragma once
#include "FIO.h"
#include "pd.h"
//#include "Student.h"
//#include "Professor.h"

class Human
{
public:
	class FIO fio;
	class passport_data pd;
	int age;
};

//Human HumanInit(int inpage, struct FIO Fio, struct passport_data Pd);