/*
Given an n x m matrix grid where each cell contains either 0 or 1, determine the shortest distance between a source cell and a destination cell. You can move to an adjacent cell (up, down, left, or right) if that adjacent cell has a value of 1. The path can only be created out of cells containing 1. If the destination cell is not reachable from the source cell, return -1.


Examples:
Input: grid = [[1, 1, 1, 1],[1, 1, 0, 1],[1, 1, 1, 1],[1, 1, 0, 0],[1, 0, 0, 1]], source = [0, 1], destination = [2, 2]

Output: 3

Explanation: The shortest path from (0, 1) to (2, 2) is:

Move down to (1, 1)

Move down to (2, 1)

Move right to (2, 2)

Thus, the shortest distance is 3

Input: grid = [[1, 1, 1, 1, 1],[1, 1, 1, 1, 1],[1, 1, 1, 1, 0],[1, 0, 1, 0, 1]], source = [0, 0], destination = [3, 4]

Output: -1

Explanation: 

Since, there is no path possible between the source cell and the destination cell, hence we return -1.
  */
class Solution{
private:

    // Delta row and column array
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, -1, 0, 1};
    
    // Function to check if a cell is valid
    bool isValid(int &row, int &col, 
                 int &n, int &m) {
                     
        // Return false if the cell is invalid
        if(row < 0 || row >= n) return false;
        if(col < 0 || col >= m) return false;
        
        // Return true if the cell is valid
        return true;
    }
    
public:

    /* Function to determine the shortest distance
    between source and destination */
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {

        // Edge Case
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;

        /* Queue data structure to store the pairs of the 
        form: {dist, {coordinates of cell}} */
        queue<pair<int, pair<int, int>>> q;
        
        // Dimensions of grid
        int n = grid.size();
        int m = grid[0].size();

        // Distance matrix
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        // Distane of source from itself is zero
        dist[source.first][source.second] = 0;
        
        // Add the source to queue
        q.push({0, {source.first, source.second}});

        // Until the queue is empty
        while (!q.empty()) {
            // Get the element
            auto it = q.front();
            q.pop();
            
            int dis = it.first; // Distance
            int row = it.second.first; // Row of cell
            int col = it.second.second; // Column of cell

            // Iterate through all the neighbors
            for (int i = 0; i < 4; i++){
                
                // Coordinates of the new cell
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                /* Checking the validity of the cell and 
                updating if a shorter distance is found */
                if (isValid(newRow, newCol, n, m) && 
                    grid[newRow][newCol] == 1 && 
                    dis + 1 < dist[newRow][newCol]) {
                    
                    // Update the distance
                    dist[newRow][newCol] = 1 + dis;

                    // Return the distance if the destination is reached
                    if (newRow == destination.first &&
                        newCol == destination.second)
                        return dis + 1;
                    
                    // Add the new cell to queue
                    q.push({1 + dis, {newRow, newCol}});
                }
            }
        }
        
        // If no path is found from source to destination
        return -1;
    }
};
