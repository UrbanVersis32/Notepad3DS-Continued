#include <fstream>
#include <iostream>
#include "file_io.h"
bool write_to_file(std::string& filename, File& file) {
    std::ofstream new_file(filename);

    for (auto iter = file.lines.begin(); iter != file.lines.end(); iter++) {
        for (const auto& ch: *iter)
            new_file << ch;
    }
    new_file.close();
    if (new_file.bad())
        return false;
    return true;
}

File open_file(std::string& filename) {
    std::ifstream file_open (filename);
    File file;
    if (file_open.is_open()) {
        char ch;
        std::string line;
        while (getline(file_open, line)) {
            std::vector<char> thing;
            for (const auto& ch : line)
                thing.push_back(ch);
            file.add_line(thing);
        }
        /*
        while (file_open >> ch) {
            std::vector<char> line;
            line.push_back(ch);
            if (ch == '\n') {
                file.lines.push_back(line);
                line.clear();
            }
        }
        */
        file.read_success = true;
        file_open.close();
    } else {
        file.read_success = false;
    }
    return file;
}
