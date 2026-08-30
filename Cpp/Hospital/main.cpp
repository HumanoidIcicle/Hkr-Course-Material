#include <iostream>
#include "nurse.h"
#include "doctor.h"
#include "intern.h"
#include "hospital.h"

int main() {
    Hospital Devine;

    Devine.newEmp(new Nurse ("Jane", 47700, 48));
    Nurse n2("Jane", 47700, 48);
    Devine.newEmp(&n2);
    Nurse n3("Jane", 47700, 48);
    Devine.newEmp(&n3);
    Doctor d1("Jane", "Surgeon", 93600);
    Devine.newEmp(&d1);
    Doctor d2("Jane", "Surgeon", 93600);
    Devine.newEmp(&d2);
    Intern i1("Jane", 3700, 9);
    Devine.newEmp(&i1);
    int n = 0;
    int d = 0;
    int i = 0;

    Devine.allEmployees();
    cout << "\n==================================" <<endl;
    cout << "Before bonus" <<endl;
    Devine.budget();

    Devine.addBonus(13);
    cout << "\n==================================" <<endl;
    cout << "After bonus" <<endl;
    Devine.budget();
    Devine.type_count( n,  d,  i);

    cout << "\nThere are " << d <<" doctors.\n" <<endl;
    cout << "There are " << n <<" nurses.\n" <<endl;
    cout << "There are " << i <<" interns.\n" <<endl;

    //Devine.clearMem(); //For if/when using new
    return 0;
}

