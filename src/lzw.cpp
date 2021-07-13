/**
 * This file is licensed under the MIT License (MIT).
 * Copyright (c) 2021 RandomKiddo
 **/

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>

std::vector<int> encode(std::string str);

int main(void) {
    std::ifstream fin;
    std::ofstream fout;
    std::string in, out;
    std::cout << "Enter an input dir: ";
    std::cin >> in;
    std::cout << "\nEnter an output dir: ";
    std::cin >> out;
    fin.open(in.c_str());
    fout.open(in.c_str());
    std::string buffer;
    while (std::getline(fin, buffer)) {
        std::vector<int> code = encode(buffer);
        for (int i = 0; i < code.size(); ++i) {
            fout << code.at(i) << " ";
        }
        fout << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

std::vector<int> encode(std::string str) {
    std::unordered_map<std::string, int> table;
    for (int i = 0; i < 256; ++i) {
        std::string s = "";
        s += char(i);
        table[s] = i;
    }
    std::string p = "", c = "";
    p += str[0];
    int code = 256;
    std::vector<int> output;
    for (int i = 0; i < str.size(); ++i) {
        if (i != str.size() - 1) {
            c += str[i+1];
        }
        if (table.find(p+c) != table.end()) {
            p += c;
        } else {
            //print
            output.push_back(table[p]);
            table[p+c] = code;
            ++code;
            p = c;
        }
        c = "";
    }
    //print
    output.push_back(table[p]);
    return output;
}