#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

//Iterative insertion sort
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int temp = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > temp) { /*Move values greater than current
        key to the right*/
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

//Recursive insertion sort
void recursiveInsertion(vector<int>& arr, int n) {
    if (n <= 1)
        return;
    recursiveInsertion(arr, n-1);/* Place the last element at correct position in sorted array*/
    int last = arr[n-1];
    int j = n-2;

    while (j >= 0 && arr[j] > last) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

int main() {
    int n;
    cout << "Numbers to read: ";
    cin >> n;
    cout << "Read: "<< n << endl;
    vector arr = {2,5,4,6,3,7,3,3,8,9,7,1};

    //insertionSort(arr);

    recursiveInsertion(arr, arr.size());
    for (auto i : arr){
        cout << i << ", ";
    }
    return 0;
}