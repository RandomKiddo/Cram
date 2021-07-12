#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>

#define INTEGER_MAX 2147483647

struct Node {
    char input;
    unsigned frequency;
    Node *left, *right;
    Node (char input, unsigned frequency) {
        left = right = NULL;
        this->input = input;
        this->frequency = frequency;
    }
};

struct compare {
    bool operator() (Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

void print(Node* root, std::string str);
void encode(char input[], int frequency[], int size);
void run(void);
std::map<char, int> countChars(std::map<char, int> map, std::string line);
std::pair<std::vector<char>, std::vector<int> > sort(std::map<char, int> map);
std::string encodeLine(std::map<char, int> map, std::string line);

std::map<char, int> encoding;

int main(void) {
    run();
    return 0;
}

void run(void) {
    std::string in;
    std::cout << "Enter an input dir: ";
    std::cin >> in;
    std::ifstream fin;
    fin.open(in.c_str());
    std::map<char, int> counter;
    std::string buffer;
    std::vector<std::string> lines;
    while (std::getline(fin, buffer)) {
        counter = countChars(counter, buffer);
        lines.push_back(buffer);
    }
    std::pair<std::vector<char>, std::vector<int> > pair = sort(counter);
    char input[pair.first.size()];
    int frequency[pair.second.size()];
    for (int i = 0; i < pair.first.size(); ++i) {
        input[i] = pair.first.at(i);
    }
    for (int i = 0; i < pair.second.size(); ++i) {
        frequency[i] = pair.second.at(i);
    }
    int size = sizeof(input) / sizeof(input[0]);
    encode(input, frequency, size);
    std::ofstream fout;
    std::string out;
    std::cout << "\nEnter an output dir: ";
    std::cin >> out;
    fout.open(out.c_str());
    for (int i = 0; i < lines.size(); ++i) {
        fout << encodeLine(encoding, lines.at(i)) << "\n";
    }
    fout.close();
    fin.close();
}

std::string encodeLine(std::map<char, int> map, std::string line) {
    std::string str;
    for (int i = 0; i < line.size(); ++i) {
        std::map<char, int>::iterator it = map.find(line[i]);
        str += std::to_string(it->second);
    }
    return str;
}

std::map<char, int> countChars(std::map<char, int> map, std::string line) {
    for (int i = 0; i < line.size(); ++i) {
        std::map<char, int>::iterator it = map.find(line.at(i));
        if (it == map.end()) {
            map.insert(std::pair<char, int>(line.at(i), 1));
        } else {
            ++(it->second);
        }
    }
    return map;
}

std::pair<std::vector<char>, std::vector<int> > sort(std::map<char, int> map) {
    std::vector<char> chars;
    std::vector<int> ints;
    for (int i = 0; i < map.size(); ++i) {
        std::map<char, int>::iterator it;
        int min = INTEGER_MAX;
        char c;
        for (it = map.begin(); it != map.end(); it++) {
            if (it->second < min) {
                min = it->second;
                c = it->first;
            }
        }
        it = map.find(c);
        chars.push_back(it->first);
        ints.push_back(it->second);
        map.erase(it);
    }
    return std::pair<std::vector<char>, std::vector<int> >(chars, ints);
}

void print(Node* root, std::string str) {
    if (!root) { return; }
    if (root->input != '$') {
        //std::cout << root->input << ": " << str << "\n";
        encoding.insert(std::pair<char, int>(root->input, stoi(str)));
    }
    print(root->left, str + "0");
    print(root->right, str + "1");
}

void encode(char input[], int frequency[], int size) {
    struct Node *left, *right, *top;
    std::priority_queue<Node*, std::vector<Node*>, compare> tree;
    for (int i = 0; i < size; ++i) {
        tree.push(new Node(input[i], frequency[i]));
    }
    while (tree.size() != 1) {
        left = tree.top();
        tree.pop();
        right = tree.top();
        tree.pop();
        top = new Node('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        tree.push(top);
    }
    print(tree.top(), "");
}