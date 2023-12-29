/*
Problem statement
You are given two strings ‘s1’ and ‘s2’.
Return the longest common subsequence of these strings.
If there’s no such string, return an empty string. If there are multiple possible answers, return any such string.
Note:
Longest common subsequence of string ‘s1’ and ‘s2’ is the longest subsequence of ‘s1’ that is also a subsequence of ‘s2’. A ‘subsequence’ of ‘s1’ is a string that can be formed by deleting one or more (possibly zero) characters from ‘s1’.
Example:
Input: ‘s1’  = “abcab”, ‘s2’ = “cbab”
Output: “bab”
  */
//memoization approach
#include<bits/stdc++.h>

string callme(int n,int m,string &s1,string &s2,vector<vector<string>> &dp)

{

    if(n<0||m<0)

    return "";

    if(dp[n][m]!="")

    return dp[n][m];

    if(s1[n]==s2[m])

    return dp[n][m]=s1[n]+callme(n-1,m-1,s1,s2,dp);

    else{

        string a=callme(n-1,m,s1,s2,dp);

        string b=callme(n,m-1,s1,s2,dp);

        if(a.size()>b.size())

        {

            return dp[n][m]=a;

        }

        else

        return dp[n][m]=b;

    }

    

}

string findLCS(int n, int m,string &s1, string &s2){

    // Write your code here.

    vector<vector<string>> dp(n+1,vector<string> (m+1,""));

    string st=callme(n-1,m-1,s1,s2,dp);

    reverse(st.begin(),st.end());

    return st;

 

}
