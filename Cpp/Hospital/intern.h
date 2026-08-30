//
// Created by JOSS0001 on 2025-11-26.
//

#ifndef INTERN_H
#define INTERN_H

#include "staff.h"
#include <string>
using namespace std;

class Intern: public Staff {
protected:
    string prof = "intern";
    int duration;
public:
    Intern(string name, float salary, int months);
    void info() const override;
    void increase(float percent) override;
    float annual() override;
    string getPro()override{return prof;}

};
#endif //INTERN_H
