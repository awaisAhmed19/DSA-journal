#include <iostream>
using namespace std;
void f(int& a) { a = a + 10000; }

int main() {
    int m = 10;

    std::cout << m;
}
