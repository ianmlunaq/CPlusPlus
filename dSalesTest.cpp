// NumDays.cpp
// Ian Luna Quiroz

#include <iostream>
#include "DivSales.cpp"
using namespace std;

int main() {
    DivSales divisions[6];
    double quarterSalesTempHold[4];

    /*divisions[0].enterSales(200, 324, 220, 400);
    divisions[1].enterSales(100, 300, 240, 410);
    divisions[2].enterSales(123, 475, 250, 430);
    divisions[3].enterSales(154, 354, 256, 440);
    divisions[4].enterSales(175, 345, 267, 460);
    divisions[5].enterSales(190, 300, 257, 470);*/

    for(int i = 0; i < 6; i++) {
        cout << "\nEnter quarterly sales for division " << i + 1 << endl;
        for(int j = 0; j < 4; j++) {
            cout << "\nQ" << j + 1 << ": ";
            cin >> quarterSalesTempHold[j];
        }
        divisions[i].enterSales(quarterSalesTempHold[0], quarterSalesTempHold[1], quarterSalesTempHold[2], quarterSalesTempHold[3]);
    }

    cout << endl;

    for(int i = 0; i < 6; i++) {
        cout << "Division " << i+1 << ": ";
        for(int j = 0; j < 4; j++) {
            cout << 'Q' << j+1 << ":" << divisions[i].getQuarterSales(j) << " ";
        }
        cout << endl;
    }
    cout << "\nTotal corporate sales for the year: " << divisions[0].getGrandTotalSales() << endl;

    return 0;
}