//
// Created by JOSS0001 on 2025-11-26.
//

#include "staff.h"
#include <iostream>
#include <string>

using namespace std;
Staff::Staff(string name, float salary) : name(move(name)), salary(salary){}

float Staff::annual() {
    return 12 * salary;
}

void Staff::increase(float percent) {
    salary += percent/100*salary;
}

void Staff::info() const {
    cout << "\nName: " << name <<endl;
    cout << "Salary: SEK." << salary <<endl;
}




