//
// Created by JOSS0001 on 15/02/2026.
//

#pragma once 

#include <iostream>
#include <string>

using namespace std;
class Node {
public:
    string name;
    string address;
    int index;
    Node* next;

    Node(string name, string add, int index)
        : name(name), address(add),
        index(index),
        next(nullptr){}
};

class AddressBook {
    Node* head;
    int index = 0;

public:
    AddressBook(): head(nullptr){}
    ~AddressBook() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(string name, string add) {
        Node* newPerson = new Node(name, add, index);
        cout << "Added: " << newPerson->name << endl;
        Node* temp = head;
        head = newPerson;
        head->next = temp;
        index++;
    }
    void remove(string name) {
        if (head == nullptr) cout << "Address book is empty.\n";
        else if (head->name == name) {
            cout << "Removed: " << head->name << endl;
            Node* del = head;
            head = head->next;
            delete del;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->name != name) temp = temp->next;
            if (temp->next != nullptr) {
                Node* toDel = temp->next;
                cout << "Removed: " << toDel->name << endl;
                temp->next = toDel->next;
                delete toDel;
            }
            else cout << "Person not in address book.\n";
        }
    }
    void getByIndex(int who) {
        cout << "Searching for " << who << "...\n";
        if (head == nullptr) cout << "Address book is empty.\n";
        else if (head->index == who) {
            details(head);
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->index != who) temp = temp->next;
            if (temp->next != nullptr) {
                cout << "Found: \n";
                details(temp);
            }
            else cout << "Not found in address book.\n";
        }
    }
    void Display() {
        Node* temp = head;
        cout << "\nADDRESS BOOK: " << endl;
        while (temp) {
            details(temp);
            temp = temp->next;
        }
    }
    void details(Node* node) {
        cout << "    Idex: " << node->index << endl
            << "    Name: " << node->name << endl
            << "    Address: " << node->address << endl << endl;
    }
};
