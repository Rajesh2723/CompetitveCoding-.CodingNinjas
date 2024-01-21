/*
Problem statement
While learning DSA, Ninja found two N-ary trees and wants to check whether they are mirror images of each other or not. But, he can’t find a suitable method to check the same. Can you help Ninja to solve this problem?

You are given two N-ary trees, ‘TREEA’ and ‘TREEB’ having ‘N’ vertices labeled from 0 to ‘N’-1, and both the trees are rooted at node 0. Your task is to find whether the trees are mirror images of each other or not. Edges of the tree are in order from left to right.

For Example:
For the given example below, the trees are mirror images of each other.
Example

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 1000.
0 <= Node Label <=N-1.


Time limit: 1 sec
Sample Input 1:
2
5 
0 1
1 2
1 3
1 4
0 1
1 4
1 3
1 2
5
0 1
0 2
2 3
2 4
0 2
0 1
2 3
2 4
Sample Output 1:
YES
NO
Explanation of sample input 1:
For the first test case,
altimage

As from the image above, we can clearly see that these two N-ary trees are mirror images of each other. Hence, the answer is ‘YES’.



For the second test case, 
altimage

The given two trees are not the mirror images because corresponding to the Node 4 of ‘TREE_A’, there exist Node3 of ‘TREE_B’.Hence, the answer is ‘NO’.
Sample Input 2:
2
5
0 1
0 2
1 3
1 4
0 2
0 1
1 4
1 3
5
0 1
0 2
1 4
2 3
0 1
0 2
1 3
3 4
Sample Output 2:
YES
NO
  */
#include<bits/stdc++.h>
#include<vector>
bool dfs(int node,vector<int>adj1[],vector<int>adj2[]){
    if(adj1[node].size()!=adj2[node].size()){
        return false;
    }
    vector<int>*arr1=&adj1[node];
    vector<int>*arr2=&adj2[node];
    reverse(arr1->begin(),arr1->end());
    if(*arr1!=*arr2){
        return false;
    }
    for(auto x:adj1[node]){
        if(dfs(x,adj1,adj2)==false){
            return false;
        }
    }
    return true;
}
bool checkMirror(int n, vector<vector<int>> &edgesA, vector<vector<int>> &edgesB)
{
     vector<int>adj1[n];
     vector<int>adj2[n];
    for(auto it:edgesA){
        int u=it[0];
        int v=it[1];
        adj1[u].push_back(v);
    }   
    for(auto it:edgesB){
        int u=it[0];
        int v=it[1];
        adj2[u].push_back(v);
    }
   return dfs(0,adj1,adj2);
    // if(dfs(0,adj1,adj2)){
    //     return true;
    // }else{
    //     return false;
    // }
    
}
