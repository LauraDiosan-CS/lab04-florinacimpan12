//adăugarea unei tranzacții în lista de tranzacții
//o ex.adaugă 100 out pizza - este adăugată o tranzație de tip out în valoarea de
//100 RON pentru ziua curentă cu descrierea ”pizza”
//o ex.inserează 25 100 in salar - inserează o tranzacție de tip in pentru ziua 25 în
//valaorea de 100 RON cu descrierea salar

#include "Service.h"
#include "Transaction.h"


void Service::add_transaction(int day,int sum,char* type, char* description) {
	Transaction t = Transaction(day, sum, type, description);
	this->r.add_transaction(t);

}

Transaction* Service::get_all()
{
	return this->r.get_all();

}


int Service::get_size_repo()
{
	return this->r.get_size();
}

void Service::delete_transactions_by_day(int day)
{
	int size = this->r.get_size();
	Transaction* transactions = this->r.get_all();
	for (int i = 0; i < size;) {
		if (transactions[i].get_day() == day) {
			this->r.delete_transaction(transactions[i]);
			if (size == 1 || i == size - 1)
				size = 0;
		}
		else {
			i++;
		}
	}
}

void Service::delete_transactions_between_days(int day1, int day2)
{
	int size = this->r.get_size();
	Transaction* transactions = this->r.get_all();
	for (int i = 0; i < size;) {
		if (transactions[i].get_day()>=day1 && transactions[i].get_day() <= day2) {
			this->r.delete_transaction(transactions[i]);
			if (size == 1 || i==size-1)
				size = 0;
		}
		else {
			i++;
		}
	}
}

void Service::delete_transactions_by_type(char* type)
{
	int size = this->r.get_size();
	Transaction* transactions = this->r.get_all();
	for (int i = 0; i < size;) {
		if (strcmp(transactions[i].get_type(), type) == 0) {
			this->r.delete_transaction(transactions[i]);
			if (size == 1 || i==size-1)
				size = 0;
			
		}
		else
		{
			i++;
		}
	}
}

void Service::replace_sum_in_transaction(int replaced_sum, int day,char* type, char* description )
{
	
	int size = this->r.get_size();
	Transaction* transactions = this->r.get_all();
	for (int i = 0; i < size; i++) {
		if (transactions[i].get_day() == day && strcmp(transactions[i].get_type(), type) == 0 && strcmp(transactions[i].get_description(), description) == 0)
			transactions[i].set_sum(replaced_sum);
	}
	

}

void Service::array_with_transactions_by_type(char* type,Transaction transactions[],int &length)
{
	length = 0;
	int size = this->r.get_size();
	Transaction auxiliar;
	Transaction* full_transactions = this->r.get_all();
	for (int i = 0; i < size; i++)
	{
		if (strcmp(full_transactions[i].get_type(), type) == 0) {
			auxiliar = full_transactions[i];
			transactions[length++] = auxiliar;
		}
	}

}

void Service::array_with_transaction_sum_b(Transaction transactions[], int &length,int sum)
{
	int size = this->r.get_size();
	Transaction* current_transactions = this->r.get_all();
	Transaction auxiliar;
	for (int i = 0; i < size; i++) {
		if (current_transactions[i].get_sum() > sum)
		{	
			transactions[length++] = current_transactions[i];

		}
	}
}

void Service::array_with_transaction_sum_equal(Transaction transactions[], int& length,int sum)
{
	int size = this->r.get_size();
	Transaction* current_transactions = this->r.get_all();
	Transaction auxiliar;
	for (int i = 0; i < size; i++) {
		if (current_transactions[i].get_sum() == sum )
		{
			transactions[length++] = current_transactions[i];

		}
	}
}

int Service::sold_by_day(int day)
{
	int sold = 0;
	int size = this->r.get_size();
	Transaction* transactions = this->r.get_all();
	for (int i = 0; i < size; i++) {
		if (transactions[i].get_day() == day) {
			if (strcmp(transactions[i].get_type(), "in") == 0)
				sold += transactions[i].get_sum();
			else
				sold -= transactions[i].get_sum();
		}
	}
	return sold;
}

int Service::sum_by_type(char* type)
{
	int size = this->r.get_size();
	Transaction* transactions = this->r.get_all();
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(transactions[i].get_type(), type) == 0)
			sum += transactions[i].get_sum();
	}
	return sum;
}

Transaction Service::most_valuable_by_day(int day)
{
	int size = this->r.get_size();
	Transaction* transactions = this->r.get_all();
	Transaction most_valuable_transaction;
	int max_value = 0;
	for (int i = 0; i < size; i++) {
		if (transactions[i].get_day()==day && transactions[i].get_sum() > max_value) {
			most_valuable_transaction = transactions[i];
			max_value = transactions[i].get_sum();
		}
	}
	return most_valuable_transaction;
}

void Service::keep_by_type(char* type)
{
	int size = this->r.get_size();
	Transaction* transactions = this->r.get_all();
	for (int i = 0; i < size; ) {
		if (strcmp(transactions[i].get_type(), type) != 0) {
			this->r.delete_transaction(transactions[i]);
			if (size == 1 || i == size - 1)
				size = 0;
		}
		else {
			i++;
		}

	}
}

void Service::keep_by_type_and_sum(char* type, int sum)
{
	int size = this->r.get_size();
	Transaction* transactions = this->r.get_all();
	for (int i = 0; i < size; ) {
		if (strcmp(transactions[i].get_type(), type) != 0 || transactions[i].get_sum() > sum) {
			this->r.delete_transaction(transactions[i]);
			if(size== 1 || i==size-1)
				size = 0;
		}
		else {
			i++;
		}

	}

}


