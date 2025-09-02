#include <iostream>

using namespace std;

class Temp {
    float Ftemp;
    float Ctemp;

   public:
    float getFar(int temp) { return (9 / 5) * temp + 32; }
    float getCel(int temp) { return (5 / 9) * (temp - 32); }
};

int main() {
    Temp t;
    std::cout << "in far" << t.getFar(32);
    std::cout << "\nin cel" << t.getCel(32);
}
