#include <algorithm>
#include <set>
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Not specified file with data";
        return -1;
    }
    std::ifstream inputFile (argv[1]);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    std::set<int> buffer;
    std::string line;
    const std::string delimiter = " ";
    int readedVal = 0;

    while (getline(inputFile, line)) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        while ((pos_end = line.find(delimiter, pos_start)) != std::string::npos) {
            readedVal = atoi(line.substr(pos_start, pos_end - pos_start).c_str());
            pos_start = pos_end + delim_len;
            buffer.insert(std::move(readedVal));
        }
    }

    std::ofstream resultFile;
    resultFile.open ("result.txt", std::ios::out | std::ios::trunc);
    for (auto const& val : buffer) {
        resultFile << std::to_string(val) << ' ';
    }
    resultFile << '\n';
    resultFile.close();

    return 0;
}
