
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, int> dictionary;

void file_opener(string file_name) {
    ifstream infile(file_name);
    string buff;
    while (getline(infile, buff)) {
        string word = "";
        for (char c : buff) {
            if (c >= 'a' && c <= 'z' || c <= 'A' && c >= 'Z') {
                word += c;
            }
            if (c == ' ') {
                if (dictionary.count(word)) {
                    dictionary[word]++;
                } else {
                    dictionary[word] = 1;
                }
                word = "";
            }
        }
        buff = "";
    }
}

void print(vector<pair<string, int>> data) {
    for (auto s : data) {
        cout << s.first << " -> " << s.second << "\n";
    }
}

int main() {
    string input;
    cout << "Type a word (simulate live input): ";
    file_opener("sample.txt");
    vector<pair<string, int>> data(dictionary.begin(), dictionary.end());
    sort(data.begin(), data.end(),
         [](const auto& a, const auto& b) { return a.second < b.second; });
    print(data);
    return 0;
}
