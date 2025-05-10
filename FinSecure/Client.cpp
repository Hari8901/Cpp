#include <limits>
#include <cctype>
#include "BankManager.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"

static void clearInput() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
	char ch = 'y';
	int choice;
	string type_of_acc, role;
	BankManager b1;

	try {
		do {
			cout << "\n=========== Welcome to EXIM BANK ===========\n";
			cout << "1. Create Account\n2. Display Account Details\n3. Deposit Money\n";
			cout << "4. Withdraw Money\n5. Display All Accounts (Admin only)\n6. Exit\n";
			cout << "=============================================\n";
			cout << "Enter your choice: ";
			cin >> choice;

			if (cin.fail()) {
				clearInput();
				throw runtime_error("Invalid input: Please enter a number.");
			}

			switch (choice) {
			case 1: {
				cout << "Enter account type to open (saving/current): ";
				cin >> type_of_acc;
				if (type_of_acc == "saving") {
					b1.createAcc(new SavingAccount);
				}
				else if (type_of_acc == "current") {
					b1.createAcc(new CurrentAccount);
				}
				else {
					cout << "Invalid account type.\n";
				}
				break;
			}
			case 2:
				b1.display();
				break;
			case 3:
				b1.deposit();
				break;
			case 4:
				b1.withdraw();
				break;
			case 5:
				cout << "Enter your role (admin/user): ";
				cin >> role;
				if (role == "admin" || role == "Admin" || role == "ADMIN") {
					b1.displayAll();
				}
				else {
					cout << "Access denied. Admins only.\n";
				}
				break;
			case 6:
				cout << "Thank you! Visit again.\n";
				exit(0);
			default:
				cout << "Invalid choice.\n";
			}

			clearInput();
			cout << "\nReturn to main menu? (y/n): ";
			cin >> ch;
		} while (ch == 'y' || ch == 'Y');
	}
	catch (const exception& e) {
		cerr << "Exception: " << e.what() << '\n';
	}

	return 0;
}
