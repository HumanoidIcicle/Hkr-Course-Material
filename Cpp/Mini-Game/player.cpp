//
// Created by JOSS0001 on 2025-12-03.
//

#include "player.h"
#include <algorithm>
#include <iostream>

using namespace std;

//Player::Player(string weaponName) : weaponName(move(weaponName)) {}
void Player::stats() {
    cout <<endl;
    cout << "My stats: \n";
    cout << "  HP: " << hp << endl;
    cout << "  MaxHp: " << maxHp << endl;
    cout << "  Base attack: " << baseAttack << endl;
    cout << "  Weapon: " << weaponName << endl;
}

void Player::addItem(Item item) {
    item.setValue();
    inventory.push_back(item);
}

void Player::addItem(string name, string id, string type) {
    Item item(move(name), move(id), move(type));
    item.setValue();
    inventory.push_back(item);
}

void Player::showItems() {
    if (!inventory.empty()){
        cout << "\n    - Items in inventory:\n";
        for (auto item: inventory) item.itemInfo();
    }
    else cout << "\nOops! Your inventory is empty.\n";
}

void Player::heal(string id) {
    string found = "";

    for (auto item: inventory) {
        if (item.getId() == id && item.getType() == "consumable")
            found = item.getName();
    }

    if (found != "") {
        hp = maxHp;
        cout << "\nHealth restored to full hp." <<endl;
    }
    else cout << "Consumable not available in inventory.\n";
}

void Player::equip(string id) {
    string found = "";
    for (auto item: inventory) {
        if (item.getId() == id && item.getType() == "weapon") {
            found = item.getName();
            break;
        }
    }
    if (found != "") {
        weaponName = found;
        cout << "\nWeapon equipped.\n" <<endl;
        totalAttack();
    }
    else cout << "Weapon with that ID isn't available in inventory.\n";
}

void Player::totalAttack() {
    int total = baseAttack;
    for (auto item: inventory) {
        if (weaponName == item.getName()) {
            total += item.getValue();
            break;
        }
    }
    baseAttack = total;
    cout << "Attack advanced to: "<< baseAttack <<endl;
}




