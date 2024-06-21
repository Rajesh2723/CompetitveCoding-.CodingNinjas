/*
Problem statement
Patrick Jane is ready to pick up another challenge, and his friend Teresa is up to the task. She has created an elaborate puzzle for him to solve.

She gives Patrick two integers n and m. Using those integers Patrick needs to find the number of pairs of arrays (a,b) by following some rules. Teresa lists the rules as:

1. The length of both arrays should be equal to m.

2. Elements inside both the arrays should be an integer in the range 1 to n (both inclusive).

3. Arrays a and b should be created such that, ai ≤ bi for any index i from 1 to m.

4. Array a should be sorted in non-descending order.

5. Array b should be sorted in non-ascending order.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10^5
1 <= N, M <= 5*10^4
Output Format:
For each test case, print the answer in a new line.
As the result can be very large, you should print its modulo with 10^9+7.
Sample Input 1:
4
2 2
1 4
3 6
4 4
Sample Output 1:
5
1
91
165
Explanation:
In the first test case of the given input, where N=2 and M=2, there are 5 suitable arrays:
a=[1,1],b=[2,2];
a=[1,2],b=[2,2];
a=[2,2],b=[2,2];
a=[1,1],b=[2,1];
a=[1,1],b=[1,1].
 


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int n=200000;
const ll mod=1e9+7;
ll binpow(ll x,ll y){
    ll z=1;
    while(y){
        if(y&1ll)
            z=(z*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return z;
}
ll fact[n];
void precal(){
    fact[0]=1;
    for(int i=1;i<n;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
}
int main(){
    int t;
    cin>>t;
    precal();
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll ans=fact[n+2*m-1];
        ll a=(fact[2*m]*fact[n-1])%mod;
        a=binpow(a, mod-2);
        ans=(ans*a)%mod;
        cout<<ans<<endl;
    }
    
    return 0;
}
