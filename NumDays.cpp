// NumDays.cpp
// Ian Luna Quiroz

#include <iostream>
using namespace std;

class NumDays {
    private:
        double hours, days;

    public:
        NumDays(double);
        NumDays operator+(const NumDays&);
        NumDays operator-(const NumDays&);
        NumDays operator++();
        NumDays operator++(int);
        NumDays operator--();
        NumDays operator--(int);
        void setHours(double);
        void setDays(double);
        double getHours();
        double getDays();

};

NumDays::NumDays(double hours) {
    this->hours = hours;
    days = hours / 8;
}

void NumDays::setHours(double hours) {
    this->hours = hours;
    days = hours / 8;
}

void NumDays::setDays(double days) {
    this->days = days;
    hours = days * 8;
}

double NumDays::getHours() {
    return hours;
}

double NumDays::getDays() {
    return days;
}

NumDays NumDays::operator++() {
    ++hours;
    days = hours / 8;

    return NumDays(hours);
}

NumDays NumDays::operator++(int) {
    NumDays og(hours);

    ++hours;
    days = hours / 8;

    return og;
}

NumDays NumDays::operator--() {
    --hours;
    days = hours / 8;

    return NumDays(hours);
}

NumDays NumDays::operator--(int) {
    NumDays og(hours);

    --hours;
    days = hours / 8;

    return og;
}

NumDays NumDays::operator+(const NumDays &right) {
    NumDays temp(0);

    temp.setHours(hours + right.hours);

    return temp;
}

NumDays NumDays::operator-(const NumDays &right) {
    NumDays temp(0);

    temp.setHours(hours - right.hours);

    return temp;
}

int main() {
    /*NumDays hrs(12);
    NumDays hrs2(12);

    cout << hrs.getHours() << endl;
    --hrs;
    cout << hrs.getHours() << endl;

    NumDays hrs3 = hrs + hrs2;
    cout << hrs3.getHours() << endl;

    NumDays hrs4 = hrs3 - hrs;
    cout << hrs4.getHours() << endl;*/

    double hrsWorked;

    cout << "How many hours have you worked? ";
    cin >> hrsWorked;
    NumDays hrs(hrsWorked);

    cout << "You have worked " << hrs.getDays() << " eight hour day(s)." << endl;

    return 0;
}