//
// Created by JOSS0001 on 2025-11-26.
//

#ifndef STAFF_H
#define STAFF_H

#include <string>
using namespace std;

class Staff {
protected:
    string prof;
    string name;
    float salary;
public:
    ~Staff() = default;
    Staff(string name, float salary);
    virtual void info() const;
    virtual void increase(float percent);
    virtual float annual();
    virtual string getPro(){return prof;}

};
#endif //STAFF_H
