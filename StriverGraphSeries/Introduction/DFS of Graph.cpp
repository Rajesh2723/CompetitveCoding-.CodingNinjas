/*
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.


Example 1:

Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]

Output: 0 2 4 3 1
Explanation: 
0 is connected to 2, 3, 1.
1 is connected to 0.
2 is connected to 0 and 4.
3 is connected to 0.
4 is connected to 2.
so starting from 0, it will go to 2 then 4,
and then 3 and 1.
Thus dfs will be 0 2 4 3 1.
*/
private:
    void dfs(int start,vector<int>&ans,vector<int>adj[],int vis[]){
        vis[start]=1;
        ans.push_back(start);
        for(auto it:adj[start]){
            if(!vis[it]){
                dfs(it,ans,adj,vis);//Recursive call
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
         vector<int>ans;
         int vis[V]={0};//make V nodes to visit
         int start=0;//starting given as 0
        //  vector<int>ans;
         dfs(start,ans,adj,vis);
         return ans;
    }
