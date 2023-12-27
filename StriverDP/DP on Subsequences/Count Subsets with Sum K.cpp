/*
Problem statement
You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.



Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.



Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.



Example:
Input: 'arr' = [1, 1, 4, 5]

Output: 3

Explanation: The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.
  */
#include <vector>
using namespace std;

int f(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    
    if (dp[index][target] != -1) {
        return dp[index][target];
    }
    if (index == 0) { //base cases need to revise
        if (target == 0 && arr[0] == 0) return 2;
        if (target == arr[0] || target == 0) return 1;
        return 0;
    }
    int nottake = f(index - 1, target, arr, dp);
    int take = 0;
    if (arr[index] <= target) {
        take = f(index - 1, target - arr[index], arr, dp);
    }
    return dp[index][target] = (take + nottake) % 1000000007;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}
