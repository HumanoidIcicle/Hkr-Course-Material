//
// Created by JOSS0001 on 2025-11-25.
//

#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <iostream>
using namespace std;

class Shape {
protected:
    string colour;
public:
    virtual ~Shape() = default;
    explicit Shape(string c): colour(move(c)){}

    virtual double area() {
        return 3.14159;
    }
    virtual  void display(double area) {
        cout << "The Shape area is: " << area <<endl;
    }
};

//CIRCLE STUFF
class Circle final : public Shape {
protected:
    double radius;
public:
    Circle(double r, string c): Shape(move(c)), radius(r){}
    double area() override {
        return 2*3.14159*radius*radius;
    }
    void display(double area) override{
        cout << "\nThe Circle area is: " << area <<endl;
    }
};

//RECTANGLE STUFF
class Rect final :public Shape {
    double w, h;
public:
    Rect(double w, double h, string c): Shape(move(c)), w(w), h(h){}
    double area() override {
        return w*h;
    }
    void display(double area) override{
        cout << "\nThe Rectangle area is: " << area <<endl;
    }
};
#endif //SHAPES_H
