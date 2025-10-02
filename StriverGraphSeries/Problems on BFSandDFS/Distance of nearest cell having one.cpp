/*
Given a binary grid of N x M. Find the distance of the nearest 1 in the grid for each cell.



The distance is calculated as |i1 - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.


Examples:


Input: grid = [ [0, 1, 1, 0], [1, 1, 0, 0], [0, 0, 1, 1] ]

Output: [ [1, 0, 0, 1], [0, 0, 1, 1], [1, 1, 0, 0] ]

Explanation: 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1),(0,2), (0,2), (2,3), (1,0) and (1,1) respectively.
  */
class Solution {
private:
    // DelRow and delCol for neighbors
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    
    /* Helper Function to check if a 
    cell is within boundaries */
    bool isValid(int &i, int &j, 
                 int &n, int &m) {
        
        // Return false if cell is invalid
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        
        // Return true if cell is valid
        return true;
    }
    
public:
    /* Function to find the distance of the 
    nearest 1 in the grid for each cell. */
    vector<vector<int>> nearest(vector<vector<int>>grid) {
        
        // Determine the dimensions
	    int n = grid.size();
	    int m = grid[0].size(); 
	    
	    // visited and distance matrix
	    vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
	    
	    // Queue to store the pair {coordinates, steps}
	    queue<pair<pair<int,int>, int>> q; 
	    
	    // Traverse the matrix
	    for(int i=0; i < n; i++) {
	        for(int j=0; j < m; j++) {
	            
	            // Start BFS if cell contains 1
	            if(grid[i][j] == 1) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	            else {
	                // mark unvisited 
	                vis[i][j] = 0; 
	            }
	        }
	    }
	    
	    // Traverse till queue becomes empty
	    while(!q.empty()) {
	        
	        // Determine the top of queue
	        auto it = q.front();
	        q.pop();
	        
	        // Determine the coordinates of cell
	        int row = it.first.first; 
	        int col = it.first.second; 
	        
	        // Get the steps
	        int steps = it.second; 
	        
	        // Update the distance matrix
	        dist[row][col] = steps; 
	        
	        // Traverse the 4 neighbours
	        for(int i = 0;i<4;i++) {
	            
	            // Coordinates of new cell
	            int nRow = row + delRow[i]; 
	            int nCol = col + delCol[i]; 
	            
	            // Check for valid, unvisited cell
	            if(isValid(nRow, nCol, n, m)
	            && vis[nRow][nCol] == 0) {
	                
	                // Mark the cell as visited
	                vis[nRow][nCol] = 1; 
	                q.push({{nRow, nCol}, steps+1});  
	            }
	        }
	    }
	    
	    // return distance matrix
	    return dist; 
	}
};
