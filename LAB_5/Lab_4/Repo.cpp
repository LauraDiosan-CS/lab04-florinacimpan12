#include "Repo.h"
#include <cstddef>
#include <iostream>


Repo::Repo()
{

	this->n = 0;
	this->money_paid = 0;

}

Repo::~Repo() {

	this->n = 0;
}

void Repo::add_transaction(Transaction t) {

	this->transactions[this->n++] = t;
	this->money_paid+= t.get_sum();

}

Transaction* Repo::get_all() {

	return this->transactions;
}

int Repo::get_size() {

	return this->n;

}

int Repo::get_money_paid()
{
	return this->money_paid;
}



//void Repo::update_transaction(Transaction t1, Transaction t2)
//{
//	int size = this->get_size();
//	Transaction* transactions = this->get_all();
//	for (int i = 0; i < size; i++) {
//		if (transactions[i].get_day() == day && strcmp(transactions[i].get_type(), type) == 0 && strcmp(transactions[i].get_description(), description) == 0)
//			transactions[i].set_sum(replaced_sum);
//	}
//
//}

//bool Repo::search_transaction(const Transaction &t)
//{
//	int size = this->get_size();
//	Transaction* transactions = this->get_all();
//	for (int i = 0; i < size; i++)
//	{
//		if (transactions[i] == t)
//			return true;
//
//	}
//	return false;
//}
void Repo::delete_transaction(Transaction t)
{
	int size = this->get_size();
	if (size == 1) {
		this->n=0;
	}
	else {
		Transaction* transactions = this->get_all();
		for (int i = 0; i < size; i++) {
			if (transactions[i] == t) {
				for (int j = i; j < size - 1; j++)
					transactions[j] = transactions[j + 1];
				size--;

			}

		}
		this->n = size;
	}
}

