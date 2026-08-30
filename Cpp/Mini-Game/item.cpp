//
// Created by JOSS0001 on 2025-12-03.
//

#include "item.h"
#include <iostream>
using namespace std;

Item::Item(string name, string id, string type)
    : id(move(id)), name(move(name)), type(move(type)){}

void Item::setValue() {
    if (type == "weapon") value = 2;
    if (type == "consumable") value = 15;
    if (type == "key") value = 0;
}
void Item::itemInfo() const{
    cout <<endl;
    cout << "->Type: " << type << endl;
    cout << "  Name: " << name << endl;
    cout << "  ID: " << id << endl;
    cout << "  Value: " << value << endl;
}


