/*
Problem statement
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

Your task is to find if the graph contains a cycle or not.

A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

Example :

In the below graph, there exists a cycle between vertex 1, 2 and 3. 
Example

Note:

1. There are no parallel edges between two vertices.

2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

3. The graph can be disconnected.
For Example :

Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes

Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 5000
0 <= M <= min(5000, (N * (N - 1)) / 2)
1 <= edges[i][0] <= N 
1 <= edges[i][1] <= N 

Time Limit: 1 sec 
Sample Input 1:
1
3 2
1 2
2 3
Sample output 1:
No
Explanation of Sample output 1:
 The above graph can be represented as 
Example

There are a total of 3 vertices in the graph.There is an edge between vertex 1 and 2 and vertex 2 and 3. So, there is no cycle present in the graph. 
Sample Input 2:
2
4 0 
4 3
1 4
4 3
3 1
Sample output 2:
No
Yes
*/
//logic:get parents of each of them if parent are equal means they are in same set which means they forms cycle,if parents are not equal means we are merging them small to larger one.
int findParent(int i,vector<int>&parent){
    if(i==parent[i]){
        return i;
    }
    return parent[i]=findParent(parent[i], parent);
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int>parent(n+1,0);
    vector<int>rank(n+1,0);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=1;
    }
    for(vector<int>&arr:edges){
        int u=arr[0];
        int v=arr[1];

        int p1=findParent(u,parent);
        int p2=findParent(v,parent);
        if(p1!=p2){
            if(rank[p1]<rank[p2]){
                parent[p1]=p2;
            }else if(rank[p1]>rank[p2]){
                parent[p2]=p1;
            }else{
                parent[p1]=p2;
                rank[p2]++;
            }
        }else{
            return "Yes";
        }

    }
    return "No";
}
