// MMultiFilter.cpp
// Ian Luna Quiroz

#include <iostream>
#include "MultiFilter.h"
using namespace std;

class OneLine : public MultiFilter {
    public:
        void doFilter(ifstream &in, ofstream &out) {
            char ch;
            while (in.get(ch)) {
                if (int(ch) == 10) {
                    out << ' ';
                } else {
                    out << ch;
                }
            }
        }
};

int main() {
    ifstream inFile("jfk.txt");
    if (!inFile) {
        cout << "Unable to open jfk.txt" << endl;
    }

    ofstream outFile("transformered.txt");
    if (!outFile) {
        cout << "Unable to open transformered.txt" << endl;
    }

    OneLine file;
    file.doFilter(inFile, outFile);

    return 0;
}