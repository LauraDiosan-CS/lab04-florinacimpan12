#include "Transaction.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;


Transaction::Transaction()
{ ///default constructor
	this->ziua = 0;
	this->suma = 0;
	this->tip = NULL;
	this->descriere = NULL;

}

Transaction::Transaction(int day, int sum, char* type, char* description)
{ ///constructor with parameters
	this->ziua = day;
	this->suma = sum;
	this->tip = new char[1 + strlen(type)];
	strcpy_s(this->tip, 1 + strlen(type), type);
	this->descriere = new char[1 + strlen(description)];
	strcpy_s(this->descriere, 1 + strlen(description), description);

}

Transaction::Transaction(const Transaction& t)
{	///copy constructor
	this->ziua = t.ziua;
	this->suma = t.suma;
	this->tip = new char[1 + strlen(t.tip)];
	strcpy_s(this->tip, 1 + strlen(t.tip), t.tip);
	this->descriere = new char[1 + strlen(t.descriere)];
	strcpy_s(this->descriere, 1 + strlen(t.descriere), t.descriere);

}

Transaction::~Transaction()
{	///desctructor
	if (this->tip)
	{
		delete[] this->tip;
		this->tip = NULL;

	}
	if (this->descriere) {
		delete[] this->descriere;
		this->descriere = NULL;
	}

}

int Transaction::get_day() {
	return this->ziua;
}

int Transaction::get_sum() {
	return this->suma;
}

char* Transaction::get_type() {

	return this->tip;
}

char* Transaction::get_description() {

	return this->descriere;
}

void Transaction::set_day(int day) {
	this->ziua = day;
}

void Transaction::set_sum(int sum) {
	this->suma = sum;

}

void Transaction::set_type(char* type) {
	if (this->tip != NULL)
	{
		delete[] this->tip;
		this->tip = NULL;

	}
	this->tip = new char[1 + strlen(type)];
	strcpy_s(this->tip, 1 + strlen(type), type);
}

void Transaction::set_description(char* description) {
	if (this->descriere != NULL) {

		delete[] this->descriere;
		this->descriere = NULL;
	}
	this->descriere = new char[1 + strlen(description)];
	strcpy_s(this->descriere, 1 + strlen(description), description);
}

Transaction& Transaction::operator=(const Transaction& t) {
	this->set_day(t.ziua);
	this->set_sum(t.suma);
	this->set_type(t.tip);
	this->set_description(t.descriere);
	return *this;
}

ostream& operator<<(ostream& os, const Transaction& s)
{
	os << s.ziua << " " << s.suma << " " << s.tip << " " << s.descriere << endl;;
	return os;
}

bool Transaction:: operator==(const Transaction& t) {
	return (this->ziua==t.ziua) && (this->suma==t.suma) && (strcmp(this->tip,t.tip) == 0) && (strcmp(this->descriere, t.descriere)==0);
}

//char* Transaction::to_string()
//{
//	int length_string = 2 + 1 + 3 + 1 + 10 + 1;
//	char* string_name = new char[length_string];
//	char* number = new char[2];
//	_itoa(this->day, number,10);
//	strcat(string_name, number);
//	strcat(string_name, " ");
//	strcat(string_name, this->type);
//	strcat(string_name, " ");
//	strcat(string_name, this->description);
//
//	return string_name;
//
//}
