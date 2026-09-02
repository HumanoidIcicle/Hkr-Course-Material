#pragma once

#include <vector>
#include <string>
#define ROW 4
#define COL 4

using namespace std;

int directions[8][2] = {
    {-1, 0}, //N
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {-1, 0},
    {-1, -1} //NW
};

bool search(vector<vector<char>>& grid, string word){
    int len = word.length();

    for (int r = 0; r < ROW; r++){
        //Check for first letter of the word
        for (int c = 0; c < COL; c++){
            if (grid[r][c] != word[0]) continue; 

            for (int d = 0; d < 8; d++){
                int rowDir = r + directions[d][0]; //next row position
                int colDir = c + directions[d][1]; //next col position

                int k; //index for characters of word
                for (k = 1; k < len; k++){
                    //outside boundary
                    if (rowDir < 0 || rowDir >= ROW 
                        ||colDir < 0 || colDir >= COL) break; 
                    
                    //mismatch letter in word
                    if (grid[rowDir][colDir] != word[k]) break;

                    // Continue in same direction
                    rowDir += directions[d][0]; 
                    colDir += directions[d][1];
                }
                if (k == len) return true; // if all characters match
            }
        }
    }
    return false; //Word not found
}


