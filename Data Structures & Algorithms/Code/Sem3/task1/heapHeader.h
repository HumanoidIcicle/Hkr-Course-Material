#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>


using namespace std; 

template <typename Function>
double Runtime(Function func, vector<int>& arr, int size) {
    LARGE_INTEGER freq, begin, stop;
    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&begin);
    func(arr, size); 
    QueryPerformanceCounter(&stop);

    double time_taken =
        static_cast<double>(stop.QuadPart - begin.QuadPart) / freq.QuadPart;
    //cout << "\nTime: " << time_taken << "\n\n";
    return time_taken;
}

template <typename Funct>
double Runtime(Funct func, vector<int>& arr, int val, int i) {
    LARGE_INTEGER freq, begin, stop;
    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&begin);
    func(arr, val, i); 
    QueryPerformanceCounter(&stop);

    double time_taken =
        static_cast<double>(stop.QuadPart - begin.QuadPart) / freq.QuadPart;
    //cout << "\nTime: " << time_taken << "\n\n";
    return time_taken;
}
void readFile(vector<int>& array, string filename, int limit) {
    string store_line;
    ifstream  file_to_read(filename);

    if (!file_to_read) {
        cerr << "Could not read file.\n";
        return;
    }
    for (int i = 0; i < limit; i++){
        getline(file_to_read, store_line);
        if (!store_line.empty()) {
            int value = stoi(store_line);
            array.push_back(value);
        }
    }
}

void heapifyDown(vector<int>& arr, int size, int i){
    int small = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left < size && arr[left] < arr[small]) small = left;
    
    if (right < size && arr[right] < arr[small]) small = right;
    
    if (small != i){ //if small changed, a child is lower than parent
        swap(arr[i], arr[small]); //swap them
        heapifyDown(arr, size, small); /*the swap can cause more heap violation,
        heapify that node*/
    }
}

void Insert(vector<int>& arr, int value, int i){ //inserts at the end
    arr.push_back(value);

    int current = i;
    
    while (current > 1 && arr[current/2] > arr[current]) {
        int temp = arr[current];
        arr[current] = arr[current/2];
        arr[current/2] = temp;

        current = current/2;
    };
}


void deleteMin(vector<int>& arr, int size){
    cout << "\nRemoved: " << arr[1];

    arr[1] = arr[size-1];
    arr.pop_back(); 
    size--;

    heapifyDown(arr, size, 1);
}
void levelorder(vector<int>& arr, int size){
    cout << "\nLevel-order:\n";
    for(int i = 1; i < size; i++){
        cout << arr[i] << ", ";
    }
} 

void ino(vector<int>& arr, int size, int i){
    if (i == 0 || i >= size ) return;
    ino (arr, size, 2*i);
    cout << arr[i] << ", ";
    ino (arr, size, 2*i + 1);
}
void inorder(vector<int>& arr, int size){
    cout << "\nIn-order:\n";
    ino(arr, size, 1);
}


void post(vector<int>& arr, int size, int i){
    if (i >= size || i == 0) return;
    post (arr, size, 2*i);
    post (arr, size, 2*i + 1);
    cout << arr[i] << ", ";
}
void postorder(vector<int>& arr, int size){
    cout << "\nPost-order:\n";
    post(arr, size, 1);
}

void pre(vector<int>& arr, int size, int i){
    if (i >= size || i == 0) return;
    cout << arr[i] << ", ";
    pre (arr, size, 2*i);
    pre (arr, size, 2*i + 1);
}
void preorder(vector<int>& arr, int size){
    cout << "\nPre-order:\n";
    pre(arr, size, 1);
}

void saveData(string t) {
    std::ofstream file("Dummy.txt", std::ios::app);

    if (!file.is_open()) {
        cout << "Problem opening file.\n";
    }
    file << t << endl;
    file.close();
}

void saveData(string t, double time) {
    std::ofstream file("Dummy.txt", std::ios::app);

    if (!file.is_open()) {
        cout << "Problem opening file.\n";
    }
    file << t << ": " << time << endl;
    file.close();
}
