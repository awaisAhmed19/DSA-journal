#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

using ld = long double;

ld Fact(int a, vector<ld>& cache) {
    if (a == 1 || a == 0) {
        return 1;
    }
    if (cache[a] != -1) return cache[a];
    return cache[a] = a * Fact(a - 1, cache);
}

int main() {
    int a;
    cin >> a;
    vector<ld> cache(a + 1, -1);
    cout << " " << Fact(a, cache);
    return 0;
}
