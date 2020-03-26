#pragma once
#include "Service.h"
class Console {
private:
	Service s;
public:
	int run();
	
	int read_int();
	char read_op();
	char* read_p_char();
	
	void add_transaction_without_day();
	int get_current_day();
	void menu_main();
	void menu_secondary_1();
	void menu_secondary_2();
	void menu_secondary_3();
	void menu_secondary_4();
	void menu_secondary_5();
	void delete_transaction_day();
	void show_transaction();
	void add_transaction_with_day();
	void delete_transaction_between_days();
	void delete_transactions_by_type();
	void show_by_given_type();
	void sum_by_type();
	void most_valuable_transaction_by_day();
	void keep_by_type();
	void keep_by_type_and_sum();
	void replace_sum_in_transaction();
	void show_array_with_tran_sum_over();
	void show_array_with_tran_equal();
	void sold_for_the_day();
};
