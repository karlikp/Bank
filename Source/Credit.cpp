#include <math.h>
#include <fstream>   
#include <sstream>   

#include "Headers\Credit.h"
#include "Headers\Functions.h"
#include "Headers\FormValidation.h"

using namespace std;

void Credit::input_universal()
{
	cout << "\nYou will be asked to complete form your privat information needed to applying for a credit.\n";
	
	legal_name = get_fullname();
	age = get_age();
	evidence_number = get_evidence_number();
	birthplace = get_birthplace();
	PESEL = get_PESEL();

	cout << "\nWe will ask you about your financial conditon.";
	cout << "\nThen, the program will calculate your credit capacity.";

	cout << "\nHow high is your monthly income?"; 
	monthly_income = get_number("monthly income");

	cout << "\nHow high are your monthly spending on average.";
	monthly_spending = get_number("monthly spending");

}


void Credit::input_credit_details()
{
	cout << "\n\nHow much money do you expect to receive in a loan?"; 
	credit_amount = get_number("credit amount");

	
	cout << "\n\nWhen you take out a credit, you oblige yourself to repay one loan instalment every month";
	cout << "\nHow long do you intend to pay off the loan?";
	cout << "\nEnter answer in number of years, or if you prefer month period of time write number '0' (write only number)";
	instalment_amount = get_number("answer");

	if (instalment_amount == 0)
	{
		cout << "\nHow many months do you intend to pay off the loan?";
		cout << "\nYour answer: ";
		cin >> instalment_amount;
	}
	else 
		instalment_amount = instalment_amount * 12;
}


void Credit::input_pledge_info()
{
	string answer;
	if (!pledge)
	{

		cout << "\nDo you want to pledge your property to increase your credit capacity?";
		cout << "\nType in: 'yes' or 'no': ";
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
		pledge_name = get_letter_answer("pledge name");
		pledge_value = get_number("pledge value");
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
	cout << "\nWould you like to check another bank offers or exit the program?";
	cout <<	"\nType in 'check' or '!exit': ";
	answer = type_in_answer("check", "!exit");
	
	if (answer == "check")
		return true;

	else
	{
		cout << "\nThank you for used the credit program.";
		cout << "\nIf you have any sugestion to improve the program write to email: pitera.karol@gmail.com";
		cout <<	"\nBest regards";
		cout <<	"\nBank XYZ\n";
		return false;
	}

}

bool Credit::checkpoint_2()
{
	string answer;
	cout << "\nWould you like change information crucial for your financial capacity?";
	cout << "\nType in 'yes' or 'no': ";
	answer = type_in_answer("yes", "no");

	if (answer == "yes")
		return true;

	else
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
			 \nIf you accept conditions enter 'accept', otherwise type in 'reject': ";
	
	string answer = type_in_answer("accept", "reject");

	if (answer == "accept")
	{
		lack_finalisation = false;
		final();
	}
	else
		lack_finalisation = true;
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
	string name = counter + ". " + legal_name + ".txt";

	ofstream file("Customers/"+name);

	if (file)
	{
		file << "legal_name: " << legal_name;					
		file << "\nage: " << age;
		file << "\nbirthplace: " << birthplace;
		file << "\nevidence_number: " << evidence_number;
		file << "\nPESEL: " << PESEL;
		file << "\nmonthly_income: " << monthly_income;
		file << "\nmonthly_spending: " << monthly_spending;		

		file << "\ncredit_amount: " << credit_amount;			
		file << "\ninstalment_amount: " << instalment_amount;	
		if (pledge)
		{
			file << "\npledge_value: " << pledge_value;				
			file << "\npledge_name: " << pledge_name;				
		}
	}
	file.close();
}


void Credit::save_credit_data()
{
	string counter = to_string(credit_counter);
	string name = counter + ". " + legal_name + ".txt";

	ofstream file("Customers/" + name, std::ios_base::app);

	if (file)
	{

		if (verification) 
		{
			file << "\ntotal_credit: " << total_credit;				
		}
		else if (!verification)
		{
			file << "\ncurrent_oportunity: " << current_oportunity; 
		}

		file << "\ncapacity: " << capacity;						
		file << "\nsafety_bufor: " << safety_bufor;				
		file << "\nmonthly_payment: " << monthly_payment;		
	}
	
	file.close();
}


void Credit::operator ++()
{
	ifstream file("counter.txt");
	if (file)
		file >> credit_counter;
	
	file.close();

	credit_counter += 1;

	ofstream file2("counter.txt");
	if (file2)
		file2 << credit_counter;
	
	file2.close();
}


void Credit::read_data_file()
{
	bool correction = false;

	cout << "\nWould you like type your personal data from file?";
	cout <<	"\nEnter 'yes' or 'no': ";
	string answer = type_in_answer("yes", "no");
	

	if (answer == "yes")
	{
		do
		{


			string file_name;
			cout << "\nType in file name with your data: ";
			getline(cin >> ws, file_name);
			ifstream file(file_name);

			if (!file.good())
			{
				cout << "Wrong file name!\n";
				correction = true;
			}

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
		} while (correction);
	}
	
}