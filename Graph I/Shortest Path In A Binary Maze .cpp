/*
Problem statement
Given a maze in the form of a binary rectangular matrix of size M*N, where each element can either be 0 or 1, the task is to find the length of the shortest path in a maze from a given source cell to a destination cell.

The path can only be created out of a cell if its value is 1 and at any given moment, we can only move one step in one of the four directions. The valid moves are:

Up: (x, y) -> (x - 1, y)
Left: (x, y) -> (x, y - 1)
Down: (x, y) -> (x + 1, y)
Right: (x, y) -> (x, y + 1)
If there is no path from a given source cell to a destination cell, return -1.

For example :
consider the binary matrix below. If source = (0, 0) and destination = (3, 4), the shortest path from source to destination has length 11.
example

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= M, N <= 100

Time Limit: 1sec
Sample Input 1 :
2
3 4
1 1 1 1
0 1 1 0
0 0 1 1
0 0
2 3
2 2
1 1
0 1
0 0
1 1
Sample Output 1 :
5
2
Explanation of Sample Input 1 :
For the first test case, the shortest path between the source cell (0, 0) and destination cell (2,3) is highlighted in the figure below, having a length of 5.
example

For the second test case, the only path from the source cell to the destination cell has a length of 2.
Sample Input 2 :
2
2 2
1 1
1 1
0 1
1 1
2 2
1 0
0 1
0 0
1 1
Sample Output 2 :
1
-1
  */
// Hello Rajesh 
#include <queue>
int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int>
                             dest)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (!matrix[src.first][src.second]) {
        return -1;
    }
    int ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    visited[src.first][src.second] = 1;
    queue<pair<int, int>> q;
    q.push(src);
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    while (q.size()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            pair<int, int> node = q.front();
            q.pop();
            if (node.first == dest.first && node.second == dest.second) {
                return ans;
            }
            for (int j = 0; j < 4; j++) {
                int newX = dx[j] + node.first;
                int newY = dy[j] + node.second;
                if (newX >= 0 && newY >= 0 && newX < n && newY < m && !visited[newX][newY] &&
                        matrix[newX][newY]) {
                    visited[newX][newY] = 1;
                    q.emplace(newX, newY);
                }
            }
        }
        ans++;
    }
    return -1;
}
