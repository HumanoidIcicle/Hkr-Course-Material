#include <iostream>
#include "ArrayQueue.h"
#include "LinkedQueue.h"
using namespace std;

int main() {

    cout << "Array: \n";
    Queue<int> arr(5);
    arr.Enqueue(3);
    arr.Enqueue(2);
    arr.Enqueue(1);
    arr.Display();
    arr.Dequeue();
    arr.Display();

    cout << "\nLinked: \n";
    QueueLinked ar;
    ar.Enqueue(3);
    ar.Enqueue(2);
    ar.Enqueue(1);
    ar.Display();
    ar.Dequeue();
    ar.Display();
    return 0;
}
