#include "BankManager.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"

BankManager::BankManager() {}

void BankManager::createAcc(Account* acc) {
    acc->CreateAccount();
    accounts.push_back(acc);
}

void BankManager::display() {
    long acc_num;
    string type;
    cout << "Enter your account number: ";
    cin >> acc_num;
    cout << "Enter your account type (saving/current): ";
    cin >> type;

    for (Account* acc : accounts) {
        if (acc->getAccountNumber() == acc_num && acc->getAccountType() == type) {
            acc->displayAccountDetails();
            return;
        }
    }
    cout << "Account not found.\n";
}

void BankManager::deposit() {
    long acc_num;
    string type;
    cout << "Enter your account number: ";
    cin >> acc_num;
    cout << "Enter your account type (saving/current): ";
    cin >> type;

    for (Account* acc : accounts) {
        if (acc->getAccountNumber() == acc_num && acc->getAccountType() == type) {
            acc->deposit();
            return;
        }
    }
    cout << "Account not found.\n";
}

void BankManager::withdraw() {
    long acc_num;
    string type;
    cout << "Enter your account number: ";
    cin >> acc_num;
    cout << "Enter your account type (saving/current): ";
    cin >> type;

    for (Account* acc : accounts) {
        if (acc->getAccountNumber() == acc_num && acc->getAccountType() == type) {
            acc->withdraw();
            return;
        }
    }
    cout << "Account not found.\n";
}

void BankManager::displayAll() {
    if (accounts.empty()) {
        cout << "No accounts to display.\n";
        return;
    }

    for (Account* acc : accounts) {
        acc->displayAccountDetails();
        cout << "--------------------------------\n";
    }
}

BankManager::~BankManager() {
    for (Account* acc : accounts) {
        delete acc;
    }
    cout << "BankManager destructor\n";
}