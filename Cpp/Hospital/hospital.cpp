//
// Created by JOSS0001 on 2025-11-26.
//

#include "hospital.h"
#include <vector>
#include <iostream>

void Hospital::newEmp(Staff* member) {
    all.push_back(member);
}
void Hospital::allEmployees() const{
    for (Staff* one: all) {
        one->info();
    }
}
void Hospital::addBonus(float percent) {
    for (auto mem: all) {
        mem->increase(percent);
    }
}
void Hospital::budget() {
    int total = 0;
    for (auto mem: all) {
        total += mem->annual();
    }
    cout << "Budget for all employees: SEK."<< total << endl;
}
void Hospital::type_count(int& nurses, int& docs, int& terns) const{
    for (auto her:all) {
        if (her->getPro()== "doctor") docs += 1;
        if (her->getPro()== "nurse") nurses += 1;
        if (her->getPro()== "intern") terns += 1;
    }
}
void Hospital::clearMem() {
    for (auto em: all) delete em;
}





