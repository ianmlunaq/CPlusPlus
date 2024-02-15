// BCheckString.cpp
// Ian Luna Quiroz
// Nov 21, 2023
// Using Clang

#include <iostream>
#include <string>
using namespace std;

class BCheckString : public string {
    public:
        BCheckString(string s) : string(s) { } // Constructor that receives a string object passed by value and passes it on to the base class constructor.

        class BoundsException { };

        char operator[](int k) {
            if (k < 0 or k >= length())
                throw BoundsException();
            return at(k);
        }
};

int main() {
    BCheckString hola("hello");

    try {
        for (int i = 0; i < hola.length() + 1; i++) {
            cout << hola[i] << endl;
        }
    } catch (BCheckString::BoundsException) {
        cout << "You are out of bounds." << endl;
    }

    return 0;
}