#include "Transaction.h"
#include "Tests.h"
#include "Repo.h"

#include "Console.h"
#include <iostream>

using namespace std;

void Console::menu()
{
	cout << "1.Add- write the transaction you wish to add with the exception of its date, which will be automatially imputed."<<endl;
	cout << "Insert- write the transaction you wish to add with all of its atributes"<<endl;


}

int Console::run() {


	while (true)
	{
		menu();
		cout << "Choose your option" << endl;
		char op;
		cin >> op;
		if (op == '1') {
			char instruction;
			cin >> instruction;

		}

		else
			return 0;




	}
}