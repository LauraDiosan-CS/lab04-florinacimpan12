#pragma once
#include "Repo.h"
#include "Transaction.h"
class Service {
	Repo r;
public:
	void add_transaction(int ziua, int suma, char* tip, char* descriere);
	Transaction* get_all();

	int get_size_repo();
	void delete_transactions_by_day(int ziua);
	
	void replace_sum_in_transaction(int replaced_ziua, int ziua, char* tip, char* descriere);
	void array_with_transaction_sum_b(Transaction transactions[], int &length,int suma);
	int sold_by_day(int ziua);
	Transaction most_valuable_by_day(int ziua);
	int sum_by_type(char* tip);
	void array_with_transaction_sum_equal(Transaction transactions[], int& length,int suma);
	void keep_by_type(char* tip);
	void delete_transactions_by_type(char* tip);
	void delete_transactions_between_days(int ziua1, int ziua2);	
	void keep_by_type_and_sum(char* tip,int suma);
	void array_with_transactions_by_type(char* tip, Transaction transactions[], int& length);

	
};

