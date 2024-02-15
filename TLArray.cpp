// TLArray.cpp
// Ian Luna Quiroz
// Nov 21, 2023
// Using Clang

#include <iostream>
#include <memory>
using namespace std;

template<class T>
class TLArray {
    private:
        unique_ptr<T[]> powerPointer; // A smart pointer of type T
        int size;

    public:
        class OutOfRangeException {};

        TLArray(int tamaño) { // A constructor that allocates an array based on the size entered.
            size = tamaño;
            powerPointer = make_unique<T[]>(tamaño);
            for (int i = 0; i < size; i++)
                powerPointer[i] = T();
        }

        T &operator[](int sandwich) { // Function that allows the user to fill in the array based on the size. Throws an exception if you go out of range. 
            if (sandwich < 0 or sandwich >= size)
                throw OutOfRangeException();
            return powerPointer[sandwich];
        }

        void print() { // Function used to display the elements of the array.
            for (int i = 0; i < size; i++)
                cout << powerPointer[i] << " ";
            cout << endl;
        }

        void sortAndPrint() { // Function that sorts the array and displays the sorted elements.
            bool swapCheck = true; // I reused some code from Lab 2 to sort the array.
            T temp;
            while(swapCheck) {
                swapCheck = false;
                for(int j = 0; j < size-1; j++) {
                    if(powerPointer[j] > powerPointer[j+1]) {
                        temp = powerPointer[j];
                        powerPointer[j] = powerPointer[j+1];
                        powerPointer[j+1] = temp;
                        swapCheck = true;
                    }
                }
            }

            print();
        }

        ~TLArray() {
            powerPointer.reset(); // Apparently, smart pointers self-destruct when they go out of scope,
        }                         // but I included this since we were explicitly asked to include a destructor.
};

int main() {
    const int SIZE = 7;
    TLArray<double> dblArr(SIZE);
    TLArray<int> intArr(SIZE);
    
    for (int i = 0; i < SIZE; i++) {
        intArr[i] = i + 65;
        dblArr[i] = i + 77.35;
    }

    cout << "intArr: ";
    intArr.print();
    cout << "dblArr: ";
    dblArr.print();

    intArr[1] = 88;
    dblArr[6] = 2.5;
    cout << endl;

    cout << "Unordered intArr: ";
    intArr.print();
    cout << "Unordered dblArr: ";
    dblArr.print();

    cout << endl;

    cout << "Ordered intArr: ";
    intArr.sortAndPrint();
    cout << "Ordered dblArr: ";
    dblArr.sortAndPrint();

    return 0;
}