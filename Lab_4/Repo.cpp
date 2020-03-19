#include "Repo.h"
#include <cstddef>


Repo::Repo()
{

	this->n = 0;

}

Repo::~Repo() {

	this->n = 0;
}

void Repo::adauga_tranzactie(Tranzactie t) {
	this->tranzactii[this->n++] = t;


}

Tranzactie* Repo::get_all() {

	return this->tranzactii;
}

int Repo::get_size() {

	return this->n;

}
