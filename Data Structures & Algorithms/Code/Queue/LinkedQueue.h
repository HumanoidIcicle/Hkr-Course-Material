//
// Created by JOSS0001 on 15/02/2026.
//

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val): data(val), next(nullptr){}
};

class QueueLinked {
    Node * head;
public:
    QueueLinked(): head(nullptr){}
    ~QueueLinked() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    bool isEmpty() {
        return head == nullptr;
    }
    void Enqueue(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) current = current->next;
            current->next = newNode;
        }
    }
    void Dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty. Underflow.\n";
        }
        else{
            cout << "Front element dequeued: " << head->data <<endl;
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void Display() {
        if (head == nullptr) cout << "Linked Queue is empty.\n";
        else {
            Node* temp = head;
            while (temp) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};
#endif //LINKEDQUEUE_H
