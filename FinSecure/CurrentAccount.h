#pragma once
#include "Account.h"

class CurrentAccount : public Account {
private:
    double overDraftLimit;

public:
    CurrentAccount();
    void CreateAccount() override;
    void withdraw() override;
    void displayAccountDetails() const override;
    ~CurrentAccount();
};

