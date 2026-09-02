//
// Created by JOSS0001 on 17/02/2026.
//

#ifndef ARRAYLIST_VECTOR_H
#define ARRAYLIST_VECTOR_H

//Arraylist -> vector in C++

#include <iostream>
#include <vector>

class Node {
public:
    int position;
    Node(int p): position(p){}
};

void josephus_Arraylist(int n_people, int m_passes) {
    std::vector<Node*> people;

    for (int i = 1; i <= n_people; i++) {
        Node* create = new Node(i);
        people.push_back(create);
    }

    int index = 0;

    while (people.size() > 1) {
        index = (index + m_passes) % people.size();

        std::cout << "Removed: "
                << people.at(index)->position
                << std::endl;

        delete people.at(index);
        people.erase(people.begin() + index);
    }
    std::cout << "Person "
            << people.at(0)->position
            << " left standing."
            << std::endl;

    delete people.at(0);
}

#endif //ARRAYLIST_VECTOR_H
