#include <iostream>
#include <iomanip>
#include "InvestmentAccount.h"
using namespace std;

InvestmentAccount::InvestmentAccount(double m_initialBalance, double m_monthlyDeposit, double m_interestRate, int m_yearsGrowth) {
	this->m_initialBalance = m_initialBalance;
	this->m_monthlyDeposit = m_monthlyDeposit;
	this->m_interestRate = m_interestRate;
	this->m_yearsGrowth = m_yearsGrowth;
	this->m_currBalance = this->m_initialBalance;
	this->m_yearEarnedInterest = 0.00;
}

void InvestmentAccount::calculateYearlyInvestmentGrowth() {//Calculates investment by year according to monthly deposit
	m_yearEarnedInterest = 0.00;
	if (m_monthlyDeposit > 0.00000001) {
		for (int i = 0; i < 12; i++) {
			m_currBalance += m_monthlyDeposit;
			m_yearEarnedInterest += (m_currBalance) * ((m_interestRate / 100.00) / 12.00);
			m_currBalance += (m_currBalance) * ((m_interestRate / 100.00) / 12.00);
		}
	}
	else {
		m_yearEarnedInterest += (m_currBalance) * (m_interestRate / 100.00);
		m_currBalance += (m_currBalance) * (m_interestRate / 100.00);
	}
}

void InvestmentAccount::printInvestmentGrowth() { //Prints investment details
	int placeValue;
	if (m_monthlyDeposit > 0.00000001) {
		cout << "   Balance and Interest With Additional Monthly Deposits   " << endl;
	}
	else {
		cout << "  Balance and Interest Without Additional Monthly Deposits " << endl;
	}

	cout << setw(60) << setfill('=') << "=" << endl;
	cout << right << setfill(' ') << setw(5) << "Year";
	cout << setw(22) << "Year End Balance";
	cout << setw(30) << "Year End Earned Interest" << endl;
	cout << setw(60) << setfill('-') << "-" << endl << endl;
	cout << setfill(' ') << fixed << setprecision(2);
	for (int i = 1; i <= m_yearsGrowth; i++) {
		calculateYearlyInvestmentGrowth();
		placeValue = 0;
		cout << setw(5) << i;
		while (m_currBalance / (pow(10, placeValue)) > 1.0000001) {
			placeValue++;
		}
		cout << setw(19 - static_cast<__int64>(placeValue)) << "$" << m_currBalance;
		placeValue = 0;
		while (m_yearEarnedInterest / (pow(10, placeValue)) > 1.0000001) {
			placeValue++;
		}
		cout << setw(27 - static_cast<__int64>(placeValue)) << "$" << m_yearEarnedInterest << endl;
	}
	cout << setw(60) << setfill('-') << "-" << endl << endl;
}