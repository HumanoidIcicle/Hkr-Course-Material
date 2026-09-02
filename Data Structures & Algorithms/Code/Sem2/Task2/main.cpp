#include <iostream>
#include "addressBook.h"

int main() {
    AddressBook m;
    m.add("Timmy", "sweden");
    m.add("Mike", "singapore");
    m.add("Sara", "sweden");
    m.add("Jane", "Heaven");
    m.add("John", "Oz-ville");
    m.Display();
    
    m.remove("John");
    m.add("Anna", "Underworld");
    m.remove("Jane");
    m.add("Daniel", "MCU");
    m.Display();
    m.getByIndex(6);
    m.getByIndex(4);
    m.getByIndex(1);
    return 0;
}
