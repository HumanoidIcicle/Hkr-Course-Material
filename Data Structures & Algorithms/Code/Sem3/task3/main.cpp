#include <iostream>
#include <vector>
#include <string>
#include "solver.h"

using namespace std;

int main() {
    // Creating the puzzle grid
    vector<vector<char>> grid = {
        {'t','h','i','s'},
        {'w','a','t','s'},
        {'o','a','h','g'},
        {'f','g','d','t'}
    };

    // List of words to search
    vector<string> words = {"this","two","fat","that", "Joe"};

    // Check each word
    for(string w : words) {
        if(search(grid, w))
            cout << w << " found in puzzle" << endl;
        else
            cout << w << " not found" << endl;
    }

    return 0;
}
