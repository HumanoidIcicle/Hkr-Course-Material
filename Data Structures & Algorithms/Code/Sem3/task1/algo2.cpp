#include <iostream>
#include "heapHeader.h"
#include <array>

/*
For an element at index **k**, its ;
- left child is at index ***2k***
- Right child is at index ***2k + 1***
- Parent of the element is at index ***k/2***
*/

// 10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2 
using namespace std;


void runLinear(vector<int>& arr, int size){
    for (int i = size/2; i >= 1; i--) 
        heapifyDown(arr, size, i);
}
int main(){
    int size;
    //cout << "Enter n value: ";
    //cin >> size;

    saveData("\n================== Algorithm 2 ==================");
    int limits[] = {10, 100, 1000, 10000, 100000, 250000, 500000, 750000, 1000000};
    //int limits[] = {2, 4, 6, 8, 9, 10, 3, 5, 7};
    
    for (int k = 0; k < 9; k++){
        size = limits[k];
        int actSize = size+1;

        vector<int> arr;
        arr.push_back(0);

        readFile(arr, "numbers.txt", size);

        saveData("\nInput " + to_string(size)+ ": ", Runtime(runLinear, arr, actSize)); //Algo2
        levelorder(arr, actSize);
        //preorder(arr, actSize);
        //inorder(arr, actSize); 
        //postorder(arr, actSize);
        saveData("Insert: ", Runtime(Insert, arr, 100, arr.size()));
        saveData("Delete: ", Runtime(deleteMin, arr, actSize));
        //levelorder(arr, actSize);
    }


    return 0;
}