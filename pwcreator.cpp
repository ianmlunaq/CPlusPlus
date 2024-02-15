// pwcreator.cpp
// Ian Luna Quiroz

#include <iostream>
#include <ostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <time.h>
using namespace std;

int main() {
    string fName, lName, dept, zip, randomFive = "", password = "";
    int randInt, upperBound = 9;

    srand(time(0));
    
    for (int i = 0; i < 5; i++) {
        randInt = rand() % upperBound+1;
        randomFive += to_string(randInt);
    }

    cout << "Enter your first name: ";
    cin >> fName;
    cout << "\nEnter your last name: ";
    cin >> lName;
    cout << "\nEnter your department name: ";
    cin >> dept;
    cout << "\nEnter your ZIP code: ";
    cin >> zip;

    password += zip.front();
    password += zip.back();
    password += char(toupper(dept[0]));
    password += char(tolower(dept[1]));
    password += char(toupper(fName[0]));
    password += char(tolower(lName[0]));
    password += randomFive;

    cout << "\nThis is your password: " << password << endl;

    return 0;
}