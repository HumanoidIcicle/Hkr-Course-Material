//
// Created by JOSS0001 on 2025-12-12.
//
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include "file.h"

using namespace std;

typedef struct {
    string name;
    int hp;
    int def;
    int atk;
    float crit, hit;
} Enemy;

void FileIO::readCatalog(string filename ) {
    string store_line;
    ifstream  file_to_read(filename);

    while (getline(file_to_read, store_line)) {
        if (!store_line.empty()) {
            transform(store_line.begin(), store_line.end(), store_line.begin(), ::toupper);
            stringstream parts(store_line);
            string cat, name, type, id;

            getline(parts, cat, ';');
            if (cat == "ITEM"){
                getline(parts, name, ';');
                getline(parts, type, ';');
                getline(parts, id);

                cout << "Cat: "<< cat << endl;
                cout << "name: "<< name << endl;
                cout << "type: "<< type << endl;
                cout << "id: "<< id << endl <<endl;
            }
            else if (cat == "ENEMY") {
                Enemy en;
                string stats;
                getline(parts, name, ';');
                getline(parts, stats);

                en.name = name;
                //name = goblin
                //stats = hp=12,atk=4,def=1,hit=0.7,crit=0.2

                stringstream split_stats(stats);
                string split_comma;

                //map<string, float> m_stats;
                vector<string> m_stats;
                // {"hp=12", "atk=4", "def=1", "hit=0.7", "crit=0.2"}

                while (getline(split_stats, split_comma, ',')) {
                    m_stats.push_back(split_comma);
                }

                for (auto stat: m_stats) {
                    stringstream split_equal(stat);
                    string key, value;

                    getline(split_equal, key, '=');
                    getline(split_equal, value);

                    if (key == "HP") en.hp = stoi(value);
                    if (key == "CRIT") en.crit = stof(value);
                    if (key == "HIT") en.hit = stof(value);
                    if (key == "DEF") en.def = stoi(value);
                    if (key == "ATK") en.atk = stoi(value);
                }

                cout << "woah: "<< cat << endl;
                cout << "Who: "<< en.name << endl;
                cout << "Hp: "<< en.hp << endl;
                cout << "Atk: "<< en.atk << endl;
                cout << "def: "<< en.def << endl;
                cout << "hit: "<< en.hit << endl;
                cout << "critical: "<< en.crit << endl <<endl;
            }

        }
    }
    file_to_read.close();
}

typedef struct {
    string id, name, description;
    map<string, string> exits;
    string items, enemies;
}Room;
//id; name; desc; n; e; s; w; items; enemies

void FileIO::readRooms(string filename) {
    ifstream file(filename);
    string store;

    while (getline(file, store)) {
        if (!store.empty()) {
            Room r;
            stringstream first(store);
            string id, name, description, north, east, south, west, items, enemies;
            getline(first, id, ';');
            getline(first, name, ';');
            getline(first, description, ';');
            getline(first, north, ';');
            getline(first, east, ';');
            getline(first, south, ';');
            getline(first, west, ';');
            getline(first, items, ';');
            getline(first, enemies);

            r.name = name;
            r.id = id;
            r.description = description;

            if (north != " " && north != "") r.exits.insert({"n", north});
            if (east != " " && east != "") r.exits.insert({"e", east});
            if (south != " " && south != "") r.exits.insert({"s", south});
            if (west != " " && west != "") r.exits.insert({"w", west});
            if (enemies != " " && enemies != "") r.enemies = enemies;
            if (items != " " && items != "") r.items = items;

            cout << "ID: "<< r.id <<endl;
            cout << "name: "<< r.name <<endl;
            cout << "desc: "<< r.description <<endl;
            cout << "enemies: "<< r.enemies <<endl;
            cout << "items: "<< r.items <<endl;

            for (auto dir: r.exits) {
                cout << dir.first<<": "<< dir.second <<endl;
            }
            cout << endl;
        }
    }
}

