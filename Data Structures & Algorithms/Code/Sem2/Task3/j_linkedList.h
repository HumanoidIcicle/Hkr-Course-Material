//
// Created by JOSS0001 on 16/02/2026.
//

#ifndef J_LINKEDLIST_H
#define J_LINKEDLIST_H

//My own linked list
#include <iostream>

class Node2 {
public:
    int index;
    Node2* next;

    Node2(int val): index(val), next(nullptr){}
};

class LinkedList {
public:
    Node2* head;
    int size;

    LinkedList():head(nullptr), size(0){}

    ~LinkedList() {
        Node2* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int value) {
        Node2* newNode = new Node2(value);
        if (head == nullptr) head = newNode;

        else{
            Node2* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    void remove(int p) {
        if (head == nullptr) std::cout << "Address book is empty.\n";

        else if (head->index == p) {
            std::cout << "Removed: " << head->index << std::endl;
            Node2* del = head;
            head = head->next;
            size--;
            delete del;
        }

        else {
            Node2* temp = head;
            while (temp->next != nullptr && temp->next->index != p)
                temp = temp->next;

            if (temp->next != nullptr) {
                Node2* toDel = temp->next;
                std::cout << "Removed: " << toDel->index << std::endl;
                temp->next = toDel->next;
                size--;
                delete toDel;
            }
            else std::cout << "Person not in address book.\n";
        }
    }
};

void josephus_my_list(int n, int m) {
    LinkedList people;

    if (n <= 1) {
        std::cout << "Left standing: Person " << n << std::endl;
        return;
    }

    for (int i = 1; i <= n; i++) people.add(i);

    Node2* temp = people.head;

    while (people.size > 1) {
        for (int i = 0; i < m; i++) {
            temp = temp->next;
            if (temp == nullptr) temp = people.head;
        }
        int removed = temp->index;

        temp = temp->next;
        if (temp == nullptr) temp = people.head;

        people.remove(removed);
    }
    std::cout << "Person " << people.head->index
            << " left standing." << std::endl;
}

#endif //J_LINKEDLIST_H
