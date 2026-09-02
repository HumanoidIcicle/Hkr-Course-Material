#pragma once
#include <iostream>

using namespace std;

class node{
    public:
    int key, value;
    bool free;

    node(): free(true){}
    ~node() = default;
};

class hashMap{
    public:
    int size, count;
    node* arr;

    hashMap(int s): size(s), count(0), arr(new node[size]){}
    ~hashMap() = default;
    
    virtual void insert(int v) {};
    virtual void display() {};

    int hashFunction(int v){
        return v % size;
    }

    void rehash(int new_size){
        cout << "\nRehashed...";
        node* old = arr;
        arr = new node[new_size];
        
        for(int i = 0; i < new_size; i++)
            arr[i].free = true;
        
        // hashMap dummy(new_size);
        for (int i = 0; i < size; i++){
            if (!old[i].free) {
                insert(old[i].value);
            }
        }
        size = new_size;
        delete[] old;
    }
};

class linearMap : public hashMap{
    public:
    linearMap(int s): hashMap(s){}

    void insert(int v) override {
        int index = hashFunction(v);
        while (!arr[index].free) index = (index + 1) % size;
        arr[index].key = index;
        arr[index].value = v;
        arr[index].free = false;
    }
    void display() override {
        cout << "\nLinear probing:\n";
        for (int i = 0; i < size; i++){
            if (!arr[i].free) cout << "\t" << arr[i].key << ": " << arr[i].value << endl;
        }
    }
};

class quadMap : public hashMap{
    public:
    quadMap(int s): hashMap(s){}

    void insert(int v) override {
        int index = hashFunction(v);
        int i = 1;
        while (!arr[index].free) {
            index = (index + i*i) % size;
            i++;
        }
        arr[index].key = index;
        arr[index].value = v;
        arr[index].free = false;
    }
    void display() override {
        cout << "\nQuadratic probing:\n";
        for (int i = 0; i < size; i++){
            if (!arr[i].free) cout << "\t" << arr[i].key << ": " << arr[i].value << endl;
        }
    }
};

