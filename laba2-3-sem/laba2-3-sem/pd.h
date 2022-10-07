#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>

struct passport_data
{
	char number[5];
	char series[7];
};

passport_data passport_dataInit(char *num, char *ser);