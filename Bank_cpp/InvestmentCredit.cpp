#include <fstream>   // file stream
#include <sstream>   //string stream

#include "InvestmentCredit.h"
#include "Functions.h"

using namespace std;


bool InvestmentCredit::acceptation_conditions()
{
	string agreeing;
	bool acceptation = false;

	cout << "\nThe credit you can recive provided you use them for develop your business";
	cout << "\n(e.g.: employe more amount employees, or buying new devices).";
	cout << "\nIt have to be planed investment which you will describe in credit form.";
	cout << "\nYou must have a certificate of no arrears with payments to ZUS and US.";  
	cout << "\nThe credit will be transfer money on your company bank account today or nearest weekday.";
	cout << "\nDo you constent and confirm to your company meet the above requirements?"; 
	cout << "\nType in: 'I agree and confirm' or 'I not agree' (without apostrophes): ";

	agreeing = type_in_answer("I agree and confirm", "I not agree");

	if (agreeing == "I agree and confirm")
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


void InvestmentCredit::input_specific()
{
	bank_account_number = type_in_digit_dash("bank account number (XX-XXXX-XXXX-XXXX-XXXX-XXXX-XXXX):");
	NIP = type_in_digit_dash("NIP of your company (XXX-XXX-XX-XX): ");
	investment_describe = type_in_alpha_space("describe your investment (Remember that laying here is criminal): ");
}


int InvestmentCredit::return_lending_rate()
{
	return lending_rate;
}


void InvestmentCredit::final()
{
	cout << "\nCredit completed successfully!\
			 \nOur bank will transfer of credit to your company bank account number: " << bank_account_number << ", today or the nearest weekday.\
			 \nThank you for cooperation.";
}


void InvestmentCredit::save_specific_data()
{
	string counter = to_string(credit_counter);
	string name = counter + "_" + legal_name + ".txt";

	ofstream file(name, std::ios_base::app);

	if (file)
	{
		file << "\nkind_credit: InvestmentCredit";
		file << "\nNIP: " << NIP;
		file << "\nbank_account_number: " << bank_account_number;
		file << "\nInvestment_describe: " << investment_describe;
		
	}
	file.close();
}
