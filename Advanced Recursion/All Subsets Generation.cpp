/*
All Subsets Generation
Send Feedback
You are given an array ‘arr’ of ‘N’ distinct integers. Your task is to find all the non-empty subsets of the array.
Note: You can return the subsets in any order, you don’t have to specifically sort them.
 

Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows

The first line of each test case contains a single integers ‘N’ denoting the length of the array.

The second line of each test case contains ‘N’ integers denoting the array elements.
Output Format :
For each test case print each subset in a separate line.

Output for each test case will be printed in a separate line.
Note :
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints :
1 <= T <= 10      
1 <= N <= 10
10^-9 <= arr[i] <= 10^9

Time limit: 1 sec
Sample Input 1 :
2
3
1 2 3
1
10
Sample Output 1 :
1
1 2
1 2 3
1 3
2
2 3
3
10
Explanation Of Sample Output 1 :
For test case 1 :
Total 7 possible subsets can be formed: {1}, {1,2}, {1,2,3}, {1,3}, {2}, {2,3}, {3}

For test case 2 :
Only a single subset {10} is possible for the given input array.
Sample Input 2 :
2
2
1 2
3
1 2 3
Sample Output 2 :
1 
1 2 
2 
1 
1 2 
1 2 3 
1 3 
2 
2 3 
3 
*/
#include<bits/stdc++.h>
void subset(vector<int>&arr,int ind,int n,vector<int>&temp,vector<vector<int>>&ans){
    if(ind==n){
        ans.push_back(temp);
        return;
    }

    temp.push_back(arr[ind]);
    subset(arr,ind+1,n,temp,ans);
    temp.pop_back();
    subset(arr,ind+1,n,temp,ans);
}


vector<vector<int>> FindAllSubsets(int n, vector<int> &arr){
vector<vector<int>>ans;   
vector<int>temp;
    subset(arr,0,n,temp,ans);
  return ans;
}
#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

#include "solution.h"

class Runner{
    int t;
    vector<int> N;
    vector<vector<int>> arr;

public:
    void takeInput(){
        cin >> t;
        N.resize(t);
        arr.resize(t);
        for (int i = 0; i < t; i++){
            cin >> N[i];
            arr[i].resize(N[i]);
            for (int j = 0; j < N[i]; j++){
                cin >> arr[i][j];
            }
        }
    }

    void execute(){
        vector<int> cpyN = N;
        vector<vector<int>> cpyArr = arr;
        for (int i = 0; i < t; i++){
            vector<vector<int>> ans = FindAllSubsets(cpyN[i], cpyArr[i]);
        }
        vector<int>().swap(cpyN);
        vector<vector<int>>().swap(cpyArr);
    }

    void executeAndPrintOutput(){
        for (int i = 0; i < t; i++){
            vector<vector<int>> ans = FindAllSubsets(N[i], arr[i]);
            for(int x=0; x<ans.size(); x++){
                sort(ans[x].begin(),ans[x].end());
            }
            sort(ans.begin(),ans.end());
            for(auto u: ans){
                for(auto x : u){
                    cout << x << " ";
                }
                cout << endl;
            }
        }
    }
};

int main()
{

#ifndef ONLINE_JUDGE
   // freopen("testcases/Large/in/input12.txt", "r", stdin);
   // freopen("testcases/Large/out/output12.txt", "w", stdout);
#endif
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}
