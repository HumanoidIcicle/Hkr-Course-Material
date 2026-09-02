//
// Created by JOSS0001 on 15/02/2026.
//
/*A stack using two queues.*/

#pragma once

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val): data(val), next(nullptr){}
};

class Linked {
public:
    int size;
    int capacity;
    Node* head;

    Linked(int s): size(0), capacity(s), head(nullptr){}
    ~Linked() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) head = newNode;
        else if (size < capacity){
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
        size++;
    }
    int dequeue() {
        if (isEmpty()) return -1;

        Node* temp = head;
        head = head->next;
        size--;
        int value = temp->data;
        delete temp;
        return value;
    }
    bool isEmpty() {
        return head == nullptr;
    }
    bool isFull() {
        return size == capacity;
    }
    Node* getTail() {
        if (isEmpty()) return nullptr;

        if (head->next == nullptr) {
            Node* tail = head;
            head = nullptr;
            size--;
            return tail;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        Node* tail = temp->next;
        temp->next = nullptr;
        size--;
        return tail;
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data <<" -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

class Stack2 {
    Linked q1;
    Linked q2;

public:
    Stack2(int size): q1(size), q2(size){}

    void push(int v) {
        if (q1.isFull()) {
            cout << "Full stack. Overflow.\n";
            return;
        }
        q1.enqueue(v);
    }
    void display() {
        q1.display();
    }
    void pop() {
        if (q1.isEmpty()) {
            cout << "Empty stack. Underflow.\n";
            return;
        }
        while (!q1.isEmpty()) {
            Node* temp = q1.getTail();
            q2.enqueue(temp->data);
            delete temp;
        }

        int x = q2.dequeue();
        cout << "Removed: " << x << endl;

        while (!q2.isEmpty()) {
            Node* temp = q2.getTail();
            q1.enqueue(temp->data);
            delete temp;
        }
    }
};

