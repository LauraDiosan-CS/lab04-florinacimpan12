#pragma once
//Gestiune conturi bancare
//John vrea să - și gestioneze conturile bancare și are nevoie de o aplicație care să - i
//permită stocarea și vizualizarea tranzacțiilor bancare efectuate în contul său în timpul
//unei luni calendaristice.Fiecare tranzacție este identificată prin : ziua din lună când a
//fost efectuată(întreg între 1 și 28 / 29 / 30 / 31), suma de bani(întreg pozitiv), tip(in - au
//	intrat bani în cont - sau out - au ieșit bani din cont) și descriere.Creați o aplicație care
//	să - l ajute pe John oferindu - i următoarele funcționalități :
#include <ostream>

using namespace std;

class Tranzactie
{
private:
	int zi;
	int suma;
	char* tip;
	char* descriere;

public:
	Tranzactie();
	Tranzactie(int zi, int suma, char* tip, char* descriere);
	Tranzactie(const Tranzactie& t);
	~Tranzactie();
	int get_zi();
	int get_suma();
	char* get_tip();
	char* get_descriere();
	void set_zi(int day);
	void set_suma(int sum);
	void set_tip(char* type);
	void set_descriere(char* description);
	Tranzactie& operator=(const Tranzactie& t);
	bool operator==(const Tranzactie& s);
	friend ostream& operator<<(ostream& os, const Tranzactie& s);


};
