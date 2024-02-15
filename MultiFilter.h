// MultiFilter.h
// Ian Luna Quiroz

#include <fstream>
using namespace std;

class MultiFilter {
    public: virtual void doFilter(ifstream &in, ofstream &out) = 0;
};

class Encrypt : public MultiFilter {
    private:
        int key;

    public:
        Encrypt(int key) {
            this->key = key;
        }

        void doFilter(ifstream &in, ofstream &out) {
            char ch;
            while (in.get(ch)) {
                out << transform(ch);
            }
        }

        char transform(char ch) {
            return ch + key;
        }
};

class ToUpperCase : public MultiFilter {
    public:
        void doFilter(ifstream &in, ofstream &out) {
            char ch;
            while (in.get(ch)) {
                out << transform(ch);
            }
        }

        char transform(char ch) {
            return toupper(ch); // ToDo
        }

};

class CarbonCopy : public MultiFilter {
    public:
        void doFilter(ifstream &in, ofstream &out) {
            char ch;
            while (in.get(ch)) {
                out << ch;
            }
        }
};