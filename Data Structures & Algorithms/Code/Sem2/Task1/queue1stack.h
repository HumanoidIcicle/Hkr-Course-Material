//
// Created by JOSS0001 on 15/02/2026.
//
/* A queue using one stack.*/

#ifndef QUEUE1STACK_H
#define QUEUE1STACK_H

#include <iostream>
using namespace std;

class ArrayStack {
    int size;
    int* arr;
    int topOfStack = -1;
public:
    ArrayStack(int size): size(size) {
        arr = new int[size];
    }
    ~ArrayStack() {
        delete[] arr;
    }
    void push(int x){
        if (isFull()) cout << "Stack overflow.\n";
        else{
            topOfStack++;
            arr[topOfStack] = x;
        }
    }
    int top(){//Get top element
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return arr[topOfStack];
    }
    void pop(){//Remove top element
        if (isEmpty()) cout << "Stack underflow.\n";
        else topOfStack--;
    }
    bool isEmpty(){
        return topOfStack == -1;
    }
    bool isFull(){
        return topOfStack == size - 1;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        for (int i = topOfStack; i >= 0; i--) {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
};

class Queue1 {
    ArrayStack mystack;
public:
    Queue1(int size): mystack(size){}

    void Enqueue (int value) {
        if (mystack.isFull()) {
            cout << "Full queue. Overflow.\n";
            return;
        }
        mystack.push(value);
    }
    int Dequeue() {
        if (mystack.isEmpty()) {
            cout << "Empty queue. Underflow.\n";
            return -1;
        }
        int temp = mystack.top();
        mystack.pop();
        if (mystack.isEmpty()) {
            cout << "Removed: " << temp << endl;
            return temp;
        }
        int hold = Dequeue();
        mystack.push(temp);
        return hold;
    }
    void Display() {
        mystack.display();
    }
};
#endif //QUEUE1STACK_H
