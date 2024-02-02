/*
Problem statement
Ninja has 'N' students number from 1 to 'N', and he graded their recent assessments and assigned marks. You are assigned to guess the relative marks of the students. Given a list 'RELATIONS' containing 'K' pair of numbers 'X' and 'Y' stating that student 'X' has a lower rank than student 'Y', your task is to find and print the rank of each student in a class.

Return a vector containing ‘N’ elements from 1 to 'N' sorted according to the rank, if two students have same rank then student with the less number will come first.

Note: There will not be cycle forming among any student group

EXAMPLE:
Input: N = 3, K = 2
RELATIONS = [[1, 2], [2, 3]]

Output: [3, 2, 1]

In the given test case, student 2 has a higher rank than student 1, and student 3 has a higher rank than student 1. hence student one should be topper with rank 1, and then student two will have rank 2, and student three will have rank 3. So, we will print [1, 2, 3].
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= ‘T’ <= 10
2 <= 'N' <= 10^2
1 <= 'K' <= 10^5
'RELATIONS[i].length' = 2
1 <= 'RELATIONS[i][j]' <= N
Time Limit: 1sec
Sample Input 1 :
2
3 2
2 1
1 3
4 3
2 1
3 2
4 3
Sample Output 1 :
3 1 2
1 2 3 4
Explanation Of Sample Input 1 :
For the first test case, student 2 has a higher rank than student 1, and student 1 has a higher rank than student 3. hence student three should be topper with rank 1, and then student one will have rank 2, and student two will have rank 3.

For the second test case, student 2 has a higher rank than student 1, student 3 has a higher rank than student 2 and student 4 has a higher rank than student 3. thus the order of their ranks will be [1, 2, 3, 4]
Sample Input 2 :
2
5 5
2 4
4 3
2 3
2 4
5 2
6 5
2 1
2 3
1 6
5 3
3 4
Sample Output 2 :
1 3 4 2 5 
4 6 1 3 2 5
  */
#include<bits/stdc++.h>
vector<int> rankOfEach(int n, int k, vector<vector<int>> &relations) {
   vector<vector<int>>adj(n);
    vector<int>ans,visited(n,0);
    vector<int>indegree(n,0);
    vector<pair<int,int>>order;
    for(int i=0;i<relations.size();i++){
        indegree[relations[i][0]-1]++;
        adj[relations[i][1]-1].push_back(relations[i][0]-1);
    }
    priority_queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push({-i,1});
            visited[i]=1;
        }
    }
    while(!q.empty()){
        pair<int,int>f=q.top();
        q.pop();
        f.first*=-1;
        order.push_back({f.second,f.first});
        for(int i=0;i<adj[f.first].size();i++){
            if(visited[adj[f.first][i]]==0){
                indegree[adj[f.first][i]]--;
                if(indegree[adj[f.first][i]]==0){
                    visited[adj[f.first][i]]=1;
                    q.push({-1*adj[f.first][i],f.second+1});
                }
            }
        }
    }
    sort(order.begin(),order.end());
    for(pair<int,int>current:order){
        ans.push_back(current.second+1);
    }
    return ans;
}
