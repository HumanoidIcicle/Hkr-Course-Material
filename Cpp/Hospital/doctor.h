//
// Created by JOSS0001 on 2025-11-26.
//

#ifndef DOCTOR_H
#define DOCTOR_H

#include "staff.h"
#include <string>
using namespace std;

class Doctor : public Staff {
protected:
    string prof = "doctor";
    string special;
public:
    Doctor(string name, string speciality, float salary);
    void increase(float percent) override;
    void info() const override;
    float annual() override;
    string getPro()override{return prof;}
};
#endif //DOCTOR_H
