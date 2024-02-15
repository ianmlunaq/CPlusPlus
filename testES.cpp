// Lab 4: Classes
// testES.cpp
// Ian Luna Quiroz

#include <iostream>
#include <iomanip>
#include "EncryptableString.cpp"
using namespace std;

int main() {
    string uno, dos;
    cout << "Enter string one: ";
    cin >> uno;
    cout << "Enter string two: ";
    cin >> dos;
    EncryptableString ichi(uno);
    EncryptableString ni(dos);
    ichi.encrypt();
    ni.encrypt();
    ichi.print();
    ni.print();
    
    
}