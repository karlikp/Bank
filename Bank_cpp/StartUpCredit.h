#pragma once
#include "Credit.h"

class StartUpCredit : public Credit
{    
	int lending_rate = 10;		       
	std::string bank_account_number;
	std::string NIP;
	std::string business_describe;

public:

	int return_lending_rate();
	bool acceptation_conditions();
	void input_specific();
	void final();
	void save_specific_data();
};

