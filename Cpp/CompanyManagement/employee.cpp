//
// Created by JOSS0001 on 2025-11-25.
//

#include "employee.h"
#include <string>
#include <iostream>

namespace employee {
    Employee::Employee(std::string name, double salary) :name(std::move(name)), salary(salary) {}
    void Employee::displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "->Salary: SEK." << salary << "\n" << std::endl;
    }
    void Employee::increaseSalary(double amount){
        salary += amount;
    }
}