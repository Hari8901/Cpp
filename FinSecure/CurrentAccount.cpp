#include "CurrentAccount.h"

CurrentAccount::CurrentAccount() : overDraftLimit(0.0) {}

void CurrentAccount::CreateAccount() {
    Account::CreateAccount();
    do {
        cout << "Enter the overdraft limit: ";
        cin >> overDraftLimit;
        if (overDraftLimit < 0) {
            cout << "Overdraft limit cannot be negative.\n";
        }
    } while (overDraftLimit < 0);
}

void CurrentAccount::withdraw() {
    double amount;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;
    if (amount > (balance + overDraftLimit)) {
        throw runtime_error("Overdraft limit exceeded.");
    }
    balance -= amount;
    cout << "INR " << amount << " debited. Updated balance: INR " << fixed << setprecision(2) << balance << "\n";
}

void CurrentAccount::displayAccountDetails() const {
    Account::displayAccountDetails();
    cout<< "\nOverdraft Limit : INR " << overDraftLimit << "\n";
}

CurrentAccount::~CurrentAccount() {
    cout << "CurrentAccount destructor\n";
}
