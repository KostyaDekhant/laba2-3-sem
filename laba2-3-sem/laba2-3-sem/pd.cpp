#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "pd.h"

passport_data passport_dataInit(string num, string ser)
{
	passport_data pd;
	pd.number = num;
	pd.series = ser;
	return pd;
}
