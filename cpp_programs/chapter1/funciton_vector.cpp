#include <iostream>
#include <vector>

using namespace std;

int* vectoor(size_t& m) {
    int* v = new int[m];

    for (int i = 0; i < m; i++) {
        v[i] = 0;
    }

    return v;
}

int main() {
    size_t m;

    std::cin >> m;
    int* a = vectoor(m);
    delete a;
    std::cout << m;
}
