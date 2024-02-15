// phase-4.cpp
// Ian Luna Quiroz

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "phase-4-classes.h"
using namespace std;

void addAccount(int customerID, vector<Customer *> & customerList, vector<Account *> & globalAccountList) {
    short selection = 0;
    double initBal = 0;
    cout << "\nWhat type of account would you like to create?"
         << "\n(1) Checking..."
         << "\n(2) Savings..."
         << "\n(3) Money Market..."
         << "\n(4) CD..."
         << "\n\nEnter your selection: ";
    cin >> selection;

    if (selection == 4) {
        cout << "\nChoose a term for your CD: "
             << "\n(1) 3 months..."
             << "\n(2) 6 months..."
             << "\n(3) 12 months..."
             << "\n\nEnter your selection: ";
        cin >> selection;
        selection += 4;
    }

    cout << "\nWhat will be the initial balance for this account?"
         << "\nEnter amount: ";
    cin >> initBal;

    customerList[customerID - 1]->createAccount(selection, initBal, globalAccountList);
    cout << "\nThe following account was created: " << endl;
    globalAccountList.back()->viewAcctInfo();
}

void addCustomerAndAccts(vector<Customer *> & customerList, vector<Account *> & globalAccountList) {
    bool exitFlag = true;
    do {
        int selection = 0;
        int accountsAmt = globalAccountList.size();
        cout << "\nWould you like to add a new customer or add a new account to an existing customer?"
             << "\n(1) Add a completely NEW customer..."
             << "\n(2) Add an account to an EXISTING customer..."
             << "\n(3) Go back..."
             << "\n\nEnter your selection: ";
        cin >> selection;

        switch (selection) {
            case 1: {
                string fName;
                string lName;
                string mailingAddr;
                string emailAddr;
                int customerID = customerList.size() + 1;

                cout << "\nPlease enter the customer's first name, last name, mailing address, email address, & customer ID one at a time."
                    << "\nFirst name: ";
                cin >> fName;
                cout << "Last name: ";
                cin >> lName;
                cout << "Mailing address: ";
                ws(cin);
                getline(cin, mailingAddr);
                cout << "Email address: ";
                cin >> emailAddr;

                Customer * newCustomer = new Customer(fName, lName, mailingAddr, emailAddr, customerID);
                customerList.push_back(newCustomer);

                cout << "\nThe following customer was added:" << endl;
                customerList.back()->viewCustomerInfo();
                cout << "\nAn account must be created." << endl;
                addAccount(customerID, customerList, globalAccountList);
                break;
            }
            case 2: {
                int customerid = -1;
                cout << "\nWhat is the customer ID of whom this new account will belong to?"
                     << "\nCustomer ID: ";
                cin >> customerid;
                addAccount(customerid, customerList, globalAccountList);
                break;
            }
            case 3:
                exitFlag = false;
                break;
            default:
                cout << "That's not an option.";
                break;
        }
    }while (exitFlag); 
}

void sortAndListAccts(vector<Account *> & globalAccountList) {
    sort(globalAccountList.begin(), globalAccountList.end());

    for (int i = 0; i < globalAccountList.size(); ++i) {
        globalAccountList[i]->viewAcctInfo();
        cout << endl;
    }
}

int mainMenu() {
    int selection = 0;
    cout << "\n\nWhat would you like to do today?"
         << "\n(1) Add customers and accounts..."
         << "\n(2) Delete customers and accounts..."
         << "\n(3) View existing accounts..."
         << "\n(4) View existing customers..."
         << "\n(5) Exit."
         << "\n\nEnter your selection: ";
    cin >> selection;
    return selection;
}

int main() {
    ofstream dataFile("bankData.dat", ios::binary);
    if (!dataFile) { // Ensures that output file can be opened & exits program if it cannot
        cout << "Could not open bankData.dat";
        return 1;
    }

    int selection = 0;
    bool exitFlag = true;
    vector<Customer *> customerList;
    vector<Account *> globalAccountList;

    cout << "Samediff Bank Data Filing System";

    do {
        selection = mainMenu();

        switch (selection) {
            case 1:
                 addCustomerAndAccts(customerList, globalAccountList);
                 break;
            case 2:
                cout << "Delete customers and accounts";
                break;
            case 3:
                sortAndListAccts(globalAccountList);
                break;
            case 4:
                cout << "View existing customers";
                break;
            case 5:
                exitFlag = false;
                break;
            default:
                cout << "That's not an option.";
                break;
        }
        
    } while (exitFlag);

    dataFile.close();
    return 0;
}