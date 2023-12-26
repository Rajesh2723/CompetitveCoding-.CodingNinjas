/*
A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items of infinite supply. Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. We need to find the maximum value of items that the thief can steal. He can take a single item any number of times he wants and put it in his knapsack.
  Input: 
'n' = 3, 'w' = 10, 
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

Output: 27

Explanation:
We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.
*/
#include<bits/stdc++.h>
using namespace std;

int f(int index,int w,vector<int>&profit,vector<int>&weight,vector<vector<int>>&dp){
    
    if(index==0){
        return (w/weight[0])*profit[0];
    }

    if(dp[index][w]!=-1){   
        return dp[index][w];
    }
    
    int nottake= f(index-1,w ,profit,weight,dp);//index decreased and moved without taking element
    int take=-1e9;
    if(w>=weight[index]){
             take=profit[index]+f(index,w-weight[index],profit,weight,dp);//index is not decreased so that element can take multiple times 
    }
    
    return dp[index][w]=max(take,nottake);

}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return f(n-1,w,profit,weight,dp);     
}
