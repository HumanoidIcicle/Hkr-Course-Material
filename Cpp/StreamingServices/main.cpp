#include <iostream>
#include <vector>
#include <algorithm>
#include "platform.h"

int main() {
    vector<StreamingService*> demo;
    demo.push_back(new Netflix("Netflix Platform", 12.99));
    demo.push_back(new Spotify("Spotify Music", 10.99));
    demo.push_back(new Disney("Disney Plus", 15.99));

    sort(demo.begin(), demo.end(),
        [](StreamingService* a, StreamingService* b) {
    return a->monthlyCost() < b->monthlyCost();
    });

    for (auto it: demo) {
        cout << it->getServiceName() << " - " << it->monthlyCost() << endl;
        it->playContent("The Boys");
    }
    return 0;
}
