#include <cmath>
#include <iostream>

using namespace std;

void readmat(int** mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = rand();
        }
    }
}

void display(int** mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << " " << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int m, n;
    std::cin >> m >> n;
    int** mat = new int*[m];

    for (int k = 0; k < m; k++) {
        mat[k] = new int[n];
    }

    readmat(mat, m, n);
    display(mat, m, n);
}
