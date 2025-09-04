
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

void yfunc() {
    float x = 0.0f, y = 0.0f;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            y = 1 / exp(x);
            std::cout << y << setw(15);
            x += 0.1;
        }
        std::cout << "\n";
    }
}
int main() { yfunc(); }
