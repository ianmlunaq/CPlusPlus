// Lab 4: Classes
// doy.cpp
// Ian Luna Quiroz

#include <iostream>
#include <iomanip>
using namespace std;

class DayOfYear {
    private:
        static string monthAndDay;
        int yearNum;

    public:
        DayOfYear(int);
        DayOfYear(string, int);
        void print();
        DayOfYear operator++();
        DayOfYear operator++(int);
        DayOfYear operator--();
        DayOfYear operator--(int);
};

string DayOfYear::monthAndDay = "";

DayOfYear::DayOfYear(int yearNum) {
    this->yearNum = yearNum;
    if(yearNum > 365 or yearNum < 1) {
        cout << "Not a valid date." << endl;
    } else {
        if(yearNum < 32) {
            monthAndDay = "January ";
            monthAndDay += to_string(yearNum);
        } else if(yearNum > 31 and yearNum < 60) {
            monthAndDay = "February ";
            monthAndDay += to_string(yearNum - 31);
        } else if(yearNum > 59 and yearNum < 91) {
            monthAndDay = "March ";
            monthAndDay += to_string(yearNum - 59);
        } else if(yearNum > 90 and yearNum < 121) {
            monthAndDay = "April ";
            monthAndDay += to_string(yearNum - 90);
        } else if(yearNum > 120 and yearNum < 152) {
            monthAndDay = "May ";
            monthAndDay += to_string(yearNum - 120);
        } else if(yearNum > 151 and yearNum < 182) {
            monthAndDay = "June ";
            monthAndDay += to_string(yearNum - 151);
        } else if(yearNum > 181 and yearNum < 213) {
            monthAndDay = "July ";
            monthAndDay += to_string(yearNum - 181);
        } else if(yearNum > 212 and yearNum < 244) {
            monthAndDay = "August ";
            monthAndDay += to_string(yearNum - 212);
        } else if(yearNum > 243 and yearNum < 274) {
            monthAndDay = "September ";
            monthAndDay += to_string(yearNum - 243);
        } else if(yearNum > 273 and yearNum < 305) {
            monthAndDay = "October ";
            monthAndDay += to_string(yearNum - 273);
        } else if(yearNum > 304 and yearNum < 335) {
            monthAndDay = "November ";
            monthAndDay += to_string(yearNum - 304);
        } else {
            monthAndDay = "December ";
            monthAndDay += to_string(yearNum - 334);
        }
    }
}

DayOfYear::DayOfYear(string month, int dayOfMonth) {
    bool longMonth;

    if(month == "January") {
        yearNum = 0;
        longMonth = true;
    } else if(month == "February") {
        yearNum = 31;
        longMonth = false;
    } else if(month == "March") {
        yearNum = 59;
        longMonth = true;
    } else if(month == "April") {
        yearNum = 90;
        longMonth = false;
    } else if(month == "May") {
        yearNum = 120;
        longMonth = true;
    } else if(month == "June") {
        yearNum = 151;
        longMonth = false;
    } else if(month == "July") {
        yearNum = 181;
        longMonth = true;
    } else if(month == "August") {
        yearNum = 212;
        longMonth = true;
    } else if(month == "September") {
        yearNum = 243;
        longMonth = false;
    } else if(month == "October") {
        yearNum = 273;
        longMonth = true;
    } else if(month == "November") {
        yearNum = 304;
        longMonth = false;
    } else if(month == "December") {
        yearNum = 334;
        longMonth = true;
    } else {
        cout << "Not a valid month name" << endl;
    }

    if(longMonth) {
        if(dayOfMonth > 31 or dayOfMonth < 1) {
            cout << "Not a valid day of the month." << endl;
            yearNum = 0;
            monthAndDay = "";
        } else {
            yearNum += dayOfMonth;
        }
    } else {
        if(month == "February") {
            if(dayOfMonth > 28 or dayOfMonth < 1) {
                cout << "Not a valid day of the month." << endl;
                yearNum = 0;
                monthAndDay = "";
            } else {
                yearNum += dayOfMonth;
            }
        } else {
            if(dayOfMonth > 30 or dayOfMonth < 1) {
                cout << "Not a valid day of the month." << endl;
                yearNum = 0;
                monthAndDay = "";
            } else {
                yearNum += dayOfMonth;
            }
        }

    }
}

void DayOfYear::print() {
    if(yearNum > 365 or yearNum < 1) {
        cout << "Not a valid date." << endl;
    } else {
        if(yearNum < 32 and yearNum > 0) {
            monthAndDay = "January ";
            monthAndDay += to_string(yearNum);
        } else if(yearNum > 31 and yearNum < 60) {
            monthAndDay = "February ";
            monthAndDay += to_string(yearNum - 31);
        } else if(yearNum > 59 and yearNum < 91) {
            monthAndDay = "March ";
            monthAndDay += to_string(yearNum - 59);
        } else if(yearNum > 90 and yearNum < 121) {
            monthAndDay = "April ";
            monthAndDay += to_string(yearNum - 90);
        } else if(yearNum > 120 and yearNum < 152) {
            monthAndDay = "May ";
            monthAndDay += to_string(yearNum - 120);
        } else if(yearNum > 151 and yearNum < 182) {
            monthAndDay = "June ";
            monthAndDay += to_string(yearNum - 151);
        } else if(yearNum > 181 and yearNum < 213) {
            monthAndDay = "July ";
            monthAndDay += to_string(yearNum - 181);
        } else if(yearNum > 212 and yearNum < 244) {
            monthAndDay = "August ";
            monthAndDay += to_string(yearNum - 212);
        } else if(yearNum > 243 and yearNum < 274) {
            monthAndDay = "September ";
            monthAndDay += to_string(yearNum - 243);
        } else if(yearNum > 273 and yearNum < 305) {
            monthAndDay = "October ";
            monthAndDay += to_string(yearNum - 273);
        } else if(yearNum > 304 and yearNum < 335) {
            monthAndDay = "November ";
            monthAndDay += to_string(yearNum - 304);
        } else {
            monthAndDay = "December ";
            monthAndDay += to_string(yearNum - 334);
        }
    }

    cout << monthAndDay << endl;
}

DayOfYear DayOfYear::operator++() {
    ++yearNum;

    if(yearNum > 365) {
        yearNum = 1;
    }

    return DayOfYear(yearNum);
}

DayOfYear DayOfYear::operator++(int) {
    DayOfYear og(yearNum);

    ++yearNum;

    if(yearNum > 365) {
        yearNum = 1;
    }

    return og;
}

DayOfYear DayOfYear::operator--() {
    --yearNum;

    if(yearNum < 1) {
        yearNum = 365;
    }

    return DayOfYear(yearNum);
}

DayOfYear DayOfYear::operator--(int) {
    DayOfYear og(yearNum);

    --yearNum;

    if(yearNum < 1) {
        yearNum = 365;
    }

    return og;
}

int main() {
    DayOfYear birthday(216);
    birthday.print();
    birthday++;
    birthday.print();
    --birthday;
    birthday.print();

    DayOfYear birthdayString("February", 29);
    birthdayString.print();

    return 0;
}