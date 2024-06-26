#include <iostream>
#include <string>
#include <fstream>   
#include <sstream>  

#include "Headers/MortgageCredit.h"
#include "Headers/Functions.h"
#include "Headers/FormValidation.h"

using namespace std;

bool MortgageCredit::acceptation_conditions()
{
	string answer;
	bool acceptation = false;

	cout << "\nThe credit you can receive providing that you use it only to buy real property.";
	cout << "\nYou have to pay 10% credit amount, during credit finalisation.";
	cout << "\nAre you of legal age and accept the term?";
	cout << "\nType in: 'accept' or 'reject' (without apostrophes): ";

	answer = type_in_answer("accept", "reject");

if (answer == "accept")
		return true;
	else 
		return false;
}


void MortgageCredit::input_specific()
{
	bank_account_number = get_account_number();
}

int MortgageCredit::return_lending_rate()
{
	return lending_rate;
}


void MortgageCredit::final()
{
	float own_contribution = Credit::credit_amount * 0.1;

	cout << "\nIn order to complete the conditions of credit you have to pay own contribution: " << own_contribution << " zl\
			 \nDo you pay? Enter 'yes' or 'no':  ";
	string answer = type_in_answer("yes", "no");

	if (answer == "yes")
	{
		cout << "\nCredit completed successfully!";
		cout << "\nOur bank will transfer of credit to bank account number: "; 
		cout << bank_account_number << " today or the nearest weekday.";
		cout <<	"\nThank you for cooperation.\n";


		lack_finalisation = false;
	}
	else 
	{
		cout << "\nUnfortunately, credit uncompleted successfully";
		cout <<	"\nPayment amount 10 % of the credit is a prerequisite";

		lack_finalisation = true;
	}
}


void MortgageCredit::save_specific_data()
{
	string counter = to_string(credit_counter);
	string name = counter + ". " + legal_name + ".txt";

	ofstream file("Customers/" + name, std::ios_base::app);

	if (file)
	{
		file << "\nkind_credit: MortgageCredit";
		file << "\nbank_account_number: " << bank_account_number;
		
	}
	file.close();
}
