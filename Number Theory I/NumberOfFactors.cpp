/*
Problem statement
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10000
1 ≤ a ≤ b ≤ 10^6
0 <= b - a <= 100
0 ≤ n ≤ 10
Sample Input
4
1 3 1
1 10 2
1 10 3
1 100 3
Sample Output
2 
2
0
8
  */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    vector<int> prime_list;
    for (int i = 2; i <= n; ++i) {
        if (primes[i]) {
            prime_list.push_back(i);
        }
    }
    return prime_list;
}

vector<int> precalculate_factors(int max_num) {
    vector<int> primes = sieve_of_eratosthenes(max_num);
    vector<int> dp(max_num + 1, 0);
    for (int i = 2; i <= max_num; ++i) {
        if (dp[i] == 0) {
            for (int j = i; j <= max_num; j += i) {
                dp[j]++;
            }
        }
    }
    return dp;
}

int count_n_factorful(int a, int b, int n, const vector<int>& dp) {
    int count = 0;
    for (int i = a; i <= b; ++i) {
        if (dp[i] == n) {
            count++;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    vector<int> dp = precalculate_factors(1000000); // Precalculate factors up to 10^6
    for (int t = 0; t < T; ++t) {
        int a, b, n;
        cin >> a >> b >> n;
        int result = count_n_factorful(a, b, n, dp);
        cout << result << endl;
    }
    return 0;
}
