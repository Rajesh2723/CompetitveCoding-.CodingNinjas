#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
#define ll long long
using namespace std;
 
 
void precal(){
}
 
void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    sort(a.begin(),a.end());
    
    ll total_waiting=0;
    ll satisfied=0;
    for(int i=0;i<n;i++){
        if(total_waiting<=a[i]){
            satisfied++;
            total_waiting+=a[i];
        }
    }
    cout<<satisfied<<"\n";
}   
 
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
            precal();
            int t=1;
            // cin>>t;
            for(int i=1;i<=t;i++){
                solve();
    }
    return 0;
}
