/*
You are given an integer N and asked to find the Xor of first N natural numbers.
  */
#include<bits/stdc++.h>
using namespace std;
int main(){
    
   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       if(n%4==0){
           cout<<n<<endl;
       }else if(n%4==1){
           cout<<1<<endl;
       }else if(n%4==2){
           cout<<n+1<<endl;
       }else{
           cout<<0<<endl;
       }
   }
    return 0;
}
