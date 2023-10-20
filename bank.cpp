#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a struct to represent a bank account
struct BankAccount {
    string name;
    int accountNumber;
    double balance;
};

// Define a vector to store all bank accounts
vector<BankAccount> accounts;

// Function to add a new bank account
void addAccount() {
    BankAccount account;
    cout << "Enter account holder name: ";
    cin >> account.name;
    cout << "Enter account number: ";
    cin >> account.accountNumber;
    cout << "Enter initial balance: ";
    cin >> account.balance;
    accounts.push_back(account);
    cout << "Account added successfully!" << endl;
}

// Function to display all bank accounts
void displayAccounts() {
    if (accounts.empty()) {
        cout << "No accounts found." << endl;
        return;
    }
    cout << "Accounts:" << endl;
    for (const auto account : accounts) {
        cout << "Name: " << account.name << endl;
        cout << "Account number: " << account.accountNumber << endl;
        cout << "Balance: " << account.balance << endl;
        cout << endl;
    }
}

// Function to deposit money into a bank account
void deposit() {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;
    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account.balance += amount;
            cout << "Deposit successful. New balance: " << account.balance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Function to withdraw money from a bank account
void withdraw() {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;
    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (amount > account.balance) {
                cout << "Insufficient balance." << endl;
                return;
            }
            account.balance -= amount;
            cout << "Withdrawal successful. New balance: " << account.balance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Main function
int main() {
    int choice;
    while (true) {
        cout << "Bank Management System" << endl;
        cout << "1. Add account" << endl;
        cout << "2. Display accounts" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
        cout << endl;
    }
}

