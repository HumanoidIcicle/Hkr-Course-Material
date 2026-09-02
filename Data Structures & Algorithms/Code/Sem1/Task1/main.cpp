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

template <typename Function>
double Runtime(Function func, vector<int>& arr) {
    LARGE_INTEGER freq, begin, stop;
    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&begin);
    func(arr);//Replace with functinon to measure on
    QueryPerformanceCounter(&stop);

    double time_taken =
        static_cast<double>(stop.QuadPart - begin.QuadPart) / freq.QuadPart;
    cout << "\nTime taken: "<< time_taken << " seconds\n";

    return time_taken;
}

template <typename Function>
double average(Function func, int iterations) {
    double sum = 0;
    for (int i = 0; i < iterations; i++) {
        sum += func();
    }
    double avg = sum/iterations;
    cout << "========================================\n";
    return avg; 

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
    //for (auto i : arr) cout << i <<", ";
}
void iterativeQuickFirst(vector<int>& arr, int start, int end) {
    stack<pair<int, int>> mock;
    mock.push({start, end}); //Store low and high values.

    while (!mock.empty()) {
        auto [low, high] = mock.top();
        mock.pop();
        if (low < high) {
            int pivot = partition1(arr, low, high);

            if (low < pivot-1)
                mock.push({low, pivot-1});

            if (pivot+1 < high)
                mock.push({pivot+1, high});
        }
    }
}

//Quicksort median of three
int medianOfThree(vector<int>& arr, int start, int end) {
    int mid = start + (end - start) / 2;

    // Sort arr[start], arr[mid], arr[end] to find median
    if (arr[start] > arr[mid])
        swap(arr[start], arr[mid]);
    if (arr[start] > arr[end])
        swap(arr[start], arr[end]);
    if (arr[mid] > arr[end])
        swap(arr[mid], arr[end]);

    // Now arr[mid] is the median, swap it with arr[start]
    swap(arr[mid], arr[start]);
    return arr[start];
}
int partition2(vector<int>& arr, int start, int end) {
    int pivot = medianOfThree(arr, start, end);
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
void recursiveQuickMedian(vector<int>& arr, int start, int end) {
    if (start >= end) return; //base cas

    int pivot = partition2(arr, start, end);
    recursiveQuickMedian(arr, start, pivot-1);
    recursiveQuickMedian(arr, pivot+1, end);
}
void iterativeQuickMedian(vector<int>& arr, int start, int end) {
    stack<pair<int, int>> mock;
    mock.push({start, end}); //Store low and high values.

    while (!mock.empty()) {
        auto [low, high] = mock.top();
        mock.pop();
        if (low < high) {
            int pivot = partition2(arr, low, high);

            if (low < pivot-1)
                mock.push({low, pivot-1});

            if (pivot+1 < high)
                mock.push({pivot+1, high});
        }
    }
}

//Quicksort random element
int partition3(vector<int>& arr, int start, int end) {
    int randomIndex = start + rand() % (end - start + 1);
    swap(arr[randomIndex], arr[start]);  // Move random pivot to start

    int pivot = arr[start];
    //cout << "\nPivot now; "<< pivot << endl;

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
void recursiveQuickRandom(vector<int>& arr, int start, int end) {
    if (start >= end) return; //base cas

    int pivot = partition3(arr, start, end);
    recursiveQuickRandom(arr, start, pivot-1);
    recursiveQuickRandom(arr, pivot+1, end);
}
void iterativeQuickRandom(vector<int>& arr, int start, int end) {
    stack<pair<int, int>> mock;
    mock.push({start, end}); //Store low and high values.

    while (!mock.empty()) {
        auto [low, high] = mock.top();
        mock.pop();
        if (low < high) {
            int pivot = partition3(arr, low, high);

            if (low < pivot-1)
                mock.push({low, pivot-1});

            if (pivot+1 < high)
                mock.push({pivot+1, high});
        }
    }
}

//Insertion sort
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
void iterativeInsertion(vector<int>& arr) {
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

//The binary search algorithm
bool iterativeBinary(int n, vector<int>& arr, int start, int end) {
    int s = start;
    int e = end;

    while (s <= e) {
        int middle = (s + e)/2;
        if (arr[middle] == n) return true;

        if (arr[middle] > n) e = middle-1;

        if (arr[middle] < n) s = middle+1;
    }
    return false;
}
bool recursiveBinary(int n, vector<int>& arr, int start, int end) {
    if (start > end) return false;

    int middle = (start+end)/2;
    if (arr[middle] == n) return true;

    if (arr[middle] > n)
        recursiveBinary(n, arr, start, middle-1);
    if (arr[middle] < n)
        recursiveBinary(n, arr, middle+1, end);
    return false;
}


int main() {
    srand(time(NULL));
    vector<int> original;
    int iterations = 10;
    int limit;
    cout <<"Enter value of N: ";
    cin >> limit;

    readFile(original, "numbers.txt", limit);
    auto arr = original;
    double avg = 0;

    //cout <<"\nOriginal: ";
    //for (auto it:arr) cout << it << ", ";

    saveData("\n------N is: ");
    saveData(limit);

    saveData("recursiveQuickFirst:");
    avg = average([&arr]()->double {
        return Runtime([](vector<int> arr) {
            recursiveQuickFirst(arr, 0, arr.size()-1);
        }, arr);
    }, iterations);
    saveData(avg);

    arr = original;
    saveData("recursiveQuickMedian:");
    avg = average([&arr]()->double {
        return Runtime([](vector<int> arr) {
            recursiveQuickMedian(arr, 0, arr.size()-1);
        }, arr);
    }, iterations);
    saveData(avg);

    arr = original;
    saveData("recursiveQuickRandom:");
    avg = average([&arr]()->double {
        return Runtime([](vector<int> arr) {
            recursiveQuickRandom(arr, 0, arr.size()-1);
        }, arr);
    }, iterations);
    saveData(avg);

    arr = original;
    saveData("IterativeQuickFirst:");
    avg = average([&arr]()->double {
        return Runtime([](vector<int> arr) {
            iterativeQuickFirst(arr, 0, arr.size()-1);
        }, arr);
    }, iterations);
    saveData(avg);

    arr = original;
    saveData("IterativeQuickRandom:");
    avg = average([&arr]()->double {
        return Runtime([](vector<int> arr) {
            iterativeQuickRandom(arr, 0, arr.size()-1);
        }, arr);
    }, iterations);
    saveData(avg);

    arr = original;
    saveData("IterativeQuickMedian:");
    avg = average([&arr]()->double {
        return Runtime([](vector<int> arr) {
            recursiveQuickMedian(arr, 0, arr.size()-1);
        }, arr);
    }, iterations);
    saveData(avg);

    arr = original;
    saveData("IterativeInsertion:");
    avg = average([&arr]()->double {
        return Runtime([](vector<int> arr) {
            iterativeInsertion(arr);
        }, arr);
    }, iterations);
    saveData(avg);

    arr = original;
    saveData("RecursiveInsertion:");
    //saveData("-");

    if (limit < 20000){
        arr = original;
        avg = average([&arr, limit]()->double {
            return Runtime([limit](vector<int> arr) {
                recursiveInsertion(arr, limit);
            }, arr);
        }, iterations);
        saveData(avg);
    }

    arr = original;
    //cout <<"\nSorted: ";
    recursiveQuickFirst(arr, 0, arr.size()-1);
    //for (auto it:arr) cout << it << ", ";

    saveData("recursiveBinary:");
    int num;
    cout << "\nSearch a number: ";
    cin >> num;
    avg = average([&arr, num]()->double {
        return Runtime([num](vector<int>& arr2) {
            iterativeBinary(num, arr2, 0, arr2.size()-1);
        }, arr);
    }, iterations);
    saveData(avg);

    if (iterativeBinary(num, arr, 0, arr.size()-1)) cout << "Found.\n";
    else cout << "Not found.\n";

    saveData("IterativeBinary:");
    avg = average([&arr, num]()->double {
        return Runtime([num](vector<int>& arr2) {
            iterativeBinary(num, arr2, 0, arr2.size()-1);
        }, arr);
    }, iterations);
    saveData(avg);

    if (iterativeBinary(num, arr, 0, arr.size()-1)) cout << "Found.\n";
    else cout << "Not found.\n";

    return 0;
}