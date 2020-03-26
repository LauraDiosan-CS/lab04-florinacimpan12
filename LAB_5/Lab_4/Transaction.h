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

class Transaction
{
private:

	int ziua;
	int suma;
	char* tip;
	char* descriere;

public:
	Transaction();
	Transaction(int ziua, int suma, char* tip, char* descriere);
	Transaction(const Transaction& t);
	~Transaction();
	void set_day(int ziua);
	void set_sum(int suma);
	void set_type(char* tip);
	void set_description(char* descriere);
	int get_day();
	int get_sum();
	char* get_type();
	char* get_description();
	
	Transaction& operator=(const Transaction& t);
	bool operator==(const Transaction& s);
	friend ostream& operator<<(ostream& os,const Transaction& s);

};
