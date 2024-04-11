#include <math.h>
#include <fstream>   
#include <sstream>   

#include "Headers/Credit.h"
#include "Headers/Functions.h"
#include "Headers/FormValidation.h"

using namespace std;

void Credit::input_universal()
{
	cout << "\nYou will be asked to complete form your personal information needed to applying for a credit.\n";
	
	legal_name = get_fullname();
	age = get_age();
	evidence_number = get_evidence_number();
	birthplace = get_birthplace();
	PESEL = get_PESEL();

	cout << "\nWe will ask you about your financial condition.";
	cout << "\nThen, the program will calculate your credit capacity.";

	cout << "\nHow high is your monthly income?"; 
	monthly_income = get_number("monthly income");

	cout << "\nHow high are your monthly spending on average.";
	monthly_spending = get_number("monthly spending");

}


void Credit::input_credit_details()
{
	cout << "\nHow much money do you expect to receive in a loan?"; 
	credit_amount = get_number("credit amount");

	
	cout << "\nWhen you take out a credit, you oblige yourself to repay one loan instalment every month";
	cout << "\nHow long do you intend to pay off the loan?";
	cout << "\nEnter answer in number of years, or if you prefer month period of time write number '0' (write only number)";
	number_of_instalments = get_number("answer");

	if (number_of_instalments == 0)
	{
		cout << "\nHow many months do you intend to pay off the loan?";
		cout << "\nYour answer: ";
		cin >> number_of_instalments;
	}
	else 
		number_of_instalments = number_of_instalments * 12;
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
	int r = lending_rate; //percentage value, so I multiply it * 0.01
	int m = 12; // amount instalment per year;
	int n = number_of_instalments; 

	monthly_payment = N * ((r * 0.01 / m) * (pow((1 + (r * 0.01 / m)), n))) / (pow((1 + (r * 0.01 / m)), n) - 1);
}


void Credit::calculate_monthly_capacity()
{
	float temp_capacity = monthly_income - monthly_spending;

	safety_buffer = (0.3 * temp_capacity);
	safety_buffer -= reduce_buffer;

	if (safety_buffer < 0)
		safety_buffer = 0;

	monthly_capacity = monthly_income - monthly_spending - safety_buffer;
}


void Credit::check_capacity()
{
	float score = monthly_capacity - monthly_payment;

	if (score >= 0)
		verification = true;
	else
		verification = false;
}


void Credit::feedback()
{
	if (verification == true)
		cout << "\nYour financial capacity is enough high to receive the credit";
	else
	{
		cout << "\nYour financial capacity isn't enough high to receive the credit";
		cout << "\nCurrently, you can receive only: " << current_opportunity << " zl";
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
		cout << "\nIf you have any suggestion to improve the program write to email: pitera.karol@gmail.com";
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
			 \n\nYou will receive credit amount: " << credit_amount << " zl\
			 \nPeriod of repay the credit: " << number_of_instalments << "mounths\
			 \nTotal amount to repay: " << total_credit << " zl\
			 \nMonthly instalment: " << monthly_payment << " zl";

	if (pledge)
	{
		cout << "\nYour pledge property : " << pledge_name << "\
				 \nPledge value: " << pledge_value << "zl";
	}

	cout << "\n\n********** Contract **********"\
			"\nI undertake to make monthly payments " << monthly_payment << " zl of constants amounts over time " << number_of_instalments << " months.\
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
	total_credit = monthly_payment * number_of_instalments;
}

/* The maximum loan amount (taking into account the APR) is calculated, which
the bank may grant the customer a loan based on the current credit capacity and the selected period repayment.*/

void Credit::calculate_current_opportunity(int lending_rate)
{
	int r = lending_rate;
	int k = 12; // amount instalment per year;
	int n = number_of_instalments;

	current_opportunity = monthly_capacity / (((r * 0.01 / k) * (pow((1 + (r * 0.01 / k)), n))) / (pow((1 + (r * 0.01 / k)), n) - 1));
}


void Credit::calculate_reduce_buffer()
{
	if (pledge)
	{
		reduce_buffer = pledge_value / number_of_instalments;
	}
	else if(!pledge)
	{
		reduce_buffer = 0;
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
		file << "\ninstalment_amount: " << number_of_instalments;	
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
			file << "\ncurrent_oportunity: " << current_opportunity; 
		}

		file << "\ncapacity: " << monthly_capacity;						
		file << "\nsafety_bufor: " << safety_buffer;				
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
	bool correction;

	cout << "\nWould you like type your personal data from file?";
	cout <<	"\nEnter 'yes' or 'no': ";
	string answer = type_in_answer("yes", "no");
	

	if (answer == "yes")
	{
		do
		{
			correction = false;
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