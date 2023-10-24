#pragma once
#include "Credit.h"

class WorkingCapitalCredit : public Credit
{   
	int lending_rate = 8;          
	std::string bank_account_number;
	std::string NIP;

public:

	int return_lending_rate();
	bool acceptation_conditions();
	void input_specific();
	void final();
	void save_specific_data();
};

