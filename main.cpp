#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Admin.h"
#include "Package.h"
#include "Customer.h"

using namespace std;

void bookTour() {
    int packageId;
    string customerEmail;

    cout << "Enter your Email: ";
    cin >> customerEmail;
    cout << "Enter Package ID to book: ";
    cin >> packageId;

    ifstream packageFile("packages.txt");
    if (!packageFile) {
        cout << "No packages available to book.\n";
        return;
    }

    bool packageFound = false;
    string line;
    while (getline(packageFile, line)) {
        size_t pos = line.find(',');
        int id = std::stoi(line.substr(0, pos));
        if (id == packageId) {
            packageFound = true;
            ofstream bookingFile("bookings.txt", ios::app);
            if (bookingFile) {
                bookingFile << customerEmail << "," << line << endl;
                cout << customerEmail << " booked the tour (Tour ID: "<< id << ") successfully!\n";
            } else {
                cout << "Error saving booking.\n";
            }
            bookingFile.close();
            break;
        }
    }

    if (!packageFound) {
        cout << "Package ID not found.\n";
    }
    packageFile.close();
}

void suggestPackages() {
    double budget;

    cout << "Enter your budget: ";
    cin >> budget;

    ifstream packageFile("packages.txt");
    if (!packageFile) {
        cout << "No packages available.\n";
        return;
    }

    bool found = false;
    string line;

    cout << "\nPackages matching your budget:\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Days" << "Details" << endl;
    cout << string(60, '-') << endl;

    while (getline(packageFile, line)) {
        size_t pos = 0;
        string token;
        double price;
        string details;

        pos = line.find(',');
        int id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(',');
        string name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        price = stod(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(',');
        int days = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        details = line;

        if (price <= budget) {
            found = true;
            cout << left << setw(10) << id << setw(20) << name << setw(10) << price << setw(10) << days << details << endl;
        }
    }

    if (!found) {
        cout << "No packages found within your budget.\n";
    }
    packageFile.close();
}

void adminMenu() {
    Admin admin;
    Package pkg;

    int choice;
    do {
        system("cls");
        cout << "Admin Menu\n";
        cout << "1. Add Package\n";
        cout << "2. View Packages\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pkg.addPackage();
                system("pause");
                break;
            case 2:
                pkg.viewPackages();
                system("pause");
                break;
            case 3:
                cout << "Exiting Admin Menu...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                system("pause");
        }
    } while (choice != 3);
}

void customerMenu() {
    Customer customer;
    Package pkg;

    int choice;
    do {
        system("cls");
        cout << "Customer Menu\n";
        cout << "1. View Packages\n";
        cout << "2. Suggest Packages Based on Budget\n";
        cout << "3. Book a Tour\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pkg.viewPackages();
                system("pause");
                break;
            case 2:
                suggestPackages();
                system("pause");
                break;
            case 3:
                bookTour();
                system("pause");
                break;
            case 4:
                cout << "Exiting Customer Menu...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                system("pause");
        }
    } while (choice != 4);
}

void mainMenu() {
    int choice;
    Admin admin;
    Customer customer;

    do {
        system("cls");
        cout << "Welcome  to TourVista\n";
        cout << "---------------------\n";
        cout << "1. Admin Login\n";
        cout << "2. Register Customer\n";
        cout << "3. Customer Login\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (admin.loginAdmin()) {
                    adminMenu();
                } else {
                    cout << "Invalid admin credentials!\n";
                    system("pause");
                }
                break;
            case 2:
                customer.registerCustomer();
                system("pause");
                break;
            case 3:
                if (customer.loginCustomer()) {
                    customerMenu();
                } else {
                    cout << "Invalid customer credentials!\n";
                    system("pause");
                }
                break;
            case 4:
                cout << "Thank you for visiting!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                system("pause");
        }
    } while (choice != 4);
}

int main() {
    mainMenu();
    return 0;
}