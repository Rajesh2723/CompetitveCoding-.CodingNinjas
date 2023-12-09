/*
You are given two integers N and i. You need to clear all bits from MSB to ith bit (start i from right to left) and return the updated N.
1
15 2

  output:3
  */
#include<bits/stdc++.h>
using namespace std;
int main(){
    
   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       int i;
       cin>>i;
       int bitMast=(1<<(i))-1;

       
       
      
          
     
       int ans=bitMast&n;
       cout<<ans<<endl;
   }
    return 0;
}
