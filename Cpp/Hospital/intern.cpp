//
// Created by JOSS0001 on 2025-11-26.
//

#include "intern.h"
#include <string>
#include <iostream>

using namespace std;
Intern::Intern(string name, float salary , int months)
: Staff(move(name), salary), duration(months){}

float Intern::annual() {
    return duration*salary;
}
void Intern::increase(float percent) {
    cout << "";
}

void Intern::info() const {
    cout << "\n->Profession: Intern." <<endl;
    cout << "Name: " << name <<endl;
    cout << "Internship period: " << duration <<" months."<<endl;
    cout << "Salary: SEK." << salary <<endl;
}