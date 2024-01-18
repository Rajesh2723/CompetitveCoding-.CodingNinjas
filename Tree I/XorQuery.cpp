/*
Problem statement
You are given a tree(root 0) with N vertex having N - 1 edges. You are also given an array ‘QUERY’ of size ‘Q’, where each query consists of an integer that denotes a node. You have to print the xor of all the values of nodes in the sub-tree of the given node.

Note:

Here XOR denotes the bitwise operator (^).
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
0 <= N, Q <= 10^5 
0 <= QUERY[i] < N

Time Limit: 1 sec
Sample Input 1:
1
4 3
0 1
0 2
2 3
0 2 3
Sample Output 1:
0 1 3
Explanation For Sample Output 1 :
For the first test case :
The tree for the test case will be:  


For query 1: Xor will be: 0 ^ 1 ^ 2 ^ 3 = 0
For query 2: Xor will be: 2 ^ 3 = 1
For query 3: Xor will be: 3 = 3
Sample Input 2 :
1
7 4
0 1
0 2
1 3
1 4
2 5
2 6
0 1 4 5
Sample Output 2 :
7 6 4 5
Explanation For Sample Output 2 :
For the first test case :
The tree for the test case will be:  


For query 1: Xor will be: 0 ^ 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6= 7
For query 2: Xor will be: 1 ^ 3 ^ 4 = 6
For query 3: Xor will be: 4 = 4
For query 4: Xor will be: 5 = 5   
*/
/*
    Time complexity: O(N + Q)
    Space complexity: O(N)
    
    Where 'N' is the number of vertices and 'Q' is the number of queries.
*/

// dfs function.
int dfs(vector<vector<int>> &graph, int curr, int prev, vector<int> &dp) {
    
    // To store XOR value.
    int val = curr;
    
    for(int i = 0; i < graph[curr].size(); ++i) {
        
        // Check condition.
        if(graph[curr][i] != prev) {
            
            // Call dfs recursively and update value.
            val ^= dfs(graph, graph[curr][i], curr, dp);
        }
    }
    
    dp[curr] = val;
    
    return val;
}

vector<int> XORquery(int n, vector<vector<int>> &edges, int q, vector<int> &query) {
    
    // Create graph.
    vector<vector<int>> graph(n);
    for(int i = 0; i < n - 1; ++i) {
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    
    // To store pre-computed XOR values.
    vector<int> dp(n);
    
    // Call the function.
    dfs(graph, 0, -1, dp);
    
    // To store the result.
    vector<int> res;
    
    // Run all the queries.
    for(int i = 0; i < q; ++i) {
        
        // Store the result.
        res.push_back(dp[query[i]]);
    }
    
    return res;
}
