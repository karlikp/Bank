#include <iostream>
#include "Credit.h"
#include "Functions.h"

//#include "CreditForCustomer.h"
#include "ConsumerCredit.h"
#include "MortgageCredit.h"
#include "ConsolidationCredit.h"

//#include "CreditForCompany.h"
#include "WorkingCapitalCredit.h"
#include "InvestmentCredit.h"
#include "StartUpCredit.h"

//#ifdef DEBUG



using namespace std;

//ConsumerCredit* consumer;
//MortgageCredit* mortgage;
//ConsolidationCredit* consolidation;
//
//WorkingCapitalCredit* working_capital;
//InvestmentCredit* investment;
//StartUpCredit* start_up;


 Credit* make_decision()
{
	//credit* current = nullptr;
	//consumercredit* consumer = nullptr;

	//*current == &consumer;

	//mortgagecredit* mortgage = nullptr;
	//consolidationcredit* consolidation = nullptr;
	//workingcapitalcredit* working_capital = nullptr;
	//investmentcredit* investment = nullptr;
	//startupcredit* start_up = nullptr;
	int target, kind;
	Credit* current = nullptr;
	cout << "This program is able to get a credit for you" << endl;
	cout << "********************************************" << endl;

	cout << "Would you like recive a credit for individual customers or a company credit? ";
	cout << "To select an individual credit, enter number: '1'. Whereas to choose a company credit, enter nubmer: '2'.";
	cin >> target;
	if (target == 1)
	{
		cout << "Which credit kind you prefer?";
		cout << "\nPossible options:\n - Consumer credit (1),\n	- Mortage credit (2),\n - Consolidation credit (3)";
		cout << "Type in number correct option: ";
		cin >> kind;
		switch (kind)
		{
		case 1:
		{
			ConsumerCredit choice;
			current = &choice;
		}
		break;
		case 2:
		{

			MortgageCredit choice;
			current = &choice;

		}
		break;
		case 3:
		{
			ConsolidationCredit choice;
			current = &choice;	
		}	
		break;
		}
	}
	else
	{
		cout << "Which credit kind you prefer?";
		cout << "\nPossible options:\n - Working capital credit (1),\n	- Investment credit (2),\n - Start-up credit (3)";
		cout << "Type in number correct option: ";
		cin >> kind;
		switch (kind)
		{
		//case 1:
		//	WorkingCapitalCredit choice;
		//	return choice;
		//	//current = &working_capital;
		//	//break;
		//case 2:
		//	InvestmentCredit choice;
		//	return choice;
		//	//current = &investment;
		////	break;
		//case 3:
		//	StartUpCredit choice;
		//	return choice;
		//	//current = &start_up;
		////	break;
		}
	}
	return current;
}

//#endif // DEBUG