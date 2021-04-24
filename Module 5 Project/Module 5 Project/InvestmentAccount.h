#pragma once
class InvestmentAccount {
public:
	InvestmentAccount(double m_initialBalance = 0.00, double m_monthlyDeposit = 0.00, double m_interestRate = 0.00, int m_yearsGrowth = 0);
	void setInitialBalance(double t_initialBalance) { m_initialBalance = t_initialBalance; }
	void setMonthlyDeposit(double t_monthlyDeposit) { m_monthlyDeposit = t_monthlyDeposit; }
	void setInterestRate(double t_interestRate) { m_interestRate = t_interestRate; }
	void setYearsGrowth(int t_yearsGrowth) { m_yearsGrowth = t_yearsGrowth; }
	double getInitialBalance() const { return m_initialBalance; }
	double getMonthlyDeposit() const { return m_monthlyDeposit; }
	double getInterestRate() const { return m_interestRate; }
	double getCurrBalance() const { return m_currBalance; }
	int getYearsGrowth() const { return m_yearsGrowth; }
	void printInvestmentGrowth();
	void calculateYearlyInvestmentGrowth();

protected:
	double m_currBalance;
	double m_yearEarnedInterest;
	double m_initialBalance;
	double m_monthlyDeposit;
	double m_interestRate;
	int m_yearsGrowth;
};