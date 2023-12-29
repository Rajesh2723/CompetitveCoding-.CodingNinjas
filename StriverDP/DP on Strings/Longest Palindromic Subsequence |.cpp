/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
  */
//We just need to find longest common subsequence of string s and reverse of string s
class Solution {
public:
int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
    if(i<0 ||j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
    }
    return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
}
    int longestPalindromeSubseq(string s) {
        string s1=s;
         reverse(s.begin(),s.end());
        int n=s1.size();
        int m=s.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,s1,s,dp);
    }
};
