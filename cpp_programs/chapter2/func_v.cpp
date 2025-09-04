#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

float mean(int* arr, int n) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

float variance(int* arr, int n) {
    float var = 0.0f, temp = 0.0f;
    float mew = mean(arr, n);
    for (int i = 0; i < n; i++) {
        temp = arr[i] - mew;
        var += pow(temp, 2);
    }
    return var / n;
}

int main() {
    const int n = 10;

    int* list = new int[n];

    for (int i = 0; i < n; i++) {
        list[i] = rand() % 10;
    }

    float Std_ = variance(list, n);
    cout << " " << sqrt(Std_);
}
