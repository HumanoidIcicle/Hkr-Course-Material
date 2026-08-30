#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#include "file.h"

//transform(str.begin(), str.end(), str.begin(), ::toupper);
//GOBLIN; hp=12,atk=4,def=1,hit=0.7,crit=0.2

    /*
        auto g1 = make_unique<GOBLIN>("Goblin", 12, 3, 1, 0.8, 0.2);
        auto s1 = make_unique<SKELETON>("Skeleton", 16, 5, 1, 0.8, 0.2);
        auto g2 = make_unique<GOBLIN>("Goblin", 12, 3, 1, 0.8, 0.2);
        auto s2 = make_unique<SKELETON>("Skeleton", 16, 5, 1, 0.8, 0.2);
        auto b1 = make_unique<BOSS>("Boss", 30, 5, 2, 0.9, 0.2);
    */

    //Make the rooms
    /*
        rooms.emplace("R1", make_shared<Room>("Entrance", "Starting area, safe."));
        rooms.at("R1")->addExit("n", "R3");
        rooms.at("R1")->addExit("e", "R2");

        currentRoom = rooms.at("R1");

        rooms.emplace("R2", make_shared<Room>("Enchanted Library", "Endless cursed bookshelf maze."));
        rooms.at("R2")->addExit("w", "R1");

        rooms.emplace("R3", make_shared<Room>("Hall", "A dark winding path to oblivion."));
        rooms.at("R3")->addExit("n", "R4");
        rooms.at("R3")->addExit("s", "R1");

        rooms.emplace("R4", make_shared<Room>("Malevolent Shrine", "Dusty abandoned old Sukuna shrine."));
        rooms.at("R4")->addExit("e", "R5");
        rooms.at("R4")->addExit("s", "R3");

        rooms.emplace("R5", make_shared<Room>("Vecna's Infinite Dungeon", "Dangerous dark R5 crawling with mythical creatures."));
        rooms.at("R5")->addExit("w", "R4");
        rooms.at("R5")->addExit("e", "R6");

        rooms.emplace("R6", make_shared<Room>("The Upside-Down", "Dimensional Portal."));
        rooms.at("R6")->addExit("w", "R5");

        rooms.at("R6")->setLock(true);
        rooms.at("R6")->setKey("Audrey Hepburn Key");

        rooms.at("R5")->setLock(true);
        rooms.at("R5")->setKey("Ingrid Bergman Key");

    //Make items

        items.emplace("5", make_unique<KEY>("Key", "Bone-key", "5"));
        items.emplace("4", make_unique<CONSUMABLE>("Consumable", "Anne Hathaway", "4"));
        items.emplace("13", make_unique<KEY>("Key", "Ingrid Bergman Key", "13"));
        items.emplace("10", make_unique<KEY>("Key", "Judi Dench Key", "10")); //to be dropped by boss
        items.emplace("7", make_unique<CONSUMABLE>("Consumable", "Bordeaux", "7"));
        items.emplace("3", make_unique<CONSUMABLE>("Consumable", "Apple pie", "3"));
        items.emplace("6", make_unique<CONSUMABLE>("Consumable", "Vodka Martini", "6"));
        items.emplace("9", make_unique<CONSUMABLE>("Consumable", "Stagnant water", "9"));
        items.emplace("8", make_unique<CONSUMABLE>("Consumable", "Moldy bread", "8"));
        items.emplace("1", make_unique<WEAPON>("Weapon", "Sword", "1"));
        items.emplace("11", make_unique<CONSUMABLE>("Consumable", "Meryl Streep", "11"));
        items.emplace("2", make_unique<WEAPON>("Weapon", "Machine-gun", "2"));
        items.emplace("12", make_unique<WEAPON>("Weapon", "Spear", "12"));

    //Fill the rooms enemies and items

        rooms.at("R4")->addItem(move(items.at("1")));
        rooms.at("R4")->addItem(move(items.at("8")));
        rooms.at("R4")->addEnemy(move(g1));
        rooms.at("R4")->addItem(move(items.at("7")));
        rooms.at("R3")->addItem(move(items.at("6")));

        rooms.at("R1")->addItem(move(items.at("9")));
        rooms.at("R1")->addItem(move(items.at("5")));
        rooms.at("R3")->addEnemy(move(s1));

        rooms.at("R3")->addEnemy(move(g2));

        rooms.at("R3")->addItem(move(items.at("3")));
        rooms.at("R2")->addItem(move(items.at("10")));
        rooms.at("R2")->addItem(move(items.at("4")));
        rooms.at("R3")->addItem(move(items.at("12")));
        rooms.at("R2")->addItem(move(items.at("2")));
        rooms.at("R2")->addEnemy(move(s2));

        rooms.at("R1")->addItem(move(items.at("13")));
        rooms.at("R5")->addItem(move(items.at("11")));

        rooms.at("R6")->addItem(move(items.at("6")));
        rooms.at("R5")->addEnemy(move(b1));
*/

using namespace std;
int main() {
    ifstream fil_out("rooms.csv");
    FileIO f;
    //f.readCatalog("catalog.csv");
    ifstream t("rooms.csv");
    f.readRooms("rooms.csv");

    return 0;
}
