#include <iostream>
#include <ctype.h>

#include "Credit.h"

#include "Functions.h"
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
	
	cout << "\n\nWould you like recive a credit for individual customers or a company credit? ";
	cout << "\nTo select an individual credit, type in number: '1'.\nWhereas to choose a company credit, type in number: '2'.";
	cout << "\nEnter number: ";
	target = type_in_only_digit("1 or 2");
	cout << endl;
	if (target == 1)
	{
		cout << "Which credit kind you prefer?";
		cout << "\nPossible options:\n- nr 1: Mortage credit (RRSO: 10%),\n- nr 2: Consolidation credit (RRSO: 15%),\n- nr 3: Consumer credit (RRSO: 20%).";
		cout << "Type in number correct option: ";
		kind = type_in_only_digit("1, 2 or 3");
		cout << endl;
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
		cout << "\nPossible options:\n- nr 1: Investment credit (RRSO: 6 %),\n- nr 2: Working capital credit (RRSO: 8%),\n- nr 3: Start-up credit (RRSO: 10%)"; 
		cout << "\nType in number correct option: ";
		cin >> kind;
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


 string type_in_legal_name()
 {
	 bool correct = true;
	 string name;
	 do
	 {
		 cout << "\nType in your legal name: ";

		 int alpha_counter = 0, surname_letters = 0, space_counter = 0;
		 correct = true;

		 getline(cin >> ws, name);

		 for (int i = 0; i < name.size(); i++)
		 {
			 if (isalpha(name[i]))
			 {
				 alpha_counter++;
				 surname_letters++;
			 }
			 if (isspace(name[i]))
			 {
				 surname_letters = 0;
				 space_counter++;
			 }
		 }
		 if (surname_letters < 2)
		 {
			 cout << "\Surname should include at least two letters";
			 correct = false;
		 }
		 if (space_counter != 1)
		 {
			 cout << "\nLegal name should contain only one space between name and surname";
			 correct = false;
		 }
		 if ((alpha_counter + 1) < name.size())
		 {
			 correct = false;
			 cout << "\nLegal name can include only alphabets signs and one space sign";
		 }
	 } while (!correct);
	 return name;
 }


 string type_in_age()
 {
	 bool correct = true;
	 string years;
	 do
	 {
		 cout << "\nType in your age: ";

		 correct = true;

		 int digit_counter = 0;

		 getline(cin >> ws, years);

		 for (int i = 0; i < years.size(); i++)
		 {
			 if (isdigit(years[i]))
			 {
				 digit_counter++;
			 }
			 if (digit_counter > 2)
			 {
				 correct = false;
				 cout << "\nIf you be over 99 years, we invite to our stationary facility.";
				 cout << "\nOtherwise write your age again.";
			 }
		 }
		 if ((digit_counter) != years.size())
		 {
			 correct = false;
			 cout << "\nAge can include only digits";
			 continue;
		 }
		 int int_age = stoi(years);
		 if (int_age < 18)
		 {
			 cout << "\nOur bank give a credit only person which be over 18 years";
			 correct = false;
		 }
	 } while (!correct);

	 return years;
 }


 std::string type_in_birthplace()
 {
	 bool correct = true;
	 string place;
	 do
	 {
		 cout << "\nType in your birthplace: ";

		 correct = true;

		 int alpha_counter = 0;

		 getline(cin >> ws, place);

		 for (int i = 0; i < place.size(); i++)
		 {
			 if (isalpha(place[i]))
			 {
				 alpha_counter++;
			 }
		 }
		 if (alpha_counter < 2)
		 {
			 correct = false;
			 cout << "\nName the place should include at least two letters.";
		 }
		 if ((alpha_counter) != place.size())
		 {
			 correct = false;
			 cout << "\nbirthplace can include only letters";
		 }

	 } while (!correct);

	 return place;
 }


 string type_in_evidence_number()
 {

	 string number;

	 bool first = false, second = true;

	 do
	 {
		 cout << "\nType in your evidence number(Pattern 'XYZ123456' {three letters and six digits} ): ";

		 int alpha_counter = 0, digit_counter = 0;
		 first = false, second = true;
		 getline(cin >> ws, number);

		 for (int i = 0; i < number.size(); i++)
		 {
			 if (isalpha(number[i]))
			 {
				 alpha_counter++;
				 if (alpha_counter == 3)
				 {
					 first = true;
				 }
				 digit_counter = 0;
			 }
			 if (isdigit(number[i]))
			 {
				 digit_counter++;
			 }
		 }
		 if (number.size() != 9)
		 {
			 cout << "\nEvidence number should have 3 letters and 6 digits";
			 second = false;
			 continue;
		 }
		 if (digit_counter != 6)
		 {
			 cout << "\nEvidence number should have 3 letters and 6 digits";
			 second = false;
		 }

	 } while (!first or !second);

	 return number;
 }


 string type_in_PESEL()
 {

	 string number;

	 bool correct = true;

	 do
	 {
		 cout << "\nType in your PESEL(it should include 11 digits): ";

		 int digit_counter = 0;
		 correct = true;
		 getline(cin >> ws, number);

		 for (int i = 0; i < number.size(); i++)
		 {

			 if (isdigit(number[i]))
			 {
				 digit_counter++;
			 }
		 }
		 if (number.size() != digit_counter)
		 {
			 cout << "\nPESEL should include only digits";
			 correct = false;
			 continue;
		 }
		 if (number.size() != 11)
		 {
			 cout << "\nPESEL should include 11 digits";
			 correct = false;
		 }

	 } while (!correct);

	 return number;
 }


 int type_in_only_digit(string target)
 {
	 bool correct = true;
	 string chain;
	 do
	 {
		 cout << "\nType in " << target << ": ";

		 int digit_counter = 0;
		 correct = true;
		 getline(cin >> ws, chain);

		 for (int i = 0; i < chain.size(); i++)
		 {
			 if (isdigit(chain[i]))
			 {
				 digit_counter++;
			 }
		 }
		 if (chain.size() != digit_counter)
		 {
			 cout << "\nThe " << chain << " should include only digits";
			 correct = false;

		 }
	 } while (!correct);
	 float i_number = stoi(chain);
	 return i_number;
 }


 string type_in_alpha_space(std::string target)
 {

	 string sentence;

	 bool correct = true;

	 do
	 {
		 cout << "\nType in " << target << ": ";

		 int alpha_counter = 0, space_counter = 0;
		 correct = true;
		 getline(cin >> ws, sentence);

		 for (int i = 0; i < sentence.size(); i++)
		 {
			 if (isalpha(sentence[i]))
			 {
				 alpha_counter++;
			 }
			 if (isspace(sentence[i]))
			 {
				 space_counter++;
			 }
		 }
		 if (sentence.size() != (alpha_counter + space_counter))
		 {
			 cout << "\nThe answer should include only letters and spaces";
			 correct = false;

		 }
	 } while (!correct);

	 return sentence;
 }


 string type_in_digit_dash(std::string target)
 {

	 string chain;
	 bool correct = true;
	 do
	 {
		 cout << "\nType in " << target << ": ";

		 char dash = '-';
		 int digit_counter = 0, dash_counter = 0;
		 correct = true;

		 getline(cin >> ws, chain);

		 for (int i = 0; i < chain.size(); i++)
		 {
			 if (isdigit(chain[i]))
			 {
				 digit_counter++;
			 }
			 if (chain[i] == dash)
			 {
				 dash_counter++;
			 }
		 }

		 if (chain.size() != (digit_counter + dash_counter))
		 {
			 cout << "\nThe answer should include only digits and dashes";
			 correct = false;

		 }
	 } while (!correct);

	 return chain;
 }
 

 void executing_program()
 {
	 bool checkpoint_decision = false;
	 cout << "This program is able to get a credit for you.\n";
	 cout << "********************************************";

	 do
	 {
		 Credit* credit_kind = make_decision();

		 int lending_rate = credit_kind->return_lending_rate();

		 bool acceptation_conditions = credit_kind->acceptation_conditions();

		 bool update_financial_info = false;

		 if (acceptation_conditions)
		 {

			 credit_kind->read_data_file();

			 
			 if (!(credit_kind->read_data))	credit_kind->input_universal();
			 do
			 {
				 if (!(credit_kind->read_data))	credit_kind->input_pledge_info();

				 credit_kind->input_credit_details();

				 credit_kind->input_specific();

				 credit_kind->calculate_reduce_bufor();

				 credit_kind->calculate_capacity();

				 credit_kind->calculate_instalment(lending_rate);

				 credit_kind->check_capacity();

				 if (credit_kind->verification != true)
				 {

					 credit_kind->calculate_current_oportunity(lending_rate);

				 }
				 else if (credit_kind->verification == true)
				 {
					 credit_kind->calculate_credit();
				 }

				 credit_kind->feedback();

				 if (credit_kind->verification)
				 {
					 credit_kind->contract(); 
				 }
				 
				 if (credit_kind->lack_finalisation)
				 {
					 update_financial_info = credit_kind->checkpoint_2();
				 }
				 else
				 {
					 update_financial_info = false;
				 }
				
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


 
