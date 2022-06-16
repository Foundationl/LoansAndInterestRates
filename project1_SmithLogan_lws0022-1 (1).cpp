//============================================================================
// Name        : project1_SmithLogan_lws0022.cpp
// Author      : Logan Smith
// Au username :lws0022
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// colaboration: worked with Christian Chapman and Trey Wood on setting up eclipse, as well as getting MinGW working properly. We also talked about the use of loops.
// compile     : g++ project1_SmithLogan_lws0022.cpp -o project1_SmithLogan_lws0022.out
//run          : ./project1_SmithLogan_lws0022.out
//============================================================================

#include <iostream>
using namespace std;

int main() {
		// VARIABLE INITALIZATION
	double interestRate;
	double monthlyPayment;
	double loanAmount;
	double interestRateC;
	int currentMonth = 0;
	double principal;
	double interestTotal;

	//CURRENCY FORMATTING
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	// USER INPUT
	// NOTE: For valid input, the loan, interest, and monthly payment must
	// be positive. The monthly payment must also be large enough to
	// terminate the loan.
	cout << "\nLoan Amount: ";
	cin >> loanAmount;
	static double loan = loanAmount;

	cout << "Interest Rate (% per year) : ";
	cin >> interestRate;

	// GET PROPER INTEREST RATES FOR CALCULATIONS
		interestRate /=12;
		interestRateC = interestRate / 100;
		cout << "Monthly Payments: ";
		cin >> monthlyPayment;

		cout << endl;

		// AMORTIZATION TABLE
		cout << "*****************************************************************\n"
			 << "\tAmortization Table\n"
			 << "*****************************************************************\n"
			 << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

		// LOOP TO FILL TABLE
		while (loanAmount > 0) {

			if  (currentMonth == 0) {
				cout << currentMonth++ <<  "\t$"   << loanAmount << "\t" << "N/A" << "\t" << "N/A" << "\t" << "N/A" << "\t\t" << "N/A\n";
				if (loan < 1000)
						cout << "\t"; // FORMATTING MAGIC

							}


			if (currentMonth >= 1){




				if (loanAmount * (1 + interestRateC) < monthlyPayment){
				monthlyPayment = loanAmount *(1 +interestRateC);
				cout << currentMonth++ <<  "\t$"   << ("0") << "\t\t$" << monthlyPayment << "\t" << interestRate  << "\t$" << (interestRateC * loanAmount) << "\t\t$" << (monthlyPayment -(interestRateC * loanAmount)) << "\n";
				interestTotal += (loanAmount * interestRateC);

				cout << "****************************************************************\n";
					cout << "\nIt takes " << -- currentMonth <<  " months to pay off "
						 << "the loan.\n"
						 << "Total interest paid is: $" << interestTotal;
					cout << endl << endl; return 0;
				}


				if (loanAmount *(1 + interestRateC) >= monthlyPayment){
				principal = (monthlyPayment - (loanAmount*interestRateC));

				cout<< currentMonth++ <<"\t$" << loanAmount - principal;
				if (loanAmount - principal <= 1000){
					cout << "\t";
				}

				cout << "\t$" << monthlyPayment << "\t" << interestRate  << "\t$" << (interestRateC * loanAmount) << "\t\t$" << principal << "\t" << "\n";
					interestTotal += (loanAmount * interestRateC);


					loanAmount = (loanAmount - principal);

				}


			}

		}












}
