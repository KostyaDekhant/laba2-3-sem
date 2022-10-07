#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "FIO.h"

FIO FIOInit(char *first, char* mid, char* last)
{
	FIO	fio;
	strcpy(fio.firstname,first);
	strcpy(fio.middle,mid);
	strcpy(fio.lastname,last);
	return fio;
}
