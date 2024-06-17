#include <iostream>
#include <vector>
using namespace std;

const int N = 8; // Size of the chessboard

bool isSafe(vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i][col])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row) {
    if (row == N)
        return true;

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            if (solveNQueensUtil(board, row + 1))
                return true;
            board[row][col] = 0;
        }
    }

    return false;
}

void solveNQueens() {
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (solveNQueensUtil(board, 0)) {
        cout << "Solution found:" << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {
    solveNQueens();
    return 0;
}

