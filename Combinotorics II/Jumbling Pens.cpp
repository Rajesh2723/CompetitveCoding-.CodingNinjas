/*
Problem statement
You are given a total of ‘N’ pens. Out of which ‘R’ pens are Red, ‘G’ pens are green, and ‘B’ pens are blue. Pens of the same color are identical. We need to tell the distinct number of orderings of these pens we can achieve by jumbling them in any possible way since the answer can be huge print it modulo (10^9+7).

For Example:
‘N’ = 4, ‘R’ = 3, ‘G’ = 1, and ‘B’ = 0

All the possible distinct ordering are as follows:

G R R R
R G R R
R R G R
R R R G

Note that swapping or jumbling pens of the same colors doesn’t create a new ordering. 
As the total number of distinct arrangements is 4. Hence the output will be 4.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
2
4 3 1 0
3 1 1 1
Sample Output 1 :
4
6
Explanation For Sample Input 1 :
For First Case - Same as explained in above example.

For the second case - 

‘N’ = 3, ‘R’ = 1, ‘G’ = 1, and ‘B’ = 1

All the possible distinct ordering are as follows:

R G B
R B G
G R B
G B R
B R G
B G R

The total number of distinct orderings is 6. Hence the output will be 6.
Sample Input 2 :
2
6 2 3 1
8 4 1 3
Sample Output 2 :
60
280
  */
// #include <bits/stdc++.h>
// using namespace std;

// const int mod = 1e9 + 7;

// int fact(int n) {
//     if (n == 0 || n == 1) {
//         return 1;
//     }
//     int ans = 1;
//     for (int i = 2; i <= n; i++) {
//         ans = (ans * i) % mod;
//     }
//     return ans%mod;
// }

// int inv(int base, int power) {
//     int res = 1;
//     while (power) {
//         if (power & 1) {
//             res = (1LL * res * base) % mod; // Use long long multiplication to avoid overflow
//             power--;
//         }
//         base = (1LL * base * base) % mod; // Use long long multiplication to avoid overflow
//         power /= 2;
//     }
//     return res;
// }


// int jumbledPens(int n, int red, int green, int blue) {
//     int n1 = fact(n);
//     int r = fact(red);
//     int g = fact(green);
//     int b = fact(blue);
//     int ans = n1;
//     int denominator = (r * g * b) % mod;
//     int inv_denominator = inv(denominator, mod - 2);
//     ans = (ans * inv_denominator) % mod;
//     return ans;
// }
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = (ans * i) % mod;
    }
    return ans;
}

long long inv(long long base, long long power) {
    long long res = 1;
    while (power) {
        if (power & 1) {
            res = (res * base) % mod;
            power--;
        }
        base = (base * base) % mod;
        power /= 2;
    }
    return res;
}

long long jumbledPens(int n, int red, int green, int blue) {
    int total = red + green + blue;
    long long ans = fact(n);
    ans = (ans * inv(fact(red), mod - 2)) % mod;
    ans = (ans * inv(fact(green), mod - 2)) % mod;
    ans = (ans * inv(fact(blue), mod - 2)) % mod;
    return ans;
}
 
