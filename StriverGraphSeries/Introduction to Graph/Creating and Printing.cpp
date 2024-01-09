/*
Problem statement
You are given an undirected graph of 'N' nodes and 'M' edges. Your task is to create the graph and print the adjacency list of the graph. It is guaranteed that all the edges are unique, i.e., if there is an edge from 'X' to 'Y', then there is no edge present from 'Y' to 'X' and vice versa. Also, there are no self-loops present in the graph.



In graph theory, an adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph.



For Example:
If 'N' = 3 and edges = {{2,1}, {2,0}}.

So, the adjacency list of the graph is stated below.
0 → 2
1 → 2
2 → 0 → 1
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4 3
1 2
0 3
2 3
Sample Output 1:
0 3
1 2
2 1 3
3 0 2
Explanation For Sample Input 1:
The graph is shown in the below figure.

So, the neighbour of node 0 is 3. So, in the first line, the first integer is 0 followed by its neighbour 3. Similarly in the second line, 1 is followed by its neighbour 2. 

In the third line, 2 is followed by its neighbours 1 and 3. And in the fourth line, 3 is followed by its neighbours 0 and 2.
Sample Input 2:
3 3
0 1
1 2
2 0
Sample Output 2:
0 1 2
1 0 2
2 0 1
Explanation For Sample Input 2:
The graph is shown in the below figure.

So, the neighbour of node 0 is 1 and 2. So, in the first line, the first integer is 0 followed by its neighbour 1 and 2. Similarly in the second line, 1 is followed by its neighbour 2 and 0. 

In the third line, 2 is followed by its neighbours 1 and 0. 
Constraints:
1 <= N <= 5000
1 <= M <= min(5000, (N * (N - 1)) / 2)
0 <= edges[i][0], edges[i][1] <= N-1

Time limit: 1 sec
  */
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    //creating an array of vectors to store connections
    vector<int>connections[n];
    //n->nodes
    //n connections
    //0->3
    //1->2
    //2->1,3
    //3->0,2
    
    for(int i=0;i<m;i++){
       //at max the connections can go upto m
       //for 2 nodes 1 edge is connected 
       int u = edges[i][0];//{0,3}->{0}
       int v = edges[i][1];//{0,3}->{3}

       connections[u].push_back(v);//0->3
       connections[v].push_back(u);//3->0
    }

  vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        //acc to output format
        adj[i].push_back(i);//node itself connected {0,1,2,3}
        for(int j=0;j<connections[i].size();j++){
            adj[i].push_back(connections[i][j]);//0->0,1
        }
    }
    return adj;
}
