/*
There are a total of N tasks, labeled from 0 to N-1. Given an array arr where arr[i] = [a, b] indicates that you must take course b first if you want to take course a. Find the order of tasks you should pick to finish all tasks.

If no such ordering exists, return an empty array.

Since multiple valid answers are possible, the final output will be 1 if your solution is correct, otherwise 0.


Examples:
Input: N = 4, arr = [[1,0],[2,1],[3,2]]

Output: [0, 1, 2, 3]

Explanation: First,finish task 0, as it has no prerequisites. Then,finish task 1, since it depends only on task 0. After that,finish task 2, since it depends only on task 1. Finally,finish task 3, since it depends only on task 2

Input: N = 4, arr = [[0,1],[3,2],[1,3],[3,0]]

Output: []

Explanation: It is impossible to finish all the tasks. Let’s analyze the pairs:

For pair {0, 1} → we need to finish task 1 first and then task 0 (order: 1 → 0).

For pair {3, 2} → we need to finish task 2 first and then task 3 (order: 2 → 3).

For pair {1, 3} → we need to finish task 3 first and then task 1 (order: 2 → 3 → 1 → 0).

But for pair {3, 0} → we need to finish task 0 first and then task 3, which contradicts the previous order. So, it is not possible to finish all the tasks.
  */
class Solution {
  public:
   vector < int > findOrder(int N, vector < vector < int >> arr) {
    vector<int>ans;
         queue<int>q;
        vector<int>inDegree(N,0);
        vector<int>adj[N];
            for (auto &edge : arr) {
                int u = edge[0];
                int v = edge[1];
                adj[v].push_back(u);
                inDegree[u]++;
            }
        for(int i=0;i<N;i++){
            if(inDegree[i]==0)q.push(i);
        }
        //int count=0;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()<N)return {};
        return ans;
  }
};

