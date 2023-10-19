#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class FileReader {
public:
    static bool readMapFile(const std::string& filename, std::vector<std::vector<int>>& data);
};