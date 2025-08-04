/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
  */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //int rows=board.size();
        //int cols=board[i].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(word[0]==board[i][j]){
                    bool ans=f(board,i,j,word,0);
                    if(ans)return true;
                }
            }
        }
        return false;
    }
    bool f(vector<vector<char>>&board,int r,int c,string word,int index){
        if(index==word.size()){
            return true;
        }
        if(r<0||c<0||r>=board.size()||c>=board[0].size()||word[index]!=board[r][c])return false;
        char temp=board[r][c];
        board[r][c]='*';
        bool op1=f(board,r+1,c,word,index+1);//down
        bool op2=f(board,r,c+1,word,index+1);//right
        bool op3=f(board,r-1,c,word,index+1);//up
        bool op4=f(board,r,c-1,word,index+1);//left
        board[r][c]=temp;
        return op1||op2||op3||op4;
        
    }
};
