// cstrtester.cpp
// Ian Luna Quiroz

#include <cctype>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char sentence[150];
    char notAlNum[150];

    cout << "Enter a minimum of 10 characters and a maximum of 150: ";

    while (strlen(sentence) < 10) {
        fgets(sentence, 150, stdin);
    }

    cout << "This is your sentence: " << sentence << endl;

    for (int i = 0, c = -1; i < strlen(sentence)-1; i++) {
        if (!isalnum(sentence[i])) {
            c++;
            notAlNum[c] = sentence[i];
        }
    }
    
    cout << "\nYour sentence contained " << strlen(notAlNum) << " non-alphanumeric characters" << endl;
    cout << "In order: " << notAlNum << endl;
    cout << "In reverse order: ";
    for (int i = strlen(notAlNum); i > -1; i--) {
        cout << notAlNum[i];
    }

    cout << endl;

    return 0;
}


