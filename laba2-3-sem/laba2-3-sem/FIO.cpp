#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "FIO.h"

FIO FIOInit(string first, string mid, string last)
{
	FIO	fio;
	fio.firstname = first;
	fio.middle = mid;
	fio.lastname = last;
	return fio;
}
