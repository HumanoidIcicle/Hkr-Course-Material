#include <iostream>
#include "separate.h"
#include "probing.h"

#define HASH_SIZE 10

using namespace std;


int main(){
    int inputs[] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
    chainMap m1(HASH_SIZE);
    linearMap m2(HASH_SIZE);
    quadMap m3(HASH_SIZE);

    for (int x : inputs){
        m1.insert(x);
        m2.insert(x);
        m3.insert(x);
    }
    // m1.insert(2);
    // m2.insert(2);
    // m3.insert(2);
    // m1.insert(10);
    // m2.insert(10);
    // m3.insert(10);
    
    m1.display();
    m2.display();
    m3.display();
    
    m1.rehash(20);
    m2.rehash(20);
    m3.rehash(20);
    
    m1.display();
    m2.display();
    m3.display();


    return 0;
}