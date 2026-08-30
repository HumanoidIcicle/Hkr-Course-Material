//
// Created by JOSS0001 on 2025-12-03.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "item.h"

using namespace std;

class Player{
protected:
    int hp = 5;
    int maxHp = 15;
    int baseAttack = 1;
    string weaponName = "None";

    vector<Item> inventory;
public:
    //~Player() = default;
    //Player(string weaponName);
    void stats();
    void showItems();
    string getWeapon() const { return weaponName; }

    void addItem(Item item);
    void addItem(string name, string id, string type);
    void damage(int d) {hp -= d;}
    int defense(int d) {d = 0.5*d; return d;}
    void equip(string id);
    void heal(string id); //hp to maxhp
    void totalAttack(); //base + weapon bonus

    void getHp() const {cout <<"current health: " << hp <<endl; }
};

#endif //PLAYER_H
