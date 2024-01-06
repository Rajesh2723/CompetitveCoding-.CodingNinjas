/*
Problem statement
Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.

You are given an integer N and you are supposed to find the number special prime in the range: [1, N].

Example of special prime 19 = 7 + 11 + 1

Neighbouring primes are prime number such that there is no other prime number between them.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 2*10^5
Sample Input:
27
Sample Output:
2
  */
#include<bits/stdc++.h>
using namespace std;
const int n=200000;

  
vector<int>primes;
 bool prime[n+1];
void sieve(){
   
    memset(prime,true,sizeof(prime));
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
                 for(int j=i*i;j<=n;j+=i){
            prime[j]=false;
        }
        }
       
    }
    for(int i=2;i<=n;i++){
        if(prime[i]){
            primes.push_back(i);
        }
    }
}
int main(){
    sieve();
   int n;
   cin>>n;
   int count=0;
    for(int i=0;i<primes.size()-1;i++){
            int first=primes[i];
            int second=primes[i+1];
             int num=first+second+1;//
             if(num<=n and prime[num]){//check condidtion that num should be <than n and it must be prime
                 count++;
             }
    }
    cout<<count<<endl;
    return 0;
}
