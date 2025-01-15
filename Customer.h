#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Customer {
    string name;
    string email;
    string password;

public:
    void registerCustomer() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Password: ";
        cin >> password;

        ofstream outFile("customers.txt", ios::app);
        outFile << email << "," << password << "," << name << endl;
        outFile.close();
        cout << "Customer registered successfully!" << endl;
    }

    bool loginCustomer() {
        string inputEmail, inputPassword;

        cout << "Enter Email: ";
        cin >> inputEmail;
        cout << "Enter Password: ";
        cin >> inputPassword;

        ifstream inFile("customers.txt");
        if (!inFile) {
            cout << "No registered customers found.\n";
            return false;
        }

        string line, email, password;
        while (getline(inFile, line)) {
            size_t pos = line.find(',');
            email = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(',');
            password = line.substr(0, pos);

            if (email == inputEmail && password == inputPassword) {
                return true;
            }
        }

        return false;
    }
};

#endif