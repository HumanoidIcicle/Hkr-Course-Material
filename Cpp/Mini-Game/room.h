//
// Created by JOSS0001 on 2025-12-03.
//

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <map>
#include <vector>
#include "item.h"

using namespace std;

class Room {
protected:
    string name;
    string description;
    map<char, string> exits; //'n' -> "R2"
    vector<string> itemIds;
public:
    ~Room()= default;
    Room(string name, string desc);

    void describe() const;
    void addExit(char dir, string id);
    string getName() const { return name;}
    auto getExits() {return exits;}
    void showExits() const;
    void addItemById(Item item);
    auto getItemIds() {return itemIds;}
};

#endif //ROOM_H
