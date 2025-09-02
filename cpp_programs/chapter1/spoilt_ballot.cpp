#include <iostream>

using namespace std;

void choice(void) {
    std::cout << "select a canditate from 1-5\n";
    std::cout << "type 1 for cand 1\n";
    std::cout << "type 2 for cand 2\n";
    std::cout << "type 3 for cand 3\n";
    std::cout << "type 4 for cand 4\n";
    std::cout << "type 5 for cand 5\n";
    std::cout << " any number out side of 1-5 will cound as spoilt ballot \n";
    std::cout << "-1 to exit";
}
int main() {
    int* cand = new int[5];
    int i, spoilt = 0;
    for (int k = 0; k < 5; k++) {
        cand[k] = 0;
    }
    choice();
    std::cout << "enter your choice:";
    std::cin >> i;
    while (i != -1) {
        switch (i) {
            case 1:
                cand[0]++;
                break;
            case 2:
                cand[1]++;
                break;
            case 3:
                cand[2]++;
                break;
            case 4:
                cand[3]++;
                break;
            case 5:
                cand[4]++;
                break;
            default:
                spoilt += 1;
                break;
        }
        std::cout << "enter your choice:";
        std::cin >> i;
    }

    for (int j = 0; j < 5; j++) {
        std::cout << "candidte " << j + 1 << " has " << cand[j] << " votes\n";
    }
    std::cout << "spoilt ballots " << spoilt << "\n";
}
