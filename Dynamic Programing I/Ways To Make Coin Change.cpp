/*
Problem statement
You are given an infinite supply supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.

Note :
Return 0, if change isn't possible.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1<=n<=10
1<=V<=500
Sample Input 1 :
3
1 2 3
4
Sample Output :
4
Sample Output Explanation :
Number of ways are - 4, i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
  */
#include<bits/stdc++.h>
int f(int index,int arr[],int n,int target,vector<vector<int>>&dp){
   
  if(target<0||index>=n){
    return 0;
  }
  if(index==0){
      if(target==0){
        return 1;
      }
  }
  if(target==0 and index<n){
    return 1;
  }
  if(dp[index][target]!=-1){
    return dp[index][target];
  }
  int notpick=f(index+1,arr,n,target,dp); 
   
   
    int pick=f(index,arr,n,target-arr[index],dp);//when picking index is not changes since infinite supply of coins
  
  dp[index][target]=pick+notpick;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
 vector<vector<int>>dp(numDenominations+1,vector<int>(value+1,-1));
   return f(0,denominations,numDenominations,value,dp);


}
