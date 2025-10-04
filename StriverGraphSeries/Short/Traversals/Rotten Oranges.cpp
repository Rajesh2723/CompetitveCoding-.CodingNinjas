/*
Given an n x m grid, where each cell has the following values : 



2 - represents a rotten orange

1 - represents a Fresh orange

0 - represents an Empty Cell

Every minute, if a fresh orange is adjacent to a rotten orange in 4-direction ( upward, downwards, right, and left ) it becomes rotten. 



Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it's not possible, return -1.


Examples:
Input: grid = [ [2, 1, 1] , [0, 1, 1] , [1, 0, 1] ]

Output: -1

Explanation: Orange at (3,0) cannot be rotten.
  */
class Solution{
public:
    int orangesRotting(vector<vector<int>> &grid) {
       //up->(x,y)->-1,0
       //down->(+1,0)
       //right->(0,+1)
       //left->(0,-1)
       int dx[4]={-1,+1,0,0};
       int dy[4]={0,0,+1,-1};
       int time=0;
       queue<pair<pair<int,int>,int>>q;
       vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
       int n=grid.size();
       int m=grid[0].size();
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=true;
            }
        }
       }
       //int time=0;
       while(!q.empty()){
        int first=q.front().first.first;
        int second=q.front().first.second;
        int t=q.front().second;
        time=max(time,t);
        q.pop();
        for(int i=0;i<4;i++){
            int x=first+dx[i];
            int y=second+dy[i];

            if(x>=0 and x<n and y>=0 and y<m and !visited[x][y] and grid[x][y]==1){
                q.push({{x,y},t+1});
                visited[x][y]=true;
                grid[x][y]=2;
            }
        }
       }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                return -1;
            }
        }
       }
       return time;
    }
};
