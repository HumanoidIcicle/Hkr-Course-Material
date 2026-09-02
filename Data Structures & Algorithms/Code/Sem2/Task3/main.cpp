#include <iostream>
#include "j_Arraylist_vector.h"
#include "j_linkedList.h"
#include "j_STL_list.h"
#include <windows.h>

//using namespace std;
template <typename Function>

void Runtime(Function func, int n, int m) {
    LARGE_INTEGER freq, begin, stop;
    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&begin);
    func(n, m); 
    QueryPerformanceCounter(&stop);

    double time_taken =
        static_cast<double>(stop.QuadPart - begin.QuadPart) / freq.QuadPart;
    std::cout << time_taken << "\n\n";
}

int main() {
    int n, m;
    std::cout << "Enter n and m values: ";
    std::cin >> n >> m;
    
    Runtime(josephus_my_list, n, m);
    Runtime(josephus_Arraylist, n, m);
    Runtime(josephus_stl_list, n, m);
    return 0;
}
