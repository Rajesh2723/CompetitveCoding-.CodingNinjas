/*
You are given two integers N and i. You need to make ith bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
  1
7 2

output=3;
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
        
            n=n&~(1<<i); //take example 7 
        
        cout<<n<<endl;
       
       
   }
    return 0;
}
