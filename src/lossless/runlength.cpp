/**
 * This file is licensed under the MIT License (MIT).
 * Copyright (c) 2021 RandomKiddo
 **/

#include <iostream>
#include <string>
#include <fstream>

void compress(std::string input, std::string output);
std::string runLine(std::string line);

int main(void) {
    std::string input;
    std::string output;
    std::cout << "Enter an input dir: ";
    std::cin >> input;
    std::cout << "\n" << "Enter an output dir: ";
    std::cin >> output;
    std::cout << "\n";
    compress(input, output);
    return 0;
}

void compress(std::string input, std::string output) {
    std::ifstream fin;
    fin.open(input.c_str());
    std::ofstream fout;
    fout.open(output.c_str());
    std::string buffer;
    while (std::getline(fin, buffer)) {
        std::string run = runLine(buffer);
        fout << run << "\n";
    }
    fin.close();
    fout.close();
}

std::string runLine(std::string line) {
    std::string buffer;
    for (int i = 0; i < line.size(); ++i) {
        int count = 1;
        while (i < line.size() - 1 && line[i] == line[i + 1]) {
            ++count;
            ++i;
        }
        buffer += line[i];
        buffer += std::to_string(count);
    }
    return buffer;
}