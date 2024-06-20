#include "pet.h"
#include "user.h"
#include "vaccination.h"
#include <ctime>
#include "DBConnection.h" 
using namespace std;

pet::pet() {
	//initialize
	pet_id = 0;
	user_id = 0;
	vaccine_id = 0;
	pet_name = "";
	pet_age = "";
	pet_breed = "";
	pet_gender = "";
}

pet::pet(int id, string name) {
	//initialize
	pet_id = id;
	user_id = 0;
	vaccine_id = 0;
	pet_name = name;
	pet_age = "";
	pet_breed = "";
	pet_gender = "";
}
pet::pet(int pet_id, std::string pet_name, std::string pet_age, std::string pet_breed, std::string pet_gender, int user_id, int vaccine_id) {
	this->pet_id = pet_id;
	this->pet_name = pet_name;
	this->pet_age = pet_age;
	this->pet_breed = pet_breed;
	this->pet_gender = pet_gender;
	this->user_id = user_id;
	this->vaccine_id = vaccine_id;
}

int pet::insertpet() {

	// Nanti untuk client, tukar query dia ikut attribute dalam database
	//string something = user.user_id <- tukarkan jadi string


	DBConnection db;//instantiate
	db.prepareStatement("Insert into pet (pet_name, pet_age, pet_breed, pet_gender, user_id) VALUES (?,?,?,?,?)"); // <-- Ni nama dia query
	db.stmt->setString(1, pet_name);
	db.stmt->setString(2, pet_age);
	db.stmt->setString(3, pet_breed);
	db.stmt->setString(4, pet_gender);
	db.stmt->setInt(5, user_id);
	db.QueryStatement();
	generatedpet_id = db.getGeneratedId();
	db.~DBConnection();
	return generatedpet_id;
}
//void pet::update() {
//
//	DBConnection db;
//	db.prepareStatement("UPDATE pet SET pet_name=?, pet_age=?, pet_breed=?, pet_gender=?, WHERE pet_id=?");
//	db.stmt->setString(1, pet_name);
//	db.stmt->setString(2, pet_age);
//	db.stmt->setString(3, pet_breed);
//	db.stmt->setString(4, pet_gender);
//	db.stmt->setInt(6, pet_id);
//	db.QueryStatement();
//	db.~DBConnection();
//
//}
//void pet::remove() {
//	DBConnection db;
//	db.prepareStatement("DELETE FROM pet WHERE petid=?");
//	db.stmt->setInt(1, pet_id);
//	db.QueryStatement();
//	db.~DBConnection();
//}

pet::~pet() {

}

