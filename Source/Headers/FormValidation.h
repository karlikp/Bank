#include <string>

#ifndef FORMVALIDATION_H
#define FORMVALIDATION_H

std::string get_fullname();

std::string get_age();

std::string get_birthplace();

std::string get_evidence_number();

std::string get_PESEL();

int get_number(std::string desire_info);

std::string get_letter_answer(std::string target);

std::string get_account_number();

std::string get_NIP();

std::string type_in_answer(std::string yes, std::string no);

#endif