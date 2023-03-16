/*
Paths in a Maze
Send Feedback
You are given a 2-D matrix consisting of 0’s and 1’s with ‘N’ rows and ‘N’ columns, you are supposed to find all paths from the cell (0,0) (top-left cell) to the cell (N-1, N-1)(bottom-right cell). All cells with value 0 are blocked and cannot be travelled through while all cells with value 1 are open.
If you are currently at cell (x,y) then you can move to (x+1,y)(denoted by ‘D’), (x-1,y)(denoted by ‘U’), (x,y+1)(denoted by ‘R’), (x,y-1)(denoted by ‘L’) in one move. You cannot move out of the grid.
Example :
Example

Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases. The test cases follow.

The first line of each test case contains a single integer ‘N’ denoting the number of rows and columns in the given matrix.

Next ‘N’ lines contain ‘N’ single space-separated integers each denoting the elements in the matrix.
Output Format :
For each test case, print all paths from (0,0) to (N-1, N-1) separated by a single space.

The output of every test case will be printed in a separate line.
Note :
You don’t need to print anything; It has already been taken care of.
Constraints :
1 <= T <= 5
1 <= N <= 5
0 <= ARR[i][j] <= 1

Where ‘T’ denotes the number of test cases, ‘N’ denotes the number of rows and columns of the given matrix, and ARR[i] denotes the value of the cell (i,j) in the given matrix.

Time Limit: 1 sec
Sample Input 1 :
2
2
1 1
1 1
2
1 0
1 1
Sample Output 1 :
DR RD
DR
Explanation of Sample Input 1 :
In the first test case, there are two paths from (0,0) to (1,1). The first path is (0,0)->(1,0)->(1,1) and the second path is (0,0)->(0,1)->(1,1)

In the second test case, there is only one path since the cell at (0,1) is blocked. The path is (0,0)->(1,0)->(1,1).
Sample Input 2 :
2
3
1 0 1
1 0 0
1 1 1
3
1 1 1
1 0 1
1 1 1
Sample Output 2 :
DDRR
DDRR RRDD
Explanation of Sample Input 2 :
In the first test case, there is only one path from (0,0) to (2,2). The path is (0,0)->(1,0)->(2,0)->(2,1)->(2,2).

In the second test case, there are two paths from (0,0) to (2,2). The first path is (0,0)->(1,0)->(2,0)->(2,1)->(2,2). and the second path is (0,0)->(0,1)->(0,2)->(1,2)->(2,2).
*/
#include<bits/stdc++.h>

void findPaths(vector<vector<bool>>& grid, int x, int y, vector<char>& path, vector<string>& result) 

{

    int n = grid.size();

    int m = grid[0].size();

 

    if(grid[n-1][m-1] == 0) return;

    // check if we reached the destination cell

    if (x == n-1 && y == m-1) {

        string s(path.begin(), path.end());

        result.push_back(s);

        return;

    }

    // check if current cell is valid

    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0)

      return;

 

    // mark current cell as visited

    grid[x][y] = 0;

    // explore all possible moves from the current cell

    path.push_back('D');

    findPaths(grid, x + 1, y, path, result);

    path.pop_back();

    path.push_back('R');

    findPaths(grid, x, y + 1, path, result);

    path.pop_back();

    path.push_back('U');

    findPaths(grid, x - 1, y, path, result);

    path.pop_back();

    path.push_back('L');

    findPaths(grid, x, y - 1, path, result);

    path.pop_back();

    // unmark current cell

    grid[x][y] = 1;

}

 

vector<string> findAllPaths(vector<vector<bool>> &grid)

{

    vector<string> result;

    if (grid.empty()) {

        return result;

    }

    

    vector<char> path;

    findPaths(grid, 0, 0, path, result);

    return result;

}
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "solution.h"

class Runner
{
    int t;
    vector<vector<vector<bool>>> arr;

public:
    void takeInput()
    {

        cin >> t;
        arr.resize(t);

        for (int tc = 0; tc < t; tc++)
        {
            int n;
            cin >> n;
            arr[tc].resize(n);

            for (int i = 0; i < n; i++)
            {
                arr[tc][i].resize(n);
                for (int j = 0; j < n; j++)
                {
                    bool x;
                    cin>>x;
                    arr[tc][i][j]=x;
                    
                }
            }
        }
    }

    vector<vector<vector<bool>>> getCopy()
    {
        vector<vector<vector<bool>>> arrCopy = arr;

        return arrCopy;
    }

    void execute()
    {
        vector<vector<vector<bool>>> arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            vector<string> ans = findAllPaths(arrCopy[i]);
        }
    }
    

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<string> ans = findAllPaths(arr[i]);
            
            sort(ans.begin(),ans.end());
            for (string i : ans)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
