//
// Created by JOSS0001 on 15/02/2026.
//
/*A queue using two stacks.*/

#ifndef QUEUE2STACKS_H
#define QUEUE2STACKS_H

#include <iostream>
#include "queue1stack.h"

using namespace std;

class Queue2 {
    ArrayStack stack1;
    ArrayStack stack2;
public:
    Queue2(int size): stack1(size), stack2(size){}

    void Enqueue(int value) {
        if (stack1.isFull()) {
            cout << "Full queue. Overflow.\n";
            return;
        }
        stack1.push(value);
    }
    void Dequeue() {
        if (stack1.isEmpty()) cout << "Queue underflow.\n";
        else{
            while (!stack1.isEmpty()){
                int temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
            cout << "Removed: " << stack2.top() << endl;
            stack2.pop();
            while (!stack2.isEmpty()){
                int temp = stack2.top();
                stack1.push(temp);
                stack2.pop();
            }
        }
    }
    void Display() {
        stack1.display();
    }
};
#endif //QUEUE2STACKS_H
