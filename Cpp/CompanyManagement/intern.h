//
// Created by JOSS0001 on 2025-11-25.
//

#ifndef INTERN_H
#define INTERN_H

#include <string>
#include "employee.h"
using namespace std;

namespace intern {
    class Intern : public employee::Employee {
        int durationMonths;

    public:
        Intern(string name, double salary, int duration);
        void displayInfo() override;
        void increaseSalary(double amount) override;
    };
}

#endif //INTERN_H
