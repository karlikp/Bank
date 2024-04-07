#include <fstream>   
#include <sstream>   

#include "WorkingCapitalCredit.h"
#include "Functions.h"
#include "FormValidation.h"

using namespace std;


bool WorkingCapitalCredit::acceptation_conditions()
{
	string agreeing;
	bool acceptation = false;

	cout << "\nThe credit you can recive provided you use them for your business and your company exist at least 12 months.";
	cout << "\nAre you of legal age and accept the terms?";  
	cout << "\nType in: 'accept' or 'reject' (without apostrophes): ";

	agreeing = type_in_answer("accept", "reject");

	if (agreeing == "accept")
		return true;
	else 
		return false;
}


void WorkingCapitalCredit::input_specific()
{
	
	bank_account_number = get_account_number();
	NIP = get_NIP();

}


int WorkingCapitalCredit::return_lending_rate()
{
	return lending_rate;
}


void WorkingCapitalCredit::final()
{
	cout << "\nCredit completed successfully!\
			 \nOur bank will transfer of credit to your company bank account number: " << bank_account_number << ", today or the nearest weekday.\
			 \nThank you for cooperation.";
}


void WorkingCapitalCredit::save_specific_data()
{
	string counter = to_string(credit_counter);
	string name = counter + "_" + legal_name + ".txt";

	ofstream file(name, std::ios_base::app);

	if (file)
	{
		file << "\nkind_credit: WorkingCapitalCredit";
		file << "\nNIP: " << NIP;
		file << "\nbank_account_number: " << bank_account_number;
		
	}
	file.close();
}
