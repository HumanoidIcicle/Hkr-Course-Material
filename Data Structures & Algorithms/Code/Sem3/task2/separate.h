#pragma once
#include <iostream>

using namespace std;

class Node{
    public:
    int key;
    int value;
    Node* next;

    Node(int val, int k): value(val), key(k), next(nullptr){}
};

class chainMap{
    public:
    int numElements, size;
    Node** arr;

    chainMap(int s): numElements(0), size(s), arr(new Node*[size]){
        for (int i = 0; i < size; i++) arr[i] = nullptr;
    }

    int hashFunction(int k){
        return k % size;
    }

    void insert(int val){
        int index = hashFunction(val);
        Node* newNode = new Node(val, index);
        
        if (numElements < size){
            if (arr[index] == nullptr) arr[index] = newNode;
            else {
                newNode->next = arr[index];
                arr[index] = newNode;
    
                numElements++;
            }
        }
        else cout << "Hash map full\n";
    }

    void display(){
        cout << "\nSeparate chaining:\n";
        for (int index = 0; index < size; index++){
            if (arr[index] != nullptr) {
                Node* temp = arr[index];
                while (temp){
                    cout << "\t" <<temp->key << ": " << temp->value << endl;
                    temp = temp->next;
                }    
            }
        } 
    }
    
    void rehash(int new_size){
        cout << "\nRehashed...";
        chainMap newHash(new_size);
        for (int i = 0; i < size; i++){
            if (arr[i] != nullptr){
                Node* temp = arr[i];
                while (temp){
                    newHash.insert(temp->value);
                    //cout <<"Added " << temp->key << ": " << temp->value << endl;
                    temp = temp->next;
                }
            }
        }
        arr = newHash.arr;
        size = new_size;
    }
};

