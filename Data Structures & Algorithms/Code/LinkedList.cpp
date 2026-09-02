#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val): data(val), next(nullptr){}
};

class LinkedList {
    Node* head;
public:
    LinkedList():head(nullptr){}
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) head = newNode; //if head is null, make new node head

        else{
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next; //traverse to last node
            temp->next = newNode; //add new node at the end
        }
    }
    void removeByValue(int value) {
        if (head == nullptr) return;
        if (head->data == value) { //if head has the value
            Node* temp = head;
            head = head->next; //Move head to next node
            delete temp; //Free memory of deleted node
            return;
        }
        Node* current = head;
        while (current->next != nullptr /*Check if the next node after current hold the value,
            current always holds node before*/
            && current->next->data != value) current = current->next;
        /*Check why loop ended*/
        if (current->next != nullptr) {
            Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        }
    }
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList myList;
    myList.insert(12);
    myList.insert(11);
    myList.insert(13);
    myList.insert(15);
    myList.insert(10);
    myList.displayList();
    myList.removeByValue(15);
    myList.displayList();

    return 0;
}
