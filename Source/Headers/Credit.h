#include <iostream>
#include <string>

#ifndef CREDIT_H
#define CREDIT_H

class Credit
{
	std::string age;
	std::string birthplace;
	std::string evidence_number;
	std::string PESEL;

	float monthly_income;
	float monthly_spending;

	std::string pledge_name;
	float pledge_value; 
	
	int number_of_instalments;
	float monthly_payment;

	double total_credit;
	float current_opportunity;
	
	float monthly_capacity;
	float safety_buffer;
	float reduce_buffer;


public:
	
	int credit_counter;
	int credit_amount;
	bool verification, lack_finalisation = true, read_data = false, pledge = false;
	
	std::string legal_name;

	Credit() = default;
	~Credit() = default;
	virtual void operator++();

	virtual void read_data_file();
	virtual void calculate_credit();
	virtual void calculate_monthly_capacity();
	virtual void calculate_instalment(int lending_rate);
	virtual void calculate_current_opportunity(int lending_rate);
	virtual void calculate_reduce_buffer();
	

	virtual bool acceptation_conditions() = 0;       
	virtual void input_specific() = 0;

	virtual void input_universal();
	virtual void input_credit_details();
	virtual void input_pledge_info();

	virtual void check_capacity();
	
	virtual int return_lending_rate() = 0;
	
	virtual void save_all_data();
	virtual void save_based_data();
	virtual void save_credit_data();
	virtual void save_specific_data() = 0; 

	virtual void feedback();
	virtual void contract();
	virtual void final() = 0;

	virtual bool checkpoint();
	virtual bool checkpoint_2();
};

#endif