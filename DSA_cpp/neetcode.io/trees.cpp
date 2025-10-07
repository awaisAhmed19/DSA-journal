#include <iostream>
using namespace std;

struct tree {
    int val;
    tree* left;
    tree* right;
    tree(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++) {
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left < n) cout << "left: " << a[left];
        if (right < n) cout << ", right: " << a[right];
        cout << endl;
    }

    return 0;
}
