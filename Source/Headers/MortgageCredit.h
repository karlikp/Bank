#include "Credit.h"

#ifndef MORTAGECREDIT_H
#define MORTAGECREDIT_H

class MortgageCredit : public Credit
{
	int lending_rate = 10;     
	std::string bank_account_number;
		
public:		

	int return_lending_rate();
	bool acceptation_conditions();
	void input_specific();
	void final();
	void save_specific_data();
};									

#endif