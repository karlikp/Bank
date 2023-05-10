#pragma once

class Credit
{
	char* legal_name;
	int age = 0;
	char* evidence_number;
	int PESEL;
	char* birthplace;
	char* father_name;
	char* mother_name;
	char* mother_maiden_name;

public:

	//friend auto make_decision();
	//virtual void complete_data() = 0;
	//virtual int credit_capacity() = 0;
	virtual bool check_capacity();
	virtual void feedback();
	virtual int checkpoint();
	//virtual void final();
	//virtual void save_info();
	//virtual void exit();
};

