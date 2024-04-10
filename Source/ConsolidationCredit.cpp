#include <iostream>
#include <fstream>   
#include <sstream>   

#include "Headers\ConsolidationCredit.h"
#include "Headers\Functions.h"
#include "Headers\FormValidation.h"

using namespace std;


bool ConsolidationCredit::acceptation_conditions()
{
	cout << "\nThe credit you can receive providing that you will use it to repay other credit.";
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
	other_bank = get_letter_answer("the bank name which give you previous credit:");
}


int ConsolidationCredit::return_lending_rate()
{
	return lending_rate;
}


void ConsolidationCredit::final()
{
	cout << "\nCredit completed successfully!";
	cout << "\nOur bank will contact to " << other_bank;
	cout << " today or the nearest weekday and repay amount consistent with the contract.";
	cout <<	"\nThank you for cooperation.\n";
}


void ConsolidationCredit::save_specific_data()
{
	string counter = to_string(credit_counter);
	string name = counter + ". " + legal_name + ".txt";

	ofstream file("Customers/" + name, std::ios_base::app);

	if (file)
	{
		file << "\nkind_credit: ConsolidationCredit";
		file << "\nother_bank: " << other_bank;
		
	}
	file.close();
}