#pragma once
#include "DBConnection.h"
#ifndef pet_H
#define pet_H

#include <string>

class pet
{
public://access specifier
	int pet_id, user_id, vaccine_id; //numerical attributes
	std::string pet_name, pet_age, pet_breed, pet_gender; // text attributes


	pet(); // constructor method
	pet(int id, std::string name); // constructor method
	pet(int pet_id, std::string pet_name, std::string pet_age, std::string pet_breed, std::string pet_gender, int user_id, int vaccine_id);

	int generatedpet_id;
	int insertpet();
	/*void update();
	void remove();*/

	~pet(); //destructor method


	/*static pet older(pet a, pet b);*/

};

#endif
