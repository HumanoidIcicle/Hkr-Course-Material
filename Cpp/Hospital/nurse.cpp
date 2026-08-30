//
// Created by JOSS0001 on 2025-11-26.
//

#include "nurse.h"
#include <string>
#include <iostream>

using namespace std;
Nurse::Nurse(string name, float salary , int hpw)
: Staff(move(name), salary), hpw(hpw){}

float Nurse::annual() {
    float shift = 800*(hpw-40);
    return 12*salary + shift;
}

void Nurse::info() const {
    cout << "\n->Profession: Nurse." <<endl;
    cout << "Name: " << name <<endl;
    cout << "Annual shift hours: " << hpw*4*12 << " hours."<<endl;
    cout << "Salary: SEK." << salary <<endl;
}
