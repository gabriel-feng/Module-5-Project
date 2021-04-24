#include <iostream>
#include <string>
#include <iomanip>
#include "InvestmentAccount.h"
#include <stdexcept>
using namespace std;

int main() {
	string userInput = "y";	//Initializes variables
	double startingBalance;
	double monthlyDeposit;
	double interestRate;
	int yearsGrowth;

	while (userInput != "n") { //While user wants to try investment detials
		try
		{ //If user doesn't enter valid inputs
			string::size_type sz;
			cout << setw(60) << setfill('*') << "*" << endl;
			cout << setw(24) << "*" << setw(12) << " Data Input " << setw(24) << "*" << endl;
			cout << setfill(' ') << left << "Initial Investment Amount: " << flush;
			getline(cin, userInput);
			startingBalance = stod(userInput, &sz);
			if (startingBalance < 0.0) {
				throw runtime_error("");
			}
			cout << "Monthly Deposit: " << flush;
			getline(cin, userInput);
			monthlyDeposit = stod(userInput, &sz);
			if (monthlyDeposit < 0.0) {
				throw runtime_error("");
			}
			cout << "Annual Interest: " << flush;
			getline(cin, userInput);
			interestRate = stod(userInput, &sz);
			if (interestRate < 0.0) {
				throw runtime_error("");
			}
			cout << "Number of Years: " << flush;
			getline(cin, userInput);
			yearsGrowth = stoi(userInput, &sz);
			if (yearsGrowth < 0) {
				throw runtime_error("");
			}
			cout << setw(60) << setfill('*') << "*" << endl;
			cout << "If you'd like to make a correction, enter 'c'." << endl << "Otherwise, press enter to continue." << endl;
			getline(cin, userInput);
			if (userInput == "c") {
				system("CLS");
				continue;
			}
			system("CLS");
			InvestmentAccount* userAccount = new InvestmentAccount(startingBalance, monthlyDeposit, interestRate, yearsGrowth);

			userAccount->printInvestmentGrowth();
			cout << "Enter 'n' to quit. ";
			getline(cin, userInput);
			system("CLS");
		}
		catch (invalid_argument except)
		{ //Restart the while loop
			cout << "Invalid input. Press enter to continue. ";
			getline(cin, userInput);
			system("CLS");
			continue;
		}
		catch (runtime_error except) {
			cout << "Invalid input. Press enter to continue. ";
			getline(cin, userInput);
			system("CLS");
			continue;
		} 
	}

	return 0;
}