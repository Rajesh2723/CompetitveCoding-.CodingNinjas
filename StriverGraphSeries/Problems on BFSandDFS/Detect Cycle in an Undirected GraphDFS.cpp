/*
Problem statement
Given an undirected graph of 'V' vertices and 'E' edges. Return true if the graph contains a cycle or not, else return false.



Note:

There are no self-loops(an edge connecting the vertex to itself) in the given graph.
Example:
Given N=3, M =2, and edges are (1, 2) and (2, 3), with nodes 1, 2, and 3.

We return false because the given graph does not have any cycle.
  */
class Graph {
bool isCycle(int i,int parent,vector<int>adj[],int vis[]){
    vis[i]=1;
    for(auto x:adj[i]){
       if(!vis[x]){
           if(isCycle(x, i, adj,vis)==true){
               return true;
           }
           
       } else if(x!=parent)  {
           return true;
       }
    }
    return false;
}
public:
    bool detectCycle(int V, vector<int> adj[]) {
        //  vector<bool>vis(V,0);
        int vis[V]={0};
         for(int i=0;i<V;i++){
             if(!vis[i]){
                     if(isCycle(i,-1,adj,vis)){
                 return true;
             }
             }
            
         }
         return false;
    }
};
