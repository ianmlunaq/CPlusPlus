// MultiFilter.cpp
// Ian Luna Quiroz

#include <iostream>
#include <fstream>
#include "MultiFilter.h"
using namespace std;

int main() {
    ifstream inFile("jfk.txt");
    if (!inFile) {
        cout << "Unable to open jfk.txt" << endl;
    }

    ofstream outFile("transformered.txt");
    if (!outFile) {
        cout << "Unable to open transformered.txt" << endl;
    }

    //Encrypt file(1);
    ToUpperCase file;
    //CarbonCopy file;
    file.doFilter(inFile, outFile);

    return 0;
}