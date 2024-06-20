#include "vaccination.h"
#include "pet.h"
#include "user.h"
#include <ctime>
#include "DBConnection.h" 
using namespace std;

vaccination::vaccination() {
	//initialize
	vaccine_id = 0;
	pet_id = 0;
	user_id = 0;
	vaccine_date = "";
	vaccine_name = "";
	pet_name = "";
	user_name = "";
}
vaccination::vaccination(int vaccine_id, std::string vaccine_date, std::string vaccine_name, std::string pet_name, std::string user_name, int user_id, int pet_id) {
	this->vaccine_id = vaccine_id;
	this->vaccine_date = vaccine_date;
	this->vaccine_name = vaccine_name;
	this->pet_name = pet_name;
	this->user_name = user_name;
	this->user_id = user_id;
	this->pet_id = pet_id;
}

int vaccination::insertvaccination() {

	// Nanti untuk client, tukar query dia ikut attribute dalam database
	//string something = user.user_id <- tukarkan jadi string


	DBConnection db;//instantiate
	db.prepareStatement("Insert into vaccination (vaccine_date, vaccine_name, pet_id) VALUES (?,?,?)"); // <-- Ni nama dia query
	db.stmt->setString(1, vaccine_date);
	db.stmt->setString(2, vaccine_name);
	db.stmt->setString(3, pet_name);
	db.QueryStatement();
	generatedvaccine_id = db.getGeneratedId();
	db.~DBConnection();
	return generatedvaccine_id;
}

bool vaccination::vaccinedate_exist(const std::string& vaccine_date)
{
	DBConnection db;
	db.prepareStatement("SELECT * FROM vaccination WHERE vaccine_Date= ?");
	db.stmt->setString(1, vaccine_date);
	db.QueryResult();
	return (db.res->rowsCount() > 0);
}


void vaccination::updateVaccination() {
	//
	DBConnection db;
	db.prepareStatement("UPDATE vaccination SET vaccine_id=?, vaccine_date=?, WHERE user_id=? AND pet_id");
	db.stmt->setInt(1, vaccine_id);
	db.stmt->setString(2, vaccine_date);
	db.stmt->setInt(3, user_id);
	db.stmt->setInt(4, pet_id);
	db.QueryStatement();
	generatedvaccine_id = db.getGeneratedId();
	db.~DBConnection();

}

vector<vaccination> vaccination::findBook(string vaccine_date, string pet_name, string user_name, int vaccine_id, int pet_id, int user_idd, bool ascending)
{
	/*cout << "PHONE NUMBER ENTERED : " << user_name << endl;
	int x;
	cin >> x;*/
	string query = "SELECT v.*, p.pet_name, u.user_name, u.user_id FROM vaccination v JOIN pet p ON v.pet_id = p.pet_id JOIN user u ON p.user_id = u.user_id WHERE 1=1 AND u.user_phone = " + user_name;

	/*if (!vaccine_date.empty()) {
		query += " AND v.vaccine_date = ?";
	}
	if (!pet_name.empty()) {
		query += " AND p.pet_name = ?";
	}
	if (!user_name.empty()) {
		query += " AND u.user_name = ?";
	}
	if (vaccine_id != -1) {
		query += " AND v.vaccine_id = ?";
	}
	if (pet_id != -1) {
		query += " AND v.pet_id = ?";
	}
	if (user_id != -1) {
		query += " AND u.user_id = ?";
	}*/
	query += " ORDER BY v.vaccine_date " + std::string(ascending ? "ASC" : "DESC");


	DBConnection db;
	db.prepareStatement(query);

	/*int parameterIndex = 1;
	if (!vaccine_date.empty()) db.stmt->setString(parameterIndex++, "%" + vaccine_date + "%");
	if (vaccine_id != 0) db.stmt->setInt(parameterIndex++, vaccine_id);
	if (user_id != 0) db.stmt->setInt(parameterIndex++, user_id);*/

	vector<vaccination> vaccinations;

	db.QueryResult();

	if (db.res->rowsCount() > 0)
	{
		while (db.res->next())
		{
			vaccination tmpVaccinations(db.res);
			vaccinations.push_back(tmpVaccinations);
		}
		db.~DBConnection();
		return vaccinations;
	}

	return vaccinations;
}


vaccination::vaccination(sql::ResultSet* data)
{
	/*DBConnection db;
	db.prepareStatement("SELECT * FROM vaccination");*/
	vaccine_id = data->getInt("vaccine_id");
	user_id = data->getInt("user_id");
	pet_id = data->getInt("pet_id");
	vaccine_date = data->getString("vaccine_date");
	vaccine_name = data->getString("vaccine_name");
	pet_name = data->getString("pet_name");
	user_name = data->getString("user_name");
}
vaccination::~vaccination()
{
}
