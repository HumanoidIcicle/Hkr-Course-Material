#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <windows.h>

using namespace std;

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
void saveData(auto time) {
    std::ofstream file("Record.txt", std::ios::app);

    if (!file.is_open()) {
        cout << "Problem opening file.\n";
    }
    file << time << endl;
    file.close();
}

//Quicksort first element
int partition1(vector<int>& arr, int start, int end) {
    int pivot = arr[start];
    int i = end + 1;
    for (int j = end; j > start; j--) {
        if (arr[j] > pivot) {
            i--;
            swap(arr[i], arr[j]);
        }
    }
    i--;
    swap(arr[i],arr[start]);
    return i;
}
void recursiveQuickFirst(vector<int>& arr, int start, int end) {
    if (start >= end) return; //base cas

    int pivot = partition1(arr, start, end);
    recursiveQuickFirst(arr, start, pivot-1);
    recursiveQuickFirst(arr, pivot+1, end);
}

int main() {

    return 0;
}