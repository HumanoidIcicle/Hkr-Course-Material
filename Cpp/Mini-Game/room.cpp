//
// Created by JOSS0001 on 2025-12-03.
//

#include "room.h"
#include <string>
#include <iostream>

using namespace std;

Room::Room(string name, string desc)
    : name(move(name)), description(move(desc)) {}

void Room::describe() const {
    cout << "Current room: " << endl;
    cout << " -> " << description << endl;
}
void Room::addItemById(Item item) {
    itemIds.push_back(item.getId());
}

void Room::addExit(char dir, string id) {
    exits.insert({dir, id});
}

void Room::showExits() const {
    cout << "\nAvailable exits" << endl;
    for (auto exit: exits) {
        cout << " - " << exit.second << "(" << exit.first << ")\n";
    }
}



