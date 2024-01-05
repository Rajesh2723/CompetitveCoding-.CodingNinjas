/*
Problem statement
You are given two integers 'n' and 'r' and a prime number 'p'. Your task is to find (nCr) % p where nCr can be calculated as n! / (r! * (n - r)!).

Note :

N!  =  1 * 2 * 3 *... N
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5 
1 <= n, r, p <= 5 * 10 ^ 2
p is prime number.

Time limit: 1 sec.
Sample Input 1 :
2 
5 2 11
4 3 13
Sample Output 1 :
10
4
Explanation for Sample Output 1:
In test case 1, 
n = 5, r = 2, and p = 11
n C r = 5 C 2 = (5 * 4) / (2!) = 10
n C r % p = 10 % 11 = 10. 
So the answer will be 10.

In test case 2,
n = 4, r = 3, and p = 13 
n C r = 4 C 3 = 4 C 1 = 4 
n C r % p = 4 % 13 = 4. 
So the answer will be 4.
Sample Input 2 :
2
5 2 17
10 2 13
Sample Output 2 :
10
6
  */
/*
    Time Complexity: O(N + log(P))
    Space Complexity: O(N)

    Where 'N' is the given integer 'n',
    'P' is the given integer 'p'.
*/

// Iterative Function to calculate (x ^ y) % p.
unsigned long long  power(int x, int y, int p)
{

    // Initialize ans.
    unsigned long long  ans = 1;

    // If x is more than or equal to p then update x.
    x = x % p;

    while (y > 0)
    {

        // If y is odd, multiply x.
        if (y % 2 != 0)
        {
            ans = (ans * x) % p;
        }

        // For even y.
        y = y / 2;
        x = (x * x) % p;
    }

    return ans;
}

// Returns n ^ (- 1) mod p
unsigned long long  powInverse(int n, int p)
{
    return power(n, p - 2, p);
}

unsigned long long  fermatLittle(int n, int r, int p)
{

    if (n < r)
    {
        return 0;
    }

    // Base case
    if (r == 0)
    {
        return 1;
    }

    // Make dp array to store the value of factorial of number modulo p.
    unsigned long long  dp[n + 1];
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] * i % p;
    }

    return (dp[n] * powInverse(dp[r], p) % p * powInverse(dp[n - r], p) % p) % p;
}


