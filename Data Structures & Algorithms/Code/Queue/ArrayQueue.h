//
// Created by JOSS0001 on 15/02/2026.
//

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>
using namespace std;

template <typename T>
class Queue {
    int size;
    int capacity;
    T* arr;
    int front;
    int back;

public:
    Queue(int size) {
        arr = new T[size];
        capacity = size;
        front = 0;
        back = -1;
        this->size = 0;
    }

    void Enqueue(T value) { //Add element to back
        if (size == capacity) cout << "Queue is full." << endl;
        else {
            back++;
            arr[back] = value;
            size++;
        }
    }
    void Dequeue() { //Remove front element
        if (isEmpty()) {
            cout << "\nQueue is empty." << endl;
            return;
        }
        cout << "\nFront element dequeued: " << arr[front] << endl;
        //size;
        front++;
    }
    void Display() { //Print list
        for (int i = front; i < size; i++) cout << arr[i] << ", ";
    }
    bool isEmpty() {
        return size == 0;
    }
};
#endif //ARRAYQUEUE_H
