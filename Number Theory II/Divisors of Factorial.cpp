/*
Given a number, find the total number of divisors of the factorial of the number.
  Since the answer can be very large, print answer modulo 10^9+7.
1 <= T <= 500
0 <= N <= 50000
input:3
2
3
4
  output:
2
4
8
  */
#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000000 + 7;

vector<int> primes;

void preproccess(){
    
    int N = 50000;
    int ar[N+1];
    
    for(int i=1;i<=N;i++) ar[i] = 1;
    
    ar[1] = 0;
    
    for(int i=2;i*i<=N; i++)
        if(ar[i] == 1){
            
            for(int j=i*i;j<=N;j+=i)
                ar[j] = 0;
            
        }
    
    for(int i=2;i<=N;i++)
        if(ar[i] == 1)
            primes.push_back(i);
    
}

long long divisorCount(long long n){
    
    long long res = 1;
    
    for(int i=0;i<primes.size();i++)
        if(primes[i]<=n){//take each prime number 
            
            int p = primes[i];
            int count = 0;
            
            while(p <= n) {
                count = count + n / p;//[n/p]+[n/p2]...+[n/pk].
                p = p * primes[i];//update p
            }
            
            res = ((res % mod) * ((count + 1) % mod)) % mod;//update individual count to res (a1+1)->(count+1).
            
        }
    	else{
            break;
        }
    
    return res;
    
    
}

int main(){
    
    // write your code here
    int t;
    long long n;
    
    cin>>t;
    
    preproccess();
    
    while(t--){
        cin>>n;
        
        cout<<divisorCount(n)<<endl;
    }
    return 0;
}










