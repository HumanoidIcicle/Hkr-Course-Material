//
// Created by JOSS0001 on 2025-12-03.
//

#include <map>
#include <string>
#include <iostream>

#include "Game.h"
#include "room.h"
#include "item.h"
#include "player.h"

using namespace std;

void Game::initializeWorld(Player* p) {
    player = p;

    // Add items safely
    items.emplace("1", Item("Sword", "1", "weapon"));
    items.emplace("7", Item("Katana", "7", "weapon"));
    items.emplace("5", Item("Healing Potion", "5", "consumable"));
    items.emplace("4", Item("Golden Key", "4", "key"));
    items.emplace("3", Item("Bone-key", "3", "key"));
    items.emplace("6", Item("Goblin-key", "6", "key"));
    items.emplace("2", Item("Water", "2", "consumable"));

    // Create rooms safely
    rooms.emplace("entrance", Room("Entrance", "Starting area, safe."));
    rooms.at("entrance").addExit('n', "prayer");
    rooms.at("entrance").addExit('e', "library");

    currentRoom = &rooms.at("entrance");

    rooms.emplace("prayer", Room("Prayer Room", "Dusty abandoned old prayer room."));
    rooms.at("prayer").addExit('e', "dungeon");
    rooms.at("prayer").addExit('s', "entrance");
    rooms.at("prayer").addItemById(items.at("1"));
    rooms.at("prayer").addItemById(items.at("6"));

    rooms.emplace("dungeon", Room("Dungeon", "Dangerous dark dungeon crawling with mythical creatures."));
    rooms.at("dungeon").addExit('w', "prayer");

    rooms.emplace("library", Room("Enchanted Library", "Endless cursed bookshelf maze."));
    rooms.at("library").addExit('w', "entrance");
    rooms.at("library").addItemById(items.at("3"));
    rooms.at("library").addItemById(items.at("2"));
}
void Game::menu() {
    cout <<endl;
    cout << "------------------------------------\n";
    cout << "    \t===== MENU =====" << endl;
    cout << "  1. Look around room." << endl;
    cout << "  2. Pick up items." << endl;
    cout << "  3. Show my inventory." << endl;
    cout << "  4. Equip a weapon (by ID)." << endl;
    cout << "  5. Use a consumable (by ID)." << endl;
    cout << "  6. Go to another room. (Direction)" << endl;
    cout << "  7. Help." << endl;
    cout << "  8. Exit game." << endl;
    cout << "------------------------------------\n";
    cout << "" << endl;
}
void Game::addItem(Item item) { //adds item to game, not player
    items.insert({item.getId(),item});
}
void Game::look() {
    currentRoom->describe();

    auto collectibles = currentRoom->getItemIds();
    if (!collectibles.empty()){
        cout << "\nItems in room:\n";
        for (auto id: collectibles) {
            auto it = items.find(id);
            if (it != items.end()) {
                (*it).second.itemInfo();
            }
        }
    }
    else cout << "\n*This room has no collectibles.\n";
    currentRoom->showExits();
}
void Game::pickUp() {
    for (auto id: currentRoom->getItemIds()) {
        auto it = items.find(id);
        if (it != items.end()) {
            cout <<"added to player.";
            it->second.itemInfo();
            player->addItem((*it).second);
        }
    }
    cout << "\nCollectibles added to inventory." << endl;
}
void Game::go(char dir) {
    //if (avail.contains(dir)) {//returns true if dir is in exits
    auto available = currentRoom->getExits();
    auto it_of_room_in_avail = available.find(dir);

    if (it_of_room_in_avail != available.end()){
        auto it_in_game_rooms = rooms.find((*it_of_room_in_avail).second);
        currentRoom = &(*it_in_game_rooms).second;
        cout << "YOu are now in the: " << currentRoom->getName() <<endl;
    }
    else cout << "\nNot an exit from this room.\n";
}
void Game::inventory() {
    player->showItems();
}
void Game::equip(string id) {
    player->equip(id);
}
void Game::use(string id) {
    player->heal(id);
}
void Game::help() {
    menu();
}
void Game::exit(bool* keep_playing) {
    cout << "\nThank you for playing Dungeons Not Dragons." << endl;
    *keep_playing = false;
}

