#include "Credit.h"

#ifndef INVESTMENTCREDIT_H
#define INVESTMENTCREDIT_H

class InvestmentCredit : public Credit
{    
	int lending_rate = 6;		       
	std::string bank_account_number;
	std::string NIP;
	std::string investment_describe;

public:

	int return_lending_rate();
	bool acceptation_conditions();
	void input_specific();
	void final();
	void save_specific_data();
};

#endif