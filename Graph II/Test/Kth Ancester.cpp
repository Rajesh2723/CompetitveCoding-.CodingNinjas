/*
Problem statement
Ninja found a family tree with ‘N’ members labeled from 0 to ‘N’-1. These ‘N’ members are connected by ‘N’-1 edges in the form of an N-ary tree. Now, Ninja is excited to find the K’th ancestor of each of the members of the family. Can you help Ninja to find the Kth ancestor of each of the members?

You are given an N-ary tree having ‘N’ vertices labeled from 0 to ‘N’-1 and an integer ‘K’. Your task is to find the Kth ancestor of each node. If the Kth ancestor doesn’t exist, print -1 corresponding to that.

For Example:
For K = 2 in the given tree, the 2nd ancestor for node 4 is 2, and the 2nd ancestor for node 1 does not exist.
Example

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^6.
1 <= K <=N.

Time limit: 1 sec
Sample Input 1:
2
5 2
0 1
1 2
1 3
1 4
6 2
0 1
1 4
1 2
1 5
2 3
Sample Output 1:
-1 -1 0 0 0 
-1 -1 0 1 0 0
Explanation of sample input 1:
For the first test case,
Example

Kth ancestor of Node 0 does not exist. So, the answer corresponding to Node 0 is -1.
Kth ancestor of Node 1 does not exist. So, the answer corresponding to Node 1 is -1.
Kth ancestor of Node 2 is Node 0. So, the answer corresponding to node 2 is 0.
Kth ancestor of Node 3 is Node 0. So, the answer corresponding to node 3 is 0.
Kth ancestor of Node 4 is Node 0. So, the answer corresponding to node 4 is 0.

Hence,the answer array will be [-1,-1,0,0,0].

For the second test case, 
Example

Kth ancestor of Node 0 does not exist. So, the answer corresponding to Node 0 is -1.
Kth ancestor of Node 1 does not exist. So, the answer corresponding to Node 1 is -1.
Kth ancestor of Node 2 is Node 0. So, the answer corresponding to node 2 is 0.
Kth ancestor of Node 3 is Node 1. So, the answer corresponding to node 3 is 1.
Kth ancestor of Node 4 is Node 0. So, the answer corresponding to node 4 is 0.
Kth ancestor of Node 5 is Node 0. So, the answer corresponding to node 5 is 0.

Hence,the answer array will be [-1,-1,0,1,0,0].
Sample Input 2:
2
7 1
0 1
0 2
1 4
1 5
1 6
2 3
7 1
0 1
0 2
0 6
1 3
3 4
4 5
Sample Output 2:
-1 0 0 2 1 1 1 
-1 0 0 1 3 4 0 
  */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> kthAncestor(int n, int k, vector<vector<int>> &edges) {
    vector<int> result(n, -1); // Initialize result array with -1

    vector<vector<int>> parent(n, vector<int>(log2(n) + 1, -1));

    // Construct the tree
    for (const auto &edge : edges) {
        int u = edge[0], v = edge[1];
        parent[v][0] = u;
    }

    // Precompute ancestors using dynamic programming
    for (int j = 1; (1 << j) < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }

    // Find Kth ancestor for each node
    for (int i = 0; i < n; ++i) {
        int node = i;
        for (int j = 0; j <= log2(n); ++j) {
            if (k & (1 << j)) {
                node = parent[node][j];
                if (node == -1) {
                    break;
                }
            }
        }
        result[i] = node;
    }

    return result;
}
