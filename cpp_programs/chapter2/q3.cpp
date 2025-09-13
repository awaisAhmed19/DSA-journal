#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
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
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    reverse_arr(arr, n);
    cout << "\n";
    cout << "largest: " << arr[0];
    cout << "second largest: " << arr[1];
    return 0;
}
