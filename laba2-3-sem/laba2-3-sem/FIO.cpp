#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "FIO.h"

FIO::FIO()
{
	this->firstname = "����";
	this->middle = "��������";
	this->lastname = "������";
}
FIO::FIO(string first)
{
	this->firstname = first;
	this->middle = "��������";
	this->lastname = "������";
}
FIO::FIO(string first, string mid, string last)
{
	this->firstname = first;
	this->middle = mid;
	this->lastname = last;
}
FIO::~FIO()
{

}

string FIO::getFirst()
{
	return this->firstname;
}
string FIO::getMid()
{
	return this->middle;
}
string FIO::getLast()
{
	return this->lastname;
}

void FIO::setFirst(string first)
{
	firstname = first;
}
void FIO::setMid(string mid)
{
	middle = mid;
}
void FIO::setLast(string last)
{
	lastname = last;
}