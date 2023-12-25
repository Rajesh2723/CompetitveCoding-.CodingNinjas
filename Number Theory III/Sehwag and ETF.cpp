/*
Sehwag has been solving a lot of mathematical problems recently. He was learning ETF (Euler Totient Function) and found the topic quite interesting. So, he tried solving a question on ETF. He will be given two numbers L and R. He has to find the probability that the ETF of a number in the range [L, R] is divisible by a number K.
1 <= T <= 10
1 <= L <= R <= 10^12
0 <= R - L <= 10^5
1 <= K <= 10^6
input:
3
1 4 2
2 5 2
3 10 4

output:
0.500000
0.750000
0.375000
  */
#include <bits/stdc++.h>
#define ll long long
#define MAX 1000001
using namespace std;

void primeCheck(bool primes[])
{

    for (int i = 2; i < MAX; i++)
    {
        primes[i] = true;
    }
    for (int i = 2; i < MAX; i++)
    {
        if (primes[i])
        {
            for (int j = 2; j * i < MAX; j++)
            {
                primes[j * i] = false;
            }
        }
    }
}

double solve(bool primes[], ll phi[], ll num[], ll a, ll b, ll k)
{
    for (ll i = a; i <= b; i++) //take a=2 b=7
    {
        phi[i - a] = i;//phi values=phi[0],phi[1],phi[2],phi[3],phi[4] values are 2,3,4,5,6 respectively
        num[i - a] = i;
    }
    vector<int> p;
    for (int i = 2; i < MAX; i++)
    {
        if (primes[i] == true)
        {
            p.push_back(i);
        }
    }
    for (ll i = 0; p[i] * p[i] <= b; i++)
    {
        ll base = a / p[i] * p[i];

        while (base < a) //if base is less than a which means not in range ,range starts from a to b
            base += p[i];

        for (ll j = base; j <= b; j += p[i])
        {
            while (num[j - a] % p[i] == 0)
                num[j - a] /= p[i];
            phi[j - a] -= phi[j - a] / p[i];
        }
    }
    for (ll i = a; i <= b; i++)
    {
        if (num[i - a] > 1)
            phi[i - a] -= phi[i - a] / num[i - a];

        num[i - a] = 1;
    }
    ll c = 0;

    for (ll i = a; i <= b; i++)
    {
        if (phi[i - a] % k == 0)
            c++;
    }
    double ans = c;
    ans /= (b - a + 1);
    return ans;
}

int main()
{
    int t;
    cin >> t;
    bool primes[MAX];
    ll phi[100001], num[100001];
    primeCheck(primes);
    while (t--)
    {
        ll a, b, k;
        double ans;
        cin >> a >> b >> k;
        ans = solve(primes, phi, num, a, b, k);
        cout << fixed << setprecision(6) << ans << endl;
    }
}
