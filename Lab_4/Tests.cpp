#include "Tests.h"
#include "Transaction.h"
#include "Repo.h"
#include <cassert>

void test_transaction_gets() {
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Tranzactie transaction = Tranzactie(5, 30, type, description);
	assert(transaction.get_zi() == 5);
	assert(transaction.get_suma() == 30);
	assert(strcmp(transaction.get_tip(),"in")==0);
	assert(strcmp(transaction.get_descriere(),"descriere")==0);
	

}

void test_transaction_sets() {
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];


	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Tranzactie transaction = Tranzactie(1, 23, type, description);
	
	transaction.set_zi(2);
	transaction.set_suma(24);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("descriere_2")];

	strcpy_s(description_2, 1 + strlen("descriere_2"), "descriere_2");
	strcpy_s(type_2, 1 + strlen("out"), "out");


	transaction.set_descriere(description_2);
	transaction.set_tip(type_2);
	
	
	assert(transaction.get_zi() == 2);
	assert(transaction.get_suma() == 24);
	assert(strcmp(transaction.get_tip(), "out") == 0);
	assert(strcmp(transaction.get_descriere(), "descriere_2") == 0);



}

void test_repo() {
	Repo r = Repo();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");

	
	Tranzactie transaction_1= Tranzactie(1, 23, type, description);

	r.adauga_tranzactie(transaction_1);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("descriere_2")];

	strcpy_s(type_2, 1 + strlen("out"), "out");

	strcpy_s(description_2, 1 + strlen("descriere_2"), "descriere_2");


	Tranzactie transaction_2 = Tranzactie(1, 23, type_2, description_2);

	r.adauga_tranzactie(transaction_2);

	

	assert(r.get_size() == 2);
	assert(r.get_all()[0] == transaction_1);
	assert(r.get_all()[1] == transaction_2);

	
}