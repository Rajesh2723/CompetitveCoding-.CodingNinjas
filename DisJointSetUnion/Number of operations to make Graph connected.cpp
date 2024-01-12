/*
Problem statement
You have been given a graph consisting of ‘N’ vertices numbered from 1 to ‘N’. The graph has ‘M’ edges. In an operation, you can shift an edge between two directly connected vertices to between pair of disconnected vertices to make them directly connected. Return the minimum number of operations to make the graph connected. If it is not possible to make graph connected return -1.

Example:
Let’s say ‘N’ is 4 and ‘M' is 3. The 3 edges are (1,2), (2,3) and (1,3). Then our graph will look as follows:-

To make the graph connected we can shift the edge between (1,3) to (1,4). This operation will make the graph connected. There are multiple ways in which we can make graph connected. So, in this case, we can make graph connected in just one operation.
Note:
1. A connected graph is a graph that is connected in the sense of a topological space, i.e., there is a path from any vertex to any other vertex in the graph.

2. There are no repeated edges and self-loops in the graph.

3. You do not need to print anything; it has already been taken care of. Just implement the function.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10000
1 <= M <= 10000
1 <= U[i], V[i] <= N

Where ‘T’ is the number of test cases.‘N’ is the number of vertices in the graph. ‘M’ is the number of edges in the graph. ‘U[i]’ and ‘V[i]’ are vertices of the i-th edge.

Time Limit: 1sec.
Sample Input 1:
2
4 3
1 2
2 3
3 1
4 3
1 2
2 3
3 4
Sample Output 1:
1
0
Sample Output 1 Explanation:
Test case 1:

The graph looks as follows:-

Initially, graph is disconnected. We can apply one operation and shift the edge between (2,3) to (3,4). This operation will make the graph connected. The graph after the operation will look as follows:-

Therefore the answer is 1.


Test case 2:

The graph looks as follows:-

The graph is already connected so we don’t need to make any operation.

Therefore the answer is 0.
Sample Input 2:
2
4 2
1 2
3 4
4 6
1 2
1 3
1 4
2 3
2 4
3 4
Sample Output 2:
-1
0 
  */
// we can use anyone as unionBySize or UnionByRank anyone works.
/*
	For a graph with ‘n’ vertices to be connected, there must be at least ‘N’-1 edges in the graph. If a graph has less than ‘N’-1 edges it is impossible to make the graph connected. Otherwise, it is always possible to make graph connected. As we need to find the minimum number of operations to make the graph connected we will think greedily. We will find the total number of connected components in the graph. We can treat each connected component in the graph as a single vertex. Basically, we want to shift edges such that these components become connected. Therefore answer will be the total number of connected components - 1. We can find the total number of connected components using disjoint set union.
	*/

class Disjoint{

    public:

    vector<int>parent,size;

    Disjoint(int n){

        size.resize(n+1,1);

        parent.resize(n+1);

        for(int i=0;i<=n;i++){

            parent[i]=i;

        }

    }

    int findUpar(int node){

        if(node == parent[node]){

            return node;

        }

        return parent[node]=findUpar(parent[node]);

    }

    void unionBySize(int u, int v){

        int ulp_u=findUpar(u);

        int ulp_v=findUpar(v);

        if(ulp_u == ulp_v){

            return;

        }

        if(size[ulp_u] < size[ulp_v]){

            parent[ulp_u]=ulp_v;

            size[ulp_v]+=size[ulp_u];

        }

        else{

            parent[ulp_v]=ulp_u;

            size[ulp_u]+=size[ulp_v];

        }

    }

};

 

int makeGraphConnected(int n, vector < pair < int,int > > edges, int m) {

    // Write Your Code here 

       Disjoint ds(n);

        int extra=0;

        for(auto it:edges){

            int u=it.first;

            int v=it.second;

            if(ds.findUpar(u) == ds.findUpar(v)){//if they already connected to same parent then its extra edge we have to count that .

                extra++;

            }

            else{

                ds.unionBySize(u,v);//else we can merge them to single

            }

        }

        int cnt=0;

        for(int i=1;i<=n;i++){

            if(i == ds.parent[i]){

                cnt++;

            }

        }

        int ans=cnt-1;//for a connnected components there requires n-1 edges .

        if(extra >= ans){

            return ans;

        }

    return -1;   

}
