/*
N-Queens
Send Feedback
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format:
The first and the only line of input contains an integer 'N' representing the size of the chessboard and the number of queens.
Output Format:
Each line would be representing a single configuration.

Each configuration would contain 'N '* 'N' elements printed row-wise separated by spaces. The position where we can place the queen will have the value 1 rest will have the value 0.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= 'N' <= 10

Time Limit: 1sec
Sample Input 1:
4
Sample Output 1:
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
Explanation For Sample Input 1:
Output depicts two possible configurations of the chessboard for 4 queens.

The Chessboard matrix for the first configuration looks as follows:-

0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0

Queen contained cell is depicted by 1. As seen, No queen is in the same row, column, or diagonal as the other queens. Hence this is a valid configuration.
Sample Input 2:
3
Sample Output2:
      (Blank)
Explanation For Sample Input 2:
Since no possible configuration exists for 3 Queen's.The output remains Empty.
*/
bool isValid(int row, int col, vector<vector<int>>& board, int n) {
    // Check if there is a queen in the same row
    for (int i = 0; i < n; i++) {
        if (board[row][i] == 1) {//row constant
            return false;
        }
    }
    
    // Check if there is a queen in the same column
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 1) {//column constant
            return false;
        }
    }
    
    // Check if there is a queen in the same diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    return true;
}

void solve(vector<vector<int>>& board, vector<vector<int>>& ans, int n, int col) {
    // If all queens are placed, add the solution to the answer and return
    if (col == n) {
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }
    
    // Try placing a queen in each row of the current column
    for (int row = 0; row < n; row++) {
        if (isValid(row, col, board, n)) {
            board[row][col] = 1;
            solve(board, ans, n, col + 1);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(board, ans, n, 0);
    return ans;
}
#include <iostream>
#include <vector>
using namespace std;
#include "solution.h"

int main() {
    int n;
    cin >> n;
    vector<vector<int>> answer;
    answer = solveNQueens(n);

    for (auto sol : answer) {
        for (auto i : sol) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
