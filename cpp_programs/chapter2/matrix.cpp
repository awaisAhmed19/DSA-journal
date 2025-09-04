#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
class matrix {
   public:
    int m, n;
    int** p;

    matrix(int m = 0, int n = 0) {
        this->m = m;
        this->n = n;
        p = new int*[m];
        for (int i = 0; i < m; i++) {
            p[i] = new int[n];
        }
    }

    static matrix random(int m, int n) {
        matrix mat(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat.p[i][j] = rand() % 10;
            }
        }
        return mat;
    }
    matrix operator+(const matrix& other) {
        if (m != other.m || n != other.n) {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }

        matrix temp(m, n);  // create an empty m×n
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                temp.p[i][j] = p[i][j] + other.p[i][j];
            }
        }
        return temp;
    }

    matrix operator*(const matrix& other) {
        if (m != other.m || n != other.n) {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }

        matrix temp(other.m, other.n);  // create an empty m×n
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                temp.p[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    temp.p[i][j] = temp.p[i][j] * p[i][k] + other.p[k][j];
                }
            }
        }
        return temp;
    }
    ~matrix() {
        for (int i = 0; i < m; i++) {
            delete[] p[i];
        }
        delete[] p;
    }

    // Deep copy constructor
    matrix(const matrix& other) {
        m = other.m;
        n = other.n;
        p = new int*[m];
        for (int i = 0; i < m; i++) {
            p[i] = new int[n];
            for (int j = 0; j < n; j++) {
                p[i][j] = other.p[i][j];
            }
        }
    }

    // Deep copy assignment
    matrix& operator=(const matrix& other) {
        if (this != &other) {
            // free old memory
            for (int i = 0; i < m; i++) delete[] p[i];
            delete[] p;

            // copy dimensions
            m = other.m;
            n = other.n;

            // allocate new memory
            p = new int*[m];
            for (int i = 0; i < m; i++) {
                p[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    p[i][j] = other.p[i][j];
                }
            }
        }
        return *this;
    }
};

int main() {
    srand(time(0));
    matrix m1 = matrix::random(10, 10), m2 = matrix::random(10, 10);

    cout << "-------------------------------------------------------------------------\n" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(10) << m1.p[i][j];
        }
        cout << "\n" << endl;
    }

    cout << "-------------------------------------------------------------------------\n" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(10) << m2.p[i][j];
        }
        cout << "\n" << endl;
    }
    matrix m3(10, 10);

    m3 = m2 + m1;

    cout << "-------------------------------------------------------------------------\n" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(10) << m3.p[i][j];
        }
        cout << "\n" << endl;
    }

    matrix m4(10, 10);
    m4 = m2 * m1;

    cout << "-------------------------------------------------------------------------\n" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(10) << m4.p[i][j];
        }
        cout << "\n" << endl;
    }
    return 0;
}
