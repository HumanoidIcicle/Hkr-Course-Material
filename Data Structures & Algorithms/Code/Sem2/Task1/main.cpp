#include <iostream>
#include "queue1stack.h"
#include "queue2stacks.h"
#include "stack1queue.h"
#include "stack2queue.h"

using namespace std;
void queue2() {
    cout << "\nQueue using 2 stacks." << endl;
    cout << "=======================" << endl;
    Queue2 q(5);

    q.Dequeue();
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);

    q.Display();
    q.Dequeue();
    q.Display();
    cout << "=======================" << endl;
}
void queue1() {
    cout << "\nQueue using 1 stack." << endl;
    cout << "=======================" << endl;
    Queue1 q(5);

    q.Dequeue();
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);

    q.Display();
    q.Dequeue();
    q.Display();
    cout << "=======================" << endl;
}
void stack1() {
    cout << "\nStack using 1 queue." << endl;
    cout << "=======================" << endl;
    Stack1 q(5);
    q.pop();
    q.push(10);
    q.push(15);
    q.push(17);
    q.push(19);
    q.push(16);
    q.push(16);
    q.display();

    q.pop();
    q.display();
    cout << "=======================" << endl;
}
void stack2() {
    cout << "\nStack using 2 queues." << endl;
    cout << "=======================" << endl;
    Stack2 q(5);
    q.pop();
    q.push(10);
    q.push(15);
    q.push(17);
    q.push(19);
    q.push(16);
    q.push(16);
    q.display();
    q.pop();
    q.display();
    cout << "=======================" << endl;

}

int main() {
    queue1();
    queue2();
    stack2();
    stack1();

    return 0;
}
