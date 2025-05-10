#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include<vector>
using namespace std;

class Account {
protected:
    long account_number;
    string account_holder, acc_type;
    double balance;

public:
    Account();

    virtual void CreateAccount();
    virtual void displayAccountDetails() const;
    virtual void deposit();
    virtual void withdraw() = 0;

    long getAccountNumber() const;
    void setAccountNumber(long acc_num);
    double getBalance() const;
    void setBalance(double b);
    string getAccountType() const;
    void setAccountType(const string& type);

    virtual ~Account();
};