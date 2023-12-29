/*
Problem statement
You are given two strings, 'str1' and 'str2'. You have to find the length of the longest common substring.
 
A substring is a continuous segment of a string. For example, "bcd" is a substring of "abcd", while "acd" or "cda" are not.
 
Example:
Input: ‘str1’ = “abcjklp” , ‘str2’ = “acjkp”.

Output: 3

Explanation:  The longest common substring between ‘str1’ and ‘str2’ is “cjk”, of length 3.
*/
 
int lcs(string &text1, string &text2){
      int n=text1.size();
        int m=text2.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         for(int i=1;i<=n;i++){
             for(int j=1;j<=m;j++){
                    if(text1[i-1]==text2[j-1]){
                        int val=1+dp[i-1][j-1];
                        dp[i][j]=val;
                        ans=max(ans,val);
                    }else{
                        dp[i][j]=0;
                    }
             }
         }
         return ans;
}
