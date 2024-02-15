// phase-4-classes.h
// Ian Luna Quiroz

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Account {
    protected:
        double balance;
        int acctNum;
        int customerID;
    public:
        virtual double getAcctBal() = 0;
        virtual void setAcctBal(double) = 0;
        virtual void deposit(double) = 0;
        virtual void withdraw(double) = 0;
        virtual void processInterest() = 0;
        virtual double processPenalties() = 0;
        virtual void viewAcctInfo() = 0;
        bool operator < (const Account & acc) const{
            return (balance < acc.balance);
        };
};

class Checking : public Account {
    private:
        double APY = 0.0002;
    public:
        Checking(double initialBalance, int customerID, int accountNum) {
            this->balance = initialBalance;
            this->customerID = customerID;
            this->acctNum = accountNum;
        }
        double getAcctBal() {
            return this->balance;
        }
        void setAcctBal(double newBal) {
            this->balance = newBal;
        }
        void deposit(double monies) {
            this->balance += monies;
        }
        void withdraw(double monies) {
            this->balance -= monies;
        }
        void processInterest() {
            this->balance += this->balance * APY;
        }
        double processPenalties() {
            return 0;
        }
        void viewAcctInfo() {
            cout << "Account Number: " << this->acctNum << endl;
            cout << "Customer ID: " << this->customerID << endl;
            cout << "Account Type: Checking" << endl;
            cout << "Balance: $" << this->balance << endl;
        }
};

class Savings : public Account {
    private:
        double APY = 0.0105;
        double withdrawlPenalty = 50;
    public:
        Savings(double initialBalance, int customerID, int accountNum) {
            this->balance = initialBalance;
            this->customerID = customerID;
            this->acctNum = accountNum;
        }
        double getAcctBal() {
            return this->balance;
        }
        void setAcctBal(double newBal) {
            this->balance = newBal;
        }
        void deposit(double monies) {
            this->balance += monies;
        }
        void withdraw(double monies) {
            this->balance -= monies + processPenalties();
        }
        void processInterest() {
            this->balance += this->balance * APY;
        }
        double processPenalties() {
            if (this->balance < 1000) {
                return withdrawlPenalty;
            } else {
                return 0;
            }
        }
        void viewAcctInfo() {
            cout << "Account Number: " << this->acctNum << endl;
            cout << "Customer ID: " << this->customerID << endl;
            cout << "Account Type: Savings" << endl;
            cout << "Balance: $" << this->balance << endl;
        }
};

class MoneyMarket : public Account {
    private:
        double APY = 0.0125;
        double withdrawlPenalty = 200; 
    public:
        MoneyMarket(double initialBalance, int customerID, int accountNum) {
            this->balance = initialBalance;
            this->customerID = customerID;
            this->acctNum = accountNum;
        }
        double getAcctBal() {
            return this->balance;
        }
        void setAcctBal(double newBal) {
            this->balance = newBal;
        }
        void deposit(double monies) {
            this->balance += monies;
        }
        void withdraw(double monies) {
            this->balance -= monies + processPenalties();
        }
        void processInterest() {
            this->balance += this->balance * APY;
        }
        double processPenalties() {
            if (this->balance < 10000) {
                return withdrawlPenalty;
            } else {
                return 0;
            }
        }
        void viewAcctInfo() {
            cout << "Account Number: " << this->acctNum << endl;
            cout << "Customer ID: " << this->customerID << endl;
            cout << "Account Type: Money Market" << endl;
            cout << "Balance: $" << this->balance << endl;
        }
};

class CD : public Account {
    private:
        double APY;
        double withdrawlPenalty;
        int term;
    public:
        CD(int type, double initialBalance, int customerID, int accountNum) {
            switch (type) {
                case 1:
                    APY = 0.025;
                    withdrawlPenalty = 0.1;
                    term = 3;
                case 2:
                    APY = 0.03;
                    withdrawlPenalty = 0.2;
                    term = 6;
                case 3:
                    APY = 0.05;
                    withdrawlPenalty = 0.5;
            }

            balance = initialBalance;
            this->customerID = customerID;
            this->acctNum = accountNum;
        }
        double getAcctBal() {
            return this->balance;
        }
        void setAcctBal(double newBal) {
            this->balance = newBal;
        }
        void deposit(double monies) {
            this->balance += monies;
        }
        void withdraw(double monies) {
            this->balance -= monies + processPenalties();
        }
        void processInterest() {
            this->balance += this->balance * APY;
        }
        double processPenalties() {
            if (this->balance < 10000) {
                return 200;
            } else {
                return 0;
            }
        }
        void viewAcctInfo() {
            cout << "Account Number: " << this->acctNum << endl;
            cout << "Customer ID: " << this->customerID << endl;
            cout << "Account Type: CD" << endl;
            cout << "Balance: $" << this->balance << endl;
        }
};

class Customer {
    private:
        string fName;
        string lName;
        string mailingAddr;
        string emailAddr;
        int customerID;
        vector<Account *> customerAccountList;
    public:
        Customer(string fName, string lName, string mailingAddr, string emailAddr, int id) {
            this->fName = fName;
            this->lName = lName;
            this->mailingAddr = mailingAddr;
            this->emailAddr = emailAddr;
            customerID = id;
        }
        void viewCustomerInfo() {
            cout << "\nCustomer ID: " << customerID
                 << "\nFirst name: " << fName
                 << "\nLast name: " << lName
                 << "\nMailing address: " << mailingAddr
                 << "\nEmail address: " << emailAddr << endl;
        }
        void createAccount(int type, double initialBalance, vector<Account *> & globalAccountList) {
            int cdType = 0;
            if (type > 3) {
                cdType = type - 4;
                type = 4;
            }

            switch (type) {
                case 1: {
                    Checking * newChecking = new Checking(initialBalance, customerID, globalAccountList.size() + 1);
                    globalAccountList.push_back(newChecking);
                    customerAccountList.push_back(newChecking);
                    break;
                }
                case 2: {
                    Savings * newSavings = new Savings(initialBalance, customerID, globalAccountList.size() + 1);
                    globalAccountList.push_back(newSavings);
                    customerAccountList.push_back(newSavings);
                    break;
                }
                case 3: {
                    MoneyMarket * newMMarket = new MoneyMarket(initialBalance, customerID, globalAccountList.size() + 1);
                    globalAccountList.push_back(newMMarket);
                    customerAccountList.push_back(newMMarket);
                    break;
                }
                case 4: {
                    CD * newCD = new CD(cdType, initialBalance, customerID, globalAccountList.size() + 1);
                    globalAccountList.push_back(newCD);
                    customerAccountList.push_back(newCD);
                    break;
                }
            }
        }
};