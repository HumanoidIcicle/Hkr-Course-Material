//
// Created by JOSS0001 on 2025-11-25.
//

#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"
#include <string>
using namespace employee;

namespace manager {
    class Manager:public Employee {
        int teamSize;

    public:
        Manager(std::string name, double salary, int team);
        void increaseSalary(double amount) override;
        void displayInfo() override;
    };

    class Executive: public Manager {
        double bonus;

    public:
        Executive(std::string name, double salary, double bonus);
        void increaseSalary(double amount) override;
        void displayInfo() override;
    };
}

#endif //MANAGER_H
