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
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


bool isSafe(vector<vector<int>>& chessBoard, int row, int col){
    // check this row on the left
    for(int i=0;i<col;i++){
        if(chessBoard[row][i]==1) return false;
    }

    // check upper left diagonal
    for(int i=row,j=col;i>=0 && j>=0 ; i--,j--){
        if(chessBoard[i][j]==1) return false;
    }

    // check lower left diaognal 
    for(int i=row,j=col;i<chessBoard.size() && j>=0;i++,j--){
        if(chessBoard[i][j]==1) return false;
    }

    // else it is safe to place a queen
    return true;
}

//Function to add valid configuration
void addSolution(vector<vector<int>>& chessBoard, int n, vector<vector<int>>& ans){
    vector<int>state;
    for(auto i : chessBoard){
        for(auto j : i){
            state.push_back(j);
        }
    }
    ans.push_back(state);
    return;
}


void nQueenHelper(vector<vector<int>>& chessBoard, int col, int n, vector<vector<int>>& ans){
    //base case
    if(col>=n){
        addSolution(chessBoard,n,ans);
        return;
    }

    // iterate over all the rows
    for(int row=0;row<n;row++){
        if(isSafe(chessBoard,row,col)){
            // mark this state with queen
            chessBoard[row][col]=1;

            // recursive all the helper function for next column
            nQueenHelper(chessBoard,col+1,n,ans);

            //backtracking to previous state
            chessBoard[row][col]=0;
        }
    }
    return;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>>ans;
    vector<vector<int>>chessBoard(n,vector<int>(n,0));

    nQueenHelper(chessBoard,0,n,ans);

    for(auto i : ans){
        for(auto j : i) cout<<j<<" ";
            cout<<"\n";
    }
}
                
int main(){
    int t=1;
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}





