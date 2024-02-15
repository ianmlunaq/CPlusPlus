// Lab 4: Classes
// EncryptableString.cpp
// Ian Luna Quiroz

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

class EncryptableString : public string {
    private:
        string encryptable;
    public:
        EncryptableString(string);
        void encrypt();
        void print();
};

EncryptableString::EncryptableString(string word) {
    encryptable = word;
}

void EncryptableString::encrypt() {
    for(int i = 0; i < encryptable.length(); i++) {
        if(tolower(encryptable[i]) == 'z') {
            if(islower(encryptable[i])) {
                encryptable[i] = 'a';
            } else {
                encryptable[i] = 'A';
            }
        } else {
            encryptable[i] = char(encryptable[i] + 1);
        }
    }
}

void EncryptableString::print() {
    cout << encryptable << endl;
}