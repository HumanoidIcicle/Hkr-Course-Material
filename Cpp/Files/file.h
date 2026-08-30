//
// Created by JOSS0001 on 2025-12-12.
//

#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

using namespace std;

class FileIO {
public:
    void readRooms(string filename);
    void readCatalog(string filename);
};
#endif //FILE_H
