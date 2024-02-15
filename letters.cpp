// letters.cpp
// The letter e is the most frequently used letter in English prose, and the letter z is the least frequently used.
// To test this theory, write a program that will take a text file and print, for each letter of the English alphabet,
// the number of times the letter appears in the file.
// Hint: Use an integer array of size 128, and use the ASCII values of letters to index into the array to store and retrieve counts for the letters.

// Ian Luna Quiroz

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int ARRAY_SIZE = 128;
    const int A_INDEX = 65;
    const int z_INDEX = 122;
    int count[ARRAY_SIZE] = { }; // Initialize array with zeroes
    char ch;
    int chVal;

    ifstream huxley("thuxley.txt");

    if (!huxley) {
        cout << "File doesn't exist" << endl;
        return 1;
    }

    while (huxley) {
        huxley.get(ch);
        chVal = int(ch);
        if (chVal > A_INDEX) {
            count[chVal]++;
        }
    }
    
    for (int i = A_INDEX; i < z_INDEX+1; i++) {
        if (i > 90 and i < 97) {
            // Makes sure special characters aren't included in list
        } else {
            cout << char(i) << ": " << count[i] << endl;
        }
    }

    huxley.close();

    return 0;
}