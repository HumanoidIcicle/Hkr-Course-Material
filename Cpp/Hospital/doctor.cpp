//
// Created by JOSS0001 on 2025-11-26.
//

#include "doctor.h"
#include <iostream>
#include <string>

using namespace std;
Doctor::Doctor(string name,string speciality, float salary)
: Staff(move(name), salary), special(move(speciality)){}

float Doctor::annual() {
    return 12*(1200+salary);
}

void Doctor::increase(float percent) {
    salary += percent/100*salary + 1200;
}

void Doctor::info() const {
    cout << "\n->Profession: Doctor." <<endl;
    cout << "Name: " << name <<endl;
    cout << "Speciality: " << special <<endl;
    cout << "Salary: SEK." << salary <<endl;
}
