//
// Created by JOSS0001 on 2025-11-26.
//

#ifndef PARTS_H
#define PARTS_H

#include <iostream>
#include <string>
using namespace std;

class Engine {
protected:
    string type;
    int horsepower;
public:
    virtual ~Engine() = default;
    Engine(string type, int horse): type(move(type)), horsepower(horse){}
    void start(){cout << "Engine started...\n";}

    void getEng() {
        cout << "An unbelievable " << type << " engine with " << horsepower << " horsepower.\n";
    }

};

class Wheel {
protected:
    string type;
    float size;
public:
    virtual ~Wheel() = default;
    Wheel(string type, float size): type(move(type)), size(size){}

    void getWheel() {
        cout << "\nWith a " << type << " wheel " << size << "cm across.\n";
    }
};

class Transmission final {
    string type;
    int gears;
public:
    ~Transmission() = default;
    Transmission(string type, int gears): type(move(type)), gears(gears){}

    string getType()const {
        return type;
    }
    int getGears() const{
        return gears;
    }
    void getWheel() {
        cout << "And a " << type << " transmission with " << gears << " gears.\n";
    }

};

class Car {
    Engine& engine;
    Wheel& wheel;
    Transmission& trans;

public:
    Car(Engine& eng, Wheel& wheel, Transmission& tran)
        :engine(eng), wheel(wheel), trans(tran){}

    void startCar() {
        cout << "\nThis car will change your life. Here's a preview ==>" <<endl;
        engine.start();
    }
    void specs() {
        wheel.getWheel();
        engine.getEng();
        trans.getWheel();
    }

};
#endif //PARTS_H
