#include <cmath>
#include <iostream>

using namespace std;

double _pow(int r, int n) {
    double res = 1.0;
    for (int i = 0; i < n; i++) {
        res = res * r;
    }
    return res;
}

long _fact(int a) {
    double res = 1.0, i = 1.0;
    while (i <= a) {
        res *= i;
        i++;
    }
    return res;
}

double _sin(int x) {
    int pre = 20;
    double result = 0.0;
    for (int i = 0; i < pre; i++) {
        int n = 2 * i + 1;
        double term = _pow(x, n) / _fact(n);
        if (i % 2 == 0) term = -term;
        result += term;
    }
    return result;
}
double _sum(int x) {
    int prev = x;
    double sum, n;
    for (int i = 1; i < prev; i++) {
        n = 1 / i;
        sum += _pow(n, i);
    }
    return sum;
}

int main() {
    int x = 100;
    std::cout << "Our _sin(" << x << "): " << _sin(x) << endl;
    std::cout << "std::sin(" << x << "): " << sin(x) << endl;
    std::cout << "Our _sum(" << x << "): " << _sum(x) << endl;
}
