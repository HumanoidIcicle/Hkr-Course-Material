
#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <string>
using namespace std;

int main() {
    map<string, int> grades;
    grades.emplace("bon", 93);
    grades.emplace("jn", 53);
    grades.emplace("jmn", 30);

    for (auto it: grades) {
        cout <<  it.first << '-' << it.second << endl;
    }
    cout << grades.size();
    return 0;
}

