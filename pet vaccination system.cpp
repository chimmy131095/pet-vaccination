#include <iostream>  
#include <conio.h>
#include <iomanip>

#include <sstream>
#include <vector> // Include the <vector> header for std::vector
#include<windows.h>
// advanced
// include our custom class
#include "admin.h" 
#include "user.h"
#include "menu.h"
#include "pet.h"
#include "vaccination.h"

using namespace std;

int main();
void registerAccount();

//user function
pet registerPet(user user, pet pets, vaccination vaccinations);
vaccination registerVaccination(user user, vaccination vaccinations, pet pets);
void payment(const user& usr);
bool isVaccinePaid(int vaccine_id);
void insertPaymentRecord(int vaccine_id, double amount, const std::string& method);
void home(user user);

std::vector<vaccination> findVaccinationsForUser(int user_id);
std::vector<pet> findPetsForUser(int user_id);

int search(user user);
//admin and user function
void roleMenu();

//admin function
void loginAdmin();
void loginClient();
void display();// CONTOH
void home(admin user);

//color design 
enum Color {
    Black,
    Blue,
    Green,
    Cyan,
    Red,
    Magenta,
    Yellow,
    White,
    Gray,
    Light_Blue,
    Light_Green,
    Light_Aqua,
    Light_Red,
    Light_Purple,
    Light_Yellow,
    Bright_White,
};

// background color
string background(Color color) {
    switch (color) {
    case Black:
        return "\u001b[40m";
    case Blue:
        return "\u001b[44m";
    case Green:
        return "\u001b[42m";
    case Cyan:
        return "\u001b[46m";
    case Red:
        return "\u001b[41m";
    case Magenta:
        return "\u001b[45m";
    case Yellow:
        return "\u001b[43m";
    case White:
        return "\u001b[47m";
    case Gray:
        return "\u001b[40;1m";
    case Light_Blue:
        return "\u001b[44;1m";
    case Light_Green:
        return "\u001b[42;1m";
    case Light_Aqua:
        return "\u001b[46;1m";
    case Light_Red:
        return "\u001b[41;1m";
    case Light_Purple:
        return "\u001b[45;1m";
    case Light_Yellow:
        return "\u001b[43;1m";
    case Bright_White:
        return "\u001b[47;1m";
    default:
        throw std::invalid_argument("invalid value");
    }
}

//text color
string foreground(Color color) {
    switch (color) {
    case Black:
        return "\u001b[30m";
    case Blue:
        return "\u001b[34m";
    case Green:
        return "\u001b[32m";
    case Cyan:
        return "\u001b[36m";
    case Red:
        return "\u001b[31m";
    case Magenta:
        return "\u001b[35m";
    case Yellow:
        return "\u001b[33m";
    case White:
        return "\u001b[37m";
    case Gray:
        return "\u001b[30;1m";
    case Light_Blue:
        return "\u001b[34;1m";
    case Light_Green:
        return "\u001b[32;1m";
    case Light_Aqua:
        return "\u001b[36;1m";
    case Light_Red:
        return "\u001b[31;1m";
    case Light_Purple:
        return "\u001b[35;1m";
    case Light_Yellow:
        return "\u001b[33;1m";
    case Bright_White:
        return "\u001b[37;1m";
    default:
        throw std::invalid_argument("invalid value");
    }
}
//table
void printTableLine();
void printTableLine(int width) {

    for (int i = 0; i < width; ++i) {
        cout << '-';
    }
    cout << endl;
}
//
////utility functions
//bool isNumeric(string input);
//
//// extras
//bool toInteger(string* input, int* valueholder);

int main()
{
    system("cls"); //clear the screen

    //adjusting windows console size
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    MoveWindow(console, r.left, r.top, 1500, 650, TRUE); //width=1500, height=650
    char optionMain;
    /*  Show();*/

    /*  cout << background(White) << foreground(Black) << endl;*/
    cout << "\t\t\t\t\t+------------------------------------------------+" << endl;
    cout << "\t\t\t\t\t||=> WELCOME TO PET VACCINATION SYSTEM   <=" << endl;
    cout << "\t\t\t\t\t+------------------------------------------------+";
    /* cout << background(Black) << foreground(White) << resetANSI() << endl;*/
    cout << endl;


    cout << "\t\t\t\t\t+------------------------------------------------+" << endl;
    cout << "\t\t\t\t\t=>            [1] Login                     <=" << endl;
    cout << "\t\t\t\t\t=>            [2] Register                  <=" << endl;
    cout << "\t\t\t\t\t=>            [3] Exit                      <=||" << endl;
    cout << "\t\t\t\t\t+------------------------------------------------+" << endl;
    cout << endl;

    cout << "\n\t\t\t\t\tEnter your option: ";
    cin >> optionMain;

    // Validation of option
    while (optionMain != '1' && optionMain != '2' && optionMain != '3') {
        cin.clear();  // Clear the error flag
        cout << "Invalid input! Please enter 1, 2, or 3: ";
        cin >> optionMain;
    }

    // Choice of homemenu
    if (optionMain == '1') {
        roleMenu();
    }
    else if (optionMain == '2') {
        registerAccount();
    }
    else if (optionMain == '3') {
        exit(0);
    }
    else
    {
        cout << "Invalid!";
        system("pause");
        main();
    }
}

void roleMenu() {
    Menu roleMenu;
    roleMenu.header = "\n\n\t ----------- Choose your role: ---------- \n\t";
    roleMenu.addOption("Login as admin");
    roleMenu.addOption("Login as user");
    roleMenu.addOption("Back");

    while (1) {
        switch (roleMenu.prompt())
        {
        case 1:
            loginAdmin();
            break;
        case 2:
            loginClient();
            break;
        case 3:
            main();
            return;
            break;
        default:
            break;
        }
    }
}

void registerAccount() {
    user newacc;
    //pet haiwan;
    Menu rgMenu;
    rgMenu.header = "****** Please key in the data for User Registration ****** \n\n\t";
    rgMenu.addOption("Username");
    rgMenu.addOption("Email");
    rgMenu.addOption("Phone");
    rgMenu.addOption("Password");
    rgMenu.addOption("Register");
    rgMenu.addOption("Back");

    string tmpinput;
    bool valid = true;
    bool allDataEntered = false;
    while (1) {

        switch (rgMenu.prompt()) {
        case 1:
            cout << "Insert User Name:";
            cin >> newacc.user_name;
            rgMenu.setValue(0, newacc.user_name);
            break;
        case 2:
            cout << "Insert Email:";
            cin >> newacc.user_email;
            rgMenu.setValue(1, newacc.user_email);
            break;
        case 3:
            cout << "Insert Phone:";
            cin >> newacc.user_phone;
            rgMenu.setValue(2, newacc.user_phone);
            break;
        case 4:
            cout << "Insert password:";
            cin >> tmpinput;
            if (tmpinput.length() < 6) {
                cout << "Password must be at least 6 character long";
                _getch();
            }
            else {
                newacc.user_password = tmpinput;
                rgMenu.setValue(3, newacc.user_password);
            }
            break;
        case 5:
            if (newacc.user_name.empty() || newacc.user_email.empty() || newacc.user_phone.empty() || newacc.user_password.empty()) {
                cout << "Please fill in all required fields before registering." << endl;
                _getch();
            }
            else{
            newacc.insert();
            //haiwan.insert(user);
            cout << "New User Successfully Registered";
            _getch();
            main();
            return;
            }
            break;
        case 6:
            return;
        default:
            break;
        }
    }

}

pet registerPet(user user,pet pets, vaccination vaccinations) {
    pet newpet = pets;
    newpet.user_id = user.user_id;
    newpet.vaccine_id = vaccinations.vaccine_id;
    //pet haiwan;
    Menu rgMenu;
    rgMenu.header = "****** Please key in the data for Pet Registration ****** \n\n\t";
    rgMenu.addOption("Pet Name");
    rgMenu.addOption("Pet Age");
    rgMenu.addOption("Pet Breed");
    rgMenu.addOption("Pet Gender");
    rgMenu.addOption("Register");
    rgMenu.addOption("Back");

    string tmpinput;
    bool valid = true;
    while (1) {

        switch (rgMenu.prompt()) {
        case 1:
            cout << "Insert Pet Name:";
            cin >> newpet.pet_name;
            rgMenu.setValue(0, newpet.pet_name);
            break;
        case 2:
            cout << "Insert Pet Age:";
            getline(cin, newpet.pet_age);
            rgMenu.setValue(1, newpet.pet_age);
            break;
        case 3:
            cout << "Insert Pet Breed:";
            cin >> newpet.pet_breed;
            rgMenu.setValue(2, newpet.pet_breed);
            break;
        case 4:
            cout << "Insert Pet Gender:";
            cin >> newpet.pet_gender;
            rgMenu.setValue(3, newpet.pet_gender);
            break;
        case 5:
            /*newpet.insertpet(user user_id);*/
            //haiwan.insert(user);
            valid = true;
            newpet.insertpet();
            cout << "New Pet Successfully Registered";
            _getch();
        case 6:
            return pets;
        default:
            break;
        }
    }

}

vaccination registerVaccination(user user, vaccination vaccinations, pet pets) {
    vaccination newvaccination = vaccinations;
    newvaccination.user_id = user.user_id;
    newvaccination.pet_id = pets.pet_id;
    newvaccination.vaccine_id = vaccinations.vaccine_id;
    vaccination temp = vaccinations;
    //pet haiwan;
    Menu rgMenu;
    rgMenu.header = " ****** Please key in the data for Vaccination Booking ****** \n\n\t";
    rgMenu.addOption("Vaccine Date");
    rgMenu.addOption("Vaccine Name");
    rgMenu.addOption("Pet ID");
    rgMenu.addOption("Register");
    rgMenu.addOption("Back");

    string tmpinput;
    bool valid = true;
    while (1) {

        switch (rgMenu.prompt()) {
        case 1:
            cout << "Insert Vaccine Date (YYYY-MM-DD):";
            cin >> newvaccination.vaccine_date;
            if (vaccinations.vaccinedate_exist(vaccinations.vaccine_date))
            {
                cout << "\n\n\t Sorry, your booking date currently not available. \n\n\t The chosen booking date has already been reserved by someone. \n\n\t Please choose another date. \n";
                _getch();
                cout << "\n Set another Date for Booking (YYYY-MM-DD); ";
                cin >> newvaccination.vaccine_date;
            }
            rgMenu.setValue(0, newvaccination.vaccine_date);
            break;
        case 2:
            cout << "Insert Vaccine Name [E = Elanco (RM80) | N = Nobivac (RM60) | Z = Zoetis (RM150) | P = PureVax (RM100) ]: ";
            cin >> newvaccination.vaccine_name;
            rgMenu.setValue(1, newvaccination.vaccine_name);
            break;
        case 3:
            cout << "Insert Pet ID:";
            cin >> newvaccination.pet_name;
            rgMenu.setValue(2, newvaccination.pet_name);
            break;
        case 4:
            valid = true;
            newvaccination.insertvaccination();
            cout << "Successfully Registered";
            _getch();
        case 5:
            return vaccinations;
        default:
            break;
        }
    }

}

void payment(const user& usr) {
    std::vector<pet> pets = findPetsForUser(usr.user_id);
    std::vector<vaccination> vaccinations = findVaccinationsForUser(usr.user_id);

    std::cout << "Vaccination details for user: " << usr.user_name << "\n";
    for (const auto& pet : pets) {
        for (const auto& vacc : vaccinations) {
            if (vacc.pet_id == pet.pet_id) {

                std::cout << "Pet Name: " << pet.pet_name << "\n";

                if (isVaccinePaid(vacc.vaccine_id)) {
                    std::cout << "Vaccine ID: " << vacc.vaccine_id << ", Date: " << vacc.vaccine_date << ", Name: " << vacc.vaccine_name << " (Paid)\n";
                }
                else {
                    std::cout << "Vaccine ID: " << vacc.vaccine_id << ", Date: " << vacc.vaccine_date << ", Name: " << vacc.vaccine_name << " (Unpaid)\n";
                    std::cout << "Would you like to pay for this vaccination? (yes/no): ";
                    std::string response;
                    std::cin >> response;
                    if (response == "yes") {
                        double price = 0.0;
                        char vaccine_type = toupper(vacc.vaccine_name[0]);
                        switch (vaccine_type) {
                        case 'E':
                            price = 80.0;
                            break;
                        case 'N':
                            price = 60.0;
                            break;
                        case 'Z':
                            price = 150.0;
                            break;
                        case 'P':
                            price = 100.0;
                            break;
                        default:
                            std::cout << "Invalid vaccine type.\n";
                            continue;
                        }

                        std::cout << "Payment method (cash/card): ";
                        std::string payment_method;
                        std::cin >> payment_method;

                        if (payment_method == "cash") {
                            double cash_received = 0.0;
                            while (cash_received < price) {
                                double cash;
                                std::cout << "Please enter cash amount: ";
                                std::cin >> cash;
                                cash_received += cash;
                                if (cash_received < price) {
                                    std::cout << "Insufficient amount. You still need to pay RM" << (price - cash_received) << "\n";
                                }
                            }
                            double balance = cash_received - price;
                            std::cout << "Payment received in cash. Thank you!\n";
                            if (balance > 0) {
                                std::cout << "Your change is RM" << balance << "\n";
                            }
                            insertPaymentRecord(vacc.vaccine_id, price, "cash");

                        }
                        else if (payment_method == "card") {
                            std::cout << "Enter card details:\n";
                            std::string card_number, expiry_date, cvv;
                            std::cout << "Card Number: ";
                            std::cin >> card_number;
                            std::cout << "Expiry Date (MM/YY): ";
                            std::cin >> expiry_date;
                            std::cout << "CVV: ";
                            std::cin >> cvv;
                            // Process the card payment
                            // If payment is successful:
                            std::cout << "Payment successful. Thank you!\n";
                            insertPaymentRecord(vacc.vaccine_id, price, "card");

                        }
                        else {
                            std::cout << "Invalid payment method.\n";
                        }
                    }

                }
            }
        }
    }
}

std::vector<vaccination> findVaccinationsForUser(int user_id) {
    std::vector<vaccination> vaccinations;
    DBConnection db;
    std::string query = "SELECT v.vaccine_id, v.vaccine_date, v.vaccine_name, v.pet_id, p.user_id, p.pet_name, u.user_name "
        "FROM vaccination v JOIN pet p ON v.pet_id = p.pet_id "
        "JOIN user u ON p.user_id = u.user_id WHERE u.user_id = ?";
    db.prepareStatement(query);
    db.stmt->setInt(1, user_id);
    db.QueryResult();
    while (db.res->next()) {

        vaccination tmpVaccinations(db.res);
        vaccinations.push_back(tmpVaccinations);
       /* int vaccine_id = db.res->getInt("vaccine_id");
        std::string vaccine_date = db.res->getString("vaccine_date");
        std::string vaccine_name = db.res->getString("vaccine_name");
        int pet_id = db.res->getInt("pet_id");
        vaccinations.emplace_back(vaccine_id, vaccine_date, vaccine_name, pet_id);*/
    }
    return vaccinations;
}

std::vector<pet> findPetsForUser(int user_id) {
    std::vector<pet> pets;
    DBConnection db;
    std::string query = "SELECT p.pet_id, p.pet_name FROM pet p WHERE p.user_id = ?";
    db.prepareStatement(query);
    db.stmt->setInt(1, user_id);
    db.QueryResult();
    while (db.res->next()) {
        int pet_id = db.res->getInt("pet_id");
        std::string pet_name = db.res->getString("pet_name");
        pets.emplace_back(pet_id, pet_name);
    }
    return pets;
}

bool isVaccinePaid(int vaccine_id) {
    DBConnection db;
    std::string query = "SELECT COUNT(*) FROM payment WHERE vaccine_id = ?";
    db.prepareStatement(query);
    db.stmt->setInt(1, vaccine_id);
    db.QueryResult();
    if (db.res->next()) {
        int count = db.res->getInt(1);
        return count > 0;
    }
    return false;
}

void insertPaymentRecord(int vaccine_id, double amount, const std::string& method) {
    DBConnection db;
    std::string query = "INSERT INTO payment (payment_amount, vaccine_id) VALUES (?, ?)";
    db.prepareStatement(query);
    db.stmt->setDouble(1, amount);
    db.stmt->setInt(2, vaccine_id);
    db.QueryStatement();
}

void loginAdmin() {
    Menu loginAdmin;
    loginAdmin.header = "LOGIN ADMIN";
    loginAdmin.addOption("Username");
    loginAdmin.addOption("Password");
    loginAdmin.addOption("Login");
    loginAdmin.addOption("Back");

    admin user;

    while (1) {
        switch (loginAdmin.prompt())
        {
        case 1:
            cout << "Insert Username:";
            cin >> user.username;
            loginAdmin.setValue(0, user.username);
            break;
        case 2:
            cout << "Insert Password:";
            cin >> user.admin_password;
            loginAdmin.setValue(1, user.admin_password);
            break;
        case 3:
            if (user.loginAdmin()) {
                home(user);
            }
            else {
                cout << "\n\n\t Invalid Login \n\n\t Press any key to login again. \n\n";
                _getch();
            }
            break;
        case 4:
            return;
            break;
        default:
            break;
        }
    }
}

void loginClient() {
    Menu loginClient;
    loginClient.header = "****** Login User ****** \n\n\t";
    loginClient.addOption("Username");
    loginClient.addOption("Password");
    loginClient.addOption("Login");
    loginClient.addOption("Back");

    user user;

    while (1) {
        switch (loginClient.prompt())
        {
        case 1:
            cout << "Insert Username:";
            cin >> user.user_name;
            loginClient.setValue(0, user.user_name);
            break;
        case 2:
            cout << "Insert Password:";
            cin >> user.user_password;
            loginClient.setValue(1, user.user_password);
            break;
        case 3:
            if (user.loginuser()) {
                home(user);
            }
            else {
                cout << "Invalid Login";
                _getch();
            }
            break;
        case 4:
            return;
            break;
        default:
            break;
        }
    }
}


void home(admin user) {
    Menu homeMenu;
    homeMenu.header = "****** Admin Main Menu ****** \n\n\t";
    homeMenu.addOption("Display Booking Information");
    homeMenu.addOption("View Monthly Report");
    homeMenu.addOption("Back");


    while (1) {
        switch (homeMenu.prompt())
        {
        case 1:
            //updateBookingDate();
            break;
        case 2:
            //dipslayBookingInformation();
            break;
        case 3:
            //viewMonthlyreport();
            break;
        case 4:
            return;
            break;
        default:
            break;
        }
    }
}

void home(user user) {
    Menu homeMenu;
    pet pets;
    vaccination vaccinations;
    vaccination book;
    int user_id;
    homeMenu.header = "User Main Menu";
    homeMenu.addOption("Add Pet");
    homeMenu.addOption("Add Booking");
    homeMenu.addOption("Search");
    homeMenu.addOption("Update Booking Date");
    homeMenu.addOption("Delete Booking");
    homeMenu.addOption("Payment");
    homeMenu.addOption("Back");

    while (1) {
        homeMenu.header = "Welcome" + user.user_name;
        switch (homeMenu.prompt())
        {
        case 1:
            registerPet(user, pets, vaccinations);
            break;
        case 2:
            registerVaccination(user, vaccinations, pets);
            break;
        case 3:
            search(user);
            cout << "Enter User Phone Number to update booking date: ";
            cin >> user_id;
            break;
        case 4:
            //update booking();
            break;
        case 5:
            //deleteBooking();
            break;
        case 6:
            payment(user);
            break;
        case 7:
            return;
            break;
        default:
            break;
        }
    }
}

int search(user user)
{
    //vector<user> user;
    string displayB = "";
    vector <vaccination> vaccinations;
    int vaccine_id = 0, pet_id = 0, user_id = 0;
    string vaccine_date = "" , pet_name = "", user_name = "", status = "";
    bool asc = true;

    Menu searchB;
    searchB.header = "\n\n\t\tSearch: ";
    searchB.addOption(" 1 > Search by user Phone Number");
    searchB.addOption(" 3 > Back");
    searchB.addOption(" 2 > Update Status ");

    while (1)
    {
        if (asc)
        {
            searchB.setValue(2, "Ascending");
        }
        else
        {
            searchB.setValue(2, "Descending");
        }
        if (displayB == "")
        {
            displayB = "\n\tResult:\n\n";
            stringstream tmpS;

            tmpS << setw(5) << "User ID | " << setw(9) << "Pet ID | " << setw(9) << " Vaccine ID | " << setw(13) << " Vaccine Name | " << setw(13) << "Pet Name | " << setw(13) << " User Name  | " << setw(13) << " Vaccine Date | " << endl;

            for (int i = 0; i < vaccinations.size(); i++)
            {
                tmpS << setw(7) << vaccinations[i].user_id << " |" << setw(7)  << vaccinations[i].pet_id << " |" << setw(12) << vaccinations[i].vaccine_id << " |" << setw(14) << vaccinations[i].vaccine_name << " |" << setw(11) << vaccinations[i].pet_name << " |" << setw(12) << vaccinations[i].user_name << " |" << setw(14) << vaccinations[i].vaccine_date << " |" << endl;
            }
            if (vaccinations.size() == 0)
                tmpS << "Phone number entered is not found in our database, try again." << endl;
            displayB += tmpS.str();


        }
        searchB.footer = displayB;
        string phone = "";


        switch (searchB.prompt())
        {
        case 1:
            cout << " Insert User Phone Number: ";
            cin >> phone;
            searchB.setValue(0, to_string(user_id));
            vaccinations = vaccination::findBook(vaccine_date, pet_name, phone, vaccine_id, user_id, pet_id, asc);
            displayB = "";
            break;
        case 2:
            asc = !asc;
            vaccinations = vaccination::findBook(vaccine_date, pet_name, user_name, vaccine_id, user_id, pet_id, asc);
            displayB = "";
            break;
        case 3:
            home (user);
            break;
        case 4:
            // Update Date
            cout << "Enter User Phone to Update booking date: ";
            cin >> user_id;

            // Find the appointment with the specified AppointmentID
            auto it = find_if(vaccinations.begin(), vaccinations.end(), [user_id](const vaccination& vaccinations) {
                return vaccinations.user_id == user_id;
                });

            if (it != vaccinations.end()) {
                // Appointment found, update the date
                cout << "Enter new vaccine date: ";
                cin >> vaccine_date;
                it->vaccine_date = status;
                it->updateVaccination();
                cout << "The date has been successfully updated." << endl;
            }
            else {
                cout << "Appointment not found." << endl;
                _getch();
            }

            break;
        }
    }
}

void display() {
    cout << "\n\n HAIIIII";
    _getch();
}