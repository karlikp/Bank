#pragma once
#include "CreditForCustomer.h"

//extern 
class ConsolidationCredit : public CreditForCustomer
{

public:
	ConsolidationCredit();
	~ConsolidationCredit();
	//friend auto make_decision();
};

