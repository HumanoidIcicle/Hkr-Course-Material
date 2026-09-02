#include <iostream>
#include "ArrayStack.h"
#include "LinkedStack.h"

void toBinary() {
    ArrayStack<int> stack(10);
    int num;
    cout << "Enter a num: ";
    cin >> num;

    while (num > 0){
        int bit = num % 2;
        if (stack.isFull()) throw "Stack overflow.";
        stack.push(bit);
        num = floor(num/2);
    }
    while (!stack.isEMpty())
        cout << stack.topAndPop();
}
void runLinked() {
    LinkedStack arr(1);
    arr.display();
    arr.pop();
    arr.push(56);
    arr.display();
    arr.push(6);
    arr.pop();
    arr.push(5);
    arr.display();
}

int main() {
    //toBinary();
    runLinked();
    return 0;
}
