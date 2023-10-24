#include <iostream>
#include <fstream>   // file stream
#include <sstream>   //string stream
#include "ConsolidationCredit.h"
#include "Functions.h"

using namespace std;


bool ConsolidationCredit::acceptation_conditions()
{
	string agreeing;
	bool acceptation = false;

	cout << "\nThe credit you can recive providing that you will use it to repay other credit.";
	cout << "\nYour previous credit will be repaid by transaction directly between banks.";
	cout << "\nYou must be over 18 years old.";
	cout << "\nDo you constent to the above conditions?";
	cout << "\nType in: 'I agree' or 'I not agree' (without apostrophes): ";

	agreeing = type_in_answer("I agree", "I not agree");

	if (agreeing == "I agree")
	{
		cout << "\n\nThank you for trust";
		acceptation = true;
	}
	else if (agreeing == "I not agree")
	{
		cout << "\nI'm sorry, but this consent is necessary.";
		cout << "\nIf you change your mind, you will be able to continue process giving the credit";
		acceptation = false;
	}

	return acceptation;
}


void ConsolidationCredit::input_specific()
{
	cout << "\nType in the bank name which give you previous credit: ";
	other_bank = type_in_alpha_space("other bank");
}


int ConsolidationCredit::return_lending_rate()
{
	return lending_rate;
}


void ConsolidationCredit::final()
{
	cout << "\nCredit completed successfully!\
			 \nOur bank will contact to " << other_bank << " today or the nearest weekday and repay amount consistent with the contract\
		     \nThank you for cooperation.";
}


void ConsolidationCredit::save_specific_data()
{
	string counter = to_string(credit_counter);
	string name = counter + "_" + legal_name + ".txt";

	ofstream file(name, std::ios_base::app);

	if (file)
	{
		file << "\nkind_credit: ConsolidationCredit";
		file << "\nother_bank: " << other_bank;
		
	}
	file.close();
}