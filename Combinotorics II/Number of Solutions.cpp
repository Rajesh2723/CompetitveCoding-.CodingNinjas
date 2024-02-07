/*
Problem statement
You are given the following equation:

X1 + X2 + ⋯ + Xk = N

Your task is to find the number of solutions of this equation, such that xi ≥ 0.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10^5
1 <= N , k <= 10^5
Output Format:
For each test case, print the number of solutions for the equation.
Answer can be very huge, so print its modulo with 10^9 + 7
Sample Input:
4
2 2
5 5
2 4
2 1
Sample Output:
3
126
10
1
  */
#include<bits/stdc++.h>
using namespace std;
# define ll long long
const int m=1e9+7;

vector<ll> fact(200005,1);
vector<ll> invfact(200005,1);

ll modInv(ll base, ll power){
    ll res=1;

    while(power){
        if(power&1){
            res=((res*base)%m);
            power--;
        }

        base=((base*base)%m);
        power/=2;
    }

    return res;
}

void solve(){
    ll n,k;
    cin >> n >> k;

    ll ans=(fact[n+k-1]*invfact[n])%m;
    ans=(ans*invfact[k-1])%m;
    cout << ans << endl;

}

int main(){

    for(int i=1;i<=200000;i++){
        fact[i]=((i*fact[i-1])%m);
        ll a=modInv(fact[i],m-2);
        a=((a%m)+m)%m;
        invfact[i]=a;
        // cout << a <<   " ";
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
here fact and inverse have to preprocess the answers ,each time execute 10^5 *10^5 creates array so create at once and make function.
#include<bits/stdc++.h>
using namespace std;
  typedef long long int ll;
 ll mod=1e9+7;

const int size=200001;
ll fact[200001];
ll  modpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll  ans = modpow(a, b / 2);
    ans = (ans * ans) % mod;
    if (b % 2) {
        ans = (ans * a) % mod;
    }
    return ans;
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
       fact[0] = 1; // Initialize fact[0] as 1
for(int i = 1; i < size; i++) {
    fact[i] = (fact[i-1] * i) % mod; // Update fact[i] correctly
}

         vector<ll> inv(size );

    inv[0] = inv[1] = 1;
    for (int i = 2; i < size; i++) {//calculate modInverse for all i values
        inv[i] = modpow(i, mod - 2);
    }
        ll ans=1;
        ans*=fact[n+k-1];
        ans*=inv[fact[n]*fact[k-1]];
        ans=ans%mod;
        cout<<ans<<endl;
    }
    return 0;
}

*/
