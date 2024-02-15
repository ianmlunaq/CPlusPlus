// This program uses hours, pay rate, state tax and fed tax to determine gross
// and net pay.

// Ian Luna Quiroz

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Fill in the code to define payfile as an input file
	ifstream payfile;

	float gross;
	float net;
	float hours = 2.5;
	float payRate;
	float stateTax;
	float fedTax;

	cout << fixed << setprecision(2) << showpoint;

	// Fill in the code to open payfile and attach it to the physical file
	// named payroll.dat
	payfile.open("payroll.dat");

	// Fill in code to write a conditional statement to check if payfile
	// does not exist.
	if (!payfile) {
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}

	cout << "Payrate      Hours      Gross Pay	Net Pay"
	     << endl << endl;

	// Fill in code to prime the read for the payfile file.
	payfile >> payRate;

	// Fill in code to write a loop condition to run while payfile has more
	// data to process.
	while (payfile) { 
		payfile >> stateTax >> fedTax;

		gross = payRate * hours;

		net = gross - (gross * stateTax) - (gross * fedTax);

		cout << payRate << setw(12) << hours << setw(12) << gross
			 << setw(12) << net << endl;

		payfile >> payRate;
	}
	payfile.close();

	return 0;
}