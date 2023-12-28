/*
In the coming articles, we will discuss problems related to ‘Dynamic Programming on Strings’. We will discuss the problem of ‘Longest Common Subsequence’ in this article. Before proceeding further, let us understand what is the “Longest Common Subsequence”, or rather what is a “subsequence”?

A subsequence of a string is a list of characters of the string where some characters are deleted ( or not deleted at all) and they should be in the same order in the subsequence as in the original string.

For eg:


Strings like “cab”,” bc” will not be called as a subsequence of “abc” as the characters are not coming in the same order.

Note: For a string of length n, the number of subsequences will be 2n.

Now we will look at “Longest Common Subsequence”. The longest Common Subsequence is defined for two strings. It is the common subsequence that has the greatest length.
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
  */
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
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }
};
