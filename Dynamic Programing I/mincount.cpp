/*
Problem statement
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.

That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)

B) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)  + (2 ^ 2)

C) (1^1) + (1^1) + (1^1) + (1^1) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
  */
int minCount(int n){
    //non Recursive solution

	std::vector<int> dp(n+1, 0);
	dp[0] = 0;
	dp[1] = 1;
    for (int i = 1; i <= n; ++i)
    {
    	int count = INT_MAX;
    	for (int j = 1; j <= i; ++j)
    	{
    		if (i-j*j<0)
    		{
    			break;
    		}

    		count = min(count, dp[i-j*j]);
    	}
    	dp[i] = 1+count;	
    }

    return dp[n];
	
}
