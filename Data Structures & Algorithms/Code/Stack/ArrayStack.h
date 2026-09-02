//
// Created by JOSS0001 on 15/02/2026.
//

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>
#include <math.h>
using namespace std;

/*Array implementation*/
template <typename Anytype>
class ArrayStack {
    int size;
    Anytype* myArray;
    int topOfStack = -1;
public:
    ArrayStack(int size): size(size) {
        myArray = new Anytype[size];
    }
    ~ArrayStack() {
        delete[] myArray;
    }
    void push(Anytype x){//Insert x
        topOfStack++;
        if (!isFull()) myArray[topOfStack] = x;
    }
    Anytype top(){//Remove top element
        if (isEMpty()) throw "ArrayStack is empty.";
        return myArray.at(topOfStack);
    }
    void pop(){//Remove top element
        if (isEMpty()) throw "ArrayStack pop.";
        topOfStack--;
    }
    void makeEmpty(){//Remove all elements
        topOfStack = -1;
    }
    bool isEMpty(){//True-stack is empty, false else
        return topOfStack == -1;
    }
    bool isFull(){//True-stack is empty, false else
        return topOfStack == size-1;
    }
    Anytype topAndPop(){//return and remove top element
        if (isEMpty()) throw "Stack is empty.";
        return myArray[topOfStack--];
    }
};

#endif //ARRAYSTACK_H
