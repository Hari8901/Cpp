#include "Account.h"

Account::Account() { account_number = 0; balance = 0.0; }

void Account::CreateAccount() {
	cout << "\nEnter account details" << endl << endl;
	cout << "Enter account holder name: ";
	cin.ignore();
	getline(cin, account_holder);

	cout << "Enter account number: ";
	cin >> account_number;

	cout << "Enter the opening balance: ";
	cin >> balance;

	cout << "Enter the type of account (saving/current): ";
	cin >> acc_type;
}

void Account::displayAccountDetails() const{
	cout << "\nAccount Number: " << account_number
		<< "\nHolder Name   : " << account_holder
		<< "\nBalance       : INR " << fixed << setprecision(2) << balance
		<< "\nAccount Type  : " << acc_type<<"\n";
}

void Account::deposit() {
	long amount;
	cout << "Enter the amount to deposit: ";
	cin >> amount;
	if (amount <= 0)
		throw invalid_argument("Deposit amount must be positive");

	balance += amount;
	cout << "INR " << amount << " credited successfully.\n";
}

long Account::getAccountNumber() const { return account_number; }
void Account::setAccountNumber(long acc_num) { account_number = acc_num; }

double Account::getBalance() const { return balance; }
void Account::setBalance(double b) { balance = b; }

string Account::getAccountType() const { return acc_type; }
void Account::setAccountType(const string& type) { acc_type = type; }

Account::~Account() {
	cout << "Account destructor\n";
}
