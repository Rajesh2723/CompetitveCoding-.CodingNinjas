#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


int Partition(vector<int>& a, int left , int right){
    int pivot = left;
    int end = a[right];
    
    for(int i=left;i<right;i++){
        if(a[i]<=end){
            swap(a[pivot],a[i]);
            pivot++;
        }
    }
    
    swap(a[pivot],a[right]);
    return pivot;
}


void QuickSort(vector<int>& a, int left , int right){
    if(left>=right) return;
    int pivot = Partition(a,left,right);
    QuickSort(a,left,pivot-1);
    QuickSort(a,pivot+1,right);
}




void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
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
