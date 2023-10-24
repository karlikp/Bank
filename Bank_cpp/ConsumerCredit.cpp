#include <iostream>
#include <fstream>   // file stream
#include <sstream>   //string stream
#include "ConsumerCredit.h"
#include "Functions.h"

using namespace std;


bool ConsumerCredit::acceptation_conditions()
{
	string agreeing;
	bool acceptation = false;

	cout << "\nThe credit you can recive provided you aren't using them for your business.";
	cout << "\nThe credit will be transfer money on your bank account today or nearest weekday.";
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


void ConsumerCredit::input_specific()
{
	bank_account_number = type_in_digit_dash("bank account number (XX-XXXX-XXXX-XXXX-XXXX-XXXX-XXXX):");

}


int ConsumerCredit::return_lending_rate()
{
	return lending_rate;
}


void ConsumerCredit::final()
{
	cout << "\nCredit completed successfully!\
			 \nOur bank will transfer of credit to bank account number: " << bank_account_number << " today or the nearest weekday.\
			 \nThank you for cooperation.";
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