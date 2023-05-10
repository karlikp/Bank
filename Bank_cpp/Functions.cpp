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

#ifdef DEBUG



using namespace std;

//ConsumerCredit* consumer;
//MortgageCredit* mortgage;
//ConsolidationCredit* consolidation;
//
//WorkingCapitalCredit* working_capital;
//InvestmentCredit* investment;
//StartUpCredit* start_up;


 auto* make_decision()
{
	Credit* current = nullptr;
	ConsumerCredit* consumer = nullptr;

	//*current == &consumer;

	MortgageCredit* mortgage = nullptr;
	ConsolidationCredit* consolidation = nullptr;
	WorkingCapitalCredit* working_capital = nullptr;
	InvestmentCredit* investment = nullptr;
	StartUpCredit* start_up = nullptr;
	int target, kind;
	string correct;
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
			*current = &consumer;
			break;
		case 2:
			*current = &mortgage;
			break;
		case 3:
			*current = &consolidation;
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
		case 1:
			*current = &working_capital;
			break;
		case 2:
			*current = &investment;
			break;
		case 3:
			*current = &start_up;
			break;
		}
	}
	return current;
}

#endif // DEBUG