#pragma once
#include "DBConnection.h"
#ifndef vaccination_H
#define vaccination_H

#include <string>
#include <vector>

class vaccination
{
public://access specifier
	int vaccine_id, pet_id, user_id; //numerical attributes
	std::string vaccine_date, vaccine_name, pet_name, user_name; // text attributes


	vaccination(); // constructor method
	vaccination(int vaccine_id, std::string vaccine_date, std::string vaccine_name, std::string pet_name, std::string user_name, int user_id, int pet_id);

	int generatedvaccine_id;
	int insertvaccination();
	bool vaccinedate_exist(const std::string& vaccine_date);
	void updateVaccination();

	static std::vector<vaccination> findBook(std::string vaccine_date, std::string pet_name, std::string user_name, int vaccine_id, int pet_id, int user_id, bool ascending);


	/*void remove(); */

	vaccination(sql::ResultSet* data);

	~vaccination(); //destructor method


	/*static vaccination older(pet a, pet b);*/

};

#endif

