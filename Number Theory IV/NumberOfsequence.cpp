/*
Problem statement
A sequence is called nice by a coding ninja if the following conditions are met:

0 <= ‘ARR’[k] <= k 
‘ARR’[k] = ‘ARR’[m] mod k, for all pairs of k,m such that k divides m.
You are given a sequence of integers ‘ARR’ where some numbers may be -1. Find and print the number of nice sequences you can create by changing each -1 to a non-negative integer. As this number can be quite large, your answer must be modulo it by 10 ^ 9 + 7.

For example:

Given ‘N’ = 3, 
'A' = {0, -1, -1} 
Then the answer is 6 because following sequences are possible:[0, 0, 0], [0, 1, 0], [0, 1, 1], [0, 1, 2], [0, 0, 1], [0, 0, 2].
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= ‘T’ <= 10
1 <= ‘N’ <= 3000
0 <= 'ARR[i]’ <= 10 ^ 6

Time Limit: 1 sec.
Sample Input 1 :
2
3
0 -1 -1
3
0 1 -1
Sample Output 1 :
6
3  
Explanation of the Sample Input 1:
In the first test case, The following sequences are possible: [0, 0, 0], [0, 1, 0], [0, 1, 1], [0, 1, 2], [0, 0, 1], [0, 0, 2]. Hence the answer is 6.

In the second test case, The following sequences are possible: [0,1,0],[0,1,1], and [0,1,2]. Therefore the final answer is 3.
Sample Input 2 :
2
3
0 1 2
3
-1 -1 2 
Sample Output 2 :
1
2
  */
int check(int x, vector<int>& v)

{

int cur = -1;

int n = v.size();

for (int i = x; i < n; i += x)

{

if (v[i] != -1)

{

if (cur == -1) cur = v[i] % x;

else{

if (v[i] % x != cur) return 0;

}

}

}

if (cur == -1) return x;

else return 1;

}

 

int solve(vector<int> arr)

{

int n = arr.size();

vector<int> v(n + 1);

 

for (int i = 1; i <= n; i++) v[i] = arr[i - 1];

 

if (v[1] != 0 && v[1] != -1) return 0;

 

vector<long long int> isprime;

isprime.resize(n + 1, 1);

 

int sqrtn = min((int)sqrt(n) + 1, n);

 

vector<long long int> primes;

 

for (int i = 2; i <= sqrtn; i++)

{

long long int cur = i * 2;

 

if (!isprime[i]) continue;

while (cur <= n)

{

isprime[cur] = 0;

cur += i;

}

}

 

for (int i = 2; i <= n; i++) {

if (isprime[i]) primes.push_back(i);

}

long long int res = 1;

 

for (int i = 0; i < primes.size(); i++)

{

long long int cur = primes[i];

while (cur <= n)

{

int temp = check(cur, v);

if (temp == cur) res *= primes[i];

else res *= temp ;

res %= 1000000007;

cur *= primes[i];

}

}

return res;

}
