#include <fstream>   
#include <sstream>   

#include "Headers/StartUpCredit.h"
#include "Headers/Functions.h"
#include "Headers/FormValidation.h"

using namespace std;




bool StartUpCredit::acceptation_conditions()
{
	string agreeing;
	bool acceptation = false;

	cout << "\nThe credit you can receive provided you use them for start your business.";
	cout << "\nYou will have to write your business plan.";
	cout << "\nAre you of legal age and accept the terms?"; 
	cout << "\nType in: 'accept' or 'reject' (without apostrophes): ";

	agreeing = type_in_answer("accept", "reject");

	if (agreeing == "accept")
		return true;
	else 
		return false;
}

void StartUpCredit::input_specific()
{
	
	bank_account_number = get_account_number();
	NIP = get_NIP();
	business_describe = get_letter_answer("describe short your business plan: ");
}


int StartUpCredit::return_lending_rate()
{
	return lending_rate;
}


void StartUpCredit::final()
{
	cout << "\nCredit completed successfully!";
	cout << "\nOur bank will transfer of credit to bank account number: ";
	cout << bank_account_number << " today or the nearest weekday.";
	cout << "\nThank you for cooperation.\n";
}


void StartUpCredit::save_specific_data()
{
	string counter = to_string(credit_counter);
	string name = counter + ". " + legal_name + ".txt";

	ofstream file("Customers/" + name, std::ios_base::app);

	if (file)
	{
		file << "\nkind_credit: InvestmentCredit";
		file << "\nNIP: " << NIP;
		file << "\nbank_account_number: " << bank_account_number;
		file << "\nbusiness_describe: " << business_describe;
		
	}
	file.close();
}
