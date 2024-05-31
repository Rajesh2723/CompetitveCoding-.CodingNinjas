#include<bits/stdc++.h>
using namespace std;
void build(int start,int end,int pos,int *tree,int *arr){
    if(start==end){
        tree[pos]=arr[start];
        return ;
    }
    int mid=(start+end)/2;
    build(start,mid,2*pos+1,tree,arr);
    build(mid+1,end,2*pos+2,tree,arr);
    tree[pos]=tree[2*pos+1]+tree[2*pos+2];
}

 int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *tree=new int[4*n]();
    build(0,n-1,0,tree,arr);
    for(int i=0;i<2*n-1;i++){
        cout<<tree[i]<<endl;
    }
    return 0;
 }
