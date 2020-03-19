#include "Transaction.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;


Tranzactie::Tranzactie()
{
	this->zi = 0;
	this->suma = 0;
	this->tip = NULL;
	this->descriere = NULL;

}

Tranzactie::Tranzactie(int day, int sum, char* type, char* description)
{
	this->zi = day;
	this->suma = sum;
	this->tip = new char[1 + strlen(type)];
	strcpy_s(this->tip, 1 + strlen(type), type);
	this->descriere = new char[1 + strlen(description)];
	strcpy_s(this->descriere, 1 + strlen(description), description);

}

Tranzactie::Tranzactie(const Tranzactie& t)
{
	this->zi = t.zi;
	this->suma = t.suma;
	this->tip = new char[1 + strlen(t.tip)];
	strcpy_s(this->tip, 1 + strlen(t.tip), t.tip);
	this->descriere = new char[1 + strlen(t.descriere)];
	strcpy_s(this->descriere, 1 + strlen(t.descriere), t.descriere);

}

Tranzactie::~Tranzactie()
{
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

int Tranzactie::get_zi() {
	return this->zi;
}

int Tranzactie::get_suma() {
	return this->suma;
}

char* Tranzactie::get_tip() {

	return this->tip;
}

char* Tranzactie::get_descriere() {

	return this->descriere;
}

void Tranzactie::set_zi(int day) {
	this->zi = day;
}

void Tranzactie::set_suma(int sum) {
	this->suma = sum;

}

void Tranzactie::set_tip(char* type) {
	this->tip = new char[1 + strlen(type)];
	strcpy_s(this->tip, 1 + strlen(type), type);
}

void Tranzactie::set_descriere(char* description) {
	this->descriere = new char[1 + strlen(description)];
	strcpy_s(this->descriere, 1 + strlen(description), description);
}

Tranzactie& Tranzactie::operator=(const Tranzactie& t) {
	this->set_zi(t.zi);
	this->set_suma(t.suma);
	this->set_tip(t.tip);
	this->set_descriere(t.descriere);
	return *this;
}

ostream& operator<<(ostream& os, const Tranzactie& s)
{
	os << s.zi << " " << s.suma<< " " <<s.tip<<" "<<s.descriere;
	return os;
}

bool Tranzactie:: operator==(const Tranzactie& t) {
	return (this->zi==t.zi) && (this->suma==t.suma) && (strcmp(this->tip,t.tip) == 0) && (strcmp(this->descriere, t.descriere)==0);
}