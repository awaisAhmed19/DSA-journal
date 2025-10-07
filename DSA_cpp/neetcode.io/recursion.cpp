#include <iostream>

using namespace std;

int Z(int a) {
    if (a == 0) {
        return 0;
    }
    if (a % 2 == 0 && a > 0) {
        return Z(0.5 * a);
    }
    if (a % 2 != 0 && a > 0) {
        return 1 + Z(a - 1);
    }
}

int Y(int a) {
    if (a <= 1) {
        return a;
    }
    if (a % 2 == 0 && a > 1) {
        return a + Y(0.5 * a);
    }
    if (a % 2 != 0 && a > 1) {
        return Y(0.5 * (a + 1)) + Y(0.5 * (a - 1));
    }
}
int main() {
    cout << Y(1) << "\n";
    // cout << Z(3) << "\n";
    // cout << Z(100) << "\n";
    // cout << Z(128) << "\n";
    // cout << Z(2) << "\n";
    cout << Y(4) << "\n";
    return 0;
}
