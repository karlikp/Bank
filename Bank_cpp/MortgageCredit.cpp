#include <iostream>
#include <string>
#include <fstream>   // file stream
#include <sstream>   //string stream
#include "MortgageCredit.h"
#include "Functions.h"

using namespace std;

bool MortgageCredit::acceptation_conditions()
{
	string agreeing;
	bool acceptation = false;

	cout << "\nYou can get this credit, provided that you use it only to buy real property.";
	cout << "\nThe credit will be transfer money on your bank account today or nearest weekday.";
	cout << "\nYou have to pay 10% credit amount, during credit finalisation.";
	cout << "\nYou must be over 18 years old.";
	cout << "\nDo you constent to the above conditions?";
	cout << "\nType in: 'I agree' or 'I not agree' (without apostrophes): ";

	agreeing = type_in_answer("I agree", "I not agree");

	if (agreeing == "I agree")
	{
		acceptation = true;
	}
	else if (agreeing == "I not agree")
	{
		cout << "\nI'm sorry, but this consent is necessary.";
		acceptation = false;
	}

	return acceptation;
}


void MortgageCredit::input_specific()
{
	//std::cout << "\nType in your bank account number (XX-XXXX-XXXX-XXXX-XXXX-XXXX-XXXX): ";
	bank_account_number = type_in_digit_dash("bank account number (XX-XXXX-XXXX-XXXX-XXXX-XXXX-XXXX):");

}


int MortgageCredit::return_lending_rate()
{
	return lending_rate;
}


void MortgageCredit::final()
{
	float own_contribution = Credit::credit_amount * 0.1;

	cout << "\nIn order to complete the conditions of credit. I am paying the amount of " << own_contribution << " zl\
			 \nIf you want to pay the amount write 'I am paying', otherwise enter 'I am resigning': ";
	string answer = type_in_answer("I am paying", "I am resigning");

	if (answer == "I am paying")
	{
		cout << "\nCredit completed successfully!\
				 \nOur bank will transfer of credit to bank account number: " << bank_account_number << " today or the nearest weekday.\
				 \nThank you for cooperation.";

		lack_finalisation = false;
	}
	else if (answer == "I am resigning")
	{
		cout << "\nUnfortunately, credit uncompleted successfully\
				 \nPayment amount 10% of the credit is a prerequisite";

		lack_finalisation = true;
	}
}


void MortgageCredit::save_specific_data()
{
	string counter = to_string(credit_counter);
	string name = counter + "_" + legal_name + ".txt";

	ofstream file(name, std::ios_base::app);

	if (file)
	{
		file << "\nkind_credit: MortgageCredit";
		file << "\nbank_account_number: " << bank_account_number;
		
	}
	file.close();
}
