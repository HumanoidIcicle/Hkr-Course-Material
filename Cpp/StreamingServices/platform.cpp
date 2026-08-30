//
// Created by JOSS0001 on 2026-01-07.
//

#include "platform.h"
#include <iostream>

using namespace std;
BaseStreamingService::BaseStreamingService(string name, double cost)
    : serviceName(move(name)), cost(move(cost)){}
double BaseStreamingService::monthlyCost() {
    return cost;
}
string BaseStreamingService::getServiceName() {
    return serviceName;
}

Netflix::Netflix(string Name, double cost)
    : BaseStreamingService(Name, cost){}

void Netflix::playContent(string title) {
    cout << "Welcome to Netflix Streaming Service." << endl;
    cout << "Now Playing: " << title << endl << endl;
}

Spotify::Spotify(string Name, double cost)
    : BaseStreamingService(Name, cost){}

void Spotify::playContent(string title) {
    cout << "Welcome to Spotify Music Service." << endl;
    cout << "Now Playing: " << title << endl << endl;
}

Disney::Disney(string Name, double cost)
    : BaseStreamingService(Name, cost){}

void Disney::playContent(string title) {
    cout << "Welcome to Disney Plus Streaming." << endl;
    cout << "Now Playing: " << title << endl << endl;
}



