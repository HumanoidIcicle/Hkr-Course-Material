//
// Created by JOSS0001 on 2025-11-24.
//

#pragma once
#include <string>

class BankAccount {
    // Constructor, deposit(), withdraw(), getBalance()
    double balance;
    std::string owner;
public:
    //CONSTRUCTOR
    BankAccount() = default;
    BankAccount(std::string firstname, std::string lastname, double amount);

    //GETTER
    double getBalance() const;
    std::string getName() const;

    //SETTERS
    void withdraw(float draw);
    void deposit(float add);
};


