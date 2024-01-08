/*
Problem statement
Consider all numbers from 1 to ‘N’, your task is to find the sum of gcd of all pairs (i, j) such that 1 <= i < j <= N.

For example for N = 3, all pairs are { (1, 2), (1, 3), (2, 3) }.

Note :

Gcd of two numbers (X, Y) is defined as the largest integer that divides both ‘X’ and ‘Y’. 
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
2
3
5
Sample Output 1 :
3
11
Explanation Of Sample Input 1 :
Test case 1:
gcd(1, 2) + gcd(1, 3) +  gcd(2, 3) = 1 + 1 + 1 = 3.

Test case 2:
gcd(1, 2) + gcd(1, 3) +  gcd(1, 4) + gcd(1, 5) +
gcd(2, 3) + gcd(2, 4) + gcd(2, 5) +
gcd(3, 4) + gcd(3, 5) +
gcd(4, 5)  = 11.
Sample Input 2 :
1
1
Sample Output 2 :
0
Explanation Of Sample Input 2 :
Test case 1:
As there is no possible Paris, so the gcd sum is 0.
  */
/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(N)

    Where 'N' is the given number.
*/

// Function to calculate Euler's totient value for each 'i' from 1 to 'n'. 
vector<int> eulerTotient(int n)
{
    vector<int> phi(n + 1);

    for(int i= 1; i <= n; i++)
    {
        phi[i] = i;
    }

    for(int i = 2;i <= n; i++)
    {
        if(phi[i] == i)
        {
            for(int j = i; j <= n; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }

    return phi;
}

// Function to calculate gcd sum of pairs (i, x) such that i <= x for all 'x'.
vector<int> preCompute(int n, vector<int> &phi)
{
    // Declare an array to store 'f(x)' for all 'x' 1 to 'n'.
    vector<int> pre(n + 1);

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j += i)
        {
            pre[j] += (i * phi[j / i]);
        }
    }

    return pre;
}

long long gcdSum(int n)
{
    // Declare a variable to store gcd sum.
    long long answer = 0;

    // Declare an array 'phi' for Euler's totient fucntion values.
    vector<int> phi = eulerTotient(n);

    // Declare an array 'pre' to store 'f(x)' for each 'x' from 1 to 'n'.
    vector<int> pre =  preCompute(n, phi);

    // Find sum of each f(x) for all 'x' such that: 1 <= x <= n.
    for (int i = 1; i <= n; i++)
    {
        answer += pre[i];
        answer -= i;
    }

    // Return answer.
    return answer;
}
/*
#include<iostream>

using namespace std;

const int N = 1000000;
int phi[N+1];

void preproccess(){

	for(int i=1;i<=N;i++) phi[i] = i;

	for(int i=2;i<=N;i++)
	if(phi[i] == i)
	{
		for(int j=i;j<=N;j+=i)
		{
			phi[j] = phi[j] / i;
			phi[j] = phi[j] * (i - 1);
		}
	}
}

long long gcdSum(int n){

	long long result = 0;

	for(long long i=1;i*i<=n;i++)
		if(n % i == 0){
			long long d1 = i;
			long long d2 = n / d1;

			result = result + d1 * phi[n / d1];

			if(d1 != d2)
			result = result + d2 * phi[n / d2];
		}

	return result;
}

int main(){
	int t , n;

	cin>>t;
	preproccess();
	while(t--){
		cin>>n;

		cout<<gcdSum(n)<<endl;
	}
}
*/

