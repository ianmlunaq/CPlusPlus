// minicount.cpp
// Ian Luna Quiroz

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int loadWithRandomAndSaveToFile(int arr[], int size, int upperBound, ofstream &file) {
    if (size == 0) {
        return 0;
    } else {
        size--;
        arr[size] = rand() % upperBound + 1;
        file << arr[size] << endl;
        return loadWithRandomAndSaveToFile(arr, size, upperBound, file);
    }
}

int evenOut(const int arr[], int size) {
    if (size == 0) {
        return 0;
    } else {
        size--;
        if (arr[size] % 2 == 0) {
            return 1 + evenOut(arr, size);
        } else {
            return evenOut(arr, size);
        }
    }
}

unsigned long long int sevenFact(const int arr[], int size) {
    if (size == 0) {
        return 1;
    } else {
        size--;
        if (arr[size] % 10 == 7) {
            return 7 * sevenFact(arr, size);
        } else {
            return sevenFact(arr, size);
        }
    }
}

int main() {
    int sizeOfMil = 1000, upperBound = 100, evenCount = 0;
    unsigned long long int seven = 0;
    int mil[sizeOfMil];

    ofstream outFile("array.txt");
    if (!outFile) {
        cout << "Unable to to open file.";
    }

    srand(time(0));
    loadWithRandomAndSaveToFile(mil, sizeOfMil, upperBound, outFile);

    evenCount = evenOut(mil, sizeOfMil);
    cout << "Number of even numbers: " << evenCount << endl;

    seven = sevenFact(mil, sizeOfMil);
    cout << "7 to the power of the amount of numbers ending in 7: " << seven << endl;

    return 0;
}