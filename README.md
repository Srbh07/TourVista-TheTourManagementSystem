# TourVista: Tour Package Management System

## Overview
TourVista is a C++ console application that allows users to manage and book tour packages. It offers functionalities for both administrators and customers, including package management, customer registration, and package suggestions based on budget.

## Features
### Admin Features
- Login using admin credentials.
- Add new tour packages.
- View all available tour packages.
## Customer Features
- Register as a new customer.
- Login as a customer.
- View available tour packages.
- Get package suggestions based on budget.
- Book a tour package.

## Usage
### Main Menu
- Admin Login: Access admin functionalities like adding or viewing packages.
- Register Customer: Create a new customer account.
- Customer Login: Access customer features like viewing packages, budget suggestions, and booking a tour.
- Exit: Exit the application.
### Admin Credentials
- Username: admin
- Password: password

## File Descriptions
- Admin.h: Handles admin login functionality.
- Customer.h: Manages customer registration and login.
- Package.h: Handles adding and viewing tour packages.
- main.cpp: Entry point of the program, contains menu navigation and core logic.

## Data Files
- packages.txt: Stores tour package information in the format ID,Name,Price,Days,Details.
- customers.txt: Stores customer credentials in the format Email,Password.
- bookings.txt: Logs bookings in the format CustomerEmail,PackageDetails.
