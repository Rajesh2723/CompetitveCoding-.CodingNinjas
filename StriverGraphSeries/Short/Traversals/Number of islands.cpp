/*
Given a grid of size N x M (N is the number of rows and M is the number of columns in the grid) consisting of '0's (Water) and ‘1's(Land). Find the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.


Examples:




Input: grid = [ ["1", "1", "1", "0", "1"], ["1", "0", "0", "0", "0"], ["1", "1", "1", "0", "1"], ["0", "0", "0", "1", "1"] ]

Output: 2

Explanation: This grid contains 2 islands. Each '1' represents a piece of land, and the islands are formed by connecting adjacent lands horizontally or vertically. Despite some islands having a common edge, they are considered separate islands because there is no land connectivity in any of the eight directions between them. Therefore, the grid contains 2 islands.

Input: grid = [ ["1", "0", "0", "0", "1"], ["0", "1", "0", "1", "0"], ["0", "0", "1", "0", "0"], ["0", "1", "0", "1"," 0"] ]

Output: 1

Explanation: In the given grid, there's only one island as all the '1's are connected either horizontally, vertically, or diagonally, forming a single contiguous landmass surrounded by water on all sides.
  */
class Solution{
public:
    int numIslands(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int dx[8] = {-1, -1, -1,  0, 0, 1, 1, 1};
        int dy[8] = {-1,  0,  1, -1, 1,-1, 0, 1};

        int count = 0;
         queue<pair<pair<int,int>,char>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    q.push({{i,j},'1'});
                    visited[i][j] = 1;
                    break;
                }
            }
        }
                        while(!q.empty()){
                            count++;  // new island found
                        int x = q.front().first.first;
                        int y = q.front().first.second;
                        // char val = q.front().second; // val not needed
                        q.pop();

                        for(int k=0;k<8;k++){
                            int dirx = x + dx[k];
                            int diry = y + dy[k];

                            if(dirx>=0 && dirx<n && diry>=0 && diry<m &&
                               grid[dirx][diry]=='1' && !visited[dirx][diry]){
                                q.push({{dirx,diry},'1'});
                                visited[dirx][diry] = 1;
                            }
                        }
                    }
            return count;
    }
};
