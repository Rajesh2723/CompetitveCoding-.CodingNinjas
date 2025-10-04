/*
There are a total of N tasks, labeled from 0 to N-1. Given an array arr where arr[i] = [a, b] indicates that you must take course b first if you want to take course a. Find if it is possible to finish all tasks.


Examples:
Input: N = 4, arr = [[1,0],[2,1],[3,2]]



Output: True



Explanation: It is possible to finish all the tasks in the order : 0 1 2 3.

First, we will finish task 0. Then we will finish task 1, task 2, and task 3.

Input: N = 4, arr = [[0,1],[3,2],[1,3],[3,0]]



Output: False



Explanation: It is impossible to finish all the tasks. Let’s analyze the pairs:

For pair {0, 1} -> we need to finish task 1 first and then task 0. (order : 1 0).

For pair{3, 2} -> we need to finish task 2 first and then task 3. (order: 2 3).

For pair {1, 3} -> we need to finish task 3 first and then task 1. (order: 3 1).

But for pair {3, 0} -> we need to finish task 0 first and then task 3 but task 0 requires task 1 and task 1 requires task 3. So, it is not possible to finish all the tasks.
  */
class Solution{
public:
    bool canFinish(int N, vector<vector<int>> arr) {
        //bool ans=false;
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
        int count=0;
        while(!q.empty()){
            int node=q.front();
            count++;
            q.pop();
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        return count==N;
    }
};
