/*
You are given an integer N and are supposed to find the value of Euler toient function for N phi(N)
First line of input will contain T(number of test case), each test case follows as.
An integer N in new line.
1 <= T <= 100
1 <= N <= 10^9

input:2
20
21

output:
8 
12
  */
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
// Function to calculate Euler's totient function
int phi(int n) {
    int result = n; // Initialize result as n

    // Consider all prime factors of n and subtract their multiples from result
    for (int p = 2; p * p <= n; ++p) {
        // Check if p is a prime factor of n
        if (n % p == 0) {
            // Update result by subtracting multiples of p
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }

    // If n has a prime factor greater than sqrt(n), update result accordingly
    if (n > 1) {
        result -= result / n;
    }

    return result;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=phi(n);
        cout<<ans<<endl;
    }
}
