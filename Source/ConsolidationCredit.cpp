#include <iostream>
#include <fstream>   
#include <sstream>   

#include "ConsolidationCredit.h"
#include "Functions.h"
#include "FormValidation.h"

using namespace std;


bool ConsolidationCredit::acceptation_conditions()
{
	cout << "\nThe credit you can recive providing that you will use it to repay other credit.";
	cout << "\nAre you of legal age and accept the term?";
	cout << "\nType in: 'accept' or 'reject' (without apostrophes): ";

	string agreeing;
	agreeing = type_in_answer("accept", "reject");

	if (agreeing == "accept")
		return true;
	else 
		return false;
}


void ConsolidationCredit::input_specific()
{
	cout << "\nType in the bank name which give you previous credit: ";
	other_bank = get_letter_answer("other bank");
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