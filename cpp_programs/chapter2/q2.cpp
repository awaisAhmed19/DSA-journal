#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int* rotate(int* a, int k, int n) {
    int l = k;
    int r = n - 1;
    while (l <= r) {
        swap(a[l], a[r]);
        l++;
        r--;
    }
    return a;
}

void reverse_arr(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] <= a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

int main() {
    srand(time(0));
    int n;
    int* arr = new int[n];

    int k;
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    reverse_arr(arr, n);
    int* res = rotate(arr, k, n);
    cout << "\n";
    for (int a = 0; a < n; a++) {
        cout << " " << res[a];
    }
    return 0;
}
