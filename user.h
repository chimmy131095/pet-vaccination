#pragma once
#ifndef user_H
#define user_H

#include <vector>
#include <string>

class user
{
public://access specifier
	int user_id; //numerical attributes
	std::string user_name, user_email, user_phone, user_password; // text attributes


	user(); // constructor method
	user(int user_id, std::string user_name, std::string user_email, std::string user_phone, std::string user_password);
	static std::vector<user> searchUser(std::string user_phone);
	bool loginuser();
	void insert();
	void update();
	void remove();

	~user(); //destructor method


	static user older(user a, user b);


};

#endif





