#include "Credit.h"	

#ifndef CONSUMERCREDIT_H
#define CONSUMERCREDIT_H


						
class ConsumerCredit : public Credit
{	     
	int lending_rate = 20;           
	std::string bank_account_number;

public:

	int return_lending_rate();
	bool acceptation_conditions();
	void input_specific();
	void final();
	void save_specific_data();
};

#endif