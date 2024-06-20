#include "admin.h"
#include <ctime>
#include "DBConnection.h" 
using namespace std;

admin::admin() {
	//initialize
	adminid = 0;
	//user_id = 0;
	username = "";
	email = "";
	admin_password = "";
	//user_name = "";
	//user_email = "";
	//user_phone = "";
	//user_password = "";

}
admin::admin(int adminid, std::string username, std::string email, std::string admin_password) {
	this->adminid = adminid;
	this->username = username;
	this->email = email;

}

bool admin::loginAdmin() {

	DBConnection db;
	db.prepareStatement("SELECT * FROM admin WHERE username=? AND admin_password=?");
	db.stmt->setString(1, username);
	db.stmt->setString(2, admin_password);
	db.QueryResult();
	if (db.res->rowsCount() == 1) {
		while (db.res->next()) {
			adminid = db.res->getInt("adminid");
			username = db.res->getString("username");
			email = db.res->getString("email");
			admin_password = db.res->getString("admin_password");
		}
		db.~DBConnection();
		return true;
	}
	else {

		db.~DBConnection();
		return false;
	}
}

/*void admin::insert() {

	// Nanti untuk client, tukar query dia ikut attribute dalam database

	DBConnection db;//instantiate
	db.prepareStatement("Insert into admin (username,email,admin_password) VALUES (?,?,?,?,?)"); // <-- Ni nama dia query
	db.stmt->setString(1, username);
	db.stmt->setString(2, email);
	db.stmt->setString(3, admin_password);
	db.QueryStatement();
	db.~DBConnection();
}
void admin::update() {

	DBConnection db;
	db.prepareStatement("UPDATE admin SET username=?, email=?, admin_password=?, WHERE adminid=?");
	db.stmt->setString(1, username);
	db.stmt->setString(2, email);
	db.stmt->setString(3, admin_password);
	db.stmt->setInt(6, adminid);
	db.QueryStatement();
	db.~DBConnection();

}
void admin::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM account WHERE adminid=?");
	db.stmt->setInt(1, adminid);
	db.QueryStatement();
	db.~DBConnection();
}*/

admin::~admin() {

}

