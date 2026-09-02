//
// Created by JOSS0001 on 15/02/2026.
//
/*A stack using one queue.*/

#ifndef STACK1QUEUE_H
#define STACK1QUEUE_H

#include <iostream>
#include "stack2queue.h"

class Stack1 {
    Linked q;

public:
    Stack1(int size): q(size){}

    void pop() {
        if (q.isEmpty()) {
            cout << "Empty stack. Underflow.\n";
            return;
        }
        cout << "Removed: " << q.dequeue() << endl;
    }
    void display() {
        q.display();
    }
    void push(int x) {
        if (q.isFull()) {
            cout << "Full stack. Overflow.\n";
            return;
        }
        q.enqueue(x);

        int count = q.size -1;
        while (count) {
            int hold = q.dequeue();
            q.enqueue(hold);
            count--;
        }
    }
};
#endif //STACK1QUEUE_H
