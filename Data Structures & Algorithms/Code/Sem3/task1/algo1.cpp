#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include "heapHeader.h"
#include <array>

// 10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2 
using namespace std;

int main(){
    //cout << "Enter n value: ";
    //cin >> size;
    //readFile(arr0, "numbers.txt", size);
    
    saveData("\n================== Algorithm 1 ==================");
    
    //int limits[] = {10, 100, 1000, 10000, 100000, 250000, 500000, 750000, 1000000};
    int limits[] = {2, 4, 6, 8, 9, 10, 3, 5, 7};
    
    for (int k = 0; k < 9; k++){
        int size = limits[k];
        int actSize = size+1;
        vector<int> arr0;
        readFile(arr0, "numbers.txt", size);
        
        vector<int> arr;
        arr.push_back(0);

        int i = 1;
        LARGE_INTEGER freq, begin, stop;
        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&begin);
        
        //Manually get the time for all single insertions
        for (int j = 0; j < size; j++){
            Insert(arr, arr0[j], arr.size());
            i++;
        }
        QueryPerformanceCounter(&stop);

        double time_taken =
            static_cast<double>(stop.QuadPart - begin.QuadPart) / freq.QuadPart;
        cout << "\nTime: " << time_taken << "\n\n";
        
        saveData("\nInput: " + to_string(size) + ": " + to_string(time_taken)); 
        
        levelorder(arr, actSize);
        // preorder(arr, actSize);
        // inorder(arr, actSize); 
        // postorder(arr, actSize);
        saveData("Insert: ", Runtime(Insert, arr, 100, arr.size()));
        saveData("Delete: ", Runtime(deleteMin, arr, actSize));
        //levelorder(arr, actSize);
    }

    return 0;
}