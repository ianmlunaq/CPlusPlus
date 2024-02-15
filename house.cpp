// Chapter 11 Quiz
// Ian Luna Quiroz

#include <iostream>
using namespace std;

class HouseAddress {
    private:
        string street, city;
    public:
        HouseAddress(string, string);
        string getAddress();
};

HouseAddress::HouseAddress(string street, string city) {
    this->street = street;
    this->city = city;
}

string HouseAddress::getAddress() {
    return street + ", " + city;
}

class House {
    private:
        HouseAddress address;
        string color;

    public:
        House(string, string, string);
        void printInfo();
};

House::House(string street, string city, string color) : address(street, city) {
    this->color = color;
}

void House::printInfo() {
    cout << "Color: " << color << endl;
    cout << "Address: " << address.getAddress();
}

int main() {
    House casa("23 Main St", "York", "Red");
    casa.printInfo();

    return 0;
}