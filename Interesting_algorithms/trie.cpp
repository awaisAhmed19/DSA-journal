#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

set<string> dict;
struct trie {
    trie* children[26];

    bool isleaf;
    trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    void insert(const string& str) {
        trie* curr = this;
        for (char c : str) {
            int val = c - 'a';
            if (curr->children[val] == nullptr) {
                trie* newtrie;
                curr->children[val] = new trie();
            }
            curr = curr->children[val];
        }
        curr->isleaf = true;
    }
    bool search(const string& str) {
        if (this == nullptr) {
            return false;
        }

        trie* curr = this;

        for (char c : str) {
            int val = c - 'a';
            if (curr->children[val] == nullptr) {
                return false;
            }
            curr = curr->children[val];
        }
        return curr->isleaf;
    }
    bool prefix(const string& str) {
        if (this == nullptr) {
            return false;
        }

        trie* curr = this;

        for (char c : str) {
            int val = c - 'a';
            if (curr->children[val] == nullptr) {
                return false;
            }
            curr = curr->children[val];
        }
        return true;
    }

    void print() {
        trie* curr = this;
        string word;

        while (curr && !curr->isleaf) {
            bool found = false;
            for (int i = 0; i < 26; i++) {
                if (curr->children[i]) {
                    word += ('a' + i);
                    curr = curr->children[i];
                    found = true;
                    break;  // go down the first child
                }
            }
            if (!found) break;  // no children
        }

        if (!word.empty())
            cout << word << endl;
        else
            cout << "nothing to print" << endl;
    }
};

void file_opener(string file_name) {
    ifstream infile(file_name);
    string buff;
    while (getline(infile, buff)) {
        string word = "";
        for (char c : buff) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                word += c;
            } else if (c == ' ') {
                if (!word.empty()) dict.insert(word);
                word = "";
            }
        }
        if (!word.empty()) dict.insert(word);
    }
}

int main() {
    file_opener("common.txt");
    trie root;
    for (const string& s : dict) {  // must be const
        root.insert(s);
    }

    string input;
    cout << "Type a word: ";
    cin >> input;

    trie* node = &root;

    for (char c : input) {
        int idx = c - 'a';
        if (!node->children[idx]) {
            cout << "No suggestions found\n";
            return 0;
        }
        node = node->children[idx];
    }

    if (node->isleaf) {
        cout << input << " is in the dictionary\n";
    }

    cout << "Suggestions:\n";
    node->print();  // this should print first completion
}
