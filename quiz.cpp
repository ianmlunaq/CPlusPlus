// Chapter 10 Quiz
// Ian Luna Quiroz

#include <iostream>
#include <iomanip>
using namespace std;

int printOut(double *ptr, int size) {
    for(int k = 0; k < size; k++) {
        cout << *(ptr+k) << endl;
    }

    return 0;
}

int main() {
    double *arrr = NULL;
    int arrrSize;

    cout << "Enter array size: ";
    cin >> arrrSize;

    arrr = new double[arrrSize];

    for(int i = 0; i < arrrSize; i++) {
        cout << "Enter value number " << i+1 << ": " ;
        cin >> *(arrr+i);
    }

    printOut(arrr, arrrSize);

    delete [] arrr;
    arrr = NULL;
    return 0;
}