#include <iostream>
#include <vector>
using namespace std;

void print(int v) { cout << "values " << v << endl; }

void forall(vector<int>& v, void (*func)(int)) {
    for (int vals : v) {
        func(vals);
    }
}

int main() {
    vector<int> v = {1, 23, 3, 4, 5, 6, 7, 8, 6, 5, 4};

    forall(v, [](int val) { cout << "values " << val << endl; });
}
