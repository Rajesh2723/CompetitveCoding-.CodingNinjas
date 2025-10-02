/*
You are given a matrix mat of size N x M where each cell contains either 'O' or 'X'.

Your task is to replace all 'O' cells that are completely surrounded by 'X' with 'X'.



Rules:

An 'O' (or a group of connected 'O's) is considered surrounded if it is not connected to any border of the matrix.
Two 'O' cells are considered connected if they are adjacent horizontally or vertically (not diagonally).
A region of connected 'O's that touches the border (i.e., first row, last row, first column, or last column) is not surrounded and should not be changed.

Examples:


Input: mat = [ ["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "X", "O", "X"], ["X", "O", "X", "X"] ]

Output: [ ["X", "X", "X", "X"], ["X", "X", "X", "X"], ["X", "X", "X", "X"], ["X", "O", "X", "X"] ]

Explanation:



The 'O' cells at positions (1,1), (1,2), (2,2), and (3,1) are surrounded by 'X' cells in all directions (horizontally and vertically).

However, the 'O' region at (3,1) is adjacent to an edge of the board, so it cannot be completely surrounded by 'X' cells. Therefore, it remains unchanged.
  */
class Solution{
public:
    vector<vector<char>> fill(vector<vector<char>> mat) {
        int n=mat.size();
        int m=mat[0].size();
       vector<vector<bool>>visited(n,vector<bool>(m,false));
       queue<pair<int,int>>q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0||j==0||i==n-1||j==m-1) and mat[i][j]=='O' and !visited[i][j]){
                q.push({i,j});
                visited[i][j]=true;
            } 
        }
       }
         int dr[4] = {-1, 0, 1, 0};
         int dy[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int first=q.front().first;
            int second=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=first+dr[i];
                int ny=second+dy[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m and  !visited[nx][ny]
                and mat[nx][ny]=='O'){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' and !visited[i][j]){
                    mat[i][j]='X';
                    //visited[i][j]=true;
                }
            }
        }
    
       return mat;
    }
};
