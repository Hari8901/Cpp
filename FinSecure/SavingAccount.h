#include "Account.h"

class SavingAccount : public Account {
private:
    double interest_rate;

public:
    SavingAccount();
    void CreateAccount() override;
    void withdraw() override;
    void displayAccountDetails() const override;
    ~SavingAccount();
};
