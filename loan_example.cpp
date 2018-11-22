#include <iostream>
#include <stdlib.h>
using namespace std;

const int expected_args = 3;


int processInputs(const int argc, const char* const argv[], int& loanAmount, int& payment, int& interestRate){
		if (argc != expected_args+1){
			if(argc <= expected_args){
				return -1;
			}
			else{
				return 1;
			}
		}

		loanAmount = atof(argv[1]);
		payment = atof(argv[2]);
		interestRate = atof(argv[3]);

		return 0;
}


void printResults(const float loanAmount, const float payment, const float interestRate, const int numofMonths){
	cout << "Total amount of loan: $" << loanAmount << endl << "Repayment amount: $" << payment << endl << "Interest rate: " << interestRate << "%" << endl
	<< "Time to repay loan: " << numofMonths/12 <<  " years and " << numofMonths%12  << "months" << endl;

}

int loan(const float loanAmount, const float payment, const float interestRate){
	float monthinterest = (interestRate/12.0)/100.0;
	float amoutOwe = loanAmount;

	if(loanAmount <= 0 || interestRate < 0 || (payment <= amoutOwe*interestRate)){
		return -1;
	}

	if(payment <= amoutOwe*interestRate){
		return -1;
	}
	int numofMonths = 0;
	while(amoutOwe > 0){
		amoutOwe = amoutOwe + amoutOwe*monthinterest - payment;
		++numofMonths;
	}

	return numofMonths;
}
int main(const int argc, const char* const argv[]){
	int rc = 0;
	float loanAmount = -1;
	float payment = -1;
	float interestRate = -1;
	

	rc = processInputs(argc, argv, loanAmount, payment, interestRate);

	if(rc < 0){
		cerr << "Error" << endl;
		return rc;
	}
	else if (rc > 0){
		cerr << "Warning" << endl;
	}

	numofMonths = loan(loanAmount, payment, interestRate);

	if (numofMonths < 0 ){
		cerr << "Error: bad parameters" << endl;
		return -1;
	}

	printResults(loanAmount, payment, interestRate, numofMonths);

	return rc;
}