/*
A hiker is preparing for an upcoming hike. Given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of the cell (row, col). The hiker is situated in the top-left cell, (0, 0), and hopes to travel to the bottom-right cell, (rows-1, columns-1) (i.e.,0-indexed). He can move up, down, left, or right. He wishes to find a route that requires the minimum effort.



A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.


Examples:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]

Output: 2

Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells. This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Input: heights = [[1,2,3],[3,8,4],[5,3,5]]

Output: 1

Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
  */
#include <bits/stdc++.h>
using namespace std;

/* Define P as a shorthand for
the pair<int, pair<int,int>> type */
#define P pair <int, pair<int,int>>

class Solution {
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

    /* Function to determine minimum efforts 
    to go from top-left to bottom-right */
    int MinimumEffort(vector<vector<int>>& heights) {
        
        // Get the dimensions of grid
        int n = heights.size();
        int m = heights[0].size();

        // To store maximum difference
        vector<vector<int>> maxDiff(n, vector<int>(m, 1e9));
        
        /* Min-Heap storing the pair: 
        {diff, {row of cell, column of cell}} */
        priority_queue <P, vector<P>, greater<P>> pq;
        
        // Mark the initial position as 0
        maxDiff[0][0] = 0;
        
        // Push the starting cell to min-heap
        pq.push({0, {0, 0}});

        // Until the min-heap is not empty
        while(!pq.empty()) {
            
            /* Get the cell with minimum 
            difference (effort) */
            auto p = pq.top();
            
            // Get the difference
            int diff = p.first;
            
            int row = p.second.first; // Row
            int col = p.second.second; // Column
            pq.pop();
            
            /* If the destination cell is reached, 
            return the difference */
            if(row == n-1 && col == m-1) 
                return diff;
            
            // Traverse it's neighbors
            for(int i=0; i<4; i++) {
                
                /* Get the coordinates 
                of neighboring cell */
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                
                // Check if the cell is valid
                if(isValid(newRow, newCol, n, m)) {
                    
                    /* Get the current difference 
                    in heights of cells */
                    int currDiff = 
                    abs(heights[newRow][newCol] - heights[row][col]);
                    
                    /* Check if the current difference is 
                    less than earlier known difference */
                    if(max(currDiff, diff) < maxDiff[newRow][newCol]) {
                        
                        // Store the current difference
                        maxDiff[newRow][newCol] = max(currDiff, diff);
                        
                        // Add the new pair found in the min-heap
                        pq.push({max(currDiff, diff), {newRow, newCol}});
                    }
                }
            }
        }
        
        // Return -1
        return -1;
    }
};

int main() {
    
    vector<vector<int>> heights = {
        {1,2,2}, 
        {3,8,2}, 
        {5,3,5}
    };
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to determine minimum efforts 
    to go from top-left to bottom-right */
    int ans = sol.MinimumEffort(heights);
    
    // Output
    cout << "The minimum efforts required to go from cell (0,0) to cell (row-1, col-1) is: " << ans;
    
    return 0;
}
