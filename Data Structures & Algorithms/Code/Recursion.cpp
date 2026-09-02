#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return n*factorial(n-1);
}

int fib(int n) {//no array
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

int fib2(int n) { //with array
    static int arr[100] = {0};
    /*
     * has a time complexity of O(2^n)
     * Simple to write and efficient for smaller values of N
     * But not really good for larger values.
     */
    if (n <= 1) return n;
    if (arr[n] != 0) return arr[n];//check if value already exists

    arr[n] = fib2(n-1) + fib2(n-2);
    return arr[n];
}

int fib3(int n) {//O(N) but 0(1) is the number is already calculated.
    int arr[n+1];
    arr[0] = arr[1] = 1;

    for (int i = 2; i < n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

float GoldenRatio(int n) {
    if (n == 0) return 1.0;
    if (n > 0) return 1 + 1/GoldenRatio(n-1);
}

double Ackermann(int i, int j) {
    if (i == 1 && j >= 1) return pow(2, j);
    if (i > 1 && j == 1) return Ackermann(i-1,2);
    if (i >= 2 && j >= 2) return Ackermann(i-1, Ackermann(i, j-1));
    return 0;
}

void towerOfHanoi(int n, char fromRod, char toRod,
                    char auxRod){
    /*
     * T(n) = O(2^n)
     * motivation: T(n) = 2 * T(n-1)
     */
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    cout << "Disk " << n << " moved from " << fromRod
        << " to " << toRod << endl;
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}
int main() {
    int n, m;
    cout << "Enter N: ";
    //cout << "Enter N and M: ";
    //cin >> n >> m;
    cin >> n;


    //cout << "Fibonacci with array: " << fib2(n) << endl;
    //cout << "Fibonacci with array 2: " << fib3(n) << endl;
    //cout << "Fibonacci without array: " << fib(n) << endl;
    //cout << "Factorial: " << factorial(n) << endl;
    //cout << "Golden ratio: " << GoldenRatio(n) << endl;
    //cout << "Ackermann: " << Ackermann(1, 2) << endl;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}

/*
a) linear time - O(N), not expressed in terms of first and last.
b) logarithmic time - O(log N)
c) linear time - O(N)
 */
