//
// Created by JOSS0001 on 2025-11-26.
//

#ifndef NURSE_H
#define NURSE_H

#include "staff.h"
#include <string>
using namespace std;

class Nurse: public Staff {
protected:
    string prof = "nurse";
    int hpw;
public:
    Nurse(string name, float salary, int hpw);
    void info() const override;
    float annual() override;
    string getPro()override{return prof;}

};
#endif //NURSE_H
