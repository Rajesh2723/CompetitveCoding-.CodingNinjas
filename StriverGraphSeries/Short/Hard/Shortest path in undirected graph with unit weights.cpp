/*
Given a Undirected Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a edge from vertex edges[i][0] to vertex edges[i][1] of unit weight.



Find the shortest path from the source to all other nodes in this graph. In this problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.


Examples:
Input: n = 9, m = 10, edges = [[0,1],[0,3],[3,4],[4,5],[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]]



Output: 0 1 2 1 2 3 3 4 4



Explanation:

The above output array shows the shortest path to all 

the nodes from the source vertex (0), Dist[0] = 0, Dist[1] = 1 , Dist[2] = 2 , …. Dist[8] = 4.Where Dist[node] is the shortest path between src and the node. For a node, if the value of Dist[node]= -1, then we conclude that the node is unreachable from the src node.

Input: n = 8, m = 10, edges =[[1,0],[2,1],[0,3],[3,7],[3,4],[7,4],[7,6],[4,5],[4,6],[6,5]]



Output: 0 1 2 1 2 3 3 2



Explanation: 

The above output list shows the shortest path to all the nodes from the source vertex (0), Dist[0] = 0, Dist[1] = 1, Dist[2] = 2,.....Dist[7] = 2.
  */
class Solution {
  public:
    void bfs(vector<int>adj[],int n,int m,vector<int>&ans,int firstnode){
        vector<int>vis(n,0);
        ans[0]=0;
        queue<int>q;
        q.push(firstnode);
        //push nodes to queue and relax each 
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(ans[node]+1<ans[it]){
                    ans[it]=1+ans[node];
                    q.push(it);
                }
            }
        }
    }

    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        vector<int>ans(N,1e9);
        vector<int>adj[N];
        //form adjacency
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //call bfs to relax nodes.
        bfs(adj,N,M,ans,0);

        for(int i=0;i<N;i++){
            if(ans[i]==1e9){
                ans[i]=-1;
            }
        }

        return ans;
    }
};
