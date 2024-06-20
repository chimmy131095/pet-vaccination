#pragma once
#ifndef admin_H
#define admin_H

#include <string>

class admin
{
public://access specifier
	int adminid; //numerical attributes
	std::string username, email, admin_password; // text attributes


	admin(); // constructor method
	admin(int adminid, std::string username, std::string email, std::string admin_password);

	bool loginAdmin();
	void insert();
	//void update();
	//void remove();

	~admin(); //destructor method


	//static admin older(admin a, admin b);

protected:
private:
};

#endif