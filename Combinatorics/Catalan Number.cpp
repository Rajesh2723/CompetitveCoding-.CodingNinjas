/*
Problem statement
You are given an integer n. Your task is to find the nth catalan number. nth Catalan number is defined using following expression:


Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10^4
0 <= n < 10^3
Output Format:
For each test case. print the answer in a new line.
Since answer can be pretty huge print its modulo with 10^9 + 7
Sample Input:
2 
0
2
Sample Output:
1
2
  */
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long modpow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    vector<long long> inv(2e5 + 1);

    inv[0] = inv[1] = 1;
    for (int i = 2; i <= 2e5; i++) {//calculate modInverse for all i values
        inv[i] = modpow(i, mod - 2);
    }

    while (t--) {
        int n;
        cin >> n;

        if (n == 0 || n == 1) {
            cout << 1 << endl;
            continue;
        }

        long long final = 1;  // Initialize final

        for (int k = 2; k <= n; k++) {
            final = (final * (n + k) % mod) * inv[k] % mod;
        }

        cout << final << endl;
    }

    return 0;
}
