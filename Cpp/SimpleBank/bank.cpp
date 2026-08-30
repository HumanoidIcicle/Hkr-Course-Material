//
// Created by JOSS0001 on 2025-11-24.
//

#include "bank.h"
#include <string>

BankAccount::BankAccount(std::string firstname, std::string lastname,
    double amount=0): balance(amount), owner(firstname + " " + lastname){}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::withdraw(float draw) {
    balance = balance - draw;
}
std::string BankAccount::getName() const {
    return owner;
}

void BankAccount::deposit(float add) {
    balance = balance + add;
}


