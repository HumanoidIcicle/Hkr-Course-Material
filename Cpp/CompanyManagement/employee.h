//
// Created by JOSS0001 on 2025-11-25.
//

#ifndef STAFF_H
#define STAFF_H

#include <string>
namespace employee {
    class Employee {
    protected:
        std::string name;
        double salary;

    public:
        virtual ~Employee() = default;
        Employee(std::string name, double salary);

        virtual void displayInfo();
        virtual void increaseSalary(double amount);
    };
}
#endif //STAFF_H
