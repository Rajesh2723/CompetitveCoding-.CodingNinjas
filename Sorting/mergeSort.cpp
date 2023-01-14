/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void mergeSort(vector<int>&arr,int start,int mid,int end){
    vector<int>left,right;
    for(int i=start;i<=mid;i++){
        left.push_back(arr[i]);
    }
    for(int i=mid;i<end;i++){
        right.push_back(arr[i]);
    }
    int left_poin=0,right_poin=0;
    int curr=start;
    int n=left.size();
    int m=right.size();
    while(left_poin<n and right_poin<m){
        if(left[left_poin]<right[right_poin]){
            arr[curr]=left[left_poin];
            curr++;
            left_poin++;
        }else{
            arr[curr]=right[right_poin];
            curr++;
            right_poin++;
        }
    }
    while(left_poin<n){
        arr[curr]=left[left_poin];
            curr++;
            left_poin++;
    }
    while(right_poin<m){
        arr[curr]=right[right_poin];
            curr++;
            right_poin++;
    }
    
}


void merge(vector<int>&arr,int start,int end){
    
    int mid=(start+end)/2;
    merge(arr,start,mid);
    merge(arr,mid+1,end);
    
    mergeSort(arr,start,mid,end);
    
}
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge(arr,0,n-1);
    cout<<"\n";
    for(auto i:arr)cout<<i<<" ";
    
    
}
