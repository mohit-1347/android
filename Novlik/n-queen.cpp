// #include <bits/stdc++.h>
// #define mod 1000000007
// #define ll long long int
// using namespace std;

// bool isSafe(vector<vector<int>> &board, int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         if (board[i][col] == 1)
//         {
//             return false;
//         }
//     }

//     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//     }

//     for (int i = row, j = col; i < board.size() && j >= 0; i++, j--)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//     }

//     return true;
// }

// // Function to solve the N-Queen problem using greedy approach
// bool solveNQueensGreedy(vector<vector<int>> &board, int row)
// {
//     if (row == board.size())
//     {
//         return true;
//     }

//     for (int col = 0; col < board[row].size(); col++)
//     {
//         if (isSafe(board, row, col))
//         {
//             board[row][col] = 1;

//             if (solveNQueensGreedy(board, row + 1))
//             {
//                 return true;
//             }

//             board[row][col] = 0; // backtrack
//         }
//     }

//     return false;
// }

// // Function to print the solution
// void printSolution(vector<vector<int>> &board)
// {
//     for (int i = 0; i < board.size(); i++)
//     {
//         for (int j = 0; j < board[i].size(); j++)
//         {
//             if (board[i][j] == 1)
//             {
//                 cout << "Q ";
//             }
//             else
//             {
//                 cout << ". ";
//             }
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter the value of N: ";
//     cin >> n;

//     vector<vector<int>> board(n, vector<int>(n, 0));

//     if (n < 4)
//     {
//         cout << "No solution exists." << endl;
//     }
//     else if (solveNQueensGreedy(board, 0))
//     {
//         printSolution(board);
//     }
//     else
//     {
//         cout << "No solution exists." << endl;
//     }

//     return 0;
// }

// n-queen using backtracking approach?

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col)
{
    // Check for queens in the same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // Check for queens in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check for queens in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>> &board, int row)
{
    int n = board.size();
    if (row == n)
    {
        return true; // All queens are placed successfully
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1; // Place the queen

            // Recursive call to place queen in the next row
            if (solveNQueens(board, row + 1))
            {
                return true;
            }

            // If placing queen in (row, col) doesn't lead to a solution,
            // backtrack and try placing it in the next column
            board[row][col] = 0;
        }
    }

    return false; // No solution found for this row
}

void printSolution(vector<vector<int>> &board)
{
    for (auto &row : board)
    {
        for (int cell : row)
        {
            if (cell == 1)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (n < 4)
    {
        cout << "No solution exists." << endl;
    }
    else if (solveNQueens(board, 0))
    {
        printSolution(board);
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}
