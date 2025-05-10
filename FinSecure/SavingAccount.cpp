#include "SavingAccount.h"

SavingAccount::SavingAccount() : interest_rate(0.0) {}

void SavingAccount::CreateAccount() {
    Account::CreateAccount();
    do {
        cout << "Enter the interest rate for the saving account: ";
        cin >> interest_rate;
        if (interest_rate < 0) {
            cout << "Interest rate cannot be negative.\n";
        }
    } while (interest_rate < 0);
}

void SavingAccount::withdraw() {
    double amount;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;
    if (amount > balance) {
        throw runtime_error("Insufficient funds.");
    }
    balance -= amount;
    cout << "INR " << amount << " debited. Updated balance: INR " << fixed << setprecision(2) << balance << "\n";
}

void SavingAccount::displayAccountDetails() const {
    Account::displayAccountDetails();
       cout << "\nInterest Rate : " << interest_rate << "%\n";
}

SavingAccount::~SavingAccount() {
    cout << "SavingAccount destructor\n";
}