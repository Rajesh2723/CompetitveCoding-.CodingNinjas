/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
  */
//If we know the longest palindromic sub-sequence is x and the length of the string is n then, what is the answer to this problem? It is n - x as we need n - x insertions to make the remaining characters also palindrome.
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
    int minInsertions(string s) {
        string s1=s;
         reverse(s.begin(),s.end());
        int n=s1.size();
        int m=s.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans= f(n-1,m-1,s1,s,dp);
        return (n-ans);
    }
};
