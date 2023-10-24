#include <math.h>
#include <fstream>   //file stream
#include <sstream>   //string stream
#include "Credit.h"
#include "Functions.h"

using namespace std;


Credit::Credit()
{
}


Credit::~Credit()
{
}

void Credit::input_universal()
{
	cout << "You will be asked to complete form fields below your personal datails and information needed to applying for a credit.\n";
	
	legal_name = type_in_legal_name();
	age = type_in_age();
	evidence_number = type_in_evidence_number();
	birthplace = type_in_birthplace();
	PESEL = type_in_PESEL();

	cout << "\nIn destination you financial safety, our company will calculate your credit capacity.";
	cout << "\nSo, we will ask you about your financial conditon.";

	cout << "\nHow high is your monthly income?"; 
	monthly_income = type_in_only_digit("monthly income");

	cout << "\nHow high are your monthly spending on average. Remember that lying can make your insolvent.";
	monthly_spending = type_in_only_digit("monthly spending");

}


void Credit::input_credit_details()
{

	cout << "\n\nWhat credit amount are you going to apply for?"; 
	credit_amount = type_in_only_digit("credit amount");

	do
	{
		cout << "\n\nWhen you take out a credit, you oblige yourself to repay one loan instalment every month";
		cout << "\nHow long do you intend to pay off the loan?";
		cout << "\nEnter answer in years, or if you prefer month period of time write number '0' (write only number)";
		instalment_amount = type_in_only_digit("instalment amount");

		if (instalment_amount == 0)
		{
			cout << "\nHow long do you intend to pay off the loan?";
			cout << "\nType in answer in months";
			cout << "\nMy answer: ";
			cin >> instalment_amount;
		}
		else if (instalment_amount > 0)
		{
			instalment_amount = instalment_amount * 12;
		}
		else
		{
			cout << "\nYou wrote a wrong answer\n";
		}

		
	} while (instalment_amount <= 0);
}


void Credit::input_pledge_info()
{
	string answer;
	if (!pledge)
	{

		cout << "\nOur company assume that there may be a random situation that will reduce your budget, so we lower your financial capacity";
		cout << "\nIf you want to enhance your credit capacity, you can to pledge your propety, and estimate its value";
		cout << "\nThen our bank will be able to give you enhance credit. But if you won't repay the instalment your pledge propety will be asset of our bank";
		cout << "\nIf you want to pledge something write 'yes', else type in 'no': ";
		answer = type_in_answer("yes", "no");
	}
	else if (pledge)
	{
		cout << "\nIf you want to change your pledge write 'yes', otherwise type in 'no': ";
		answer = type_in_answer("yes", "no");
	}

	if (answer == "yes")
	{
		pledge = true;
		cout << "\nEnter your propety which you mean to pledge";
		cout << "\nName of the propety: ";
		pledge_name = type_in_alpha_space("pledge name");
		pledge_value = type_in_only_digit("pledge value");
	}
	read_data = true;
}


void Credit::calculate_instalment(int lending_rate) 
{
	
	float N = credit_amount; 
	int r = lending_rate; 
	int k = 12; // amount instalment per year;
	int n = instalment_amount; 

	monthly_payment = N * ((r * 0.01 / k) * (pow((1 + (r * 0.01 / k)), n))) / (pow((1 + (r * 0.01 / k)), n) - 1);
}


void Credit::calculate_capacity()
{
	safety_bufor = (0.2 * monthly_income);
	safety_bufor -= reduce_bufor;
	if (safety_bufor < 0)
	{
		safety_bufor = 0;
	}
	capacity = monthly_income - monthly_spending - safety_bufor;
}


void Credit::check_capacity()
{
	float score = capacity - monthly_payment;

	if (score >= 0)
	{
		verification = true;
	}
	else
	{
		verification = false;
	}
}


void Credit::feedback()
{
	if (verification == true)
	{
		cout << "\nYour financial capacity is enough high to recive the credit";
	}
	else
	{
		cout << "\nYour financial capacity isn't enough high to recive the credit";
		cout << "\nCurrently, you can recive only: " << current_oportunity << " zl";
		lack_finalisation = true;
	}
}


bool Credit::checkpoint() 
{
	string answer;
	cout << "\n\nWould you like to use of another offer our bank or exit the program?\
			 \nIf you want to use of another offer our bank enter 'bank offers'.\
			 \nOtherwise type in '!exit'.(Answer enter without apostrophes)\
			 \nYour answer: ";
	answer = type_in_answer("bank offers", "!exit");
	
	if (answer == "bank offers")
	{
		cout << "\nYou will able to choose one of offers our bank";
		return true;
	}
	else if(answer == "!exit")
	{
		cout << "\nThank you for used of new credit program.\
				 \nIf you have any sugestion to improve the program write to email: pitera.karol@gmail.com\
				 \n\nBest regards\
				 \nBank XYZ\n";
		return false;
	}
}


bool Credit::checkpoint_2()
{
	string answer;
	cout << "\nWould you like update your credit information?\
			 \nType in 'yes' or 'no': ";
	answer = type_in_answer("yes", "no");

	if (answer == "yes")
	{
		"You will be able to complete some key information, which influence for your credit capacity";
		return true;
	}
	return false;
}


void Credit::contract()
{
	cout << "\n********** Summary the credit **********\
			 \n\nYou will recive credit amount: " << credit_amount << " zl\
			 \nPeriod of repay the credit: " << instalment_amount << "mounths\
			 \nTotal amount to repay: " << total_credit << " zl\
			 \nMonthly instalment: " << monthly_payment << " zl";

	if (pledge)
	{
		cout << "\nYour pledge propety : " << pledge_name << "\
				 \nPledge value: " << pledge_value << "zl";
	}

	cout << "\n\n********** Contract **********"\
			"\nI undertake to make monthly payments " << monthly_payment << " zl of constants amounts over time " << instalment_amount << " mounths.\
			 \nI'm aware that non-observance with the conditions of the contract will result in an increase in the cost of the credit.\
			 \nWhereas in case of an attempt to cheat the bank, I will be held legally responsible.\
			 \nIf you accept conditions enter 'I accept the contract', otherwise type in 'I don't accept the contract': ";
	
	string answer = type_in_answer("I accept the contract", "I don't accept the contract");

	if (answer == "I accept the contract")
	{
		lack_finalisation = false;
		final();
		cout << endl;
		
		
		
	}
	else if (answer == "I don't accept the contract")
	{
		cout << "\nI'm sorry, but this consent is necessary.";
		lack_finalisation = true;

	}
}


void Credit::final()
{
	cout << "\nOur bank sent the credit amount to your bank account today or the nearest weekday\
		   \nThank you for cooperation and We wish you achieve your plans. ";

	
}


string Credit::type_in_answer(string yes, string no)
{
	string answer;
	getline(cin >> ws, answer);

	if (answer == yes || answer == no)
	{
		return answer;
	}
	else
	{
		do
		{
			cout << "\nYou typed in wrong answer";
			cout << "\nIf your answer was yes, type in '" << yes << "'. Whereas, if your anwser was no, type in '" << no << "'(without apostrophes)";
			cout << "\nYour new answer: ";
			getline(cin >> ws, answer);
		} while (!(answer == yes or answer == no)); //repeat until condition is true
	}
		return answer;
}

void Credit::calculate_credit()
{
	total_credit = monthly_payment * instalment_amount;
}


void Credit::calculate_current_oportunity(int lending_rate)
{; 
	int r = lending_rate; 
	int k = 12; // amount instalment per year;
	int n = instalment_amount; 

	current_oportunity = capacity / (((r * 0.01 / k) * (pow((1 + (r * 0.01 / k)), n))) / (pow((1 + (r * 0.01 / k)), n) - 1));
}


void Credit::calculate_reduce_bufor()
{
	if (pledge)
	{
		reduce_bufor = pledge_value / instalment_amount;
	}
	else if(!pledge)
	{
		reduce_bufor = 0;
	}
}


void Credit::save_all_data()
{
	save_based_data();
	save_credit_data();
	save_specific_data();
}


void Credit::save_based_data()
{
	string counter = to_string(credit_counter);
	string name = counter + "_" + legal_name + ".txt";

	ofstream file(name);

	if (file)
	{
		file << "legal_name: " << legal_name;					//universal data
		file << "\nage: " << age;
		file << "\nbirthplace: " << birthplace;
		file << "\nevidence_number: " << evidence_number;
		file << "\nPESEL: " << PESEL;
		file << "\nmonthly_income: " << monthly_income;
		file << "\nmonthly_spending: " << monthly_spending;		

		file << "\ncredit_amount: " << credit_amount;			//always - financial
		file << "\ninstalment_amount: " << instalment_amount;	//always - financial
		if (pledge)
		{
			file << "\npledge_value: " << pledge_value;				//conditional = choise user
			file << "\npledge_name: " << pledge_name;				//conditional = choise user
		}
	}
	file.close();
}


void Credit::save_credit_data()
{
	string counter = to_string(credit_counter);
	string name = counter + "_" + legal_name + ".txt";

	ofstream file(name, std::ios_base::app);

	if (file)
	{

		if (verification) 
		{
			file << "\ntotal_credit: " << total_credit;				//verification = true
		}
		else if (!verification)
		{
			file << "\ncurrent_oportunity: " << current_oportunity; //verification = false
		}

		file << "\ncapacity: " << capacity;						//always
		file << "\nsafety_bufor: " << safety_bufor;				//always
		file << "\nmonthly_payment: " << monthly_payment;		//always
	}
	
	file.close();
}


void Credit::operator ++()
{
	ifstream file("counter.txt");
	if (file)
	{
		file >> credit_counter;
	}
	file.close();

	credit_counter += 1;

	ofstream file2("counter.txt");
	if (file2)
	{
		file2 << credit_counter;
	}
	file2.close();
}


void Credit::read_data_file()
{
	cout << "\n\nWould you like type your universal data from file?\
			\nIf you like write 'yes', otherwise write 'no': ";
	string answer = type_in_answer("yes", "no");

	if (answer == "yes")
	{
		string file_name;
		cout << "\n Type in file name with your data: ";
		getline(cin >> ws, file_name);

		ifstream file(file_name);
		if (file)
		{

			string temp, first_name, last_name;
			file >> temp >> first_name >> last_name;
			legal_name = first_name + " " + last_name;
			file >> temp >> age;
			file >> temp >> birthplace;
			file >> temp >> evidence_number;
			file >> temp >> PESEL;
			file >> temp >> monthly_income;
			file >> temp >> monthly_spending;
			file >> temp >> temp;
			if (temp == "true")
			{
				pledge = true;
				file >> temp >> pledge_name;
				file >> temp >> pledge_value;
			}
		}
		file.close();

		read_data = true;
	}
}