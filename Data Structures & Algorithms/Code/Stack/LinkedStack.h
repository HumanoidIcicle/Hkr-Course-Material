//
// Created by JOSS0001 on 15/02/2026.
//

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value): data(value), next(nullptr){}
};

class LinkedStack {
    int size = 0;
    int capacity;
    Node* topOfStack;
public:
    LinkedStack(int size):capacity(size), topOfStack(nullptr){}
    ~LinkedStack() {
        Node* temp;
        while (topOfStack) {
            temp = topOfStack;
            topOfStack = topOfStack->next;
            delete temp;
        }
    }
    void push(int val) {
        if (size < capacity){
            Node* newNode = new Node(val);
            Node* temp = topOfStack;
            topOfStack = newNode;
            newNode->next = temp;
            size++;
        }
        else cout << "Stack overflow.\n";
    }
    void pop() {
        if (topOfStack == nullptr) {
            cout << "Stack underflow.\n";
            return;
        }
        cout << "Popped from stack: " << topOfStack->data << endl;
        Node* temp = topOfStack;
        topOfStack = topOfStack->next;
        delete temp;
        size--;
    }
    void display() {
        Node* temp = topOfStack;
        cout << "TOP -> " ;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
#endif //LINKEDSTACK_H
