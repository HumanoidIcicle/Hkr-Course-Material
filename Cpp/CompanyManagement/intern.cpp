//
// Created by JOSS0001 on 2025-11-25.
//

#include "intern.h"
#include <string>
#include <iostream>

namespace intern {
    Intern::Intern(string name, double salary, int duration): Employee(std::move(name), salary), durationMonths(duration){}
    void Intern::displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "->Salary: SEK." << salary << std::endl;
        std::cout << "->Internship Duration: " << durationMonths <<"months." << "\n" << std::endl;
    }
    void Intern::increaseSalary(double amount) {
        std::cout << "Company doesn't give bonuses to interns." <<std::endl;
    }
}
