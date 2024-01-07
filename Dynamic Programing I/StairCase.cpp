/*
Problem statement
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.

Time complexity of your code should be O(n).

Since the answer can be pretty large soo print the answer with mod(10^9 +7)

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T < = 10
1 <= N <= 10^5
Sample input 1
2
2
3
Sample output 1
2
4
Explanation of sample input 1:
Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)
Sample input 2:
2
5
10
Sample output 2:
13
274
  */
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define ll long long 
int main()
{
       ll t;
       cin>>t;
       while(t--){
            ll n;
        cin>>n;
        // vector<int>dp(n+1);
         
        ll a=1;
        ll b=1;
        ll c=2;
        for(ll i=0;i<=n-3;i++){
                ll d=a%mod+b%mod+c%mod;
                d%=mod;
                a=b%mod;
                b=c%mod;
                c=d%mod;

        }
        cout<<c%mod<<endl;
       }
}
