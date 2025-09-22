#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "adminLogin.h"
#include "trainerLogin.h"

void adminLogin();
void trainerLogin();

using namespace std;

class admin adm;
class trainer fac;

int num = 0;

int main()
{
    int choice;
    cout << "\n\n--------------------------------------------------------------------" << endl;
    cout << "                                    TraineeX                          " << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "\n\n\t\tWelcome To Home Page" << endl;
    cout << "\n\t\tPress 1 --> Admin Login" << endl;
    cout << "\t\tPress 2 --> Trainer Login" << endl;
    cout << "\t\tPress 3 --> Exit" << endl;
    cout << "\nPlease Enter Your Choice : ";
    cin >> choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(512, '\n');
        cout << "\nPlease enter a number!!" << endl;
        main();
    }
    else
    {
        switch (choice)
        {
        case 1:
            adminLogin();
            break;
        case 2:
            trainerLogin();
            break;
        case 3:
            cout << "See you again." << endl;
            break;
        default:
            cout << "\nPlease select from the options given above" << endl;
            main();
        }
    }
}

void adminLogin() 
{
    string userId = "admin";
    string password = "12345";
    string id, pass;
    cout << "\n\n------------------------------------------" << endl;
    cout << "         Welcome To The Admin Page         " << endl;
    cout << "------------------------------------------" << endl;
    cout << "\n\nPlease Enter Your Username & Password For Authentiocation" << endl;

    cout << "\nEnter Your Username : ";
    cin >> id;

    cout << "\nEnter Your Password : ";
    cin >> pass;

    if (userId == id && password == pass)
    {
        cout << "\nCongratulations " << userId << endl;
        cout << "Your login as administrator is successfull. Thanks for logging in.\n"
             << endl;
        adm.adminModules();
    }
    else
    {
        cout << "\n!!!Login Error!!!" << endl;
        cout << "Please check your username and password again\n"
             << endl;
        num += 1;
        if (num == 3)
        {
            cout << "\nACCESS DENIED" << endl;
            exit(0);
        }
        main();
    }
}

void trainerLogin() 
{

    int count = 0;
    string id, pass, stream, userId, password, techName;
    cout << "\n\n------------------------------------------" << endl;
    cout << "         Welcome To The Trainer Page         " << endl;
    cout << "------------------------------------------" << endl;
    cout << "\n\nPlease Enter Your Credentials For Authentiocation" << endl;

    cout << "\nEnter Your Name : ";
    cin >> userId;

    cout << "\nEnter Your Password : ";
    cin >> password;

    cout << "\nEnter Your Technology Name : ";
    cin >> techName;

    ifstream input("./../data/trainerLogin.csv");

    while (input >> id >> pass >> stream)
    {
        if (id == userId && pass == password && stream == techName)
        {
            count = 1;
        }
    }

    input.close();

    if (count == 1)
    {
        cout << "\n\nCongratulations " << userId << endl;
        cout << "Your login as trainer is successfull. Thanks for logging in.\n"
             << endl;
        fac.loginId = userId;
        fac.trainerModules();
    }
    else
    {
        cout << "\n!!!Login Error!!!" << endl;
        cout << "Please enter your details again\n"
             << endl;
        num += 1;
        if (num == 3)
        {
            cout << "\nACCESS DENIED" << endl;
            exit(0);
        }
        main();
    }
}