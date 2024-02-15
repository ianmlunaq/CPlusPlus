// DivSales.cpp
// Ian Luna Quiroz

#include <iostream>
using namespace std;

class DivSales {
    private:
        static int grandTotalSales;
        double quarterSales[4];

    public:
        void enterSales(double, double, double, double);
        double getQuarterSales(int);
        double getGrandTotalSales();

};

int DivSales::grandTotalSales = 0;

void DivSales::enterSales(double Q1, double Q2, double Q3, double Q4) {
    quarterSales[0] = Q1;
    quarterSales[1] = Q2;
    quarterSales[2] = Q3;
    quarterSales[3] = Q4;
    grandTotalSales += Q1 + Q2 + Q3 + Q4;
}

double DivSales::getQuarterSales(int quarter) {
    if(quarter > -1 or quarter < 4) {
        return quarterSales[quarter];
    } else {
        return -1;
    }
}

double DivSales::getGrandTotalSales() {
    return grandTotalSales;
}