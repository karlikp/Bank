#include <iostream>
#include <ctype.h>
#include <regex>

#include "Credit.h"

#include "Functions.h"
#include "FormValidation.h"
#include "ConsumerCredit.h"
#include "MortgageCredit.h"

#include "ConsolidationCredit.h"
#include "WorkingCapitalCredit.h"
#include "InvestmentCredit.h"
#include "StartUpCredit.h"

using namespace std;


 Credit* make_decision()
{
	int target, kind;
	Credit* current = nullptr;       
	
	cout << "\nWould you like recive a credit for individual customers or a company credit? ";
	cout << "\nTo select an individual credit, type in number: '1'.";
	cout << "\nWhereas to choose a company credit, type in number: '2'.";

	target = get_number("1 or 2");
	cout << endl;
	if (target == 1)
	{
		cout << "Which credit kind you prefer?";
		cout << "\nPossible options:";
		cout << "\n- nr 1: Mortage credit (RRSO: 10%),";
		cout << "\n- nr 2: Consolidation credit (RRSO: 15%),";
		cout << "\n- nr 3: Consumer credit (RRSO: 20%).";

		kind = get_number("1, 2 or 3");
		
		switch (kind)
		{
		case 1:
			current = new MortgageCredit;
			break;
		case 2:
			current = new ConsolidationCredit;
			break;
		case 3:
			current = new ConsumerCredit;
			break;
		}
	}
	else
	{
		cout << "Which credit kind you prefer?";
		cout << "\nPossible options:";
		cout << "\n- nr 1: Investment credit (RRSO: 6 %),";
		cout << "\n- nr 2: Working capital credit (RRSO: 8%),";
		cout << "\n- nr 3: Start-up credit (RRSO: 10%)"; 
		
		kind = get_number("1, 2 or 3");

		switch (kind)
		{
		case 1:
			current = new InvestmentCredit;
			break;
		case 2:
			current = new WorkingCapitalCredit;
			break;
		case 3:
			current = new StartUpCredit;
			break;
		}
	}
	return current;
}


 
void executing_program()
{
	bool checkpoint_decision = false;
	cout << "********\n";
	cout << "* BANK *\n";
	cout << "********\n";

	do
	{
		Credit* credit_kind = make_decision();

		int lending_rate = credit_kind->return_lending_rate();

		bool acceptation_conditions = credit_kind->acceptation_conditions();

		bool update_financial_info = false;

		if (acceptation_conditions)
		{

			credit_kind->read_data_file();

			
			if (!(credit_kind->read_data))	
				credit_kind->input_universal();
			do
			{
				if (!(credit_kind->read_data))	
					credit_kind->input_pledge_info();

				credit_kind->input_credit_details();
				credit_kind->input_specific();
				credit_kind->calculate_reduce_bufor();
				credit_kind->calculate_capacity();
				credit_kind->calculate_instalment(lending_rate);
				credit_kind->check_capacity();

				if (credit_kind->verification != true)
					credit_kind->calculate_current_oportunity(lending_rate);
				
				else if (credit_kind->verification == true)
					credit_kind->calculate_credit();
				

				credit_kind->feedback();

				if (credit_kind->verification)
					credit_kind->contract(); 
				
				
				if (credit_kind->lack_finalisation)
					update_financial_info = credit_kind->checkpoint_2();
				
				else
					update_financial_info = false;
				
				
			} while (update_financial_info);
		}
		if (!credit_kind->lack_finalisation)
		{
			++(*credit_kind);
			credit_kind->save_all_data();
		}

		checkpoint_decision = credit_kind->checkpoint();
	
		delete credit_kind;
		credit_kind = nullptr;

	} while (checkpoint_decision);
}

