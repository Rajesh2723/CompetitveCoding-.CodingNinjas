/*
Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
G=0;
for(i = 1 ; i < N ; i++)
   for(j = i+1 ; j <= N ; j++) 
       G+=gcd(i,j);
Here gcd() is a function that finds the greatest common divisor of the two input numbers.
Input Format:
The first line of input will contain T(number of the test case). Each test case contains an integer N.
Output Format:
For each test case print the answer in a new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^5
Sample Input:
3
10
100
3
Sample Output:
67
13015
3
//
|  n  | φ(n) |
|-----|------|
|  1  |  1   |
|  2  |  1   |
|  3  |  2   |
|  4  |  2   |
|  5  |  4   |
|  6  |  2   |
|  7  |  6   |
|  8  |  4   |
|  9  |  6   |
| 10  |  4   |
https://www.codingninjas.com/studio/library/euler-s-totient-function
Certainly! Let's delve deeper into the theory behind Euler's Totient Function and how it is efficiently calculated using the Sieve of Eratosthenes.

**Euler's Totient Function (φ):**

The Euler's Totient Function, denoted as φ(n), gives the count of positive integers less than or equal to n that are coprime (relatively prime) to n. In other words, it represents the number of positive integers less than or equal to n that do not share any common factor (other than 1) with n.

**Euler's Product Formula:**

Euler's Totient Function can be expressed using the product formula:

\[ \phi(n) = n \left(1 - \frac{1}{p_1}\right) \left(1 - \frac{1}{p_2}\right) \ldots \left(1 - \frac{1}{p_k}\right) \]

where \(p_1, p_2, \ldots, p_k\) are the distinct prime factors of n.

**The Sieve of Eratosthenes and Euler's Totient Function:**

Now, let's connect this with the Sieve of Eratosthenes. The Sieve of Eratosthenes is a well-known algorithm for finding all prime numbers up to a given limit (let's call it \(N\)). During the sieve, when you encounter a prime number \(p\), you mark all multiples of \(p\) as composite.

**Connection:**

- **Prime Numbers and Euler's Totient Function:**
  - When we encounter a prime number \(p\) during the sieve, it means that all multiples of \(p\) are not prime.
  - For Euler's Totient Function, we are interested in counting the numbers that are coprime to \(p\). Since multiples of \(p\) are not coprime with \(p\), we subtract their count from the total count.

- **Iteration and Adjustment:**
  - The outer loop iterates through numbers from 2 to \(N\).
  - For each prime number \(p\), the inner loop updates the Euler's Totient Function values by subtracting \(\frac{\phi[j]}{p}\) for all multiples \(j\) of \(p\).
  - This adjustment is based on the Euler's Totient Function formula and the fact that for prime numbers, \(\phi[p] = p - 1\).

- **Efficiency:**
  - The beauty of the Sieve of Eratosthenes lies in its efficiency. As the algorithm progresses, it marks multiples of primes, gradually refining the counts and eliminating numbers that are not coprime with these primes.

**Example:**

Consider \(N = 12\). During the Sieve of Eratosthenes, when you encounter the prime number 2, you subtract \(\frac{\phi[j]}{2}\) from the count for each multiple \(j\) of 2. Similarly, for the prime number 3, you subtract \(\frac{\phi[j]}{3}\) for each multiple \(j\) of 3.

In this way, the algorithm iteratively adjusts the Euler's Totient Function values based on the prime factors, leading to an efficient calculation.

I hope this explanation provides a clearer understanding of how Euler's Totient Function is related to prime factors and how the Sieve of Eratosthenes can be adapted to efficiently calculate it.

  */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mex = 1e5 + 1;
ll arr[mex];
void sieve() {

	for (ll i = 0; i < mex; i++) {
		arr[i] = i;
	}

	for (ll i = 2; i < mex; i++) {
		if (arr[i] == i) {//if it is same means its a prime number ,its multiple came means composite numbers.
			arr[i] -= 1;//phi(i,N)->if i and n are coprime i mean not composite means there are p-1 numbers will be there.
			for (ll j = 2 * i; j < mex; j += i) {
				arr[j] = arr[j] * (i - 1) / i;//phi function calculate->n*(1-1/p1)....->arr[j]*(1-1/i)
			}
		}
	}



}



int main() {

	ll t;
	cin >> t;
	sieve();
	ll result[mex];
	memset(result, 0, sizeof(result));
	for (ll i = 1; i < mex; i++) {
		for (ll j = 2; i * j < mex; j++) {
			result[i * j] += (i * arr[j]);
		}
	}
	ll dp[mex];
	dp[0] = result[0];
	for (ll i = 1; i < mex; i++) {
		dp[i] = result[i] + dp[i - 1];//prefix array
	}
	while (t--) {
		ll n;
		cin >> n;
		ll sum = 0;
		cout << dp[n] << endl;

	}
}
