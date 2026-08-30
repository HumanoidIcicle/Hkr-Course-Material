//
// Created by JOSS0001 on 2025-12-03.
//

#ifndef GAME_H
#define GAME_H

#include "room.h"
#include "item.h"
#include "player.h"
using namespace std;

#include <map>
#include <string>


class Game {
protected:
    map<string, Room> rooms; //roomName -> Room
    map<string, Item> items; //itemId -> item
    Player* player = nullptr;
    Room* currentRoom = nullptr;

public:
    void initializeWorld(Player* p);
    void addItem(Item item);

    //OPTIONS
    void menu();
    void look(); //the describe in room class
    void go(char dir);// in Game class
    void pickUp(); //add items in room, calls addItem, to player inventory
    void inventory();//ready in player
    void equip(string id);//ready in player
    void use(string id); //the heal in player class
    void help(); //print menu
    void exit(bool* keep_playing); //Ends the game
};
#endif //GAME_H
