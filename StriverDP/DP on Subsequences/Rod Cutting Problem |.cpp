/*
Problem statement
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.
*/
int f(int index,int N,vector<int>&price,vector<vector<int>>&dp){
	if(index==0){
		return (N*price[0]);//only one element we can take infinite times so to form N we are taking upto N times.only one element
	}
	
	if(dp[index][N]!=-1){
		return dp[index][N];
	}
	int nottake=f(index-1,N,price,dp);//decrease array length
	int take=INT_MIN;
	int rodlength=index+1;//length of current priece
	if(rodlength<=N){
		  take=price[index]+f(index,N-rodlength,price,dp);//here did mistake before redeclared (int take)
	}
	return dp[index][N]=max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return f(n-1,n,price,dp);
}
