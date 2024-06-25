#include <iostream> 
#include <string>
#include <vector>
#include <Windows.h>
#include <limits>
#include <cctype>

using namespace std;

class BankAccount {
private: 
	int AccountNumber; 
	double balance;
	double interestRate;

public: 
	BankAccount(int AccountNumber, double balance, double interestRate) {
		this->AccountNumber = AccountNumber;
		this->balance = balance;
		this->interestRate = interestRate;
	}

	void deposit(double amount) {
		balance += amount;
	}

	void withdraw(double amount) {
		if (amount < 0) {
			cout << "Ошибка!" << endl;
			return;
		}
		if (balance - amount < 0) {
			cout << "Ошибка!" << endl;
			return; 
		}
		balance -= amount; 
	}

	double getbalance() {
		return balance;
	}

	double getInterest() {
		return balance * interestRate * 1.0/12.0;
	}

	double setIneterestRate(double newInterestRate) {
		if (newInterestRate < 0) {
			cout << "Ошибка!" << endl;
			return 0;
		}
		interestRate = newInterestRate;
		return newInterestRate;
	}

	int getAccountNumber() {
		return AccountNumber;
	}

	friend bool transfer(BankAccount& n, BankAccount& m, double amount) {
		if (amount < 0) {
			cout << "Ошибка!" << endl;
			return false; 
		}
		if (n.balance - amount < 0) {
			cout << "Ошибка!" << endl;
			return false; 
		}
		n.balance -= amount;
		m.balance += amount;
		return true;
	}
};

int main() {
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");

	BankAccount account1(123456, 2000.0, 0.05);
	BankAccount account2(654321, 4000.0, 0.05);

	cout << "Баланс 1 аккаунта: " << account1.getbalance() << endl;
	cout << "Проценты 1 аккаунта: " << account1.getInterest() << endl;

	if (transfer(account1, account2, 500.0)) {
		cout << "Перевод выполнен" << endl;
	}
	else {
		cout << "Перевод не удался :(" << endl;
	}
	return 0;
}
