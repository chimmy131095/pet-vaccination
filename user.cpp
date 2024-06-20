#include "user.h"
#include <ctime>
#include <vector>
#include "DBConnection.h" 
using namespace std;

user::user() {
	//initialize
	user_id = 0;
	user_name = "";
	user_email = "";
	user_phone = "";
	user_password = "";
}
user::user(int user_id, std::string user_name, std::string user_email, std::string user_phone, std::string user_password) {
	this->user_id = user_id;
	this->user_name = user_name;
	this->user_email = user_email;
	this->user_phone = user_phone;
	this->user_password = user_password;
}
std::vector<user> user::searchUser(std::string user_phone)
{
	return std::vector<user>();
}
bool user::loginuser() {

	DBConnection db;
	db.prepareStatement("SELECT * FROM user WHERE user_name=? AND user_password=?");
	db.stmt->setString(1, user_name);
	db.stmt->setString(2, user_password);
	db.QueryResult();
	if (db.res->rowsCount() == 1) {
		while (db.res->next()) {
			user_id = db.res->getInt("user_id");
			user_name = db.res->getString("user_name");
			user_email = db.res->getString("user_email");
			user_phone = db.res->getString("user_phone");
			user_password = db.res->getString("user_password");
		}
		db.~DBConnection();
		return true;
	}
	else {

		db.~DBConnection();
		return false;
	}
}
void user::insert() {

	// Nanti untuk client, tukar query dia ikut attribute dalam database
	
	DBConnection db;//instantiate
	db.prepareStatement("Insert into user (user_name,user_email,user_phone,user_password) VALUES (?,?,?,?)"); // <-- Ni nama dia query
	db.stmt->setString(1, user_name);
	db.stmt->setString(2, user_email);
	db.stmt->setString(3, user_phone);
	db.stmt->setString(4, user_password);
	
	db.QueryStatement();
	db.~DBConnection();
}
void user::update() {

	DBConnection db;
	db.prepareStatement("UPDATE user SET user_name=?, user_email=?, user_phone=?, user_password=?, WHERE userid=?");
	db.stmt->setString(1, user_name);
	db.stmt->setString(2, user_email);
	db.stmt->setString(3, user_phone);
	db.stmt->setString(4, user_password);
	db.stmt->setInt(6, user_id);
	db.QueryStatement();
	db.~DBConnection();

}
void user::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM account WHERE userid=?");
	db.stmt->setInt(1, user_id);
	db.QueryStatement();
	db.~DBConnection();
}

user::~user() {

}



