//
// Created by JOSS0001 on 16/02/2026.
//

#ifndef J_STL_LIST_H
#define J_STL_LIST_H

//Linked List with iterator -> STL list in C++

#include <iostream>
#include <list>

void josephus_stl_list(int n_people, int m_passes) {
    std::list<int> people;

    for (int i = 1; i <= n_people; i++) people.push_back(i);
    
    auto itr = people.begin();

    while (people.size() > 1){
        for (int i = 0; i < m_passes; i++) {
            ++itr;
            if (itr == people.end()) itr = people.begin();
        }
        std::cout << "Removed: " << *itr << std::endl;
        itr = people.erase(itr);

        if (itr == people.end()) itr = people.begin();
    }
    std::cout << "Person " << *itr << " left standing."
            << std::endl;
}

#endif //J_STL_LIST_H
