//
// Created by JOSS0001 on 2025-12-03.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Item {
protected:
    int value = 0;
    string id;
    string name;
    string type;
public:
    ~Item() = default;
    Item(string name, string id, string type);

    void setValue();
    void itemInfo() const;

    int getValue() const {return value;}
    string getName() const {return name;}
    string getId() const {return id;}
    string getType() const {return type;}

};
#endif //ITEM_H
