/*
  Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
*/

#include <bits/stdc++.h>
 int f(int index,vector<int>&heights,vector<int>&dp){
     if(index==0){
         return 0;
     }
     if(index<0){
         return 1e9;
     }
         
     if(dp[index]!=-1){
         return dp[index];
     }
     
      
            int left=f(index-1,heights,dp)+abs(heights[index]-heights[index-1]);//for each recursion(for each jump)enerygy consumed
      
          int right=f(index-2,heights,dp)+abs(heights[index]-heights[index-2]);
      
         
     
    
     return  dp[index]=min(left,right);
 }
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
    return  f(n-1,heights,dp);
     

}
