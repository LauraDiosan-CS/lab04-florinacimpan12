#include "Tests.h"
#include "Transaction.h"
#include "Repo.h"
#include "Service.h"
#include <cassert>


void Tests_transaction::test_transaction_sets() {
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];


	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction = Transaction(1, 23, type, description);
	
	transaction.set_day(2);
	transaction.set_sum(24);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("descriere_2")];

	strcpy_s(description_2, 1 + strlen("descriere_2"), "descriere_2");
	strcpy_s(type_2, 1 + strlen("out"), "out");


	transaction.set_description(description_2);
	transaction.set_type(type_2);
	
	
	assert(transaction.get_day() == 2);
	assert(transaction.get_sum() == 24);
	assert(strcmp(transaction.get_type(), "out") == 0);
	assert(strcmp(transaction.get_description(), "descriere_2") == 0);

	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
}
void Tests_transaction::test_transaction_gets() {
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction = Transaction(1, 23, type, description);
	assert(transaction.get_day() == 1);
	assert(transaction.get_sum() == 23);
	assert(strcmp(transaction.get_type(),"in")==0);
	assert(strcmp(transaction.get_description(),"descriere")==0);
	

}


void Tests_repo::test_repo_add() {
	Repo r = Repo();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");

	
	Transaction transaction_1= Transaction(1, 23, type, description);

	r.add_transaction(transaction_1);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("descriere_2")];

	strcpy_s(type_2, 1 + strlen("out"), "out");

	strcpy_s(description_2, 1 + strlen("descriere_2"), "descriere_2");


	Transaction transaction_2 = Transaction(1, 23, type_2, description_2);

	r.add_transaction(transaction_2);

	

	assert(r.get_size() == 2);
	assert(r.get_all()[0] == transaction_1);
	assert(r.get_all()[1] == transaction_2);

	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
}

void Tests_transaction::test_transaction_operator()
{
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];


	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction_1 = Transaction(1, 23, type, description);
	Transaction transaction_2 = Transaction(1, 23, type, description);
	

	assert(transaction_1 == transaction_2);
	transaction_2.set_day(2);
	assert(not(transaction_1 == transaction_2));
	delete[] type;
	delete[] description;


}



void Tests_repo::test_repo_delete()
{
	Repo r = Repo();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction_1 = Transaction(1, 23, type, description);

	r.add_transaction(transaction_1);


	assert(r.get_size() == 1);
	assert(r.get_all()[0] == transaction_1);


	r.delete_transaction(transaction_1);

	assert(r.get_size() == 0);

	delete[] type;
	delete[] description;

}

void Tests_service::test_add_transaction()
{
	Service s = Service();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");
	s.add_transaction(10, 30, type, description);
	
	assert(s.get_size_repo(), 1);

}

void Tests_service::test_delete_transaction() {
	Service s = Service();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");
	s.add_transaction(10, 30, type, description);

	assert(s.get_size_repo(), 1);

	s.delete_transactions_by_day(10);

	assert(s.get_size_repo(), 0);
}

void Tests_service::test_sum_by_type()
{
	Service s = Service();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("descriere_2")];

	strcpy_s(type_2, 1 + strlen("out"), "out");
	strcpy_s(description_2, 1 + strlen("descriere_2"), "descriere_2");

	s.add_transaction(10, 30, type, description);
	s.add_transaction(12, 20, type_2, description_2);

	assert(s.sum_by_type(type), 30);

}
