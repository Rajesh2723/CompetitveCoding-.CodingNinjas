/*
Problem statement
Ninja is at a shop and wants to buy a gift whose value is ‘K’. Ninja has N coins, each having a different denomination. While paying the shopkeeper, he found that he could pay the price of the gift using other ways. Ninja wants to know what is the number of different combinations in which Ninja can pay the price. Can you help the ninja to find the number of ways to make the value of ‘K’ using these ‘N’ coins?

You are given an array ‘COINS’ having ‘N’ integers corresponding to the value of each denomination and an integer ‘K’ denoting the value of the gift. Your task is to find the number of different ways in which the value ‘K’ can be made using these ‘N’ coins. The answer can be very large.Return answer % (10^9 +7).

For Example
If the given ‘COINS’ array is [9,6,1,10] and K = ‘16’.There are two ways to make 16,which are {10+6} and {9+1+6}.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 100.
1 <= K <=10000.
1 <= COINS[i] <= 1000

Time limit: 1 sec
Sample Input 1:
2
4 16
9 6 1 10
5 10
5 4 1 9 10
Sample Output 1:
2
3
Explanation of sample input 1:
For the first test case,
There are 2 ways to make 16 using the given coins.The combinations are {9+1+6},{10+6}.
Hence the answer is 2.

For the second test case:
There are 3 ways to make 10 using the given coins.The combinations are {10},{1+9} , {1+5+4}.
Hence the answer is 3.
Sample Input 2:
2
4 15
10 5 3 1 
3 13
10 2 6
Sample Output 2:
1
0
  */
/*
In C++ and many other programming languages, arrays are zero-indexed. This means that an array of size n will have indices ranging from 0 to n-1.
While the array dp is initialized with n+1 rows (0 to n), when accessing the result, dp[n - 1][k] refers to the entry at the (n-1)th row (which is the nth row in terms of indexing from 0) for the final result when considering all n coins.
Thus, the n-1 in the return statement is used because the array indexing starts at 0, so the n-1 index actually represents the nth element in the array of size n+1
and we can make base condition more concise also like this 

  // Sun is equal to 0.
            if (j == 0)
                continue;
                
            // Only one coin.
            if (i == 0) {
                if (j == coins[i])
                    dp[i][j] = 1;
                continue;
            }
*/

const int mod=1e9+7;
 
int ninjaAndCoins(int n, int k, vector<int> &coins)
{
     vector<vector<int>>dp(n+1,vector<int>(k+1,0));
     for(int i=0;i<=n;i++){
         dp[i][0]=1;
     }
     for(int i=0;i<n;i++){//i refers index value
         for(int j=0;j<=k;j++){//j referes to target value

            // Sun is equal to 0.
            if (j == 0) {
                dp[i][j] = 1;
                continue;
            }
            // Only one coin.
            if (i == 0) {
                if (j == coins[i]) {
                dp[i][j] = 1;
                } else {
                dp[i][j] = 0;
                }
                continue;
            }

             dp[i][j] = dp[i - 1][j];
             if(j>=coins[i]){
                 dp[i][j] = (dp[i][j] + dp[i - 1][j - coins[i]]) % mod;//taking coins[i] and decrementing target 
             }
         }
     }
     return dp[n-1][k];
}
// const int mod=1e9+7;
 
// int ninjaAndCoins(int n, int k, vector<int> &coins)
// {
//      vector<vector<int>>dp(n+1,vector<int>(k+1,0));
//      for(int i=0;i<=n;i++){
//          dp[i][0]=1;
//      }
//      for(int i=0;i<n;i++){
//          for(int j=1;j<=k;j++){
//              dp[i+1][j]=dp[i][j];
//              if(j>=coins[i]){
//                  dp[i + 1][j] = (dp[i + 1][j] + dp[i + 1][j - coins[i]]) % mod;
//              }
//          }
//      }
//      return dp[n-1][k];
// }
