#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;




void solve(){
    //taking input
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];


    // find the maximum and minimum element in the array 
    int maxi = *max_element(a.begin(),a.end());
    int mini = *min_element(a.begin(),a.end());
    
    // initalize a vector with the number of elements equal to diff between
    // maximum and minimum number
    vector<int>f(maxi-mini+2);
    
    // update the frequency of each number shifted by the minimum number
    // this will make the minimum number always shift to zero
    for(int i=0;i<n;i++){
        f[a[i]-mini]++;
    }


    
    // print the sorted array & before priting shift the number to its
    // original form
    for(int i=0;i<f.size();i++){
        for(int j=0;j<f[i];j++){
            cout<<(i+mini)<<" ";
        }
    }
    
}
                
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
            int t=1;
            // cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";  
                solve();
    }
    return 0;
}
