/*
Given a weighted undirected graph having n vertices numbered from 1 to n and m edges describing there are edges, where edges[i]=[ai,bi,wi], representing an edge from vertex ai to bi with weight wi.



Find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.



If there exists a path, then return a list whose first element is the weight of the path and the remaining elements represent the shortest path from vertex 1 to vertex n.



Note: On IDE only the total sum of weights will be shown as output. As there might be more than one path (The path will be validated through driver code and If wrong then output shown will be -2.).


Examples:






Input: n = 5, m= 6, edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]

Output: 5 1 4 3 5

Explanation: The source vertex is 1. Hence, the shortest distance path of node 5 from the source will be 1->4->3->5 as this is the path with a minimum sum of edge weights from source to destination.
*/
#define p pair<int,int>

class Solution{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        priority_queue<p,vector<p>,greater<p>>pq;

         vector<pair<int, int>> adj[n + 1];
        
        // Adding the edges to the graph
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int>dist(n+1,1e9);

        vector<int>parent(n+1);

        for(int i=1;i<=n;i++){
            parent[i]=i;
        }

        dist[1]=0;

        pq.push({0,1});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int node=it.second;
            int dis=it.first;

            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;

                if(dis+wt<dist[adjNode]){
                    dist[adjNode]=dis+wt;
                    pq.push({dis+wt,adjNode});
                    parent[adjNode]=node;
                }
            }
        }

        if(dist[n]==1e9){
            return {-1};
        }
        vector<int>path;

        int node=n;

        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);

        reverse(path.begin(),path.end());

        path.insert(path.begin(),dist[n]);

        return path;


    }
};
