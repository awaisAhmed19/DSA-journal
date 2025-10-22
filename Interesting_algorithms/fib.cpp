#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

using i64 = int64_t;

i64 fib(int n, vector<i64>& cache) {
    if (cache[n] != -1) return cache[n];
    if (n <= 1) {
        return n;
    }
    if (cache[n] == -1) cache[n] = fib(n - 1, cache) + fib(n - 2, cache);
    return cache[n];
}

int main() {
    int a = 0;
    cin >> a;
    vector<i64> cache(a + 1, -1);
    cout << " " << fib(a, cache);
    return 0;
}
