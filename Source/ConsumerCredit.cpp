#include <iostream>
#include <fstream>   
#include <sstream>  

#include "ConsumerCredit.h"
#include "Functions.h"
#include "FormValidation.h"

using namespace std;


bool ConsumerCredit::acceptation_conditions()
{
	string agreeing;
	bool acceptation = false;

	cout << "\nThe credit you can recive provided you aren't using them for your business.";
	cout << "\nAre you of legal age and accept the term?";
	cout << "\nType in: 'accept' or 'reject' (without apostrophes): ";

	agreeing = type_in_answer("accept", "reject");

	if (agreeing == "accept")
		return true;
	else 
		return false;
}


void ConsumerCredit::input_specific()
{
	bank_account_number = get_account_number();
}

int ConsumerCredit::return_lending_rate()
{
	return lending_rate;
}


void ConsumerCredit::final()
{
	cout << "\nCredit completed successfully!";
	cout <<	"\nOur bank will transfer of credit to bank account number:";
	cout << bank_account_number << " today or the nearest weekday.";
	cout <<	"\nThank you for cooperation.";
}


void ConsumerCredit::save_specific_data()
{
	string counter = to_string(credit_counter);
	string name = counter + "_" + legal_name + ".txt";

	ofstream file(name, std::ios_base::app);

	if (file)
	{
		file << "\nkind_credit: ConsumerCredit";
		file << "\nbank_account_number: " << bank_account_number;
		
	}
	file.close();
}