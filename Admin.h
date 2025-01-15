#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>

using namespace std;

class Admin {
    string username;
    string password;

public:
    Admin() : username("admin"), password("password") {}

    bool loginAdmin() {
        string inputUsername, inputPassword;

        cout << "Enter Admin Username: ";
        cin >> inputUsername;
        cout << "Enter Admin Password: ";
        cin >> inputPassword;

        return (inputUsername == username && inputPassword == password);
    }
};

#endif