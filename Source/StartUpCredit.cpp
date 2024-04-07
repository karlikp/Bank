#include <fstream>   
#include <sstream>   

#include "StartUpCredit.h"
#include "Functions.h"
#include "FormValidation.h"

using namespace std;




bool StartUpCredit::acceptation_conditions()
{
	string agreeing;
	bool acceptation = false;

	cout << "\nThe credit you can recive provided you use them for start your business.";
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
	cout << "\nCredit completed successfully!\
			 \nOur bank will transfer of credit to your company bank account number: " << bank_account_number << ", today or the nearest weekday.\
			 \nThank you for cooperation.";
}


void StartUpCredit::save_specific_data()
{
	string counter = to_string(credit_counter);
	string name = counter + "_" + legal_name + ".txt";

	ofstream file(name, std::ios_base::app);

	if (file)
	{
		file << "\nkind_credit: InvestmentCredit";
		file << "\nNIP: " << NIP;
		file << "\nbank_account_number: " << bank_account_number;
		file << "\nbusiness_describe: " << business_describe;
		
	}
	file.close();
}
