
#include <iomanip>
#include <iostream>
#include <vector>

#include "bank.h"

BankAccount user() {
    std::string firstname, lastname;
    double amount;

    std::cout << "Enter first and lastname: ";
    std::cin >> firstname >> lastname;

    std::cout << "Enter amout to add to account: ";
    std::cin >> amount;
    BankAccount person(firstname, lastname, amount);

    return person;
}
void userDetails(BankAccount person) {
    std::cout << " \n-> Account for: " << person.getName() <<std::endl;
    std::cout << "-> Current balance: " << person.getBalance() <<std::endl;
}
std::vector<BankAccount> users(int n) {
    std::vector<BankAccount> accounts;
    for (int i = 0; i < n; i++) {
        auto person = user();
        accounts.push_back(person);
    }

    std::cout << "Current users: ";
    for (BankAccount person: accounts) {
        userDetails(person);
    }
    return accounts;
}
int main() {
    bool run = true;
    //Create how many users
    int n = 2;
    auto use = users(n);

    std::cout << "\n\t=======First create an account.=======\n" <<std::endl;

    auto person = user();
    userDetails(person);

    while (run) {
        std::cout << "\nMENU" <<std::endl;
        //std::cout << "\t1. Create account" <<std::endl;
        std::cout << "\t1. Deposit" << std::endl;
        std::cout << "\t2. Withdraw" <<std::endl;
        std::cout << "\t3. Exit page" <<std::endl;

        int choice;
        std::cout << "Enter a choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                double add;
                std::cout << "Amount to add: ";
                std::cin >> add;
                person.deposit(add);
            std::cout << "You account balance is: " << person.getBalance() <<std::endl;
            break;
            case 2:
                double take;
                std::cout << "Amount to take: ";
                std::cin >> take;
                person.withdraw(take);
            std::cout << "You account balance is: " << person.getBalance() << std::endl;
            break;
            case 3: run = false; break;
            default: std::cout <<"Enter valid choice.";
        }
    }
    std::cout << "Welcome to Jovan Consolidated International Bank. "
                "\nSee you again soon, "<< person.getName() + ".\n";

    return 0;
}