/*
Problem statement
A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack. There are 'N' items available in the store and the weight and value of each item is known to the thief. Considering the constraints of the maximum weight that a knapsack can carry, you have to find the maximum profit that a thief can generate by stealing items.

Note: The thief is not allowed to break the items.

For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with weight 6, 1 and 3. The total value of knapsack = 3 + 6 + 4 = 13.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^3
1 <= W <= 10^3
1<= weights <=10^3
1 <= values <= 10^3


where 'T' is the number of test cases, ‘N’ is the number of items, "weights" is the weight of each item, "values" is the value of each item and ‘W’ is the maximum weight the thief can carry. 
Sample Input:
1 
4 5
1 2 4 5
5 4 8 6
Sample Output:
13
Explanation of Sample output 1
The most optimal way to fill the knapsack is to choose items with weight 4 and value 8, weight 1 and value 5.

The total value of the knapsack =  8 + 5 = 13.
Sample Input 2:
1
5 100
20 24 36 40 42
12 35 41 25 32
Sample output 2:
101
  */
#include <bits/stdc++.h>

int solve(vector<int>& weight, vector<int>& value, int n, int maxWeight, vector<vector<int>>& dp) {
    if (n == 0 || maxWeight == 0)
        return 0;

    if (dp[n][maxWeight] != -1)
        return dp[n][maxWeight];

    int result;

    if (weight[n - 1] <= maxWeight) {
        result = max(value[n - 1] + solve(weight, value, n - 1, maxWeight - weight[n - 1], dp),
                     solve(weight, value, n - 1, maxWeight, dp));
    } else {
        result = solve(weight, value, n - 1, maxWeight, dp);
    }

    dp[n][maxWeight] = result;

    return result;
}

int maxProfit(vector<int>& values, vector<int>& weights, int n, int w) {
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    return solve(weights, values, n, w, dp);
}
