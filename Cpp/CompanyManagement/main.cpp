#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
#include "intern.h"
#include "manager.h"
using namespace manager;
using namespace employee;
using namespace intern;
using namespace std;
int main() {
    cout << "\n========== BEFORE BONUS ==========" << endl;

    vector<Employee*> staff;
    Executive x1("Super", 15000, 0.2);
    Manager m1("Jane", 15000.0, 15);
    Employee e1("PeiShan", 15000.0);
    Intern i1("Lisa", 15000.0, 7);
    staff.push_back(&x1);
    staff.push_back(&m1);
    staff.push_back(&e1);
    staff.push_back(&i1);

    for (Employee* s : staff) {
        s->displayInfo();
    }
    cout << "\n========== AFTER BONUS ==========" << endl;
    for (Employee* s : staff) {
        s->increaseSalary(1530.0);
        s->displayInfo();
    }

    return 0;
}
