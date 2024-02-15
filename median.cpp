// Median

// Ian Luna Quiroz

#include <iostream>
#include <iomanip>
using namespace std;

int findMedian(int size, int ptr[]) {
    return *(ptr+(size/2));
}

int main() {
    int arrSize = 11;
    int arr[] = {1, 3, 5, 7, 11, 15, 17, 21, 32, 34, 42};
    
    int median = findMedian(arrSize, arr);
    cout << median;
    return 0;
}