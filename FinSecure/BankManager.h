#pragma once
#include "Account.h"

class BankManager {
private:
    vector<Account*> accounts;

public:
    BankManager();
    void createAcc(Account* acc);
    void display();
    void deposit();
    void withdraw();
    void displayAll();
    ~BankManager();
};