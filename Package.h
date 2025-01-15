#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Package {
    int id;
    string name;
    double price;
    int duration;
    string details;

public:
    void addPackage() {
        cout << "Enter Package ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Package Name: ";
        getline(cin, name);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Duration (days): ";
        cin >> duration;
        cin.ignore();
        cout << "Enter Package Details: ";
        getline(cin, details);

        ofstream outFile("packages.txt", ios::app);
        outFile << id << "," << name << "," << price << "," << duration << "," << details << endl;
        outFile.close();
        cout << "Package added successfully!" << endl;
    }

    void viewPackages() {
        ifstream inFile("packages.txt");
        if (!inFile) {
            cout << "No packages available." << endl;
            return;
        }

        string line;
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "Price" << setw(10) << "Days" << "Details" << endl;
        cout << string(60, '-') << endl;

        while (getline(inFile, line)) {
            size_t pos = 0;
            string token;
            while ((pos = line.find(',')) != string::npos) {
                token = line.substr(0, pos);
                cout << left << setw(15) << token;
                line.erase(0, pos + 1);
            }
            cout << line << endl;
        }
        inFile.close();
    }
};

#endif