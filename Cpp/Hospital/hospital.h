//
// Created by JOSS0001 on 2025-11-26.
//

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "doctor.h"
#include "intern.h"
#include "nurse.h"
#include <vector>

using namespace std;
class Hospital {
protected:
    vector<Staff*> all;
public:
    void newEmp(Staff* member);
    void allEmployees() const;
    void budget();
    void addBonus(float percent );
    void type_count(int& nurses, int& docs, int& terns) const;
    void clearMem();
};

#endif //HOSPITAL_H
