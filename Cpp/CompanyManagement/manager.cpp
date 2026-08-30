//
// Created by JOSS0001 on 2025-11-25.
//

#include "manager.h"
#include <iostream>

namespace manager {
    Manager::Manager(std::string name, double salary, int team=0):Employee(std::move(name), salary), teamSize(team){}
    void Manager::increaseSalary(double amount) {
        amount += 0.1*amount;
        salary += amount;
    }
    void Manager::displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "->Salary: SEK." << salary << std::endl;
        std::cout << "->Members on Team: " << teamSize << "\n"<< std::endl;
    }

    Executive::Executive(std::string name, double salary, double bonus): Manager(std::move(name), salary), bonus(bonus) {}
    void Executive::increaseSalary(double amount) {
        amount += bonus*amount;
        salary += amount;
    }
    void Executive::displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "->Salary: SEK." << salary << std::endl;
        std::cout << "->Bonus for Executives: " << bonus*100 << "%\n"<< std::endl;
    }
}
