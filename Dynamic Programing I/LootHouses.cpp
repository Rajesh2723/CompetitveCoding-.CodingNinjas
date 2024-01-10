/*
Problem statement
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
  */
#include<bits/stdc++.h>
int f(int index,int *arr,vector<int>&dp){
	if(index==0){
		return arr[0];
	}
	if(dp[index]!=-1){
		return dp[index];
	}
	if(index<0){
		return 0;
	}
	int notpick=f(index-1,arr,dp);
	int pick=arr[index]+f(index-2,arr,dp);
	return dp[index]=max(notpick,pick);
}
int maxMoneyLooted(int *arr, int n)
{
	vector<int>dp(n+1,-1);
	return f(n-1,arr,dp);
}
