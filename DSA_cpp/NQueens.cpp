#include <iomanip>
#include <iostream>

using namespace std;

struct NQueens {
    const size_t queens = 8;
    const size_t ROWS = queens;
    const size_t COLS = queens;
    int** create_board() {
        int** board = new int*[ROWS];
        for (int i = 0; i < ROWS; i++) {
            board[i] = new int[COLS];
        }
        return board;
    }

    void print(int** board) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if ((i + j) % 2 == 0)
                    cout << setw(3) << "##";
                else
                    cout << "  ";
            }
            cout << "\n";
        }
    }
};

int main() {
    NQueens n;
    n.print(n.create_board());
}
