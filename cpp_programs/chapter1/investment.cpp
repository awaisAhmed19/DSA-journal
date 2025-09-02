
#include <iostream>

using namespace std;

float pow(float& r, int& n) {
    float res = 1.0f;
    for (int i = 0; i < n; i++) {
        res = res * r;
    }
    return r;
}

int main() {
    size_t size = 10;

    int p = 1000;
    float* r = new float[size];
    float* V = new float[size];
    int* n = new int[size];

    r[0] = 0.10f;
    n[0] = 1;

    for (size_t i = 1; i < size; i++) {
        r[i] = r[i - 1] + 0.01f;
        n[i] = n[i - 1] + 1;
    }
    for (size_t i = 0; i < size; i++) {
        std::cout << "rate " << i + 1 << ":" << r[i] << "\n";
    }
    for (size_t i = 0; i < size; i++) {
        r[i] = 1.0f + r[i];
        V[i] = p * pow(r[i], n[i]);
        p += 1000;
    }

    for (size_t i = 0; i < size; i++) {
        std::cout << "rate " << i + 1 << ":" << r[i] << "\n";
    }
    for (size_t i = 0; i < size; i++) {
        std::cout << "years " << i + 1 << ":" << n[i] << "\n";
    }
    for (size_t i = 0; i < size; i++) {
        std::cout << "investment " << i + 1 << ":" << V[i] << "\n";
    }

    delete r, V, p, n;
}
