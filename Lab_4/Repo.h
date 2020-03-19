#pragma once
#include "Transaction.h"
#include <cstddef>

class Repo {
private:
	int n;
	Tranzactie tranzactii[10];
public:
	Repo();
	~Repo();
	void adauga_tranzactie(Tranzactie t);
	Tranzactie* get_all();
	int get_size();
};
