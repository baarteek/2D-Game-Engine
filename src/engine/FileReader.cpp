#include "FileReader.h"

bool FileReader::readMapFile(const std::string& filename, std::vector<std::vector<int>>& data)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Nie można otworzyć pliku: " << filename << endl;
        return false;
    }

    data.clear(); 

    string line;
    while (getline(file, line)) {
        vector<int> row;
        stringstream ss(line);
        string number;

        while (getline(ss, number, ',')) {
            try {
                int value = stoi(number);
                row.push_back(value);
            }
            catch (const invalid_argument& e) {
                cerr << "Conversion to number error: " << e.what() << endl;
                file.close();
                return false;
            }
        }

        data.push_back(row);
    }

    file.close();
    return true;
}
