//Lab 2: Sorting
// Ian Luna Quiroz
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int largeArray[50];
    int upperBound = 100;
    int arraySize = sizeof(largeArray) / sizeof(int);   // I found this way of getting an array's length on the internet.
    int temp;
    bool swapCheck = true;

    // When trying to sort an "empty" array, the program outputs a bunch of numbers that I did not expect.
    // I expected it to produce an error or to output zeroes.

    // This inserts random values into the array.
    // When sorting a completely unsorted array, we get the expected sorted array as the output.
    /*for(int i = 0; i < 100; i++) {
        largeArray[i] = rand() % upperBound;
    }*/

    // This makes a sorted array.
    // When sorting an already sorted array, we get the expected sorted array as the output.
    /*for(int i = 0; i < arraySize; i++) {
        largeArray[i] = i;
    }*/

    // This makes a partially sorted array.
    // When sorting a partially sorted array, we get the expected sorted array as the output.
    /*for(int i = 0; i < arraySize; i++) {
        if(i > arraySize / 2) {
            largeArray[i] = i;
        } else {
            largeArray[i] = rand() % upperBound;
        }
    }*/
    
    // Print unsorted largeArray
    cout << "Unsorted array:\n";
    for(int i = 0; i < arraySize; i++) {
        cout << largeArray[i] << " ";
    }
    cout << endl << endl;

    // Bubble sort algorithm
    while(swapCheck) {
        swapCheck = false;
        for(int j = 0; j < arraySize-1; j++) {
            if(largeArray[j] > largeArray[j+1]) {
                temp = largeArray[j];
                largeArray[j] = largeArray[j+1];
                largeArray[j+1] = temp;
                swapCheck = true;
            }
        }
    }

    // Print sorted largeArray
    cout << "Sorted array:\n";
    for(int i = 0; i < arraySize; i++) {
        cout << largeArray[i] << " ";
    }
    cout << endl;

    return 0; 
}