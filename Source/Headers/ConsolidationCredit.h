#include "Credit.h"

#ifndef CONSOLIDATIONCREDIT_H
#define CONSOLIDATIONCREDIT_H

class ConsolidationCredit : public Credit
{
	std::string other_bank;    
	int lending_rate = 15;     
	float credit_amount;      
   																			
public:

	int return_lending_rate();
	bool acceptation_conditions();
	void input_specific();
	void final();
	void save_specific_data();
};

#endif

