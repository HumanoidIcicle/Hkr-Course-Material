//
// Created by JOSS0001 on 2025-11-25.
//

#ifndef COMPUTERSYSTEM_H
#define COMPUTERSYSTEM_H

#include <string>
#include <iostream>
using namespace std;

class CPU {
    string model;
    int speed;
public:
    CPU(string model, int speed): model(move(model)), speed(speed){}
    string getModel() const {
        return model;
    }
    int getSpeed() const {
        return speed;
    }
};

class RAM {
    int capacity;
    string type;
public:
    RAM(string type,int cap): capacity(cap), type(move(type)){}

    string getType() const { return type; }
    int getCapacity() const { return capacity; }
};

class Storage{
    int capacity;
    string type;
public:
    Storage(string type, int cap): type(move(type)),capacity(cap){}

    // Add getter methods
    string getType() const { return type; }
    int getCapacity() const { return capacity; }
};

//THE COMPOSITOR
class Computer {
    string model;
    CPU cpu;
    RAM ram;
    Storage storage;
public:
    Computer(string comp_model,string model, int speed, string rtype,
        int ramsize, string stype, int storesize)
    :model(move(comp_model)),
    cpu(move(model), speed),
    ram(move(rtype), ramsize),
    storage(move(stype), storesize){}

    void specs() const {
        cout <<"\n=============================================\n";
        cout << "Computer model: " << model << endl;
        cout << "CPU model: " << cpu.getModel() << endl;
        cout << "CPU Speed: " << cpu.getSpeed() << " GHz" << endl;
        cout << "RAM type: " << ram.getType() << endl;
        cout << "RAM size: " << ram.getCapacity() << " GB" << endl;
        cout << "Storage type: " << storage.getType() << endl;
        cout << "Storage size: " << storage.getCapacity() << " GB" << endl;
        cout <<"\n=============================================\n";

    }
};
#endif //COMPUTERSYSTEM_H
