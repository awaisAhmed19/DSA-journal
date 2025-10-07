#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> dictionary;

void file_opener(string file_name) {
    ifstream infile(file_name);
    string buff;
    while (getline(infile, buff)) {
        dictionary.push_back(buff);
        buff = "";
    }
}

int lev_impl(const string& S1, const string& S2, int n1, int n2, vector<vector<int>>& cache) {
    if (cache[n1][n2] != -1) return cache[n1][n2];

    if (n1 == 0) {
        cache[n1][n2] = n2;
        return cache[n1][n2];
    }

    if (n2 == 0) {
        cache[n1][n2] = n1;
        return cache[n1][n2];
    }

    if (S1[n1 - 1] == S2[n2 - 1]) {
        cache[n1][n2] = lev_impl(S1, S2, n1 - 1, n2 - 1, cache);
        return cache[n1][n2];
    } else {
        cache[n1][n2] = 1 + min({
                                lev_impl(S1, S2, n1 - 1, n2, cache),
                                lev_impl(S1, S2, n1, n2 - 1, cache),
                                lev_impl(S1, S2, n1 - 1, n2 - 1, cache),
                            });
        return cache[n1][n2];
    }
}

int lev(string a, string b) {
    int n1 = a.size();
    int n2 = b.size();

    vector<vector<int>> cache(n1 + 1, vector<int>(n2 + 1, -1));

    return lev_impl(a, b, n1, n2, cache);
}

string recommend(string a) {
    for (string b : dictionary) {
        if (lev(a, b) <= 2) {
            return b;
        }
    }
    return "";
}
int main() {
    string input;
    cout << "Type a word (simulate live input): ";
    file_opener("common.txt");
    while (cin >> input) {
        string rec = recommend(input);
        if (rec == "")
            cout << "No match\n";
        else
            cout << "Did you mean: " << rec << " ?\n";

        cout << "\nType another word: ";
    }
    return 0;
}
